#include <std.h>
inherit ROOM;
void create (){
::create ();
   set_travel(RUTTED_TRACK);
   set_terrain(NAT_CAVE);
set_property ("light", 1);
set_property("indoors", 1);
set_short("caves");
set_long("The cave ends here at the top of a steep inclining chute,
a mat made of woven reeds lies at the top of the chute.");

set_smell("default", "The sharp odor of oil tickles your your nose.");
set_listen("default", "You hear the echo of your footsteps and the faint
sound of dripping water.");
set_items(([
"mat" : "This mat of woven reeds seems to be the only way down. Try riding it.",
"chute" : "This deep, steep chute is coated with some kind of slippery oil.",
]));
set_exits( ([
"northeast" : "/d/dagger/cave1/rooms/room12",
]) );
}
void init() {
  ::init();

  add_action("ride","ride");
  add_action("ride","go");
}

int ride(string str) {
  if(!str) {
    write("Ride what?");
    return 1;
  }
  if((str == "mat") || (str=="woven mat")){
  write("%^BOLD%^You jump onto the mat and push off....You suddenly find yourself speeding downwards at a really high speed!
You swallow hard and scream loudly in horror or fun as the walls fly by
at fantastic speeds!
AHHH
   HHHHHHH
         HHHHHHH
               HHHHHHHH
                      HHHHHHHHH
                              HHHHHHHHHH
                                       HHHHHHHH
                                              HHHHHHHHH
                                                      HHHHHHHHH!!!!!!
WHHHEEEEEEEEE!!!!!!! That was fun!! You scream as you tumble out onto a
thick carpet of soft furs deep underground!
You also wonder how you are gonna get out?");
  tell_room(TO,"%^BOLD%^"+TPQCN+" jumps ont a woven reed mat and disappears down the chute at high speed!!!", TP);
this_player()->move_player("/d/dagger/cave1/rooms/entrance");
  return 1;
  }
}
