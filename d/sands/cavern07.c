#include <std.h>
#include "traps.h";
inherit ROOM;

int trap=1;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"This room is also filled with the strange designs, although they are now\n"+
"enhanced by a row of small holes placed in the wall at odd intervals. The\n"+
"rumbling continues.");
  set_items(([ "designs":"They look like they must have taken a great deal of time to create.",
"holes":"They act as an enhancing character in the designs." ]));
  set_exits(([ "northeast":"/d/sands/cavern08",
"southeast":"/d/sands/cavern06" ]));
  add_pre_exit_function("northeast", "northeast");
}

void init() {
  ::init();
  add_action("check", "check");
}

void reset() {
  ::reset();
  if(trap==0) trap=1;
}

void check() {
  int find;
  find=random(50);
  if(trap==0) {return notify_fail("You find no obvious traps.\n");}
  if(INT>=6) find+=3;
  if(INT>=12) find+=3;
  if(INT>=18) find+=4;
  if(find > random(100)) {
    write("You find a trap! You feel safer somehow, knowing it's there.");
    say(TPQCN+" finds a trap!");
    trap=0;
    return 1;
  } else {return notify_fail("You find no obvious traps.\n");}
}

void northeast() {
  if(trap==0) return 1;
  else wall_darts();
  return 1;
}
