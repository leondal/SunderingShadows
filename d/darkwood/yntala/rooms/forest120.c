//forest120
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest121",
"east":INRMS+"forest15"
]));
}