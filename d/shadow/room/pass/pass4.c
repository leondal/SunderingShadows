//minor changes by Circe 12/29/03 to fix mapping problems by adding rooms.
#include <std.h>
#include "../pass.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On Dragon Pass Road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^
%^GREEN%^To the north of you lie the Charu Mountains. They are very intimidating, looming high in the sky. The road continues to wind away to the south, quickly being lost to sight as  it makes its way into the foothills of the Charu Mountains.  There is a huge rock directly north and a %^BLUE%^pond%^GREEN%^ to the east.
MELNMARN
    );

    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the valleys.");
    set_items(([
	"road":"A new road through the mountains.",
	"mountains":"They are impressive, even from here.",
      ]));

    set_exits(([
	"south" : PASSDIR+"passn1",
      "east":PASSDIR+"long_pond",
	"northeast" : PASSDIR+"pass5"
      ]));
}

void reset() {
   ::reset();
}
