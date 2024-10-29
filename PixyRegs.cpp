#include "PixyRegs.h"

PixyRegs::PixyRegs() {
    // Constructor vacío
}

void PixyRegs::init() {
    pixy.init();  // Inicializa la cámara Pixy
}

bool PixyRegs::detectBlock(int &x, int &y, int &signature, String &region) {
    pixy.getBlocks();  // Obtiene los bloques detectados

    if (pixy.numBlocks > 0) { // Si hay al menos un bloque detectado
        x = pixy.blocks[0].m_x;            // Obtiene la coordenada x del primer bloque
        y = pixy.blocks[0].m_y;            // Obtiene la coordenada y del primer bloque
        signature = pixy.blocks[0].m_signature; // Obtiene la firma del primer bloque
        region = getBlockRegion(x, y);     // Obtiene la región del bloque
        return true;                       // Indica que se ha detectado un bloque
    }
    return false;                          // No se ha detectado ningún bloque
}

String PixyRegs::getBlockRegion(int x, int y) {
    // Define las regiones basadas en las coordenadas (puedes ajustar los límites)
    if (x < 106) { // Región izquierda
        if (y < 69) return "Alpha (Izquierda-Superior)";
        else if (y < 138) return "Delta (Izquierda-Inferior)";
        else return "Zeta (Izquierda-Inferior)";
    } else if (x < 212) { // Región centro
        if (y < 69) return "Beta (Centro-Superior)";
        else if (y < 138) return "Epsilon (Centro-Inferior)";
        else return "Theta (Centro-Inferior)";
    } else { // Región derecha
        if (y < 69) return "Gamma (Derecha-Superior)";
        else if (y < 138) return "Gamma (Derecha-Inferior)";
        else return "Iota (Derecha-Inferior)";
    }
}
