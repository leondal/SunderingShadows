
#include "/d/ptalkin/ptalkin.h"
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
set_short("%^ORANGE%^D'regel's General Store");
set_long("%^ORANGE%^Inside this store you see many shelves filled with wares.  Sacks, chests, lanterns and other items line the shelves.  D'regel is seen puttering around tidying shelves and checking his inventory.  Should you require assistance, type <list> or <buy> or <sell>.");

    set_items(
	(["shop" : "A general store, actually.",
          "store" : "A place where you can buy and sell stuff.",
	  "counter" : "An worn and battered oak counter. About waist high.",
	  "shelves" : "The shelves are made of oak."]) );
    set_exits( 
(["out" : PROOM+"room54.c"]));
    set_property("no castle", 1);
set_property("no attack", 1);
    set_smell("default","The smell of oil lanterns, and rope fills your nostrils.");
    set_listen("default","The sounds of a craftmans tools, fill your ears.");
 }


void reset(){
::reset();
if(!present("d'regel"))
new("/d/ptalkin/mon/d'regel")->move(TO);

}
