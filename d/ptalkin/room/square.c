#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create(){
object ob;
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short("A square");
set_long(
@PATOR
%^ORANGE%^
The square is made out of cobble-stone and bordered by flower boxes on 
all sides and people walk by, and stop to talk to other passers-by. 
To the south you see several shops and to the north you see the church 
with it's mighty bell tower. 
PATOR
);
set_smell("default", "%^BLUE%^You can smell floral scent mingling with other scents delightfully.");
set_listen("default", "%^CYAN%^You can hear the normal sounds of a small town, laughter, cursing and talk");
set_exits (([
	"north" : PROOM+"church.c",
	"south" : PROOM+"room64.c"
]));
set_items(([
"square" : "Around 30 feet across, cobblestones set in mortar and bordered with lots of lovely flowers set in flower boxes",
"buildings" : "Buildings begin to take shape in front of you, colourful with flowers and bold signs",
"people" : "Peoples of every race and description stroll across the square", 
"signs" : "The signs are wood slabs with names either carved or burned into them",
"church" : "It is a nice and cosey church with it's belltower next to it",
"town" : "The town appears to be well kept, tidy and well known, perhaps you should investigate, you never know what surprises may await you"
]));
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "bulletin board", "Ptalkin board" }) );
  ob->set_board_id("ptalkin_board");
  ob->set("short", "The Ptalkin Board");
   ob->set("long",
@PATOR
A freshly painted oak board for all visitors to the Ptalkin area.
Please post your remarks onto this board.
PATOR
);
  ob->set_max_posts(50);
  ob->set_location(PROOM+"square.c");
}
