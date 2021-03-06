
# DHT22_COM

Arduino firmware and Python script for reading data of the temperature-humidity sensor [DHT-22](https://www.waveshare.com/DHT22-Temperature-Humidity-Sensor.htm) from Arduino.

Arduino connection (the signal line is connected to aт arbitrary pin, it can be changed in the firmware code):

 - Arduino Uno
 
![Arduino Uno connection scheme](https://nerdytechy.com/wp-content/uploads/2021/01/dht22-arduino-1024x650.jpg)

 - Arduino Nano

 ![Arduino Nano connection scheme](https://external-content.duckduckgo.com/iu/?u=https://hacksterio.s3.amazonaws.com/uploads/attachments/399838/dht22_PXIGopsnPc.jpg&f=1&nofb=1)
 
 *Note: the sensor can be powered either with 5 or 3.3 V*

## Requirements

In order to program the Arduino board, the Arduino IDE should be installed. Then the DHT22 library should be installed inside the IDE. For this:

 1. Click Sketch -> Include library -> Manage libraries
 2. Type "DHT22" in the Filter your search field and click the Install button (last version):
 
 ![Aruino library manager](https://www.makerguides.com/wp-content/uploads/2019/02/Installing-an-Arduino-library-step-2-DHT-Adafruit.png)
 
 In order to run Python script, the latest version on Python and Anaconda/Miniconda should be installed as well. Miniconda is preferable, since the smaller size.
 For this just download Miniconda from the official website [here](https://docs.conda.io/en/latest/miniconda.html) (also choose the option to install the latest version of Python).
 
 After installation, you'll be able to run Anaconda prompt. I recommend using the Anaconda Powershell Prompt.
 
 In order to exclude some issues with interrupting the script run with the mouse click, find Anaconda Powershell Prompt in the Start menu, click with the right button and choose "Open file location". Then click on the shortcut in the Explorer with the right button and choose "Properties". Then choose the "Option" section and leave only these options (at least uncheck Quick Edit Mode and Insert mode):
 
![Anaconda Powershell Prompt options](images/AnacondaPrompt_Options.png)

 Also, it's useful to change the default path when Anaconda Powershell Prompt is opened. For this just go to the Shortcut section in Properties and change the "Start in" field (by default contains %HOMEPATH%):
 
 ![Anaconda Powershell Prompt Path](images/AnacondaPrompt_Path.png)

Now everything is ready for the Arduino firmware uploading and running the Python script.
 
## Parameters and options

### Arduino
The data signal pin can be chosen here in the Arduino firmware code:
`#define DHTPIN 2     // what digital pin we're connected to`
Arduino is connected to the PC via COM-port with baudrate of 115200 baud.

### Python script
In order to run the Python script, you need to connect Arduino and find the right COM port (in devices manager) and, if needed, change it manually in the DHT22_COM.py in the following code section:

    # Important variables
    comPort = "COM3"
    baudRate = 115200
    samp_per = 60  # in minutes

Also, here you can change the sampling rate/period (sample_per), which is in minutes.

Then you can just type the following command in the Anaconda Powershell Prompt (*it the directory, where the script is located*):
`python DHT22_COM.py`
After that, the script will start running. There is an example of the output in the prompt below:

![Script running](images/ScriptRunning.png)

*NOTE: The first value is Temperature value, the second one is Humidity value.*

*Note: if there are any messages about missing libraries, use a command like this to install needed libraries/packages (but Miniconda should have all needed libraries by default)*
`conda install -c anaconda pyserial time`

Also, the script will save all results in the .csv file with a name `Year-Month-Day_Hour-Minutes-Seconds.csv`. An example of the file content is bellow:

![csv output example](images/CsvOutput.png)

## Important notes

 - In order to stop the Script runnung just press the `ESC` button
 - Also the Script could be interrupted with `Ctrl + C`, but it's for the cases when it's stuck. It's better to use the previous method to be sure that .csv file will be saved properly
