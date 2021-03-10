//t3.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"transition";
int searched;

void create(){
::create();
set_exits(([
"southwest":INRMS+"t4","northeast":INRMS+"t2"
]));
}