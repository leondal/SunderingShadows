//Coded by Bane//
#include <std.h>
inherit CROOM;


void create(){
   set_monsters(({"/d/laerad/mon/troll2"}),({3}));
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("Systyquah entrance");
    set_short("Systyquah entrance");
    set_long(
	"%^BOLD%^Main street%^RESET%^
You have walked into the famous city of Trolls, Systyquah.  A long dirt "+
	"road continues to the south.  To the east and west are the "+
	"massive city walls, gates lead into either side.  To the north "+
	"are the Systyquah city gates."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the occasional scream of a troll war party.");
    set_exits( ([
	"east":"/d/laerad/parnelli/systyquah/sys117",
	"west":"/d/laerad/parnelli/systyquah/sys070",
	"north":"/d/laerad/parnelli/systyquah/sys001",
	"south":"/d/laerad/parnelli/systyquah/sys003"
    ]) );
    set_pre_exit_functions( ({"north"}),({"go_north"}) );
}

void reset(){
    ::reset();
}

int go_north(){
    tell_object(TP,"You walk through the city gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
