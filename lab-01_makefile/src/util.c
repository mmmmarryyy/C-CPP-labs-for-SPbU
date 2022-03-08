#include "stdio.h"
#include "io.h"

int max(int a, int b) {
  logDebug('m');
  return a < b ? b : a;
}
