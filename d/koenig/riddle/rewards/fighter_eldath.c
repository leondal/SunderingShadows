//fighter_eldath.c - reward for Riddle Quest. Circe 2/5/04
//Thanks to Torm for describing this item!
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("eldath hide");
	set_id(({"hide","leather","netted leather","armor"}));
	set_short("%^RESET%^%^ORANGE%^N%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^tte"+
         "%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^ Le%^BOLD%^%^WHITE%^a%^RESET%^"+
         "%^ORANGE%^th%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Netted Leather%^RESET%^");
	set_long(
@CIRCE
%^ORANGE%^This is re-inforced leather armor.  A th%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^n me%^BOLD%^%^WHITE%^t%^RESET%^%^ORANGE%^al m%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^sh ma%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^e of %^BOLD%^%^WHITE%^m%^RESET%^%^ORANGE%^ithril has been overlayed on the leather, forming a protective outer net for the wearer.  The net has been secured to the leather which is clearly visible beneath it and it is flexible enough to not impede the wearer's movement.
CIRCE
	);
	set_lore(
@CIRCE
%^RESET%^%^ORANGE%^Attributed to an Eldathian armorsmith, this design encapsulates his vision of harmonious balance in all things.  The Eldathian preference for the net as a weapon which can incapacitate without injury inspired the use of a net to aid protection also.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^RESET%^%^ORANGE%^You fold the netted leather armor up neatly%^RESET%^");
}
