//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(BUILT_CAVE);
    set_travel(RUBBLE);
    set_name("Secret cave");
    set_short("Secret cave");
    set_long(
	"You have found a hidden cavern.  It is very dark in the room "+
	"except towards the north where two torches sit on the cave walls "+
	"illuminating a massive draw bridge.  Water streams in "+
	"from the walls sending an eerie sound throughout the room."
    );
    set_property("indoors",1);
    set_property("light",2);
//    set_property("no teleport",1);
//    set_property("no steal",1);
    set_listen("default","The sound of water dripping echoes through this cavern.");
    set_smell("default","The smell of old fungus is very strong.");
    set_exits( ([
	"out":"/d/shadow/room/mountain/cave01",
	"drawbridge":"/d/shadow/guilds/angels/tmp/entryway"
    ]) );
}
