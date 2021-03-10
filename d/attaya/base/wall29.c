
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Inside the walls of the Tower of the Black Dawn.");
set_long("
    You walk through the majestic hallway.  Glimmering polished metal columns hold up the ceiling here.  The walls have been ornately decorated and shine with all the effects of royalty.
");
    set_smell("default","There is a strange odor in the air, almost like some sort of spice.");
    set_listen("default","Something seems wrong here.");

    set_exits( ([
    "north" : "/d/attaya/base/wall13",
    "south" : "/d/attaya/base/wall30",
        ]) );
    set_items(([
    "windows" : "The entire inner wall is made of glass to display the beautiful crystalline tower outside.",
    "pool" : "The reflecting pool is crystal clear and reflects the crystalline tower."
    ]));

}
void init() {
  ::init();
do_random_encounters(({"/d/attaya/mon/archer","/d/attaya/mon/archer2","d/attaya/mon/solstice","/d/islands/common/mon/scorpion","/d/attaya/mon/nightstalker","/d/attaya/mon/poltergeist","/d/attaya/mon/uwarrior","/d/attaya/mon/toclahar","/d/islands/common/mon/necrophidius"}),30,6);
}
