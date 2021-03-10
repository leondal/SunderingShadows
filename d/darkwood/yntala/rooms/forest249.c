//forest249
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest250",
"east":INRMS+"forest23"
]));
}