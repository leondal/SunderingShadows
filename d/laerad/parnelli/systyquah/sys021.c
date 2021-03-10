//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("City of Systyquah");
    set_short("Systyquah's Gate");
    set_long(
        "You stand before Systyquahs massive city gates.  The walls surrounding "+
        "the city look to be at least 20 feet tall and made from what looks like "+
        "huge wooden stakes.  You can hear the shouting of Troll war generals "+
        "from deep inside the city.  The gates to the city are cracked open, perhaps "+
        "bidding you welcome, or perhaps trouble."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A clean, fresh wind blows about.");
    set_listen("default","The shouting of war parties comes from within the gates.");
    set_exits( ([
	"north":"/d/laerad/parnelli/systyquah/sys020",
	"south":"/d/laerad/swamp/swamp19"
    ]) );
    set_pre_exit_functions( ({"north"}),({"go_north"}) );
}
int go_north(){
    tell_object(TP,"You walk through the city gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
