#include <std.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/armour/fullplate.c";

void create()
{
    ::create();
    set_name("a suit of deep blue full plate");
    set_id(({"full plate", "armor", "fullplate", "shroud",
    "shroud of the impaler", "impalers shroud", "plate", "armor"}));

    set_short("%^BOLD%^%^BLACK%^Shr%^BOLD%^%^WHITE%^ou%^BOLD%^%^BLACK%^"+
    "d of the Im%^BOLD%^%^RED%^pa%^BOLD%^%^BLACK%^ler%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLUE%^A suit deep blue full plate%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This magnificient full plate "+
    "has been exquisitely forged from a %^RESET%^%^BLUE%^deep blue%^BOLD%^"+
    "%^BLACK%^ metal. The individual parts of the armor have been honed down so that "+
    "each is slightly thinner than normal. The metal seems "+
    "l%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ghter, yet much sturdier despite this. "+
    "A thick and comfortable padding of almost a pure %^RESET%^%^WHITE%^"+
    "white%^BOLD%^%^BLACK%^ covers the inside of the armor. Tiny, ever "+
    "changing %^BOLD%^%^CYAN%^runes%^BOLD%^%^BLACK%^ have been inscribed "+
    "all along the inside of the armor. They are hard to make out, but seem "+
    "quite important and quite serene to observe. In fact, a peaceful "+
    "yet %^BOLD%^%^CYAN%^powerful%^BOLD%^%^BLACK%^ feeling washes over you when "+
    "trying to observe them.%^RESET%^");

    set_lore("%^RESET%^%^RED%^This ancient armor was rumoured to have been forged "+
    "in the intense heat of a volcano and then enchanted by the power "+
    "of a %^RESET%^%^YELLOW%^gold dragon%^RESET%^%^RED%^ in order to "+
    "aid a powerful warrior of the light. It is thought to be composed of "+
    "a strange mixture of ores that were hard to come by in their time and "+
    "long since forgotten. Legends suggest that the warrior eventually heard of "+
    "a man named Aorus Devar who was working on somehow altering the very fabric "+
    "of magic. These same legends suggest that he went in search of Aorus Devar. "+
    "Unfortunately the legends stop after this, as if the warrior simply "+
    "disappeared.%^RESET%^");

    set_weight(40);
    set_property("lore difficulty", 25);
    set_property("no curse", 1);
    set_property("enchantment", 5);
    set_value(5000);
    set("no curse", 1);
    set_decay_rate(0);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
    set_item_bonus("spell damage resistance", 10);
    set_item_bonus("constitution", 4);
}

int wearme()
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel an %^BOLD%^%^WHITE%^"+
    "invisible%^BOLD%^%^YELLOW%^ force%^BOLD%^%^BLACK%^ surround "+
    "you as you don the armor.%^RESET%^");
	return 1;
}

