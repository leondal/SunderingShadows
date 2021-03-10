//cr6
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"west":INRMS+"cr5",
"south":INRMS+"cr7"
]));
}