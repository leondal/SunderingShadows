//forest25
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest24",
"south":INRMS+"forest26",
"east":INRMS+"forest231"
]));
}