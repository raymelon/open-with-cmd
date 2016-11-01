# 
# installer.py
# Open with cmd installer
# 
# (c) May 2015 Raymel Francisco

from tkinter import *
from tkinter import ttk
from tkinter.filedialog import askdirectory
from tkinter import messagebox

class initialize:
	def main():
		initialize.systemCheck()
		initialize.displayWindow()
		install.intro()
		root.window.mainloop()

	def displayWindow():
		root.window.title('Install Open with cmd')
		root.window.geometry('400x300')
		root.window.resizable(False, False)
		root.window.iconbitmap('terminal.ico')
		root.showButtons()

	def systemCheck():
		from platform import system
		if system() is not 'Windows':
			messagebox.showerror(message="You can't install Open with cmd because the platform you're using is not Windows.", title='Oops!')

class root:
	from os import sys
	window = Tk()
	next = ttk.Button(window, text='Next >', state=DISABLED)
	cancel = ttk.Button(window, text='Cancel', command=sys.exit)
	style = ttk.Style()
	style.theme_use('clam')

	def showButtons():
		root.next.place(x=123, y=245)
		root.cancel.place(x=199, y=245)

	buttonsClicked = lambda clean: root.next.config(command=clean)

class install:
	def intro():
		frame = ttk.Frame(root.window, width=400, height=220)
		frame.pack()

		text = '\nWelcome to Open with cmd installer.\nThis setup will install Open with cmd to your computer.\n'
		ttk.Label(frame, text=text, anchor=CENTER, font='Segoe 9', width=400).pack()
		
		license = 'No license yet.'
		ttk.Label(frame, text='License', font='Segoe 10 bold').pack()
		licenseHolder = Text(frame, wrap=WORD, font="Arial 10", width=45, height=8)
		licenseHolder.insert(END, license)
		licenseHolder.config(state=DISABLED)
		licenseHolder.pack()

		isChecked = IntVar()
		checkBox = ttk.Checkbutton(frame, text='I understand and accept the license.', variable=isChecked, command=lambda: root.next.config(state=ACTIVE) if isChecked.get() else root.next.config(state=DISABLED)).pack()

		def clean():
			frame.destroy()
			install.setpath()

		root.buttonsClicked(clean)
		
	def setpath():
		from os import environ

		initialPath = environ['PROGRAMFILES'] + r'\Open with cmd'
		frame = ttk.Frame(root.window, width=400, height=220)
		frame.pack()

		ttk.Label(frame, text='Choose where to install:', font='Segoe 10 bold').place(x=20, y=80)
		path = ttk.Entry(frame, width=45)
		path.insert(END, initialPath)
		path.place(x=20, y=110)

		def choosePath():
			initialPath = askdirectory(initialdir = '.', title='Choose a path')
			if initialPath != '':path.delete(0, END)
			path.insert(0, initialPath)

		browse = ttk.Button(frame, text='Browse...', command=choosePath).place(x=300, y=107)
		ttk.Label(frame, text="\n*Note: Forward slashes are okay.\n Don't worry, the installer can handle it.", font='Segoe 10').place(x=20, y=133)

		def clean():
			frame.destroy()
			install.copyFiles(initialPath)

		root.buttonsClicked(clean)

	def copyFiles(destination):
		from os import system, getcwd, mkdir
		from os.path import exists
		from shutil import rmtree, copytree, copy2

		if exists(destination): rmtree(destination)

		mkdir(destination)
		frame = ttk.Frame(root.window, width=400, height=240).pack()

		ttk.Label(frame, text='Copying files...', font='Segoe 10 bold').place(x=20, y=15)
		
		progress = Text(frame, wrap=WORD, font="Arial 10", width=50, height=10)
		progress.place(x=20, y=70)

		bar = ttk.Progressbar(root.window, orient='horizontal', length=355, mode='determinate', maximum=125, value=0)
		bar.place(x=20, y=40)

		bar.start()
		copy2('open-with-cmd.exe', destination)
		#bar.step(25)
		bar.config(value=25)
		progress.insert(END, 'Copied open-with-cmd.exe')
		copy2('terminal.ico', destination)
		#bar.step(25)
		bar.config(value=50)
		progress.insert(END, '\nCopied terminal.ico')
		copy2('icon-license.txt', destination)
		#bar.step(25)
		bar.config(value=75)
		progress.insert(END, '\nCopied icon-license.txt')
		copy2('uninstall.exe', destination)
		#bar.step(25)
		bar.config(value=100)
		progress.insert(END, '\nCopied uninstall.exe')
		bar.stop()
		bar.config(value=125)

		def addToContextMenu():
			from win32api import GetShortPathName
			location = GetShortPathName(destination) + '/OPEN-W~1.EXE'
			system(r'reg add "HKEY_CLASSES_ROOT\*\shell\Open with command prompt" /t REG_SZ /v "" /d "Open with command prompt" /f')
			system(r'reg add "HKEY_CLASSES_ROOT\*\shell\Open with command prompt" /t REG_EXPAND_SZ /v "Icon" /d ""' + location + '",0" /f')
			system(r'reg add "HKEY_CLASSES_ROOT\*\shell\Open with command prompt\command" /t REG_SZ /v "" /d ""' + location + '" ""%1""" /f')

		addToContextMenu()
		progress.insert(END, '\nOpen with cmd is added to context menu\n\nThank you for installing!')
		progress.config(state=DISABLED)

		root.next.destroy()
		root.cancel.place(x=300, y=245)
		root.cancel.config(text='Finish')

initialize.main()
