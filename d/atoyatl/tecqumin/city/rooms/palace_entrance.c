#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit VAULT;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A grand entrance");
  set_short( "%^ORANGE%^A %^CYAN%^grand %^ORANGE%^entrance" );
  set_long( "%^ORANGE%^This semicircular %^RESET%^stone%^ORANGE%^"
    +" chamber has a high ceiling and finely worked walls, marking it"
    +" as the entrance to a building of the highest status. It"
    +" appears to have been long abandoned, though. Layers of"
    +" %^RESET%^d%^BOLD%^%^BLACK%^u%^RESET%^st%^ORANGE%^, and creeping"
    +" %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^l%^RESET%^%^GREEN%^"
    +"ia%^BOLD%^g%^RESET%^%^GREEN%^e %^ORANGE%^cling to the%^RESET%^"
    +" walls %^ORANGE%^and %^RESET%^floor%^ORANGE%^.%^BOLD%^%^YELLOW%^"
    +" L%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^ght%^RESET%^%^ORANGE%^"
    +" streams in through the front entrance, which is in the form of"
    +" the open mouth of a %^BOLD%^%^YELLOW%^j%^RESET%^%^ORANGE%^u"
    +"%^BOLD%^%^YELLOW%^ng%^RESET%^%^ORANGE%^l%^BOLD%^%^YELLOW%^e"
    +" c%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^t%^RESET%^%^ORANGE%^,"
    +" complete with sculpted %^BOLD%^%^WHITE%^t%^RESET%^e%^BOLD%^"
    +"%^WHITE%^e%^RESET%^t%^BOLD%^%^WHITE%^h %^RESET%^%^ORANGE%^at the"
    +" top and bottom corners. It grows %^BOLD%^%^BLACK%^d%^RESET%^a"
    +"%^BOLD%^%^BLACK%^rk%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^"
    +" %^ORANGE%^to the rear, where a %^RESET%^stone double door"
    +" %^ORANGE%^leads further into the building." );
  set_items(([({"mouth", "front entrance"}): "The entrance to the"
    +" building is through a stone representation of the snarling mouth"
    +" of a great %^BOLD%^%^YELLOW%^j%^RESET%^%^ORANGE%^u%^BOLD%^"
    +"%^YELLOW%^ng%^RESET%^%^ORANGE%^l%^BOLD%^%^YELLOW%^e c%^RESET%^"
    +"%^ORANGE%^a%^BOLD%^%^YELLOW%^t%^RESET%^. Thin,%^BOLD%^%^WHITE%^"
    +" curved white pillars%^RESET%^ in the floor and ceiling either"
    +" side of the entrance represent the cat's threateningly displayed"
    +" %^BOLD%^%^WHITE%^fangs%^RESET%^.",
         ({"tooth", "teeth", "fang", "fangs", "pillar", "pillars" }): 
     "The pillars appear to be carved from %^BOLD%^%^WHITE%^i%^RESET%^v"
    +"%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^y %^RESET%^or %^BOLD%^"
    +"%^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^ne%^RESET%^. Since they are"
    +" over four and a half feet in height, you have to wonder where"
    +" the original material came from."  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
  set_exits((["out"   : CITY_ROOM + "palace_approach",
              "north" : CITY_ROOM + "palace_entry_hall"]));
  set_door("double door", CITY_ROOM + "palace_entry_hall", "north", 0);
  set_string("double door","open","The heavy stone doors swing open"
    " silently, with the lightest touch");
  set_string("double door","close","The heavy stone doors swing closed"
    +" silently, with just the slightest whoosh as they form an airtight"
    +" seal");
  set_door_description("double door", "These double doors are made of"
    +" stone. They are enormously heavy, but set on a cunning mechanism"
    +" that allows them to swing silently open with the lightest touch.");
}

void init(){
  ::init();
}

