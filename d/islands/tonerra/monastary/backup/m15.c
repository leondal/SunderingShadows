
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^BLUE%^Dining hall.
");
set_long(
@SEETH
%^BOLD%^%^BLUE%^This is the dining hall of the monastary. The room is very simple
with one long table with chairs. The table is made of stone and spans
across most of the room. The chairs are made from bamboo and are well-built.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
"table" : "A long stone table.",
"chairs" : "Bamboo chairs along the table.",
]));

set_exits(([
"east" : RPATH "m14.c",
]));

set_smell("default", "The air is filled with the smell of chinese food.");

}
