#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "vjit attendance";
const char* password = "vjit@123";

ESP8266WebServer server(80);

const char* htmlContent = R"(
<!DOCTYPE html>
<html>
<head>
  <title>VJIT Attendance</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
    }
    h2 {
      margin-bottom: 20px;
    }
  </style>
  <script>
    setTimeout(function() {
      window.location.href = "/attendance";
    }, 5000); // Redirect after 5 seconds (adjust the time as needed).
  </script>
</head>
<body>
  <h2>Student Attendance</h2>
  <p>Redirecting to attendance page...</p>
</body>
</html>
)";

const char* attendancePage = R"(
<!DOCTYPE html>
<html>
<head>
  <title>VJIT Attendance</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
    }
    h2 {
      margin-bottom: 20px;
    }
  </style>
</head>
<body>
  <h2>Student Attendance</h2>
  <form action="/submit" method="post">
    <label for="name">Name:</label>
    <input type="text" id="name" name="name" required><br><br>
    <label for="roll">Roll Number:</label>
    <input type="text" id="roll" name="roll" required><br><br>
    <input type="submit" value="Mark Attendance">
  </form>
</body>
</html>
)";

String attendanceData; // Variable to store the attendance data.

void handleRoot() {
  server.send(200, "text/html", htmlContent);
}

void handleAttendance() {
  server.send(200, "text/html", attendancePage);
}

void handleFormSubmit() {
  if (server.method() == HTTP_POST) {
    String name = server.arg("name");
    String roll = server.arg("roll");
    // Store the attendance data in a data structure (e.g., an array or list).
    // Here, you can add the attendance data to the attendanceData string for later processing.
    attendanceData += name + "," + roll + "\n"; // Append the data with a newline.
    server.send(200, "text/html", "<h2>Attendance Marked</h2>");
  }
}

void handleDownload() {
  String filename = "attendance.txt";
  server.sendHeader("Content-Disposition", "attachment; filename=" + filename);
  server.send(200, "text/plain", attendanceData);
}

void setup() {
  WiFi.softAP(ssid, password);
  IPAddress ipAddress = WiFi.softAPIP();

  server.on("/", handleRoot);
  server.on("/attendance", handleAttendance);
  server.on("/submit", handleFormSubmit);
  server.on("/download", handleDownload); // New endpoint for data download.

  server.begin();
  Serial.begin(115200);
  Serial.print("Access Point IP Address: ");
  Serial.println(ipAddress);
}

void loop() {
  server.handleClient();
}
