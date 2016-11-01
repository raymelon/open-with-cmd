#
# create-installer-folder.py
#
# setup file for installer.py
# creates setup folder 
# adds necessary files to Open with cmd setup folder
#
# (c) May 2015 Raymel Francisco
#
# *since tkinter doesn't support 1 bundle_file yet, bundle_files is set to 2

def compile():
	import py2exe
	from sys import argv
	from distutils.core import setup
	argv.append('py2exe')
	setup(
		#options={'py2exe':{'bundle_files':1, 'compressed': True, 'dll_excludes':['tcl86t.dll', 'tk86t.dll', '_tkinter.pyd']}},
		options={'py2exe':{'bundle_files':2, 'compressed': True, 'optimize':2, 'dist_dir':'open-with-cmd-1.0-setup'}},
		windows=[{'script':'src/installer.py', 'icon_resources':[(1, 'res/terminal.ico')], 'version':'1.0'}],
		#options={'py2exe':{'excludes':['tkinter'], 'bundle_files':1, 'compressed': True, 'dll_excludes':['tcl86t.dll', 'tk86t.dll']}},
		zipfile=None,
		url='none',
		)

def copyFiles():
	from os import system
	def copy(src, des):
		system('copy "' + src + '" "' + des + '"')

	copy('bin\\open-with-cmd.exe', 'open-with-cmd-1.0-setup')
	copy('res\\terminal.ico', 'open-with-cmd-1.0-setup')
	copy('res\\icon-license.txt', 'open-with-cmd-1.0-setup')
	copy('bin\\uninstall.exe', 'open-with-cmd-1.0-setup')
	#copy('src\\add-to-context-menu.bat', 'open-with-cmd-1.0-setup')
	system('pause')

compile()
copyFiles()
#from os import system
#system('finalize-folder.bat')
