//forest253
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest252",
"west":INRMS+"river3"
]));
}