//troom1
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"troom.c";

void create(){
::create();
set_exits(([
"down":INRMS+"fpath1",
"east":INRMS+"troom2",
"south":INRMS+"troom3",
]));
}