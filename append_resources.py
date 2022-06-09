import struct
import os

# SYNC3
# sync3_binary_location = './sync3/Release/'
# sync3_binary_path = sync3_binary_location + 'sync3.bin'
# sync3_start_address = 131072
# sync3_bin_size = os.path.getsize(sync3_binary_path)
# sync3_pad_size = sync3_start_address - sync3_bin_size
# pad_array = []
# for i in range(0, sync3_pad_size):
#     pad_array.append(0)
# packer = struct.Struct('<%dB' % sync3_pad_size)
# pad_bin = packer.pack(*pad_array)
# with open(sync3_binary_path, 'rb') as firmware:
#     firmware_data = firmware.read()
# with open(sync3_binary_location + 'sync3scales.bin', 'rb') as firmware:
#     resource_data = firmware.read()
# with open(sync3_binary_location + 'sync3_padded.bin', 'wb') as padded_firmware:
#     padded_firmware.truncate()
#     padded_firmware.write(firmware_data + pad_bin + resource_data)
# print(os.path.getsize(sync3_binary_location + 'sync3_padded.bin'))

modules = {}
modules['gateseq'] = {}
modules['gateseq']['slug'] = 'gateseq'
modules['gateseq']['start'] = 131072

module = modules['gateseq']

# GATESEQ
binary_location = 'build/' + module['slug'] + '/'
binary_path = binary_location + module['slug'] +'.bin'
start_address = module['start']
bin_size = os.path.getsize(binary_path)
pad_size = start_address - bin_size
print(pad_size)
pad_array = []
for i in range(0, pad_size):
    pad_array.append(0)
packer = struct.Struct('<%dB' % pad_size)
pad_bin = packer.pack(*pad_array)
with open(binary_path, 'rb') as firmware:
    firmware_data = firmware.read()
with open('resources/original.' + module['slug'], 'rb') as firmware:
    resource_data = firmware.read()
with open(binary_location + 'padded.bin', 'wb') as padded_firmware:
    padded_firmware.truncate()
    padded_firmware.write(firmware_data + pad_bin + resource_data)
os.replace(binary_location + 'padded.bin', binary_path) 
print(os.path.getsize(binary_path))

