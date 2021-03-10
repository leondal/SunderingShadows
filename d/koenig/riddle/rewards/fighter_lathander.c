//fighter_lathander.c - reward for Riddle Quest. Circe 2/5/04
//Thanks to Torm for describing this item!
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("lathander hide");
	set_id(({"hide","armor","sunrise armor"}));
	set_short("%^RESET%^%^MAGENTA%^Su%^RED%^nri%^BOLD%^%^RED%^se Po%^YELLOW%^"+
         "urpo%^BOLD%^%^RED%^int A%^RESET%^%^RED%^rm%^MAGENTA%^or%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^Sunrise Armor%^RESET%^");
	set_long(
@CIRCE
%^MAGENTA%^This is a suit of leather armor that has been studded with an assortment of enamelled metal studs.  The studs have been colored in a variety of shades of rose, red and yellow and they have been secured to the leather in a particular pattern that forms a stylized image of a sunrise.%^RESET%^
CIRCE
	);
	set_lore(
@CIRCE
%^MAGENTA%^The image depicted on the armor is one that can be found in any number of Lathanderite temples across the realm.  Whilst no longer common, this style of armor was once very popular with members of Lathander's church.  The stylized image was copied from a famous peice of artwork commissioned by the church that depicted Lathander himself in a suit of armor with a sunrise emblazoned upon it which was formed of rose-quartz, rubies, topaz and diamonds.%^RESET%^
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^MAGENTA%^You check that none of the enamelled studs has been "+
         "chipped after you remove the armor.%^RESET%^");
}
