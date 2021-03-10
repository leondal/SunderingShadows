// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_p1");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("old mounts");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^RESET%^%^ORANGE%^a plateau in the mountains%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^A plateau opens up here, wedged between the curves of two mountains and is sheltered from the harshest of winds.  About half way up the mountain, there is little here to be seen beyon"
	"d the mostly smooth plain of the ledge.  Looking outward though, the view is incredible, reaching all the way to the %^CYAN%^sea %^WHITE%^beyond the %^RESET%^%^GREEN%^valley %^BOLD%^%^WHITE%^and %^BLA"
	"CK%^plains%^WHITE%^.  A gathering of rocks, trees and shrubs partially covers the ledge, blocking your access to the remaining portion of the plateau.  Closer inspection reveals that the pile might ev"
	"en be a %^YELLOW%^nest%^WHITE%^.%^RESET%^"
	);

    set_smell("default","
There is a bitter, foul order coming from the pile of debris.");
    set_listen("default","The wind howls past this sheltered area.");

    
set_items(([ 
	({ "snow", "snow melt", "rain" }) : "%^BOLD%^%^WHITE%^Most of the peaks of the surrounding mountain range are dotted with snow caps that grow and shrink with the season.  The main source of water for the mountain streams, it is further enhanced by the occasional rainstorm.%^RESET%^",
	({ "mountains", "mountain", "mountain range", "range" }) : "%^BOLD%^%^BLACK%^The Parnelli Mountains extend east and west, curving to the south toward the eastern edge of the valley far below.  Dark granite makes up the majority of the stone that juts from the earth and forms these peaks, but you can see %^RESET%^%^ORANGE%^deep browns%^BOLD%^%^BLACK%^, %^RESET%^%^RED%^rusty reds %^BOLD%^%^BLACK%^and the occasional %^YELLOW%^glimmer %^BLACK%^throughout.%^RESET%^",
	({ "feather", "feathers" }) : "%^BOLD%^%^BLACK%^Some of those feathers look as big as you!%^RESET%^",
	({ "plateau", "ledge" }) : "%^BOLD%^%^WHITE%^Its difficult to make out much of the plateau due to the pile of old trees, branches and shrubs that appear to have gathered up in a pile here.  Likely the remains of a landslide or erosion, the pile looks a bit like a %^YELLOW%^nest %^WHITE%^for something very large.%^RESET%^",
	"nest" : "%^YELLOW%^The nest is made up of up-rooted trees, branches, rocks, shrubs and who knows what else.  Its very large and smells of things best left undiscovered.  You can even make out a few large feathers sticking out, now that you're looking closer.%^RESET%^",
	"crevice" : "%^BOLD%^%^BLACK%^The crevice is just a jagged opening that allows passage down onto the plateau to the south.  Oddly, there are several v-shaped crevices all in a neat row.  Almost as though something had taken a several chunks out of the rock.  You're pretty sure you could wiggle through them and make your way down to the plateau.%^RESET%^",
	]));

    set_exits(([ 
		"ride" : "/d/av_rooms/lurue/parmt_p2",
		"crevice" : "/d/av_rooms/lurue/parmt_m4",
	]));

}