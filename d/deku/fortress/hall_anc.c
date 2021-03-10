#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(RUBBLE);
    set_short("Hall of the Ancients");
    set_long(
@KAYLA
%^YELLOW%^Vault of the Ancients%^RESET%^
This eerie, gigantic hall has fallen into decay.  Many tall
columns rise to a lofty ceiling, others have fallen over and
litter the center of the room like the trees in Shadowlord 
forest.  From behind the rubble comes a chittering noise.  A
huge granite throne sits against the left wall.
KAYLA
    );
     set_smell("default","The smell of rot and decay is strong in this room.");
    set_exits(([
       "south" : "/d/deku/fortress/hallN7"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("knight")) {
    new("/d/deku/fortress/monster/dknight1")->move(TO);
  }
}
