#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Shrine room of Hell");
    set_long(
@KAYLA
%^YELLOW%^Worship Chamber%^RESET%^
This large chamber is dominated by a large statue of a large 
human warrior standing on an elaborate dais cleverly carved
in the effect of a black dragon curled around the feet of the
human.  Surrounded by the statue are six maroon and white robed
figures kneel, facing the statue.  All these people are chanting
in deep tones.  On the north and west walls are the images of
the black dragon insignia.
KAYLA
    );
     set_listen("default","The eternal chanting from the priests fills the air.");
    set_exits(([
       "east" : "/d/deku/fortress/hallN5"
    ] ));
    set_items(([
       "statue" : "A very elaborate statue that depicts the Shadowlord himself."
    ] ));
}

void reset() {
  int x;
  ::reset();
  if(!present("cleric")) {
    for(x = 0;x < random(2) + 1;x++) {
        new("/d/deku/fortress/monster/k_priest")->move(TO);
        continue;
    }
  }
}
