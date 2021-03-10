#include <std.h>
inherit ROOM;

void create(){
   object ob;
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("fill waterskin", 1);
   set_short("A Fountain in Daggerdale.");
   set("day long",
@GIL
%^ORANGE%^This is the city Fountain in the middle of Market Square.%^RESET%^
%^BOLD%^The Fountain has a large silver Dragon statue in the center of the
pool, it spurts cool water in a stream from its jaws.%^RESET%^
%^ORANGE%^The shallow pool under the Dragon is filled with clean, clear water
and coins lie about the bottom.
You can exit the Fountain square to the North, South, East or West.
GIL
);
   set("night long",
@GIL
%^YELLOW%^This is the city Fountain in the middle of Market Square.%^RESET%^
%^BOLD%^The Fountain has a large silver Dragon statue in the center of the
pool, it spurts cool water in a stream from its jaws.%^RESET%^
%^YELLOW%^The Dragons eyes glow and light up the square area brightly.
The shallow pool under the Dragon is filled with cool, clear water
and a few coins lie about the bottom.
You can exit the Fountain square to the North, South, East or West.
GIL
   );
   set_smell("default", "You can smell the cool water of the Fountain.");
   set_listen("default", "You can hear the sounds of villagers talking all around you.");
   set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"fountain" : "This large round Fountain has a shallow pool and a Dragon statue spurting water from its jaws into the pool.",
"eyes" : "They are most definantly magic gems that glow at night to light the square.",
"pool" : "It's not very deep and several coins lie around the bottom",
"coins" : "Awww shucks they are only copper.",
"jaws" : "The Dragons jaws are opened wide showing his sharp teeth, the water issues from within its throat and spurts out into the pool.",
   ]));

   set_exits(([
     "north" : "/d/dagger/Daggerdale/streets/street28",
     "south" : "/d/dagger/Daggerdale/streets/street15",
     "west" : "/d/dagger/Daggerdale/streets/street21",
     "east" : "/d/dagger/Daggerdale/streets/street22",
   ]));
/*  moving these to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, etc.

  find_object_or_load("/d/npc/skeet");
  find_object_or_load("/d/npc/aldera");
  find_object_or_load("/d/npc/needlia");
  find_object_or_load("/d/npc/effram");
  find_object_or_load("/d/npc/brunson");
*/

   ob = new("/std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board", "daggerdale board", "Daggerdale board" }));
   ob->set_board_id("daggerdale_board");
   ob->set_short("Daggerdale City Bulletin Board");
   ob->set_long("A sturdy wooden frame supports a cork noticeboard here, "+
     "to allow businesses to advertise and citizens and adventurers "+
     "to communicate about events.");
   ob->set_max_posts(50);
   ob->set_location("/d/dagger/Daggerdale/fountain/fountain.c");
}

void reset() {
  if(!present("dragon fountain"))
    new("/d/dagger/Daggerdale/streets/items/objs/dragon_fountain.c")->move(TO);
}

void init() {
  ::init();
  add_action("drink","drink");
}

int drink(string str) {
  if(!str) {
    write("Drink what?");
    return 1;
  }
  if((str == "from fountain") || (str=="water") || (str=="from water") || (str=="the water") || (str=="from pond")) {
    write("%^BOLD%^%^BLUE%^You drink your fill from the cool, clear fountain water.");
    say("%^BOLD%^%^BLUE%^"+TPQCN+" bends and drinks from the fountains water.");
    TP->add_quenched(50);
    return 1;
  }
}
