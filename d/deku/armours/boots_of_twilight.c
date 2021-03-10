#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/clothing/shoes";

int flag;

void init() {
  ::init();
    if(interactive(ETO)) 
    {
        TO->add_item_owner(ETOQN);
    }
}

void create(){
  ::create();
    set_name("boots");
    set_id(({ "boots","light blue boots","blue boots",
    "twilight boots","drakkans boots","twilights blessing",
    "blessing"}));
    
    set_short("%^BOLD%^%^WHITE%^T%^CYAN%^w%^BOLD%^%^WHITE%^"+
    "i%^CYAN%^l%^BOLD%^%^WHITE%^i%^CYAN%^g%^BOLD%^%^WHITE%^h"+
    "%^CYAN%^t%^BOLD%^%^WHITE%^'s ble%^CYAN%^ss%^BOLD%^%^WHITE%^"+
    "ing%^RESET%^");
    set_obvious_short("%^BOLD%^%^CYAN%^A pair of light blue boots%^RESET%^");

    
    set_long("%^BOLD%^%^WHITE%^These boots are made from a "+
    "thick and heavy leather.  The color and texture of the leather "+
    "is vastly different than what is common.  The hue is a mixture "+
    "of %^CYAN%^light blue%^BOLD%^%^WHITE%^ with a brilliant white "+
    "that has a faint tinge of %^BOLD%^%^BLACK%^blackness%^BOLD%^%^WHITE%^"+
    ".  The texture of the leather is almost completely smooth "+
    "with what feels and looks like %^BLUE%^tiny ripples%^BOLD%^"+
    "%^WHITE%^ continually moving across its surface.  The sturdy "+
    "boots are short, reaching only slightly above the ankles of "+
    "the wearer.  The soles of the boots are made from a "+
    "%^BOLD%^%^BLACK%^darker %^BOLD%^%^WHITE%^and much thinner "+
    "leather.%^RESET%^");

    set_lore("Created by a expert tailor and then blessed by his "+
    "bride for many members of their family, these boots are said "+
    "to possess a soothing and healing quality that only "+
    "activates at a certain time of day.  The lady who blessed "+
    "them was renown as the mistress of twilight, so the guess "+
    "as to what time of day their blessing makes itself known "+
    "has never been a difficult one to get right.");
    
    set_value(1000);   
    set_size(-1);
    set_wear((:TO,"wear_func":));
    set_property("enchantment",3);
	set_item_bonus("damage resistance",5);
	set_item_bonus("sight bonus",2);
    set_heart_beat(1);
    set_remove("%^CYAN%^You pull your feet from the boots.%^RESET%^");
}

void heart_beat() {
    if(!objectp(TO) || !objectp(ETO)) return;
    if((string)EVENTS_D->query_time_of_day() == "twilight" 
    && TO->query_worn()) {
        if(ETO->query_hp() < ETO->query_max_hp()) {
            if(!random(12)) {
                ETO->add_hp(15 + random(6));
                tell_object(ETO,"A sudden pleasurable %^BLUE%^warmth "+
                "%^RESET%^comes from the boots and offers your body "+
                "needed nourishment.%^RESET%^");
                return;
            }
        }
    }
}

int wear_func() {
	if((int)ETO->query_highest_level() < 15)
	{
		tell_object(ETO, "%^CYAN%^Your power is not strong enough to "+
		"control these boots.");
		return 0;
	}
	if(!TO->query_owns_item(ETOQN) && interactive(ETO)) 
	{	
		tell_object(ETO,"%^CYAN%^The boots don't fit you!%^RESET%^");
	      return 0;
	}
	tell_object(ETO,"%^CYAN%^A soothing warmth envelopes you."+
	"%^RESET%^");
	return 1;
}
