//fpath5
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"fpath4",
"southeast":"/d/barriermnts/bpeak/rooms/bpath2",
]));
}