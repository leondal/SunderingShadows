//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_name("An old abandoned battle room");
    set_short("An old abandoned battle room");
    set_long(
	"You have walked up into and old abandoned battle room.  A huge broken "+
	"table sits in the middle of this hall.  Countless chairs lie around "+
	"the room in heaps.  Old parchments and scrolls litter the table, most "+
	"have disintegrated into dust with time.  The walls are covered in "+
	"rusted armors and weapons from ancient warriors."
    );
/*    set_property("no teleport",1);
    set_property("no steal",1);
*/
    set_listen("default","The creaking of wood shatters a moment of silence.");
    set_smell("default","The room smells of steel and iron.");
    set_exits( ([
	"down":"/d/shadow/guilds/angels/tmp/hall1"
    ]) );
}
/*
void init(){
    ::init();
    if((string)TP->query_guild() == "Fallen Angel"){
    add_action("read","read");
    set_name("Fallen Angels battle room");
    set_short("Fallen Angels battle room");
    set_long(
        "You have walked into the Fallen Angels battle room.  A huge "+
        "round oaken table sits in the middle of this hall.  Countless "+
        "chairs lie scattered around the room.  The table is "+
        "littered with maps and battle tactics.  The walls are decorated "+
        "with armors and weapons from hundreds of warriors.  This is "+
        "obviously where the guild plans its battle plans "+
	"in times of war.  A list of the current guild members is tacked "+
	"to one of the walls."
    );
    } else {
    set_name("An old abandoned battle room");
    set_short("An old abandoned battle room");
    set_long(
	"You have walked up into and old abandoned battle room.  A huge broken "+
	"table sits in the middle of this hall.  Countless chairs lie around "+
	"the room in heaps.  Old parchments and scrolls litter the table, most "+
	"have disintegrated into dust with time.  The walls are covered in "+
	"rusted armors and weapons from ancient warriors."
    );
    }
}
int read(string str){
    if(!str) return notify_fail("Read what?\n");
    if("list" != str) return 0;
    TP->more("/d/shadow/guilds/angels/MEMBERS");
    return 1;
}
*/