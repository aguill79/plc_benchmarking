import socket
import struct

ip = "192.168.56.1"
port = 10105

msg = 1

print(str(ip), str(port), str(msg))

msg_to_send = struct.pack("d", msg)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto(msg_to_send, (ip, port))
