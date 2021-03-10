//sec4
#include <std.h>
#include "../yntala.h"
inherit ROOM;


void create(){
::create();
   set_property("indoors",2);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("");
   set_short("");
   set_smell("default","%^RESET%^%^ORANGE%^The smell of must is overwhelming.%^RESET%^");
   set_long("");
   set_exits(([
   "down":INRMS+"sec3",
   "up":INRMS+"sec5",
   ]));
}
