//forest166
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest167",
"east":INRMS+"forest165"
]));
}