#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create()
{
    ::create();
    set_name("curved dagger");
    set_id(({"curved dagger", "dagger", "curving dagger", "dark bladed dagger",
    "mind pierce", "mindpierce"}));

    set_obvious_short("%^BOLD%^%^CYAN%^curved %^RESET%^%^CYAN%^dark%^BOLD%^ "+
    "bladed dagger%^RESET%^");

    set_short("%^BOLD%^%^CYAN%^M%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^ndp%^RESET%^%^CYAN%^ie"+
    "%^BOLD%^%^CYAN%^rc%^RESET%^%^CYAN%^e%^RESET%^");
	
    set_long("%^BOLD%^%^CYAN%^This dagger is forged from a %^RESET%^%^CYAN%^dark blue"+
    "%^BOLD%^%^CYAN%^ metal that seems to emit a low frequency hum constantly. The blade "+
    "of it extends approximately ten inches in length and is curved, almost like a scimitar. "+
    "There are %^RESET%^%^CYAN%^strange symbols%^BOLD%^%^CYAN%^ engraved into the length of it "+
    "that seem to flash occasionally but only for a brief moment before they go dull again. One edge "+
    "of the blade is %^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^zor%^BOLD%^%^CYAN%^ sharp. A "+
    "small crossguard, made from a brighter azure material rests beneath the blade and attachs "+
    "it to the hilt of the dagger. The hilt is engraved with more %^RESET%^%^CYAN%^strange symbols"+
    "%^BOLD%^%^CYAN%^ which seem permenantly dull. A pommel made from %^BOLD%^%^GREEN%^em%^RESET%^"+
    "%^GREEN%^e%^BOLD%^rald%^BOLD%^%^CYAN%^ balloons out from the bottom of the hilt.%^RESET%^");

    set_lore("%^BOLD%^%^CYAN%^These daggers, known invidivually as 'mindpierce' where "+
    "forged by some forgotten blacksmith for a creature known as the collector. It is said "+
    "that the collector has always had a host of servants working for him, 'collecting things' and "+
    "that he sometimes grants them one of these weapons to help make sure that they can collect "+
    "from those who are familiar with magic or psionics. Never before has one of them surfaced and "+
    "mostly they were considered nothing more than an old and slightly odd rumor, just like the "+
    "collector himself. Supposedly these weapons were made with the ability to pierce the mind of "+
    "whoever they strike in combat.%^RESET%^");

    set_property("lore difficulty", 22);
    set_value(3000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("dexterity", 4);
}

int wield_func()
{
    if((int)ETO->query_highest_level() < 35)
    {
        tell_object(ETO, "%^BOLD%^%^CYAN%^The dagger will never be wielded "+
        "by someone as %^BOLD%^%^RED%^weak%^BOLD%^%^CYAN%^ as you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel a quickness settle over you and "+
    "the essence of something blends with your own!%^RESET%^");
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel the quickness and the essence "+
    "fade away!%^RESET%^");
    return 1;
}

int forget_random(object vic)
{
    string *classes, myclass, spell, *spells;
    int x, max = 0, y;
    mapping tmp;
    int *lvls;

    if(!objectp(vic)) return 0;
    classes = vic->query_classes();

    for(x = 0;x< sizeof(classes);x++)
    {
       tmp = vic->query_all_memorized(classes[x]);
       lvls = keys(tmp);
       if(!sizeof(lvls)) continue;
       for(y = 0;y < sizeof(lvls);y++)
       {
           spells = keys(tmp[lvls[y]]);
           if(!sizeof(spells)) continue;
           if(max < lvls[y])
           {
               max = lvls[y];
               myclass = classes[x];
               spell = spells[random(sizeof(spells))];
               continue;
           }
           continue;
        }
     }
     if(max && stringp(spell))
     {
         if(spell == "generic")
         {
             vic->forget_memorized(myclass, "level "+max);
             return 1;
         }
         else
         {
             vic->forget_memorized(myclass, spell);
             return 1;
         }
     }
     return 0;
}



int hit_func(object targ)
{
    string tlimb;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(1000) < 325)
    {
        switch(random(10))
        {
            case 0..8:
                tlimb = targ->return_target_limb();
                tell_object(ETO, "%^BOLD%^%^CYAN%^You stab into "+targ->QCN+"%^BOLD%^%^CYAN%^'s "+
                tlimb+"!%^RESET%^");
				
                tell_object(targ, ETOQCN +"%^BOLD%^%^CYAN%^ stabs "+ETO->QP+" dagger into "+
                "your "+tlimb+"!%^RESET%^");
				
                tell_room(EETO, ETOQCN +"%^BOLD%^%^CYAN%^ stabs "+ETO->QP+" dagger into "+
                targ->QCN+"%^BOLD%^%^CYAN%^'s "+tlimb+"!%^RESET%^", ({ETO, targ}));
                
                if(!random(10)) 
                {
                    tell_object(ETO, "%^RESET%^%^CYAN%^You use "+targ->QCN+"%^RESET%^%^CYAN%^'s "+
                    "surprise to launch another attack!%^RESET%^");
                    
                    tell_object(targ, ETOQCN+"%^RESET%^%^CYAN%^ uses your surprise to launch "+
                    "another attack!%^RESET%^");
                    
                    tell_room(EETO, ETOQCN+"%^RESET%^%^CYAN%^ uses "+targ->QCN+"%^RESET%^%^CYAN%^'s "+
                    "surprise to launch another attack!%^RESET%^", ({ETO, targ}));
                    
                    ETO->execute_attack();
                }                
                return roll_dice(2,6);
                break;
            case 9:
            
                tell_object(ETO, "%^BOLD%^%^CYAN%^The symbols along the length of the blade "+
                "suddenly %^BOLD%^%^YELLOW%^F%^BOLD%^%^WHITE%^L%^BOLD%^%^RED%^A%^BOLD%^%^YELLOW%^S"+
                "%^BOLD%^%^WHITE%^H%^BOLD%^%^CYAN%^ erratically as it sinks into "+targ->QCN+
                "%^BOLD%^%^CYAN%^!%^RESET%^");
                
                tell_object(targ, "%^BOLD%^%^CYAN%^The symbols along the length of "+ETO->QCN+
                "%^BOLD%^%^CYAN%^'s dagger suddenly %^BOLD%^%^YELLOW%^F%^BOLD%^%^WHITE%^L"+
                "%^BOLD%^%^RED%^A%^BOLD%^%^YELLOW%^S"+
                "%^BOLD%^%^WHITE%^H%^BOLD%^%^CYAN%^ erratically as it sinks into you!%^RESET%^");
  
                tell_room(EETO, "%^BOLD%^%^CYAN%^The symbols along the length of "+ETO->QCN+
                "%^BOLD%^%^CYAN%^'s dagger suddenly %^BOLD%^%^YELLOW%^F%^BOLD%^%^WHITE%^L"+
                "%^BOLD%^%^RED%^A%^BOLD%^%^YELLOW%^S"+
                "%^BOLD%^%^WHITE%^H%^BOLD%^%^CYAN%^ erratically as it sinks into "+targ->QCN+
                "%^BOLD%^%^CYAN%^!%^RESET%^", ({ETO, targ}));
                
                if(forget_random(targ))
                {
                    tell_object(targ, "%^BOLD%^%^WHITE%^You feel something pulled from your mind!%^RESET%^");
                }
                return roll_dice(2, 6)+2;
                break;
        }
    }
}

