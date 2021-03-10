//Reward for Shar ranger - Cythera 4/05
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("shar hide");
	set_id(({"nightstalker hide","hide of the nightstalker","hide","black hide"}));
	set_short("%^BOLD%^%^BLACK%^Hide of the Nightstalker%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A black leather hide%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Shaped from the hide of a black "+
		"skinned creature, this leather armor almost seems as "+
		"if it soaks up the light.  The inky black scaled hide"+
		" has been stretched taunt over a boiled leather "+
		"breastplate.  The slick black scales of the hide "+
		"just barely reflect any light, making it extremely"+
		" difficult to separate them out.  The inside of the"+
		" black breastplate has been lined with black suede, "+
		"to cushion any blows. \n%^RESET%^");
	set_lore("The Nightstalkers are a band of rangers who"+
		" have dedicated themselves to Shar, Mistress of the"+
		" Night.  Traveling by the comforting cloak of night, "+
		"the Nightstalkers move swiftly in their hunt for those"+
		" who follow the eternal enemy of Shar, Selune.  With "+
		"their fearsome scimitars and stealth, the rangers have"+
		" quickly become one of the greatest successes in Shar's"+
		" faith.  In recent times the rangers have began to prey"+
		" on followers of Mystra.  Some speculate that Shar has "+
		"not forgotten which side Mystra choose in the Clash of "+
		"the Two Sister eons ago, and now is ready to show the "+
		"Lady of Mysteries her folly.");
   	set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You pull off the black scaled"+
		" hide armor and feel a sense of loss.");
	return 1;
}
