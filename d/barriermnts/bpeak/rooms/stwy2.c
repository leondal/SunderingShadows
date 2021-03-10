//stwy2
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit IHRMS+"stwy.c";

void create(){
::create();
   set_exits((["down":INRMS+"stwy1","up":INRMS+"stwy3"]));
} 

