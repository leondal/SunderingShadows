//hid15
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"south":INRMS+"hid12",
"west":INRMS+"hid14",
]));
}