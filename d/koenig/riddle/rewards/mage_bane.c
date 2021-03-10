//mage_xvim.c - reward for Riddle Quest.
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the black hand");
	set_id(({ "robe", "robe of the black hand" }));
	set_short("%^BOLD%^%^RED%^Robe of the %^BLACK%^Black Hand%^RESET%^");
	set_obvious_short("A stunning black robe");
	set_long(
@CIRCE
%^RED%^This robe is made of thick, high quality %^BOLD%^%^BLACK%^black brocade %^RESET%^%^RED%^embroidered faintly with %^BOLD%^red %^RESET%^%^RED%^and %^GREEN%^green %^RED%^lines.  The thick robes hang close to the wearer's body, accenting his physique.  Wide bands of %^GREEN%^green silk %^RED%^line the row of %^BOLD%^%^RED%^ruby buttons %^RESET%^%^RED%^running down the front of the robe, while exquisite cufflinks of %^BOLD%^%^GREEN%^emeralds %^RESET%^%^RED%^fasten the sleeves.  Clearly, the robe was made for one of quality taste and quite a bit of status.%^RESET%^
CIRCE
	);
	set_lore(
@AVATAR
The Robes of the Black Hand are given out to select magi of the Dark One.  The Black Hand recognizes the usefulness of the magi and works to keep them within his fold the best he can, just as his priests are charged to do.  This has led to some major conflicts between the priests and the wizards as to just whom the Tyrant favors.  One reason, some sages say, that the Dark One is active about recruiting magi is that they tend to have a very short life span once they cross the line with the clerics.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^GREEN%^You slip out of the robe.");
	return 1;
}
