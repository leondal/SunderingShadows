#include <std.h>
      
inherit ROOM;
      
void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_short("%^GREEN%^%^BOLD%^S%^RESET%^%^GREEN%^eath's %^BOLD%^M%^RESET%^%^GREEN%^agic %^BOLD%^S%^RESET%^%^GREEN%^hop");
  set_long( "%^GREEN%^%^BOLD%^S%^RESET%^%^GREEN%^eath's %^BOLD%^M%^RESET%^%^GREEN%^agic %^BOLD%^S%^RESET%^%^GREEN%^hop
%^RESET%^%^MAGENTA%^This is a magic store. The valuable components of the mage's spells are sold here. All along the walls are strange and sometimes wonderful items whose purposes are only understood by the mages and occasionally the extraordinary Bard. The walls are plain. This store feels no need to garnish itself with flashy decorations of other stores. Everything appears to be quite well organized.");
  set_smell("default","The room is filled with mingled smells of various herbs and
concoctions.");
  set_exits((["north":"/d/deku/town/road7"]));
  set_items(([
"shelves":"These shelves are stacked with the components so vital to the mage."
     ] ));
    if(!present("seath")) find_object_or_load("/d/deku/monster/seath")->move(TO);
}

void reset()
{
    ::reset();
    if(!present("seath")) find_object_or_load("/d/deku/monster/seath")->move(TO);
}
