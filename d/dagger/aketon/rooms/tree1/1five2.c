#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Living room on top of the tree");
   set_long("%^GREEN%^Living room on top of the tree%^RESET%^
The living room is large. You never thought that is possible to build such a "
      "large sized room on top of a tree. Similar to the stairways at the house "
      "entrance, the floor is covered by some thick beautiful carpet. Two "
      "large windows occupy the north wall. More drawings are hanging "
      "on the walls here. A long wooden couch covered with cotton, a set "
      "of cushions and a single candlestick are here. Above your head is a "
      "crystal chandelier.");
   set_items( (["house":"The house is quite large and is built on the "
      "tree branches.",
      "windows":"You can see the other parts of the house through the "
      "windows.",
      "carpet":"These beautiful carpets are made by craftsmen in Tonovi.",
      "couch":"A wooden couch with some cotton covering it. It looks like "
      "comfortable to sit on.",
      "cushions":"They are lay on the carpet randomly, you can probably "
      "sit on them and take a break of your journey.",
      "candlestick":"A candlestick coated with gold.",
      "chandelier":"A large crystal chandelier hanging from the ceiling.",
      "drawings":"These are the drawings of the mayors of Aketon."]) );
   set_smell("default","Smells of perfume fill your nostrils.");
   set_listen("default","It is quiet here.");
   set_exits( (["south":RPATH1+"1five1",
      "southwest":RPATH1+"1five3",
      "southeast":RPATH1+"1five4"]) );
}
