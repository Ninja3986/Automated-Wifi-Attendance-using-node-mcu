# Automated-Wifi-Attendance-using-node-mcu



1. Make sure your NodeMCU is connected to your computer via the USB cable.

2. Select the correct board and port in the Arduino IDE under the `Tools` menu. Choose the appropriate NodeMCU board (e.g., "NodeMCU 1.0 (ESP-12E Module)" or "NodeMCU 0.9 (ESP-12 Module)").

3. Once the correct board and port are selected, click the "Upload" (arrow) button in the Arduino IDE to upload the code to your NodeMCU.

4. The IDE will compile the code again and then start uploading it to your NodeMCU. You should see some messages in the bottom console showing the progress.

5. Once the upload process is complete, the code will start running on your NodeMCU, and it will create the Wi-Fi hotspot with the specified SSID ("vjit attendance") and password ("vjit@123").

6. When you connect to the Wi-Fi hotspot with your mobile phone or any device, it should automatically redirect you to the attendance page after 5 seconds (as per the current code). On the attendance page, you can fill in your name and roll number to mark your attendance.

7. When you submit your attendance, it will be stored in the `attendanceData` variable, and you'll see the "Attendance Marked" message.

8. To download the attendance data, open a browser on your mobile phone and navigate to the URL "http://192.168.4.1/download" (replace "192.168.4.1" with the IP address of your NodeMCU's Wi-Fi hotspot). The browser should prompt you to download the "attendance.txt" file containing the attendance data.

If you encounter any issues during the upload or testing process, double-check your connections, board settings, and Wi-Fi hotspot settings. Feel free to ask for further assistance if needed.

 I hope everything goes smoothly! Happy coding!
