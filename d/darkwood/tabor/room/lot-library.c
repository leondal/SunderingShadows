//adapted from Shadow's library for use in Tabor.  Circe 6/2/04
#include <std.h>
#include "../include/tabor.h"
inherit LIBRARY;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_library_name("Tabor_Public_Library");
   set_name("Illustrious Tabor City Library");
   set_short("Illustrious Tabor City Library");
   set_long(
@DESC
%^BOLD%^This fantastic structure is made entirely of silver-veined white marble that is cool and smooth to the touch. Tall columns reach high overhead to support the vaulted ceiling. The floor has several %^RESET%^%^GREEN%^deep green runners %^BOLD%^%^WHITE%^that make their way between the numerous %^RESET%^%^ORANGE%^study desks %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^tables %^BOLD%^%^WHITE%^arranged neatly around this room. This appears to be the main chamber of the library, though pointed archways lead deeper into other sections of the library. For now, though, it seems everything you need is here on the %^RESET%^%^ORANGE%^shelves %^BOLD%^%^WHITE%^ that line the walls.
Here, you may ask the librarian to help you <research> someone.
DESC
   );
   set_light(2);
   set_indoors(1);
   set_smell("default","You smell the aged scent of old tomes and scrolls.");
   set_listen("default","A respectful silence hangs in the air, broken "+
      "only by the sound of turning pages.");
   set_items(([
      "shelves":"They are filled with scrolls used to research people.",
      "scrolls":"These contain the background information on the characters of the realm."
   ]));
   set_exits(([
      "west" : ROOMDIR+"math4",
   ]));
}

void reset(){
  if(!present("librarian")) 
      find_object_or_load("/d/darkwood/tabor/mon/librarian")->move(TO);
}

