# QoLinux-Scripts
Welcome to Quality of Life Linux Scripts. These are all the scripts I use to make git, linux, and ssh as useable as possible. I find git to be clunky and when you
  have a personal git server (way too many keys). This is how I make my own life (and hopefully yours) way easier!


NOTE: These are all just wrapper for common linux commands and git management. This is intentional so that any problems which are encountered and not covered by
        these commands can be fixed by defaulting to git and linux commands. Allows for shorthand and the same deep control offered by the platforms


INSTALLATION:
- Download and install Git and SSH on a remote server and your desired computer. 
  - The username on the remote server will be referred to as USER and its ip as ADDRESS 
- Establish passwordless SSH connection between git server and desired computer (see ESTABLISHING SSH below)
- Create 2 folders for default and archived projects to be stored. These locations will be referred to as ARCHIVE_LOCATION and DEFAULT_LOCATION
- Download this file somewhere on your computer
- Add that directory to PATH variable (located at /etc/environment) 
- Fill out and save scripts-config file as follows:
  - ARCHIVE_LOCATION, DEFAULT_LOCATION, USER, and ADDRESSS must be filled out with the values they were assigned above 
  - NOTE: Make usre to use full paths. It shouldn;t be an issue if you don't but it definitely will not be if you do.
- QED 


COMMANDS:
- repo: Takes repo names as args. This create a bare git repo on your remote server and downloads it to your computer. Will locally save git repo wherever you call
              this command 
- migrate: Takes existing NON-GIT folder names as args. This create git repo on server, moves not git folder contents into new repo, save the repo on server, then
              deletes the old, non-git folder off your computer. Will locally save this repo wherever you call this command. 
- archive: Takes name of repos you want to archive as args. This command will move specified repos into archive location and remove them from your computer.
              These repos can be accessed later by specifying the -a flag with get and can be unarchived with the 'unarchive' command below.
              NOTE: MUST BE IN SAME WORKING DIRECTORY AS GIT REPO
- unarchive: Takes name of repos you want to unarchive as args. This will move all specified repos from the archive to unarchived locations. 
              NOTE: THIS WILL NOT DOWNLOAD THE UNARCHIVED REPO TO YOUR COMPUTER
- save: This take the message you would like to commit as arg. adds all changed files, commits changes, and save repo to server.
- update: This command will pull updates from the git repo
- destroy: deletes a git repo locally and on the git server. THIS CANNOT BE UNDONE
- add: Takes filenames as args. This command adds a file to your git repo and saves the change to the server.
- del: Takes filenames as args. This removes a file from the git repo and updates the server
- mov: will move file from one location to another, removing the old file from the repo and adding the new one automatically.
- folder: Takes folder names as args. This creates a new folder and updates the git server 
- get: Takes git repos as args and -a flag to search archived repos. This will clone any git repo onto your computer in current directory if it exists in the
              default location. If -a flag is specified then it will search the archived repos and clone it to your computer. IT WILL NOT UNARCHIVE REPO IF CLONED.
- ignore: This will add any args to a git ingnore file wherever you specify the command
- git-login: Will remote ssh you into your git server
- exe: Takes files to exe or no args. Converts all args into executable files. If no args are specified, all files in working directory will become executable
- unexe: Takes files to remove executable privildges from or no args. Will covert all args, or entire working directory if none are specified, to unexecutable


ESTABLISHING SSH:
- NOTE: You will want to set up passwordless ssh on your SERVER, this takes a lot of the friction out of the program.
- How to enable SSH on Ubuntu: https://linuxize.com/post/how-to-enable-ssh-on-ubuntu-18-04/
- How to enable SSH on Raspberry Pi: https://www.raspberrypi.org/documentation/remote-access/ssh/
- How to enable passwordless SSH on Raspberry Pi: https://www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md
