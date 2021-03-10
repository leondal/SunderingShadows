//mage_tymora.c - reward for Riddle Quest.
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("overcoat");
	set_id(({ "overcoat", "coat", "overcoat of good fortune" }));
	set_short("%^BOLD%^%^BLUE%^Overcoat of %^BLUE%^"+
         "Fo%^WHITE%^rt%^BLUE%^u%^WHITE%^n%^BLUE%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^A deep blue leather overcoat%^RESET%^");
	set_long(
@CIRCE
%^BOLD%^%^BLUE%^This long overcoat is fashioned of %^RESET%^%^BLUE%^midnight blue leather %^BOLD%^that is supple to the touch.  The coat reaches the wearer's knees, ending there in tails.  The smooth, sleek lines of the coat hug the wearer's waist, giving him a trim appearance.  The front of the coat is worn open, fastened only by a %^YELLOW%^gold braid frog %^BLUE%^that stretches across the chest.  The wide, pointed collar reaches near the wearer's chin, and the jacket has been edged in %^YELLOW%^gold braid%^BLUE%^.  The long sleeves end in folded cuffs, leaving the wearer's hands free.%^RESET%^

CIRCE
	);
	set_lore(
@CIRCE
The Overcoat of Fortune was made by a magess of Tymora.  Purdence Imigoran was dedicated to the service of the Lady of Luck some three or four centuries ago.  Prudence, or Purdy as she liked to be called, was not the most competent mage many would say.  Her spells often went wild when she was casting them.  Purdy always claimed that it was the grace of Tymora that her spells even operated.  There are a few tales of how Purdy would try to cast one spell and only end up creating something entirely different.  Still to this day many of the more academic magi use her as an example of how NOT to act with their Art.

CIRCE
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" pulls "+ETO->QO+"self "+
         "free of the overcoat.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You slip off the overcoat and "+
         "can't help but hope that your %^WHITE%^luck%^BLUE%^ will hold.");
	return 1;
}
