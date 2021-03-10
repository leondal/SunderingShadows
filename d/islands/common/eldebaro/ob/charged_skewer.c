#include <std.h>
#include "../area_stuff.h"
#define NUMBERS ({ "zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine", "ten" })
inherit "/d/common/obj/weapon/spear_lg";

void create()
{
    ::create();
    set_name("large spear");
    set_id(({"spear", "large spear", "electrified spear", 
    "electrified large spear", "charged spear", "skewer", 
    "charged skewer", "electrified skewer", "asantras skewer", 
    "asantras charged skewer"}));

    set_obvious_short("electrified large spear");

    set_short("%^RESET%^%^MAGENTA%^As%^BOLD%^a%^RESET%^%^MAGENTA%^ntra's "+
    "%^BOLD%^%^CYAN%^ch%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^rg%^BOLD%^%^BLUE%^e"+
    "%^BOLD%^%^CYAN%^d sk%^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^w%^BOLD%^%^BLUE%^"+
    "e%^BOLD%^%^CYAN%^r%^RESET%^");
	
    set_long("%^BOLD%^%^CYAN%^This spear is approximately six feet in length. It is "+
    "quite thick near the base, with multiple layers of %^BOLD%^%^BLACK%^dark cloth%^BOLD%^"+
    "%^CYAN%^ wrapped tightly around it to provide a means of holding it. The rest of the "+
    "spear is composed from a very deep %^RESET%^%^MAGENTA%^purple%^BOLD%^%^CYAN%^ metal "+
    "with tinges of almost pure black throughout it. The tip of the spear is %^BOLD%^%^RED%^"+
    "b%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^rbed%^BOLD%^%^CYAN%^ and curved in an attempt to "+
    "make an attack with it even more brutal. Amazingly, %^YELLOW%^electricity%^BOLD%^%^CYAN%^ "+
    "crackles up and down the length of the entire spear continually, so quickly that it "+
    "almost reminds you of a pulse. It seems somehow contained within the metal that composes "+
    "the spear, but sparks frequently jump from the spear and quickly fade away.%^RESET%^");
    
    set_lore("%^BOLD%^%^CYAN%^This spear was said to have been composed for Asantra FreeHolm. "+
    "She was the reputed queen of the Storm Giants who dwelled in Castle FreeHolm and the lands "+
    "around it. Some believed that it was her mercy that resulted in her demise, though the "+
    "stories are not exactly clear about what happened. Some had thought her nothing more than a "+
    "myth until the recent events on the island of Eldebaro.\n\nThe stories surrounding "+
    "this spear suggest that it was one of the most powerful creations by the smith of Castle "+
    "Freeholm, commissioned for Asantra by Kayan FreeHolm, himself. Some say that the King "+
    "later imbued the spear with a tremendous amount of power. Some stories suggest that while "+
    "a fraction of this power still remains a good deal of it has faded. These stories suggest that "+
    "the spear granted tremendous strength to its wielder, inordinate health, and had the ability to "+
    "siphon life energy from its victims and pump it into Asantra. It was also reportedly able to "+
    "inflict great amounts of electrical damage on whoever happened to be struck by it and was "+
    "said to insulate Asantra against even the most powerful electrical attacks.%^RESET%^");

    set_property("lore difficulty", 25);
    set_value(5000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("strength", 6);
    set_item_bonus("constitution", 4);
    set_item_bonus("electricity resistance", 40);
}

int wield_func()
{
    if(ETO->query_highest_level() < 35) 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The spear refuses to submit to one as "+
        "puny as you!%^RESET%^");        
        return 0;
    }
    
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel your life force and your strength "+
    "imbued with electrical power as you wield the spear!%^RESET%^");  
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel the electrical empowerment fade "+
    "away as you release the spear!%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    int dam, bolts;
    string myBolts, tlim;
    object wound;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(5))
    {
        switch(random(20))
        {
            case 0..10:            
                switch(random(20))
                {
                    case 0..5:
                        bolts = 2;
                        break;
                    case 6..10:
                        bolts = 3;
                        break;
                    case 11..18:
                        bolts = 4;
                        break;
                    case 19:
                        bolts = 5;
                        break;
                }
                myBolts = NUMBERS[bolts];
                
                tell_object(ETO, "%^BOLD%^%^YELLOW%^"+capitalize(myBolts) +" bolts of "+
                "electricity zap from the tip of your spear toward "+
                targ->QCN+"!%^RESET%^");
                
                tell_object(targ, "%^BOLD%^%^YELLOW%^"+capitalize(myBolts) + " bolts of "+
                "electricity zap from the tip of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s spear "+
                "toward you!%^RESET%^");
                
                tell_room(EETO, "%^BOLD%^%^YELLOW%^"+capitalize(myBolts) + " bolts of "+
                "electricity zap from the tip of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s spear "+
                "toward "+targ->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^", ({ETO, targ}));
        
                if(targ->reflex_save(35 + random(11)))
                {
                    bolts /= 2;
                    if(bolts == 2) myBolts = NUMBERS[bolts] + " bolt";
                    else myBolts = NUMBERS[bolts] + " bolts";
            
                    tell_room(EETO, targ->QCN+"%^BOLD%^%^WHITE%^ manages to move out of "+
                    "the way just in time and is only struck by "+myBolts+ " of electricity!", targ);
                    tell_object(targ, "%^BOLD%^%^WHITE%^You manage to move out of the way "+
                    "just in time and are only struck by "+myBolts+" of electricity!");
                    targ->cause_typed_damage(targ, "torso", roll_dice(bolts, 8), "electricity");
                    return 0;
                }
                tell_room(EETO, targ->QCN+"%^BOLD%^%^YELLOW%^ is UNABLE to move out of the way "+
                "in time and is %^BOLD%^%^BLACK%^CHARRED%^BOLD%^%^YELLOW%^ by the electricity!%^RESET%^", targ);
                tell_object(targ, "%^BOLD%^%^YELLOW%^You are UNABLE to move out of the way in "+
                "time and are %^BOLD%^%^BLACK%^CHARRED%^BOLD%^%^YELLOW%^ by the electricity!%^RESET%^");
                targ->cause_typed_damage(targ, "torso", roll_dice(bolts, 8), "electricity");
                return 0;                        
                break;
            case 11..17:
                tlim = targ->return_target_limb();
            
                tell_object(ETO, "%^BOLD%^%^BLACK%^You imbed the barbed tip of your spear into "+
                targ->QCN+"%^BOLD%^%^BLACK%^'s "+tlim+" and then %^BOLD%^%^RED%^YANK%^BOLD%^%^BLACK%^ "+
                "it viciously from the wound!%^RESET%^");
                
                tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^ imbeds the barbed tip of "+ETO->QP+
                " spear into your "+tlim+" and then %^BOLD%^%^RED%^YANKS%^BOLD%^%^BLACK%^ "+
                "it viciously from the wound!%^RESET%^");
                
                tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ imbeds the barbed tip of "+ETO->QP+
                " spear into "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+tlim+" and then %^BOLD%^%^RED%^"+
                "YANKS%^BOLD%^%^BLACK%^ it viciously from the wound!%^RESET%^", ({targ, ETO}));
                dam = roll_dice(3,6);
                wound = new(ELOB+"grievous_wound");
                wound->set_for(tlim, dam);
                wound->move(targ);
                targ->cause_typed_damage(targ, tlim, dam, "piercing");
                return 0;
                break;
            case 18..19:
                tlim = targ->return_target_limb(); 
                
                tell_object(ETO, "%^BOLD%^%^RED%^You bury the barbed tip of your spear in "+targ->QCN+
                "'s "+tlim+" and feel it %^BOLD%^%^CYAN%^SUCKING%^BOLD%^%^RED%^ the life from "+
                targ->QO+" before you %^BOLD%^%^BLACK%^RIP%^BOLD%^%^RED%^ it violently from "+
                "the wound!%^RESET%^");
                
                tell_object(targ, ETOQCN+"%^BOLD%^%^RED%^ buries the barbed tip of "+ETO->QP+" spear "+
                "in your "+tlim+" and you feel it %^BOLD%^%^CYAN%^SUCKING%^BOLD%^%^RED%^ "+
                "the life from you before "+ETO->QS+" %^BOLD%^%^BLACK%^RIPS%^BOLD%^%^RED%^ it "+
                "violently from the wound!%^RESET%^");
                
                tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ buries the barbed tip of "+ETO->QP+" spear "+
                "in "+targ->QCN+"%^BOLD%^%^RED%^'s "+tlim+" and then %^BOLD%^%^BLACK%^RIPS%^BOLD%^"+
                "%^RED%^ it violently from the wound!%^RESET%^", ({targ, ETO}));
                
                dam = roll_dice(3,6);
                wound = new(ELOB+"grievous_wound");
                wound->set_for(tlim, dam);
                wound->move(targ);
                targ->cause_typed_damage(targ, tlim, dam, "piercing");
                ETO->heal(dam);
                return 0;
                break;
        }               
    }
    return 0;      
}

