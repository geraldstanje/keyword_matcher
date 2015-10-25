#include "util.h"

bool is_alpha(const char &ch) {
    if (!((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))) {
        return false;
    }
    return true;
}