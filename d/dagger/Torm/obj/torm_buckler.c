#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("buckler shield");
	set_id(({ "shield", "small buckler shield", "crested buckler shield", "crested buckler", "buckler" }));
	set_short("%^BOLD%^%^CYAN%^C%^WHITE%^r%^RESET%^%^CYAN%^e%^RESET%^s%^BOLD%^%^CYAN%^t%^BLUE%^e%^CYAN%^d B%^BLUE%^u%^RESET%^c%^WHITE%^%^BOLD%^k%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^D%^WHITE%^e%^CYAN%^c%^WHITE%^o%^CYAN%^r%^WHITE%^a%^CYAN%^t%^WHITE%^e%^CYAN%^d %^ORANGE%^b%^CYAN%^u%^ORANGE%^ckl%^CYAN%^e%^ORANGE%^r%^RESET%^");
	set_long("%^CYAN%^This shield is made of %^ORANGE%^leather%^CYAN%^, hardened in b%^BOLD%^%^BLACK%^oi%^RESET%^%^CYAN%^ling oil and then shaped into an oval shield. Though called a shield, it is only a small disk that can strapped to the arm and used to deflect blows in close quarter %^RED%^combat%^CYAN%^. The shield is designed so the user won't be hindered if using two weapons. On the middle of the buckler, a st%^WHITE%^ee"
"%^CYAN%^l plate has been attached, and a br%^YELLOW%^ea%^RESET%^%^CYAN%^tht%^YELLOW%^a%^RESET%^%^CYAN%^k%^YELLOW%^i%^RESET%^%^CYAN%^n%^YELLOW%^g%^RESET%^%^CYAN%^ image decorates it. A %^BOLD%^%^WHITE%^masted ship%^RESET%^%^CYAN%^ which rests in the %^BOLD%^%^BLUE%^watery foreground %^RESET%^%^CYAN%^of a busy %^ORANGE%^city harbor%^RESET%^%^CYAN%^. At the edge of the %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^, towering over the city, is the majestic %^BOLD%^%^BLUE%^silhouette%^RESET%^%^CYAN%^ of a male %^YELLOW%^statue%^RESET%^%^CYAN%^. In his "
"outstretched hand he holds a %^BOLD%^%^CYAN%^glowing orb%^RESET%^%^CYAN%^ leading the ship home to its harbor. Cast in the twilight sky is a %^BOLD%^%^WHITE%^crescent%^RESET%^%^CYAN%^ moon flanked by five %^BOLD%^%^CYAN%^glittering stars%^RESET%^%^CYAN%^. Small %^YELLOW%^s%^GREEN%^e%^YELLOW%^m%^GREEN%^i%^YELLOW%^pr%^GREEN%^e%^YELLOW%^c%^GREEN%^iou%^YELLOW%^s%^RESET%^%^CYAN%^ gemstones completes this puzzle adding colors at the right places.%^RESET%^");
	set_weight(3);
	set_value(350);
	set_lore("After the war between Tonovi and the surrounding lands, the City of Torm realized that their standing army was ill equipped to meet the challenges that continued to plague the regions.  Not only had General Telkaror betrayed the city and led the majority of the senior guards to their death in the drow war upon Daggerdale, but the attacks by pirates, bandits and other entities had taxed the regiments.  It became clear "
"that not only were more guards needed, but suitable armor and weapons to protect them.  And so, in 685 SG the Vizier commissioned Gigi's of Torm to design and manufacture the necessary items to provide additional protection to the troops.  Created by the armorsmith Cedric of Tempus, this shield, along with other armaments, were presented to the city after several months of taxing work.");
	set_property("lore difficulty",16);
	set_type("shield");
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
return (damage*30)/100;	}
}