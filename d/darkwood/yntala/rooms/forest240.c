//forest240
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest241",
"south":INRMS+"forest239",
"east":INRMS+"forestpath",
]));
}
