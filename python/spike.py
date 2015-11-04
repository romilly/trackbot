import serial

# serial version - designed to work with websocketd

def send():
      with serial.Serial('/dev/ttyACM0', 9600) as ser:
        while(True):
            c = raw_input(':')
            if c.startswith('q'):
                break
            ser.write(c)

if __name__ == '__main__':
    send()
