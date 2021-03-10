//uw19
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";

void create(){
::create();
set_exits(([
"east":INRMS+"uw20",
"west":INRMS+"uw18"
]));
}