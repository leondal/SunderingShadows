//cr1
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"cr8",
"northwest":INRMS+"cr2",
"out":INRMS+"path6"
]));
}