#include <std.h>
inherit ROOM;
void create() {
::create();
set_property("light",1);
set_property("indoors",1);
set_short("%^BLUE%^Archer tower%^RESET%^");
set_long(
"%^BLUE%^You have entered into the bottom floor of one of the archer towers found near the entrance of the city. The room is quite bare except for a few scattered and broken bows and arrows.%^RESET%^"
);
set_listen("default",
"It is quite silent in here."
);
set_smell("default",
"There is a strange scent in the air."
);
set_items(([
"bows":"All broken and useless.",
"arrows":"All broken and worthless."
]));
set_exits(([
"up":"/d/dagger/drow/rooms/twr4.c",
"south":"/d/dagger/drow/rooms/city20.c"
]));
}
