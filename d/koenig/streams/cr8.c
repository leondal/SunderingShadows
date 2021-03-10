//cr8
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"north":INRMS+"cr7",
"southwest":INRMS+"cr1"
]));
}