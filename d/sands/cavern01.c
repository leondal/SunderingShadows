#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A sandstone cavern");
  set_long(
"You seem to have wound up in a giant sandstone cavern. The light stone\n"+
"seems to emit a very faint light. There is an ancient message scrawled\n"+
"into the sandstone. The almost dark tunnel continues north.");
  set_items(([
"message":"It reads: Beware to those whom do not care, you will find death lying here." ]));
  set_exits(([
"north":"/d/sands/cavern02" ]));
  add_pre_exit_function("north","north");
}

void north() {
  write("As you walk along the tunnel you trip on something and here a 'whoosh'\n"+
        "above you. You turn around to see 15 darts protruding from the other\n"+
        "side of the wall. You now notice 15 small holes in the wall, where the\n"+
        "darts obviously came from. You may want to watch your step from here on.\n");
  return 1;
}
