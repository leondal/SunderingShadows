// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("acidlake");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("deep water");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^YELLOW%^Deep in a Lake of Acid%^RESET%^");

    set_long("%^RESET%^You are swimming in a %^YELLOW%^lake of acid%^RESET%^. You can feel the liquid sucking the life out of you. It is burning your flesh, and unmaking your gear. High above, the flickering light "
	"of %^BOLD%^%^MAGENTA%^Faezress crystals%^RESET%^ shines %^BOLD%^%^CYAN%^spears of l%^WHITE%^i%^CYAN%^g%^WHITE%^h%^CYAN%^t%^RESET%^ through the surface of the lake into the %^BOLD%^%^BLACK%^murky depth"
	"s%^RESET%^ below. The bottom of the lake is covered in %^RESET%^%^ORANGE%^smooth sand%^RESET%^ of all the debris that is eaten by the %^BOLD%^%^RED%^ever-hungry%^YELLOW%^ acidic%^RED%^ waters%^RESET%^"
	". "
	);

    set_smell("default","
You can't smell anything -- the nerve endings in your nose are getting burned off!");
    set_listen("default","It is utterly silent but for your struggles.");

    set_search("sand","There is a cavity in the sandy bottom of the lake that is revealed as you claw it away.");
    
set_items(([ 
	"cavity" : "Perhaps you could swim into the <cavity> now that it has been cleared of sand.",
	"sand" : "The sand looks completely flat except for some places near the bottom that look slightly indented. ",
	]));

    set_exits(([ 
		"cavity" : "/d/av_rooms/myrkul/acidlakecavity",
		"up" : "/d/av_rooms/myrkul/acidlakesurface",
	]));



    set_invis_exits(({ "cavity" }));

}