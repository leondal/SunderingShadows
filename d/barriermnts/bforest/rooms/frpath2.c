//frpath2
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fredge.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"frpath1",
"southwest":INRMS+"frpath3",
"northwest":INRMS+"fpath55",
]));
}