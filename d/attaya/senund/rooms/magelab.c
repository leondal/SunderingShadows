#include <std.h>
#include "../areadefs.h"
inherit VAULT;

void create()
{

        ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("no teleport",1);
    set_property("indoors", 1);
    set_property("light",2);
    set_name("Mage Lab");
    set_short("Mage Lab");
    set_long(
@BRUENOR
%^BOLD%^%^CYAN%^Mage Lab%^RESET%^
This room is unlike the others down here. The room is crowded with
%^ORANGE%^tables%^RESET%^ covered in books, beakers, and scrolls. The room does not 
appear to have any torches but is still lit rather well. A bed lies
on the far side of the room, and %^BOLD%^bookshelves%^RESET%^ line the walls.  
BRUENOR
    );
    set_items( ([ "walls": "The walls are lined with bookshelves.",
       "table": "The table is covered in various old tools and books.",
       "ceiling": "The ceiling is rather low and is carved out of "+
       "the rock itself.",
       "bookshelves": "The books all seem to pertain to alchemy and "+
       "realm history" ]) );
    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_exits(
    ([
        "north" : ROOMS+"rm24"


    ]) );

    set_door("iron door",ROOMS+"rm24","north","old key");
    set_door_description("iron door","This door is made of polished "+
                         "stainless steel, it looks nearly impenetrable.");
    set_string("iron door","open","The heavy door swings open silently");
}
void reset()
{
  ::reset();
  if(!present("elseroad")) {
  new(MON+"elseroad.c")->move(TO);
  }
}
