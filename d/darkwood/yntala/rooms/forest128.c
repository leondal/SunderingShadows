//forest128
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest127",
"south":INRMS+"forest149",
"east":INRMS+"forest129"
]));
}