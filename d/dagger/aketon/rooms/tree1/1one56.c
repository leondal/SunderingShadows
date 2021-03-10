#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_short("Aketon Archery");
   set_long("%^BOLD%^Aketon Archery%^RESET%^
You are standing in a huge place. A counter is to the east. Some large "
      "shelves are standing next to the wall behind the counter. Many types of "
      "bows and arrows are shown there. A target board made of straws and "
      "supported by a tripod is standing close to the south wall. It is "
      "used for customers to test their brand new bows. Several customers "
      "are busy choosing the bow they want at the counter.");
   set_items( (["counter":"A hardwood counter to the east.",
      "place":"Large place with a target board to the south.",
      "shelves":"Simple shelves used to display things.",
       ({"target","board"}):"A target board with a bulls-eye is to the south "
      "for customers to test the new bows they've purchased.",
      "tripod":"It supports the target board.",
      "bows":"There are different kinds of bows sold here.",
      "arrows":"There are different kinds of arrows sold here.",
      "customers":"They are busy finding the bow they want."]) );
   set_property("light",3);
   set_property("indoors",1);
   set_smell("default","The smell of fresh woods fills your nostrils.");
   set_listen("default","The sounds of wood crafting fills your ears.");
   set_exits( (["north":RPATH1+"1one48"]) );
}

void reset() {
   ::reset();
   if( !present("ziliot") )
      new(MPATH+"ziliot")->move(TO);
}
