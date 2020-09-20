#!/usr/bin/env python3

inputfile=open(input("Enter source file name: "),"r")  #source file
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
    #print(lines, " lines copied successfully.");
except:
    print("Error :-")
    
