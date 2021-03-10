#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Sharply sloping ramp.\n%^RESET%^"  );
  set_long(
  "%^RED%^Sharply sloping ramp.\n%^RESET%^"
  "  To the west a ramp slopes up into a patch of blackness.  To the northwest the ramp slopes down into a narrow doorway that has a open metal gate in it."
  "\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "gate":"A massive iron bound door hangs open.  It's 20 feet tall 2 feet thick and 12 feet across.  It looks like it could take a lot of punishment.",
  "doorway":"The door would open towards you and from the look of the gate and the frame it's in it would take some huge siege equipment to knock it down.   To bad you couldn't get that sorta thing past the corner though.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "northwest":ROOMS"b4",
  "west":ROOMS"b7",
  ]));
}
init(){
  ::init();
  add_action("close","close");
}
int close(string str){
  if(!str) return notify_fail("Close what?");
  if((str=="metal gate")||(str=="gate")){
  write("The hinges are stiff and the doors are to massive for you to move.");
  say(""+TPQCN+" tries to close the gates but fails as their immense weight defies it.");
  return 1;
  }
}
