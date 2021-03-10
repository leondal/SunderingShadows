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
In this room, many books line the shelves in yellow, hard-bound covers. 
Some are a bit dusty as they have not been read in quite a while.  You
notice numerous books that catch your attention.
OLI
   );

   set_smell("default","This room is quite musty");
   set_listen("default","The rustling of pages break the silence.");
   set_items(([
              "books":"These books are each hand written by members of the consortium. They reflect the collective knowledge of the consortium and related organizations.",
              ]));

   set_exits(([
              "west":"/d/guilds/consortium/hall/library",
      ]));
}
