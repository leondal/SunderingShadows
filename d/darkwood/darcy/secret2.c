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

  As you walk into the room you are instantly drawn to the sight of
the painting on the wall of a skeletal being with jewels replacing
his teeth.  In this mouth is the bloody, gore encrusted body of a
headless man.  His head is in the hands of the skeletal man, with
the bony fingers digging into his dead eye sockets.  Although
dead, the mouth is open in the expression of a hideous scream that
death cannot end.

  You notice a passage open up in the southwest corner of the room.
The main passage towards the crypt entrance is to the north.

DARKWOOD
);
  set_smell("default","You can smell strange aromas making you light-headed and dazzled.");
  set_listen("default","Chants and animal screams mix in terrifying dissonance!");
  set_exits(([
    "north"     : ROOMDIR+"secret1",
    "southwest" : ROOMDIR+"secret3"
  ]));
}
