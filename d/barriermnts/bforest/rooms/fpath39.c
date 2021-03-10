//fpath39
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"fpath38",
"west":INRMS+"fpath40",
]));
}