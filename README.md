Private repo

The part that generates assembly instructions can be found under Compilator folder, and should be tested using Makefile or by typing the script from inside the Makefile.
The hardware description is under "Procesor" folder and it contains only  .vhd and .prj files



How to start the compilator:
Install flex and bison in case you do not have them.
Run ./MakeInstall and be sure you provide in the current working directory a "fakeC" file that should have the following syntax
