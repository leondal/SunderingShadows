//fpath58
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"south":INRMS+"fpath57",
"north":INRMS+"fpath59",
"east":INRMS+"fpath3",
"northeast":INRMS+"fpath2",
]));

}