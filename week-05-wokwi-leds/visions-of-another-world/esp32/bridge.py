import asyncio
import serial
from websockets.asyncio.server import serve

clients = set()

# Receive browser connections
async def handle_client(websocket):
    clients.add(websocket)
    print("p5.js connected")

    try:
        await websocket.wait_closed()
    finally:
        clients.discard(websocket)

# Read ESP32 serial messages and forward them
async def read_serial(esp32):
    while True:
        data = await asyncio.to_thread(esp32.readline)

        if data:
            value = data.decode("utf-8", errors="replace").strip()

            # Forward only valid numerical readings
            try:
                number = int(value)
            except ValueError:
                continue

            if 0 <= number <= 65535:
                print("Sensor:", number)

                for client in tuple(clients):
                    try:
                        await client.send(str(number))
                    except Exception:
                        clients.discard(client)

# Run bridge
async def main():
    esp32 = serial.serial_for_url(
        "rfc2217://localhost:4000",
        baudrate=115200,
        timeout=0.1
    )

    try:
        async with serve(handle_client, "localhost", 8765):
            print("Bridge running on ws://localhost:8765")
            await read_serial(esp32)
    finally:
        esp32.close()

asyncio.run(main())
