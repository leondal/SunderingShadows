//dcave3
#include <std.h>;
#include "../bpeak.h"
inherit IHRMS+"dcave.c";

void create(){
::create();
set_exits(([
"east":INRMS+"dcave2",
"west":INRMS+"dcave4"
]));
}