//cr4
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"south":INRMS+"cr3",
"west":INRMS+"cr11",
"east":INRMS+"cr5"
]));
}