#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Barracks under the walls of the Rose Keep."
  );
  set_long(
  "Barracks under the walls of the Rose Keep.\n"
  "  The high walls of the outer fortress loom above you with a set of stairs that climbs to their heights laid against them."
  "  Shadows lurk about here and its hard to make out any of the features of the room in the gloom that is everywhere around here."
  "  The cots and bunks are untidy and the barrels and chests in the room ransaced and a generall display of disorder is apparent."
  "\n"
  );
  set_smell("default",
  "You smell the far off taint of blood in the air."
  );
  set_listen("default",
  "You can hear faint footsteps from somewhere echo off the flagstones of the battlements."
  );
  set_items(([
 ({"cots","cot","bunks","bunk"}):"Untidy and ransacked they appear used but uncared for recently.",
  "stairs":"The stairs lead up to the top of the outer walls of the keep.",
  "walls":"Although not tall compared to many fortresses you've seen these seem to loom above you.",
  ]));
  set_exits(([
  "up":KEEP"k72.c",
  "west":KEEP"k63.c",
  ]));
}
