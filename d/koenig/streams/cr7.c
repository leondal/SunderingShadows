//cr7
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"north":INRMS+"cr6",
"south":INRMS+"cr8"
]));
}