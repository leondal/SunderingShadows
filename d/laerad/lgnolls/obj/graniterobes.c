//pocketrobes.c

#include <std.h>
#include "../lgnoll.h"
inherit "/d/common/obj/clothing/magerobe.c";

void create(){
        ::create();
        set_name("granite robes");
        set_id(({"robe","robes","granite robes","mage robes","dust","dust robes"}));
        set_short("%^BOLD%^%^BOLD%^%^BLACK%^gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e %^BLACK%^d%^CYAN%^u%^BLACK%^st r%^CYAN%^o%^BLACK%^b%^CYAN%^e%^BLACK%^s%^RESET%^");
		set_obvious_short("%^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^ss of gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e %^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^st%^RESET%^");
		set_long("%^BOLD%^%^BLACK%^These %^RESET%^%^CYAN%^robes %^BOLD%^%^BLACK%^are made of gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e "+
		"%^BLACK%^d%^CYAN%^u%^BLACK%^st. When not worn, the garment simply looks like a pile of gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e "+
		"%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^l, but as soon as it is worn it seems to form and adjust "+
		"to the body of the wearer. Even though the %^RESET%^%^CYAN%^robes %^BOLD%^%^BLACK%^are thin and weight very little, they seem "+
		"to solidify to a s%^RESET%^o%^BOLD%^%^BLACK%^l%^RESET%^i%^BOLD%^%^BLACK%^d m%^RESET%^a%^BOLD%^%^BLACK%^ss of "+
		"r%^RESET%^o%^BOLD%^%^BLACK%^ck-h%^RESET%^a%^BOLD%^%^BLACK%^rd gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e %^BLACK%^where "+
		"they are touched or otherwise manipulated.%^RESET%^");        
		set_lore("Very little is in fact known about these robes. What is known is that they are product "+
		"of a very powerful golem which has been destroyed. The powerful magic used to create such a construct "+
		"is not entirely destroyed when the golem is. Some remains in what is left after it has been destroyed. "+
		"This is the reason that people who try to wear such robes must be proficient "+
		"in magic themselves. -- Sallonir deldor, Bard of Torm.");
		set_property("lore",20);
        set_property("enchantment",3);
		set_item_bonus("magic resistance",1);
        set_weight(5);
        set_value(900);
        set_type("clothing");
        set_limbs(({"torso"}));
        set_max_internal_encumbrance(35);
        set_wear((:TO,"wear_stuff":));
}

int wear_stuff(){
		if((string)ETO->query_deity()== "grumbar"){
			tell_object(ETO,"%^BOLD%^%^BLACK%^The robes s%^CYAN%^o%^BLACK%^l%^CYAN%^i%^BLACK%^d%^CYAN%^i%^BLACK%^f%^CYAN%^y%^BLACK%^ around your body in a p%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^ot%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^ct%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^ve gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e %^BLACK%^sh%^CYAN%^e%^BLACK%^ll.%^RESET%^");
			tell_room(EETO,"%^BOLD%^%^BLACK%^The robes s%^CYAN%^o%^BLACK%^l%^CYAN%^i%^BLACK%^d%^CYAN%^i%^BLACK%^f%^CYAN%^y%^BLACK%^ around "+ETO->QCN+"'s body in a p%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^ot%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^ct%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^ve gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e %^BLACK%^sh%^CYAN%^e%^BLACK%^ll.",ETO);
			
			set_item_bonus("damage resistance",3);
			return 1;
		}
		if((string)ETO->query_deity() == "akadi"){
			tell_object(ETO,"%^BOLD%^%^BLACK%^The robes %^RESET%^%^CYAN%^sh%^BOLD%^i%^RESET%^%^CYAN%^mm%^BOLD%^e%^RESET%^%^CYAN%^r %^BOLD%^%^BLACK%^in %^RESET%^%^MAGENTA%^protest %^BOLD%^%^BLACK%^for a moment before accepting you");
			tell_room(EETO,"%^BOLD%^%^BLACK%^The robes %^RESET%^%^CYAN%^sh%^BOLD%^i%^RESET%^%^CYAN%^mm%^BOLD%^e%^RESET%^%^CYAN%^r %^BOLD%^%^BLACK%^in %^RESET%^%^MAGENTA%^protest %^BOLD%^%^BLACK%^for a moment before accepting "+ETO->QCN+".",ETO);
			set_item_bonus("damage resistance",1);
			return 1;
		}
		else{
			tell_object(ETO,"%^BOLD%^%^BLACK%^The gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e %^BLACK%^d%^CYAN%^u%^BLACK%^st binds together around you in pr%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^ct%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^v%^RESET%^%^CYAN%^e robes.");
			tell_room(EETO,"%^BOLD%^%^BLACK%^The gr%^CYAN%^a%^BLACK%^n%^CYAN%^i%^BLACK%^t%^CYAN%^e %^BLACK%^d%^CYAN%^u%^BLACK%^st binds together around "+ETP->QCN+" in pr%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^ct%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^v%^RESET%^%^CYAN%^e robes.",ETO);
			set_item_bonus("damage resistance",2);
	return 1;
			}
}
