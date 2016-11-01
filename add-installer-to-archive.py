#
# add-installer-to-archive.py
#
# creates a zip archive, and adds the setup folder to it 
#
# (c) May 2015 Raymel Francisco

from zipfile import ZipFile, ZIP_DEFLATED
from os import path, walk, getcwd
import zlib

def addToArchive(folderName):
	for dirpath, dirs, files in walk(folderName):
		for file_ in files:
			archive.write(path.join(dirpath, file_))

with ZipFile("open-with-cmd-1.0-setup.zip", "w", ZIP_DEFLATED) as archive:
	addToArchive('open-with-cmd-1.0-setup')
