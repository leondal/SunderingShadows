//dcave8
#include <std.h>;
#include "../bpeak.h"
inherit IHRMS+"dcave.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"dcave7",
"out":"/d/barriermnts/bforest/rooms/fpath1"
]));
}