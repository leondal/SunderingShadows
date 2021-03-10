#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";
int stored_energy, chance;

create() {
 ::create();    
    set_id(({"soulcrusher","sword","shortsword","short sword"}));
    set_name("short sword");
    set_obvious_short("A short sword");
    set_short("%^RED%^S%^BOLD%^%^BLACK%^ou%^RESET%^%^RED%^"+
    "l%^YELLOW%^c%^RESET%^%^RED%^ru%^BOLD%^%^BLACK%^sh%^RESET%^"+
    "%^RED%^er%^RESET%^");
 
    set_lore("This is the sword known infamously as Soulcrusher.  "+
    "Its adamantite blade was made famous as it seemed to single "+
    "handedly crush the hopes and the soul of its opponents.   "+
    "Legends say that it was encased in the tomb of the man who "+
    "last possessed it, the location of that tomb has been lost "+
    "over the course of time.  Obviously it was somehow "+
    "rediscovered.%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This sword spans approximately two feet "+
    "from the tip of the blade to the pommel.  The blade is made "+
    "from adamantium that has been enchanted to continually "+
    "give off a dull %^YELLOW%^glow%^BOLD%^%^WHITE%^ and it "+
    "has several strange %^BLUE%^runes%^BOLD%^%^WHITE%^ engraved "+
    "onto one side of it.  It runs through the hilt and ends "+
    "in a %^BOLD%^%^BLACK%^charred%^BOLD%^%^WHITE%^ steel "+
    "pommel that has a lone %^CYAN%^crystal%^BOLD%^%^WHITE%^ "+
    "inset into it.  The hilt itself is made from a %^RESET%^"+
    "metal alloy%^BOLD%^%^WHITE%^ that has been carefully molded "+
    "to perfectly balance the weight of the weapon.%^RESET%^"); 
    
    set_value(1000);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
    set_property("enchantment", 4);
    stored_energy = 0;
    chance = 250 + random(91);
	set_item_bonus("sight bonus", 1);
    set_item_bonus("attack bonus", 1);
    //set_item_bonus("damage bonus", 1);
}

int wield_me() {
   if(ETO->query_highest_level() <15){
        	tell_object(ETO,"%^RED%^The weapon "+
		"is too complex for you to master.%^RESET%^");
        	return 0;
    }
    tell_object(ETO,"%^BOLD%^%^WHITE%^You carefully grip the "+
    "hilt of the sword and the %^YELLOW%^light%^BOLD%^%^WHITE%^ "+
    "from its glowing blade cascades around you!%^RESET%^");
    tell_room(EETO,ETO->QCN +"%^BOLD%^%^WHITE%^ carefully grips "+
    "the hilt of " +ETO->QP+ "%^BOLD%^%^WHITE%^ sword and "+
    "the %^YELLOW%^light%^BOLD%^%^WHITE%^ from its glowing blade "+
    "cascades around "+TP->QO+ ".%^RESET%^",ETO);
    return 1;
}

int unwield_me() {
    tell_object(ETO,"%^BOLD%^%^WHITE%^You release your grip "+
    "on the sword and the %^YELLOW%^light%^BOLD%^%^WHITE%^ "+
    "from its glowing blade recedes!%^RESET%^");
    
    tell_room(EETO,ETO->QCN +"%^BOLD%^%^WHITE%^ releases "+
    "the hilt of "+ETO->QP+ "%^BOLD%^%^WHITE%^ sword and "+
    "the %^YELLOW%^light%^BOLD%^%^WHITE%^ from its "+
    "glowing blade recedes!%^RESET%^",ETO);
    return 1;
}

int special(object targ) {
    int dam;
    if(!objectp(targ)) return 0;
    if(random(1000) < chance && (int)TO->query_property("enchantment") >= 1) {
        switch(random(2)) {
            case 0:
                tell_object(ETO,"%^RED%^As you strike "+targ->QCN+"%^RED%^ with your sword, the %^CYAN%^crystal%^RED%^ in its %^BOLD%^%^BLACK%^pommel%^RESET%^%^RED%^ flashes %^YELLOW%^brilliantly%^RESET%^%^RED%^!%^RESET%^");
                tell_object(targ,ETO->QCN +"%^RED%^ strikes you with "+ETO->QP+"%^RED%^ sword and the %^CYAN%^crystal%^RED%^ in its %^BOLD%^%^BLACK%^pommel%^RESET%^%^RED%^ flashes %^YELLOW%^brilliantly%^RESET%^%^RED%^!%^RESET%^");
                tell_room(EETO,ETO->QCN + "%^RED%^ strikes "+targ->QCN+"%^RED%^ with " +ETO->QP+ 
                "%^RED%^ sword and the %^CYAN%^crystal%^RED%^ in its %^BOLD%^%^BLACK%^pommel%^RESET%^%^RED%^ flashes %^YELLOW%^brilliantly%^RESET%^%^RED%^!%^RESET%^",({ETO,targ}));
                dam = roll_dice(2,4);
                stored_energy += dam;
                if(stored_energy >= 30 && ETO->query_hp() < ETO->query_max_hp()) {
                    tell_object(ETO,"%^CYAN%^The crystal in the %^BOLD%^%^BLACK%^pommel%^RESET%^%^CYAN%^ of your sword suddenly pulses a brilliant %^BLUE%^blue%^CYAN%^ hue and some of your wounds quickly %^RED%^mend%^CYAN%^!%^RESET%^");
                    tell_room(EETO,"%^CYAN%^The crystal in the %^BOLD%^%^BLACK%^pommel%^RESET%^%^CYAN%^of "+ ETO->QCN+"%^CYAN%^'s sword suddenly pulses a brilliant %^BLUE%^blue%^CYAN%^ and some of "+ETO->QP+ "%^CYAN%^ wounds quickly %^RED%^mend%^CYAN%^!%^RESET%^",ETO);
                    ETO->heal(6);
                    stored_energy = 0;
                }
                return targ->do_damage(targ->return_target_limb(),dam);
                break;
            case 1:
                tell_object(ETO,"%^BOLD%^%^BLACK%^You slice deep into "+targ->QCN+"%^BOLD%^%^BLACK%^'s flesh and feel your weapon make contact with a %^RESET%^bone%^BOLD%^%^WHITE%^!%^RESET%^");
                tell_object(targ,ETO->QCN+"%^BOLD%^%^BLACK%^ slices "+ETO->QP+"%^BOLD%^%^BLACK%^ sword deep into your flesh, making contact with one of your %^RESET%^bones%^BOLD%^%^BLACK%^!%^RESET%^");
                tell_room(EETO,ETO->QCN +"%^BOLD%^%^BLACK%^ slices "+ETO->QP+"%^BOLD%^%^BLACK%^ sword deep into "+targ->QCN+"%^BOLD%^%^BLACK%^'s flesh!%^RESET%^",({ETO,targ}));
                return targ->do_damage(targ->return_target_limb(),roll_dice(1,8));
            break;
        }
    }
}


