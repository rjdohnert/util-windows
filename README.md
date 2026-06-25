Util-windows is a complimentary package to Microsofts Coreutils that they 
have just released at Build 2026.  It contains clones of system management
tools you find in BSD and in Linux.  These tools are written in C++ and have 
been tested on Windows 11, Windows Server 2022 and Windows Server 2025.  They 
have been tested with Powershell and cmd.

Requirements
-------------
su requires Powershell 7 to launch an Administrator Powershell consoile

Commands
--------

Calendar - List the current date
driveinfo - Lists all available drives, filesystem type, used and free space
lsbt - Lists all available Bluetooth devices
lscpu - Lists the processor installed on your system
lspci - lists all PCI devices installed on your system
lsusb - Lists all available USB devices on your system
mem - Lists all memory statistics on your system including virtual memory
su - Launches an admin console. su -cmd launches an admin cmd session
uname - lists system information including architecture type and Windows NT version

Install
-------

Copy all commands from the releases folder into C:\Windows\system32 folder


Main Developer:  Roberto J Dohnert, CTO, PC/OpenSystems LLC
