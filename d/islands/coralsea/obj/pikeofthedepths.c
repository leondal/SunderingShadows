#include <std.h>
inherit "/d/common/obj/weapon/awlpike.c";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
	set_name("glowing polearm"); 
	set_id(({"polearm","pike","glowing pike","pike of the depths",
			"weapon"}));
	set_short("%^BOLD%^%^GREEN%^P%^WHITE%^i%^RESET%^%^GREEN%^k"+
		"%^BOLD%^e o%^RESET%^f %^BOLD%^%^GREEN%^t%^WHITE%^h"+
		"%^GREEN%^e D%^WHITE%^e%^RESET%^p%^GREEN%^t%^WHITE%^h"+
		"%^BOLD%^%^GREEN%^s%^RESET%^");  
	set_obvious_short("%^RESET%^%^GREEN%^a softly %^BOLD%^g"+
		"%^WHITE%^l%^RESET%^%^GREEN%^o%^WHITE%^w%^BOLD%^%^GREEN%^"+
		"i%^RESET%^%^GREEN%^n%^BOLD%^g %^RESET%^%^GREEN%^polearm"+
		"%^RESET%^");
	
	set_long("%^RESET%^%^GREEN%^The blade of this pike is formed "+
		"of a dark green metal that %^BOLD%^glows %^RESET%^"+
		"%^GREEN%^slightly along its sloping curve.  Beginning "+
		"with a sharp point, the blade widens into a spade before "+
		"blending into a pair of sharp %^RED%^serrated %^GREEN%^"+
		"tines that twist backward to rip and tear when the "+
		"weapon is withdrawn.  The blade is set upon a %^ORANGE%^"+
		"wooden shaft %^GREEN%^of thick white oak, which has had "+
		"a lump of the same green metal fastened to its base.  "+
		"Flat, this end cap gives the weapon balance and a way "+
		"to stand it up when at rest.  Running along the full "+
		"length of the shaft are numerous liquid looking markings "+
		"that %^BOLD%^glitter %^RESET%^%^GREEN%^with the same "+
		"faint green glow as the metal.%^RESET%^");
	
	set_value(300);
	set_property("enchantment",3);
		
	set_lore("Living on the outskirts of a small seaside village, "+
		"Errathea was the most beautiful of women.  Her hair was "+
		"fair, her eyes bright, her curves pleasing to the eye.  A "+
		"servant of Istishia, she worked her magic to bring large "+
		"catches for her people and to assure fair travel and "+
		"return.  Then a tribe of Orcish raiders attacked the "+
		"successful village, slaughtering and destroying all the "+
		"residents they could find.  Those that survived the "+
		"initial attack fled to Errathea for aid.  The sea witch, "+
		"fearing for her friends prayed to Istishia for guidance "+
		"in how to stop the orcs.  She awoke from that vision pale "+
		"and aged in years, transformed by the knowledge and magic "+
		"she had invoked.  She said nothing to the people who "+
		"huddled near, but instead motioned to a group of glowing "+
		"pikes that had appeared in the meditation room.  Then, "+
		"without another word, she walked into the sea.  The "+
		"villagers gathered the pikes, infused with all of "+
		"Errathea's power and destroyed every last orc.  Whatever "+
		"happened to Errathea is unknown.  Some claim that Istishia "+
		"called her home.  Others say that on lonely nights, when "+
		"the moon is low on the horizon, you can see her swimming "+
		"below the sea.");
	set_property("lore difficulty",15);
	
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	
	set_hit((:TO,"hit_function":));
}

int wieldme(){
	tell_object(ETO,"%^BOLD%^%^GREEN%^The whole polearm "+
		"begins to glow as you take firm hold of the shaft."+
		"%^RESET%^");
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^A burst of deep "+
		"green lights up the air as "+ETO->QCN+" takes hold of "+
		"their weapon.%^RESET%^");
	return 1;
}

int removeme(){
	tell_object(ETO,"%^BOLD%^%^GREEN%^The green light fades away "+
		"as you release your grip.%^RESET%^");
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+" "+
		"relaxes as they let go of their weapon.%^RESET%^");
	return 1;
}

int hit_function(object targ){
	if(random(1000) < 150) {
		switch(random(10)){
		
		case 0..2:
			tell_object(ETO,"%^RESET%^%^RED%^You drive the blade "+
				"of your pike into "+targ->QCN+", then yank it back "+
				"quickly tearing out a large hole!"+
				"");
			tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+" drives "+
				"the blade of their pike deep then pulls back, "+
				"ripping the pike free!%^RESET%^");
			tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" "+
				"pike is thrust deep into "+targ->QCN+"'s body, "+ 
				"ripping and tearing on the way out!%^RESET%^",
				({targ,ETO}));
			targ->do_damage("torso",random(8)+6);
		break;	
		
		case 3..8:
			tell_object(ETO,"%^RESET%^%^ORANGE%^You slice the pike's "+
				"sharp edge across "+targ->QCN+"'s skin!%^RESET%^");
			tell_object(targ,"%^RESET%^%^ORANGE%^You feel pain as"+
				" "+ETO->QCN+"'s pike slashes you!%^RESET%^");
			tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+targ->QCN+" "+
				"makes a startled cry as "+ETO->QCN+"'s pike slashes "+
				"their skin!%^RESET%^",({targ,ETO}));
			targ->do_damage("torso",random(8)+6);
		break;

		case 9..10:
			tell_object(ETO,"%^BOLD%^%^GREEN%^You spin suddenly and "+
				"bring the heavy base of the pike up against "+targ->QCN+
				"'s head with a loud %^RED%^crack%^GREEN%^!%^RESET%^");
			tell_object(targ,"%^BOLD%^%^GREEN%^You are knocked senseless "+
				"as "+ETO->QCN+" connects the heavy base of their "+
				"pike with your head! %^RED%^Crack!%^RESET%^");
			tell_room(environment(ETO),"There is a loud %^RED%^"+
				"CRACK%^GREEN%^ as "+ETO->QCN+" strikes "+targ->QCN+
				"with the heavy base of their pike!%^RESET%^",
				({targ,ETO}));
			targ->set_paralyzed(10,"%^BOLD%^%^GREEN%^You're trying to "+
				"recover your senses!%^RESET%^");
		break;			

		return 1;
		}
	}
}