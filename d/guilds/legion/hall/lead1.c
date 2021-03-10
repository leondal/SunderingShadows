#include <std.h>

inherit ROOM;
object ob;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_short("Hall of ancient tapestries");
    set_long(
   "This was at one time where the leaders of the Legion would meet.  Now it is in complete disrepair.  Everything is destroyed, except for 4 tattered tapestries left hanging on the walls."

    );
   set_smell("default", "You can smell ancient woodsmoke coming from somewhere.");
    set_listen("default", "The silence is deafening");

    set_items( ([
      ({"tapestries", "tapestry"}) : "These ancient tattered tapestries look to have once held magical power.",
    ]) );
    set_exits( ([
      "west" : "/d/guilds/legion/hall/hub",
    ]) );
}
