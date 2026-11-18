# Software Set Up 
In order to upload code to the Arduino, you will need a IDE (Integrated Development Environment) where you can write and upload your code. You can use Arduino IDE or 
Visual Studio Code with the PlatformIO extension. The Ardunio IDE is ideal for prototyping and for basic, quick uploads and programs. While VS Code and PlatformIO is more 
powerful and complex and includes more features such as a Git/GitHub connection useful for making projects. You are free to install and use either IDE 

## How to setup Arduino IDE
You can download the Arduino IDE from the [official Arduino website](https://www.arduino.cc/en/software/). 
Once you have finished clicking through the set up, start the application and do the following: 
1. Select **Tools** > **Boards** > **Boards Manager**
2. Search for "arduino uno r4"
3. Select **Install** and accept all prompts for installation
4. Once the installation is complete, please confirm you see the following "Tools > Boards > Arduino UNO R4 Boards > Arduino UNO R4 Minima"
5. You can start typing and programming in the file opened up. To create a new sketch (new project) go to **File** > **New Sketch**. To create a new file within your project click the drop down arrow to the right of the file tabs in the IDE.
Select 'New Tab' and then name the file.You can add .h, .c and .cpp files just as you would in other C or C++ environments

## How to set up Visual Studio Code and PlatformIO
You will first need to install Visual Studio Code and then the PlatformIO extension. 
You can download VS Code from the [official VS Code website for Windows](https://code.visualstudio.com/docs/setup/windows) 
or from the [official VS Code website for MacOS](https://code.visualstudio.com/docs/setup/mac). 
Once you have finished through the set up, start the application and do the following: 
1. On the left panel, click on the **Extensions** button.
2. Search "PlatformIO" and click **Install** PlatformIO IDE (published by PlatformIO).
3. Once it has finished installing, restart VS Code.
4. To create a new project, PIO Home should open automatically (to access it generally, click on the PlatformIO icon on the left panel and go **Quick Access** > **Open**)
then click **New Project**, title your project, in board type "Arduino Uno R4 Minima" and make sure the framework is Arduino. You can also have your project sit anywhere on your laptop by unchecking "Use default location".
Then click **Finish**. The time for the project to initialize may take up to 10-20 minutes so be sure to have this done before attending the workshop. 
