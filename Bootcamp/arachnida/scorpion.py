#!/goinfre/djanssen/miniconda3/envs/42AI-djanssen/bin/python3.7

import string
import argparse
from PIL import Image
from PIL.ExifTags import TAGS
#from exif import Image
import sys
import os
import datetime

class colors:
    fail = '\033[91m'
    ok = '\033[92m'
    purple = '\033[95m'
    cyan = '\033[96m'
    yellow = '\033[93m'
    reset = '\033[0m'


def parser():
    parser = argparse.ArgumentParser(
        prog = "Scorpion",
        description = "Search for EXIF data and other metadata.")
    parser.add_argument("images", type=str, nargs="+", help="Images files to check")
    arg = parser.parse_args()
    return arg.images

def get_meta(files):
    for i,file in enumerate(files):
        print(colors.purple + "\nImage %i:\t%s\n"%(i,file.split('/')[-1]) + colors.reset)
        try:
            with Image.open(file) as fileOpen:
                image = fileOpen
        except:
            print(colors.fail + "fail to open file: ",file.split('/')[-1] + colors.reset)
        else:
            fileInfo = os.stat(file)
            print(colors.cyan + "\tCreated at:\t" + colors.ok + str(datetime.datetime.fromtimestamp(fileInfo.st_ctime)) + colors.reset)
            print(colors.cyan + "\tModified at:\t" + colors.ok + str(datetime.datetime.fromtimestamp(fileInfo.st_mtime)) + colors.reset)
            try:
                exif = image.getexif()
            except:
                print(colors.fail + "\n\tno exif for ",file.split('/')[-1] + colors.reset)
                continue
            else:
                print(colors.yellow + "\n\t\t\tEXIF" + colors.reset)
                for tag in exif:
                    print(colors.cyan + "\ttag: {:<20} {}{}".format(TAGS.get(tag), colors.ok, exif.get(tag)) + colors.reset)

if __name__ == "__main__":
    arg = parser()
    get_meta(arg)
    exit()