
#include <std.h>
inherit ROOM;
void create(){
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("Level 1, Nasty Rat Breeding Room Number 1.");
  set("long",
@GIL
%^BOLD%^This is Nasty Rat Breeding Room Number 1.
Harvey the Rat King breeds Nasty Rats here.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the scent of Rats!");
set_listen("default", "%^BOLD%^%^BLUE%^You can hear the sounds of Baby Rats squeeking.");

  set_exits(([
     "east" : "/d/dagger/Daggerdale/sewers/level1/sewer9",
]));
}
