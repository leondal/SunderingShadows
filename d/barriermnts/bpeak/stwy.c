//stwy
#include <std.h>
#include <rooms.h>
#include "bpeak.h"
inherit ROOM;



void create(){
::create();
   set_property("light",2);
   set_travel(STAIRWAY);
   set_terrain(ROCKY);
   set_name("%^RESET%^A granite staircase");
   set_short("%^RESET%^A granite staircase%^RESET%^");
   set_long((:TO,"ldesc":));
   set_listen("default","%^BOLD%^%^BLACK%^The sounds of wolves can be heard from somewhere above you.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^You are approaching the top of the cliff.%^RESET%^",
   "steps":"Each step here is huge.",
]));

}
string ldesc(string str){
   return("%^RESET%^This steep staircase is carved right into the cliff itself and looks as though it leads to the top.  Sheer cliff face rises high on either side of the staircase, dwarfing the giant slabs of granite that compose each individual step.  %^RESET%^\n");
} 

