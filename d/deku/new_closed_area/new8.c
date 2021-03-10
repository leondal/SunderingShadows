#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Kobold Forest");
    set_long(
@KAYLA
You are among the trees and underbush of the Kobold forest.  The
forest seems to enlessly extend to the west and east.  The creatures
who dwell within the forest must not be accustomed to strangers.
All around you, fog blankets the paths eastward and westward like
a flowing dark gray cloak.  The light endlessly tries to penetrate
the dark leaves of the forest trees.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/new/new10",
       "east" : "/d/deku/new/new7"
    ] ));
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_items(([
    ] ));
}
