// HTML code for the control buttons page
String htmlPage = R"html(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Remote Control</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no, maximum-scale=1.0, minimum-scale=1.0">
    <style>
        body { 
            font-family: Arial, sans-serif; 
            display: flex; 
            align-items: center; 
            justify-content: center; 
            height: 100vh; 
            margin: 0; 
            background-color: #f2f2f2;
        }
        .container {
            display: grid;
            grid-template-rows: 1fr 1fr 1fr;
            grid-template-columns: 1fr 1fr 1fr;
            gap: 10px;
            width: 80vw;
            max-width: 300px;
            height: 80vw;
            max-height: 300px;
        }
        .button {
            padding: 20px; 
            font-size: 4vw;
            color: white; 
            background-color: #4CAF50; 
            border: none; 
            border-radius: 10px;
            cursor: pointer;
            -webkit-user-select: none; /* Disable text selection on Safari */
            -moz-user-select: none; /* Disable text selection on Firefox */
            -ms-user-select: none; /* Disable text selection on IE/Edge */
            user-select: none; /* Standard CSS */
        }
        .button:hover { background-color: #45a049; }
        .button:active { background-color: #3e8e41; }
        #forward { grid-column: 2 / 3; grid-row: 1 / 2; }
        #left { grid-column: 1 / 2; grid-row: 2 / 3; }
        #right { grid-column: 3 / 4; grid-row: 2 / 3; }
        #backward { grid-column: 2 / 3; grid-row: 3 / 4; }
    </style>
</head>
<body>
    <div class="container">
        <button id="forward" class="button" onmousedown="sendRequest('/F')" onmouseup="sendRequest('/S')" ontouchstart="sendRequest('/F')" ontouchend="sendRequest('/S')">Forward</button>
        <button id="left" class="button" onmousedown="sendRequest('/L')" onmouseup="sendRequest('/S')" ontouchstart="sendRequest('/L')" ontouchend="sendRequest('/S')">Left</button>
        <button id="right" class="button" onmousedown="sendRequest('/R')" onmouseup="sendRequest('/S')" ontouchstart="sendRequest('/R')" ontouchend="sendRequest('/S')">Right</button>
        <button id="backward" class="button" onmousedown="sendRequest('/B')" onmouseup="sendRequest('/S')" ontouchstart="sendRequest('/B')" ontouchend="sendRequest('/S')">Backward</button>
    </div>

    <script>
        function sendRequest(path) {
            fetch(path).then(response => {
                console.log("Request sent to " + path);
            }).catch(error => {
                console.error("Error sending request: ", error);
            });
        }
    </script>
</body>
</html>
)html";
