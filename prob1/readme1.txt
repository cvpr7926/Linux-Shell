This executes almost all the linux commands using system() function.

The requirements to execute this terminal are:
-->A linux ubuntu machine.
-->GCC should be installed in the machine :
	If GCC is not installed in your machine,do the following:
	open the terminal on your machine and run the following commands:
		--> "sudo apt update"
		--> "sudo apt install build-essential"
		OR
		--> "sudo apt install gcc"
	To check if installed then run the following command:
		--> "gcc --version"
--> libreadline:
Install libreadline in your machine:
For that run the following command on your terminal:
		--> "sudo apt-get install libreadline8 libreadline-dev"
Now you are ready to execute the terminal!

steps to execute:

-->change the directory to the directory where the files are located.
-->Now run the following commands:
	--> "make" (To compile the executable files.)
	--> "./myshell" (To execute the terminal.)
commands except help are executed using system() function.
