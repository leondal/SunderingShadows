#include <std.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set_short("Rubble filled room");
    set_long(
      "This room is filled with rock and debris from a cave-in.  You can see where there were exits in many different places before, but now large, unmovable piles of rocks keep you from going anywhere but east."
    );

    set_listen("default", "The silence is deafening");
    set_smell("default", "The dust in the air is chokingly thick");

    set_items( ([
	"walls" : "These walls are rather plain and made of stone and in some places wood.",
	"floor" : "The floor is dirt and has several cart tracks through it, but you can't make out where they are going or where they've been.",

      ]) );
    set_exits( ([
	"east" : "/d/guilds/legion/hall/hub",
      ]) );
}
