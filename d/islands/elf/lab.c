#include <std.h>
#include "elf.h"

inherit "/std/lab";

void create(){
   object ob;
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_property("indoors",1);
   set_property("light",2);

   set_name("Ashta'Rathai lab");
   set_short("Ashta'Rathai lab");
   set_long("%^BOLD%^Ashta'Rathai lab\n%^RESET%^"+
      "%^CYAN%^Crafted in the %^RESET%^ornate%^CYAN%^ elven fashion, "+
	  "this lab provides all the essential "+
	  "apparatus the %^GREEN%^elven%^CYAN%^ magi need.  There "+
	  "are many counters and racks scattered "+
	  "throughout the room.  Also, many tables"+
	  " and mixing kits are present.  The center"+
	  " of the room %^RESET%^slopes down%^CYAN%^ with a strange "+
	  "circle of runes.  Perhaps this is where "+
	  "elves perform their secret magic? "+
      "\n\nThe command <help laboratory> will instruct "+
      "you in its use.\n");
   set_exits(([
           "west" : ROOMS"hall4"
   ]));
 	set_items(([
      (({"rack","racks"})) :
        "There are racks here used to store things.",
      (({"table","tables"})) : "These tables are sturdy.  The magi use them for experements.",
      (({"runes","rune"})) : "These runes circle the low spot in the room.  They look arcane in nature.",
	  (({"counter","counters"})) : "A sturdy stone counter.  It is set against the wall.",
	  (({"kit","kits"})) : "A kit of clay bowls and glass bottles.  It would work good for making potions.",
	   ]));

   set_smell("default","The the area smell pure, almost magicly so.");
   set_listen("default","Potions brewing can be heard.");
   set_door("door",ROOMS"hall4","west",0,0);
   set_door_description("door","The door appears to be made of a bright strange metal.");
   setOwner("none");
   setLabId("Ashta'Rathai");
   ob=new("/d/magic/obj/mirror");
   ob->set_short("%^RESET%^%^CYAN%^a m%^BOLD%^i%^RESET%^%^CYAN%^rror-l%^BOLD%^i%^RESET%^%^CYAN%^ke pool of quicksilver%^RESET%^");
   ob->add_id("pool");
   ob->add_id("quicksilver");
   ob->set_long("%^BOLD%^On the floor there is a large pool of quicksilver.  "+
   "There is a filigree surrounding the pool adding to the decorative"+
   " nature.  People look down at the pool and use it as a mirror.  It"+
   " seems strange to have a mirror in the floor.  %^RESET%^What could it be used for?");
   ob->move(TO);
}
