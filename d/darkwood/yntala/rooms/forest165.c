//forest165
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest166",
"east":INRMS+"forest164"
]));
}