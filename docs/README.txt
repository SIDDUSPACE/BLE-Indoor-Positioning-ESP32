SUPPLEMENTARY MATERIAL
======================

Paper Title:
Design and Implementation of a Zone-Based BLE Indoor Localization System Using ESP32

Authors:
Siddarth.S , Akash.M

------------------------------------------------------------

1. OVERVIEW
-----------
This supplementary package provides implementation-level evidence 
supporting the proposed zone-based BLE indoor localization system.

The system performs RSSI-based proximity classification into three 
predefined zones using an ESP32-S3 platform without external servers 
or cloud computation.

------------------------------------------------------------

2. FOLDER CONTENTS
------------------

ESP32_Source_Code/
    - Zone_BLE_Localization.ino
      Complete firmware implementing BLE scanning, RSSI filtering,
      and zone classification.

    - CODE_INFO.txt
      Detailed system configuration and parameter documentation.

Sample_RSSI_Log.csv
    - 90 experimental RSSI samples
    - 30 samples collected per zone
    - Includes timestamp, RSSI, predicted zone, and ground truth distance

BLE_Zone_Localization_Demo.mp4
    - Real-time demonstration of zone transitions
    - Shows RSSI variation and dynamic zone switching

------------------------------------------------------------

3. EXPERIMENTAL CONFIGURATION
-----------------------------

Indoor Test Area:
    100 sq.ft (≈9.29 m²)

Maximum Tested Distance:
    3.25 meters

Zone Definitions:
    Zone A (Near):  < 0.5 m
    Zone B (Mid):   0.5 – 1.5 m
    Zone C (Far):   1.5 – 3.25 m

System Parameters:
    RSSI averaging window size: 8 samples
    BLE scan duration: 2 seconds per cycle
    Total samples collected: 90

Overall Filtered Zone Classification Accuracy:
    91%

------------------------------------------------------------

4. SYSTEM DESCRIPTION
---------------------

- BLE beacon has an advertising mode.
- The receiver ESP32 keeps on scanning  the BLE advertisements.
- The sliding window moving average is used to filter RSSI values.
- The values of filtered RSSI are mapped on predetermined proximity zones.
- To minimize the oscillation of boundaries, zone locking logic is used.
- All the calculations are made on the ESP32.

------------------------------------------------------------

5. PURPOSE OF SUBMISSION
------------------------

This additional resource proves that the suggested BLE implementation and evaluation of zone based localization system was done during an actual indoor setting with controlled experimental conditions.

------------------------------------------------------------
