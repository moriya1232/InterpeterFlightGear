
#the project- projectFly

projectFly is project that interpret text file with code and in help this code it make a plane in the simulator that fly airplane.

#downloads

we need to download and install the application "FligheGear". Furtheremore we need a text file with the code, which will be one of the arguments. Additionally we need a xml file with all the varible names in the simulator, which we will put in the flightgear/properties/data folder.

#install the flightGear

Instructions for download can be found on the website

 https://www.flightgear.org/download/main-program/



# Compiling the Code
 
To compile, we need to provide a text file that list all of the commands of the plane. It will be provided as a program argument 

To compile from the command line:
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

# Running the Program
 
For the program to run well, first we compile and then run the program, after we open and run the FlightGear application, which should connect with our program, through the server we opened. Once we have a  connection between the simulator and our program, the plane should start to move, and shortly after, takeoff and fly. 

# How The Program Works
 
 We interpret the fly.txt file into commands so we can use them. We will open 3 threads which will run at the same time. One thread is in the main, which runs the main program, the second is a thread that keeps a connection between the simulator and our program, which is how we will send the commands to the simulator to update the values,  and the third is also in connection with the server,which the server will update our values. Thecommunication between these threads enables allows us to share information which flys the plane.

https://github.com/shiloleopold/projectFly
