//hid13
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"south":INRMS+"hid14",
"east":INRMS+"hid6",
]));
}