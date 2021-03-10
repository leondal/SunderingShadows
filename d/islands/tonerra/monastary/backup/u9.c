
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
%^CYAN%^You have reached the top of the stairs entering the west-wing of the
upper floor. The hallway is lighted by the torches on the walls. 
Northwest leads you further down the hallway.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
]));

set_exits(([
"northwest" : RPATH "u10.c",
"stairs" : RPATH "m5.c",
]));

set_smell("default", "The air is confortable to you.");

}
