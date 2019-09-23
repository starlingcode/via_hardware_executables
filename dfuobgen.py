import sys

target = sys.argv[1]
fwid = sys.argv[2]
version = sys.argv[3]

file = bytes([170, 85, 255, 0, int(fwid), 255 - int(fwid), int(version), 255 - int(version), 255, 0, 255, 0, 255, 0, 255, 0])

with open("build/" + target + "/optionbytes.temp", "wb") as output:
	output.write(file)
