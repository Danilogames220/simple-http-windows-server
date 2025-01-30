# simple-http-windows-server
old project made in 2024

  While learning about sockets, i tried coding my own http server to understand how sockets work and how to use them.
The code is very simple and dosen't have much error handling, since i wanted to focus on the core elements that make the code work.

  Since i was coding this project on windows, i decided to use a powershell script to compile the project.
to compile it, run the make.ps1 file or gcc main.c renderfile.c -o server.exe -lws2_32
