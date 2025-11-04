#include "MemInspector.h"

extern int __heap_start, *__brkval;

int MemInspector::freeMemory() {
  int v;
  return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

void MemInspector::printReport(Stream &out) {
  out.println(F("===== Memory Report ====="));
  out.print(F("Free SRAM: "));
  out.print(freeMemory());
  out.println(F(" bytes"));
  out.println(F("========================="));
}
