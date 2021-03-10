// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_council");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^ORANGE%^an %^BOLD%^expansive %^RESET%^%^ORANGE%^council room%^WHITE%^");

    set_long("%^ORANGE%^In contrast to the lavishly decorated rooms previous, this large council chamber has a much more solemn and subdued design, its walls and floors made of uniform s%^WHITE%^a%^BOLD%^n%^RESET%^"
	"%^ORANGE%^d%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^ORANGE%^e, with only a few %^BOLD%^%^RED%^banners %^RESET%^%^ORANGE%^adorning the walls. A large %^BOLD%^%^WHITE%^white t"
	"able %^RESET%^%^ORANGE%^dominates most of the room, and a dozen matching %^WHITE%^chairs %^ORANGE%^are set on each side, with one more at the head of the table opposite the door.%^WHITE%^"
	);

    set_smell("default","
The air smells almost entirely neutral.");
    set_listen("default","The room lends itself to a near perfect silence.");

    
set_items(([ 
	({ "walls", "wall", "floor" }) : "%^ORANGE%^Though clearly the work of a master artisan, these smooth sandstone walls and floors bear little embellishment.",
	({ "table", "chair", "chairs" }) : "%^BOLD%^The %^BLACK%^massive%^WHITE%^, ovular table that dominates most of this room is wrought of immaculate, s%^RESET%^m%^BOLD%^oo%^RESET%^t%^BOLD%^h %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e %^BOLD%^s%^RESET%^t%^BOLD%^o%^BLACK%^n%^WHITE%^e, and looks to be heavy enough that it is unclear how the table was moved into the room in the first place. The %^RESET%^chairs %^BOLD%^that line the table on each side are crafted of similar stone, though they thankfully seem light enough to move - possibly due to some manner of enchantment.%^RESET%^",
	({ "banner", "banners" }) : "%^BOLD%^%^RED%^Rich red b%^RESET%^%^RED%^a%^BOLD%^n%^RESET%^%^RED%^n%^BOLD%^e%^RESET%^%^RED%^r%^BOLD%^s adorn the walls all around this room at regular intervals, bearing the seal of this fortress in %^ORANGE%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e%^ORANGE%^n e%^WHITE%^m%^ORANGE%^br%^WHITE%^o%^ORANGE%^id%^WHITE%^e%^ORANGE%^ry%^RED%^.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/brandobaris/efrt_antechamber",
	]));

    set_door("golden door","/d/av_rooms/brandobaris/efrt_antechamber","north");
    set_open("golden door",0);
    set_string("golden door","knock","knock");
    set_string("golden door","open","%^ORANGE%^The door %^BOLD%^g%^WHITE%^l%^ORANGE%^i%^WHITE%^t%^ORANGE%^t%^RED%^e%^WHITE%^r%^ORANGE%^s %^RESET%^%^ORANGE%^in the light as it opens.%^WHITE%^");
    set_string("golden door","close","%^ORANGE%^The door closes with a solemn %^BOLD%^%^WHITE%^-%^BLACK%^thud%^WHITE%^-%^RESET%^%^ORANGE%^.%^WHITE%^");
    set_door_description("golden door","%^YELLOW%^This heavy door is made from %^BLACK%^da%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k wo%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^d%^ORANGE%^, and e%^RESET%^%^ORANGE%^m%^BOLD%^b%^RESET%^%^ORANGE%^e%^BOLD%^l%^RESET%^%^ORANGE%^l%^BOLD%^i%^RESET%^%^ORANGE%^s%^BOLD%^h%^RESET%^%^ORANGE%^e%^BOLD%^d heavily with g%^RESET%^%^ORANGE%^o%^BOLD%^ld and %^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^WHITE%^i%^RESET%^%^RED%^e%^BOLD%^s%^ORANGE%^.%^RESET%^");
}