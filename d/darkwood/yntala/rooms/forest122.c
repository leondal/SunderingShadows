//forest122
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest121",
"south":INRMS+"forest123"
]));
}