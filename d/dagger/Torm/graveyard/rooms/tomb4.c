#include <std.h>
inherit CVAULT;
void create(){
  ::create();
  set_property("no teleport",1);
  set_property("indoors",1);
  set_property("light",2);
  set_short("%^BOLD%^%^BLACK%^A grand decaying Tomb");
  set_long(
  "%^BOLD%^%^BLACK%^"
  "A grand decaying Tomb.\n"
  "%^RED%^"
  "  This mosoleum was once draped with finery and a stone bier lays in the center of the room"
  "  A skeleton still lays on the bier and the dust appears undisturbed in the room, but you still have the feeling that something walks the shadows."
  );
  set_smell("default","The stink of decay hangs heavy in the air.");
  set_listen("default","A faint scratching sounds from somewhere.");
  set_items(([
  "bier":"A low stone table on which the lord who was laid to rest heres skeleton still remains.",
  "skeleton":"Its bones are blackened from the fragments of leathery skin still clinging to it.",
  "finery":"Rags hang from the corners of the ceiling and once a funeral wrap was laid on the bier but its long since rotted to little more than fragments.",
  ]));
   set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
  set_exits(([
  "out":"/d/dagger/Torm/graveyard/rooms/grave27.c",
  ]));
  set_door("door","/d/dagger/Torm/graveyard/rooms/grave27.c","out","rusted key");
  set_string("door","open","With a heavy grating noise the tomb door swings open.");
}
void reset(){
  object mon;
  ::reset();
  if(!present("wight")){
  new("/d/dagger/Torm/graveyard/mon/twight.c")->move(TO);
  }
}
int GoThroughDoor() {
  if(present("wight")){
  write("%^RED%^The wight blocks your only way out!!");
  say("%^RED%^The wight moves to block "+TPQCN+"s escape!!");
  return 0;
  }
  return 1;
}
