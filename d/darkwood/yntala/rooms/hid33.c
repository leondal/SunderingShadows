//hid33
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"west":INRMS+"hid32",
"south":INRMS+"hid34",
"northwest":INRMS+"hid36",
]));
}