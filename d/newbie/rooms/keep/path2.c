#include <std.h>
#include "../inherit/keep.h"
inherit ROOM;

void create() {
   ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(FOOT_PATH);
   set_property("light",2);
   set_name("A well-trodden path");
   set_short("%^RESET%^%^ORANGE%^A well-trodden path%^RESET%^");
   set_long("This %^ORANGE%^path %^RESET%^is narrow, but must see regular use, "
"as it is solid and well-trodden.  %^GREEN%^Trees %^RESET%^rise up to either "
"side, obscuring your view in most directions.  It leads northwards through the "
"surrounding foliage, and back towards southeast where the main %^BLUE%^road "
"%^RESET%^is visible.\n");
   set_smell("default","Fresh air drifts to your nose.");
   set_listen("default","The wind whispers softly through the trees.");
   set_items(([
     "path" : "%^ORANGE%^The path you are on is fairly narrow, but looks well-"
"trodden.  The trees and wilderness around seem to have had little luck "
"reclaiming it for their own.  A few small footprints are visible in the muck "
"alongside the main path.",
     "trees" : "%^GREEN%^Trees rise up alongside the path and around the keep, "
"not so dense as the forest further south, but enough to limit your vision"
".%^RESET%^",
     "road" : "%^BLUE%^The main road lies back amongst the trees further "
"southeast.%^RESET%^",
   ]));
   set_exits(([
     "west" : ROOMS"path3",
     "east" : ROOMS"path1",
   ]));
}
