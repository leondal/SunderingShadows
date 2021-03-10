#include <std.h>
#include "../cave.h"

inherit ROOM;
int items;

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 0);
   set_property("no sticks", 1);
   set_terrain(NAT_TUNNEL);
   set_travel(RUBBLE);
   set("short", "%^RESET%^%^ORANGE%^A hidden alcove%^RESET%^");
   set("long",
      "%^RESET%^%^ORANGE%^This niche in the cave walls opens up into a spacious room"+
      " that has obviously been occupied for some time now.  There are numerous pieces of"+
      " garbage that have been turned into furniture for the occupants.  There is a"+
      " bed against the wall furthest from the entrance and a rock obviously used"+
      " as a table.  The person or thing that lives here is"+
      " not here at the moment and you are not sure if you want to be here when it gets back."
   );
   set_listen("default", "%^RESET%^%^GREEN%^It is very silent here.");
   set_smell("default", "%^RESET%^%^CYAN%^This place smells awful.");
   set_items( ([
   "bed":"This is a bed of sticks, mud, padded dirt, and old clothes.",
   "rock":"This is a very large rock with a smaller rock pulled up to it, obviously a crude table and chair."
   ]) );
   set_search("default","There is not much here other than the rock and bed.");
   set_search("rock","This is just a large rock.");
   set_search("bed","You rummage through the disgusting bed and find a chest hidden in the mess.  Maybe you should search it?");
   set_search("chest", (: TO, "searching" :) );

   set_exits( ([
      "north" : TUNNEL+"tunnel08"
   ]) );
   items = random(2);
}

void searching() {
   if(!items) {
      write("Looks like someone beat you to whatever might have been there.");
      return;
   }
   switch(random(4)) {
   case 0:
      new("/d/shadow/room/mountain/obj/helmet")->move(TO);
      write("You find a helmet in the hidden chest!");
      tell_room(TO,TPQCN+" finds a helmet in a hidden chest.",TP);
      break;
   case 1:
      new("/d/shadow/room/mountain/obj/helmet2")->move(TO);
      write("You find a helmet in the hidden chest!");
      tell_room(TO,TPQCN+" finds a helmet in a hidden chest.",TP);
      break;
   case 2..3:
      "/d/common/daemon/randstuff_d"->find_stuff(TO,"random");
      write("You find something useful in the hidden chest!");
      tell_room(TO,TPQCN+" finds something useful in a hidden chest.",TP);
      break;
   }
   items = 0;
   return;
}

void reset() {
object obj;
   ::reset();
   if(!random(4))
      items = 1;
	if(!(present("grakulan",TO))){
          obj = new("/d/shadow/room/mountain/mons/grakulan");
	    obj->move(TO);
      }
}
