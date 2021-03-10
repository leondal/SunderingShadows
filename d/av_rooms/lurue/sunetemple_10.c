// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_10");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Beauty's Alcove%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This small alcove has been created in the causeway formed between two columns.  Sheer, alternating drapes of %^RED%^crimson %^WHITE%^and %^RESET%^ivory %^BOLD%^%^WHITE%^toned silk han"
	"g from s%^BLACK%^i%^WHITE%^lv%^BLACK%^e%^WHITE%^r rings affixed to the ceiling's rim.  The diaphanous, billowing material encloses the small area giving it a semblance of intimate privacy.  Set in the"
	" center of this recess is a large %^RESET%^%^CYAN%^mirror %^BOLD%^%^WHITE%^framed in %^YELLOW%^golden filigree %^WHITE%^and supported by two large %^BLACK%^mahogany %^WHITE%^supports that keep the mir"
	"ror standing up straight.  A single, heavy appearing, high backed chair is set centered before the mirror. Like the mirror it seems to be made of %^BLACK%^mahogany %^WHITE%^and is upholstered in %^YEL"
	"LOW%^golden fabric %^WHITE%^on the seat and backrest.  Stretched across the marble floor of the enclosure is a circular, %^GREEN%^tapestry carpet%^WHITE%^.  The images within its weave are of interlac"
	"ing %^RED%^rose bushes %^WHITE%^in various stages of bloom.  Curving around the back half of the enclosure, only a little higher then the chair's seat, is a low white marble wall.  Upon it rests a rai"
	"sed %^RESET%^%^ORANGE%^bronze plaque %^BOLD%^%^WHITE%^with a meditative %^CYAN%^prayer %^WHITE%^etched in fluid %^YELLOW%^golden scrollwork%^WHITE%^.  Above everything, on the domed ceiling are images"
	" of individuals standing before many different reflective surfaces.  Incredibly detailed, they show the stages of life from young to old.  No two are the same and yet a sense of %^MAGENTA%^wonder %^WH"
	"ITE%^emanates from each, filling the enclosure with an beautiful aura of welcome.%^RESET%^"
	);

    set_smell("default","
The faint scent of roses fills your senses.");
    set_listen("default","You can hear the sounds of joyful laughter coming from the garden temple.");


    set_exits(([ 
		"south" : "/d/av_rooms/lurue/sunetemple_04",
		"southwest" : "/d/av_rooms/lurue/sunetemple_09",
	]));

}