#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit J_ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_climb_exits(([ "descend" : ({base_name(TO)[0..strlen(base_name(TO)) - 7] + "snake_room",2,6,200}) ]));
}
void init() {
   ::init();
}

void reset(){
  ::reset();
  if (!present("snake", TO))
  {
    new(MOB + "anaconda")->move(TO);
  }
}

string long_desc(){
  return "%^ORANGE%^You are resting on one of the lower branches of a great"
    +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^"
    +"%^GREEN%^l%^BOLD%^%^GREEN%^e %^RESET%^%^GREEN%^tree%^ORANGE%^. The solid,"
    +" sturdy limb supports your weight easily. %^GREEN%^Le%^BOLD%^%^GREEN%^a"
    +"%^RESET%^%^GREEN%^ves%^ORANGE%^, wet from the %^BLUE%^humidity"
    +" %^ORANGE%^of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
    +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
    +" %^BOLD%^%^CYAN%^air%^RESET%^%^ORANGE%^, brush against you, and"
    +" %^GREEN%^trailing v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes"
    +" %^ORANGE%^loop around branches before dropping back toward the ground.";
}
