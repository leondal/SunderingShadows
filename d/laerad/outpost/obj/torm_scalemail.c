#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("jazerant armor");
	set_id(({ "jazerant armor", "scalemail", "mail", "scale mail", "jazerant", "armor" }));
	set_short("%^RESET%^%^CYAN%^Scalemail of the %^BOLD%^A%^WHITE%^z%^BLUE%^u%^RESET%^%^CYAN%^r%^BOLD%^e S%^BLUE%^e%^RESET%^a%^BOLD%^%^CYAN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^D%^WHITE%^e%^CYAN%^c%^WHITE%^o%^CYAN%^r%^WHITE%^a%^CYAN%^t%^WHITE%^e%^CYAN%^d jazerant armor%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This scale mail is made out of high quality iron. Small %^WHITE%^d%^CYAN%^i%^WHITE%^amond%^CYAN%^ shaped plates interlock with each other to create a %^BOLD%^f%^WHITE%^i%^CYAN%^s%^WHITE%^h%^CYAN%^s%^WHITE%^c%^CYAN%^a%^WHITE%^l%^CYAN%^e%^RESET%^%^CYAN%^ effect. The scales are all hammered out to resemble fishscales except on a area on the chest. The scales on the chest seems to have been given special "
"%^MAGENTA%^attention%^CYAN%^. They have been ch%^WHITE%^i%^CYAN%^seled so they fit into a small part of a large picture. So when you see the armor from the front a br%^YELLOW%^ea%^RESET%^%^CYAN%^tht%^YELLOW%^a%^RESET%^%^CYAN%^k%^YELLOW%^e%^RESET%^%^CYAN%^ing picture emerges from the metal itself. The scales have been ch%^WHITE%^i%^CYAN%^seled into showing a %^BOLD%^%^WHITE%^masted ship%^RESET%^%^CYAN%^ which rests in the "
"%^BOLD%^%^BLUE%^watery foreground %^RESET%^%^CYAN%^of a busy %^ORANGE%^city harbor%^CYAN%^. At the edge of the %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^, towering over the city, is the majestic %^BOLD%^%^BLUE%^silhouette%^RESET%^%^CYAN%^ of a male %^YELLOW%^statue%^RESET%^%^CYAN%^. In his outstretched hand he holds a %^BOLD%^%^CYAN%^glowing orb%^RESET%^%^CYAN%^ leading the ship home to its harbor. Cast in the twilight sky "
"is a %^BOLD%^%^WHITE%^crescent%^RESET%^%^CYAN%^ moon flanked by five %^BOLD%^glittering stars%^RESET%^%^CYAN%^. Small %^YELLOW%^s%^GREEN%^e%^YELLOW%^m%^GREEN%^i%^YELLOW%^pr%^GREEN%^e%^YELLOW%^c%^GREEN%^iou%^YELLOW%^s%^RESET%^%^CYAN%^ gemstones completes this puzzle adding colors at the right places.%^RESET%^");
	set_weight(25);
	set_value(2500);
	set_lore("After the war between Tonovi and the surrounding lands, the City of Torm realized that their standing army was ill equipped to meet the challenges that continued to plague the regions.  Not only had General Telkaror betrayed the city and led the majority of the senior guards to their death in the drow war upon Daggerdale, but the attacks by pirates, bandits and other entities had taxed the regiments.  It became clear "
"that not only were more guards needed, but suitable armor and weapons to protect them.  And so, in 685 SG the Vizier commissioned Gigi's of Torm to design and manufacture the necessary items to provide additional protection to the troops.  Created by the armorsmith Cedric of Tempus, this piece, along with others, were presented to the city after several months of taxing work.");
	set_property("lore difficulty",16);
	set_type("chain");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
      set_item_bonus("magic resistance",1);
	set_ac(4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You slide the armor on and feel protected all around.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You hesitate before drawing the protective armor off.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^With a flash, the orb depicted on the front of "+ETOQCN+"'s armor comes to life, pulsing with energy.  "+who->QCN+" cries out in pain!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^With a flash, the orb depicted on the front comes to life, pulsing with energy.  "+who->QCN+" cries out in pain!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLUE%^With a flash, the orb depicted on the front of "+ETOQCN+"'s armor comes to life, pulsing with energy.  You cry out in pain!%^RESET%^");
		who->set_paralyzed(roll_dice(1,3));
return damage;	}
}