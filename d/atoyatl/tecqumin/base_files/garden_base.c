#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit VAULT;

void create() {
  ::create();
  set_indoors(0);
  set_climate("tropical");
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("An overgrown garden");
  set_short( "An %^BOLD%^%^GREEN%^ov%^RESET%^%^GREEN%^e%^BOLD%^rgr"
    +"%^RESET%^%^GREEN%^o%^BOLD%^wn %^RESET%^%^GREEN%^garden" );
  set_long( "This walled %^GREEN%^garden%^RESET%^ may once have been"
    +" a place of simple %^CYAN%^tranquility%^RESET%^, with cool,"
    +" still %^BOLD%^%^CYAN%^pools%^RESET%^ and peaceful"
    +" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^ck"
    +" g%^RESET%^%^BOLD%^%^BLACK%^ard%^RESET%^e%^BOLD%^%^BLACK%^ns"
    +"%^RESET%^. However, but it has been overtaken by decades of"
    +" neglect. Vibrant %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
    +"ng%^RESET%^%^GREEN%^l%^BOLD%^e pl%^RESET%^%^GREEN%^a%^BOLD%^nts"
    +" %^RESET%^burst forth from all directions, and young"
    +" %^GREEN%^trees%^RESET%^ have sprouted and grown tall. The"
    +" %^BLUE%^ponds%^RESET%^ are murky with %^GREEN%^weeds%^RESET%^." );
  set_items(([ ({"pond", "ponds", "weeds", "pondweed"}) 
              : "The pondwater is dark green, nearly black, with a"
    +" thick layer of surface scum and algae. Barely visible below the"
    +" surface, thick weeds tangle together, choking the oxygen from the"
    +" water below. There are no signs of fish or other animal life.", 
           ({"plant", "plants", "jungle plants"}): "The jungle plants"
    +" that have overtaken the garden are no respecters of the carefully"
    +" planned design. They busrt forth from every available space, and"
    +" fill the waters of the ponds as well.",
            ({"tree", "trees"}): "The trees in the jungle have some"
    +" decades of growth. They feel too big for the space, even though"
    +" they are clearly younger than those in the surrounding jungle.",
           ({"wall", "walls"}) : "The garden is circled by a high wall,"
    +" presumably to keep it private for the %^CYAN%^Tecqumin"
    +" %^RESET%^royalty."
  ]));
  set_smell("default","The stagnant smell of the water in the ponds"
    +" mostly overcomes the perfumes of the jungle plants");
  set_listen("default","It is mostly quiet here, though sounds of"
    +" the jungle drift in from beyond the wall");
  set_exits((["south"   : CITY_ROOM + "throne_room" ]));
  set_door("arched door", CITY_ROOM + "throne_room", "south", 0);
  set_door_description("carved door", "This grand door is made of"
    +" %^BOLD%^%^BLACK%^time-blackened h%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^BLACK%^rdw%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^d%^RESET%^,"
    +" and carved with symbols of the %^CYAN%^Tecqumin gods");
}

void init(){
  ::init();
}
