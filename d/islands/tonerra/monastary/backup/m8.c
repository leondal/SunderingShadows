
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^WHITE%^An old oriental monastary.
");
set_long(
@SEETH
%^BOLD%^%^CYAN%^You are traveling down one of the hallways of the monastary.
The hallway is lighted by torches along the stone walls.
As you peer north, you see a garden outside.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
]));

set_exits(([
"north" : RPATH "g2.c",
"east" : RPATH "m6.c",
"west" : RPATH "m7.c",
]));

set_smell("default", "The air is clean and comfortable.");

}
