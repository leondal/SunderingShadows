// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_06");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^YELLOW%^The Seneca Arena Gladiator's Lounge%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Stairs lead up to the main level where the huge %^YELLOW%^Seneca Arena %^RESET%^%^GREEN%^awaits.  Once, gladiators lounged in this series of rooms, training and preparing themselves "
	"for the upcoming battles.  The remains of comfortable looking %^ORANGE%^chairs %^GREEN%^and %^BOLD%^%^WHITE%^couches %^RESET%^%^GREEN%^can be found here, though their dilapidated state leaves you caut"
	"ious to trust any weight to them.  The walls were once decorated with %^BOLD%^%^WHITE%^painted frescos %^RESET%^%^GREEN%^depicting the arena above filled with combatants locked in an endless %^RED%^ba"
	"ttle%^GREEN%^.  Just looking at what's left of the paintings makes your blood rush.%^RESET%^"
	);

    set_smell("default","
The faint trace of musty incense lingers still.");
    set_listen("default","Things are quiet down here, there is no cheering crowd left. ");

    set_search("couches","%^BOLD%^%^WHITE%^You reach into the couch and feel around, but can't even find a few loose coppers for your effort.  And you're pretty sure you don't want to know what those %^BLACK%^black lumps %^WHITE%^you did pull back are.%^RESET%^");
    
set_items(([ 
	({ "painting", "paintings", "combatants", "walls", "wall", "fresco", "frescos" }) : "%^BOLD%^%^WHITE%^You look over the painting and notice the skill and artistry of the piece.  The artist must have taken his inspiration from the bloody battles that happened above, for circling the entire room are images of warriors locked in combat, fighting with weapons, with hands, against one another and great beasts.  Just looking at them causes your blood to boil with the desire to be this heroic and powerful!%^RESET%^",
	({ "couches", "chairs", "couch", "chair" }) : "%^BOLD%^%^WHITE%^You look over what is left of the chairs and couches that once offered rest to the mighty warriors above.  There is little remaining after almost a hundred years.  Just a few threadbare covers and broken wood.  You couldn't put much weight on them at all.%^RESET%^",
	"stairs" : "%^BOLD%^%^BLACK%^Made of granite slabs that were once lined with a carpet of some type, the stairs have weathered poorly under the onslaught of rain and weather that spills through the grate at the top.  Thankfully, whoever created this place had the wisdom to place a few grates for drainage at the bottom of the stairs, preventing this room and the adjacent ones from becoming flooded.%^RESET%^",
	"battle" : "%^RED%^There is no battle here, just the last remnants of a painting long faded.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/arena_05",
		"northwest" : "/d/av_rooms/lurue/arena_08",
		"southwest" : "/d/av_rooms/lurue/arena_07",
	]));

}