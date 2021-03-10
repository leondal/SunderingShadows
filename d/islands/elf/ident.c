#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_climate("arctic");
    set_name("Beren's Office");
    set_short("Beren's Office");
    set_long("Beren's Office
This is a no doubt a mage's office.  There is a desk"+
" and lots of shelves with components on them.  "+
"There are several tables along the walls that "+
"look to be running various experiments.  However"+
" the entry way is clear, indicating that the owner does not mind visitors."+
"\n");
        set_items(([
      (({"desk"})) :
        "This is a well used stone desk.",
              
          (({"shelves"})) : "The shelves are made "+
	  "of a dark wood and filled with strange bottled and bagged items.",
           ]));
   set_exits(([ "south" : ROOMS"hall7",
      ]));
   set_listen("default","There is a peaceful quiet.");
   set_smell("default",
   "It smells of fresh air here.");
   set_door("door",ROOMS"hall7","south","key");
   set_locked("door",0);
   set_door_description("door","This door is made of metal and quartz.");
}
void reset(){
::reset();
if(!present("beren"))new(MON"beren")->move(TO);
}
