
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^CYAN%^Upper floor of the monastary.
");
set_long(
@SEETH
%^CYAN%^You are traveling through the hallways of the upper floor of the
monastary. The torches along the walls light the room as you walk.
The hallway ends here with two doorways north and south.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
"doors" : "The doors don't appear to be locked.",
]));

set_exits(([
"east" : RPATH "u11.c",
"north" : RPATH "u13.c",
"south" : RPATH "u15.c",
]));

set_smell("default", "The air is clean and confortable.");

}
