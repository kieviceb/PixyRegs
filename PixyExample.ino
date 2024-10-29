#include <PixyRegs.h>

PixyRegs pixyCam;

void setup() {
    Serial.begin(9600);
    pixyCam.init();  // Inicializa la Pixy Cam
}

void loop() {
    int x, y, signature;
    String region;

    if (pixyCam.detectBlock(x, y, signature, region)) {
        // Imprime las coordenadas, la firma y la región del bloque detectado
        Serial.print("Bloque detectado - X: ");
        Serial.print(x);
        Serial.print(" Y: ");
        Serial.print(y);
        Serial.print(" Firma: ");
        Serial.print(signature);
        Serial.print(" Región: ");
        Serial.println(region);
    } else {
        Serial.println("No se detectaron bloques.");
    }

    delay(500);  // Espera 500 ms antes de la próxima detección
}
