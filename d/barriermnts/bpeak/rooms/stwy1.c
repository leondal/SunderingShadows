//stwy1
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit IHRMS+"stwy.c";

void create(){
::create();
   set_exits((["down":INRMS+"bcliff8","up":INRMS+"stwy2"]));
} 

