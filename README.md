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

