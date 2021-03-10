//fpath60
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"frpath3",
"west":INRMS+"fpath61",
"northeast":INRMS+"fpath55",
]));
}