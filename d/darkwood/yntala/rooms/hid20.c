//hid20
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"southwest":INRMS+"hid19",
"north":INRMS+"hid22",
"south":INRMS+"hid21",
]));
}