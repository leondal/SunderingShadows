
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BLUE%^Monastary room.
");
set_long(
@SEETH
%^BOLD%^%^BLUE%^This room appears to be a bedroom. Thee isn't anything out of the
ordinary. There is a bed to the far side of the room. A desk is placed 
along a wall. There are shelves beside the desk. The shelves are filled
with many books and boxes.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
"bed" : "The bed is flat with a blanket and pillow.",
"desk" : "The desk is neat and orderly. Books lay upon the desk along with paper and ink.",
"shelves" : "The shelves have many books and boxes on it.",
"books" : "You do not understand any of the books because they are written in chinese.",
"boxes" : "There is nothing of interest in the boxes.",
]));

set_exits(([
"north" : RPATH "u12.c",
]));

set_smell("default", "The air is confortable to you.");

}
