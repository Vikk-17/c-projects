import socket

HOST = "0.0.0.0" # the server's hostname or IP address
PORT = 5035    # The port used by server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b"Hello, world!")
    data = s.recv(1024) 
    print(f"Received {data}")
