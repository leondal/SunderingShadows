//Reward for Malar ranger - Cythera 4/05
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("malar hide");
	set_id(({"owlbear hide","hide of the owlbear","hide","feathered hide"}));
	set_short("%^BOLD%^%^WHITE%^Owlbear Hide%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A white feathered hide%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Shaped from the hide of an owlbear,"+
		" this suit of armor has a ferocious look to it.  The "+
		"white feathered hide of the owlbear has been stretched"+
		" across a boiled leather base.  Some of the feathers "+
		"features dried %^RED%^bloodstains%^WHITE%^, giving "+
		"this suit of hide a wild and savage look.  The "+
		"%^YELLOW%^golden%^WHITE%^ colored beak of the "+
		"owlbear is attached to the shoulders of the "+
		"hide, adding to its untamed look.  \n%^RESET%^");
	set_lore("Owlbears have always been revered in Malar's"+
		" faith.  They are one of the prime examples of what"+
		" a predator should be.  So it is no surprise that "+
		"the Owlbears of the Forest adopted their name from "+
		"these massive bloodthirsty creatures.  The Owlbears "+
		"of the Forest are a band of rangers devoted to the "+
		"crueler side of nature.  Believing that nature should"+
		" be feared for their savage nature and bloodthirstiness,"+
		" the rangers come in direct opposition with the Needles"+
		" of the Forest, Mielikki's rangers.  The two orders have"+
		" clashed for ages across the landscape of the forest.");
   	set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^RED%^The thrill of the hunt leaves you as you pull of the hide.");
	return 1;
}
