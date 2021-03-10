#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

mixed master;
int GaveUp, MyPower;

void create()
{
    ::create();
    set_name("two handed sword");
    set_id(({"sword", "two handed sword", "large sword",
    "redemption", "yellow sword", "yellow blade", "blade",
    "large blade", "two handed yellow sword", "two handed blade"}));

    set_obvious_short("%^BOLD%^%^WHITE%^A %^WHITE%^tw%^ORANGE%^o %^ORANGE%^h%^WHITE%^and%^ORANGE%^e%^WHITE%^d %^WHITE%^g%^ORANGE%^o%^WHITE%^ld%^ORANGE%^e%^ORANGE%^n %^ORANGE%^b%^WHITE%^lade%^RESET%^");

    set_short("%^BOLD%^%^WHITE%^R%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^"+
    "d%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^mpt%^BOLD%^%^YELLOW%^"+
    "io%^BOLD%^%^WHITE%^n%^RESET%^");

    set_long("%^BOLD%^%^YELLOW%^This large two handed blade is composed of "+
    "a %^BOLD%^%^WHITE%^br%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ll%^BOLD%^%^YELLOW%^"+
    "ia%^BOLD%^%^WHITE%^nt%^BOLD%^%^YELLOW%^ substance. It does not "+
    "feel metallic at all. It seems to be another more primitive mineral "+
    "based substance, almost like stone. The blade of it has been sharpened to "+
    "a fine %^BOLD%^%^WHITE%^edge%^BOLD%^%^YELLOW%^ on one side and "+
    "extends nearly six feet. The hilt of this heavy blade has been forged "+
    "from a %^RESET%^%^YELLOW%^deeper yellow%^BOLD%^ stone and formed into "+
    "the shape of two %^BOLD%^%^WHITE%^a%^RESET%^rms%^BOLD%^%^YELLOW%^ "+
    "folded into a %^BOLD%^%^WHITE%^cr%^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^"+
    "ss%^BOLD%^%^YELLOW%^. The handle of the "+
    "blade is composed of an almost pure %^BOLD%^%^WHITE%^white m"+
    "%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^rbl%^BOLD%^%^BLACK%^e%^BOLD%^%^YELLOW%^. "+
    "It is lined with %^BOLD%^%^CYAN%^glyphs%^BOLD%^%^YELLOW%^ which almost "+
    "radiate a tangible %^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^u%^BOLD%^%^WHITE%^"+
    "r%^RESET%^%^WHITE%^a%^BOLD%^%^YELLOW%^. Apart from the strange "+
    "%^BOLD%^%^CYAN%^glyphs%^BOLD%^%^YELLOW%^ it appears quite dull.%^RESET%^");

    set_lore("%^BOLD%^%^YELLOW%^This strange weapon was said to have been "+
    "one of the last ever enchanted by Aorus Devar, before he disappeared. "+
    "The legend suggests that an unholy knight sought out Aorus Devar to "+
    "enchant another blade with unholy power. After enchanting that blade "+
    "and keeping it for himself, he created this one. The intention was to "+
    "see what they might do when near each other. The legend hints at the "+
    "nature of Aorus Devar and suggests that instead of being evil, he was "+
    "more likely neutral, though he valued chaos above order. This blade "+
    "was believed to be only a legend, much like its supposed creator."+
    "%^RESET%^");

    set_property("lore difficulty", 25);
    set_value(10000);
    set_property("no curse", 1);
    set_property("enchantment",5);
    set_decay_rate(0);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("damage bonus", 2);
    set_item_bonus("strength", 2);
    master = 0;
    GaveUp = 0;
    MyPower = 0;
}

