#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

mixed master;
int GaveUp, MyPower;

void create()
{
    ::create();
    set_name("two handed sword");
    set_id(({"sword", "two handed sword", "large sword",
    "blasphemy", "purple sword", "purple blade", "blade",
    "large blade", "two handed purple sword", "two handed blade"}));

    set_obvious_short("%^BOLD%^%^BLACK%^A %^BLACK%^t%^MAGENTA%^w%^MAGENTA%^o %^BLACK%^han%^MAGENTA%^d%^BLACK%^ed %^BLACK%^p%^MAGENTA%^u%^MAGENTA%^r%^BLACK%^p%^MAGENTA%^l%^MAGENTA%^e %^MAGENTA%^b%^BLACK%^lade%^RESET%^");

    set_short("%^BOLD%^%^BLACK%^Bl%^MAGENTA%^a%^BOLD%^%^BLACK%^sph"+
    "%^MAGENTA%^e%^BOLD%^%^BLACK%^my%^RESET%^");

    set_long("%^BOLD%^%^MAGENTA%^This large two handed blade is composed of "+
    "a %^BOLD%^%^WHITE%^br%^BOLD%^%^MAGENTA%^i%^BOLD%^%^WHITE%^ll%^BOLD%^%^MAGENTA%^"+
    "ia%^BOLD%^%^WHITE%^nt%^BOLD%^%^MAGENTA%^ purple substance. It does not "+
    "feel metallic at all. It seems to be another more primitive mineral "+
    "based substance, almost like stone. The blade of it has been sharpened to "+
    "a fine %^BOLD%^%^BLACK%^edge%^BOLD%^%^MAGENTA%^ on both sides and "+
    "extends nearly six feet. The hilt of this heavy blade has been forged "+
    "from a %^RESET%^%^MAGENTA%^deeper purple%^BOLD%^ stone and formed into "+
    "the shape of a r%^BOLD%^%^GREEN%^e%^MAGENTA%^pt%^BOLD%^%^GREEN%^i%^MAGENTA%^"+
    "ll%^GREEN%^ian %^RESET%^%^WHITE%^skull%^BOLD%^%^MAGENTA%^. The handle of the "+
    "blade is composed of an almost pure %^BOLD%^%^BLACK%^black%^BOLD%^%^MAGENTA%^"+
    " stone. It is lined with %^BOLD%^%^CYAN%^glyphs%^BOLD%^%^MAGENTA%^ which almost "+
    "radiate a tangible %^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^u%^BOLD%^%^WHITE%^"+
    "r%^RESET%^%^WHITE%^a%^BOLD%^%^MAGENTA%^. Apart from the strange "+
    "%^BOLD%^%^CYAN%^glyphs%^BOLD%^%^MAGENTA%^ it appears quite dull.%^RESET%^");

    set_lore("%^BOLD%^%^MAGENTA%^This strange weapon was said to have been "+
    "one of the last ever enchanted by Aorus Devar, before he disappeared. "+
    "The legend suggests that it was brought before him by an evil knight in "+
    "an attempt to get Aorus Devar to condemn the weapon with his unholy "+
    "power. The legend suggest that this knight, alone with many others, "+
    "failed to truly grasp what Aorus Devar was or wanted. He did imbue "+
    "the weapon with power, unholy power, though the knight was never again "+
    "seen or heard from. Some stories suggest that Aorus Devar had prepared a method of "+
    "cleaning this weapon of its evil, though there are no details beyond that."+
    "%^RESET%^");

    set_property("lore difficulty", 25);
    set_value(10000);
    set_property("no curse", 1);
    set_property("enchantment",5);
    set_decay_rate(0);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("damage bonus", 3);
    set_item_bonus("attack bonus", 3);
    set_item_bonus("strength", 4);
    master = 0;
    GaveUp = 0;
    MyPower = 0;
}

int wield_func()
{
    if(stringp(master) && ETO->query_name() != master)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ I will NEVER SUBMIT TO YOU!%^RESET%^");
        tell_object(ETO, "%^BOLD%^%^MAGENTA%^You cannot seem to grasp the handle of the blade, as if it keeps moving "+
        "out of your reach somehow.%^RESET%^");
        return 0;
    }

    tell_object(ETO, "%^BOLD%^%^MAGENTA%^You carefully grasp the handle of the "+
    "purple blade and feel stronger as an unholy presences enters your mind.%^RESET%^");

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^MAGENTA%^ seems shaken and stares off in "+
        "almost trance like state for a brief moment.%^RESET%^", ETO);
    }

    if(master && ETO->query_name() == master)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ hello "+capitalize(master)+", I am "+
        "glad that you have finally embraced me!%^RESET%^");
    }
    if(!GaveUp) set_heart_beat(1);
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^MAGENTA%^You quickly release the handle of the purple"+
    " blade and feel weaker as the unholy presence leaves your mind!%^RESET%^");

    if(!stringp(master))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ until next time, my puppet!%^RESET%^");
        set_heart_beat(0);
    }
    if(stringp(master) && ETO->query_name() == master)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ very well "+capitalize(master)+", "+
        "I shall eagerly await your embrace.%^RESET%^");
    }

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^MAGENTA%^ suddenly seems relieved.%^RESET%^", ETO);
    }
    return 1;
}

