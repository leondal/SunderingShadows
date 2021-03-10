//forest170
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest171",
"southwest":INRMS+"forest169",
"southeast":INRMS+"forest177"
]));
}