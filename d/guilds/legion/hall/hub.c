#include <std.h>
#include "/d/guilds/legion/hall/guildinfo.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property("indoors", 1);
    set_property("light", 2);
    set_property("night light", 2);
    set_short("Collapsed meeting room.");
    set_long(
      "This used to be the center of the Legion's hall.  Now it is a collapsed mess.  All around old exits are collapsed in, or look like they will be soon."
    );
    set_listen("default" , "You hear the joyous cries of those in power over the lamentation of those who are not strong enough to hold the power high.");
    set_smell("default", "You smell the oils and brimstone of weapons prepared for battle to prove our might.");

    set_items( ([

      ]) );
    set_exits( ([
	"south" : "/d/guilds/legion/hall/main",
	"east" : "/d/guilds/legion/hall/lead1",
	"west" : "/d/guilds/legion/hall/store1",
	"north" : "/d/guilds/legion/hall/center1"

      ]) );
}
