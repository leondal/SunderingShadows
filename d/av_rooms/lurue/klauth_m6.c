// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("klauth_m6");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("shore");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^Edge of a Crater%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You scramble up onto the edge of the crater and find yourself peering down into %^RED%^Klauth's %^BLACK%^home.  The giant red dragon that everyone fears.  From here you can see severa"
	"l things including the large %^CYAN%^crystal fishbowl %^BLACK%^which contains your friend and the %^YELLOW%^treasure pile %^BLACK%^that Klauth has gathered.  The %^YELLOW%^glitter %^BLACK%^and %^WHITE"
	"%^gleam %^BLACK%^of that pile nearly distracts you from your destination.  So many treasures to be had.  Of course if the dragon catches you..  Best to keep your eye on your destination.  The only que"
	"stion now is how to get %^RED%^Valas %^BLACK%^out of a crystal dome.%^RESET%^"
	);

    set_smell("default","
The smell of sulfur is heavy in the air.");
    set_listen("default","Little rocks skitter down the mountain side.");

    
set_items(([ 
	({ "dragon", "klauth" }) : "%^RED%^Thankfully, he seems to be missing right now.  You only hope he doesn't come back too soon, otherwise you might end up dragon food.%^RESET%^",
	({ "treasure", "gold", "pile", "treasure pile", "glitter", "gleam" }) : "%^YELLOW%^Piles upon piles of amazing treasure are littered around the crater that Klauth calls home.  Each piece gleaming and glittering in even the faintest of light.  Legendary armor and weapons, rare and powerful artifacts, gold, platinum and jewels, all there for the taking.  If you were willing to risk it.  If you were willing to try for the treasure instead of your friend who sits in a magical fish bowl waiting for rescue.  So many treasures though... and no dragon to protect them.%^RESET%^",
	({ "fishbowl", "bowl", "fish bowl", "valas" }) : "%^BOLD%^%^CYAN%^The fishbowl is close to where you are.  A huge dome of clear crystal the bowl has an opening on top, but even from here you can see the magical field that covers it and prevents access. The sides of the crystal look at least a foot thick, distorting what is inside.  You can, however, see the shape of a man inside, along with a couch and a.. is that a palmtree?.. and a few other personal things that the dragon has provided to the wizard for his comfort.  How you get Valas out of that crystal is a whole other question for its clear that there is a magical force covering it and its likely designed to prevent him from getting out as well as someone else from entering and saving him.%^RESET%^",
	]));

    set_exits(([ 
		"wizonly" : "/d/darkwood/yntala/rooms/sec5",
		"southwest" : "/d/av_rooms/lurue/klauth_m5",
	]));



    set_invis_exits(({ "wizonly" }));

}