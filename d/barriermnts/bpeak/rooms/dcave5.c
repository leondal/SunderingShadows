//dcave5
#include <std.h>;
#include "../bpeak.h"
inherit IHRMS+"dcave.c";

void create(){
::create();
set_exits(([
"north":INRMS+"dcave4",
"south":INRMS+"dcave6"
]));
}