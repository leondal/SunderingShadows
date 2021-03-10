#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_property("light",2);
    set_name("office");
    set_short("minister's office");
    set_long("%^BOLD%^%^GREEN%^Minister's office \n\n%^RESET%^"
"%^GREEN%^This is a bit of a tree house that has been made "+
"into a large office and storage area.  Unlike a "+
"conventional tree house the area looks to be formed"+
" from living wood as the branches snake out in odd"+
" ways to form this room.  There is a ladder leading "+
"back down.  In the center of the room is a large"+
" wooden desk.  There are several racks around for "+
"storing weapons and armor.  ");

        set_items(([
      (({"ladder"})) :
        "It leads back down the the jail.",
      (({"desk"})) : "This scribe's desk has seen a lot of use.",
      (({"rack","racks"})) : "The racks are filled with various supphies for the guards.",
           ]));

   
      set_exits(([ "down" : ROOMS"guard1",
          ]));

   set_listen("default","The smell of trees fill the room.");

   set_smell("default",
   "This place is bustling with elves coming and going.");
}
void reset() {
  ::reset();
  if(!present("minister"))new(MON"minister")->move(TO);
  if(!present("sign"))new(OBJ"sign1")->move(TO);
  //sign shows a log of recent attacks in city.
}
