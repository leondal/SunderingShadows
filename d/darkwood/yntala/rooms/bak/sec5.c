//sec5
#include <std.h>
#include "/d/darkwood/yntala/yntala.h"
inherit ROOM;


void create(){
::create();
   set_property("indoors",2);
   set_property("no teleport",1);
   set_property("no starve",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("");
   set_short("");
   set_smell("default","%^RESET%^%^ORANGE%^The smell of must is overwhelming.%^RESET%^");
   set_long("");
 //set_exits(([
   //"down":INRMS+"sec4"
   //]));
}
