# ESP32 Web Server Development Tips

## Resources for ESP32 Web Development 
[Building an ESP32 Web Server: The Complete Guide for Beginners | Random Nerd Tutorials](https://randomnerdtutorials.com/esp32-web-server-beginners-guide/)
Tutorial for building a basic ESP32 web server and gives example code with explanation. Shows how to get input from webpage and have a hardware output. 
 
[ESP32 Web Server using LittleFS Filesystem | Random Nerd Tutorials](https://randomnerdtutorials.com/esp32-web-server-littlefs/)
Tutorial for using LittleFS to save HTML/CSS to build a web server interface. Includes example code and shows how to link HTML and CSS files to .ino files. 
 
[ESP32 VS Code PlatformIO: Upload Files to LittleFS Filesystem | Random Nerd Tutorials](https://randomnerdtutorials.com/esp32-vs-code-platformio-littlefs/)
Tutorial on how to use the ESP32 LittleFS filesystem in VS Code with the PlatformIO IDE extension. 
 
[ESP32 LittleFS Tutorial: File Storage, Read/Write & Web Server with Arduino IDE](https://www.sunfounder.com/blogs/news/esp32-littlefs-tutorial-file-storage-read-write-web-server-with-arduino-ide?srsltid=AYCX9vK2LbkLpkK1ZWRkeaHvsuKjvVzuStqw1qiqPCh4F5_P0fU3DPNK)
Another ESP32 and LittleFS tutorial and good for learning how to connect HTML and CSS files and what functions you will need. 
 
[DIYables ESP32 Web Server Json Example | ESP32 Tutorial](https://esp32io.com/tutorials/diyables-esp32-web-server-json-example)
Resource for how to use Json and how to make a JavaScript function for the frontend to have updating values. 
 
[ESP32 WebServer.h Example — Arduino Web Server in 30 Lines](https://blog.hirnschall.net/esp32-webserver/)
Good resources for handler functions to help build the ESP32 web server. 
 
[HTML DOM Element innerHTML Property](https://www.w3schools.com/jsref/prop_html_innerhtml.asp)
JavaScript code syntax that lets you get or set the HTML content inside an element.
 
[Learn Changing the Contents of HTML Elements | DOM and HTML Manipulation](https://codefinity.com/courses/v2/b9808bef-5849-468d-b10d-532a2e0a015f/2a6c55b7-8d6e-434b-9304-1705c697dbc5/2828a78c-de46-4659-938b-4798b7c5e2ed) 
Code examples on how to change the contents of HTML elements. 
 
[JavaScript · Bootstrap](https://getbootstrap.com/docs/3.4/javascript/)
JavaScript and HTML use tutorial. 
 
[Window setInterval() Method](https://www.w3schools.com/jsref/met_win_setinterval.asp)
Javascript code syntax that states how often content on a webpage is refreshed. 
 
[15 CSS Card Grid Layouts — Free Live Demos | CodeFronts](https://codefronts.com/layouts/css-card-grid-layout/)
CSS card grid layout visual and code examples. 
 
[Learn CSS Basics by Building a Card Component](https://www.freecodecamp.org/news/learn-css-basics-by-building-a-card-component/) 
Tutorial explaining and giving examples of styling elements for a card on a webpage. 
 
https://developer.mozilla.org/en-US/docs/Web/CSS/How_to/Layout_cookbook/Card
Tutorial on how to make a card in CSS. 
 
[Responsive Web Design Media Queries](https://www.w3schools.com/css/css_rwd_mediaqueries.asp)
How to use media queries to have your webpage to adapt to different screens (laptop, phone, etc). 

## Tips 
- When you upload to the ESP32, open the serial monitor to find the IP Address (something like 192.168.0.105) and you can paste it into a broswer on a laptop, phone etc. The device you are looking to display the webpage must be connected to the same WiFi that the ESP32 is for the webpage to load. 
- When making webpage files: Make a folder that is at the same level as the src folder, .vscode folder, etc. called "data". Within data you can make files such as data.html, data.css, and data.js. 
- To see an updated webpage (if you make any edits in the data folder to HTML, CSS, or JS files) you will have to go under the PlatformIO -> the name of the board you are using (esp32-s3-devkitc-1) -> Platform -> Upload Filesystem Image. To see updated functionaility (if you make edits under the src folder such as .cpp and .h files) you will have to click the arrow button (->) at the bottom of VS Code. 
- To connect your CSS and JS file to your HTML file include this in your HTML code: 
    - Links CSS: <link rel="stylesheet" type="text/css" href="file.css">. file.css is the name of the file. 
    - Links JS: <script src="file.js"></script>. file.js is the name of the file. 
- If you have mutiple classes that will have the same formatting in CSS you can format them like this: 
    .info-card-1, 
    .info-card-2 {
        /* code */
    }
- When you want to connect the variables to the JS file, within the .cpp file you are building and initalizaing the web server you will need a handleData function. In handleData, you will start a Json string to store the values. String values require escaped quotation marks (\") while numeric values do not. If the value is stored as an enum, create a helper function such as enumToString() to convert it into a readable string before adding it to the JSON. For C++ std::string values, use .c_str() when appending them to an Arduino String. Remember that every JSON field except the last must end with a comma, otherwise dashboard.js will fail to parse the data. For example: <br>
    String json = "{"; <br>
    json += "\"value1\":\""; <br>
    json += enumToString(value1cpp).c_str(); <br>
    json += "\","; <br>
    json += "\"value2\":\""; <br>
    json += value2cpp.c_str(); <br>
    json += "\","; <br>
    json += "\"value3ID\":"; <br>
    json += String(value3cpp); <br>
    json += ","; <br>
    json += "}"; <br>
In the example, value1, value2, and value3 are  and the value1cpp, value2cpp, and value3cpp are the variable names. Together they will display value1: 123 when you go to http://esp32-id/data (not a link) in your browser. 

- Using div in HTML is a very good way to group elements together to make them easier to style in CSS
- If you want a certain feature to show up on a laptop vs phone display you can give each variation a class in the HTML file and in the CSS file, in the medie query use display: none; for the laptop feature and display: inline; for the phone feature
- In JavaScript, an async function can use await and automatically returns a promise, while a normal function executes immediately and returns the value directly.
