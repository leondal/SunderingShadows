// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_08");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^YELLOW%^The Seneca Arena Gladiator's Lounge%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Located deep under the %^YELLOW%^Seneca Arena%^RESET%^%^GREEN%^ this room was once a warm up room, to judge by what is left.  A pile of woven %^ORANGE%^grass mats %^GREEN%^lays in a "
	"festering moldy pile in one corner, though it is likely they once covered the hard floor here and offered some %^CYAN%^spongy %^GREEN%^resistance to the pre-sparring that was done in this chamber.  Th"
	"e walls of this room are painted similarly to the main lounge with images of combatants %^RED%^fighting %^GREEN%^one another in the arena above.%^RESET%^"
	);

    set_smell("default","
Mold and blood tickle your nose.");
    set_listen("default","Things are quiet down here, there is no cheering crowd left. ");

    set_search("mats","%^GREEN%^You plunge your hand into the moldy mess of grass mats and pull away nothing but %^WHITE%^lice%^GREEN%^ and foul smelling %^CYAN%^mold%^GREEN%^.");
    
set_items(([ 
	({ "mats", "grass mats" }) : "%^GREEN%^Mold and rot cover these mats, though they were probably once very well made items, woven from the softest of grass and designed to provide cushions for the warriors as they practiced their moves in this large sparring room.%^RESET%^",
	({ "painting", "paintings", "combatants", "walls", "wall", "fresco", "frescos" }) : "%^BOLD%^%^WHITE%^You look over the painting and notice the skill and artistry of the piece.  The artist must have taken his inspiration from the bloody battles that happened above, for circling the entire room are images of warriors locked in combat, fighting with weapons, with hands, against one another and great beasts.  Just looking at them causes your blood to boil with the desire to be this heroic and powerful!%^RESET%^",
	"battle" : "%^RED%^There is no battle here, just the last remnants of a painting long faded.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/arena_06",
		"south" : "/d/av_rooms/lurue/arena_07",
	]));

}