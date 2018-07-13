'''
Simple reading information from the tag and send to Arduino for controlling
'''


from ruuvitag_sensor.ruuvi import RuuviTagSensor
import serial
import struct


tags = {
    'DC:03:56:BE:FE:BE': 'kitchen',
}

timeout_in_sec = 1

ser = serial.Serial('/dev/ttyACM0', 9600)


macs = ['DC:03:56:BE:FE:BE']
# get_data_for_sensors will look data for the duration of timeout_in_sec
timeout_in_sec = 4

datas = RuuviTagSensor.get_data_for_sensors(macs, timeout_in_sec)

ser.write(b'%i'% int(datas[macs[0]]['temperature']))
ser.write(b'%i'% int(datas[macs[0]]['humidity']))

# Dictionary will have lates data for each sensor
print(int(datas[macs[0]]['temperature']))
print(int(datas[macs[0]]['humidity']))
   
