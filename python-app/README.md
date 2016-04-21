# Python files of the LSPiD
We collect here the Python Scripts to make the LSPiD working.
First pull the scripts into the develop branch and wait
for the merge by the Project managers.

## Files description

### LSPiD.apk
Android Package of the project's app to configure the server

### conf.txt
Configuration file of the server.
It collects: parents e-mail, hour and minutes to take the pills

### daemon.py
Server daemon to run the service in background.
It checks if the pills were taken, sends alarms, updates data.

### functions.py
The file collects the functions that were executed by other scripts.
Each function must to include the following variables that describes it self.
*command = "shell command"*
*info = "command info"*

### shell.py
A basic Python shell that runs the functions of *functions.py* by typing into
the shell the commands and *help* to get a basic info screen.

### webapp.py index.html style.css
Cherrypy-based Python WebApp to configure the server via HTTP or with the
Android App

### logo.png Pills-red-icon.png
App's logos
