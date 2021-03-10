// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_13");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Center of the City of Seneca%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Wooden trellises %^GREEN%^are artfully arranged around the city garden.  Over run with %^BOLD%^%^MAGENTA%^blooming flowers %^RESET%^%^GREEN%^whose weight has begun to take its toll,"
	" the grounds are still lovely to look upon and spend time within.  %^ORANGE%^Wooden benches%^GREEN%^, worn from the weather could support a bit of weight still, and offer a place in the central courty"
	"ard to rest and relax, or study the %^BOLD%^%^WHITE%^statue %^RESET%^%^GREEN%^of an elven figure at its center.%^RESET%^"
	);

    set_smell("default","
The clean scent of the ocean rises on the breeze.");
    set_listen("default","You can faintly hear the crashing of waves on the shore.");

    
set_items(([ 
	({ "benches", "bench" }) : "%^RESET%^%^ORANGE%^ Each of the benches is crafted from slats of wood placed closely together to form a simple place to sit.  They are scattered about the garden in a natural way, with no regard to symmetry.%^RESET%^",
	({ "flowers", "flower" }) : "%^RESET%^%^GREEN%^ The flowers grow from vines much like ivy and are formed into trumpet blossoms in a mixed variety of %^BOLD%^%^RED%^reds%^RESET%^%^GREEN%^, %^MAGENTA%^purples%^RESET%^%^GREEN%^, %^BOLD%^%^MAGENTA%^pinks%^RESET%^%^GREEN%^, %^YELLOW%^yellows%^RESET%^%^GREEN%^, and countless shades in between.%^RESET%^",
	({ "trellis", "trellises", "wooden trellises" }) : "%^RESET%^%^ORANGE%^The sun trellis is built upon four thick square columns roofed with lattice that rises high overhead, creating a unique sense of freedom and cover at once.  Trumpet blossoms in countless %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^WHITE%^o%^MAGENTA%^r%^RESET%^%^MAGENTA%^s climb the trellis, dancing within the lattice openings and swirling around the columns.%^RESET%^",
	"statue" : "%^BOLD%^%^WHITE%^Books in precarious stacks pile around the slender feet of this male elf.  He holds an ancient tome open in his slender hands, the pages rolling and crumbling. Flowing hair restrained by a delicate circlet cascades down his back to his waist, where his simple robes are gathered by a silken rope belt.  Intelligence radiates from his elven features, visible in his eyes, while even his pointed ears seem alert.  Like the other statues, something has been broken away, a staff perhaps for the statue seems posed leaning slightly as though supported.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/attaya_10",
	]));

}