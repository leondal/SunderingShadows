//forest131
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"1forest1.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest130",
"northwest":INRMS+"forest132",
"southwest":INRMS+"forest140"
]));
}