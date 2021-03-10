//t4.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"transition2";
int searched;

void create(){
::create();
set_exits(([
"southwest":INRMS+"t5","northeast":INRMS+"t3"
]));
}