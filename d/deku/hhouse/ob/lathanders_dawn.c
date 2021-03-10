//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/armour/shield.c";
int charges;
int beating;
int damage;
int count = 1200;

void create()
{
    ::create();
    set_name("A polished red shield");
    set_id(({ "shield", "red shield", "polished shield",
    "polished red shield", "dawnguard of jarmila", "dawnguard",
    "jarmilas dawn guard", "dawn guard", "jarmilas dawnguard"}));
    set_obvious_short("%^RESET%^%^RED%^A polished red shield%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^D%^BOLD%^%^YELLOW%^a%^BOLD%^%^WHITE%^wng%^BOLD%^%^YELLOW%^ua%^BOLD%^%^WHITE%^rd %^BOLD%^%^YELLOW%^o%^BOLD%^f J%^BOLD%^%^YELLOW%^a%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^m%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^l%^BOLD%^%^WHITE%^a%^RESET%^");
    set_long("%^BOLD%^%^RED%^This beautiful shield is made from what appears to be a large ruby. It has been expertly and tediously p%^BOLD%^%^WHITE%^o%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^sh%^BOLD%^%^WHITE%^e%^BOLD%^%^RED%^d to the point where it reflects even the smallest amount of %^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^ght, somehow magnifying it. It is almost completely square in shape with edges tapering into a much thinner material. To maintain durability the edges have been reinforced by an unknown substance of a %^BOLD%^%^YELLOW%^yellow%^BOLD%^%^RED%^ hue. The starkly contrasting color reflects across the shield constantly, even when there is no %^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ght %^RED%^and almost resembles an %^BOLD%^%^WHITE%^au%^BOLD%^%^CYAN%^t%^BOLD%^%^WHITE%^u%^BOLD%^%^WHITE%^mn%^RESET%^ %^BOLD%^%^YELLOW%^sunrise%^BOLD%^%^RED%^. There are sturdy leather straps on the back of it serving as a means of strapping or wrapping it around your arm while you hold the reinforced %^BOLD%^%^WHITE%^steel handle%^BOLD%^%^RED%^ that has been added into the back of it.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^Legend suggest that this remarkable shield was crafted by a blacksmith of some renown who used to frequent the town of Verbobone. It was originally crafted and polished for a priest of Lord Shadow and at one point it was said to have been composed of an almost black marble. During a battle of some significance against a priest of Jarmila, one which was reportedly witnessed by Aorus Devar, it changed dramatically as the priest was holding it. Some say that Aorus Devar was somehow involved with its current enchantments, but none are for certain. What is known is that shortly after the remarkable battle, both priests disappeared.%^RESET%^");
    set_property("lore difficulty", 25);
    set_size(-1);
    set_weight(12);
    set_value(10000);
    set_property("no curse", 1);
    set_property("enchantment", 5);
    set_item_bonus("shieldMiss", 40);
    set_item_bonus("sight bonus", 4);
    set_item_bonus("fire resistance", 35);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
    set_heart_beat(1);
    charges = 0;
}

void heart_beat()
{
    string targ_name;
    int tmp_dam;
    if(!objectp(TO->query_worn()))
    {
        return;
    }
    if(!objectp(ETO))
    {
        return;
    }
    if(!living(ETO))
    {
        return;
    }
    if(random(10000) > 9950)
    {
        if((string)EVENTS_D->query_time_of_day() == "dawn" || !random(5))
        {
            tell_object(ETO, "%^BOLD%^%^RED%^Your shield grows "+
            "slightly w%^RESET%^%^RED%^a%^BOLD%^%^RED%^rm and you "+
            "feel it %^BOLD%^%^WHITE%^p%^RESET%^u%^BOLD%^%^WHITE%^"+
            "l%^RESET%^s%^BOLD%^%^WHITE%^a%^RESET%^t%^BOLD%^%^WHITE%^"+
            "i%^RESET%^n%^BOLD%^%^WHITE%^g%^BOLD%^%^RED%^ quickly "+
            "for a brief moment%^RESET%^");
            tmp_dam = roll_dice(4,10);
            damage += tmp_dam;
            if((int)ETO->query_hp() < (int)ETO->query_max_hp())
            {
                tell_object(ETO, "%^BOLD%^%^CYAN%^You feel your "+
                "wounds instantaneously %^RESET%^m%^BOLD%^%^WHITE%^"+
                "e%^RESET%^n%^BOLD%^%^WHITE%^d%^RESET%^i%^BOLD%^%^WHITE%^"+
                "n%^RESET%^g%^BOLD%^%^CYAN%^!");
                if(!ETO->query_invis())
                {
                    tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^'s "+
                    "wounds begin instantaneously %^RESET%^m%^BOLD%^%^WHITE%^"+
                    "e%^RESET%^n%^BOLD%^%^WHITE%^d%^RESET%^i%^BOLD%^%^WHITE%^"+
                    "n%^RESET%^g%^BOLD%^%^CYAN%^!", ETO);
                }
                ETO->heal(tmp_dam);
            }
            else
            {
                tell_object(ETO, "%^BOLD%^%^CYAN%^You feel yourself "+
                "grow suddenly more %^RESET%^v%^BOLD%^%^WHITE%^i%^RESET%^"+
                "g%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^o%^RESET%^u%^BOLD%^"+
                "%^WHITE%^s%^BOLD%^%^CYAN%^!");
                if(!ETO->query_invis())
                {
                    tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ suddenly grows "+
                    "more %^RESET%^v%^BOLD%^%^WHITE%^i%^RESET%^"+
                    "g%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^o%^RESET%^u%^BOLD%^"+
                    "%^WHITE%^s%^BOLD%^%^CYAN%^!", ETO);
                }
                ETO->add_extra_hp(tmp_dam);
            }
            charges += 2 + random(5);
            if(charges > 50)
            {
                charges = 50;
            }
            return;
        }
    }
}

