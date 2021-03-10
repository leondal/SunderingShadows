//fpath43
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"north":INRMS+"fpath42",
"east":INRMS+"fpath46",
"south":INRMS+"fpath44",
]));
}