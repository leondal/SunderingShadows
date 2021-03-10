#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create()
{
   	::create();
   	set_name("steel plated glove");
   	set_short("%^RESET%^%^ORANGE%^Gnomish %^CYAN%^Backscratcher%^RESET%^");
   	set_obvious_short("%^RESET%^%^ORANGE%^A steel plated leather glove%^RESET%^");
   	set_id(({"claw","claws","glove","leather glove","gnomish backscratcher"}));
   	set_long("%^ORANGE%^Stitched from dark brown leather strips, this glove"+
		" looks well used and weathered.  The creased leather around the"+
		" fingers and palm takes on a %^YELLOW%^lighter%^RESET%^%^ORANGE%^"+
		" hue.  Three %^CYAN%^steel%^ORANGE%^ metal plates have been "+
		"riveted to the back of the glove.  The metal plates are "+
		"actually small box shapes which seem to house some kind "+
		"of gears.  Four small %^BOLD%^%^BLACK%^black hoses"+
		"%^RESET%^%^ORANGE%^ come out of each steel "+
		"box and connect to the next one.  From the top most box "+
		"(across the knuckles), four similar black hoses rise up "+
		"to the fingers.  The fingers of the gloves have been capped"+
		" with %^CYAN%^steel tips%^ORANGE%^, each cap is ridden with"+
		" numerous small needle sized holes.  The caps taper to "+
		"point at the apex of each finger.  The glove has a "+
		"distinct gnomish touch to it.  \n%^RESET%^"); 
	set_lore("The story as Piaf tells me, was that one day he "+
		"had an itch so bad that it drove him mad.  Finding the"+
		" willpower to work on a new creation that would allow "+
		"him to scratch his back, Piaf created the dreaded Gnomish"+
		" Backscratcher.  EXTREME warning is to be had when using "+
		"this device, as there have been many reports of serious "+
		"burns and scars as a result of using this to scratch your"+
		" or anyone's back. -An Observation of Piaf - Theadora "+
		"Illonium");
   	set_property("lore difficulty",6);
   	set_value(75);
   	set_property("enchantment",1);
   	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
   	tell_room(EETO,"%^ORANGE%^"+ETOQCN+" slide "+ETO->QP+" hand into a "+
		"strange glove.",ETO);
	tell_object(ETO,"%^ORANGE%^You slide your hand into the weighty glove.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(EETO,"%^CYAN%^"+ETOQCN+" pulls "+ETO->QP+" hand out"+
		" of a strange glove.",ETO);
	tell_object(ETO,"%^CYAN%^You pull your hand out of the strange glove.");
	return 1;
}

int hit_func(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;
   if(!random(15)) {
      tell_object(ETO,"%^ORANGE%^Hot oil shoots out of the tip of "+
		""+ETOQCN+"'s glove and into"+
      	" "+targ->QCN+"'s face.");
      tell_object(targ,"%^ORANGE%^Hot oil shoots into your face from"+
		" the tips of "+ETO->QCN+"'s glove.");
      tell_room(environment(ETO),"%^ORANGE%^Hot oil shoots out of the tip of "+
		""+ETOQCN+"'s glove and into "+
      	" "+targ->QCN+"'s face.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      return 1;
   }
   if(!random(8)) {
      tell_object(ETO,"%^CYAN%^You feel the steel boxes begin to "+
		"vibrate as steam moves through the hoses.  "+
		"Your glove vibrates wildly just as you strike "+targ->QCN+".");
      tell_object(targ,"%^CYAN%^"+ETO->QCN+"'s glove begins to vibrate wildly"+
		" as steam rises from it.  You feel yourself shaken a bit by that blow.");
      tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+"'s glove begins to"+
		" vibrate widly as steam rises from it. "+
		""+targ->QCN+" shakes a bit from the vibrations of "+
		""+ETOQCN+"'s blow.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+2);
      return 1;
   }
}
