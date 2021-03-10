//fpath41
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"fpath40",
"northwest":INRMS+"fpath48",
"south":INRMS+"fpath42",
]));
}