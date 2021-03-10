#include <std.h>
inherit "/d/common/obj/weapon/hhlance";

void create() 
{
    ::create();
    set_name("lance of thorns");
    set_id(({"lance", "thorn lance", "lance of thorns", 
    "thorn lance"}));
    set_obvious_short("%^RESET%^%^GREEN%^heavy oak lance%^RESET%^");
    
    set_short("%^BOLD%^%^GREEN%^L%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nc%^RESET%^%^ORANGE%^"+
    "e o%^BOLD%^%^GREEN%^f th%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^rns%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^This lance is carved from a piece of very heavy "+
    "%^RESET%^%^GREEN%^oak%^RESET%^%^ORANGE%^. The base of it is wide, with a "+
    "segment of it carved slightly narrower in order to allow someone to grip it with relative "+
    "ease. As the lance lengthens it thins and toward the very tip of it there are several "+
    "%^BOLD%^%^GREEN%^vicious thorns%^RESET%^%^ORANGE%^ jutting out from it at odd angles. Each of the "+
    "thorns is a deep %^RESET%^%^MAGENTA%^purple%^RESET%^%^ORANGE%^ color."+
    " You quickly realize that they are actually small pointed spikes, made from a "+
    "deep %^RESET%^%^MAGENTA%^purple%^RESET%^%^ORANGE%^ metallic substance. Each has been inserted "+
    "through the lance from one side to the other. There are numerous %^BOLD%^%^BLACK%^scorch%^RESET%^"+
    "%^ORANGE%^ marks the entire length of the it.%^RESET%^");

    set_lore("%^RESET%^%^GREEN%^These lances were standard equipment for an ancient order "+
    "of Knights, dedicated to Lysara. They were made specifically with the intention of "+
    "ripping apart undeath filth. The original creator of them has long been lost to the passage "+
    "of time, but it is believed that he was some Knight of Renown who had dedicated himself to the "+
    "destruction on undeath where ever he might find it. Some say that he imbued the lances to "+
    "emit fire to burn away undead in combat.\n\n"+
    "It is somewhat alarming that these lances have turned up recently on Eldebaro. Supposedly they "+
    "are wielded by several apparent Knights who have lost their sanity and roam the island. Some stories "+
    "are suggesting that these Knights are the very same ancient order that once served Lysara. Others "+
    "say that they are the ancestors of those Knights. Whichever story is true, if either, remains a "+
    "mystery.%^RESET%^");
    
    set_property("lore difficult", 25);
    set_value(4500);
    set_property("enchantment",5);
    set_wield((:TP,"wield":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"check":));
    set_item_bonus("strength", 4);
    set_item_bonus("fire resistance", 20);
}

int wield()
{
    tell_object(ETO, "%^RESET%^%^ORANGE%^You sense an ancient knowledge seep out "+
    "from the lance and feel yourself grow stronger!%^RESET%^");
    return 1;
}

int removeme()
{
    tell_object(ETO, "%^RESET%^%^ORANGE%^You feel the ancient knowledge slip away from "+
    "you as you release the lance.%^RESET%^");
    return 1;
}

int check(object targ)
{
    string targRace;
    int is_undead, dam;
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;    
    if(random(100) < 70) return 0;
    
    targRace = (string)targ->query_race();
    if((int)targ->query_property("undead") || targRace == "undead"
    || targRace == "zombie" || targRace == "skeleton")
    {
        is_undead = 1;
    }
    else is_undead = 0;
    switch(random(10))
    {
        case 0..8:
            tell_object(ETO, "%^BOLD%^%^GREEN%^You %^BOLD%^%^RED%^IMB%^BOLD%^%^BLACK%^E%^BOLD%^%^RED%^D%^BOLD%^%^GREEN%^"+
            " your lance deep into "+targ->QCN+"%^BOLD%^%^GREEN%^'s torso and %^BOLD%^%^YELLOW%^TWIST%^BOLD%^%^GREEN%^"+
            " the thorns around inside as "+targ->QS+" %^BOLD%^%^RED%^SCREAMS%^BOLD%^%^GREEN%^ in %^BOLD%^%^BLACK%^PAIN%^BOLD%^%^GREEN%^!%^RESET%^");
    
            tell_object(targ, ETOQCN+"%^BOLD%^%^GREEN%^ %^BOLD%^%^RED%^IMB%^BOLD%^%^BLACK%^E%^BOLD%^%^RED%^DS%^BOLD%^%^GREEN%^"+
            " "+ETO->QP+" lance deep into your torso and %^BOLD%^%^YELLOW%^TWISTS%^BOLD%^%^GREEN%^"+
            " the thorns around inside!! You %^BOLD%^%^RED%^SCREAM%^BOLD%^%^GREEN%^ in %^BOLD%^%^BLACK%^PAIN%^BOLD%^%^GREEN%^!%^RESET%^");
    
            tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ %^BOLD%^%^RED%^IMB%^BOLD%^%^BLACK%^E%^BOLD%^%^RED%^DS%^BOLD%^%^GREEN%^"+
            " "+ETO->QP+" lance deep into "+targ->QCN+"%^BOLD%^%^GREEN%^'s torso and %^BOLD%^%^YELLOW%^TWISTS%^BOLD%^%^GREEN%^"+
            " the thorns around inside as "+targ->QS+" %^BOLD%^%^RED%^SCREAMS%^BOLD%^%^GREEN%^ in %^BOLD%^%^BLACK%^PAIN%^BOLD%^%^GREEN%^!%^RESET%^", ({ETO, targ}));
            if(is_undead) return roll_dice(2,20);
            else return roll_dice(2, 8);
            break;
        case 9:
            tell_object(ETO, "%^BOLD%^%^RED%^A brilliant burst of %^RESET%^%^RED%^FL%^BOLD%^%^YELLOW%^A%^RESET%^%^RED%^M"+
            "%^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^ erupts from the end of your lance and envelopes "+targ->QCN+"%^BOLD%^%^RED%^!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^RED%^A brilliant burst of %^RESET%^%^RED%^FL%^BOLD%^%^YELLOW%^A%^RESET%^%^RED%^M"+
            "%^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^ erupts from the end of "+ETOQCN+"%^BOLD%^%^RED%^'s lance and envelopes you!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^RED%^A brilliant burst of %^RESET%^%^RED%^FL%^BOLD%^%^YELLOW%^A%^RESET%^%^RED%^M"+
            "%^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^ erupts from the end of "+ETOQCN+"%^BOLD%^%^RED%^'s lance and envelopes "+
            targ->QCN+"%^BOLD%^%^RED%^!%^RESET%^", ({ETO, targ}));
            if(is_undead) dam = roll_dice(20, 6);
            else dam = roll_dice(4, 6);
            targ->cause_typed_damage(targ, targ->return_target_limb(), dam, "fire");
            return 0;
            break;
    }
    return 0;
            
}


int query_size()
{
    if(objectp(ETO)&&living(ETO)) return (int)ETO->query_size();
    return ::query_size();
}
