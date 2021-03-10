// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_back");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Back of the Chapel%^RESET%^");

    set_long("%^RESET%^%^GREEN%^The back of the chapel reveals a vaulting, arched ceiling over a beautiful %^BOLD%^%^BLACK%^gothic%^RESET%^%^GREEN%^ chapel. Further east lies row upon row of %^ORANGE%^pews%^GREEN%^"
	" for the faithful, and in the very front of the chapel is a %^WHITE%^stone altar%^GREEN%^. Alcoves lie to the northeast and southwest, which can be reached by walking down outer aisles outside the pew"
	"s. %^YELLOW%^S%^CYAN%^t%^GREEN%^a%^BLUE%^i%^WHITE%^n%^RED%^e%^MAGENTA%^d%^CYAN%^ glass windows%^RESET%^%^GREEN%^ line the chapel walls, %^BLUE%^splashing%^GREEN%^ streams of %^YELLOW%^light%^RESET%^%^"
	"GREEN%^ and %^WHITE%^c%^RED%^o%^YELLOW%^l%^RESET%^%^BLUE%^o%^ORANGE%^r%^RESET%^%^GREEN%^ throughout the chapel.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^MAGENTA%^Zesty%^BLACK%^ scents reach your nose of stone walls and decay with a %^GREEN%^dash%^BLACK%^ of %^RED%^dead body stank%^BLACK%^.%^RESET%^");
    set_listen("default","Peacefully quiet. Too quiet?");

    set_search("ceiling,walls,floor","Ceiling, walls, and floor: all made of the finest marble.");
    set_search("alcoves","You will have to walk to them.");
    set_search("altar","You will have to walk to it to get a closer look.");
    set_search("pews","They seem shattered and in very great disrepair. But you will have to move closer to get a better look.");
    set_search("windows","Nothing seems out of the ordinary. The windows are made of colored glass.");
    
set_items(([ 
	({ "ceiling", "walls", "floor" }) : "Ceiling, walls, and floor: all made of the finest marble.",
	"alcoves" : "You will have to walk to them.",
	"altar" : "You will have to walk to it to get a closer look.",
	"pews" : "They seem shattered and in very great disrepair. But you will have to move closer to get a better look.",
	"windows" : "%^YELLOW%^The glass depict images of %^WHITE%^Kelemvor%^YELLOW%^ with uplifted hand with %^CYAN%^scales%^YELLOW%^ to weigh souls.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/myrkul/location_chapel_salcove",
		"northeast" : "/d/av_rooms/myrkul/location_chapel_nalcove",
		"west" : "/d/av_rooms/myrkul/location_chapel_entry",
		"east" : "/d/av_rooms/myrkul/location_chapel_mid",
	]));

}