// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("aryn_lab");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Laboratory Wing%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This is a wing of the %^WHITE%^laboratory%^GREEN%^ that seems often quite unused. The room itself is a wide open bay with many tall tables holding %^BLACK%^vivisection kits%^GREEN%^ w"
	"ith various %^YELLOW%^s%^RED%^u%^YELLOW%^rgi%^RED%^c%^YELLOW%^al%^GREEN%^ tools. Many bandages and tourniquets seem to be available. If it wasn't for the sign that said bolding %^BOLD%^%^CYAN%^<%^MAGE"
	"NTA%^Caution%^YELLOW%^:%^RED%^ L%^RESET%^%^RED%^i%^BOLD%^%^RED%^v%^RESET%^%^RED%^e%^BOLD%^%^RED%^ E%^RESET%^%^RED%^x%^BOLD%^%^RED%^p%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^m%^RESET%^%^RED%^"
	"e%^BOLD%^n%^RESET%^%^RED%^t%^BOLD%^s%^CYAN%^>%^GREEN%^ you would get the idea this was more of a hospital than a laboratory. A hallway to the north leads to an observation chamber.%^RESET%^"
	);

    set_smell("default","
It smells of acid and vaguely of sulfur.");
    set_listen("default","A leaky faucet drips water into a basin somewhere. It is water... you hope.");

    set_search("floor","Are those bloodstains? Old but possibly so. What a grim place!");
    set_search("kits","The kits have many scissors, scalpels, bone grinders, and other surgical implements.");
    set_search("tables","There isn't a whole lot useful to you unless you were working here, in which case many surgical implements are free to use.");
    
set_items(([ 
	"floor" : "The floor is in need of wax and there are some spots here and there.",
	({ "kits", "tools", "tables", "bandages", "tourniquets" }) : "The tools here are surgical in nature but doubtless have been used for dissection rather than any kind of healing. There are scissors, scalpels, bone grinders and all other kinds of surgical tools available. Bandages and tourniquets seem plentiful as bleeding must be a common problem with all these cutting implements handy. ",
	"ceiling" : "The ceiling looks pretty ordinary. In fact it is ordinary.",
	"sign" : "The sign says <Caution: Live Experiments> and that seems quite ominous.",
	"walls" : "The walls are the same as the rest of the larger lab.",
	]));

    set_exits(([ 
		"south" : "/d/attaya/newseneca/rooms/psi_workroom",
		"north" : "/d/av_rooms/myrkul/aryn_obs",
	]));

}