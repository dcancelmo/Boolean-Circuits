Daniel Cancelmo
Project 05 - Boolean Circuits
CSC 173 - Professor Ferguson
May 3, 2017
I did not collaborate with anyone on this assignment.
ReadMe file

I had no group or partner for this project.

To build the project type

	make

in the command line when in the directory containing the files and Makefile. Then to run type

	./boosim

The progrma will print the tests of each circuit on all possible inputs. Print statements state what input is about to be passed in and what the output should be if done correctly.

Code explanation:
To implement NOR and NAND Gates I used an OR Gate or AND Gate respectively and then passed in the result of those into an Inverter Gate/NOT Gate. These are algebraically equivalent.

Extra credit:
One bit adder circuit (FOCS Fig. 13.10) implemented and tested correctly on all possible inputs