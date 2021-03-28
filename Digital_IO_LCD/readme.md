1.how to setup and run your program
&nbsp;&nbsp;(1)Clone the repo: $ git clone https://github.com/Lyds099/hw2.git
&nbsp;&nbsp;(2) $ cd Digital_IO_LCD
&nbsp;&nbsp;(3)Compile the program: $ sudo mbed compile --source . --source ~/ee2405/mbed-os-build/ -m B_L4S5I_IOT01A -t GCC_ARM -f
&nbsp;&nbsp;(4)Choose the frequency in the menu: After you pressed the Up or Down button, the frequency that you selected will be displayed on the LCD with green background color. After you pressed the Confirm button, the frequency that you selected will be displayed on the LCD with blue background color. 
&nbsp;&nbsp;(5)Start the picoscope: Select "input range A" as +-5 and collection time as 100 ms/div.
&nbsp;&nbsp;(6)Execute the Python script: $ sudo python3 FFT.py

2.what are the results
&nbsp;&nbsp;Picoscope 20hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%2020.png?raw=true
&nbsp;&nbsp;Picoscope 40hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%2040.png?raw=true
&nbsp;&nbsp;Picoscope 100hz: https://github.com/Lyds099/hw2/blob/master/Picoscope%20100.png?raw=true
&nbsp;&nbsp;20 hz waveform: https://github.com/Lyds099/hw2/blob/master/waveform%2020.png?raw=true
&nbsp;&nbsp;40 hz waveform: https://github.com/Lyds099/hw2/blob/master/waveform%2040.png?raw=true
&nbsp;&nbsp;100 hz waveform: https://github.com/Lyds099/hw2/blob/master/waveform%20100.png?raw=true