#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_short("%^BOLD%^%^BLACK%^Shadowlord forest");
    set_long(
@KAYLA
%^BOLD%^%^BLACK%^You passed across the bridge without falling.  As light turns into darkness, you look back to the west and the bridge fades away into the darkness.  All life as you know it fades away with the bridge.  To the northeast you see an image of the Fortress and feel pure evil.  Down below, the mist from the river rises to meet the gray skies.
KAYLA
    );
    set_smell("default","The mist carries the smell of death and decay.");
    set_listen("default","You hear the running water from the river below.");
    set_exits(([
       "west" : "/d/deku/open/bridge",
       "east" : "/d/deku/open/pass2",
       "down":"/d/deku/open/bank1"
] ));
    set_invis_exits(({"down"}));
    set_items(([
      "river" : "There seems to be a well-hidden path leading down to the river."
    ] ));
}
