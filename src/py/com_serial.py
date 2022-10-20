# ===============================================
# ===============================================
# *\src\py\com_serial.py
# ===============================================
# ===============================================
#
# start time: 2022.10.20
# 2022.10.20 finish temp file writing part, end of this program (if don't have any further requests)

# check serial port for Arduino in windows device manager
# using module: serial, pyserial, time
# ~ pip3 install serial
# ~ pip3 install pyserial

import serial
import serial.tools.list_ports

import time

plist = list( serial.tools.list_ports.comports() )
# get serial device

temp_file_name = 'com_serial.atctemp'
# temp file in .\bin

# all datas Arduino_Task.exe needs will be written to one special file-format ".atctemp" (means Arduino_Task_Creator Temp file)
# here datas will be written to com_serial.atctemp

with open( temp_file_name , 'w' ) as rFile: # create temp file
    rFile.write( time.strftime( '%Y-%m-%d %H:%M:%S' , time.localtime() ) ) # write create time to temp file (in format "Y-M-D H:M:S")
    rFile.write( "\n" )
    rFile.write( str( plist ) ) # write plist to temp file
    rFile.write( "\n" )
    rFile.write( "~~ Begin serial device part ~~\n" ) # add begin signal (begin to write serial device) in temp file

    for i in range( 0 , len( plist ) ):
#       print( plist[i] ) # print this serial device
        rFile.write( str( plist[i] ) ) # write this serial device to temp file
        rFile.write( "\n" )

    rFile.write( "~~ End serial device part ~~" ) # add end signal (end of writing serial device) in temp file

# Begin and End signal is only for making it easier for Arduino_Task.exe to point out which part is serial device only