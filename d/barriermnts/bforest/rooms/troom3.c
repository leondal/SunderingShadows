//troom3
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"treeroom2.c";

void create(){
::create();
set_exits(([
"down":INRMS+"fpath1",
"north":INRMS+"troom1",
"east":INRMS+"troom2",
"south":INRMS+"troom5",
"southeast":INRMS+"troom4",
]));
}