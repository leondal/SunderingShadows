#include <std.h>

inherit ROOM;

void create(){
   ::create();

   set_name("Help area");

   set_property("indoors",1);
   set_property("light",2);

   set_short("Library of the Consortium");
   set_long(
@OLI
   %^ORANGE%^Library of the Consortium%^RESET%^
In this room, many shelves line the walls and are set up in rows along the
center of the room. There are no books on the shelves.  It
looks as if only the books and scrolls themselves have been taken as the
bookends are still in their places.  A fine layer of dust has settled on
everything, obviously this room has not been used in some time. 
OLI
   );

   set_smell("default","This room is quite musty");
   set_listen("default","The rustling of pages break the silence.");
   set_items(([
   ({"bookends","bookend"}) : "These slender stone rings once held a vast amount of knowledge between them. Now they lay bare and without purpose.",
   ]));

   set_exits(([
              "southwest":"/d/guilds/consortium/hall/library",
      ]));
}