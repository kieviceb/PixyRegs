#ifndef PixyRegs_h
#define PixyRegs_h

#include <Pixy2.h>  // Incluye la librería Pixy2

class PixyRegs {
   public:
      PixyRegs();                              // Constructor
      void init();                              // Inicializa la Pixy Cam
      bool detectBlock(int &x, int &y, int &signature, String &region);  // Detecta bloques y devuelve la posición, firma y región del primer bloque encontrado

   private:
      Pixy2 pixy;                               // Objeto Pixy2
      String getBlockRegion(int x, int y);     // Determina la región del bloque
};

#endif
