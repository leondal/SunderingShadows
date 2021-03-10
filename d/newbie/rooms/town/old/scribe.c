#include "../../newbie.h"
inherit ROOM;

void create() {
   object ob;
   ::create();
   set_property("light", 2);
   set_property("indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
   set_short("Dulan's Scribe Shop");
   set_long(
@DESC
You have entered Dulan's Scribe Shop. Everything looks fairly new, as if
it has just recently opened. Shelves line the walls, filled with the
various needs of a scribe. There is a single desk facing the door, but 
nobody is sitting there. There are a few other desks along the walls,
but they seem to be used more for storage space than anything. A man 
paces the room, looking out the windows and doors occasionally. He 
appears pleased to see you, smiling broadly as soon as you enter the 
room. A small sign is hanging from the front side of the single desk.
DESC
   );
   set_items(([
      "shelves":"The shelves are mostly empty except for blank pieces of paper, writing instruments, and books.",
      "papers":"There appears to be all kinds of written records here.",
      "books":"There are books providing translation between several languages, some of which you can't even recognize.",
      "desk":"This is a large wooden desk, completely cleared of anything that might get in the way of a scribe's work. There is only a small pile of paper and writing implements.",
      "sign":"It reads:\nMap of Offestry for 5 gold coins.\nYou can <buy> one here.",
   ]));
   set_exits( ([
      "south":MAINTOWN"nstreet5",
   ]) );
}

void reset(){
   ::reset();
   if(!present("dulan"))
      find_object_or_load("/d/newbie/mon/dulan")->move(TO);
}

void init(){
   ::init();
   add_action("map_func","buy");
}

int map_func(string str){
   if(str != "map") return notify_fail("What do you want to buy?\n");
   if(!present("dulan")) return notify_fail("The scribe is not here.\n");
   if(TP->query_money("gold") < 5)
      return notify_fail("Only if you can pay 5 gold!\n");
   write("Dulan hands you a map of Offestry.");
   tell_room(ETP,"Dulan hands "+TPQCN+" a paper scroll.",TP);
   new("/d/newbie/obj/misc/map.c")->move(TP);
   return 1;
}
