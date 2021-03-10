#include <std.h>
      
inherit ROOM;
      
void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_short("%^BOLD%^%^CYAN%^G%^RESET%^%^CYAN%^eneral %^BOLD%^S%^RESET%^%^CYAN%^tore of %^BOLD%^V%^RESET%^%^CYAN%^erbobone%^WHITE%^");
  set_long(
"%^BOLD%^%^CYAN%^G%^RESET%^%^CYAN%^eneral %^BOLD%^S%^RESET%^%^CYAN%^tore of %^BOLD%^V%^RESET%^%^CYAN%^erbobone%^WHITE%^
%^GREEN%^This is a general store. Basically you may buy all your essentials here. The %^ORANGE%^shelves%^GREEN%^ are lined with the stuffs to fill the backpacks of all adventurers. The store %^CYAN%^clerk%^GREEN%^ is prepared to take your orders to send you on your way."
     );
     set_exits((["south":"/d/deku/town/road3"]));
     set_items(([
       "shelves":"These shelves are stocked with goods for adventuring."
     ] ));
    if(!present("Burford")) 
    {
        find_object_or_load("/d/deku/monster/burford")->move(TO);
    }
}

void reset()
{
    ::reset();
    if(!present("Burford")) 
    {
        find_object_or_load("/d/deku/monster/burford")->move(TO);
    }
}
