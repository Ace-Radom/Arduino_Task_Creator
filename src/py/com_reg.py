# ===============================================
# ===============================================
# *\src\py\com_reg.py
# ===============================================
# ===============================================
#
# start time: 2022.10.20
# 2022.10.20 finish temp file writing part and Registry read part, end of this program (if don't have any further requests)

# check serial port for Arduino in Registry, returning serial port, port name and serial type
# using module: win32api, win32con, time
# ~ pip3 install pywin32

import win32api
import win32con

import time

temp_file_name = 'com_reg.atctemp'
# temp file in .\bin

class com_data: # struct to save com datas get from Registry
    def __init__(self):
        self.name = ''
        self.port = ''
        self.type = 0

# in Registry cannot read serial device name from "HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP\SERIALCOMM"
# therefore this program should not be the first choice for getting serial port for Arduino
# it should be only triggered when no serial port is got by com_serial.py

def get_com_reg():
    ports = []
    reg_key = win32api.RegOpenKey( win32con.HKEY_LOCAL_MACHINE , "HARDWARE\DEVICEMAP\SERIALCOMM" , 0 , win32con.KEY_READ )
    # create Registry key

    try:
        _temp = 0
        while True:
            _name , _port , _type = win32api.RegEnumValue( reg_key , _temp )
            # get data from Registry
#           print( "name:{} port:{} type:{}".format( _name , _port , _type ) )

            ports.append( com_data() ) # link one com_data()
            ports[_temp].name  = _name
            ports[_temp].port = _port
            ports[_temp].type  = _type

            _temp += 1
    except:
        pass

    win32api.RegCloseKey( reg_key )
    # close Registry key
    return ports

com_reg_list = get_com_reg() # save com datas to com_reg_list

with open( temp_file_name , 'w' ) as rFile: # create temp file
    rFile.write( time.strftime( '%Y-%m-%d %H:%M:%S' , time.localtime() ) ) # write create time to temp file (in format "Y-M-D H:M:S")
    rFile.write( "\n" )
    rFile.write( "~~ Begin serial device part ~~\n" ) # add begin signal (begin to write serial device) in temp file

    for i in range( 0 , len( com_reg_list ) ):
#       print( com_reg_list[i] )

        rFile.write( com_reg_list[i].name )
        rFile.write( " " )
        rFile.write( com_reg_list[i].port )
        rFile.write( " " )
        rFile.write( str( com_reg_list[i].type ) ) 
        # com_data.type is an int var, therefore needs to be changed into str
        rFile.write( "\n" )

        # between name, port and type is divided by space
        # there should be no space in these three value under win32, that's why div-sign like '~' hasn't been used

    rFile.write( "~~ End serial device part ~~" ) # add end signal (end of writing serial device) in temp file

# Begin and End signal is only for making it easier for Arduino_Task.exe to point out which part is serial device only