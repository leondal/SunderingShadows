//dcave2
#include <std.h>;
#include "../bpeak.h"
inherit IHRMS+"dcave.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"dcave1",
"west":INRMS+"dcave3"
]));
}