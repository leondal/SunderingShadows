//New rooms added by Circe 12/29/03 to fix mapping problems
#include <std.h>
#include "../pass.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",0);
    set_short("On Dragon Pass Road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^
%^ORANGE%^To the north stand the proud Charu Mountains, looming high against the sky.  They cast their long shadows here over the foothills.  This road has been carved from the rock and looks as though it is well-travelled.  To the north, the land begins to rise steeply, while the passage southward is a little easier.
MELNMARN
    );

    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the valleys.");
    set_items(([
	"road":"A new road through the mountains.",
	"mountains":"They are impressive, even from here.",
      ]));

    set_exits(([
      "northwest" : PASSDIR+"passn6",
      "east" : PASSDIR+"passn8"
      ]));
}
