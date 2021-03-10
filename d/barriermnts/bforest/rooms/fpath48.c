//fpath48
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"fpath41",
"northwest":INRMS+"fpath49",
]));
}