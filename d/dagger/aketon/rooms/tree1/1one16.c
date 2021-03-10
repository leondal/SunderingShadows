#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_short("Aketon Weapon Shop");
   set_long("%^BOLD%^Aketon Weapon Shop%^RESET%^
You are standing in a large room with a counter. Numerous pieces of metal "
      "are scattered around the room. Several shelves are standing next to the "
      "wall behind the counter. Many types of weapons are displayed on "
      "the shelves. A few customers are busy choosing their weapon at the "
      "counter.");
   set_items( (["counter":"A hardwood counter in front of you.",
      "room":"A large room, metal pieces scattered about the room.",
       "shelves":"Simple shelves used to display things.",
      "weapons":"All sorts of ordinary weapons are displayed here.",
      "customers":"They are busy finding their favourite weapon."]) );
   set_property("light",3);
   set_property("indoors",1);
   set_smell("default","You smell hot metal, an burning brasiers.");
   set_listen("default","You hear the sounds of metal work nearby.");
   set_exits( (["east":RPATH1+"1one17"]) );
}

void init() {
   ::init();
   if( !present("vavedos") )
      new(MPATH+"vavedos")->move(TO);
}
