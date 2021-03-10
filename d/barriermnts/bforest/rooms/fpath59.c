//fpath59
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"south":INRMS+"fpath58",
"east":INRMS+"fpath2",
"southeast":INRMS+"fpath3",
]));

}