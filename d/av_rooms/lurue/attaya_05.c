// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";
int bar;

void init() {
    ::init();
    add_action("pull_func", "pull");
    bar = 0;

}

void create()
{
    ::create();
    set_name("attaya_05");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Under the boardwalk%^RESET%^");

    set_long("%^RESET%^This little niche under the boardwalk is perfect for a person to comfortably relax and remain unseen by those below.  The thick %^BOLD%^%^BLACK%^crossbeams%^RESET%^ that support the walkways "
	"of the pier, extend at angles and where they cross there is often a little niche formed.  This high up, you can see where several others have learned the same thing.  %^BOLD%^%^WHITE%^Graffiti %^RESET"
	"%^covers the underside of the boardwalk.  Everything from %^RED%^hearts %^RESET%^with initials to %^CYAN%^crude phrases %^RESET%^dot the dark wood.  A few are more intricate though and show an artists"
	" touch.  Much like the %^BOLD%^%^BLACK%^design %^RESET%^above your head.%^RESET%^"
	);

    set_smell("default","
You can smell the salty spray of the ocean.");
    set_listen("default","The waves pound against the rocky coastline further south.");

    
set_items(([ 
	({ "design", "designs" }) : "%^RESET%^%^MAGENTA%^All over there are designs that are a bit nicer then the generic scrawl of young kids.  Above your head in particular is a very interesting one.  A carved drawing of a beach with high cliffs all around it.  The water rolls in and out but jetties sweep across the cove preventing the harsher waves from finding their way in making the area calm and relaxed.  A perfect beach for basking.  It even looks like there is a cave or something hidden behind a few barnacles.  Maybe if you %^RESET%^pull%^MAGENTA%^ed them away you could see it better.%^RESET%^",
	({ "graffiti", "markings", "hearts", "initials", "phrases" }) : "%^BOLD%^%^BLACK%^It looks like many climb up into this place to carve their mark on the world.  You can see where many have left their initials or a phrase.  Most are crude and childish making you think that its mostly teenagers that find this place so charming, but there are a few %^RESET%^designs%^BOLD%^%^BLACK%^ which have an artistic touch.%^RESET%^",
    ({ "barnacles" }) : "%^RESET%^%^ORANGE%^Small and roughly circular in shape, these barnacles are old and dried out, the little creature that lived within long dead.  All that is left is the dried out husk firmly stuck to the wooden board, you could %^YELLOW%^pull them%^RESET%^%^ORANGE%^.%^RESET%^",
	]));

    set_exits(([ 
		"down" : "/d/av_rooms/lurue/attaya_04",
	]));

}

int pull_func(string str){

if(!str){return 0;
        }
    if((str == "barnacles")){
        if((bar == 1)){
            tell_object(TP,"%^RESET%^%^RED%^The barnacles have already been pulled!\n%^RESET%^");
            return 1;
        }
        tell_object(TP,"%^RESET%^%^ORANGE%^As you pull the barnacles away the wood comes with it, completely removing the design%^RESET%^\n");
        tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" %^RESET%^%^ORANGE%^pulls off the barnacles. \n",TP);
        bar = 1;
        return 1;
    }
    tell_object(TP,"%^RESET%^%^ORANGE%^pull what?\n");
    return 1;
    }