int removeme()
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel an %^BOLD%^%^WHITE%^"+
    "invisible%^BOLD%^%^YELLOW%^ force%^BOLD%^%^BLACK%^ depart "+
    "from you as you carefully remove the armor.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who)
{
    object mon;
    if(!objectp(who)) return damage;
    if(!objectp(ETO)) return damage;

    if(!random(2)) return damage;
    switch(random(100))
    {
        case 0..25:
            tell_object(ETO, "%^BOLD%^%^RED%^You feel as if some invisible force has stood between "+
            "you and "+who->QCN+"%^BOLD%^%^RED%^'s attack. You shrug off the majority of the "+
            "force of "+who->QP+" blow!%^RESET%^");

            tell_object(who, "%^BOLD%^%^RED%^Your attack on "+ETO->QCN+"%^BOLD%^%^RED%^ seems weakened, "+
            "almost as if were hitting some invisible force!%^RESET%^");
            return (damage/25);
            break;
        case 26..50:
            tell_object(ETO, "%^BOLD%^%^WHITE%^Power seems to %^BOLD%^%^BLACK%^r%^YELLOW%^a%^BLACK%^d%^YELLOW%^"+
            "ia%^BLACK%^t%^YELLOW%^e%^BOLD%^%^WHITE%^ out from your armor and "+
            "%^BOLD%^%^CYAN%^wash%^BOLD%^%^WHITE%^ over you as "+who->QCN+"%^BOLD%^%^WHITE%^'s attack "+
            "lands, leaving you feeling refreshed!%^RESET%^");

            tell_object(who, "%^BOLD%^%^WHITE%^You feel a wave of power %^BOLD%^%^BLACK%^r%^YELLOW%^a%^BLACK%^d%^YELLOW%^"+
            "ia%^BLACK%^t%^YELLOW%^e%^BOLD%^%^WHITE%^ out from "+ETO->QCN+"%^BOLD%^%^WHITE%^'s "+
            "armor as your attack lands, and "+ETO->QS+"%^BOLD%^%^WHITE%^ looks refreshed!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^WHITE%^A wave of power %^BOLD%^%^BLACK%^r%^YELLOW%^a%^BLACK%^d%^YELLOW%^"+
            "ia%^BLACK%^t%^YELLOW%^e%^BOLD%^%^WHITE%^s out from "+ETO->QCN+"%^BOLD%^%^WHITE%^'s "+
            "armor as "+who->QCN+"%^BOLD%^%^WHITE%^'s attack lands, leaving "+ETOQCN+"%^BOLD%^%^WHITE%^ "+
            "looking refreshed!%^RESET%^", ({ETO, who}));

            ETO->add_hp(damage);
            return (damage*-1);
            break;
        case 51..85:

            tell_object(ETO, "%^BOLD%^%^CYAN%^You feel the runes on the inside of your armor suddently "+
            "grow %^BOLD%^%^RED%^w%^BOLD%^%^YELLOW%^a%^BOLD%^%^CYAN%^rm as "+who->QCN+"%^BOLD%^%^CYAN%^'s "+
            "attack lands and some powerful knowledge expands outward, encompassing you for a brief "+
            "moment before it is released in a brilliant flash of %^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^i"+
            "%^BOLD%^%^WHITE%^ght%^BOLD%^%^CYAN%^!%^RESET%^");

            tell_object(who, ETOQCN+"%^BOLD%^%^CYAN%^'s armor erupts in a brilliant flash of %^BOLD%^%^WHITE%^l"+
            "%^YELLOW%^i%^BOLD%^%^WHITE%^ght %^BOLD%^%^CYAN%^as your attack lands!%^RESET%^");

            tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^'s armor erupts in a brilliant flash of %^BOLD%^%^WHITE%^l "+
            "%^YELLOW%^i%^BOLD%^%^WHITE%^ght %^BOLD%^%^CYAN%^as "+who->QCN+"%^BOLD%^%^CYAN%^'s attack "+
            "lands!%^RESET%^", ({ETO, who}));

            damage = damage/2;

            new("/cmds/spells/b/_blade_barrier")->use_spell(ETO, ETO, 25, 25, "cleric");
            return damage;
        case 86..99:
            if(!objectp(what)) return damage;

            tell_object(ETO, "%^BOLD%^%^BLACK%^You watch in amazement as a %^RESET%^%^RED%^"+
            "deep red %^BOLD%^%^BLACK%^bolt of energy strikes "+who->QCN+
            " and a %^BOLD%^%^CYAN%^phantom%^BOLD%^%^BLACK%^ "+what->query_short()+
            "%^BOLD%^%^BLACK%^ appears before "+who->QO+"%^BOLD%^%^BLACK%^ and attacks!%^RESET%^");

            tell_object(who, "%^BOLD%^%^BLACK%^You watch in amazeent as a %^RESET%^%^RED%^"+
            "deep red%^BOLD%^%^BLACK%^ bolt of energy from "+ETOQCN+"%^BOLD%^%^BLACK%^'s"+
            " armor strikes you! A %^BOLD%^%^CYAN%^phantom%^BOLD%^%^BLACK%^ "+what->query_short()+
            "%^BOLD%^%^BLACK%^ appears suddenly before you and attacks!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^BLACK%^You watch in amazement as a %^RESET%^%^RED%^"+
            "deep red%^BOLD%^%^BLACK%^ bolt of energy from "+ETOQCN+"%^BOLD%^%^BLACK%^'s "+
            "armor strikes "+who->QCN+"%^BOLD%^%^BLACK%^!. A %^BOLD%^%^CYAN%^phantom%^BOLD%^"+
            "%^BLACK%^ "+what->query_short()+"%^BOLD%^%^BLACK%^ appears suddenly before "+
            who->QO+"%^BOLD%^%^BLACK%^ and attacks!%^RESET%^", ({ETO, who}));

            mon = new(HHMON+"phantom_weapon");
            mon->possess_this(what);
            mon->move(EETO);
            mon->set_property("minion", ETO);
            who->add_attacker(mon);
            ETO->add_follower(mon);
            ETO->add_protector(mon);
            return damage/2;
            break;
    }
    return damage;
}
