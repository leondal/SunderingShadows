//hid14
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid13",
"east":INRMS+"hid15",
]));
}