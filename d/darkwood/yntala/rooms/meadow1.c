//meadow1
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"meadow.c";
void create(){
::create();



set_exits(([
"north":INRMS+"meadowedge7",
"south":INRMS+"centermed",
"east":INRMS+"meadowedge6",
"west":INRMS+"meadowedge8",
"southeast":INRMS+"meadow2",
"southwest":INRMS+"meadow4"
]));
}
                        
