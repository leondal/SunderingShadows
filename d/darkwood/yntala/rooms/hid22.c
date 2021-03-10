//hid22
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"west":INRMS+"hid23",
"south":INRMS+"hid20"
]));
}