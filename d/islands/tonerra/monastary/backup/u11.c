
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
There is a door north and south of here. West continues down the hallway.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
"doors" : "The doors don't appear to be locked.",
]));

set_exits(([
"west" : RPATH "u12.c",
"east" : RPATH "u10.c",
"north" : RPATH "u14.c",
"south" : RPATH "u16.c",
]));

set_smell("default", "The air is clean and confortable.");

}
