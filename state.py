from ruuvitag_sensor.ruuvitag import RuuviTag, RuuviTagSensor

sensor = RuuviTag('DC:03:56:BE:FE:BE')

# update state from the device
state = sensor.update()

# get latest state (does not get it from the device)
state = sensor.state

print(state)
# List of macs of sensors which data will be collected
# If list is empty, data will be collected for all found sensors
macs = ['DC:03:56:BE:FE:BE']
# get_data_for_sensors will look data for the duration of timeout_in_sec
timeout_in_sec = 4

datas = RuuviTagSensor.get_data_for_sensors(macs, timeout_in_sec)

# Dictionary will have lates data for each sensor
print(type(datas['DC:03:56:BE:FE:BE']['humidity']))
