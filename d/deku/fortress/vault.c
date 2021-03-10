#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Vault of Blood");
    set_long(
@KAYLA
Vault of %^RED%^Blood%^RESET%^
Within this chamber everything seems bathed in a dark, %^RED%^red %^RESET%^haze.
In the middle of the south wall is a statue of a demon sitting on
a throne.  The figure has a goat's head with skeleton hands appearing
through the folds of a dark robe.  The throne itself seems to be
comprised of snakes that form armrests.  In front of the statue sit
large red stones atop a velvet cushion, supported by a 3' high stone
pedestal.  As you adjust your vision, it appears as if the red light
in this chamber originates from the stones.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/fortress/hallN7"
    ] ));
    set_items(([
       "custion" : "The velvet cushion holds red stones that appear to radiate red light.",
"statue" : "This statue is made of stone and resembles a large demon with a goat's head",
    ] ));
}

void reset() {
  int r;
  ::reset();
  if(!present("chest")){
    r = random(2);
   if(r==0) new("/d/hm_quest/chests/chest10")->move(TO);
    else new("/d/hm_quest/chests/chest13")->move(TO);
  }
  if(!present("giant")) {
    new("/d/deku/fortress/monster/fire")->move(TO);
  }
  if(!present("hellhound")) {
    new("/d/deku/fortress/monster/hound")->move(TO);
    new("/d/deku/fortress/monster/hound")->move(TO);
    new("/d/deku/fortress/monster/hound")->move(TO);
  }
}
