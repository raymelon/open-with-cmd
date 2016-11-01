/**
 * uninstall.c
 * Uninstalls Open with cmd
 *
 * (c) May 2015 Raymel Francisco
 */
 /*
 	1. Delete things not to be used to uninstall process
 	2. Create a ps1 script, use that to put folder cleaner to startup
 	3. Create bat1 file to run bypass ps script permissions
 	4. Create folder cleaner
 	5. Create bat2 file, use that to delete main exe, scripts and bat file
 	6. Run bat1
 	7. Run bat2
	8. Restart

 	uninstall.exe (del things not to be used to uninstall process) ->
 	create cleaner -> bat1 -> ps1 -> bat2 -> restart -> cleaner
 */
#ifndef _WIN32
 	#define _WIN32
#endif

#include <stdio.h>
#include <windows.h>

/* @discussion	Removes files not used in uninstall process
 *				Uses 'del' command of Windows Batch Script to delete files
 */
void removeFiles() {
	fputs("Removing open-with-cmd.exe...\n", stdout);

	// Kills open-with-cmd.exe process before deleting it
	system("@taskkill /f /im \"open-with-cmd.exe\"");
	system("@del \"open-with-cmd.exe\"");
	system("@del \"terminal.ico\"");
	system("@del \"icon-license.txt\"");
	system("@echo Deleting registry keys...");
	system("@reg delete \"HKEY_CLASSES_ROOT\\*\\shell\\Open with command prompt\" /f");
	system("takeown /f uninstall.exe");
	system("@pause");
}
/* @abstract	Removes filename from path, leaving only the current directory
 *
 * @discussion 	Gets path length using while loop, increments until the character before null
 * 				Decrements from path's last character until the a backslash character is reached
 *				Deletes the characters from backslash's index up to path length, thus retaining the path
 *
 * @param		path 	The current path of the executing file
 */
void editPath(char *path) {
	int len = 0;
	while(path[len++] != 0);
	while(path[--len] != '\\');
	path[len] = 0;
}
void createScripts() {
	FILE *add = fopen("add-cleaner-to-startup.ps1", "w");
	fputs("Set-ExecutionPolicy Bypass\n", add);
	fputs("$path = [Environment]::GetFolderPath(\"Startup\")\n", add);
	fputs("Copy-Item \"open-with-cmd-clean.bat\" $path\n", add);
	fclose(add);
	add = fopen("add-cleaner-to-startup.bat", "w");
	fputs("powershell.exe -noprofile -executionpolicy bypass -file add-cleaner-to-startup.ps1", add);
	fclose(add);
}
/* @abstract	Creates self-deleting cleanup batch file that will only run at startup after uninstall process
 *				The self-deleting cleanup batch file will remove files used in uninstall process
 *
 * @param		editedPath		The current directory
 */
void createCleaner(char *editedPath) {
	FILE *cleaner = fopen("open-with-cmd-clean.bat", "w");
	//fprintf(cleaner, "takeown /f \"%s\\uninstall.exe\"\n", editedPath);
	fprintf(cleaner, "icacls \"%s\\uninstall.exe\" /grant \"Everyone\":f\n", editedPath);
	fprintf(cleaner, "icacls \"%s\" /grant \"Everyone\":f\n", editedPath);
	fprintf(cleaner, "del \"%s\\uninstall.exe\"\n", editedPath);
	//fprintf(cleaner, "del \"%s\\add-cleaner-to-startup.bat\"\n", editedPath);
	//fprintf(cleaner, "del \"%s\\add-cleaner-to-startup.ps1\"\n", editedPath);
	fprintf(cleaner, "rd \"%s\"\n", editedPath);
	fputs("@echo Open with cmd is uninstalled.\npause\n", cleaner);
	fputs("del \"open-with-cmd-clean.bat\"", cleaner);
	fclose(cleaner);
}
/* @discussion	Calls add-cleaner-to-startup.bat
 *				add-cleaner-to-startup.bat calls a Windows PowerShell script that will add
 *				the created file to current user's startup folder
 */
void copyCleanerToStartup() {
	system("add-cleaner-to-startup.bat");
}
void promptRestart() {
	if (MessageBox(NULL, "Uninstallation is almost complete. Please restart to complete.\nDo you want to restart?", 
				"Uninstall Open with cmd",
				MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND) == IDYES)
		system("@shutdown /r /t 0");
}
/* @discussion	Removes cleaner from current directory
 */
void removeCleaner() {
	system("@del open-with-cmd-clean.bat");
	system("@del add-cleaner-to-startup.bat");
	system("@del add-cleaner-to-startup.ps1");
}
int main(int argc, char *args[]) {
	if (MessageBox(NULL, "Do you really want to uninstall Open with cmd?", 
					"Uninstall Open with cmd", 
					MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND) == IDNO)
		return;
	removeFiles();
	editPath(args[0]);
	createCleaner(args[0]);
	createScripts();
	copyCleanerToStartup();
	removeCleaner();
	promptRestart();
}
