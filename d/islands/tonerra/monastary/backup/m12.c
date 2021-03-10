
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
As you peer south you can see a kitchen. West continues down the hallway.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
]));

set_exits(([
"southeast" : RPATH "m7.c",
"south" : RPATH "m13.c",
"west" : RPATH "m14.c",
]));

set_smell("default", "The smell of food fills the hallways.");

}
