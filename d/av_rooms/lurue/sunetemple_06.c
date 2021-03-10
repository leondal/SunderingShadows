// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_06");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Love's Alcove%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This small alcove has been created in the causeway formed between two columns.  Sheer, alternating drapes of %^RED%^ruby %^WHITE%^and %^YELLOW%^amber %^WHITE%^toned silk hang from %^Y"
	"ELLOW%^golden rings %^WHITE%^affixed to the ceiling's rim.  The diaphanous, billowing material encloses the small area giving it a semblance of intimate privacy.  Within the recess, a pair of velvet-c"
	"overed, %^RESET%^%^RED%^burgundy%^BOLD%^%^WHITE%^ settees are placed for relaxing.  Each has several %^YELLOW%^gold-brocade %^WHITE%^pillows that offer lavish comfort for reclining.  Stretched across "
	"the marble floor of the enclosure is a circular, %^RESET%^ivory %^BOLD%^%^WHITE%^colored carpet.  The softness of its thick, deep pile makes an attractive invitation to go %^RESET%^%^ORANGE%^barefoot "
	"%^BOLD%^%^WHITE%^while here.  Curving around the back half of the enclosure, only a little higher then the settees themselves, is a low white marble wall.  Upon it rests a raised %^RESET%^%^ORANGE%^br"
	"onze plaque %^BOLD%^%^WHITE%^with a meditative %^CYAN%^prayer %^WHITE%^etched in fluid %^YELLOW%^golden %^WHITE%^scrollwork.  Above everything, on the domed ceiling are images of couples sharing each "
	"other's company in an inviting %^GREEN%^pastoral settings%^WHITE%^.  Incredibly detailed, they show the stages of life from young to old.  No two pairings are the same and yet a sense of %^RED%^devoti"
	"on %^WHITE%^emanates from each, filling the enclosure with an aura of loving harmony.%^RESET%^"
	);

    set_smell("default","
The faint scent of roses fills your senses.");
    set_listen("default","You can hear the sounds of joyful laughter coming from the garden temple.");


    set_exits(([ 
		"north" : "/d/av_rooms/lurue/sunetemple_02",
		"northwest" : "/d/av_rooms/lurue/sunetemple_07",
	]));

}