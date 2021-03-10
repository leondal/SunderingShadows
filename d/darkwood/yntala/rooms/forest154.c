//forest154
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest156",
"northeast":INRMS+"forest155",
"southwest":INRMS+"forest153"
]));
}