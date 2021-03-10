// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_archeology_dig");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Greater Circle of Undeath%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is an %^YELLOW%^archeological dig%^BLACK%^, where someone has been trying to uncover the secrets of the ancients. Many bricks and rocks have been removed to clear a large hole in"
	" a wall, revealing what was once the center of a great temple. The scene is dominated by a gigantic ritualistic summoning circle. The circle looks like a giant inward %^CYAN%^s%^WHITE%^p%^RED%^i%^CYAN"
	"%^r%^WHITE%^a%^RED%^l%^BLACK%^, and it is covered in ancient symbols of power and might. Looking at it directly causes brief moments of blindness, and something tugs at your very soul to be in its pre"
	"sence.%^RESET%^"
	);

    set_smell("default","
Your sense of smell is completely stripped from you here.");
    set_listen("default","In this place, sound is a sensation that feels foreign to your very body.");

    set_search("circle","You can't bring yourself to approach too closely. This place is anathema to life itself. ");
    
set_items(([ 
	"symbols" : "These appear to be designed to be able to control massive numbers of undead creatures. It is an enormous conduit of negative energy.",
	"circle" : "The circle almost seems to swirl in your vision. It is a thing of terrible power.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/crypt_lab",
	]));

}