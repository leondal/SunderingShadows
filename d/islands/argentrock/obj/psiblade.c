#include <std.h>
inherit "/d/common/obj/weapon/knife.c";

void create(){
	::create();
	set_name("psitouched blade");
	set_short("%^BOLD%^%^MAGENTA%^P%^RESET%^%^MAGENTA%^s%^BOLD%^i"+
		"%^RESET%^%^MAGENTA%^t%^BOLD%^o%^RESET%^%^MAGENTA%^u"+
		"%^BOLD%^c%^RESET%^%^MAGENTA%^h%^BOLD%^e%^RESET%^"+
		"%^MAGENTA%^d %^BOLD%^Blade%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^A g%^RESET%^%^MAGENTA%^l"+
		"%^BOLD%^o%^RESET%^%^MAGENTA%^w%^BOLD%^i%^RESET%^"+
		"%^MAGENTA%^n%^BOLD%^g knife%^RESET%^");
	set_id(({"knife","psitouched blade","blade","dagger"}));
	set_long("%^RESET%^%^MAGENTA%^This thick knife is bathed in "+
		"a %^BOLD%^%^MAGENTA%^soft glow%^RESET%^%^MAGENTA%^.  "+
		"The material used to craft the knife is difficult to "+
		"discern, due to strong glow that constantly surrounds "+
		"the blade.  It appears to have to strength of steel but"+
		" the weight of mithril.  The thick blade is pressed thin,"+
		" allowing it to easily slip into vulnerable areas. "+
		"Tappering to a narrow point, both edges of the blade "+
		"have been given a %^BOLD%^%^WHITE%^keen%^RESET%^"+
		"%^MAGENTA%^ edge.%^RESET%^");
	set_lore("The Psitouched Blade no one is sure how it feel into "+
		"the hands of the fey'ri.  Some claim that the weapon came"+
		" from deep within the Tsarven Empire, stolen by the house "+
            "of Heasirretyn prior to their flight from those lands."+
		"  Others whisper that the blade is actually of elven origin,"+
		" a testing in an old and ancient branch of magic that the "+
		"elves gave up on due to the difficulties their minds had.  "+
		"Others wonder if one of Batlin's random portals around the "+
		"island of Argentrock drew in the githyanki, claming this "+
		"blade is of Astral Plane origins.  If anyone knows the "+
		"truth, it would be the fey'ri, but they so far don't seem"+
		" to be open to questions.");
	set_property("lore",30);
	set_property("enchantment",4);
      set_item_bonus("magic resistance",1);
	set_hit((:TO, "hitme":));
	set_value(2000);
	set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
}

int wield_func(string str) {
   if((int)ETO->query_lowest_level() < 25) {
      	tell_object(ETO,"%^BOLD%^%^MAGENTA%^The blade refuses you!");
     	return 0;
	}
   		tell_object(ETO,"%^BOLD%^%^MAGENTA%^The glow around the blade"+
			" intensifys you grasp onto it.");
                  return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^%^MAGENTA%^The glow around the blade seems"+
		" less intense as you release your hold of the blade.");
                return 1;
}

int hitme(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 300){
	  switch(random(36)){
	     case 0..26:
		tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^%^"+ETO->QCN+"'s"+
			" blade phases into an ethereal substance as "+ETO->QS+" "+
			"plunges it into "+targ->QCN+".",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^MAGENTA%^The blade phases into an "+
			"ethereal substance as you plunge it into "+targ->QCN+".");
		tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETO->QCN+"'s blade phases"+
			" into an ethereal substance as "+ETO->QS+" plunges "+
			"it into you.");
				set_property("magic",1);
				targ->do_damage("torso",random(10)+5);
			// was remove_property, changed to properly be set -1 *Styx* 12/05
				set_property("magic", -1);
		break;
	     case 27..31:
		tell_room(environment(ETO),"%^MAGENTA%^"+ETO->QCN+"'s "+
			"blade %^BOLD%^glows%^RESET%^%^MAGENTA%^ intensly"+
                        " as "+ETO->QS+" thrusts it into "+targ->QCN+"'s "+
			"head.",({ETO,targ}));
		tell_object(ETO,"%^MAGENTA%^You feel the blade start to "+
			"draw on hidden parts of your mind as it glows "+
			"intensly.  Feeling the blade and your mind "+
			"focused as one, you thrust the blade into"+
			" "+targ->QCN+"'s head.");
		tell_object(targ,"%^MAGENTA%^"+ETO->QCN+"'s blade "+
			"%^BOLD%^glows%^RESET%^%^MAGENTA%^ intensly "+
			"as "+ETO->QS+" thrusts it into your head.\n"+
			"%^BOLD%^%^MAGENTA%^You feel the blade piercing"+
			" through your mind!");
    new("/cmds/spells/m/_mind_thrust")->use_spell(ETO,targ,15,100,"psion");
		break;
	     case 32..35:
		tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->QCN+" "+
			"circles around "+targ->QCN+" and plunges "
			""+ETO->QP+" glowing blade into the base of"
                        " "+targ->QCN+"'s skull.",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^MAGENTA%^Your circle around"+
			" "+targ->QCN+" and plunge your glowing blade "+
			"into the base of "+targ->QP+" skull.");
		tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETO->QCN+" "+
			"circles around you and plunges "+ETO->QP+" "+
			"blade into your skull.\n%^RESET%^%^MAGENTA%^"+
			"Your mind and body freeze up!");
			targ->set_paralyzed((random(4)+1),"%^MAGENTA%^Your mind and body are paralyzed!");
		break;
	    default:  tell_object(ETO,"Well now you've done it! :) Please bug"+
		" this and include what you were doing/fighting when you got"+
		" this message.");
		break;
	}
    return 1;
    }
}
