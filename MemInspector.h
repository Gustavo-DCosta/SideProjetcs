#ifndef MEMINSPECTOR_H
#define MEMINSPECTOR_H

#include <Arduino.h>

class MemInspector {
  public:
    static int freeMemory();
    static void printReport(Stream &out = Serial);
};

#endif
