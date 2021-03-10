//rooms by the House of Svaha
#include "/d/ptalkin/ptalkin.h"
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
set_short("%^MAGENTA%^F'relcks General Store");
set_long(
@DESC
%^MAGENTA%^This is not a large store, but is does seem to carry a good supply
of the basics.  The owner F'bollin stands behind the counter awaiting 
your purchase.
Large shelves cover most of the four walls, and are piled high with
merchandise.
DESC
);

    set_items(
	(["shop" : "A general store, actually.",
          "store" : "A place where you can buy and sell stuff.",
	  "counter" : "An worn and battered oak counter. About waist high.",
	  "shelves" : "The shelves are made of oak."]) );
set_exits( ([
"out" : "/d/ptalkin/mid/room77"
]) );
    set_property("no castle", 1);
set_property("no attack", 1);
    set_smell("default","The smell of oil lanterns, and rope fills your nostrils.");
    set_listen("default","The sounds of a craftmans tools, fill your ears.");
 }


void reset(){
::reset();
if(!present("f'bollin"))
new("/d/ptalkin/mon/f'bollin")->move(TO);

}
