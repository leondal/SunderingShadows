//hid19
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"hid20",
"west":INRMS+"hid18",
]));
}