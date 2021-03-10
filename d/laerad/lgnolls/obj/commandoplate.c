//Essyllis: Feb 2015
#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";
#include "../lgnoll.h"

void create()
{
        ::create();
        set_name("Commando plate");
        set_id(({"plate","armour","full plate","fullplate", "armor","commando plate","Plate","Commando plate","commandoplate"}));
        set_short("%^YELLOW%^Commando's Plate%^RESET%^");
        set_obvious_short("%^YELLOW%^A yellow fullplate%^RESET%^");
        set_long("%^ORANGE%^This fullplate has been dyed %^BOLD%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^BOLD%^en "+
				"y%^RESET%^%^ORANGE%^e%^BOLD%^ll%^RESET%^%^ORANGE%^o%^BOLD%^w "+
				"%^RESET%^%^ORANGE%^to a degree where it almost gives off %^BOLD%^%^WHITE%^light "+
				"%^RESET%^%^ORANGE%^on its own. On the chest piece of the fullplate, "+
				"the %^BOLD%^%^WHITE%^sigil %^RESET%^%^ORANGE%^of %^BOLD%^Asgard "+
				"%^RESET%^%^ORANGE%^is engraved in %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r "+
				"%^RESET%^%^ORANGE%^and adds a beautiful contrast to the "+
				"%^BOLD%^y%^RESET%^%^ORANGE%^e%^BOLD%^ll%^RESET%^%^ORANGE%^o%^BOLD%^w pl%^RESET%^%^ORANGE%^a%^BOLD%^t%^RESET%^%^ORANGE%^e. "+
				"Protective half-cup plates have been fitted onto the shoulders of the "+
				"armor. Engraved onto the half-cups, %^BOLD%^%^BLACK%^e%^BLUE%^y%^BLACK%^es "+
				"%^RESET%^%^ORANGE%^seem to look out onto its surroundings, almost "+
				"so lifelike that one would think they were really the plate's living "+
				"%^BOLD%^%^BLACK%^e%^BLUE%^y%^BLACK%^es%^RESET%^%^ORANGE%^. Despite its "+
				"obvious age the armor seem almost unmarked by time and the "+
				"combats it must have seen.%^RESET%^\n");
        set_lore("Crafted in the Sister-city of Torm, these fullplates were obviously "+
				"highly priced and valued in the city of Asgard. But producing a platemail "+
				"is no cheap task, especially not one of such quality, hence these plates "+
				"were reserved for the elite forces of Asgard. It is rumored that the "+
				"blacksmiths had the nearby temple of Helm bless the plates to help the "+
				"wearer be extra attentive in their duty of protecting Asgard.");
        set_property("lore",16);
        set_property("enchantment",3);
        set_size(-1);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
        set_value(5000);
}

int wearme(){
     if((int)ETO->query_highest_level() < 15) {
        tell_object(ETO,"The armor doesn't fit you!");
        return 0;
     }
        if(ALIGN->is_good(ETO)) {
                tell_object(ETO,"%^BOLD%^%^YELLOW%^You sense your awareness improve as you wear the plate");
                tell_room(EETO,"%^BOLD%^%^YELLOW%^The eyes on "+ETO->QCN+"'s"+
                " plate blink slowly as "+ETO->QCN+" dons the armor.",ETO);
                        ETO->set_property("good item",1);
						set_item_bonus("sight bonus",2);
						set_item_bonus("perception",2);
                return 1;
        }
        if(ALIGN->is_evil(ETO)) {
                tell_object(ETO,"%^BOLD%^%^YELLOW%^The eyes on the plate close.");
                tell_room(EETO,"%^BOLD%^%^YELLOW%^The eyes on the plate seem disappointed with "+ETO->QCN+" and shut themselves.",ETO);
                set_item_bonus("sight bonus",0);
				set_item_bonus("perception",0);
				return 1;
        }else {
                tell_object(ETO,"%^YELLOW%^The plate seem to reluctantly accept you.");
				tell_room(EETO,"%^BOLD%^%^YELLOW%^The eyes on the plate glance judgingly at "+ETO->QCN+" as "+ETO->QS+" wears it.",ETO);
				set_item_bonus("sight bonus",1);
				set_item_bonus("perception",1);
                return 1;
        }
}

int removeme(){
        if(ALIGN->is_good(ETO)) {
                tell_object(ETO,"%^BOLD%^%^YELLOW%^The eyes on the plate scan the area before letting you remove it.");
                tell_room(EETO,"%^YELLOW%^The eyes on the plate seem to scan the area just before "+ETO->QCN+" removes it.",ETO);
                return 1;
        }else {
                tell_object(ETO,"%^YELLOW%^The eyes on the plate glare at you as you set it aside.");
                tell_room(EETO,"%^YELLOW%^The eyes on "+ETO->QCN+"'s plate appear annoyed as "+ETO->QS+" removes it.",ETO);
				return 1;
        }
}
