//armor & weapon shop for Lothwaite - Circe 9/18/04

#include <std.h>
#include "../lothwaite.h"

inherit VAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("The Warrior's Crown");
    set_short("The Warrior's Crown");
    set_long(
       "This large %^BOLD%^stone building %^RESET%^is dominated by "+
       "%^ORANGE%^racks%^RESET%^, %^CYAN%^cases%^RESET%^, and %^ORANGE%^"+
       "shelves %^RESET%^holding organized pieces of %^BOLD%^%^BLACK%^"+
       "armor %^RESET%^and %^RED%^weapons%^RESET%^.  It seems the "+
       "%^RED%^forge %^RESET%^attached to this building does double "+
       "duty, producing both %^BOLD%^%^BLACK%^armor %^RESET%^and "+
       "%^RED%^weapons %^RESET%^for the town's guard.  A relatively "+
       "small %^ORANGE%^wooden counter %^RESET%^stands in the center "+
       "of the room, and from here the shopkeeper helps his customers.  "+
       "A %^BOLD%^doorway %^RESET%^on the western end of the shop "+
       "stands open, revealing the %^RED%^forge%^RESET%^.\n"
    );
    set_smell("default","You smell coal being burned in the forge out back.");
    set_listen("default","You hear the deafening racket of the bellows and hammers.");
    set_exits(([
       "west" : PATHEXIT"forge",
       "northeast" : PATHEXIT"pathway19"
    ]));
    set_items(([
       ({"armor","armors"}) : "Several pieces of armor, ranging "+
          "leather breastplates and wooden shields to chainmail "+
          "and fullplate, are arranged on cases and stands around "+
          "the room.",
       ({"weapon","weapons"}) : "The room is filled with racks "+
          "of all manner of weapons - swords, spears, bows, "+
          "maces, and every other weapon imaginable.  It seems "+
          "there is very little Mathuin cannot make.",
       ({"racks","cases","shelves"}) : "Mathuin's wares are "+
          "displayed all around the room in cases, on shelves, "+
          "and in racks.",
       ({"counter","wooden counter"}) : "This solid pine counter "+
          "is tall but narrow, providing only enough room for "+
          "Mathuin to count coins and make his exchanges.",
       ({"forge","doorway"}) : "The rectangular doorway is made "+
          "of thick stone blocks and leads to the forge to the "+
          "west.  Through there, you can see flames leap to the "+
          "ceiling as workers create new weapons and suits of "+
          "armor."
    ]));
   set_door("door",PATHEXIT"pathway19","northeast",0);
   set_door_description("door","A sturdy wooden door made of hewn "+
      "pine planks lashed together with thick rope and packed with "+
      "mud to keep out the wind.");
}

void reset(){
    ::reset();
        if(!present("mathuin"))
            new(MON"mathuin")->move(TO);
}
