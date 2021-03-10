#include <std.h>
inherit WATER;

#define RANDSTUFF "/d/common/daemon/randstuff_d.c"

int searched;
 
void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "no teleport" : 1 ]) );
  set_terrain(DEEP_WATER);
  set_travel(FRESH_BLAZE);
  set_short("%^ORANGE%^River under the bridge.");
  set_long("%^ORANGE%^You are swimming in the river under the bridge.  The "
    "water is reasonably clear here but the river is obviously quite deep "
    "and rushes past nearby.  The bottom is sandy with a few rocks and "
    "other debris settled in it.");
  set_exits((["bank":"/d/deku/open/bank1"]));
  set_listen("default","All sounds are from the rushing water all around.");
  set_items(([
    "rocks" : "They seem to be half-buried in the sand like the other debris.",
    "debris" : "It's hard to say what some of it might be since it is partly "
       "buried in the sand."
  ]));
    set_search("sand", (: TO, "search_stuff" :) );
}

void search_stuff(string str) {
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(random(2)) {
      write("You only find rocks and useless debris this time.");
      tell_room(ETP,""+TPQCN+" searches but doesn't seem to find much.", TP);
      searched = 1;
      return;
   }
   switch(random(5)) {
      case 0: RANDSTUFF->find_stuff(TO,"component", random(20));   break;
      case 1..2: RANDSTUFF->find_stuff(TO,"kit", random(20)+5);    break;
      case 3: RANDSTUFF->find_stuff(TO,"stuff",1);                 break;
      case 4: RANDSTUFF->find_stuff(TO,"coins", random(50)+50);    break;
   }
   write("%^BOLD%^You find something the water carried to the sandbar!");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" finds something in the sand.", TP);
   searched = 1;
   return;
} 

void reset() {
	::reset();
	if(!random(4)) searched = 0;
}


