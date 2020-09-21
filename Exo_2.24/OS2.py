#!/usr/bin/env python3
try:
    inputfile=open(input("Enter source file name: "),"r")  #source file
except:
    print('This file doesn\'t exxist')
    exit()
outputfile=open(input("Enter destination file name: "),"w")  #destination file
lines=0
try:
    #read each line from inputfile
    for line in inputfile:
       # lines=lines+1
        #copy to other file.	
        outputfile.write(line)

    inputfile.close()  #close inputfile
    outputfile.close() #close outputfile
    print('The file ',inputfile.name, 'is copied in ',outputfile.name)
    #print(lines, " lines copied successfully.");
except:
    print("Error :-")
    
