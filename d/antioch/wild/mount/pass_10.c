//  Created by Ignatius, for ShadowGate
//  Coded 06 March, 1995
//  Along the Antioch Trail

#include <std.h>
#include "/d/antioch/areadefs.h"

inherit ROOM;

void create()
{
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_climate("arctic");
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no castle", 1);
    set_smell("default", "The scent of fear fills this mountain range.");
    set_listen("default", "You catch murmurs of chants and evil cackles, "
               " or maybe it's simply the wind cracking tree branches.");
    set_short("In the Charu Mountains");
    set_long("%^CYAN%^The peaks of the Charu Mountains jut toward the "
             "sky all around you, blocking out much of the sun's light and all of "
             "its warmth.  Cold air whistles down this path and whips against your "
             "frail mortal body, wanting to dash you against the side of the mountain.\n"
             "An ominous castle has been built on the mountainside here.");
    set("night long",
        "%^CYAN%^The peaks of the Charu Mountains are outlined by the moon.  A "
        "wolf howls in the distance.  Cold air whistles down this path and "
        "whips against your frail mortal body, wanting to dash you against "
        "the side of the mountain.\n"
        "An ominous castle has been built on the mountainside here.");
    set_exits(([
                   "south" : MOUNT + "pass_1",
                  // "northeast" : MOUNT + "trail1", moving muln to ice island -H 12/12/20
                   "castle" : MOUNT + "tcastle_1",
                   ]));
    set_items(([
                   "mountains" :
                   "The mountains extend as far as the eye can see.",
                   "castle" : "The castle might once have been of forboding aspect, but no longer. The mighty stones "
                   "that once formed its great towers now lie in charred fragments upon the mountainside, the victim of "
                   "some terrible violence."
               ]));
}
