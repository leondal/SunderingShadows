//fpath57
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"south":INRMS+"fpath56",
"north":INRMS+"fpath58",
]));
}