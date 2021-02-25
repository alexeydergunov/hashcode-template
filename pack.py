#!/usr/bin/python3

import os
import shutil


def main():
    answers_dir = "answers"
    best_answers_dir = "best_answers"
    last_sources_dir = "last_sources"

    best_scores = {}
    for filename in os.listdir(answers_dir):
        assert filename[-4:] == ".out"
        filename = filename[:-4]
        pos = filename.rfind("_")
        letter, score = filename[:pos], int(filename[pos + 1:])
        if letter not in best_scores:
            best_scores[letter] = score
        else:
            best_scores[letter] = max(best_scores[letter], score)

    sum_score = 0
    for letter in sorted(best_scores.keys()):
        score = best_scores[letter]
        sum_score += score
        print(letter, score)
    print("Total score:", sum_score)

    print("Copying best files...")
    if os.path.exists(best_answers_dir):
        shutil.rmtree(best_answers_dir)
    os.mkdir(best_answers_dir)
    for letter in sorted(best_scores.keys()):
        score = best_scores[letter]
        src_file = os.path.join(answers_dir, "{}_{}.out".format(letter, score))
        dst_file = os.path.join(best_answers_dir, "{}_{}.out".format(letter, score))
        shutil.copy(src_file, dst_file)

    print("Zipping answers...")
    zip_filename = "submit_{}".format(sum_score)
    zip_filename_with_ext = zip_filename + ".zip"
    if os.path.exists(zip_filename_with_ext):
        os.remove(zip_filename_with_ext)

    shutil.make_archive(zip_filename, "zip", best_answers_dir)
    print("End zipping answers, result in {}".format(zip_filename_with_ext))

    print("Copying sources...")
    if os.path.exists(last_sources_dir):
        shutil.rmtree(last_sources_dir)
    os.mkdir(last_sources_dir)
    shutil.copy("solver.h", last_sources_dir)
    shutil.copy("checker.h", last_sources_dir)
    shutil.copy("main.cpp", last_sources_dir)
    shutil.copy("pack.py", last_sources_dir)
    shutil.copy("run.sh", last_sources_dir)

    print("Zipping sources...")
    src_zip_filename = "submit_sources"
    src_zip_filename_with_ext = src_zip_filename + ".zip"
    if os.path.exists(src_zip_filename_with_ext):
        os.remove(src_zip_filename_with_ext)

    shutil.make_archive(src_zip_filename, "zip", last_sources_dir)
    print("End zipping sources, result in {}".format(src_zip_filename_with_ext))


if __name__ == "__main__":
    main()
