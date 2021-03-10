#include <std.h>
inherit ROOM;
void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("smithy", 1);
  set_short("%^YELLOW%^A%^RESET%^%^ORANGE%^rmorer");
   set_long(
"%^YELLOW%^A%^RESET%^%^ORANGE%^rmorer
This timber and stone building is Verbobone's Armory. Here one can sell or buy many forms of armor, hanging on the %^BOLD%^walls%^RESET%^%^ORANGE%^. In addition are some accessories, such as helmets and gloves. As soon as you enter this timber building, you feel intense heat emanating from a big forge that is located in the center of the room. This very large fire is fanned by bellows to its side.
"
     );
  set_smell("default","The smell of oil and iron pervades this area.");
  set_listen("default","The metal clangs as the shopkeeper works with it."); 
  set_property("no attack",1);
  set_exits((["north":"/d/deku/town/road8"]));
  set_items(([
     "walls":"The walls are covered with various pieces of iron work -- some quite fancy",
 ] ));
    if(!present("galem")) find_object_or_load("/d/deku/monster/galem")->move(TO);
}

void reset()
{
    ::reset();
    if(!present("galem")) find_object_or_load("/d/deku/monster/galem")->move(TO);
}
