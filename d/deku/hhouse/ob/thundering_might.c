#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create()
{
    ::create();
    set_name("large hammer");
    set_id(({"hammer", "large hammer", "thundering hammer",
    "thundering might", "hammer of might"}));

    set_obvious_short("%^BOLD%^%^WHITE%^A %^WHITE%^larg%^BLUE%^e %^WHITE%^blu%^BLUE%^e %^WHITE%^war %^WHITE%^h%^BLUE%^a%^WHITE%^mme%^BLUE%^r%^RESET%^");

    set_short("%^BOLD%^%^WHITE%^Zh%^CYAN%^ou%^BOLD%^%^WHITE%^r's "+
    "Th%^CYAN%^u%^BOLD%^%^WHITE%^nd%^CYAN%^e%^BOLD%^%^WHITE%^"+
    "r%^CYAN%^i%^BOLD%^%^WHITE%^ng M%^CYAN%^i%^BOLD%^%^WHITE%^ght%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This massive blue st%^BOLD%^%^WHITE%^ee%^CYAN%^"+
    "l %^RED%^war%^BOLD%^%^CYAN%^ hammer spans nearly four feet in length.  "+
    "The head of it is made from a solid %^BOLD%^%^BLUE%^blue gem%^BOLD%^%^CYAN%^"+
    " that has been rounded on one side and forged to form a deadly "+
    "large %^RED%^spike%^BOLD%^%^CYAN%^ on the other.  The h%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^CYAN%^ndl%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^ of the "+
    "hammer has been forged from a strange %^BOLD%^%^BLUE%^blue%^BOLD%^%^CYAN%^"+
    " steel.  It has been inscribed with numerous m%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^CYAN%^g%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^c%^BOLD%^%^WHITE%^"+
    "a%^BOLD%^%^CYAN%^l glyphs that constantly pulse and offer a slight "+
    "%^BOLD%^%^WHITE%^glow%^BOLD%^%^CYAN%^, though they offer "+
    "no explanation for their meaning.  A piece of %^BOLD%^%^WHITE%^"+
    "ivory%^BOLD%^%^CYAN%^ has been expertly attached to the bottom of "+
    "the handle, serving as a means for the wielder to hold it.%^RESET%^");

    set_lore("This hammer was forged several decades ago, by a man "+
    "who was either lost to history or simply was never known.  The hammer "+
    "was forged for a mighty warrior by the name of Zhour, from which "+
    "it derives its name.  He was thought to have went into battle "+
    "screaming in rage, though outside of combat he was rumoured to "+
    "have been very friendly - and loyal - to those who he counted as "+
    "allies.  The hammer was thought lost upon his death, as it was "+
    "buried in a place deep in the earth, along with its fierce wielder.  "+
    "The exact location of its burial has been forgotten, but rumours "+
    "suggest that it was somewhere around the edges of the Shadowlord "+
    "forest.");

    set_property("lore difficulty", 22);
    set_value(10000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_item_bonus("damage bonus", 1);
    set_item_bonus("strength", 2);
}

int wield_func()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You carefully take hold of the "+
    "ivory portion of the handle, balancing the weapon just right, and you "+
    "feel a wave of energy pass over you, strengthening your blows.%^RESET%^");

    tell_room(EETO, ETOQCN +"%^BOLD%^%^WHITE%^ carefully takes hold of "+
    "the handle of "+ETO->QP+" hammer and you suddenly see a %^BOLD%^%^CYAN%^"+
    "wave%^RESET%^%^BOLD%^%^WHITE%^ of energy pass over "+ETO->QO+"!%^RESET%^", ETO);
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You release your hold on the ivory "+
    "portion of the handle and you feel the added strength "+
    "leave you.%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(1000) < 150)
    {
        switch(random(10))
        {
            case 0..5:

                tell_object(ETO, "%^BOLD%^%^CYAN%^You slam your hammer "+
                "into "+targ->QCN+"%^BOLD%^%^CYAN%^'s chest with "+
                "tremendous might and "+
                "you can hear something crack inside of "+targ->QO+"%^RESET%^!");

                tell_object(targ, ETOQCN +" %^BOLD%^%^CYAN%^slams "+
                ETO->QP+ " hammer into your chest with tremendous might and "+
                "you can feel something crack inside of you!%^RESET%^");

                tell_room(EETO, ETOQCN +"%^BOLD%^%^CYAN%^ slams "+
                ETO->QP +" hammer into "+targ->QCN+"%^BOLD%^%^CYAN%^'s "+
                "chest with tremendous might and you can "+
                "hear something crack inside of "+targ->QO+"%^BOLD%^%^CYAN%^!",
                ({targ, ETO}));
                ETO->set_property("magic", 1);
                TO->set_property("magic", 1);
                targ->cause_typed_damage(targ, "torso", roll_dice(1,12), "bludgeoning");
                TO->set_property("magic", -1);
                ETO->set_property("magic", -1);
                return 0;
                break;
            case 6..8:
                tell_object(ETO, "%^BOLD%^%^BLACK%^You smash "+
                targ->QCN+"%^BOLD%^%^BLACK%^ in the side of the "+
                "head with your hammer "+
                "knocking "+targ->QO+" backwards with tremendous %^BOLD%^%^CYAN%^"+
                "force%^RESET%^%^BOLD%^%^BLACK%^!%^RESET%^");

                tell_object(targ, ETOQCN +"%^BOLD%^%^BLACK%^ "+
                "smashes you in the side of the head with "+
                ETO->QP+" hammer, "+
                "knocking you backwards with tremendous "+
                "%^BOLD%^%^CYAN%^force%^RESET%^%^BOLD%^%^BLACK%^ "+
                "and leaving you temporarily "+
                "unable to see anything as you try to regain your "+
                "focus!%^RESET%^");

                tell_room(EETO, ETOQCN +"%^BOLD%^%^BLACK%^ smashes "+
                targ->QCN +"%^BOLD%^%^BLACK%^ in the side of the "+
                "head with "+ETO->QP+" hammer, knocking "+targ->QCN+
                "%^BOLD%^%^BLACK%^ backwards with tremendous %^BOLD%^"+
                "%^CYAN%^force%^RESET%^%^BOLD%^%^BLACK%^!%^RESET%^",
                ({targ, ETO}));

                targ->set_temporary_blinded(1, "%^BOLD%^%^BLACK%^"+
                "You struggle to regain focus!%^RESET%^");
                targ->cause_typed_damage(targ, "head", roll_dice(2,4), "bludgeoning");
                return 0;
                break;

            case 9:
                tell_object(ETO, "%^BOLD%^%^BLUE%^You suddenly rush toward "+
                targ->QCN+"%^BOLD%^%^BLUE%^ and slam your hammer quickly into "+
                targ->QO+" before %^RESET%^%^RED%^imbedding"+
                "%^BOLD%^%^BLUE%^ the spike into "+targ->QP+
                " chest, leaving "+targ->QO+" stunned, you attack again!%^RESET%^");

                tell_object(targ, ETOQCN + "%^BOLD%^%^BLUE%^ suddenly rushes "+
                "toward you and slams "+ETO->QP+" hammer quickly into "+
                "you, before %^RESET%^%^RED%^imbedding"+
                "%^BOLD%^%^BLUE%^ the spike into your chest - stunning you - "+
                ETO->QS+ " manages to attack again!%^RESET%^");

                tell_room(EETO, ETOQCN +"%^BOLD%^%^BLUE%^ suddenly rushes "+
                "toward "+targ->QCN+" and slams "+
                ETO->QP+" hammer quickly into "+
                targ->QO+" before %^RESET%^%^RED%^imbedding"+
                "%^BOLD%^%^BLUE%^ the spike into "+targ->QP+
                " chest - stunning "+targ->QO+" - "+ETO->QCN+
                " manages to attack again!%^RESET%^", ({ETO, targ}));

                ETO->execute_attack();
                targ->set_tripped(1, "%^BOLD%^%^BLUE%^You have been stunned by the "+
                "hammer!%^RESET%^");
                targ->cause_typed_damage(targ, "torso", roll_dice(2, 4), "bludgeoning");
                return 0;
                break;
        }
    }
}
