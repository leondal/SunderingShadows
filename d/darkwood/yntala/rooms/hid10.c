//hid10
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"east":INRMS+"hid9",
"south":INRMS+"hid11"
]));
}