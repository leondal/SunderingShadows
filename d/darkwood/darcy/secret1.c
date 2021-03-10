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
..In comparison to the dark crypt, not only is this passage
well-lit, it is lit by huge braziers burning with bright blue and
white flames. You can now hear what your frightened mind told you
were the sounds of the dead stirring as the muffled sounds of
frenzied chants.  Now, the sounds are no longer muffled and the
braziers light a brilliant path to the source of those hymns to an
unknown god or demon king.

..You see now that the stone crypt lid is worked by a mechanism that
allows one man to lift it effortlessly.  You can always go up and
out. Perhaps that would  be the right thing to do, if only to save
your own sanity and maybe your life as well.

DARKWOOD
);
  set_smell("default","You can smell strange aromas making you light-headed and dazzled.");
  set_listen("default","Chants and animal screams mix in terrifying dissonance!");
  set_exits(([
    "up"    : ROOMDIR+"crypt",
    "east"  : ROOMDIR+"secret0",
    "south" : ROOMDIR+"secret2",
  ]));
}
