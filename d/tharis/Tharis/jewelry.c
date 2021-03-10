//updated by Circe with new desc & jeweler.  9/14/04
//jewelry.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

int FLAG;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);
   set_short("Small Jewelry Store");
   set_long(
      "%^MAGENTA%^Jewelry by Yseult%^RESET%^\n"+
      "This rather small jewelry store seems to be staffed by "+
      "only one person - the young woman who is often behind the "+
      "counter.  The walls of the room support %^CYAN%^glass "+
      "cases %^RESET%^lined with %^MAGENTA%^deep maroon velvet"+
      "%^RESET%^.  Atop the lining are various pieces of %^YELLOW%^"+
      "jewelry%^RESET%^, from %^BOLD%^pins %^RESET%^to %^BOLD%^"+
      "%^RED%^anklets %^RESET%^and %^BOLD%^%^CYAN%^rings%^RESET%^.  "+
      "There is no work area here, only a small %^ORANGE%^wooden "+
      "table %^RESET%^near the right side of the room.  The thick "+
      "%^BOLD%^%^BLACK%^drapes %^RESET%^always seem to be pulled shut, "+
      "covering the two tiny windows and the walls behind the cases.  "+
      "There is a large tapestry covering the back wall as well.\n"
   );
   set_smell("default","A light fragrance of heady perfume hangs in the air.");
   set_listen("default","The bustle of the street outside works its way into the room.");
   set_items(([
      "tapestry" : "This tapestry is of a dwarven mining scene.  "+
         "You can see the diamonds being extracted from the ground.  "+
         "You notice that the tapestry sways a little even when there "+
         "appears to be no breeze.",
      ({"case","cases","glass cases","velvet","maroon velvet"}) : "Though "+
         "impressively made of glass, the cases seem to be somewhat low "+
         "quality, with thick places and imperfections in the glass.  "+
         "Like the shopkeeper, they don't quite seem to belong here, "+
         "although the jewelry displayed is quite beautiful and unique.",
      ({"jewelry","pins","anklets","rings"}) : "The jewelry displayed "+
         "is fantastically made, though some of it seems a little off "+
         "the beaten path.  All sorts of materials are used in their "+
         "creation - gems, metals, and woods.",
      ({"drapes","thick drapes"}) : "Thick drapes made of a dusky "+
         "black material cover the walls, making the small shop "+
         "seem a little more closed in.  They are always kept "+
         "pulled closed for some strange reason.",
      ({"window","windows"}) : "You cannot see the windows for the drapes."
   ]));
   set_search("tapestry","Looking closer, you think you might be "+
      "able to pull the tapestry.");
   set_exits(([
      "north":ROOMS"s11",
      "south":ROOMS"wstreet1",
   ]));
   set_invis_exits(({"north",}));
   set_pre_exit_functions(({"north",}),({"north_preExit",}));
   set_door("door",ROOMS"s11","north","blah");
}


void reset(){
   ::reset();
   if(!query_night()){
      if(!present("yseult")){
         new("/d/tharis/monsters/jeweler")->move(TO);
      }
   }
   FLAG =0;

}

void init(){
   ::init();
   add_action("pull","pull");
   add_action("pull","lift");
}

int north_preExit(){
      if(!FLAG) {
        tell_object(TP,"You cannot go that way.");
        return 0;
   }
   return 1;

}

int pull(string str){
   if(str != "tapestry" && str != "tapestries") 
      return notify_fail("Pull what?\n");

   tell_object(TP,"You notice that one of the tapestries was "+
      "covering a door to the north.");
   FLAG = 1;
   return 1;
}




