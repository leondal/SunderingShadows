//ranger_lathander.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("lathander hide");
	set_id(({"hide","snakeskin armor","golden snakeskin","snakeskin","skin","gold skin","golden skin"}));
	set_short("%^YELLOW%^Armor of the %^MAGENTA%^Rising Sun%^RESET%^");
	set_obvious_short("Shimmering snakeskin armor");
	set_long(
@CIRCE
%^YELLOW%^This armor appears to be the hide of some great golden serpent.  The scales ripple and reflect the light of the %^MAGENTA%^sun%^YELLOW%^, seeming to form a separate sunrise in each tiny scale.  When worn in sunlight, the armor is almost blindingly bright, but it seems to blend well into the shadows of the wilderness as well, hiding the wearer quite effectively.  Attached to the shoulders are two long, flowing %^RED%^f%^RESET%^%^RED%^e%^MAGENTA%^a%^BOLD%^t%^YELLOW%^h%^RESET%^%^ORANGE%^e%^RED%^r%^BOLD%^s %^YELLOW%^of a %^MAGENTA%^sun peacock%^YELLOW%^, which end just before the wearer's knees.
CIRCE
	);
	set_lore(
@CIRCE
Although more flamboyant than the armor worn by many wanderers in the wild, this glittering golden armor is perfect for the followers of the Morninglord.  The snakeskin fits well, showing off the wearer's physique.  Despite the way the scales reflect light, the armor seems capable of hiding the wearer in the forests, a property many attribute to the creation of this armor.  The process is long since forgotten, but relics such as this one that belong to an older age can still be found from time to time.  These suits of armor were once awarded to the most dedicated followers of Lathander, and anyone lucky enough to wear such a fine suit is considered blessed within the faith of Lathander.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You bask in the warmth of the sun before slipping out of the snakeskin.");
	return 1;
}
