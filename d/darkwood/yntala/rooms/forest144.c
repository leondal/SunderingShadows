//forest144
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"forest145",
"northwest":INRMS+"forest143"
]));
}