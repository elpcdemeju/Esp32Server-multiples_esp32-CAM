#include "WiFi.h"
#include "ESPAsyncWebServer.h"

// Replace with your network credentials
const char* ssid = "TU WIFI";
const char* password = "TU CONTRASEÑA";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);



const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>El PC de Meju</title>
</head>

<body>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            background-color: rgb(232, 238, 238);
        }

        header {
            width: 100vw;
            height: 60px;
            background-color: blue;
            display: flex;
            justify-content: center;
            align-items: center;
            color: whitesmoke;
        }
        h2{
            margin-top: 30px;
            text-align: center;
        }
        .contCam {
            display: flex;
            flex-direction: column;
            align-items: center;
            margin-top: 50px;
        }
       
        h3 {
            margin-bottom: 10px;
        }

        .video {
            width: 90vw;
        }


        @media (min-width: 600px) {
            .camaras {
                display: flex;
                justify-content: space-around;
                margin-top: 100px;

            }
            h2{
            margin-top: 40px;
            
        }
        .contCam{
            margin-top: 0;
        }
            .video {
                width: 500px;

            }
        }
    </style>
    <header>
        <h1>El PC de Meju</h1>
     
    </header>
    <h2>Servidor ESP32 - Cámaras</h2>
    <div class="camaras">
        
        <div class="contCam">
            <h3>ESP-CAM 1</h3>
            <img src="http://192.168.0.19" alt="" class="video">
        </div>

        <div class="contCam">
            <h3>ESP-CAM 2</h3>
            <img src="http://192.168.0.20" alt="" class="video">
        </div>
    </div>

</body>

</html>)rawliteral";



void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/html", index_html);
  });


  // Start server
  server.begin();
}

void loop() {

}
