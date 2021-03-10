//mage_akadi.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the blazing effigy");
	set_id(({ "robe", "robe of the blazing effigy" }));
	set_short("%^RESET%^%^ORANGE%^Robe %^RED%^of the %^BOLD%^Blazing %^YELLOW%^Effigy%^RESET%^");
	set_obvious_short("A vibrant robe in shades of orange");
	set_long(
@AVATAR
These robes have to be some of the most intersting you have ever laid eyes on.  The robes are cut to be sleeveless and to fit close to the wearer's body.  The torso part of the robe is made from a very fine and sheer chiffon, blending perfectly to your  skin tone.  Sewn onto the chiffon are tendrils of flames in silk, making the robes far more modest than they would have been.  The appliques vary in size, some quite thin and small, while others are rather thick.  Each tendril of flame is made of one color, either %^ORANGE%^orange%^RESET%^, %^RED%^crimson%^RESET%^,%^BOLD%^%^RED%^ flame red%^RESET%^, or %^YELLOW%^yellow%^RESET%^.  From the waist, the appliques of flames overlap and trail down to the hem of the robe. 

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Flaming Effigy was made by the famed Kossuthian mage, Loren Detherquam, an invoker with a not-so-secret love of fire.  Some claim that Loren was a pyromaniac and delighted to set anything on fire.  Much like the flames he so revered, Loren's life was brief, violent, and destructive, but died out quickly after he set the Tharis, Darkwood, and the Meadowlands afire.  These robes have become the effigy that Loren's fires left behind.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^RED%^You slip out of the vibrant robes");
	return 1;
}
