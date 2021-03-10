//fpath49
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"fpath48",
"north":INRMS+"fpath50",
]));
}