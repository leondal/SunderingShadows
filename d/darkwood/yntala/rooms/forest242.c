//forest242
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest241",
"south":INRMS+"forest243"
]));
}