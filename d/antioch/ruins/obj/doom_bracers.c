// str bonus changed to work on new stat system. Nienne, 09/07.
#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/bracers";

void create() {
    	::create();
    	set_name("Bracers of Doom");
    	set_obvious_short("A pair of black bracers");
    	set_short("%^BOLD%^%^BLACK%^B%^RESET%^r%^BOLD%^%^BLACK%^a"+
		"%^RESET%^c%^BOLD%^%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^"+
                "s of %^BOLD%^%^BLACK%^D%^RESET%^o%^BOLD%^%^BLACK%^o%^RESET%^m");
    	set_id(({"bracers","bracers of doom","Bracers of Doom","doom bracers"}));
	set_long("%^BOLD%^%^BLACK%^A set of high quality bracers. They "+
		"look to be well cared for and seem lighter than their heft"+
		" would indicate.  These bracers have an echo of absolute "+
		"power about them that is very"+
    		" tempting, yet also rather daunting. %^WHITE%^R%^RED%^u"+
		"%^WHITE%^n%^RED%^e%^WHITE%^s%^BLACK%^ are etched into the"+
    		" black-%^RESET%^grey%^BOLD%^%^BLACK%^ metal that the "+
		"bracers are made of, constantly moving about. The bracers"+
		" themselves are excellently crafted, slender spirals"+
    		" of metal extend from the main part of the bracers in a delicate and"+
    		" intricate pattern.");
	set_lore("Originally forged from mithril, the Bracers of Doom"+
		" are rumored to have been created by a wizard by the name"+
		" of Humarias Jluna.  Further research on Humarias has only"+
		" turned up that he seems to have been a member of the Church"+
		" of the Night.  Through some of the journals I have managed "+
		"to find some of Humarias' rivals claim that his arcane power"+
		" worked in different means than their own.  Humarias it seems"+
		" was able to shape the weave in ways no mage ever dreamed of."+
		"  Carrying the title of Weaver of Shadows, Humarias it is said"+
		" was vocally opposed to the 'hypocritical' Church of Mystra."+
		"  No one is quite sure how he created these infamous bracers, "+
		"as what little knowledge there is of the Weaver of Shadows is "+
		"hard and difficult to locate. - An Apprentice's Guide to Famous"+
		" Wizards - Hedwig Bigsbee");
	set_property("lore",15);
    	set_value(3000);
      set_property("enchantment",3);
	set_item_bonus("strength",-1);
	set_item_bonus("magic resistance",2);
   	set_wear((:TO,"wearme":));
   	set_remove((:TO,"removeme":));
}

int wearme(){
   ::check();
//    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("thief") || TP->is_class("ranger") || TP->is_class("psion") || query_ac() <= 0) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^Your body is wracked in pain as you"+
        " slip the bracers on.");
        tell_room(environment(ETO),""+ETO->QCN+" doubles over in"+
        " pain as "+ETO->QS+" slips on "+ETO->QP+""+
        " bracers.",ETO);
        set_property("magic",1);
        ETO->do_damage("torso",random(20)+10);
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ETO->remove_attacker(TO);
        remove_property("magic");
        return 1;
}

int removeme() {
    tell_object(ETO,"A great weight seems lifted from your shoulders as you remove the bracers.");
    tell_room(environment(ETO),""+ETO->QCN+" seems to be relieved"+
    " to remove "+ETO->QP+" bracers.",ETO);
    return 1;
}
