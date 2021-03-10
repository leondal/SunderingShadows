//hid12
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid15",
"west":INRMS+"hid24",
"east":INRMS+"hid11",
"south":INRMS+"hid16",
]));
}