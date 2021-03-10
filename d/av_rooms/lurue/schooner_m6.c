// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("schooner_m6");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^RESET%^%^CYAN%^The Maindeck of a Schooner%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The wide %^GREEN%^emerald %^ORANGE%^canvas of the Mainsail stretches above your head, extending the full length of the Mainmast down to the long boom which reaches over the Quarterd"
	"eck. The rich %^GREEN%^emerald %^ORANGE%^tones snap and tug upon their %^BOLD%^%^WHITE%^snow-white %^RESET%^%^ORANGE%^rigging as they catch the wind and guide the vessel ahead.  Below this mighty sail"
	", the Quarterdeck stretches and narrows toward the stern to give the ship a smooth cutting form.  Between the Maindeck and Quarterdeck a cabin has been created, lined with beautifully carved wooden wa"
	"lls and %^GREEN%^st%^BLUE%^ai%^RED%^ne%^GREEN%^d g%^BLUE%^l%^RED%^a%^GREEN%^ss %^ORANGE%^insets.  A door with a %^YELLOW%^brass %^RESET%^%^ORANGE%^knob the only determent to proceeding into what appea"
	"rs to be a refined sitting area.%^RESET%^"
	);

    set_smell("default","
The brine filled ocean air fills your senses.");
    set_listen("default","Waves lap at the boat's hull, rocking it back and forth.");

    
set_items(([ 
	({ "sails", "sail", "rigging", "ropes" }) : "%^GREEN%^The sails are a deep emerald green in color.  Colorful against the white of the rigging.%^RESET%^",
	({ "rails", "wood", "wood rails", "fixtures", "brass" }) : "%^YELLOW%^The brass fixtures gleam against the highly polished wood, giving a bright contrast and sparkle.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/schooner_m3",
		"west" : "/d/av_rooms/lurue/schooner_m5",
		"south" : "/d/av_rooms/lurue/schooner_m10",
		"east" : "/d/av_rooms/lurue/schooner_m7",
		"northwest" : "/d/av_rooms/lurue/schooner_m2",
		"southwest" : "/d/av_rooms/lurue/schooner_m9",
	]));

    set_door("cabin door","/d/av_rooms/lurue/schooner_m7","east","schooner key","brass lock");
    add_lock("cabin door","schooner key","brass lock","This brass lock looks secure and strong.  Set into the wood of the door, you'll either need a key to unlock it or a lot of force to batter it down.");
    set_locked("cabin door",1,"brass lock");
    lock_difficulty("cabin door",-1000,"brass lock");
    set_open("cabin door",0);
    set_string("cabin door","knock","rap on the");
    set_string("cabin door","open","With a rush of air, the cabin door opens.");
    set_string("cabin door","close","The door closes with a final sound.");
    set_door_description("cabin door","This wooden door is finely carved and decorated with delicate carvings.  To either side of it, frosted windows can be seen along the walls, and in the center of the door, a glass oval depicting the endless sea is set.");
}