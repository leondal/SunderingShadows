//cr2
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"cr1",
"north":INRMS+"cr3"
]));
}