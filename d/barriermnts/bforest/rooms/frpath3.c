//frpath3
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fredge.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"frpath2",
"south":INRMS+"frpath4",
"northwest":INRMS+"fpath60"
]));
}