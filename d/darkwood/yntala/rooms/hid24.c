//hid24
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"east":INRMS+"hid12",
"south":INRMS+"hid25",
]));
}