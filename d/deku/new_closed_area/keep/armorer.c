#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("Blacktongue's Armorer");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_long(
@GRAY
%^YELLOW%^Blacktongue's Armorer%^RESET%^
This timber and stone building is Blacktongue's Armory.  Here one
can sell or buy many forms of armor and in addition buy some
accessories such as helmets and gloves.  There is an intense heat
emanating from the large forge located in the center of the room.
%^YELLOW%^<help shop>%^RESET%^ will give a list of shop commands.
GRAY
     );
  set_smell("default","The smell of oil and iron permeates this area.");
  set_exits((["north":"/d/deku/keep/keepW7"]));
  set_items(([
"walls":"The walls are covered with various pieces of iron work, some quite fancy",
  ] ));
}

void reset(){
 ::reset();
  if(!present("pikel")) {
    new("/d/deku/keep/monster/pikel")->move(TO);
  }
}
