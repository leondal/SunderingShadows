#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light" , 2);
  set_property("indoors" , 1);
  set_short("A Secret Passage below the Chateau Crypt");
  set_long(
@DARKWOOD
%^BOLD%^A Secret Passage below the Chateau Crypt%^RESET%^ 
  Without looking further than you are at this moment, you know you
are in an unholy place.  A place of death.  Not the lazy, almost
peaceful slumber of the inhabitants of the crypt above, but a death
from insanity with the madness so strong it threatens to overcome
the bounds of death to possess its victims into the after-life. 
Reality itself seems to be warped and corrupted into a sooty haze
filled with sparks of painfully bright light.

  The sounds are now louder and more obviously coming from the
south, where the passage opens into what looks to be a wide
underground temple.  Even from here, you can see some of what looks
like a giant statue of a horned demon in there.  To the west, the
passage takes you away from the temple and the relative safety of
the outside world.

DARKWOOD
);
  set_smell("default","You can smell strange aromas making you light-headed and dazzled.");
  set_listen("default","Chants and animal screams mix in terrifying dissonance!");
  set_exits(([
    "west"  : ROOMDIR+"secret1",
    "south" : ROOMDIR+"temple"
  ]));
}
