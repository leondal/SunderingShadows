//dcave4
#include <std.h>;
#include "../bpeak.h"
inherit IHRMS+"dcave.c";

void create(){
::create();
set_exits(([
"east":INRMS+"dcave3",
"south":INRMS+"dcave5"
]));
}