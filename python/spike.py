from quick2wire.i2c import I2CMaster, writing_bytes
address = 0x04



def send_i2c():
    with I2CMaster() as master:    
        while(True):
            c = input(':')
            if c.startswith('q'):
                break
            master.transaction(
                writing_bytes(address, ord(c[0])))

send_i2c()
