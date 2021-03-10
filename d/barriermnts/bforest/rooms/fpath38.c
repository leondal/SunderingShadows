//fpath38
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"east":INRMS+"fpath8",
"northwest":INRMS+"fpath39",
]));
}