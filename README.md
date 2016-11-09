# Open With CMD
**Auto-pauses and times applications.**

Console applications have one problem, they auto-close when they are not opened via `Command Prompt`.

Open With CMD automates the process of opening the `Command Prompt` in the folder, typing the app's name and pressing `enter` to run the app. It offers the same privilege on the said process by *keeping the console window alive after exit.* It also shows *execution time* after the app's execution. 

This lightweight programmer's tool will be a great fit for command line gurus especially those who run scripts. Scripts can be tested without worrying about *not reading the exceptions that may cause the script to exit quickly*, leaving insufficient time to read and analyze the exception message.

# Table of Contents
1. [User's Hub](#users-hub)
  1. [How to use](#how-to-use)
  2. [How it works](#how-it-works)
    1. [For GUI-based applications](#for-gui-based-applications)
    2. [For console applications](#for-console-applications)
2. [Contributor's Hub](#contributors-hub)
  1. [How to configure setupinstaller file](#how-to-configure-setupinstaller-file)

# User's Hub 

## How to use 
1. Right click on the app (shortcut `.lnk` or the app `.exe` itself) you want to open
2. Click `Open with command prompt` on the context menu.

  ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/screenshots/context%20menu%20shot.png)

## How it works 

### For GUI-based applications, 
- A seperate console window is opened.
  
  ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/screenshots/gui%20shot.png) 

- Debugging/exception/log messages is shown in the separate console window.
- Once the GUI closes,
 - Separate console window remains opened.
 - Execution time is shown in the seperate console window.
  ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/screenshots/gui%20shot%20end.PNG) 

### For console applications,
- No separate console window will be opened.
- Debugging/exception/log messages is shown in main console window.
- Once the execution is done,
 - Main console window remains opened.
 - Execution time is shown in main console window.
   ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/screenshots/console%20shot%20end%20wd%20error.PNG) 

# Contributor's Hub
## How to configure setup/installer file
- Make sure you have [InstallForge](http://installforge.net/) installed on your machine.
  - If not, go to http://installforge.net/download/ and download `IFSetup.exe`
  - Then, run `IFSetup.exe`
- Open [`setup.ifp`](https://github.com/raymelon/open-with-cmd/blob/master/setup.ifp) with `InstallForge`

- The following are the setup information (don't forget to `save` the `InstallForge` file & `build` the exe installer after editing)

| Tab | Subtab | Details | Screenshot |
| --- | --- | --- | --- |
| `General` | `General` | App's basic information | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20general.JPG) |
| `Setup` | `Files` | Files to be put on installation path | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20setup%20files.JPG) |
| `Dialogs` | `License` | App's [Mozilla Public License Version 2.0](https://github.com/raymelon/open-with-cmd/blob/master/LICENSE) license | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20dialogs%20license.JPG) |
| `Dialogs` | `Finish` | Runs [`add-to-context-menu.bat`](https://github.com/raymelon/open-with-cmd/blob/master/src/add-to-context-menu.bat) at setup finish | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20dialogs%20finish.JPG) |
| `System` | `Shortcuts` | Options for shortcuts' destinations | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20system%20shortcuts.JPG) |
