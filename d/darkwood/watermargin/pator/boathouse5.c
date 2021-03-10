//	boathouse5.c
//	Written by Pator@ShadowGate
//	Fri Apr 7 1995

#include <boathouse.h>

inherit ROOM;

void create() {
    room::create();
    set_light(-1);
    set_indoors(1);
    set_short("Inside a little hole");
    set_long(
@HOLE
You are inside a little hole.  You hear water running and you suspect that
you are under the lake.  You can't see much but you can make out a 
inscription in the wall. Maybe it could help you, because your hand can't
resist glyding over the inscriptions.
HOLE
    );
set_smell("default","It is very damp and musty in here.");
set_listen("default","You can hear the water, that's all");
    set_exits(([
       "out" : WATERM_BH+"boathouse2.c"
    ] ));
    set_items(([
       "inscription" : 
@INSCRIPTION
When you look at the inscription you see the picture of a waterspirit that is in a cave.  It is repairing the watersword with some potion.  Somehow you believe that after getting the potion and the sword you will have a very powerfull weapon indead!! 
INSCRIPTION
] ));
}

int feel(string str)
{
    if (!(str = "inscription"))
      { write("You feel nothing !  Does that surprise you ??\n");return 0; }
   else 
     { write(
@FEEL
When you feel at the inscription you notice that is must be very old, because
dust has almost totally filled the carvings.  You feel that you have to look
at them, because they seem very important.
FEEL
);  return 1;}
  }

init()
   {
      ::init();
      add_action("feel","feel");
    }
