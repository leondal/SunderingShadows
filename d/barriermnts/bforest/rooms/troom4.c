//troom4
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"treeroom2.c";

void create(){
::create();
set_exits(([
"down":INRMS+"fpath1",
"north":INRMS+"troom2",
"northwest":INRMS+"troom3",
"west":INRMS+"troom5",
]));
}