void heart_beat()
{
    object *targs, targ, weap, *weaps;
    string func;
    mixed funcs;
    int x, hits;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!living(ETO) || !TO->query_wielded())
    {
        set_heart_beat(0);
        return;
    }
    if(!stringp(master))
    {
        if(random(70)) return;
        switch(ETO->query_alignment())
        {
            case 3: case 6: case 9:
                switch(random(80))
                {
                    case 0..35:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ perhaps we "+
                        "might get along afterall.... I am not quite sure just yet.");
                        return;
                        break;
                    case 36..59:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ Do you know that "+
                        "Aorus Devar is one of the strangest creatures... that I have ever encountered... and then "+
                        "there is **YOU**. I am still not quite sure what to make of that....%^RESET%^");
                        return;
                        break;
                    case 60..70:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^You seem like "+
                        "my type... but I am still not sure... I need some more time to make up my mind.");
                        return;
                        break;
                    case 71..76:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^I am leaning "+
                        "toward you... but I don't know. What have **YOU** ever done for me?");
                        return;
                        break;
                    case 77..79:
                        if(random(2)) return;
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ well it "+
                        "looks like you're not going anywhere and neither am I. You'll have to do... I am "+
                        "attuning myself to you, for now... don't make me regret my decision!");
                        master = ETO->query_name();
                        break;
                }
            default:
                switch(random(75))
                {
                    case 0..35:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ your "+
                        "self righteousness disgusts me! You are a filthly animal just like anything else!!");
                        return;
                        break;
                    case 36..58:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ why "+
                        "are **YOU** still holding me??? Put me down already before you **REGRET** "+
                        "it!!");
                        return;
                        break;
                    case 59..70:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^I am **WARNING**"+
                        " you one more time... put me down **NOW** or suffer the consequences!");
                        return;
                        break;
                    case 71..73:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^This is your "+
                        "**ABSOLUTELY** last **WARNING** next time I get pissed!!");
                        return;
                        break;
                    case 74:
                        if(random(3)) return;
                        set_decay_rate(10);
                        if(random(2))
                        {
                            targs = all_living(EETO);
                            targs -= ({ETO});
                            if(!sizeof(targs)) return;
                            targ = targs[random(sizeof(targs))];
                            if(!objectp(targ)) return;
                            if(targ->query_invis()) return;
                            if(avatarp(targ)) return;
                            //if(avatarp(ETO)) return;
                            tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                            "You **SHOULD** have listened to me when you had the chance!");
                            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel some unholy presence "+
                            "compel you to attack "+targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^");
                            tell_object(targ, "%^BOLD%^%^BLACK%^Suddenly "+ETOQCN+"%^BOLD%^%^BLACK%^"+
                            " looks enraged by you and attacks!%^RESET%^");
                            tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ suddenly looks enraged by "+
                            targ->QCN+"%^BOLD%^%^BLACK%^ and attacks "+ETO->QO+"!%^RESET%^", ({ETO, targ}));
                            ETO->force_me("kill "+targ->query_name());
                            ETO->add_attacker(targ);
                            targ->add_attacker(ETO);
                            return;
                        }
                        else
                        {
                            tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^ "+
                            "You **SHOULD** have listened to me when you had the chance! I'm "+
                            "checking out and leaving you with a surprise!");
                            while(TO->query_property("enchantment") >= 0)
                            {
                                TO->remove_property("enchantment");
                                TO->set_property("enchantment", -2);
                            }
                            set_heart_beat(0);
                            GaveUp = 1;
                        }
                }
        }
    }
    if(stringp(master))
    {
        if(random(60)) return;
        switch(random(20))
        {
            case 0..9:
                if(sizeof(targs = ETO->query_attackers()))
                {
                    tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ are "+
                    "these **FOOLS** bothering you? Allow me to help!");
                    x = sizeof(targs);
                    while(x--)
                    {
                        targ = targs[x];
                        if(!objectp(targ) && environment(targ) != EETO) continue;
                        tell_object(ETO, "%^BOLD%^%^BLACK%^A bolt of pure %^BOLD%^%^MAGENTA%^u%^BOLD%^"+
                        "%^BLACK%^nh%^BOLD%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ly %^BOLD%^%^GREEN%^"+
                        "e%^BOLD%^%^BLACK%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^rgy "+
                        "zaps from the blade and slams into "+targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^");

                        tell_object(targ, "%^BOLD%^%^BLACK%^A bolt of pure %^BOLD%^%^MAGENTA%^u%^BOLD%^"+
                        "%^BLACK%^nh%^BOLD%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ly %^BOLD%^%^GREEN%^"+
                        "e%^BOLD%^%^BLACK%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^rgy "+
                        "zaps from "+ETOQCN+"%^BOLD%^%^BLACK%^'s blade and slams into you!%^RESET%^");

                        tell_room(EETO, "%^BOLD%^%^BLACK%^A bolt of pure %^BOLD%^%^MAGENTA%^u%^BOLD%^"+
                        "%^BLACK%^nh%^BOLD%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ly %^BOLD%^%^GREEN%^"+
                        "e%^BOLD%^%^BLACK%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^rgy "+
                        "zaps from "+ETOQCN+"%^BOLD%^%^BLACK%^'s blade and slams into "+
                        targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^", ({ETO, targ}));
                        targ->cause_typed_damage(targ, 0, roll_dice(2,8), "negative energy");
                        continue;
                    }
                }
                else
                {
                    if(random(20)) return;
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    "so are we going to fight anything or do you plan on just wasting away?");
                }
                return;
                break;
            case 10..18:
                if(sizeof(targs = ETO->query_attackers()))
                {
                    tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
                    "I'll be **DAMNED** it looks like you do know how to cause chaos! Let me make "+
                    "sure you can continue!");
                    x = sizeof(targs);
                    if((int)ETO->query_hp() <= (int)ETO->query_max_hp())
                    {
                        tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the unholy presence blending its "+
                        "life force with your own as your wounds begin to mend!%^RESET%^");
                        tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^'s wounds begin %^BOLD%^%^CYAN%^"+
                        "mending%^BOLD%^%^BLACK%^ on their own!%^RESET%^", ETO);

                        ETO->heal(roll_dice(2, 6) * x);
                    }
                    else
                    {
                        if((int)ETO->query_extra_hp() < 100)
                        {
                            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the unholy presence blending its "+
                            "life force with your own and you feel vigorous!%^RESET%^");

                            tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ suddenly looks vigorous!%^RESET%^", ETO);
                            ETO->add_extra_hp(roll_dice(1, 8) * x);
                        }
                    }
                }
                else
                {
                    if(random(20)) return;
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    " What is this??? A nice day for a stroll??? I am starting to regret my decision already....");
                }
                return;
                break;
            case 19:
                if(sizeof(targs = ETO->query_attackers()))
                {
                    tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
                    "I think you're going to like this trick!! I'll show you what I am truly "+
                    "**CAPABLE** of!%^RESET%^");
                    hits = 0;
                    x = random(sizeof(targs)) + 1;
                    while(x--)
                    {
                        if(x > sizeof(targs)) break;
                        targ = targs[x];
                        if(!objectp(targ)) continue;
                        if(targ->query_property("no death") && !userp(targ)) continue;
                        if(userp(targ))
                        {
                            weaps = targ->query_wielded();
                            if(!sizeof(weaps)) continue;
                            weap = weaps[random(sizeof(weaps))];
                            if(!objectp(weap)) continue;
                            func = weap->query_hit();
                            if(!stringp(func)) continue;
                            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the unholy presence %^BOLD%^%^MAGENTA%^"+
                            "manipulating the very fabric of the "+weap->query_short()+"%^BOLD%^%^BLACK%^ wielded by "+
                            targ->QCN+"!%^RESET%^");

                            tell_object(targ, "%^BOLD%^%^BLACK%^You feel an unholy presence suddenly "+
                            "%^BOLD%^%^MAGENTA%^manipulating the very fabric of your "+weap->query_short()+
                            "%^BOLD%^%^BLACK%^!%^RESET%^");

                            tell_room(EETO, targ->QCN+"%^BOLD%^%^BLACK%^ stares in horror at "+targ->QP+
                            " "+weap->query_short()+"%^BOLD%^%^BLACK%^!%^RESET%^", ({ETO, targ}));

                            call_other(weap, func, targ);
                            hits++;
                            continue;
                        }
                        else
                        {
                            funcs = targ->query_funcs();
                            func = funcs[random(sizeof(funcs))];
                            if(!stringp(func)) continue;

                            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the unholy presence %^BOLD%^%^MAGENTA%^"+
                            "manipulating%^BOLD%^%^BLACK%^ the very fabric of "+targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^");

                            tell_object(targ, "%^BOLD%^%^BLACK%^You feel an unholy presence suddenly "+
                            "%^BOLD%^%^MAGENTA%^manipulating%^BOLD%^%^BLACK%^ the very fabric of your being!%^RESET%^");

                            tell_room(EETO, targ->QCN+"%^BOLD%^%^BLACK%^ suddenly stares off in "+
                            "horror!%^RESET%^", ({ETO, targ}));

                            hits++;
                            call_other(targ, func, targ);
                            continue;
                        }
                        continue;
                    }
                    if(hits)
                    {
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
                        "did you see that?? That is only a fraction of what I am **CAPABLE** of!! "+
                        "Hail to **ME**!");
                    }
                    else
                    {
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
                        "well that was slightly disappointing! Maybe you should try fighting something "+
                        "a little **TOUGHER**???");
                    }
                    return;
                    break;
                }
                else
                {
                    if(random(20)) return;
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    " BLOOD, BLOOD makes the grass grow!! **AND** we want it to **GROW**");
                }
                return;
                break;
        }

    }
}

