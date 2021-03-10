#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no snakes",1);
    set_name("Keep Blacktongue");
    set_short("Keep Blacktongue");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long( (: TO, "ldesc" :) );
   set_smell("default","Dust and ale permeate the walls of this Keep");
   set_listen("default","You hear voices and shouts from guards now and then.");
   set_items(([
   ] ));
    set_exits(([  "down" : "/d/deku/keep/towerE1i" ] ));
}

void reset() {
  ::reset();
  if(!present("archer") && !random(2) ) {
    new("/d/deku/keep/monster/archer")->move(TO);
    if(!random(3))   new("/d/deku/keep/monster/archer")->move(TO);
  }
}

string ldesc(string str) {
   return("%^YELLOW%^Tower of Keep Blacktongue%^RESET%^\n"
     "You are standing on the top of one of the guard towers that protect Keep "
     "Blacktongue.  Chill winds whip your cloak as you stand upon the "
     "stone tower.  All around you, Shadowlord Forest stretches to the "
     "horizon with its dark leaves shivering in the wind.");
}
