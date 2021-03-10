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
   set_long("%^RESET%^A large %^CYAN%^keep %^RESET%^stands directly in front of "
"you.  It is in bad shape, judging by the %^BLUE%^holes %^RESET%^in the walls "
"and the %^GREEN%^vines %^RESET%^growing up over the building.  Some sections "
"seem to have collapsed entirely, further towards the back.  Before you appears "
"to be the main entrance, which stands wide open with the %^RED%^doors %^RESET%^"
"fallen and shattered to either side.  The trodden %^ORANGE%^path %^RESET%^"
"beneath your feet leads back southwards, lined on either side by tall "
"%^GREEN%^trees%^RESET%^.\n");
   set_smell("default","Fresh air drifts to your nose, tainted by a slight musty smell from the keep.");
   set_listen("default","You hear the sound of the wind whistling through the cracks in the walls.");
   set_items(([
     ({"keep","walls","holes","vines"}) : "%^CYAN%^The massive structure before "
"you might once have been a grand keep, but it has fallen into disrepair.  "
"Holes and cracks let the air whistle in through its walls, and tendrils of "
"vines and other plantlife creep their way over the solid stone, slowly "
"reclaiming the building back into the wilderness.%^RESET%^",
     "doors" : "%^RED%^The keep's doors lie shattered upon the ground, long "
"since fallen or pulled from their hinges.  They offer no obstruction to anyone "
"wishing to enter the keep.%^RESET%^",
     "path" : "%^ORANGE%^The path you are on is fairly narrow, but looks well-"
"trodden.  The trees and wilderness around seem to have had little luck "
"reclaiming it for their own.  A few small footprints are visible in the muck "
"alongside the main path.",
     "trees" : "%^GREEN%^Trees rise up alongside the path and around the keep, "
"not so dense as the forest further south, but enough to limit your vision"
".%^RESET%^",
   ]));
   set_exits(([
     "north" : ROOMS"keep2",
     "southeast" : ROOMS"path3",
   ]));
}

void reset() {
   ::reset();
   if(!present("robed woman")) new(MONS"jessa")->move(TO);
}
