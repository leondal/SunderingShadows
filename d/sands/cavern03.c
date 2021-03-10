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
"You seem to be making your way deeper underground as you traverse this\n"+
"ancient place. You also begin to notice tiny cracks in the ceiling which\n"+
"could be the effect of erosion. The tunnel leads north.");
  set_items(([
"cracks":"Something just isn't right about them..." ]));
  set_exits(([
"southeast":"/d/sands/cavern02",
"north":"/d/sands/cavern04" ]));
  add_pre_exit_function("north", "north");
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
  if(trap=0) {return notify_fail("You find no obvious traps.\n");}
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

void north() {
  if(trap==0) return 1;
  else contact_poison();
  return 1;
}
