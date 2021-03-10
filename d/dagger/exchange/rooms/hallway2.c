// Foyer  - Merchant Exchange - LoKi - 19-02-2008 ((trading.c)

#include <std.h>
#include "../exchange.h"

inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
set_name("A Hallway");
    set_property("light",2);
    set_short("%^RESET%^%^ORANGE%^A Hallway%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The opulence of the foyer continues along "+
"this hallway. The glow from the Foyer still reaches here, illuminating the "+
"%^RESET%^%^RED%^plush red carpet %^RESET%^%^ORANGE%^and wood panelled walls."+
" Several paintings have with obvious reverence. To the east are stairs down.\n%^RESET%^");
    set_exits(([
        "west" : ROOMS"hallway",
      "up" : "/d/dagger/exchange/horse/rooms/hall",
    ]));
    set_items(([
        ({"paintings"}) : "%^RESET%^%^ORANGE%^Paintings depicting various victories"+
" of the Dragoons adorn the walls.%^RESET%^",
({"floor","carpet"}) : "%^RESET%^%^BOLD%^%^RED%^The floor is covered in a deep "+
"rich red carpet. Even though people walk back and forth constantly the carpet "+
"is perfectly clean and without any tears%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^You smell polished wood.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^You hear the conversations of merchants.%^RESET%^");

}
