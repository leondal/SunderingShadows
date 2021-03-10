//weapon.c
//updated by Circe 9/11/04
#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("light",2);
   set_property("indoors",1);
   set_property("smithy",1); 
   set_name("Dragon's Tooth Weapons");
   set_short("Dragon's Tooth Weapons");
   set_long(
@JAVAMAKER
%^BOLD%^%^RED%^Dragon's Tooth Weapons%^RESET%^
This cluttered shop has its walls lined with every variety of
common %^BOLD%^weapon%^RESET%^.  The left side of this shop is dominated by
the %^RED%^smithy%^RESET%^ itself.  Several strong-looking %^ORANGE%^workers %^RESET%^pound relentlessly
on the %^BOLD%^stronger steel%^RESET%^.  The %^BOLD%^%^BLACK%^bellows %^RESET%^to the back of the room
pump %^CYAN%^air %^RESET%^into the %^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^re%^RESET%^, bringing it to a new intensity.  The back of the
room has a large %^ORANGE%^table %^RESET%^attached to the wall.  There strips of %^ORANGE%^leather%^RESET%^
and %^BOLD%^%^BLACK%^iron %^RESET%^join to make weapons such as whips and flails.
JAVAMAKER
   );

   set_smell("default","The steam from the cooling barrel burns your nose hairs.");
   set_listen("default","The pounding of steel and the hiss of steam "+
      "drown out the shouts of the men.");
   set_items(([
      ({"men","workers"}) : "These well-muscled smiths swing large "+
         "hammers for 12 hours a day.  They are dark from the tanning "+
         "of the heat, and ripple with every swing of the hammer.",
      "table" : "This table seems attached to the wall.  You notice "+
         "that there is some scarring on the floor around the table.",
      "bellows" : "These bellows are huge air bags that are squeezed, "+
         "pushing air into the flames and making them burn hotter.",
      ({"smith","smithy"}) : "The smith is full of strong men working to produce "+
         "fine weapons.  There are gloves and various small bits of "+
         "metal that can be used in repairing your own weapons, though "+
         "you would have to provide your own billets should you wish "+
         "to use this smithy to make something new.",
      "scarring" : "The floor by the legs of the table looks as if "+
         "it's scarred by the legs of the table.",
      "fire" : "The fire in the smithy burns high."
   ]));
   set_exits(([
      "out" : ROOMS"main7",
   ]));
   set_door("door",ROOMS"main7","out","blah");
}


void reset(){
   ::reset();
     remove_exit("back");
     if(!present("thalusis")){
	find_object_or_load(MON"thalusis")->move(TO);
     }
}

void init(){
   ::init();
     add_action("pull","pull");
}

int pull(string str){
   if(!str || str != "table"){
      return notify_fail("Pull what?\n");
   }
   tell_object(TP,"With a grunt you pull the table, scraping the floor.");
   tell_room(TO,"With a grunt, "+TPQCN+" pulls the table from the "+
      "wall revealing an exit.",TP);
   add_exit(ROOMS"s5","back");
   return 1;
}
