# *SensorFusionAlgo*
Sensor fusion is the process of merging data from multiple sensors such that to reduce the amount of uncertainty that may be involved in a robot navigation motion or task performing. Sensor fusion helps in building a more accurate world model for the robot to navigate and behave more successfully.

## *A Simple Multi-Sensor Data Fusion Algorithm Based on Principal Component Analysis*
When we measure data (let’s focus on the example of getting data using sensors), we usually use the measures from different sensors to assure correctness. One of the methods we can use to calculate a single value from our input data is to perform a sensor fusion algorithm. The algorithm takes as inputs the row data from the sensors, perform some calculations and returns a value. The value generated by the algorithm is representative of the correct raw data from the sensors (i.e. there may be sensors giving wrong measures). The algorithm is executed every time new sensor data is received. The algorithm receives the data from all the sensors synchronously. There are different methods for doing this, but we will focus in one of them i.e. PCA.

## *Downloading the Sensor Fusion Algorithm Software*
1.	Install Git (User can use Git bash or any other software of choice to clone the project).
2.	Create a new folder for the project. Right Click inside the folder and open a git bash here. Right Click +” Git Bash here”.
3.	Type the following command in the git terminal:
Git clone https://github.com/shreyataneja/SensorFusionAlgo.git
4.	Or go to the link https://github.com/shreyataneja/SensorFusionAlgo and click on Clone or Download and download the zip folder of the software.


## *Sensor Fusion Algorithm Software Design (Architecture)*
![SensorFusionAlgo](https://github.com/shreyataneja/SensorFusionAlgo/blob/master/doc/SensorFusionAlgoDesign.jpg "SensorFusionAlgo")

## *Compiling and Running the Sensor Fusion Algorithm Software*
To compile and run the tests for the software, follow these steps:
1.	Compile the project
	1.	Open the folder containing the cloned or downloaded software from git.
	2.	Open Bash Prompt inside the folder i.e. Right Click + ”Bash Prompt here”.
	3.	To compile the project, type in the bash prompt :
		Make clean; make all

2.	Run the software and test with input file of your choice. Place the input file in the inputs_and_results folder.
	1.	From the previous command, you now have new folders created , i.e. bin and build , the tests will run in the bin folder . 
	Type: cd bin
	2.	To run test with input file of your choice, for example, input_sensorfusion.csv, type:
	./MAIN.exe ../inputs_and_results/test_input_1.csv
	3.	To run the software with different input files, simply create a .csv file with desired inputs and replace in command with new file name
	4.	The output file will be created in same folder as of the input file in the following format: inputsfolder/inputfilename_output.csv 

## Authors

- *Shreya Taneja (101132722)* - shreyataneja@cmail.carleton.ca - Carleton University
- *Ankit Kumar Vig (101120055)* - ankitvig@cmail.carleton.ca - Carleton University
