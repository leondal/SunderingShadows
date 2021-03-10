// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_stair");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("stairway");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A R%^RED%^u%^BLACK%^ined S%^CYAN%^t%^BLACK%^air C%^RED%^l%^BLACK%^imbing into %^BLUE%^D%^BLACK%^ar%^BLUE%^k%^BLACK%^ness%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The stairs teeter under your weight, loose stones slipping. The passageway leading up seems claustrophobic, and the weight of the dank air feels oppressive. An arched ceiling extends "
	"above you, with nothing but rotted, empty torch holders lining the wall to guide the way. A layer of dust coats the cold stones.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^BLACK%^A m%^YELLOW%^u%^BLACK%^sky scent of %^GREEN%^mold%^BLACK%^ and ancient st%^WHITE%^o%^BLACK%^ne pervades the room.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^The only sound is that of your feet on the stairs.%^RESET%^");

    set_search("torch holders","%^BOLD%^%^BLACK%^Only decayed remains of torches are left in the torch holders.%^RESET%^");
    set_search("dust","%^BOLD%^%^BLACK%^Perhaps you are not the only one to have walked this stair... f%^WHITE%^o%^BLACK%^otp%^WHITE%^r%^BLACK%^ints.%^RESET%^");
    set_search("ceiling","%^BOLD%^%^BLACK%^The ceiling feels %^BLUE%^damp%^BLACK%^.%^RESET%^");
    set_search("holders","%^BOLD%^%^BLACK%^Only decayed remains of torches are left in the torch holders.%^RESET%^");
    set_search("air","%^BOLD%^%^BLACK%^Could that be a hint of %^CYAN%^fresh air%^BLACK%^ above you?%^RESET%^");
    set_search("stones","%^BOLD%^%^BLACK%^The stones feel cold as if you are deep underground.%^RESET%^");
    set_search("stairs","%^BOLD%^%^BLACK%^These ramshackle stairs, while loose, are not hiding anything.%^RESET%^");
    set_search("torches","%^BOLD%^%^BLACK%^Only decayed remains of torches are left in the torch holders.%^RESET%^");
    
set_items(([ 
	({ "stone", "stones" }) : "%^BOLD%^%^BLACK%^The stones feel cold as if you are deep underground.%^RESET%^",
	({ "holders", "torch holders", "torches" }) : "%^BOLD%^%^BLACK%^Long ago these may have held torches.%^RESET%^",
	"stairs" : "%^BOLD%^%^BLACK%^These ramshackle stairs are falling apart and are very treacherous.%^RESET%^",
	"ceiling" : "%^BOLD%^%^BLACK%^The ceiling looks to be made out of the same deteriorating stone, with patches of %^GREEN%^mold%^BLACK%^.%^RESET%^",
	"air" : "%^BOLD%^%^BLACK%^Could that be a hint of %^CYAN%^fresh air%^BLACK%^ above you?%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/crypt_clinic",
		"down" : "/d/av_rooms/myrkul/crypt_start",
	]));

}