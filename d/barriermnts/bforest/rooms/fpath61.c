//fpath61
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"east":INRMS+"fpath60",
"north":INRMS+"fpath62",
]));
}