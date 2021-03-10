// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("masq_m1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Land of %^WHITE%^Mist%^MAGENTA%^ and %^BOLD%^%^CYAN%^Dreams%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^As the mist from the portal fades away, you find yourself standing in the lavish foyer of an extraordinary estate.  Walls of pale %^RESET%^white marble %^BOLD%^%^WHITE%^extend upward "
	"to an arched ceiling high overhead, from the center of which a bell shaped spill of %^MAGENTA%^cr%^WHITE%^y%^RESET%^%^MAGENTA%^s%^BOLD%^tal %^WHITE%^shards glow with magical light illuminating the hal"
	"l.  Rich tapestries of %^RESET%^%^GREEN%^a%^ORANGE%^n%^RESET%^c%^GREEN%^ie%^BOLD%^%^BLACK%^n%^RESET%^%^GREEN%^t %^BOLD%^%^WHITE%^settings can be seen upon the walls of the hallway that leads off to th"
	"e north, following the %^RESET%^%^ORANGE%^golden tiled %^BOLD%^%^WHITE%^floor.  Though a thick %^RESET%^%^MAGENTA%^purple rope %^BOLD%^%^WHITE%^has been strung across the pathway preventing access to "
	"the corridors beyond.  To the west a large set of %^RESET%^%^ORANGE%^golden %^BOLD%^%^WHITE%^double doors open into an immense ballroom filled with costumed attendees.  The sounds of music and laughte"
	"r drift from this chamber, beckoning you further in.%^RESET%^"
	);

    set_smell("default","
A faint, rich scent of flowers and earth lingers here.");
    set_listen("default","You can hear the pleasant sounds of laughter and conversation.");

    
set_items(([ 
	({ "doors", "double doors", "golden doors" }) : "%^RESET%^%^ORANGE%^Standing open, these doors look to be made from solid gold that has been burnished with a dulling agent to give them an aged look.  Though still stunning from the intricate art that has been molded onto them, the doors do not blaze with reflected light, but rather glow softly.%^RESET%^",
	({ "ballroom", "attendees", "costumed attendees" }) : "%^BOLD%^%^WHITE%^To the west you can see the main ballroom is filled with people dressed in costumes. %^RESET%^",
	({ "rope", "purple rope", "floor", "tiled floor", "golden floor", "tiles", "tile" }) : "%^RESET%^%^ORANGE%^Covered in tiles of pale gold marble, the hallway stretches off to the north but has been closed off with a dark purple rope and set of golden poles.  You're certain you could just walk past them except that something about that rope makes the hair on the back of your neck stand on edge and have second guesses.%^RESET%^",
	({ "tapestries", "tapestry", "setttings", "ancient settings" }) : "%^RESET%^%^GREEN%^There are several tapestries that line the walls of this foyer and the hallway that leads off to the north.  Though most appear to be ancient settings depicting gardens and pastoral settings, you notice a few have more interesting settings.  Perhaps you could look at the %^WHITE%^first %^GREEN%^or %^WHITE%^second %^GREEN%^tapestry closer.%^RESET%^",
	({ "ceiling", "crystals", "crystal shards", "shards", "light", "magical light", "bell" }) : "%^BOLD%^%^MAGENTA%^Bell shaped, the shards of crystals that hang from the ceiling and create a glimmering chandelier are set alight with a magical light that gives the crystals a purplish glow but which sheds white light down onto the floor.%^RESET%^",
	({ "walls", "wall", "marble", "foyer" }) : "%^BOLD%^%^WHITE%^Lined with slabs of pale white marble, the walls of the foyer rise high overhead into a vaulted ceiling.  The pale marble veined with faint lines of quartz that catches the light and glints in the light shed by the illuminated crystals above.%^RESET%^",
	"second tapestry" : "%^BOLD%^%^WHITE%^Peering closely at the tapestry to the left of the double doors you see that the image is of a finely appointed sitting room.  A %^RESET%^%^MAGENTA%^regal looking family %^BOLD%^%^WHITE%^is sitting around before the %^RESET%^%^RED%^fireplace%^BOLD%^%^WHITE%^.  The man in an arm chair, his wife on the couch with their young daughter working on %^YELLOW%^needlepoint%^BOLD%^%^WHITE%^, while the small son plays with a puppy on the floor.  It all looks normal till you start to step away and realize that the %^RED%^fire has %^WHITE%^spilled from the fireplace and is creeping across the lush carpet toward the unaware family.  Through the window you can see a %^BLACK%^cloaked figure %^WHITE%^peering in with glowing %^RED%^red %^WHITE%^eyes.%^RESET%^ ",
	"first tapestry" : "%^BOLD%^%^WHITE%^Peering closely at the tapestry to the right of the double doors you see that the image is that of a %^RESET%^%^MAGENTA%^regal looking family %^BOLD%^%^WHITE%^sitting before a multi tiered %^CYAN%^fountain %^WHITE%^that sparkles brightly in the %^YELLOW%^sun%^WHITE%^.  Beyond them, a lovely looking %^GREEN%^garden %^WHITE%^extends including a playful looking hedge maze.  As you start to step away though, you notice hiding within the maze's shadow a %^BLACK%^cloaked figure %^WHITE%^lurks, the disturbing contrast to the otherwise happy setting sends a %^BLUE%^chill %^WHITE%^down your spine.%^RESET%^",
	"portal" : "%^RESET%^%^MAGENTA%^The protal hovers in the air, surrounded by a white marble arch.  Through it you can see a fine mist spilling and beyond it looks like some sort of forest might be waiting.  A set of stairs leads up to the portal offering assistance to reach it, though it seems that once you step off that last stair you will just fall through.  Could there be something on the other side to catch you?%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/masq_m2",
		"portal" : "/d/av_rooms/lurue/masq_t2",
	]));
}