#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_room_type("guild");
    set_property("light", 2);
    set_property("indoors", 1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_short("Instrument shop");
    set_long(
      "Here lining the walls are the instruments of the bards.  Many are said to have special powers, or empower their owner to do great things.  A gentle old man sits behind the counter, carefully stringing a new guitar.  He looks up at you and smiles, before lowering his head and getting back to work."
    );
    set_smell("default", "You can smell the fire burning that keeps this room warm.");
    set_listen("default", "The instrument maker hums a merry tune as he works on his creations.");
    set_items( ([
	"fire" : "You can see the fire burning behind the old man.",
      ]) );
    set_exits( ([
	"west" : RPATH "cguilds/bard1.c",
      ]) );
}

void reset(){
    ::reset();
    if(!present("fflewdur"))
	new("/d/dagger/tonovi/town/cguilds/fflewdur.c")->move(TO);
}
