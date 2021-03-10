#include <std.h>
#include "short.h"

inherit CITYOUT;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 1);
    set_short("On the Boardwalk");
    set_long(
      "You are on the boardwalk bridge that leads to the island section of Seneca from the portion on the land.  To the south you can see the small city on the island itself, with the fabled Cathedral standing proudly on the southern tip of the island, a beacon of good in this sea of evil."
    );
    set_smell("default", "The smell of the salt water rises up from below you, filling your nose.");
    set_listen("default", "You can hear several seagulls somwhere nearby.");
    set_items( ([
	"cathedral" : "This great cathedral was built before the time of Intruder, and is now the only remaining enclave of opposotion to him on this island",
	"boardwalk" : "The boardwalk leads between the mainland and the city proper.  There are some guard posts along it.",
	({"guards", "guard posts", "guard post"}) : "meant to give the city a chance to close down to defend itself, these guards will fight bravely to the death.",
      ]) );
    set_exits( ([
	"north" : "/d/attaya/seneca/boardwalk1",
	"south" : "/d/attaya/seneca/boardwalk3",
      ]) );
}
