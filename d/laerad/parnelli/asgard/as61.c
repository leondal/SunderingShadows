//Coded by Bane//
#include <std.h>

//inherit CROOM;
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*    set_monsters(({"/d/laerad/mon/commando"}),({random(4)}));
   set_repop(50);
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_name("Asgard barracks");
    set_short("Asgard barracks");
    set_long(
	"%^BOLD%^Asgard's barracks%^RESET%^
You are standing in the guards barracks.  A few bunks line the southern "+
	"wall, while two tables and numerous chairs take up the rest of the "+
	"room.  The cities elite commandos live here while on assignment."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no bump",1);
    set_smell("default","The barracks smell of old food and sweat.");
    set_listen("default","You hear the low whispers of a few people.");
*/
   set_long(::query_long()+"\nThe wooden rubble in the room and the stone "
      "walls suggest that this was once one of the guard barracks, though "
      "it is useless now.\n");
    set_exits( ([
	"north":"/d/laerad/parnelli/asgard/as58"
    ]) );
}
