//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_name("Carriage house");
    set_short("Carriage house");
    set_long(
	"You've walked into a large carriage house.  There are carriages "+
	"parked all over the room and stables which hold horses.  There is "+
	"a man behind a counter at the far side of the room.  There is a "+
	"sign on the counter as well.  The floor of the room is covered in "+
	"straw and manure."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_listen("default","The sound of carriages creaking and horses baying can be heard.");
    set_smell("default","The room smells of dung and straw.");
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for001i"
    ]) );
}
void init(){
    ::init();
    add_action("read","read");
    add_action("ride","ride");
}
void read(){
    write("%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^");
    write("The Carriage house rates");
    write("%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^");
    write("\n<ride> to The Gods Plains: 10 Gold\n");
    write("%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^");
    write("Enjoy your ride and come again.");
    write("%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^");
    return 1;
}
void ride(){
  if(!TP->query_funds("gold",10)){
	write("The man turns you back for lack of money.");
	return 1;
    }
  TP->use_funds("gold",10);
    write("The man shows you to a carriage.");
    tell_room(ETP,TPQCN+" pays the fee and steps onto the carriage.",TP);
    TP->move("/d/laerad/parnelli/forest/carriage_ride/carr4");
    TP->describe_current_room(1);
    return 1;
}
