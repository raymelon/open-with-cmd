
<h1 align="center"> Open With CMD <br> <h3 align="center">Command Prompt, with a pause.</h3> </h1>

[![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0)
[![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](http://creativecommons.org/licenses/by/4.0/)
[![Build Status](https://travis-ci.org/raymelon/open-with-cmd.svg)](https://travis-ci.org/raymelon/open-with-cmd)
[![Coverage Status](https://coveralls.io/repos/github/raymelon/open-with-cmd/badge.svg?branch=master)](https://coveralls.io/github/raymelon/open-with-cmd?branch=master)
![](https://reposs.herokuapp.com/?path=raymelon/open-with-cmd)

### Auto-pauses and times applications.  <img align="right" src="https://github.com/raymelon/open-with-cmd/blob/master/res/terminal.ico">

Console applications have one problem, they auto-close when they are not opened via `Command Prompt`.

Open With CMD automates the process of opening the `Command Prompt` in the folder, typing the app's name and pressing `enter` to run the app. It offers the same privilege on the said process by *keeping the console window alive after exit.* It also shows *execution time* after the app's execution.

This lightweight programmer's tool will be a great fit for command line gurus especially those who run scripts. Scripts can be tested without worrying about *not reading the exceptions that may cause the script to exit quickly*, leaving insufficient time to read and analyze the exception message.

### Download :love_letter:
[`open-with-cmd-1.0-setup.exe`](https://github.com/raymelon/open-with-cmd/releases/download/v1.0/open-with-cmd-setup.exe) :new:

### Share with :heart::blue_heart:
[![Tweet](https://img.shields.io/twitter/url/http/shields.io.svg?style=social)](https://twitter.com/intent/tweet?text=Check%20out%20Open%20with%20CMD!%20Still%20your%20Command%20Prompt,%20with%20a%20pause.%20%40github%20https://github.com/raymelon/open-with-cmd)

# Table of Contents
1. [User's Hub](#users-hub)
   1. [How to use](#how-to-use)
   2. [How it works](#how-it-works) 
      1. [For GUI-based applications](#for-gui-based-applications)
      2. [For console applications](#for-console-applications)
   3. [Will run on...](#will-run-on)

2. [Contributor's Hub](#contributors-hub)
   1. [Tools needed](#tools-needed)
   2. [How to configure setup/installer file](#how-to-configure-setupinstaller-file)
  
3. [Licenses](#license)
4. [History](#history)
5. [Releases](#releases)
  
# User's Hub
<img align="right" width="50%" src="https://github.com/raymelon/open-with-cmd/blob/master/screenshots/context%20menu%20shot.png">

## How to use
   
1. Right click on the app (shortcut `.lnk` or the app `.exe` itself) you want to open


2. Click `Open with command prompt` on the context menu.
<br>
<br>
<br>

## How it works 

### For GUI-based applications, 
- A seperate console window is opened.
  
  ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/screenshots/gui%20shot.png) 


- Debugging/exception/log messages is shown in the separate console window.


- Once the GUI closes,  <img align="right" src="https://github.com/raymelon/open-with-cmd/blob/master/screenshots/gui%20shot%20end.PNG">
 
 
 - Separate console window remains opened.
 
 
 - Execution time is shown in the seperate console window.
<br>
<br>
<br>
<br>
<br>
<br>

### For console applications,
- No separate console window will be opened.
- Debugging/exception/log messages is shown in main console window.
- Once the execution is done,
 - Main console window remains opened.
 - Execution time is shown in main console window.
   ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/screenshots/console%20shot%20end%20wd%20error.PNG) 

## Will run on...
- Windows 7 to 10 (tested :100:)
- Windows Vista & XP (untested :x:)
- Below XP (run at your own risk :warning:)

# Contributor's Hub [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)]()
## Tools needed
- [C](http://www.open-std.org/jtc1/sc22/wg14/) Compiler: [GCC, the GNU Compiler Collection](https://gcc.gnu.org/) 
 - Tested on versions [4.8.1](https://gcc.gnu.org/gcc-4.8/) to [5.3.0](https://gcc.gnu.org/gcc-5/)
 - Untested on newer versions
- Resources Compiler: [windres](https://sourceware.org/binutils/docs/binutils/windres.html)
- Installer Compiler: [NSIS 3.0](http://nsis.sourceforge.net/Main_Page)
- Installer Editor: [HM NIS Edit](hmne.sourceforge.net)

## How to configure setup/installer file
- Make sure you have atleast [NSIS 3.0](http://nsis.sourceforge.net/Main_Page) and [HM NIS Edit](hmne.sourceforge.net) installed on your machine.
  - If not, go to http://nsis.sourceforge.net/Download and download `nsis-3.0-setup`
  - Then, run `nsis-3.0-setup`
- Open [`setup.nsi`](https://github.com/raymelon/open-with-cmd/blob/master/nsis-3.0-setup) with `HM NIS Edit`
- Make sure to `Compile` `setup.nsi` after editing it.

# Licenses [![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0) [![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](http://creativecommons.org/licenses/by/4.0/)
This project uses Mozilla Public License Version 2.0
- [See the full LICENSE file](https://github.com/raymelon/open-with-cmd/blob/master/LICENSE)
- [MPL 2.0 Site](https://www.mozilla.org/en-US/MPL/2.0/)
- [MPL 2.0 FAQs](https://www.mozilla.org/en-US/MPL/2.0/FAQ/)
- [MPL 2.0 Overview](http://oss-watch.ac.uk/resources/mpl2)

[`terminal.ico`](https://github.com/raymelon/open-with-cmd/blob/master/res/terminal.ico) and [`terminal.png`](https://github.com/raymelon/open-with-cmd/blob/master/res/terminal.png) uses Creative Commons Attribution 4.0 International
 - [Icon license file](https://github.com/raymelon/open-with-cmd/blob/master/res/icon-license.txt)
 - [CC BY 4.0 Site](https://creativecommons.org/licenses/by/4.0/)
 - [CC BY 4.0 Legal Code](https://creativecommons.org/licenses/by/4.0/legalcode)

# History
- April 2015 (started)
- November 2016 (github debut)

# Releases
[v1.0](https://github.com/raymelon/open-with-cmd/releases/tag/v1.0)
