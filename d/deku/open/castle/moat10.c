//	moat10.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 05:31:25 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(2);
    set_short("In the moat");
    set_long(
@ONLINE09D
You are standing in the moat. You pass under the bridge and you see the clear water here. The walls are high and you are impressed by their size !
ONLINE09D
    );
set_listen("default","You hear water splashing and birds singing");
    set_exits(([
"west" : CASTLE+"moat11",
"east" : CASTLE+"moat1"
    ] ));
    set_items(([
       "trees" : "You see the trees' reflection in the water. A beatifull sight.",
       "water" : "The water is here and making it possible for the fish to swim."
    ] ));
}
reset() {
  int x;
  ::reset();
  if (!present("fish"))
    { for (x = 0; x < random(3);x++)
      new(CASTLE+MONSTERS+"fish")->move(this_object());

    }
        }
