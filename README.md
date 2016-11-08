# Open With CMD
Auto-pauses and times applications.

Console applications have one problem, they auto-close when they are not opened via Command Prompt.
Open With CMD keeps the console window alive. It also shows execution time after the app's execution.

# How it works
### For GUI-based applications,
- A seperate console window is opened.
- Debugging/exception/log messages is shown in the separate console window.
- Once the GUI closes,
 - Separate console window remains opened.
 - Execution time is shown in the seperate console window.

### For console applications, 
- No separate console window will be opened.
- Debugging/exception/log messages is shown in main console window.
- Once the execution is done,
 - Main console window remains opened.
 - Execution time is shown in main console window.

# How to configure setup/installer file
- Make sure you have [InstallForge](http://installforge.net/) installed on your machine.
  - If not, go to http://installforge.net/download/ and download `IFSetup.exe`
  - Then, run `IFSetup.exe`
- Open [`setup.ifp`](https://github.com/raymelon/open-with-cmd/blob/master/setup.ifp) with `InstallForge`

- The following are the setup information (don't forget to save the InstallForge file & build the exe installer after editing)

| Tab | Subtab | Details | Screenshot |
| --- | --- | --- | --- |
| `General` | `General` | App's basic information | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20general.JPG) |
| `Setup` | `Files` | Files to be put on installation path | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20setup%20files.JPG) |
| `Dialogs` | `License` | App's [Mozilla Public License Version 2.0](https://github.com/raymelon/open-with-cmd/blob/master/LICENSE) license | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20dialogs%20license.JPG) |
| `Dialogs` | `Finish` | Runs [`add-to-context-menu.bat`](https://github.com/raymelon/open-with-cmd/blob/master/src/add-to-context-menu.bat) at setup finish | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20dialogs%20finish.JPG) |
| `System` | `Shortcuts` | Options for shortcuts' destinations | ![alt tag](https://github.com/raymelon/open-with-cmd/blob/master/installforge%20tutorial/ift%20system%20shortcuts.JPG) |
