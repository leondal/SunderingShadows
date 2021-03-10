//fpath3
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"north":INRMS+"fpath2",
"southeast":INRMS+"fpath4",
"northwest":INRMS+"fpath59",
"west":INRMS+"fpath58",
"east":INRMS+"bce2",
]));

}