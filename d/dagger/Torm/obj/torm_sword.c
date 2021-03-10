#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("longsword");
	set_id(({ "sword", "longsword", "long sword", "sword of the unfurled sail", "sail sword" }));
	set_short("%^BOLD%^%^CYAN%^Sword of the %^WHITE%^U%^CYAN%^n%^BLUE%^f%^RESET%^u%^CYAN%^r%^BOLD%^%^WHITE%^l%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^d %^BOLD%^%^WHITE%^S%^CYAN%^a%^RESET%^%^CYAN%^i%^BOLD%^l%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A standard issue longsword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Intricate lines have been carved into the hilt of the sword, making it resemble a spiral of %^BOLD%^water %^RESET%^%^CYAN%^swirling upwards. Where the  hilt meets the cross piece, the spiral widens out into a powerful  %^BOLD%^%^WHITE%^wave%^RESET%^%^CYAN%^, carrying a single masted %^ORANGE%^ship%^CYAN%^. The straight, double edged blade rises up midships, ending in a razor sharp point. A deep groove runs along the middle of the blade, designed to make the %^BOLD%^%^RED%^blood %^RESET%^%^CYAN%^flow off the weapon. Faint lines fan out towards the edge, creating images which look like %^RESET%^sails%^CYAN%^, making the simple artistry complete. %^RESET%^

AVATAR
	);
	set_weight(7);
	set_value(2500);
	set_lore(
@AVATAR
After the war between Tonovi and the surrounding lands, the City of Torm realized that their standing army was ill equipped to meet the challenges that continued to plague the regions.  Not only had General Telkaror betrayed the city and led the majority of the senior guards to their death in the drow war upon Daggerdale, but the attacks by pirates, bandits and other entities had taxed the regiments.  It became clear that not only were more guards needed, but suitable armor and weapons to protect them.  And so, in 685 SG the Vizier commissioned Gigi's of Torm to design and manufacture the necessary items to provide additional protection to the troops.  Created by a renown master weaponsmith, this sword, along with other armaments, were presented to the city after several months of taxing work.

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",2);
      set_item_bonus("attack bonus",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The sail like design of the "+query_short()+" %^BOLD%^%^WHITE%^appears to unfurl as you take hold of it.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You release your grip on the "+query_short()+" %^BOLD%^%^WHITE%^and draw a deep and cleansing breath, scented with the sea spray of the ocean.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" moves with the grace of a clipper cutting through the waves as they spin and slice with their "+query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your "+query_short()+" %^BOLD%^%^WHITE%^catches the wind, slicing deep into "+targ->QCN+" with several quick and fierce cutting motions!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^You feel the stinging burn of salt spray upon your wounds as "+ETOQCN+" spins and attacks you with their "+query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^");
		return roll_dice(2,4)+1;	}
}