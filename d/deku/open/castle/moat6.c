//	moat6.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 05:31:25 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(1);
    set_short("In the moat");
    set_long(
@MOAT6
You reached the end of the moat here.  The castle wall is towering
above you and it's blocking your way.  When you look around you
don't see another way out than the way you came.
MOAT6
    );
set_listen("default","You hear nothing than just forest noises.");
    set_exits(([
"south" : CASTLE+"moat5",
    ] ));
    set_items(([
       "fish" : "You see no fish in the water and not just because it isn't clear anymore !",
       "water" : "The water isn't clear here,but the smell has gone.",
       "wall" : "The wall is high,solid and very dirty here."
    ] ));
}
int climb(string str) {
    if ((!str) || (!(str=="wall"))) {
      notify_fail("Climb something that isn't here ??\n");
      return 0;
              }
    if (str =="wall")
  {
     write("You try to climb the "+str+" but you find that it is to slippery.\n");
     return 1;
   }
                           }
init() {
       ::init();
       add_action("climb","climb");
       }
// There is a baby crocodille here
reset() {
     ::reset();
     if(!(present("crocodile"))) {
     new(CASTLE+MONSTERS+"croco")->move(this_object());
                                 }
         }
