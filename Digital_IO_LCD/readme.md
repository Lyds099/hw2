1.how to setup and run your program  
&emsp;&emsp;(1)Clone the repo: $ git clone https://github.com/Lyds099/hw2.git  
&emsp;&emsp;(2) $ cd Digital_IO_LCD  
&emsp;&emsp;(3)Compile the program: $ sudo mbed compile --source . --source ~/ee2405/mbed-os-build/ -m B_L4S5I_IOT01A -t GCC_ARM -f  
&emsp;&emsp;(4)Choose the frequency in the menu: After you pressed the Up or Down button, the frequency that you selected will be displayed on the LCD with green background color. After you pressed the Confirm button, the frequency that you selected will be displayed on the LCD with blue background color.  
&emsp;&emsp;(5)Start the picoscope: Select "input range A" as +-5 and collection time as 100 ms/div.  
&emsp;&emsp;(6)Execute the Python script: $ sudo python3 FFT.py and press the user button.

2.what are the results 
&emsp;&emsp;Picoscope before RC 20hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%20before%20RC%2020hz.png?raw=true  
&emsp;&emsp;Picoscope before RC 40hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%20before%20RC%2040hz.png?raw=true  
&emsp;&emsp;Picoscope before RC 100hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%20before%20RC%20100hz.png?raw=true  
&emsp;&emsp;Picoscope after RC 20hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%2020.png?raw=true  
&emsp;&emsp;Picoscope after RC 40hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%2040.png?raw=true  
&emsp;&emsp;Picoscope after RC 100hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%20100.png?raw=true  
&emsp;&emsp;waveform 20hz: https://github.com/Lyds099/hw2/blob/master/Waveform%2020.png?raw=true  
&emsp;&emsp;waveform 40hz: https://github.com/Lyds099/hw2/blob/master/Waveform%2040.png?raw=true  
&emsp;&emsp;waveform 100hz: https://github.com/Lyds099/hw2/blob/master/Waveform%20100.png?raw=true  