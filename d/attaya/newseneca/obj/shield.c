#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create() {
        ::create();
        set_name("sphinx shield");
        set_id(({"shield","sphinx shield","gibbering"}));
        set_obvious_short("%^BLUE%^B%^BOLD%^l%^RESET%^%^BLUE%^ue K%^BOLD%^i%^RESET%^%^BLUE%^te Sh%^BOLD%^i%^RESET%^%^BLUE%^eld%^RESET%^");
        set_short("%^BOLD%^%^BLUE%^Sh%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^eld of the b%^RESET%^%^BLUE%^al%^BOLD%^%^%^BLUE%^anced hand%^RESET%^");
        set_long("%^CYAN%^This is a large %^RESET%^silver%^CYAN%^ kite "+
		"shield painted %^BLUE%^blue%^CYAN%^ and trimmed along "+
		"the edged with %^BLUE%^blue diamonds%^CYAN%^.  There is"+
		" a iron sphinx mounted to the front of "+
		"the shield.  It is colored %^RESET%^white%^CYAN%^ with "+
		"several amethyst gems for eyes.  The "+
		"shield has a handle on the back for "+
		"one to grab with their hand and a "+
		"leather strap for one to place their arm through.");
        set_lore("This shield is an trophy of Tyr."+
		"  It is given to the most respected of Tyr's"+
		" Hammers of Grimjaw.  Receiving one from "+
		"the clergy is considered a great honor "+
		"to any knight of Tyr.  Someone must battle"+
		" against evil and untruth with great success to be honored in such a way.");
        set_property("lore",20);
        set_struck((:TO,"strikeme":));
        set_wear((:TO,"wearme":));
		set_remove((:TO,"remove_func":));
        set_value(1500);
        set_property("enchantment",4);
	set_item_bonus("charisma",1);
}
int strikeme(int damage, object what, object who){
        tell_object(EETO,"%^CYAN%^An ethereal sphinx head lunges at "
		       +who->QCN+" from "+ETO->QCN+"'s shield.",({who,ETO}));
        tell_object(who,"%^CYAN%^You strike "+ETO->QCN+"'s shield "+
                "and an ethereal head of a sphinx leaps "+
				"from the shield, biting into the offending limb.");
        tell_room(ETO,"%^CYAN%^Your shield bites "+who->QCN+" limb.");
  
  who->do_damage("torso",random(6)+12);
  return (-1)*(damage/2);
}
int remove_func(){
        ETO->set_property("good item",-1);
        tell_room(environment(ETO),"%^CYAN%^As "+ETOQCN+
        " removes "+ETO->QP+" shield they look less noble.",ETO);
        tell_object(ETO,"%^CYAN%^You remove your"+
                " shield and feel a little less epic.");
         return 1;
}
int wearme(){
        ETO->set_property("good item",1);
        write("%^CYAN%^You don the shield and feel like a %^BOLD%^just knight.");
        say("%^CYAN%^"+ETO->QCN+"'s shield makes him look holy.");
  return 1;
}
