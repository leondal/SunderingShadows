//forest13
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest139",
"east":INRMS+"forest12",
"west":INRMS+"forest14"
]));
}