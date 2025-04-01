#include "../../include/execute/clear.h"
void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

}