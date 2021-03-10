#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include <daemons.h>
inherit HEALER;

string *registered;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^RESET%^%^ORANGE%^A simply-furnished side room%^RESET%^"); 
    set_long("%^RESET%^%^ORANGE%^This room is somewhat larger than the reception room, however it is no more "
"furnished save for a single cot against one wall of the room.  The other side is covered with wooden shelves "
"sporting dozens of different herbs, balms, and salves, all with medicinal purposes.  There is a list on the "
"wall of the services the healer offers.%^RESET%^\n");
    set_smell("default", "You smell the strong scent of the ointments.");
    set_listen("default", "You hear the healer mixing some potions and pulping some herbs.");
    set_exits( ([
        "out" : "/d/dagger/Torm/city/thieves/vethor_guild",
	] ));
	set_name("Herman");
}

void reset(){
    ::reset();
    if(!present("herman"))
        new("/d/dagger/Torm/mon/herman")->move(TO);
}

void remove_member(string str){
	registered = SAVE_D->query_array("vethor_members");
	if(member_array(str, registered) != -1){
		SAVE_D->remove_name_from_array("vethor_members", str);
	}
}
