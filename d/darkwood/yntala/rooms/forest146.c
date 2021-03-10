//forest146
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest147",
"west":INRMS+"forest145"
]));
}