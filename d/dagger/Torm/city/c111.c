#include <std.h>
#include "../tormdefs.h"
inherit PARK;
void create(){
  ::create();
  set_long("  You stand at the base of a grand set of wide, short steps that lead up to a mansion."
  "  The mansion is very ornate with spires leading into the sky from its towers and the peaks of its roof."
  "  All around you the park seems to be quiet as if in awe or scared of something that resides here."
  );
  set("night long",
  "%^BLUE%^"
  "All around you the park sits in silence.  The fog blankets the"+
  " ground here mostly surrounding the streambed.  The mansion itself"+
  " stretches into the sky seeming so much bigger now that the light of"+
  " sun isn't holding its presence down."
  );
  set_exits(([
  "south":TCITY+"c103",
  "northstairs":TCITY+"c130",
  "eaststairs":TCITY+"c133",
  ]));
}
