//forest241
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"forest240",
"west":INRMS+"forest242"
]));
}

