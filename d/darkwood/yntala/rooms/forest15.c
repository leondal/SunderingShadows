//forest15
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"south":INRMS+"forest16",
"west":INRMS+"forest120",
"north":INRMS+"forest14"
]));
}