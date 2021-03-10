#include <std.h>
inherit "/d/common/obj/weapon/club_lg";

void create()
{
    ::create();
    set_name("large club");
    set_id(({"club", "large club", "large spiked club", "violent smasher", 
    "smasher"}));

    set_obvious_short("%^BOLD%^%^RED%^A large viciously spiked club%^RESET%^");

    set_short("%^BOLD%^%^RED%^V%^BOLD%^%^MAGENTA%^io%^BOLD%^%^RED%^l%^BOLD%^%^MAGENTA%^e"+
    "%^BOLD%^%^RED%^nt Sm%^BOLD%^%^MAGENTA%^a%^BOLD%^%^RED%^sh%^BOLD%^%^MAGENTA%^e%^BOLD%^"+
    "%^RED%^r%^RESET%^");
	
    set_long("%^BOLD%^%^RED%^This club is made from a very solid %^RESET%^%^RED%^dark red"+
    "%^BOLD%^%^RED%^ bone like substance. It is nearing five feet in length. At the base it is "+
    "narrower and has a been wrapped with a very %^RESET%^%^WHITE%^dingy%^BOLD%^%^RED%^ cloth "+
    "to provide a means of gripping it. Sp%^RESET%^%^RED%^i%^BOLD%^%^RED%^k%^RESET%^%^RED%^e%^BOLD%^"+
    "%^RED%^s begin extruding out from it about half way up the shaft. At first they are short, perhaps "+
    "only an inch in length but as they approach the end of the club they lengthen to almost "+
    "ten inches. Each of the sp%^RESET%^%^RED%^i%^BOLD%^%^RED%^k%^RESET%^%^RED%^e%^BOLD%^%^RED%^"+
    "s at the end of the club are %^RESET%^%^ORANGE%^barbed%^BOLD%^%^RED%^ as if they are meant to "+
    "be imbedded into someone or something permenantly. They are made from what looks like pieces of "+
    "%^RESET%^%^RED%^rusted%^BOLD%^%^RED%^ metal that have been filed to a point.%^RESET%^");

    set_lore("%^BOLD%^%^RED%^These clubs are known to be used frequently by the ogres who "+
    "have been dwelling on the island of Eldebaro. The legend surrounding them suggest that they "+
    "were formed from ancient storm giant bones. The bones where somehow manipulated by the ogre "+
    "shamans. The process changed the bones, so that they were more malleable, and would allow "+
    "for the insertion of the spikes. The spikes serving two purposes, one being to lower the morale "+
    "of any enemies the ogres might face, and the other being to make combat much more brutal. The shamans "+
    "also imbued them in such a way to strengthen the ogre warriors, so that they would actually be more "+
    "ferocious in battle. Some stories say that they get their color from the blood of the enemies that "+
    "they have slain, however, those are probably just tall tales.%^RESET%^");

    set_property("lore difficulty", 22);
    set_value(3000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("strength", 6);
}

int wield_func()
{
	// Just added a level-check to wield the weapon. Least newbies starting running around with this powa club :) /Essy
	if(ETO->query_level() < 35) {
		tell_object(ETO,"%^RESET%^%^ORANGE%^You just don't have the strength to wield this club properly!");
		tell_room(EETO, ETOQCN +" %^RESET%^%^ORANGE%^grunts with the effort of wielding a heavy club, with little success", ETO);
		return 0;
	}
	
    tell_object(ETO, "%^BOLD%^%^RED%^You can't help but ROAR as you "+
    "hoist the viciously spiked club and feel it add to your strength!%^RESET%^");
	
    tell_room(EETO, ETOQCN +"%^BOLD%^%^RED%^ ROARS as "+ETO->QS+" hoists the "+
    "viciously spiked club and somehow looks physically stronger!%^RESET%^", ETO);
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^RED%^You feel noticeably weaker as you "+
    "lower the viciously spiked club.%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(1000) < 275)
    {
        switch(random(10))
        {
            case 0..8:
                tell_object(ETO, "%^RESET%^%^RED%^You slam your viciously spiked "+
                "club into "+targ->QCN+"%^RESET%^%^RED%^'s head and %^BOLD%^%^RED%^"+
                "BLOOD%^RESET%^%^RED%^ splatters everywhere as the spikes tear into "+
                targ->QO+"!%^RESET%^");
				
                tell_object(targ, ETOQCN +" %^RESET%^%^RED%^ slams "+ETO->QP+ 
                "%^RESET%^%^RED%^ viciously spiked club into your head and your blood "+
                "splatters everywhere as the spikes tear into you!%^RESET%^");
				
                tell_room(EETO, ETOQCN +"%^RESET%^%^RED%^ slams "+
                ETO->QP +" viciously spiked club into "+targ->QCN+"%^RESET%^%^RED%^'s "+
                "head and %^BOLD%^%^RED%^BLOOD%^RESET%^%^RED%^ splatters everywhere as the "+
                "spikes tear into "+targ->QO+"!%^RESET%^", ({targ, ETO}));
                ETO->set_property("magic", 1);
                TO->set_property("magic", 1);
                if(!random(1000)) targ->cause_typed_damage(targ, "head", roll_dice(30, 20), "piercing");
                else targ->cause_typed_damage(targ, "head", roll_dice(3,6), "piercing");
                TO->set_property("magic", -1);
                ETO->set_property("magic", -1);
                return 0;
                break;
            case 9:
            
                tell_object(ETO, "%^BOLD%^%^RED%^You ferociously smash your viciously spiked club "+
                "into "+targ->QCN+"%^BOLD%^%^RED%^ and use the momentum to swing again!%^RESET%^");
                
                tell_object(targ, ETOQCN+"%^BOLD%^%^RED%^ ferociously smashes "+ETO->QP+
                " viciously spiked club into you and uses the momentum to swing again!%^RESET%^");
  
			    tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ ferociously smashes "+ETO->QP+
                " viciously spiked club into "+targ->QCN+"%^BOLD%^%^RED%^ and uses the momentum to "+
                "swing again!%^RESET%^", ({targ, ETO}));

                ETO->execute_attack();
                return roll_dice(2, 6)+2;
                break;
        }
    }
}

