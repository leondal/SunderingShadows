#include <std.h>
#define NUMBERS ({ "zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine", "ten" })
inherit "/d/common/obj/weapon/two_hand_sword";

void create()
{
    ::create();
    set_name("two handed sword");
    set_id(({"sword", "two handed sword", "electrified sword",
    "two handed electrified sword", "massive sword", "massive "+
    "electrified sword"}));

    set_obvious_short("%^BOLD%^%^BLUE%^electr%^CYAN%^i%^BLUE%^fie%^CYAN%^d %^BLUE%^tw%^CYAN%^o %^BLUE%^han%^CYAN%^d%^CYAN%^e%^BLUE%^d %^BLUE%^s%^CYAN%^w%^BLUE%^or%^CYAN%^d%^RESET%^");

    set_short("%^BOLD%^%^CYAN%^E%^BOLD%^%^BLUE%^l%^BOLD%^%^CYAN%^"+
    "e%^BOLD%^%^BLUE%^c%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^r%^BOLD%^"+
    "%^CYAN%^i%^BOLD%^%^BLUE%^f%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^e"+
    "%^BOLD%^%^CYAN%^d two handed sword%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^This large two handed sword is composed of "+
    "a %^BOLD%^%^BLACK%^deep ebon%^BOLD%^%^BLUE%^ metal. The blade is smooth "+
    "on both sides and %^BOLD%^%^RED%^razor-sharp%^BOLD%^%^BLUE%^ with "+
    "electricity constantly and chaotically %^BOLD%^%^WHITE%^crackling%^BOLD%^%^BLUE%^ "+
    "the length of it. Amazingly the majority of electricity seems contained within the "+
    "blade and stops just short of the guard. The guard is simple, a piece of "+
    "contrasting %^BOLD%^%^WHITE%^white%^BOLD%^%^BLUE%^ material that turns "+
    "sharply downward on either side. The handle of the blade is ridged, "+
    "apparently to make gripping the weapon easier. A %^BOLD%^%^CYAN%^azure"+
    "%^BOLD%^%^BLUE%^ stone serves the purpose of the pommel. It is "+
    "completely smooth and much wider than the handle. Electricity "+
    "zaps around on the inside of it and occasionally a spark of it "+
    "escapes but quickly fades out.%^RESET%^");

    set_lore("%^BOLD%^%^BLUE%^The legends around these swords "+
    "suggest that they were created by the smith of Castle Freeholm. "+
    "They were given to almost all of the Storm Giants who served the "+
    "King. They are rumored to both inflict devasting electrical damage "+
    "on those they are used against and to insulate whoever wields them "+
    "against it.%^RESET%^");

    set_property("lore difficulty", 25);
    set_value(5000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("strength", 4);
    set_item_bonus("electricity resistance", 30);
}

int wield_func()
{
    if(ETO->query_highest_level() < 35)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The sword refuses to submit to one as "+
        "puny as you!%^RESET%^");
        return 0;
    }

    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel yourself strengthed with electricity as "+
    "you grip the powerful ebon blade!%^RESET%^");
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel the electrical empowerment fade "+
    "away as you release the ebon blade!%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    int dam, bolts;
    string myBolts;

    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(5))
    {
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
        "electricity zap from the blade of your sword toward "+
        targ->QCN+"!%^RESET%^");

        tell_object(targ, "%^BOLD%^%^YELLOW%^"+capitalize(myBolts) + " bolts of "+
        "electricity zap from the blade of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s ebon "+
        "sword toward you!%^RESET%^");

        tell_room(EETO, "%^BOLD%^%^YELLOW%^"+capitalize(myBolts) + " bolts of "+
        "electricity zap from the blade of "+ETOQCN+"%^BOLD%^%^YELLOW%^'s ebon "+
        "sword toward "+targ->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^", ({ETO, targ}));

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
    }
    return 0;
}
