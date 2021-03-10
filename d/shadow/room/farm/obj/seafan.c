#include <std.h>
inherit "/d/common/obj/weapon/fan.c";

void create()
{
   	::create();
   	set_name("electrum fan");
   	set_short("%^RESET%^%^CYAN%^S%^BOLD%^%^BLUE%^e%^CYAN%^a "+
		"%^RESET%^%^CYAN%^S%^BOLD%^%^BLUE%^p%^CYAN%^r%^RESET%^"+
		"%^CYAN%^a%^BOLD%^%^BLUE%^y %^CYAN%^Fan%^RESET%^");
   	set_obvious_short("%^RESET%^%^CYAN%^An electrum base fan%^RESET%^");
   	set_id(({"sea spray fan","fan","sea fan"}));
   	set_long("%^CYAN%^Crafted from a combination of %^BOLD%^%^BLUE%^blue"+
		" tinted%^RESET%^%^CYAN%^ electrum and lightweight silk, this "+
		"war fan has almost a delicate appearance.  The exterior base "+
		"of the fan is shaped from two sections of electrum.  Carved "+
		"into the electrum base are wave like shapes and inlaid with"+
		" %^BOLD%^%^WHITE%^white pearls%^RESET%^%^CYAN%^.  "+
		"The interior of"+
		" the fan features six %^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^"+
		" tinted electrum ribs that have been sharpened to fine points."+
		"  Lightweight silk in %^BOLD%^%^BLUE%^cerulean blue%^RESET%^%^CYAN%^"+
		" covers the ribs.  Painted with dyes onto the blue silk is the "+
		"image of a muscular %^RESET%^%^GREEN%^merman%^CYAN%^ and dainty "+
		"%^BOLD%^%^GREEN%^mermaid %^RESET%^%^CYAN%^forming a circle in the"+
		" center of the fan.\n%^RESET%^"); 
	set_lore("Stolen from an Istishian ranger by the name of Caladal, the"+
		" Fan of the Springs was thought lost for years.  The fan was "+
		"crafted for Caladal in honor of the completion of her Quest of"+
		" the Tides.  Caladal spent three years traveling across the"+
		" seas, searching in a quest for enlightenment.  It is said that at "+
		"each sacred spot she visited Caladal filled a crystal vial with"+
		" its waters.  Upon her return the vials of water were enchanted "+
		"to be houses within the Fan of the Springs. - As told by Jalium "+
		"Ombesk - Priest of Istishia");
   	set_property("lore difficulty",6);
   	set_value(150);
   	set_property("enchantment",1);
   	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
   	tell_room(EETO,"%^CYAN%^"+ETOQCN+" flicks "+ETO->QP+" wrist and"+
		" opens the fan.",ETO);
	tell_object(ETO,"%^CYAN%^You snap the fan open with a flick "+
		"of your wrist.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(EETO,"%^CYAN%^"+ETOQCN+" snaps "+ETO->QP+" fan closed.",ETO);
	tell_object(ETO,"%^CYAN%^You snap your fan closed with a flick of"+
		" your wrist.%^RESET%^");
	return 1;
}

int hit_func(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;
   if(!random(15)) {
      tell_object(ETO,"%^BOLD%^%^BLUE%^A blast of water shoots"+
		" out of your fan and into"+
      	" "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^%^BLUE%^A forceful blast of "+
		"water shoots of out "+ETO->QCN+"'s fan and into you.");
      tell_room(environment(ETO),"%^BOLD%^%^BLUE%^ A forceful blast"+
		" of water shoots out of "+ETO->QCN+"'s fan and into"+
      	" "+targ->QCN+".",({ETO,targ}));
      		return roll_dice(1,4)+4;
      return 1;
   }
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^CYAN%^In one fluid motion, "+
		"you slash into "+targ->QCN+" with the sharpened "+
		"edges of your fan.");
      tell_object(targ,"%^CYAN%^"+ETO->QCN+" moves in a fluid motion,"+
		" slicing into your flesh with "+ETO->QP+" fan.");
      tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" slices into "+
		""+targ->QCN+" in one fluid motion.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+2);
      return 1;
   }
}
