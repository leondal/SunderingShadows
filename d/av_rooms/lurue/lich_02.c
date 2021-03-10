// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("lich_02");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^YELLOW%^C%^WHITE%^h%^RESET%^a%^YELLOW%^m%^WHITE%^b%^RESET%^e%^YELLOW%^r%^RESET%^ of %^YELLOW%^T%^WHITE%^r%^RESET%^e%^YELLOW%^a%^WHITE%^s%^RESET%^u%^YELLOW%^r%^WHITE%^e%^RESET%^s");

    set_long("%^RESET%^This huge room is filled with piles upon piles of %^YELLOW%^treasure%^RESET%^.  As far as the eye can see, mounds of goods lay strewn about.  Everything from ornately sculpted %^BOLD%^%^WHITE"
	"%^statues%^RESET%^, to fine %^ORANGE%^carvings%^WHITE%^, to piles of %^YELLOW%^gold%^RESET%^, %^WHITE%^silver %^RESET%^and other precious metals.  %^RED%^Jewels%^RESET%^, %^MAGENTA%^gems%^RESET%^, fan"
	"ciful items that %^CYAN%^%^BOLD%^glitter %^RESET%^and %^BOLD%^%^WHITE%^gleam %^RESET%^in the light.  The wealth of nations, a dragon's hoard.  In the center of all this is %^MAGENTA%^velvet %^RESET%^d"
	"raped throne.  Sculpted from the same %^BOLD%^%^WHITE%^mithril %^RESET%^that the made the doors, this throne is huge and could easily seat several men."
	);

    set_smell("default","
Precious oils and perfumes anoint the air.");
    set_listen("default","The shift of coins reminds you of how much wealth surrounds you.");


    set_exits(([ 
		"south" : "/d/av_rooms/lurue/lich_01",
	]));

    set_door("mithril door","/d/av_rooms/lurue/lich_01","south","key","golden lock");
    add_lock("mithril door","key","golden lock","%^YELLOW%^Capped with gold you imagine that this door has an intricate device to keep it locked tight against anyone who might find their way through the maze and to this spot.%^RESET%^");
    set_locked("mithril door",1,"golden lock");
    lock_difficulty("mithril door",-70,"golden lock");
    set_open("mithril door",0);
    set_string("mithril door","knock","pounds on the heavy");
    set_string("mithril door","open","%^BOLD%^%^WHITE%^The door opens without a whisper of sound.%^RESET%^");
    set_string("mithril door","close","%^BOLD%^%^WHITE%^The door closes with an ominous thud.%^RESET%^");
    set_door_description("mithril door","%^BOLD%^%^WHITE%^Made from mithril, these doors stand ten feet high.  Rings of %^YELLOW%^gold %^WHITE%^are fitted into the handles to allow them to be pulled easier, but they still look to weigh a ton.  Etched across their glossy surface are images of a %^BLACK%^dark tower %^WHITE%^rising over a %^GREEN%^valley%^WHITE%^.  Down in the valley are several tiny %^RESET%^%^ORANGE%^villages %^BOLD%^%^WHITE%^that appear to cower under the tower's presence.  Standing atop the tower, you can see a %^RESET%^%^BLUE%^figure %^BOLD%^%^WHITE%^stands, his cloak or robe flowing out behind him.  Atop his head, a wreath of %^RESET%^%^MAGENTA%^f%^RED%^l%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^m%^RED%^e%^MAGENTA%^s %^BOLD%^%^WHITE%^dance but don't appear to burn him.%^RESET%^");
}