
#include <std.h>
inherit ROOM;
void create(){
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("Level 1, Sewer Rat Breeding Room Number 1.");
  set("long",
@GIL
%^BOLD%^This is Sewer Rat Breeding Room Number 1.
Harvey the Rat King breeds Sewer Rats here.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the scent of Rats!");
set_listen("default", "%^YELLOW%^You can hear the sounds of Baby Rats squeeking.");

  set_exits(([
     "west" : "/d/dagger/Daggerdale/sewers/level1/sewer1",
]));
}

