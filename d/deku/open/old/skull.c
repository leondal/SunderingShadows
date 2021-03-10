//note - modified by Styx 9/9/01 to add searching and using this as an inherit 
// for skull1 thru skull4 also.

#include <std.h>
#define RANDSTUFF "/d/common/daemon/randstuff_d.c"

inherit ROOM;
int searched;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_name("Shadowlord path");
    set_short("Shadowlord Path");
    set_terrain(HEAVY_FOREST);
    set_travel(GAME_TRACK);
    set_long(
@KAYLA
This path is a dark tunnel through a wall of leaves, roots, and briars.
Standing along the center of the path, spaced at irregular intervals as
far as you can see, are 6 ft. tall stakes.  On each stake is suspended an 
assortment of skulls and bones.  Some appear to be human, some don't.
KAYLA
    );
    set_items(([
       ({"skulls", "bones"}):"These are decorated with colored dyes, feathers, "
           "and tattered strips of cloth that sway in the light breeze.",
       ({"leaves", "roots"}): "The forest floor is covered with them and "
           "you have to wonder what they might conceal.", 
       "briars" : "They are so thick they block passage to the sides of the path.",
    ] ));
    set_listen("default","You hear scuffling noises to the north.");
    set_smell("default","You catch a whiff of something vile from the north.");
    set_search("leaves", (: TO, "search_stuff" :) );
    set_search("roots", (: TO, "search_stuff" :) );
    set_exits(([
       "south" : "/d/deku/open/path",
       "north" : "/d/deku/open/skull1"
    ] ));
}

void search_stuff(string str) {
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(random(4)) {
      write("You only find decaying leaves and roots this time.");
      tell_room(ETP,""+TPQCN+" searches but doesn't seem to find anything.", TP);
      searched = 1;
      return;
   }
   switch(random(5)) {
      case 0: RANDSTUFF->find_stuff(TO,"component", random(20));   break;
      case 1: RANDSTUFF->find_stuff(TO,"kit", random(20));         break;
      case 2: RANDSTUFF->find_stuff(TO,"stuff",1);
              if(random(3)) break;
      case 3..4: 
        RANDSTUFF->find_stuff(TO,"coins", random(50));
        write("%^BOLD%^%^RED%^You get snagged by a very sharp briar!  "
        "The wound bleeds profusely and burns badly for a few minutes.");
        TP->do_damage("right hand",random(8)+4);
        break;
   }
   write("%^BOLD%^You find something someone tossed aside or lost.\n");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" finds something that someone tossed "
      "aside or lost.", TP);
   searched = 1;
   return;
} 

void reset() {
	::reset();
	if(!random(4)) searched = 0;
}