int wearme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel an invigorating "+
    "w%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^rmth radiate out from the shield and "+
    "encompass you!%^RESET%^");
	return 1;
}

int removeme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the "+
    "w%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^rmth depart as you release "+
    "the shield!%^RESET%^");
	return 1;
}

int strike_func(int mydamage, object what, object who)
{
    int dam, x;
    object *foes;
    if(!objectp(who)) return damage;
    if(!objectp(ETO)) return damage;

    if(!random(3) || !charges) return damage;

    if(damage >= 150)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^As "+who->QCN+"%^BOLD%^%^WHITE%^ connects "+
        "with your shield a brilliant %^BOLD%^%^GREEN%^BL%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^"+
        "ND%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^NG %^BOLD%^%^RED%^flash of light erupts out "+
        "from it and envelopes your foes!%^RESET%^");

        foes = ETO->query_attackers();

        dam = damage/sizeof(foes);
        if(dam > 150)
        {
            if(!random(4)) dam = dam * 2;
            else dam = 150;
        }
        if(dam < 40) dam = 40;
        damage = 0;
        charges -= 5;
        if(charges < 0) charges = 0;

        tell_object(who, "%^BOLD%^%^RED%^As you%^BOLD%^%^WHITE%^ connect "+
        "with "+ETOQCN+"%^BOLD%^%^RED%^'s shield a brilliant %^BOLD%^%^GREEN%^"+
        "BL%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^"+
        "ND%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^NG %^BOLD%^%^RED%^flash of light erupts out "+
        "from it!%^RESET%^");

        tell_room(EETO, "%^BOLD%^%^RED%^As "+who+QCN+"%^BOLD%^%^WHITE%^ connects "+
        "with "+ETO->QCN+"%^BOLD%^%^RED%^'s shield a brilliant %^BOLD%^%^GREEN%^"+
        "BL%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^"+
        "ND%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^NG %^BOLD%^%^RED%^flash of light erupts out "+
        "from it!%^RESET%^", ({ETO, who}));

        for(x = 0;x < sizeof(foes);x++)
        {
            if(!objectp(foes[x])) continue;
            if(environment(foes[x]) != EETO) continue;

            tell_object(foes[x], "%^BOLD%^%^WHITE%^You are enveloped by the %^BOLD%^%^GREEN%^BL%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^ND%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^NG%^BOLD%^%^WHITE%^ %^YELLOW%^LIGHT %^WHITE%^and it %^BOLD%^%^RED%^B%^BOLD%^%^YELLOW%^U%^BOLD%^%^RED%^RNS%^BOLD%^%^WHITE%^ into you!%^RESET%^");

            tell_room(EETO, foes[x]->QCN+ "%^BOLD%^%^WHITE%^ is enveloped by "+
            "the %^BOLD%^%^GREEN%^BL%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^"+
            "ND%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^NG%^BOLD%^%^WHITE%^ %^YELLOW%^LIGHT %^WHITE%^and "+
            "it %^BOLD%^%^RED%^B%^BOLD%^%^YELLOW%^U%^BOLD%^%^RED%^RNS%^BOLD%^"+
            "%^WHITE%^ into "+foes[x]->QO+"!%^RESET%^", foes[x]);

            if(foes[x] == who) foes[x]->cause_typed_damage(foes[x], "torso", dam, "fire");
            else foes[x]->cause_typed_damage(foes[x], "torso", (dam/2), "fire");
            continue;
        }
        return mydamage;
    }
    switch(random(40))
    {
        case 0..36:
            tell_object(ETO, "%^BOLD%^%^RED%^As "+who->QCN+"%^BOLD%^%^RED%^ strikes your "+
            "shield a %^RESET%^%^RED%^T%^BOLD%^%^YELLOW%^O%^RESET%^%^RED%^W%^BOLD%^%^YELLOW%^"+
            "E%^RESET%^%^RED%^R%^BOLD%^%^RED%^ of %^RESET%^%^RED%^F%^BOLD%^%^RED%^L%^RESET%^%^RED%^"+
            "A%^BOLD%^%^RED%^M%^RESET%^%^RED%^E%^BOLD%^%^RED%^ erupts out from the center of it, "+
            "burning into "+who->QO+"!");


            tell_object(who, "%^BOLD%^%^RED%^As you strike "+ETOQCN+
            "%^BOLD%^%^RED%^'s shield a %^RESET%^%^RED%^T%^BOLD%^%^YELLOW%^O%^RESET%^%^RED%^W%^BOLD%^%^YELLOW%^"+
            "E%^RESET%^%^RED%^R%^BOLD%^%^RED%^ of %^RESET%^%^RED%^F%^BOLD%^%^RED%^L%^RESET%^%^RED%^"+
            "A%^BOLD%^%^RED%^M%^RESET%^%^RED%^E%^BOLD%^%^RED%^ erupts out from the center of it, burning "+
            "into you!");

            tell_room(EETO, "%^BOLD%^%^RED%^As "+who->QCN+"%^BOLD%^%^RED%^ strikes "+ETOQCN+
            "%^BOLD%^%^RED%^'s shield a %^RESET%^%^RED%^T%^BOLD%^%^YELLOW%^O%^RESET%^%^RED%^W%^BOLD%^%^YELLOW%^"+
            "E%^RESET%^%^RED%^R%^BOLD%^%^RED%^ of %^RESET%^%^RED%^F%^BOLD%^%^RED%^L%^RESET%^%^RED%^"+
            "A%^BOLD%^%^RED%^M%^RESET%^%^RED%^E%^BOLD%^%^RED%^ erupts out from the center of it, burning "+
            "into "+who->QO+"!", ({ETO, who}));

            dam = roll_dice(3, 6);
            damage += dam;
            who->cause_typed_damage(who, "torso", dam, "fire");
            if(!random(2)) charges -= 1 + random(3);
            if(charges < 0) charges = 0;
            return mydamage;
            break;

        case 37..39:

            tell_object(ETO, "%^BOLD%^%^YELLOW%^As "+who->QCN+"%^BOLD%^%^YELLOW%^ strikes your "+
            "shield a concentrated %^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^"+
            "y %^BOLD%^%^RED%^o%^BOLD%^%^WHITE%^f %^BOLD%^%^RED%^f%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^"+
            "r%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^ jumps out and %^BOLD%^%^RED%^E%^BOLD%^%^GREEN%^"+
            "N%^BOLD%^%^RED%^G%^BOLD%^%^GREEN%^U%^BOLD%^%^RED%^L%^BOLD%^%^GREEN%^F%^BOLD%^%^RED%^"+
            "S%^BOLD%^%^YELLOW%^ "+who->QO+"!");

            tell_object(who, "%^BOLD%^%^YELLOW%^As you%^BOLD%^%^YELLOW%^ strike "+ETOQCN+
            "%^BOLD%^%^YELLOW%^'s shield a concentrated %^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^"+
            "y %^BOLD%^%^RED%^o%^BOLD%^%^WHITE%^f %^BOLD%^%^RED%^f%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^"+
            "r%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^ jumps out and %^BOLD%^%^RED%^E%^BOLD%^%^GREEN%^"+
            "N%^BOLD%^%^RED%^G%^BOLD%^%^GREEN%^U%^BOLD%^%^RED%^L%^BOLD%^%^GREEN%^F%^BOLD%^%^RED%^"+
            "S%^BOLD%^%^YELLOW%^ you!");

            tell_room(EETO, "%^BOLD%^%^YELLOW%^As "+who->QCN+" %^BOLD%^%^YELLOW%^ strikes "+ETOQCN+
            "%^BOLD%^%^YELLOW%^'s shield a concentrated %^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^"+
            "y %^BOLD%^%^RED%^o%^BOLD%^%^WHITE%^f %^BOLD%^%^RED%^f%^BOLD%^%^WHITE%^i%^BOLD%^%^RED%^"+
            "r%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^ jumps out and %^BOLD%^%^RED%^E%^BOLD%^%^GREEN%^"+
            "N%^BOLD%^%^RED%^G%^BOLD%^%^GREEN%^U%^BOLD%^%^RED%^L%^BOLD%^%^GREEN%^F%^BOLD%^%^RED%^"+
            "S%^BOLD%^%^YELLOW%^ " +who->QO+"!", ({ETO, who}));

            dam = roll_dice(6,6);
            damage += dam;
            who->cause_typed_damage(who, "torso", dam, "fire");
            return mydamage;
            break;
    }
    return damage;
}
