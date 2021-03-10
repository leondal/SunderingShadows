
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^YELLOW%^Sparring/Training area.
");
set_long(
@SEETH
%^BOLD%^%^YELLOW%^You are in the training room of the monastary. The room has
very little in furniture. Just about the only piece of furniture is a
solitary chair, which is meant for the Master. The floor has been sweeped
showing its stone tile floors. You step back a bit and notice the tiles
are in a shape of a Yin and Yang symbol.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "Besides the Yin and Yang symbol, there is nothing special about the floors.",
"chair" : "The Masters' chair.",
]));

set_exits(([
"west" : RPATH "m10.c",
]));

set_smell("default", "The air is clean and comfortable.");

}
