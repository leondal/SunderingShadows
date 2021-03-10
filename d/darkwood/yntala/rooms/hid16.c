//hid16
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid12",
"west":INRMS+"hid25",
]));
}