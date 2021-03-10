//t1.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"transition";
int searched;

void create(){
::create();
set_exits(([
"south":INRMS+"t2","northeast":INRMS+"b3"
]));
}