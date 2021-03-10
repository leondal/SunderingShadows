#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("small shield");
	set_id(({ "shield", "small shield", "iron shield", "crested shield" }));
	set_short("%^BOLD%^%^CYAN%^C%^WHITE%^r%^RESET%^%^CYAN%^e%^RESET%^s%^BOLD%^%^CYAN%^t%^BLUE%^e%^CYAN%^d S%^BLUE%^h%^WHITE%^i%^RESET%^%^CYAN%^e%^RESET%^l%^BOLD%^%^CYAN%^d%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^D%^WHITE%^e%^CYAN%^c%^WHITE%^o%^CYAN%^r%^WHITE%^a%^CYAN%^t%^WHITE%^e%^CYAN%^d sh%^ORANGE%^ie%^CYAN%^ld%^RESET%^");
	set_long("%^CYAN%^This shield is made of the highest quality iron and is polished to a sh%^WHITE%^i%^CYAN%^ne. The sh%^WHITE%^i%^CYAN%^n%^WHITE%^i%^CYAN%^ng metal has been %^YELLOW%^o%^RESET%^%^CYAN%^rn%^YELLOW%^a%^RESET%^%^CYAN%^m%^YELLOW%^e%^RESET%^%^CYAN%^nt%^YELLOW%^e%^RESET%^%^CYAN%^ly designed with scales resembling %^BOLD%^%^CYAN%^f%^WHITE%^i%^CYAN%^s%^WHITE%^h%^CYAN%^s%^WHITE%^c%^CYAN%^a%^WHITE%^l%^CYAN%^e%^WHITE%^s%^RESET%^"
        "%^CYAN%^ and on the center of the shield a br%^YELLOW%^ea%^RESET%^%^CYAN%^tht%^YELLOW%^a%^RESET%^%^CYAN%^k%^YELLOW%^i%^RESET%^%^CYAN%^n%^YELLOW%^g%^RESET%^%^CYAN%^ image has been etched into the metal. A %^BOLD%^%^WHITE%^masted ship%^RESET%^%^CYAN%^ which rests in the %^BOLD%^%^BLUE%^watery foreground %^RESET%^%^CYAN%^of a busy %^ORANGE%^city harbor%^RESET%^%^CYAN%^. At the edge of the %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^, towering over the city, is the majestic %^BOLD%^%^BLUE%^silhouette%^RESET%^%^CYAN%^ of a male %^YELLOW%^statue"
        "%^RESET%^%^CYAN%^. In his outstretched hand he holds a %^BOLD%^%^CYAN%^glowing orb%^RESET%^%^CYAN%^ leading the ship home to its harbor. Cast in the twilight sky is a %^BOLD%^%^WHITE%^crescent%^RESET%^%^CYAN%^ moon flanked by five %^BOLD%^%^CYAN%^glittering stars%^RESET%^%^CYAN%^. Small %^YELLOW%^s%^GREEN%^e%^YELLOW%^m%^GREEN%^i%^YELLOW%^pr%^GREEN%^e%^YELLOW%^c%^GREEN%^iou%^YELLOW%^s%^RESET%^%^CYAN%^ gemstones completes this puzzle adding colors at the right places.%^RESET%^");
	set_weight(5);
	set_value(500);
	set_lore("After the war between Tonovi and the surrounding lands, the City of Torm realized that their standing army was ill equipped to meet the challenges that continued to plague the regions.  Not only had General Telkaror betrayed the city and led the majority of the senior guards to their death in the drow war upon Daggerdale, but the attacks by pirates, bandits and other entities had taxed the regiments.  It became clear "
        "that not only were more guards needed, but suitable armor and weapons to protect them.  And so, in 685 SG the Vizier commissioned Gigi's of Torm to design and manufacture the necessary items to provide additional protection to the troops.  Created by the armorsmith Cedric of Tempus, this shield, along with other armaments, were presented to the city after several months of taxing work.");
	set_property("lore difficulty",16);
	set_type("shield");
    set_armor_prof("shield");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",0);
	set_struck((:TO,"strike_func":));
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^With a quick movement, "+ETOQCN+" brings up their "+query_short()+" %^BOLD%^%^CYAN%^to block "+who->QCN+"'s attack!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^With a quick movement, you bring up your "+query_short()+" %^BOLD%^%^CYAN%^to block "+who->QCN+"'s attack!%^RESET%^");
	tell_object(who,"%^BOLD%^%^CYAN%^With a quick movement, "+ETOQCN+" brings up their "+query_short()+" %^BOLD%^%^CYAN%^to block your attack!%^RESET%^");
return (damage*50)/100;	}
}