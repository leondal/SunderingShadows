#include <std.h>
#include "../valley.h"

#define NAMES ({"bracelet","necklace","crown","armlet"})

inherit "/std/armour";

int i,j, val;
string str, TYPE;

void create()
{
	::create();
	val = random(500);
	switch(val) {
		case 0..100:
			TYPE = "%^ORANGE%^sea shells%^RESET%^";
			break;
		case 101..200:
                        TYPE = "%^ORANGE%^c%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^l%^RESET%^";
			break;
		case 201..300:
			TYPE = "%^BOLD%^%^WHITE%^iv%^YELLOW%^o%^WHITE%^ry%^RESET%^";
			break;
		case 301..400:
			TYPE = "%^BOLD%^%^WHITE%^pearls%^RESET%^";
			break;
		case 401..500:
			TYPE = "%^BOLD%^%^BLACK%^black pearls%^RESET%^";
			break;
	}
	j = random(4);
	str = NAMES[j];
	set_name("jewelry");
	set_size(1);
	set_weight(3);
	set_id(({"jewelry","ornament","trinket",str,capitalize(str)}));
	if(val < 50) {
		set_value(50);
	}
	else {
		set_value(val);
	}
	set_type("ring");
	if(str == "necklace") {
		set_limbs(({"neck"}));
		set_short("A necklace of "+TYPE+"");
		set_long("This is a beautiful necklace made out of "+TYPE+""+
		" strung tightly together and doubled over several times"+
		" so that it circles the wearer's neck in three loops."+
		" It is a little out of fashion for normal society, but"+
		" could be worth some money at a novelty shop.");
	}
	if(str == "crown") {
		set_limbs(({"head"}));
		set_short("A regal crown of "+TYPE+"");
		set_long("This is a tiny crown that might be worn by a"+
		" sea sprite. It is delicately crafted out of "+TYPE+"."+
		" Something like this belongs behind a display cabinet"+
		" instead of on someone's head.");
	}
	if(str == "bracelet") {
		set_limbs(({"right arm","left arm"}));
		set_short("A tiny bracelet of "+TYPE+"");
		set_long("The bracelet is made out of "+TYPE+". It is very"+
		" small and delicate, just from looking at it you wouldn't"+
		" think anyone's wrist would actually fit in something"+
		" so tiny! Cute is the only way to describe such a piece"+
		" of gaudy jewelry.");
	}
	if(str == "armlet") {
		set_limbs(({"right arm","left arm"}));
		set_short("An armlet made of "+TYPE+"");
		set_long("This armlet is a pretty little trinket made of "+TYPE+". It could"+
		" have come from some tropical island as a momento of the"+
		" trip. Too small to fit on a normal person, it seems"+
		" like the right size for a child. Still, it might be"+
		" worth a little bit at some store.");
	}
}
