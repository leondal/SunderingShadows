//forest250
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"west":INRMS+"river2",
"east":INRMS+"forest249",
"south":INRMS+"forest251"
]));
}