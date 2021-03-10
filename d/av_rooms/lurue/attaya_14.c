// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_14");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Center of the City of Seneca%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Designed as part of a city park, the soft %^BOLD%^grass %^RESET%^%^GREEN%^that circles the central courtyard looks inviting to laze upon.  Small trees with %^RED%^red leaves %^GREEN%"
	"^are spread out around the grounds, offering %^BOLD%^%^BLACK%^shade %^RESET%^%^GREEN%^and %^WHITE%^comfort%^GREEN%^.  At the center, a paved courtyard can be found.  The stones worn with age and weath"
	"er.  At their center in a garden of %^ORANGE%^golden sand %^GREEN%^a %^BOLD%^%^WHITE%^statue %^RESET%^%^GREEN%^kneels.%^RESET%^"
	);

    set_smell("default","
The clean scent of the ocean rises on the breeze.");
    set_listen("default","You can faintly hear the crashing of waves on the shore.");

    
set_items(([ 
	({ "sand", "golden sand" }) : "%^YELLOW%^The golden sand is caked and solid, no longer the soft powder it likely was when the statue was placed here.  Still the fine texture and golden color speak of a place far from the Seneca you know.%^RESET%^",
	({ "trees", "leaves", "tree", "leaf", "red leaves" }) : "%^RESET%^%^RED%^Small and delicate looking, these red leafed trees dot the landscape offering a bit of shade to the grassy garden.%^RESET%^",
	({ "grass", "soft grass" }) : "%^RESET%^%^GREEN%^The grass looks soft enough to rest upon, though the blade have long since overgrown a traditional garden setting.%^RESET%^",
	"statue" : "%^BOLD%^%^WHITE%^Depicted kneeling, this statue has a quiet beauty.  It is carved from flawless white marble that seems to glow no matter what light hits it.  The statue is in the shape of a man in a simple, flowing robe belted at the waist.  He is kneeling and sitting back on his heels, the robe pushed up to reveal his bare feet beneath.  His hands are crossed gently on his knees, and his eyes are closed with a serene expression on his face.  His hair is pulled back smoothly though whatever held it has been broken away, leaving a gaping hole at the back of the statue's neck.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/attaya_10",
	]));

}