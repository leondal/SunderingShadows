//forest158
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest168",
"south":INRMS+"forest159",
"east":INRMS+"forest157"
]));
}