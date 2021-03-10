//forest23
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest22",
"north":INRMS+"forest236",
"west":INRMS+"forest249",
"south":INRMS+"forest24"
]));
}