#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/spear_sm.c";

void create()
{
	::create();
	set_name("moonstone spear");
	set_id(({"spear","sprite spear","small spear","atomie spear","little spear","moonstone spear"}));
	set_obvious_short("%^BOLD%^%^WHITE%^A silver small spear%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Moonstone Spear%^RESET%^");
	set_long("%^CYAN%^Mounted on a glittering %^WHITE%^%^BOLD%^silver"+
		"%^RESET%^%^CYAN%^ shaft is a sharpened diamond shaped"+
		" %^BOLD%^%^WHITE%^moonstone%^RESET%^%^CYAN%^ spearhead."+
		"  The opaque moonstone is a milky shade of white, as "+
		"typical with most varieties of moonstone.  Etched into"+
		" the spearhead is the relief image of a crescent moon "+
		"wraped with ivy.  The slender silver spear shaft has an"+
		" obvious %^BLUE%^blue%^CYAN%^ cast to it.  The silver is"+
		" shaped and manipulated to create a vine like raised pattern"+
		" up the shaft, where it spirals around the spearhead."); 
	set_lore("The Moonstone Spear is a faerie made weapon.  Like the "+
		"elves, the Faerie Court has a deep revere for nature and "+
		"magic.  Unlike the elves though, the faeries are able to "+
		"spend their time in peace and solitude working on their art"+
		" and gifts.  Natural themes have a way of popping up in fey art."+
		"  The Moonstone Spear was crafted to allow these normally peaceful"+
		" folk aid in the protection of their beloved valley.");
	set_property("lore",10);
	//set_size(1);
	//set_wc(1,4);
	//set_large_wc(1,6);
	//set_type("pierce");
	set_weight(3);
	set_value(240);
	set_cointype("silver");
	//set_prof_type("small spear");
	set_property("enchantment",2);
	set_wield((:TO,"wieldme":));
	set_hit((:TO,"hitme":));
}

int wieldme()
{
	if(ETO->query_level() < 10) {
		tell_object(ETO,"You are not adept enough to use such a fine weapon.");
		return 0;
	}
	else {
		return 1;
	}
}

int hitme(object targ)
{
	if(!objectp(targ)) return 1;
	

	if(!random(8)) {
		tell_object(ETO,"%^BOLD%^%^CYAN%^You lash out with your"+
		" spear and manage to catch "+targ->QCN+""+
		" off guard!");
		tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
		" lashes out with "+ETO->QP+" spear"+
		" lightning fast, catching "+targ->QCN+""+
		" off guard!",({ETO,targ}));
		tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+""+
		" lashes out with "+ETO->QP+" spear in a"+
		" lightning quick motion, scoring a hit on you!");
		targ->do_damage("torso",random(6)+1);
		return 1;
	}
	if(!random(18)) {
		tell_object(ETO,"%^BOLD%^The spear seems to emit a"+
		" strange humming sound, as you strike "+targ->QCN+""+
		" a deafening noise is heard and the spear seems to go"+
		" right through "+targ->QP+" armor!");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s"+
		" spear begins to hum strangely, as "+ETO->QS+""+
		" strikes "+targ->QCN+" a deafening noise"+
		" is heard and the spear seems to pierce right through"+
		" "+targ->QP+" armor!",({ETO,targ}));
		tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s"+
		" spear begins to emit a strange humming sound, as"+
		" "+ETO->QS+" strikes you there is a"+
		" deafening noise and "+ETO->QP+" spear"+
		" pierces right through your armor!");
		targ->do_damage("torso",random(8)+2);
		return 1;
	}
	if(!random(30)) {
		tell_object(ETO,"%^BOLD%^%^BLUE%^You throw your spear at"+
		" "+targ->QCN+"! In"+
		" the air the tiny spear becomes a bolt of "+
		"%^BOLD%^%^WHITE%^moonlight%^BLUE%^ and slams"+
		" into "+targ->QO+", then the spear is"+
		" somehow back in your hands once more.");
		tell_room(environment(ETO),"%^BOLD%^BLUE%^%^"+ETO->QCN+""+
		" throws "+ETO->QP+" spear at "+targ->QCN+"."+
		" In mid-air the spear transforms into a bolt of"+
		" %^BOLD%^%^WHITE%^moonlight%^BLUE%^ and"+
		" slams into "+targ->QO+" forcefully!"+
		" Somehow the spear returns to "+ETO->QCN+"'s"+
		" hand.",({ETO,targ}));
		tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+""+
		" throws "+ETO->QP+" spear at you,"+
		" but in the air it changes into a "+
		"bolt of %^WHITE%^moonlight%^BLUE%^ that blasts"+
		" into you! When you recover from the bolt, you notice"+
		" that the spear is somehow back in "+ETO->QP+""+
		" hands again.");
		targ->do_damage("torso",random(10)+5);
		return 1;
	}
}
