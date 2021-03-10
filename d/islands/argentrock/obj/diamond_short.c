//Based on Crystal's Diamond Cutlass
#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create(){
	::create();
	set_name("gladius of the diamond dragon");
	set_short("%^BOLD%^%^WHITE%^Gladius of the Dia%^CYAN%^"+
		"m%^WHITE%^ond Dragon%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A diamond gladius%^RESET%^");
	set_id(({"sword","gladius","gladius of the diamond"+
		" dragon","diamond sword","diamdond gladius"}));
	set_long("%^BOLD%^The sword seems to be made from one piece "+
		"of dia%^CYAN%^m%^WHITE%^ond, even the hilt is part of"+
		" this magnificent gladius. The edges of the blade are"+
		" wickedly sharp, no normal armor could withstand a blow"+
		" from that! In the center of the hilt there is"+
		" a carving of a serpentine dragon.");
	set_lore("The Gladius of the Diamond Dragon was once forged"+
		" for halfling by the name of Juniper Leemond.  Juniper"+
		" was a mischevious little fellow who delighted in causing"+
		" trouble and playing pranks.  Even with his jovial nature,"+
		" Juniper was a very brave warrior who once fought to defend"+
		" a halfling settlement from a raid by drow.  Though many of"+
		" the drow escaped that night, Juniper managed to take down"+
		" seven on his own, including a drow priestess.  In honor of"+
		" his feat, the halflings in the village called in a favor "+
		"that a gnome wizard had owed their people, thus the sword "+
		"was born.  As Juniper travelled the lands, joining and "+
		"leaving numerous adventuring companies, he found his "+
		"fair share of adventures and treasure.  Strike a "+
		"friendship up with a half-elven wizard on one adventure "+
		"to slay a green dragon, Juniper paid for the enchantments that "+
		"were added to his favorite blade.  Sadly, none in the "+
		"company returned from their mission to slay the purple worm.");
	set_property("enchantment",4);
	set_hit((:TO, "hitme":));
       set_value(2000);
     set_wield((:TO,"wield_func":));
   	set_unwield((:TO,"unwield_func":));
        set_property("repairtype",({"weaponsmith", "jeweller"}));
}
int wield_func(string str) {
     if((int)ETO->query_level() < 30) {
      	tell_object(ETO,"%^BOLD%^%^WHITE%^The gladius resists your grasp!");
     	return 0;
	}
   		tell_object(ETO,"%^BOLD%^Light glimmers off the diamond body"+
			" of the gladius.\nThe image of the dragon slithers "+
			"around in response to your touch.");
     	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^BOLD%^The image of the dragon slithers in a "+
		"counter-clockwise manner as you release your hold of the"+
		" gladius.");
     	return 1;
}

int hitme(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 220){
      switch(random(36)){
	case 0..20:
		tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+""+
			" lets out a battle cry and swings "+ETO->QP+" blade"+
			" down, slicing into "+targ->QCN+".",({ETO,targ}));
		tell_object(ETO,"%^CYAN%^You shout out a battle cry and swing"+
			" your blade down, slicing deeply into "+targ->QCN+".");
		tell_object(targ,"%^CYAN%^"+ETO->QCN+" lets out"+
			" a battle cry and swings "+ETO->QP+" blade down,"+
			" slicing deeply into your flesh.");
			targ->do_damage("torso",random(8)+5);
		break;
	case 21..31:
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
			" gets a burst of speed and dodges under"+
			" "+targ->QCN+"'s guard, slamming the hilt of"+
			" "+ETO->QP+" gladius hard into "+targ->QP+""+
			" chest.",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^You get a burst of speed and dodge"+
			" under "+targ->QCN+"'s guard, slamming the"+
			" hilt of your gladius hard into "+targ->QP+""+
			" chest.");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+" speeds"+
			" up suddenly and dodges under your guard, "+
			"slamming the hilt of "+ETO->QP+" gladius "+
			"hard into your chest.");
			      ETO->execute_attack();

		break;
	case 32..35:
		tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
			"'s diamond gladius glows brightly as "+ETO->QS+" "+
			"tears into "+targ->QCN+"'s "+
			" chest.",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^CYAN%^Your gladius glows with "+
                        "a bright light as you tear into "+targ->QP+" chest.");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s diamond gladius"+
			" glows with a bright light as "+ETO->QS+" tears"+
			" into your chest!");
				set_property("magic",1);
				targ->do_damage("torso",random(10)+10);
                                targ->set_paralyzed(random(3)+2,"Your soul is held entraced by the light!");
                                set_property("magic", -1); // fixed from remove_property
		break;
	default:  tell_object(ETO,"Well now you've done it! :) Please bug"+
		" this and include what you were doing/fighting when you got"+
		" this message.");
	break;
		}
    return 1;
	}
}
