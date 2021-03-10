//cr5
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"north":INRMS+"tr1",
"west":INRMS+"cr4",
"east":INRMS+"cr6"
]));
}