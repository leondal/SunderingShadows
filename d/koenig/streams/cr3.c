//cr3
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"south":INRMS+"cr2",
"north":INRMS+"cr4"
]));
}