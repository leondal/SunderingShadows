//dcave6
#include <std.h>;
#include "../bpeak.h"
inherit IHRMS+"dcave.c";

void create(){
::create();
set_exits(([
"north":INRMS+"dcave5",
"southeast":INRMS+"dcave7"
]));
}