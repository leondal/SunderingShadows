// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_archeology_east");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Un%^BLUE%^t%^BLACK%^ouched R%^RED%^e%^BLACK%^mains of an %^YELLOW%^A%^BLACK%^ncient %^CYAN%^T%^BLACK%^emple%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^After stumbling through the blackness, the remains of an ancient temple comes into view. Before you is a %^CYAN%^pool%^BLACK%^ long since run %^RED%^dry%^BLACK%^. Images of ghostly sh"
	"apes line the walls, some in %^RED%^pain%^BLACK%^, others %^GREEN%^peaceful%^BLACK%^, and all shepherded by a %^WHITE%^skeletal figure%^BLACK%^ holding a %^RESET%^%^MAGENTA%^scythe%^BOLD%^%^BLACK%^. A"
	"ncient bones lie on the ground long undisturbed.%^RESET%^"
	);

    set_smell("default","
You smell nothing but half-remembered long forgotten memories.");
    set_listen("default","It is quiet.");

    set_search("bones","You search through the bones, and find clerical symbols -- many with grinning skulls, others with a dark sun.");
    
set_items(([ 
	"pool" : "The pool has a red tinge around the rim from long ago... perhaps it wasn't filled with water, but with blood.",
	"bones" : "They look chipped and bludgeoned -- whoever died here, died a violent death.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/crypt_vault_east",
	]));

}