int wield_func()
{
    if(stringp(master) && ETO->query_name() != master)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ I cannot serve you, Mortal. I "+
        "have already given my allegiance to another.%^RESET%^");
        tell_object(ETO, "%^BOLD%^%^YELLOW%^You cannot seem to grasp the handle of the blade, as if it keeps moving "+
        "out of your reach somehow.%^RESET%^");
        return 0;
    }

    tell_object(ETO, "%^BOLD%^%^YELLOW%^You carefully grasp the handle of the "+
    "yellow blade and feel stronger as a peaceful and holy prescence enters your mind.%^RESET%^");

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^YELLOW%^ seems almost serene as "+
        ETO->QS+" grasps the handle of the yellow blade.%^RESET%^", ETO);
    }

    if(master && ETO->query_name() == master)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ hello "+capitalize(master)+", I am "+
        "pleased to be of service to you!%^RESET%^");
    }
    if(!GaveUp) set_heart_beat(1);
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^YELLOW%^You slowly release the handle of the "+
    "yellow blade and feel weaker as the holy presence leaves your mind!%^RESET%^");

    if(!stringp(master))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ May your path be safe, until next time!%^RESET%^");
        set_heart_beat(0);
    }
    if(stringp(master) && ETO->query_name() == master)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ As you wish "+capitalize(master)+". "+
        "I shall await your command.%^RESET%^");
    }

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^YELLOW%^ suddenly looks weaker.%^RESET%^", ETO);
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
            case 1: case 4: case 7:
                switch(random(80))
                {
                    case 0..35:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ You "+
                        "seem quite noble indeed, adventurer. I can forsee us getting along well.");
                        return;
                        break;
                    case 36..59:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ Aorus Devar "+
                        "spent countless years looking for something that he could never find. I do hope "+
                        "that you are not prone to such fruitless pursuits. %^RESET%^");
                        return;
                        break;
                    case 60..70:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^You seem "+
                        "as if you may use my power for good, but I am not quite ready to declare "+
                        "my allegiance just yet.");
                        return;
                        break;
                    case 71..76:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^I must "+
                        "be with you for awhile longer. I want to observe your actions so that I "+
                        "might understand your true intentions.");
                        return;
                        break;
                    case 77..79:
                        if(random(2)) return;
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ I can "+
                        "sense the honor within you. The desire to better the world. I shall serve you "+
                        "from here on out, loyally. I hope that I may never come to regret this decision.");
                        master = ETO->query_name();
                        break;
                }
                break;
            default:
                switch(random(75))
                {
                    case 0..35:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ Your "+
                        "soul is foul. I have no desire to continue in your service.");
                        return;
                        break;
                    case 36..58:
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ why "+
                        "have **YOU** not relieved me from your presence? I am warning you "+
                        "that I will not tolerate this much longer.");
                        return;
                        break;
                    case 59..70:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^I am "+
                        "starting to grow bored of **YOUR** foulness. I am not willing to warn "+
                        "you much longer.");
                        return;
                        break;
                    case 71..73:
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^This is the "+
                        "end of my **KINDNESS**. I demand that you release me!!");
                        return;
                        break;
                    case 74:
                        if(random(10)) return;
                        set_decay_rate(10);
                        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^ "+
                        "You **COULD** have listened to me when I showed you kindness. "+
                        "I take my leave of this world now!");
                        while(TO->query_property("enchantment") >= 0)
                        {
                            TO->remove_property("enchantment");
                            TO->set_property("enchantment", -2);
                        }
                        set_heart_beat(0);
                        GaveUp = 1;
                        break;
                }
                break;
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
                    tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ I am "+
                    "lending you a fraction of my power, "+capitalize(master)+"!");
                    x = sizeof(targs);
                    while(x--)
                    {
                        targ = targs[x];
                        if(!objectp(targ) && environment(targ) != EETO) continue;
                        tell_object(ETO, "%^BOLD%^%^WHITE%^A bolt of pure h%^BOLD%^%^CYAN%^"+
                        "o%^BOLD%^%^WHITE%^ly %^BOLD%^%^GREEN%^"+
                        "e%^BOLD%^%^BLACK%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^rgy "+
                        "zaps from the blade and slams into "+targ->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^");

                        tell_object(targ, "%^BOLD%^%^WHITE%^A bolt of pure h%^BOLD%^%^CYAN%^"+
                        "o%^BOLD%^%^WHITE%^ly %^BOLD%^%^GREEN%^"+
                        "e%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^rgy "+
                        "zaps from "+ETOQCN+"%^BOLD%^%^WHITE%^'s blade and slams into you!%^RESET%^");

                        tell_room(EETO, "%^BOLD%^%^WHITE%^A bolt of pure h%^BOLD%^%^CYAN%^"+
                        "o%^BOLD%^%^WHITE%^ly %^BOLD%^%^GREEN%^"+
                        "e%^BOLD%^%^WHITE%^n%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^rgy "+
                        "zaps from "+ETOQCN+"%^BOLD%^%^WHITE%^'s blade and slams into "+
                        targ->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", ({ETO, targ}));
                        targ->cause_typed_damage(targ, 0, roll_dice(2,8), "divine");
                        continue;
                    }
                }
                else
                {
                    if(random(20)) return;
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    "You should learn to enjoy the serenity. In this world it is entirely too rare.");
                }
                return;
                break;
            case 10..18:
                if(sizeof(targs = ETO->query_attackers()))
                {
                    tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
                    "I see that you find yourself in **TROUBLE** I shall grant you a portion of "+
                    "my power!");
                    x = sizeof(targs);
                    if((int)ETO->query_hp() <= (int)ETO->query_max_hp())
                    {
                        tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the holy presence blending its "+
                        "life force with your own as your wounds begin to mend!%^RESET%^");
                        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s wounds begin %^BOLD%^%^CYAN%^"+
                        "mending%^BOLD%^%^WHITE%^ on their own!%^RESET%^", ETO);

                        ETO->heal(roll_dice(2, 6) * x);
                    }
                    else
                    {
                        if((int)ETO->query_extra_hp() < 100)
                        {
                            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the holy presence blending its "+
                            "life force with your own and you feel vigorous!%^RESET%^");

                            tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ suddenly looks vigorous!%^RESET%^", ETO);
                            ETO->add_extra_hp(roll_dice(1, 8) * x);
                        }
                    }
                }
                else
                {
                    if(random(20)) return;
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    " It is important to take time away from the battlefield, in order to "+
                    "not lose perspective.");
                }
                return;
                break;
            case 19:
                if(sizeof(targs = ETO->query_attackers()))
                {
                    tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
                    "Aorus Devar infused me with tremendous **POWER** let me show you a fraction "+
                    "of it!%^RESET%^");
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
                            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the holy presence %^BOLD%^%^MAGENTA%^"+
                            "manipulating the very fabric of the "+weap->query_short()+"%^BOLD%^%^WHITE%^ wielded by "+
                            targ->QCN+"!%^RESET%^");

                            tell_object(targ, "%^BOLD%^%^WHITE%^You feel a strange, holy presence suddenly "+
                            "%^BOLD%^%^MAGENTA%^manipulating the very fabric of your "+weap->query_short()+
                            "%^BOLD%^%^WHITE%^!%^RESET%^");

                            tell_room(EETO, targ->QCN+"%^BOLD%^%^WHITE%^ stares in horror at "+targ->QP+
                            " "+weap->query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^", ({ETO, targ}));

                            call_other(weap, func, targ);
                            hits++;
                            continue;
                        }
                        else
                        {
                            funcs = targ->query_funcs();
                            func = funcs[random(sizeof(funcs))];
                            if(!stringp(func)) continue;

                            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the holy presence %^BOLD%^%^MAGENTA%^"+
                            "manipulating%^BOLD%^%^WHITE%^ the very fabric of "+targ->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^");

                            tell_object(targ, "%^BOLD%^%^WHITE%^You feel an holy presence suddenly "+
                            "%^BOLD%^%^MAGENTA%^manipulating%^BOLD%^%^WHITE%^ the very fabric of your being!%^RESET%^");

                            tell_room(EETO, targ->QCN+"%^BOLD%^%^WHITE%^ suddenly stares off in "+
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
                        "That is a tremendous power that I have been imbued with. Do not "+
                        "treat it lightly.");
                    }
                    else
                    {
                        tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
                        "That did not go as planned. I am sorry to have disappointed you, "+
                        capitalize(master)+". I shall do better in the future.");
                    }
                    return;
                    break;
                }
                else
                {
                    if(random(20)) return;
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    "It is in moments like these where I wish that I were capable of another "+
                    "existence, so that I might truly enjoy peace.");
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
        tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^It is with **HESITATION** "+
        "that I serve you in battle.");

        tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the holy presence lash out at "+targ->QCN+
        " edding away at "+targ->QP+" %^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
        "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e!%^RESET%^");

        tell_object(targ, "%^BOLD%^%^WHITE%^You feel a holy presence edding away at "+
        "your %^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
        "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e!%^RESET%^ %^BOLD%^%^WHITE%^ as "+ETOQCN+
        "%^BOLD%^%^WHITE%^'s blade slices into you!");

        tell_room(EETO, targ->QCN+"%^BOLD%^%^WHITE%^ suddenly looks weaker as "+ETOQCN+
        "%^BOLD%^%^WHITE%^'s blade slices into "+targ->QO+"!%^RESET%^", ({ETO, targ}));

        targ->cause_typed_damage(targ, "torso", roll_dice(1,10), "divine");

        return 0;
    }
    if(stringp(master) && !random(5))
    {
        if(MyPower >= 150)
        {
            tell_object(ETO, "%^BOLD%^%^RED%^The blade tells you:%^RESET%^%^WHITE%^ "+
            "I now UNLEASH a **%^BOLD%^%^RED%^FURY%^RESET%^%^WHITE%^** "+
            "that RIVALS anything witnessed before!!");

            tell_object(targ, "%^BOLD%^%^WHITE%^A brilliant explosion of pure %^BOLD%^%^YELLOW%^"+
            "L%^RESET%^I%^BOLD%^%^YELLOW%^GHT%^BOLD%^%^WHITE%^ erupts %^BOLD%^%^YELLOW%^"+
            "VIOLENTLY%^BOLD%^%^WHITE%^ from "+ETOQCN+"%^BOLD%^%^WHITE%^'s blade and slams into "+
            "%^BOLD%^%^WHITE%^you with tremendous force, knocking you"+
            " to the ground!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^WHITE%^A brilliant explosion of pure %^BOLD%^%^YELLOW%^"+
            "L%^RESET%^I%^BOLD%^%^YELLOW%^GHT%^BOLD%^%^WHITE%^ erupts %^BOLD%^%^YELLOW%^"+
            "VIOLENTLY%^BOLD%^%^WHITE%^ from "+ETOQCN+"%^BOLD%^%^WHITE%^'s blade and slams into "+
            targ->QCN+"%^BOLD%^%^WHITE%^ with tremendous force, knocking "+ETO->QO+
            " to the ground!%^RESET%^",({ETO, targ}));
            dam = MyPower;
            if(!random(25)) dam = MyPower * 2;
            MyPower = 0;
            targ->set_tripped(2, "%^BOLD%^%^WHITE%^You are struggling to get back up!%^RESET%^");
            targ->cause_typed_damage(targ, "torso", dam, "divine");
            return 0;
        }
        else
        {
            switch(random(20))
            {
                case 0..6:
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^I have "+
                    "grown used to combat and quite good at it!");

                    tell_object(ETO, "%^BOLD%^%^WHITE%^The blade saps some of "+targ->QCN+
                    "%^BOLD%^%^WHITE%^'s "+
                    "%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
                    "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e%^RESET%^ %^BOLD%^%^WHITE%^"+
                    "and r%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^pl%^BOLD%^%^CYAN%^e"+
                    "%^BOLD%^%^WHITE%^nish%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^"+
                    "s you with it!%^RESET%^");

                    tell_object(targ, "%^BOLD%^%^WHITE%^You feel your very "+
                    "%^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
                    "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e%^RESET%^ being sapped "+
                    "away by "+ETOQCN+"%^BOLD%^%^WHITE%^'s %^MAGENTA%^blade!%^RESET%^");

                    tell_room(EETO, targ->QCN+"%^BOLD%^%^WHITE%^'s very "+
                    "%^BOLD%^%^WHITE%^l%^GREEN%^i%^WHITE%^f%^GREEN%^e%^WHITE%^"+
                    "f%^GREEN%^o%^WHITE%^rc%^GREEN%^e%^RESET%^%^BOLD%^%^WHITE%^ is "+
                    "sapped away by "+ETOQCN+"%^BOLD%^%^WHITE%^'s %^MAGENTA%^"+
                    "blade!%^RESET%^", ({ETO, targ}));

                    dam = roll_dice(2, 8);
                    MyPower += dam;
                    if((int)ETO->query_hp() < (int)ETO->query_max_hp()) ETO->heal(dam);
                    else if((int)ETO->query_extra_hp() < 100) ETO->add_extra_hp(dam);
                    targ->cause_typed_damage(targ, "torso", dam, "divine");
                    return 0;
                    break;

                case 7..15:
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^"+
                    "I hate to admit it but I enjoy the **THRILL** of battle!! Let us "+
                    "find VICTORY!");

                    tell_object(ETO, "%^BOLD%^%^WHITE%^The blade sinks deep "+
                    "into "+targ->QCN+ "%^BOLD%^%^WHITE%^ and as you pull it "+
                    "out you feel it ripping and tearing "+
                    "inside of "+targ->QO+"!%^RESET%^");

                    tell_object(targ, ETOQCN+"%^BOLD%^%^WHITE%^'s blade sinks deep "+
                    "into you and you feel it T%^BOLD%^%^RED%^EA%^BOLD%^%^GREEN%^R"+
                    "%^BOLD%^%^RED%^I%^BOLD%^%^GREEN%^NG %^BOLD%^%^WHITE%^and R%^RESET%^%^RED%^I"+
                    "%^BOLD%^%^GREEN%^PP%^RESET%^%^RED%^I%^BOLD%^%^GREEN%^NG "+
                    "%^BOLD%^%^WHITE%^your insides as "+ETO->QS+" pulls it out!%^RESET%^");

                    tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s blade sinks deep "+
                    "into "+targ->QCN+"%^BOLD%^%^WHITE%^ and "+targ->QS+" doubles "+
                    "over in %^BOLD%^%^GREEN%^AG%^RESET%^%^GREEN%^O%^BOLD%^%^GREEN%^"+
                    "NY%^BOLD%^%^WHITE%^!%^RESET%^", ({ETO, targ}));

                    targ->set_paralyzed(20, "%^BOLD%^%^YELLOW%^You are recovering "+
                    "from the agonizing pain!%^RESET%^");

                    dam = roll_dice(2, 8);
                    MyPower += dam;
                    return dam;
                    break;
                case 16..19:
                    tell_object(ETO, "%^BOLD%^%^CYAN%^The blade whispers to you: %^RESET%^I "+
                    "offer you **PROTECTION** now. May it keep you safe during the heat of battle!");

                    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel a wave of holy %^BOLD%^"+
                    "%^CYAN%^e%^BOLD%^%^WHITE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^rgy "+
                    "wash over you and form a layer of protection!%^RESET%^");

                    tell_room(EETO, "%^BOLD%^%^WHITE%^You watch as a layer of "+
                    "pr%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^e"+
                    "%^BOLD%^%^WHITE%^ct%^BOLD%^%^CYAN%^io%^BOLD%^%^WHITE%^n "+
                    "forms over "+ETOQCN+"%^BOLD%^%^WHITE%^!%^RESET%^", ETO);
                    dam = roll_dice(2, 8);
                    MyPower += dam;
                    ETO->set_stoneSkinned(dam);
                    return 0;
            }
        }
    }
    return 0;
}
