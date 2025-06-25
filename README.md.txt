# Seguidor Solar con ESP32-S3

Proyecto de seguimiento solar basado en un **Goouuu ESP32‑S3 N16R8**, con **OLED 0.96" I2C**, **DHT11**, **LED WS2812**, **4 LDRs** y **2 servomotores**.

## Componentes

- ESP32‑S3 N16R8  
- Pantalla OLED SSD1306 0.96" (I2C, dirección 0x3C)  
- Sensor DHT11  
- LED WS2812 (1 LED)  
- 4 × LDR + resistencias 10 kΩ (divisor de voltaje)  
- 2 × servomotores  
- Cables, fuente 3.3 V, protoboard

## Conexiones (ejemplo)

| Sensor / Dispositivo | Esp32‑S3 Pin | Detalles                            |
|----------------------|--------------|-------------------------------------|
| LDR TL, TR, BL, BR   | A0, A1, A2, A3 | Divisor de 10 kΩ a GND             |
| DHT11                | D10          | Con resistencia de pull‑up 4.7 kΩ  |
| OLED SDA / SCL       | D21 / D22    | I2C‑GND + 3.3 V                     |
| Servos X / Y         | D18 / D19    | PWM + alimentación 5 V (o 3.3 V)   |
| WS2812               | D48          | Alimentación 3.3 V + GND            |

## Simulación con TinkerCAD

1. Crea un nuevo circuito en TinkerCAD.
2. Elige un ESP32 genérico, OLED I2C, DHT11, LDRs, servos, LED Neopixel y resistencias.
3. Conéctalos igual que en la tabla.
4. Copia el código `main.ino` dentro y ejecuta la simulación.

Ajusta el umbral de diferencia en LDRs (`>50`) según el comportamiento observado.

## Licencia

MIT License © [Tu Nombre]