int hit_func(object targ)
{
    int dam;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!stringp(master) && !random(20))
    {
        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^I guess I should be "+
        "thankful for the taste of %^RESET%^%^RED%^BLOOD!");

        tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the unholy presence lash out at "+targ->QCN+
        " edding away at "+targ->QP+" %^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
        "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e!%^RESET%^");

        tell_object(targ, "%^BOLD%^%^BLACK%^You feel an unholy presence edding away at "+
        "your %^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
        "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e!%^RESET%^ %^BOLD%^%^BLACK%^ as "+ETOQCN+
        "%^BOLD%^%^BLACK%^'s blade slices into you!");

        tell_room(EETO, targ->QCN+"%^BOLD%^%^BLACK%^ suddenly looks weaker as "+ETOQCN+
        "%^BOLD%^%^BLACK%^'s blade slices into "+targ->QO+"!%^RESET%^", ({ETO, targ}));

        targ->cause_typed_damage(targ, "torso", roll_dice(1,10), "negative energy");

        return 0;
    }
    if(stringp(master) && !random(5))
    {
        if(MyPower >= 150)
        {
            tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
            "yes... Yes... YES!!!! WATCH YOUR FOE SUFFER!!!");

            tell_object(ETO, "%^BOLD%^%^BLACK%^A brilliant explosion of pure %^BOLD%^%^WHITE%^D"+
            "%^BLACK%^A%^WHITE%^RKN%^BLACK%^E%^WHITE%^SS %^BOLD%^%^BLACK%^ erupts %^BOLD%^%^MAGENTA%^"+
            "VIOLENTLY%^BOLD%^%^BLACK%^ from the blade and slams into "+targ->QCN+
            "%^BOLD%^%^BLACK%^ with tremendous force, knocking "+targ->QO+
            " to the ground!%^RESET%^");

            tell_object(targ, "%^BOLD%^%^BLACK%^A brilliant explosion of pure %^BOLD%^%^WHITE%^D"+
            "%^BLACK%^A%^WHITE%^RKN%^BLACK%^E%^WHITE%^SS %^BOLD%^%^BLACK%^ erupts %^BOLD%^%^MAGENTA%^"+
            "VIOLENTLY%^BOLD%^%^BLACK%^ from "+ETOQCN+"%^BOLD%^%^BLACK%^'s blade and slams into "+
            "%^BOLD%^%^BLACK%^you with tremendous force, knocking you"+
            " to the ground!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^BLACK%^A brilliant explosion of pure %^BOLD%^%^WHITE%^D"+
            "%^BLACK%^A%^WHITE%^RKN%^BLACK%^E%^WHITE%^SS %^BOLD%^%^BLACK%^ erupts %^BOLD%^%^MAGENTA%^"+
            "VIOLENTLY%^BOLD%^%^BLACK%^ from "+ETOQCN+"%^BOLD%^%^BLACK%^'s blade and slams into "+
            targ->QCN+"%^BOLD%^%^BLACK%^ with tremendous force, knocking "+ETO->QO+
            " to the ground!%^RESET%^");
            dam = MyPower;
            if(!random(25)) dam = MyPower * 2;
            MyPower = 0;
            targ->set_tripped(2, "%^BOLD%^%^BLACK%^You are struggling to get back up!%^RESET%^");
            targ->cause_typed_damage(targ, "torso", dam, "negative energy");
            return 0;
        }
        else
        {
            switch(random(20))
            {
                case 0..6:
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^Ahh... "+
                    "how I LOVE the taste of blood! Let me show you how it replenishes!");

                    tell_object(ETO, "%^BOLD%^%^BLACK%^The blade saps some of "+targ->QCN+
                    "%^BOLD%^%^BLACK%^'s "+
                    "%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
                    "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e%^RESET%^ %^BOLD%^%^BLACK%^"+
                    "and r%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^pl%^BOLD%^%^CYAN%^e"+
                    "%^BOLD%^%^BLACK%^nish%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^"+
                    "s you with it!%^RESET%^");

                    tell_object(targ, "%^BOLD%^%^BLACK%^You feel your very "+
                    "%^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
                    "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e%^RESET%^ being sapped "+
                    "away by "+ETOQCN+"%^BOLD%^%^BLACK%^'s %^MAGENTA%^blade!%^RESET%^");

                    tell_room(EETO, targ->QCN+"%^BOLD%^%^BLACK%^'s very "+
                    "%^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
                    "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e%^RESET%^%^BOLD%^%^BLACK%^ is "+
                    "sapped away by "+ETOQCN+"%^BOLD%^%^BLACK%^'s %^MAGENTA%^"+
                    "blade!%^RESET%^", ({ETO, targ}));

                    dam = roll_dice(2, 8);
                    MyPower += dam;
                    if((int)ETO->query_hp() < (int)ETO->query_max_hp()) ETO->heal(dam);
                    else if((int)ETO->query_extra_hp() < 100) ETO->add_extra_hp(dam);

                    targ->cause_typed_damage(targ, "torso", dam, "negative energy");
                    return 0;
                    break;

                case 7..15:
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    "I love it when we fight, when I get to taste battle and chaos!! THIS IS "+
                    "WHEN I THRIVE!!");

                    tell_object(ETO, "%^BOLD%^%^BLACK%^The blade sinks deep "+
                    "into "+targ->QCN+ "%^BOLD%^%^BLACK%^ and as you pull it "+
                    "out you feel it ripping and tearing "+
                    "inside of "+targ->QO+"!%^RESET%^");

                    tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^'s blade sinks deep "+
                    "into you and you feel it T%^BOLD%^%^RED%^EA%^BOLD%^%^BLACK%^R"+
                    "%^BOLD%^%^RED%^I%^BOLD%^%^BLACK%^NG and R%^RESET%^%^RED%^I"+
                    "%^BOLD%^%^BLACK%^PP%^RESET%^%^RED%^I%^BOLD%^%^BLACK%^NG "+
                    "your insides as "+ETO->QS+" pulls it out!%^RESET%^");

                    tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^'s blade sinks deep "+
                    "into "+targ->QCN+"%^BOLD%^%^BLACK%^ and "+targ->QS+" doubles "+
                    "over in %^BOLD%^%^GREEN%^AG%^RESET%^%^GREEN%^O%^BOLD%^%^GREEN%^"+
                    "NY%^BOLD%^%^BLACK%^!%^RESET%^", ({ETO, targ}));

                    targ->set_paralyzed(20, "%^BOLD%^%^MAGENTA%^You are recovering "+
                    "from the agonizing pain!%^RESET%^");

                    dam = roll_dice(2, 8);
                    MyPower += dam;
                    return dam;
                    break;
                case 16..19:
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^You "+
                    "aren't that bad... perhaps I can help you against this fool!");

                    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel a wave of unholy %^BOLD%^"+
                    "%^GREEN%^e%^BOLD%^%^BLACK%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^rgy "+
                    "wash over you and form a layer of protection!%^RESET%^");

                    tell_room(EETO, "%^BOLD%^%^BLACK%^You watch as a layer of "+
                    "pr%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^t%^BOLD%^%^CYAN%^e"+
                    "%^BOLD%^%^BLACK%^ct%^BOLD%^%^CYAN%^io%^BOLD%^%^BLACK%^n "+
                    "forms over "+ETOQCN+"%^BOLD%^%^BLACK%^!%^RESET%^", ETO);
                    dam = roll_dice(2, 8);
                    MyPower += dam;
                    ETO->set_stoneSkinned(dam);
                    return 0;
            }
        }
    }
    return 0;
}
