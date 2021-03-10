//mage_auppenser.c - reward for Riddle Quest. Circe 8/24/05
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("cyan robe edged in bronze");
	set_id(({"robe","cyan robe","robe of the inner eye"}));
	set_short("%^RESET%^%^CYAN%^Robes of the %^BOLD%^I%^RESET%^"+
         "%^CYAN%^n%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^r Eye%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a cyan robe edged "+
         "in %^ORANGE%^bronze%^RESET%^");
	set_long(
@CIRCE
%^RESET%^%^CYAN%^This simple cyan robe is made of thin cotton.  The robe is rather like a tabard, sleeveless and with the sides left open.  The outer edge is trimmed in %^ORANGE%^bronze%^CYAN%^, adding definition and a touch of elegance to the robe.  This garment is the type favored by monks for its ease of movement.  Men may often wear the robe over pants alone, while women always layer it over a shirt.  A braided %^ORANGE%^bronze cord %^CYAN%^may be cinched along the waist, holding the robe close to the body.  Centered on the chest is a fantastically embroidered %^BOLD%^%^BLUE%^stylized eye %^RESET%^%^CYAN%^atop a light %^ORANGE%^bronze background%^CYAN%^.%^RESET%^
CIRCE
	);
	set_lore(
@CIRCE
Robes of the Inner Eye are worn by many followers of the Enlightened One.  The bronze edging is thought to represent the reason that can shape one's mind, represented by the otherwise formless cyan cloth.  Through dedication and practice, followers of Auppenser believe they can broaden their minds, eventually reaching a state of enlightenment that will free them from their physical forms.  These robes are often worn by psions, monks, and even clerics, especially during holy days or ceremonies.  They are created by the monks who live within the temples.  These monks strive for absolute perfection in the creation of each robe, as they do in all things.
CIRCE
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^CYAN%^A hint of understanding tickles your mind before fading away as the robes leave your skin.");
	return 1;
}
