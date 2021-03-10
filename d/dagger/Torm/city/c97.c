#include <std.h>
#include "../tormdefs.h"
inherit ROOM;
void create()
  {
  ::create();
   set_short("Outside a Grand Library");
   set_long("You are standing outside of what used to be an old mansion that has been completely re-modled and"+
   " is now a small library. It is said to be dedicated to half-elven history and lore, and as strange a"+
   " concept as that is it somehow doesn't seem out of place here in Torm, which holds a little bit of"+
   " everything. The great doors stand wide, granting entrance to all who wish to learn more about half-elves.");
   set("night long","The night is cold here and before you looms a large newly rennovated building that has been"+
   " made into a library. Its doors stand open and inviting in this chill night air, and you see light pouring"+
   " forth from its open doors, chasing away the darkness that covers the streets.");
   set_smell("default","The salt air mingles with the faint scent of parchment.");
   set_listen("default","The crashing of the waves is but a distant murmur here.");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_exits(([
  "northwest":TCITY+"c2",
   "library" : TCITY+"library1",
  ]));
}
