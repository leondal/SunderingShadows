//updated by Circe 6/2/04 with color, etc.
// Mathowvy Road, just outside Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math3.c

#include <std.h>
#include "../include/tabor.h"

inherit CROOM;

void create() {
  set_monsters( ({ "/d/darkwood/tabor/mon/guard" }), ({random(3)+1}) );
  monster_party(40);
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Mathowvy Road, Tabor");
  set_short("Mathowvy Road, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, Tabor%^RESET%^
You are in Tabor, the capital town of the Kingdom of the same name, near
the southernmost edge of the city.  Here you can see the southernmost
shops in the city, the %^RED%^Lutgehr Brothers' Forge%^RESET%^, to your west.  The heat 
from the forge can be felt even from the street.  A shop stands on 
the eastern side of the street, a sign with a needle and thread
is above its door.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the northwest and southeast.
DAI
    );
  set_exits(([
    "west" : ROOMDIR+"armor",
    "southeast" : ROOMDIR+"math2",
    "northwest" : ROOMDIR+"math4",
    "south" : ROOMDIR+"lot-weapon",
    "east" : ROOMDIR+"new_tailor"
  ]));
  set_listen("default","You hear the constant sound of hammering on an anvil.");
  set_smell("default","The odor of burning wood and smoldering iron fills the air.");
  set_items(([
    "shop" : "Lutgehr Brothers' Forge - Finest weapons and armor on "+
        "the mainland!",
    "road" : "%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^: North to "+
        "Tabor, south to Azha in Tsarven."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

