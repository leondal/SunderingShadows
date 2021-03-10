// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_entrance");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^Dark%^BOLD%^%^BLACK%^ Entrance Hall%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in a grand entrance hall with vaulting ceilings deep underground. To the south, is a gate to the rest of the Drow city. To the east and west appear to be branching hallways "
	"where lesser Drow reside. And to the north is the main residence of the great House. The seal of the House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r"
	"%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^BLACK%^ is on the floor -- the spider, dripping yellow venom. The hallway sees much use and yet is kept impeccably clean. %^RESET%^"
	);

    set_smell("default","
You smell the dry air of the caves.");
    set_listen("default","You hear the sound of Drow voices and walking nearby.");

    
set_items(([ 
	"floor" : "The floor is made out of marble.",
	"ceiling" : "The ceiling is large enough to allow a titan to stand up straight without hitting its head.",
	"seal" : "The seal is made out of gold dust paint.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/x_nhall",
		"west" : "/d/av_rooms/myrkul/x_whall",
		"south" : "/d/av_rooms/myrkul/x_gate",
		"east" : "/d/av_rooms/myrkul/x_ehall",
	]));

    set_door("gate","/d/av_rooms/myrkul/x_gate","south","spider key","lock");
    add_lock("gate","spider key","lock","This is a strange looking lock that has a key hole resembling a spider.");
    set_locked("gate",1,"lock");
    lock_difficulty("gate",-50,"lock");
    set_open("gate",0);
    set_string("gate","knock","pounds on the");
    set_string("gate","open","The gate opens slowly.");
    set_string("gate","close","The gate swings shut.");
    set_door_description("gate","This is a wrought iron gate with ornamental spikes and bearing a symbol of a spider with dripping yellow venom.");
}