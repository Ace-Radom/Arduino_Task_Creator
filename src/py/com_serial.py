# ===============================================
# ===============================================
# *\src\py\com_serial.py
# ===============================================
# ===============================================

# check serial port for Arduino in windows device manager
# using module: serial, pyserial
# command: pip3 install serial
#          pip3 install pyserial

import serial
import serial.tools.list_ports

plist = list( serial.tools.list_ports.comports() )
ports = [p.name for p in plist]

print( ports )