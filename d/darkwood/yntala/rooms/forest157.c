//forest157
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest158",
"east":INRMS+"forest156"
]));
}