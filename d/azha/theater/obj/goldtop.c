#include <std.h>
inherit ARMOUR;

void create(){
    	::create();
      set_name("gold top");
      set_id(({ "top", "gold top" }));
      set_short("%^YELLOW%^Gold Top%^RESET%^");
      set_obvious_short("%^YELLOW%^Gold Top%^RESET%^");
      set_long( "%^YELLOW%^Crafted from gold, these tops leave"+
		" very little to one's imagination.  Gold chain "+
		"straps support the main section of the top.  The bottom"+
		" of the top features cut away sections that would support"+
		" and lift a woman's breasts up.  Twin golden swirls spiral"+
		" around to just barely cover the breasts of the wearer,"+
		" if that.  Golden disks hang from the bottom part of the"+
		" top, clinking together as the wearer moves.  This kind"+
		" of top would leave a woman very exposed!%^RESET%^\n");
      set_weight(5);
      set_value(500);
	set_cointype("electrum");
      set_lore( "Worn by the Cacophony Sirens, a top like this"+
		" no true lady would wear in public.  The top would lea"+
		"ve a woman VERY exposed, and no doubt earning her a"+
		"bad reputation.");
      set_property("lore difficulty",10);
      set_type("clothing");
      set_limbs(({ "torso" }));
      set_size(2);
	set_ac(0);
      set_property("enchantment",1);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
      tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" fasten"+
		"s the gold top in place, leaving "+ETO->QO+" VERY"+
		" exposed.",ETO);
      tell_object(ETO,"%^YELLOW%^You feel a cold draft again"+
		"st your chest as you expose yourself brazenly."+
		"%^RED%^ What a Hussy you are!");
     	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" takes"+
		" off "+ETO->QP+" top, not that it left anything to the"+
		" imagination.",ETO);
      tell_object(ETO,"%^YELLOW%^You take off the gold top,"+
		" not that it covered anything.");
        return 1;
}
