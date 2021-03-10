//b1.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"b.c";
int searched;

void create(){
::create();
set_exits(([
"south":INRMS+"b2","northeast":"/d/dagger/Torm/road/path30"
]));
}