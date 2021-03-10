#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leather bracers");
	set_id(({ "bracers", "bracers of the waves", "torm bracers", "leather bracers" }));
	set_short("%^BOLD%^%^CYAN%^B%^WHITE%^r%^RESET%^%^CYAN%^a%^BLUE%^c%^BOLD%^%^CYAN%^e%^RESET%^r%^BOLD%^%^CYAN%^s of the W%^WHITE%^a%^RESET%^%^CYAN%^v%^BOLD%^%^BLUE%^e%^CYAN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^D%^WHITE%^e%^CYAN%^c%^WHITE%^o%^CYAN%^r%^WHITE%^a%^CYAN%^t%^WHITE%^e%^CYAN%^d br%^ORANGE%^a%^CYAN%^c%^ORANGE%^e%^CYAN%^rs%^RESET%^");
	set_long("%^CYAN%^This is a pair of bracers made of %^ORANGE%^leather%^CYAN%^. The %^ORANGE%^leather%^CYAN%^ has been treated with a type of oil to make it sh%^WHITE%^i%^CYAN%^ne. A soft %^ORANGE%^f%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^r%^CYAN%^ has been attached to the underside of the bracers to provide comfort to the wearer's arms. %^ORANGE%^Leather thongs%^CYAN%^ line the underside of the bracers so the wearer can strap "
"them on securely. On top of the bracers a delicate silver plaque has been attached and a br%^YELLOW%^ea%^RESET%^%^CYAN%^tht%^YELLOW%^a%^RESET%^%^CYAN%^k%^YELLOW%^i%^RESET%^%^CYAN%^n%^YELLOW%^g%^RESET%^%^CYAN%^ image has been chiseled out of the metal. A %^BOLD%^%^WHITE%^masted ship%^RESET%^%^CYAN%^ which rests in the %^BOLD%^%^BLUE%^watery foreground %^RESET%^%^CYAN%^of a busy %^ORANGE%^city harbor%^RESET%^%^CYAN%^. At the edge of the %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^, towering over the city, is the majestic %^BOLD%^%^BLUE%^silhouette"
"%^RESET%^%^CYAN%^ of a male %^YELLOW%^statue%^RESET%^%^CYAN%^. In his outstretched hand he holds a %^BOLD%^%^CYAN%^glowing orb%^RESET%^%^CYAN%^ leading the ship home to its harbor. Cast in the twilight sky is a %^BOLD%^%^WHITE%^crescent%^RESET%^%^CYAN%^ moon flanked by five %^BOLD%^%^CYAN%^glittering stars%^RESET%^%^CYAN%^. Small %^YELLOW%^s%^GREEN%^e%^YELLOW%^m%^GREEN%^i%^YELLOW%^pr%^GREEN%^e%^YELLOW%^c%^GREEN%^iou%^YELLOW%^s%^RESET%^%^CYAN%^ gemstones completes this puzzle adding colors at the right places.%^RESET%^");
	set_weight(10);
	set_value(500);
	set_lore("After the war between Tonovi and the surrounding lands, the City of Torm realized that their standing army was ill equipped to meet the challenges that continued to plague the regions.  Not only had General Telkaror betrayed the city and led the majority of the senior guards to their death in the drow war upon Daggerdale, but the attacks by pirates, bandits and other entities had taxed the regiments.  It became clear "
"that not only were more guards needed, but suitable armor and weapons to protect them.  And so, in 685 SG the Vizier commissioned Gigi's of Torm to design and manufacture the necessary items to provide additional protection to the troops.  Created by the armorsmith Cedric of Tempus, these bracers, along with other armaments, were presented to the city after several months of taxing work.");
	set_property("lore difficulty",16);
	set_type("bracer");
	set_limbs(({ "left arm","right arm" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
}


