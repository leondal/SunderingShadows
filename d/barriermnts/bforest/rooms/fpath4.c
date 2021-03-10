//fpath4
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"fpath3",
"southeast":INRMS+"fpath5",
]));
}