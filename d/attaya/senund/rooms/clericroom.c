#include <std.h>
#include "../areadefs.h"
inherit ROOM;

void create()
{

        ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light",1);
    set_name("Altar");
    set_short("Altar");
    set_property("no teleport",1);
    set_long(
@BRUENOR
%^BOLD%^%^CYAN%^Altar%^RESET%^
%^BLUE%^This rather large room is dark and unlit. On the far side of the room
%^BLUE%^is a small %^BOLD%^%^YELLOW%^altar%^RESET%^%^BLUE%^. One side of the room is lines with tables full of 
%^BLUE%^various potions. The other side of the room is lines with tables full
%^BLUE%^of %^BOLD%^%^RED%^sacrificial knives%^RESET%^%^BLUE%^. In the center of the room is a %^MAGENTA%^circle%^BLUE%^ covered
%^BLUE%^in runes.
BRUENOR
    );
    set_items( ([ "knives": "The knives appear unfit for battle.",
       "potions": "The potions are full of various color liquids.",
       "ceiling": "The ceiling is rather low and is carved out of "+
       "the rock itself.",
       "altar": "The stone altar is very unimpressive but it an altar"+
       " nonetheless.",
       "circle": "The circle is full of runes of various colors and "+
       "sizes."   ]) );
    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_exits( 
    ([
        "east" : ROOMS+"rm16"
    ]) );

}

void reset()
{
  ::reset(); 
  if(!present("Shadowy Priest")) {
  new(MON+"priest.c")->move(TO);
  }
}
 

