#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_short("Aketon General Store");
   set_long("%^BOLD%^Aketon General Store%^RESET%^
You are standing in a large room with a counter. Lots of material pieces are "
      "scattered around the room. Several shelves are standing next to the "
      "wall behind the counter. Many types of accessories are displayed "
      "on the shelves. A few customers are busy choosing their accessory "
      "at the counter.");
   set_items( (["counter":"A hardwood counter in front of you.",
      "room":"A large room, pieces of materials scattered about the room.",
      "shelves":"Simple shelves used to display things.",
      "weapons":"All sorts of accessories are displayed here.",
      "customers":"They are busy finding the accessories they need."]) );
   set_property("light",3);
   set_property("indoors",1);
   set_smell("default","The smell of oil lanterns, and rope fills your "
      "nostrils.");
   set_listen("default","The sound of a craftman's tool fills your ears.");
   set_exits( (["north":RPATH1+"1one54"]) );
}

void init() {
   ::init();
   if( !present("furdos") )
      new(MPATH+"furdos")->move(TO);
}
