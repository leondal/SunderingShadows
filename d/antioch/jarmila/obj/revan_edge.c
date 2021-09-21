
#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword.c";

void create(){
        ::create();
        set_name("revans edge");
        set_id(({ "sword", "katana", "revans edge", "two handed sword",  }));
        set_short("%^RESET%^%^BOLD%^Rev%^RESET%^a%^RESET%^%^BOLD%^ns%^RESET%^%^RED%^ "+
		"E%^BOLD%^d%^RESET%^%^RED%^ge%^RESET%^");
        set_obvious_short("%^RESET%^%^BOLD%^bo%^RESET%^n%^BOLD%^e "+
		"blade %^BLACK%^%^BOLD%^kat%^RESET%^a%^BLACK%^%^BOLD%^na%^RESET%^");
        set_long("%^RESET%^%^BOLD%^This %^BLACK%^%^BOLD%^katana styled%^RESET%^%^BOLD%^ "+
		"blade is unique among its peers as the blade is not formed of metal, but of what "+
		"looks like %^RESET%^bone%^RESET%^%^BOLD%^. What beast it came from is unknown though "+
		"how the bone was formed into a perfect blade is the bigger mysterty as there are "+
		"no %^RESET%^%^ORANGE%^tool marks%^RESET%^%^BOLD%^ along it. At the base of the "+
		"blade near the guard is a single %^BLACK%^%^BOLD%^etched symbol%^RESET%^%^BOLD%^ "+
		"of a feather basked in %^RESET%^%^RED%^flame%^RESET%^%^BOLD%^. The hilt is devoid "+
		"of a pommel, showing the masterful crafting in its balance. The hilt itself is "+
		"wrapped in %^RESET%^white%^RESET%^%^BOLD%^ and %^BLACK%^%^BOLD%^black%^RESET%^%^BOLD%^ "+
		"silk%^RESET%^");
        set_value(15000);
        set_lore(" %^RED%^%^BOLD%^Revan was quite possibly the most feared Solar to the forces "+
		"of darkness he hunted. To be honest though some of his own kind held an amount of fear "+
		"for the 'Furious Shard' as any sign of taint or decay could cause Revan to declare you "+
		"apostate and destroy you. After Revan's death his katana was lost to time. It is saod "+
		"the blade was formed from the bones of a demi-god that Revan killed."+
        " \n%^RESET%^%^ORANGE%^Father Belanos, the Weapons of Light%^RESET%^%^RESET%^");
        set_property("lore difficulty",23);
        set_property("enchantment",7);
        set_item_bonus("attack bonus",7);
        set_item_bonus("damage bonus",7);

        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
        set_hit((:TO,"hit_func":));
}

int wield_func(){
        tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^RED%^%^BOLD%^Taking the "+query_short()+" %^RED%^%^BOLD%^into your hands, "+
		"you feel a sense of complete calmness spill over you. There will be blood, but it will not be yours.%^RESET%^");
        return 1;
}

int unwield_func(){
        tell_room(environment(ETO),"",ETO);
        tell_object(ETO,"%^RED%^%^BOLD%^Battle over, you sheath the "+query_short()+" %^RED%^%^BOLD%^knowing "+
		"it will come to your hand when next you are in need.%^RESET%^");
        return 1;
}

int hit_func(object targ){
        if(!objectp(targ)) return 0;
        if(!objectp(ETO)) return 0;
        if(random(1000) < 250){
        tell_room(environment(query_wielded()),"%^YELLOW%^With perfect calmness, "+ETOQCN+" points the tip "+
		"of their "+query_short()+" %^YELLOW%^toward "+targ->QCN+" and sends a %^RED%^burning blaze of light%
^YELLOW%^ outward toward their enemy!%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^YELLOW%^The battle seems hard and harsh, but the weight of victory is in your hands.  "+
		"Stepping forward, you point the tip of your "+query_short()+" %^YELLOW%^toward "+targ->QCN+" a
nd with perfect calmness send a %^RED%^burning blaze of light%^YELLOW%^ outward toward your enemy!%^RESET%^");
        tell_object(targ,"%^YELLOW%^With perfect calmness, "+ETOQCN+" points the tip of their "+query_short()+" %^YELLOW%^toward you!  "+
		"From the tip, a brilliant light ignites and then bursts into a %^RED%^burning "+
		"blaze of light%^YELLOW%^ that strikes out at you and burns you to your soul!%^RESET%^");
         return roll_dice(6, 10)+10;
}
}
