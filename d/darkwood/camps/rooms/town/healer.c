#include <std.h>
#include "../../elfisland1.h"
inherit HEALER;

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 2);
   set("short", "%^BOLD%^%^YELLOW%^Apothecary%^RESET%^");
   set_terrain(VILLAGE);
   set_travel(FOOT_PATH);
   set("long",
      "%^RESET%^%^GREEN%^ The large doorway opens up into a high ceiling room with"+
      " plenty of room to maneuver the ill and injured. This is obviously the village"+
      " healer."+
      " You enjoy a splendid view of the surrounding forest from the shop's window."+
      " The shop walls are lined with delicately carved shelves full of small pots and jars that"+
      " are filled with an assortment of bittersweet herbs and potions."+ 
      " There are a few small cots spaced out around the room for those that need to lay down."
   );
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell the bittersweet fragrance of assorted potions and herbs.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the peaceful sounds of the village life far below.%^RESET%^");
   set_items( ([ 
      "shelves": "The shelves all have subtle and delicate carvings.", 
      "jars":"Assorted pots and jars line the wooden shelves.", 
      "pots":"Assorted pots and jars line the wooden shelves.", 
      "cots":"These small cots for the ill and injured that need time to rest.",
   ]) );
   set_exits( ([
      "out" : TOWN+"road04",
   ]) );
   set_name("aravilar");
}

void reset(){
string clerk;
   ::reset();
   clerk = MON+"aravilar";
   if(!present("healer")) {
find_object_or_load(MON+"aravilar")->move(TO);
}
}
