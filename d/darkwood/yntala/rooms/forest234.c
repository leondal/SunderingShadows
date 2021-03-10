//forest234
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"east":INRMS+"forest235",
"west":INRMS+"forest233"
]));
}