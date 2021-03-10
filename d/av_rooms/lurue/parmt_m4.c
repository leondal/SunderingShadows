// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("parmt_m4");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("old mounts");
    set_travel("game track");
    set_climate("mountain");

    set_short("%^BOLD%^%^WHITE%^a dry streambed in the mountains%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The streambed continues northward, narrowing to little more then crag cutting through the mountain's stone.  %^RESET%^Rocks %^ORANGE%^and %^BOLD%^%^BLACK%^boulders %^RESET%^%^ORANGE"
	"%^rise up around you, but a crevice through them provides access to a %^RESET%^plateau %^ORANGE%^just to the south.  The plateau looks reasonably large, though you can see several tree trunks and some"
	" brush have gathered nearby, obscuring your view of much of the plateau's ledge.%^RESET%^"
	);

    set_smell("default","
The air is crisp and very cold.");
    set_listen("default","You can hear the shift of dirt and the occasional bird call.");

    
set_items(([ 
	({ "shrubs", "brush", "bushes", "trees", "grass", "landscape" }) : "%^GREEN%^Here in the lower part of the mountains, brush and trees can still be found, mostly pines and aspens, there are a few oaks, ash and birch to be found.  Further up the mountains, the trees give way to brush and the brush gives way to bare stone.%^RESET%^",
	({ "river beds", "riverbeds", "stream bed", "bed" }) : "%^RESET%^%^ORANGE%^Not completely dry, only a tiny trickle makes its way down what appears to have been a much larger stream at some point.  The bed makes for a reasonably safe pathway if someone wished to continue upward into the mountains.%^RESET%^",
	({ "mountains", "mountain", "mountain range", "range" }) : "%^BOLD%^%^BLACK%^The Parnelli Mountains extend east and west, curving to the south toward the eastern edge of the valley far below.  Dark granite makes up the majority of the stone that juts from the earth and forms these peaks, but you can see %^RESET%^%^ORANGE%^deep browns%^BOLD%^%^BLACK%^, %^RESET%^%^RED%^rusty reds %^BOLD%^%^BLACK%^and the occasional %^YELLOW%^glimmer %^BLACK%^throughout.%^RESET%^",
	({ "snow", "snow melt", "rain" }) : "%^BOLD%^%^WHITE%^Most of the peaks of the surrounding mountain range are dotted with snow caps that grow and shrink with the season.  The main source of water for the mountain streams, it is further enhanced by the occasional rainstorm.%^RESET%^",
	({ "plateau", "ledge" }) : "%^BOLD%^%^WHITE%^Its difficult to make out much of the plateau due to the pile of old trees, branches and shrubs that appear to have gathered up in a pile here.  Likely the remains of a landslide or erosion, the pile looks a bit like a %^YELLOW%^nest %^WHITE%^for something very large.%^RESET%^",
	"crevice" : "%^BOLD%^%^BLACK%^The crevice is just a jagged opening that allows passage down onto the plateau to the south.  Oddly, there are several v-shaped crevices all in a neat row.  Almost as though something had taken a several chunks out of the rock.  You're pretty sure you could wiggle through them and make your way down to the plateau.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/parmt_m3",
		"crevice" : "/d/av_rooms/lurue/parmt_p1",
	]));

}