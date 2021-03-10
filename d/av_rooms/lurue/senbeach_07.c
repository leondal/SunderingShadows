// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("senbeach_07");
    set_property("indoors",1);
    set_property("light",-3);
    set_property("no teleport",1);
    set_terrain("deep water");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A hidden underwater chamber%^RESET%^");

    set_long("%^RESET%^%^BLUE%^You wiggle through yet another %^BOLD%^%^BLACK%^hole %^RESET%^%^BLUE%^in this underground maze and find yourself in a small chamber.  Unlike the tunnel you were in earlier, this room "
	"shows clear signs of having been formed intentionally.  The room is circular, a %^CYAN%^bubble %^BLUE%^within the dark stone that makes up the chamber.  Etched into the stone surface is a %^MAGENTA%^s"
	"w%^WHITE%^i%^CYAN%^r%^MAGENTA%^li%^CYAN%^n%^MAGENTA%^g m%^WHITE%^a%^CYAN%^t%^MAGENTA%^r%^WHITE%^i%^MAGENTA%^x %^BLUE%^of carved markings that ruin the otherwise smooth surface.  The only place that ma"
	"rs this perfect bubble is the %^BOLD%^%^BLACK%^crevice %^RESET%^%^BLUE%^through which you entered, and even that appears to be part of the design.%^RESET%^ "
	);

    set_smell("default","
You can't smell anything underwater.");
    set_listen("default","The sound of the water moving past your ears is the only sound.");

    
set_items(([ 
	({ "hole", "crevice" }) : "%^BOLD%^%^BLACK%^This crevice appears to have been planned for, even though it looks strangely natural with its ragged edges.  Still, as the only apparent way in or out the builder of this chamber must have known it was there and worked around it.%^RESET%^",
	({ "matrix", "swirling matrix" }) : "%^RESET%^%^MAGENTA%^Carved into the stone is a matrix of swirls and images all of which blend together into a larger picture that spans the whole bubble of the room.  Whatever madness possessed someone to carve this architecture under water is impossible to say but you think if you looked closer at the lines you might be able to figure them out.%^RESET%^",
	({ "matrix", "swirling matrix" }) : "%^RESET%^%^MAGENTA%^Carved into the stone is a matrix of swirls and images all of which blend together into a larger picture that spans the whole bubble of the room.  Whatever madness possessed someone to carve this architecture under water is impossible to say but you think if you looked closer at the lines you might be able to figure them out.%^RESET%^",
	({ "hole", "crevice" }) : "%^BOLD%^%^BLACK%^This crevice appears to have been planned for, even though it looks strangely natural with its ragged edges.  Still, as the only apparent way in or out the builder of this chamber must have known it was there and worked around it.%^RESET%^",
	"mar" : "%^BOLD%^%^BLACK%^You look closer at the mar on the otherwise perfectly smooth surface of this room, and realize that the reason it looks so strange is because it's a button.  Something you could %^RESET%^depress%^BOLD%^%^BLACK%^ if you wanted.  Considering this is a maze to a map, it might just open a way to that maze.%^RESET%^",
	"lines" : "%^MAGENTA%^Your eyes follow the lines and swirls, and slowly you begin to realize you're looking at a map to a maze.  A large, intricate one that must be huge.  Could this be the entrance to such a maze?  And if so, what's in the center?  As you ponder this you find a small mar in the smooth surface of the pattern.%^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/lurue/senbeach_04",
	]));

}

void init() {
   ::init();
   add_action("depress_fun","depress");
}

int depress_fun(string str) {
   if(!str) return notify_fail("What do you want to depress?\n");
   if(str != "button") return notify_fail("You can't depress that.\n");

   tell_room(TO,"%^BOLD%^%^BLACK%^The button depresses into the surface of the wall and a whoosh of bubbles erupt as a portion of the bottom opens and something swims out!%^RESET%^");
   return 1;
}