#include <std.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_short("Crumbling Entranceway");
    set_long(
      "%^BOLD%^You are in what used to be the entrance hall to the gathering place of the most powerful people in the land.  The rubble that surrounds you was at one time great marble pillars, pillars that stood for strength but now they have crumbled into dust.  Parts of the ceiling around you have started to crumble in.  On the ground, what used to be a mural portraying power of its members lies in ruin, barely recognizable."
    );
    set_smell("default", "Wafting on a light breeze across the room you can smell the scent of many roses.");
   set_listen("default", "You can hear several sparrows flying on a breeze somewhere outside the pillars.");

    set_exits( ([
	"out" : "/d/koenig/village/genstore",
	"north" : "/d/guilds/legion/hall/hub"

      ]) );

    set_items( ([
      "rubble" : "The rubble that remains is what used to be giant marble pillars that held up the ceiling.",
      ]) );
    set_property("light", 2);
    set_property("indoors", 1);
}

