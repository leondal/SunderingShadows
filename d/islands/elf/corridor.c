//gate to keep
#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
set_property( "light", 2);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("keep entrance");
    set_short("keep entrance");
    set_long(
     "%^BLUE%^%^BOLD%^T%^RESET%^his hallway is very elaborate%^BOLD%^%^BLUE%^"+
	 ",%^RESET%^ it has a %^GREEN%^marble floor%^RESET%^ and is lit by "
"%^BOLD%^%^MAGENTA%^numerous violet lights%^BLUE%^.%^RESET%^  The walls are elaborately decorated with pictures "
"telling battles of elves and statues of long passed on elven heroes%^BOLD%^%^BLUE%^.%^RESET%^  To the "
"south there are two thick leaves that hang down from above the ceiling%^BOLD%^%^BLUE%^,%^RESET%^ they "
"seems to be movable like a door%^BOLD%^%^BLUE%^.%^RESET%^ The corridor continues northward and "
"there are two archways both to the east and west%^BOLD%^%^BLUE%^.%^RESET%^  Above%^BOLD%^%^BLUE%^,%^RESET%^ the spiral "
"staircase ascends to the tower and back down to the grove%^BOLD%^%^BLUE%^.%^RESET%^");

	set_items(([
      (({"floor","marble floor"})) :
        "The floor is made of marble with patterns of leaves etched on it.",
      (({"lights","violet lights"})) : "The lights float near the ceiling.",
      (({"wall","walls"})) : "The walls have paintings "+
	  "of regal elves.",
	   (({"statue","statues"})) : "There are statues of elven "+
	  "heroes.  They look gallant.",
	   ]));

   set_exits(([ "north" : ROOMS"hgarden", 
     "east" : ROOMS"hall4",
	  "west" : ROOMS"hall3",
	  "stairs" : ROOMS"water",
	  "up" : ROOMS"tower",]));
   
   
   set_listen("default","Sounds of people walking on the stone can be heard.");
   set_smell("default",
   "The air here is pleasant.");
  set_door_pre_exit_function ("ornate door","GoThroughDoor" );
   set_door("ornate door",ROOMS"water","stairs","key");
      set_open("ornate door",0);
      set_locked("ornate door",0);
}
int GoThroughDoor() {
     write("You descend the stairs and exit the keep.");
     tell_room(ETP, TPQCN+" descend the stairs and exit the keep.",TP); 
//need to allow normal GoThroughDoor for the regular door exits
   return ::GoThroughDoor();
}
void reset() {
   ::reset();
   if(!present("mage guard"))
      new(MON"guard")->move(TO);
   if(!present("mirror warrior"))
     new(MON"guard2")->move(TO);
 }
