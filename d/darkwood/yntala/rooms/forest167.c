//forest167
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"south":INRMS+"forest168",
"east":INRMS+"forest166"
]));
}