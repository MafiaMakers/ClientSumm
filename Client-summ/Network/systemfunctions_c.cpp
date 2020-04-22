#include "include_c.h"
#include "systemfunctions_c.h"
namespace Mafia {
    void zeroMemSys(char* arr, int size) {
        switch (currentOS) {
        case Win:
            ZeroMemory(arr, size);
            break;
        case Mac:
            memset(arr, 0, size);
            break;
        default:
            break;
        }
    }

}
