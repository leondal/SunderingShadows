#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "On the battlements of the Rose Keep."
  );
  set_long(
  "On the battlements of the Rose Keep.\n"
  "  You stand on the battlements of the rose keep overlooking the cursed hedge garden and the courtyard of the inner keep."
  "  The gloom  hangs low in the sky and the hedges fade into it to the point where you cant tell where the horizon should be."

  "\n"
  );
  set_smell("default",
  "The smell of decay from the hedges wafts up."
  );
  set_listen("default",
  "Your footsteps echo on the pink stones and off in the hedges you can hear faint screeching."
  );
  set_items(([
  ({"hedges","hedge gardens","hedge"}):"You dread walking back out to the world along its ape infested mazes.",
  "sky":"The gloom hanging over this place makes it impossible to see anything.",
  "keep":"The Rose Keep looks as if its made of blood stained granite in this gloom.",
  ({"stones","pink stones","floor"}):"The pink stones of the battlements looks bloodstained even though it isnt.  Seems all the fighting happened down in the courtyard.",
  "courtyard":"A few buildings hug the inside of the walls and a garden with a fountain similar to the one before the gates stand in the open area between the front gates and the keeps doors.",
  ]));
  set_exits(([
  "down":KEEP"k15.c",
  "east":KEEP"k12.c",
  "south":KEEP"k14.c",
  ]));
}
