#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_short("Aketon Armoury");
   set_long("%^BOLD%^Aketon Armoury%^RESET%^
You are standing in a large room with a counter. Numerous pieces of metal are "
      "scattered around the room. Several shelves are standing next to the "
      "wall behind the counter. Many types of armours are displayed on "
      "the shelves. A few customers are busy choosing their armour at the "
      "counter.");
   set_items( (["counter":"A hardwood counter in front of you.",
      "room":"A large room, metal pieces scattered about the room.",
      "shelves":"Simple shelves used to display things.",
       "weapons":"All sorts of ordinary armours are displayed here.",
      "customers":"They are busy finding their favourite armour."]) );
   set_property("light",3);
   set_property("indoors",1);
   set_smell("default","You smell dyes.");
   set_listen("default","You hear the sounds of work nearby.");
   set_exits( (["west":RPATH1+"1one50"]) );
}

void init() {
   ::init();
   if( !present("chandos") )
      new(MPATH+"chandos")->move(TO);
}
