//dcave7
#include <std.h>;
#include "../bpeak.h"
inherit IHRMS+"dcave.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"dcave6",
"southwest":INRMS+"dcave8"
]));
}