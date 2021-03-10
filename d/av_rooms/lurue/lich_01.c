// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("lich_01");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^An underground cavern%^RESET%^");

    set_long("%^RESET%^Climbing up onto the hidden %^BLUE%^ledge %^RESET%^you find yourself standing in a narrow cave shorn out of the %^ORANGE%^brown stone %^RESET%^that makes up the cliffs of Seneca.  %^YELLOW%^G"
	"%^WHITE%^o%^RESET%^l%^YELLOW%^d f%^WHITE%^l%^RESET%^e%^YELLOW%^c%^WHITE%^k%^RESET%^s catch in your light and flicker throughout the darkness, like %^YELLOW%^golden eyes %^RESET%^blinking in and out of"
	" sight.  The ground is rough and uneven, covered in tiny %^BOLD%^%^BLACK%^rocks%^RESET%^ and bits of %^ORANGE%^rubble%^RESET%^, making you wonder if anyone ever walks this way any more.  The ground sl"
	"opes downward, making its way to a vast underground %^BLUE%^lake %^RESET%^that spans the cavern and prevents crossing without getting wet, unless you want to risk climbing over those %^BOLD%^%^BLACK%^"
	"stone protrusions %^RESET%^that jut up out of the water.  Ahead, set into the stone wall, at the far end of the cave, across the underground pool, you can see the gleam of %^BOLD%^%^WHITE%^mithril doo"
	"rs%^RESET%^.  Their highly etched forms the only thing of beauty in this otherwise stark cave. %^RESET%^"
	);

    set_smell("default","
You can smell the cloying scent of saltwater and rotting seaweed.");
    set_listen("default","The soft lap of the waves echoes in the chamber.");

    
set_items(([ 
	({ "lake", "water", "underground lake", "sea" }) : "%^BLUE%^The water is deep and moves constantly, making you think that it is fresh from the sea and would likely provide another way out if you didn't mind %^CYAN%^swimming%^BLUE%^.%^RESET%^",
	({ "stone", "brown stone", "rock", "gold", "gold flecks", "eyes" }) : "%^RESET%^%^ORANGE%^This cave is carved from the brown colored stone that makes up the cliffs that Seneca is built upon.  The golden flecks run through out the stone, giving it highlights that shimmer in any light.%^RESET%^",
	({ "rocks", "rubble" }) : "%^BOLD%^%^BLACK%^Scattered across the floor of this cave are piles of rubble and rock, likely fallen from above when it was disturbed by whatever is making all that rustling noise.  You notice that there are a few small bones amongst the piles, leading you further to worry about what lurks above.%^RESET%^",
	"ledge" : "%^BLUE%^A carefully hidden ledge offers a way out of this cave and back into the labyrinth of foul smelling sewers.%^RESET%^ ",
	"protrusions" : "%^BOLD%^%^BLACK%^Jutting out of the underground lake, these stone protrusions look much like they might have once been stalagmites, but they have long since broken and made uneven surfaces that could be climbed across.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/lich_02",
		"out" : "/d/av_rooms/lurue/maze_out",
		"swim" : "/d/av_rooms/lurue/lich_03",
	]));



    set_invis_exits(({ "swim" }));

    set_door("mithril door","/d/av_rooms/lurue/lich_02","north","key","golden lock");
    add_lock("mithril door","key","golden lock","%^YELLOW%^Capped with gold you imagine that this door has an intricate device to keep it locked tight against anyone who might find their way through the maze and to this spot.%^RESET%^");
    set_locked("mithril door",1,"golden lock");
    lock_difficulty("mithril door",-70,"golden lock");
    set_open("mithril door",0);
    set_string("mithril door","knock","pounds on the heavy");
    set_string("mithril door","open","%^BOLD%^%^WHITE%^The door opens without a whisper of sound.%^RESET%^");
    set_string("mithril door","close","%^BOLD%^%^WHITE%^The door closes with an ominous thud.%^RESET%^");
    set_door_description("mithril door","%^BOLD%^%^WHITE%^Made from mithril, these doors stand ten feet high.  Rings of %^YELLOW%^gold %^WHITE%^are fitted into the handles to allow them to be pulled easier, but they still look to weigh a ton.  Etched across their glossy surface are images of a %^BLACK%^dark tower %^WHITE%^rising over a %^GREEN%^valley%^WHITE%^.  Down in the valley are several tiny %^RESET%^%^ORANGE%^villages %^BOLD%^%^WHITE%^that appear to cower under the tower's presence.  Standing atop the tower, you can see a %^RESET%^%^BLUE%^figure %^BOLD%^%^WHITE%^stands, his cloak or robe flowing out behind him.  Atop his head, a wreath of %^RESET%^%^MAGENTA%^f%^RED%^l%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^m%^RED%^e%^MAGENTA%^s %^BOLD%^%^WHITE%^dance but don't appear to burn him.%^RESET%^");
}