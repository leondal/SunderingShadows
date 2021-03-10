//uw18
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"east":INRMS+"uw19",
"up":INRMS+"uw17"
]));
}