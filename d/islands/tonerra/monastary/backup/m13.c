
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^YELLOW%^Monastary kitchen.
");
set_long(
@SEETH
%^BOLD%^%^YELLOW%^You are in the kitchen of the monastary. Before you is a stove
of some sort and a table along the wall. There are many kitchen utensils
on the table. Many baskets and barrels fill the corner of the room.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
"stove" : "The stove is made of stone with a hole at the top center, which is filled with hay and a wok is set atop it.",
"table" : "On the table are a few cut vegetables and some kitchen utensils.",
"utensils" : "There are a few knives.",
"barrels" : "The barrels are filled with different beverages.",
"baskets" : "The baskets are filled with assorted vegetables and meats.",
]));

set_exits(([
"north" : RPATH "m12.c",
]));

set_smell("default", "The smell of Chinese food is amazing.");

}
