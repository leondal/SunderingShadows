//updated by Circe 6/2/04 with color, etc.
//trainer.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create(){
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(CITY);
    set_name("The Training Yard in the Fields, Tabor");
    set_short("The Training Yard in the Fields, Tabor");
    set_long(
@TABOR
%^BOLD%^The Training Yard in the Fields, Tabor%^RESET%^
This is a partially enclosed building in the area of Tabor known as the 
%^GREEN%^Fields of Tempus%^RESET%^.  You can tell from the %^BOLD%^padded walls %^RESET%^which are lined 
with %^RED%^weapon racks%^RESET%^, that this area is for melee sparring.  Here the 
Master-at-Arms of the Tabor Royal Guard trains soldiers and all who 
request it.  Since Tabor's citizens are all required to do military 
service in the Militia, the Master-at-Arms grants free training. He 
knows that this improves the abilities of the Militia in %^RED%^time of war%^RESET%^, 
and so it is well worth his time, even if most of the students are 
somewhat inept.
TABOR
    );
    set_items(([
       ({"weapons","racks","weapon racks"}) : "A couple of the padded "+
          "walls have wooden weapon racks in front of them.  These racks "+
          "hold wooden swords alongside very real swords, axes, hammers, "+
          "spears, and the like.",
       ({"walls","padded walls"}) : "The walls have been padded with "+
          "layers of thick muslin that seems to have been stuffed "+
          "with hay.  Not the softest of padding, but it's got to "+
          "be better than being thrown into a hard stone wall.",
       "floor" : "The floor here is made of wood and padded only "+
          "with rushes.",
       "fields" : "The fields outside are covered in short grass.  "+
          "There are archery targets set up out there, and you can "+
          "often see people out there practicing.  Most seem to "+
          "be pretty bad shots."
    ]));
    set_light(2);
    set_indoors(1);
    set_listen("default","You occasionally hear the ring of metal against metal.");
    set_smell("default","This room smells perpetually of the sweat of people training.");
    set_exits(([
      "south" : ROOMDIR+"gwy6",
      "east" : ROOMDIR+"archery",
    ]));
}


void reset() {
    ::reset();
    if(!present("connor")){
        new("/d/darkwood/tabor/mon/connor")->move(TO);
    }
}

