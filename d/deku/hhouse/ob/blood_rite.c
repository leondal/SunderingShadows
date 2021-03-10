#include <std.h>
inherit "/d/common/obj/weapon/dagger";
int charges;
void create(){
    ::create();

    set_name("irridescent dagger");
    set_id(({ "dagger", "iridescent dagger", "blood rite", "rite", "hhousebloodrite"}));

    set_short("%^BOLD%^%^BLACK%^B%^BOLD%^%^RED%^l%^BOLD%^%^BLACK%^"+
    "o%^BOLD%^%^RED%^o%^BOLD%^%^BLACK%^d %^BOLD%^%^RED%^R%^BOLD%^%^BLACK%^"+
    "i%^BOLD%^%^RED%^t%^BOLD%^%^BLACK%^e%^RESET%^");

    set_obvious_short("%^BOLD%^%^BLACK%^A%^RED%^n %^RED%^irid%^BLACK%^e%^RED%^sce%^BLACK%^n%^RED%^t %^BLACK%^d%^RED%^ag%^BLACK%^g%^RED%^e%^BLACK%^r%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This dagger has an iridesent blade which "+
    "almost seems to reflect %^BOLD%^%^WHITE%^light%^BOLD%^%^CYAN%^ and "+
    "change colors, depending on the angle at which you view it. A "+
    "%^RESET%^%^RED%^dark red%^BOLD%^%^CYAN%^ orb, with a wave of "+
    "energy radiating outward from it, is depicted in approximately the "+
    "center of the blade. The crossguard of the dagger is made from "+
    "a much %^BOLD%^%^BLACK%^darker%^BOLD%^%^CYAN%^ metal that is "+
    "covered in small intricate symbols that move about constantly "+
    "on their own. Both sides of it split and curve up and down to form "+
    "much %^BOLD%^%^WHITE%^lighter%^BOLD%^%^CYAN%^ razor sharp tips. "+
    "The hilt of the dagger is a %^RESET%^%^RED%^dark red%^BOLD%^%^CYAN%^ "+
    "metal that curves slightly toward the bottom before meeting a "+
    "%^BOLD%^%^RED%^brilliant red%^BOLD%^%^CYAN%^ stone that serves as "+
    "the pommel. There are grooves along the length of the hilt to "+
    "provide extra grip when wielded.%^RESET%^");

    set_lore("%^BOLD%^%^RED%^This weapon was crafted by "+
    "Arag Dyne with for sole purpose of bringing back to "+
    "life the ancient Ao'rus Devar. The magic used to create "+
    "this weapon was quite potent, as required by the ritual "+
    "that Arag had found. As a result the weapon itself is "+
    "quite powerful. Some legends "+
    "suggest that it has the ability to leech life, "+
    "penetrate magic defenses on occassion, and to "+
    "disable the foes of its wielder.%^RESET%^");

    set("no curse", 1);
    set_property("enchantment",5);
    set_item_bonus("acid resistance", 20);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    charges = 0;
}

int wield_func()
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You slice your hand on "+
    "the crossguard of the dagger and watch as your %^BOLD%^"+
    "%^RED%^blood%^BOLD%^%^BLACK%^ is absorbed by the "+
    "metal!%^RESET%^");

    tell_room(EETO,ETOQCN+ "%^BOLD%^%^BLACK%^ slices "+ETO->QP+
    " hand on the crossguard of "+ETO->QP+" dagger and "+
    "the %^BOLD%^%^RED%^blood%^BOLD%^%^BLACK%^ is absorbed "+
    "by the metal!%^RESET%^",ETO);

    ETO->cause_typed_damage(ETO, 0, roll_dice(3, 6), "piercing");
    return 1;

}

int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You almost slice your hand "+
    "on the crossguard as you release your hold on the "+
    "dagger!%^RESET%^");
    return 1;
}


int hit_func(object targ)
{
    object *vics;
    string lim;
    int dam, x;
    if(!objectp(targ)) return 1+random(6);
    if(!random(6))
    {
        switch(random(20))
        {
            case 0..14:

                tell_object(ETO, "%^BOLD%^%^CYAN%^Your iridescent "+
                "dagger glows a dark %^RESET%^%^BLUE%^blue%^BOLD%^%^CYAN%^ "+
                "as it slices into "+targ->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^'s iridescent "+
                "dagger glows a dark %^RESET%^%^BLUE%^blue%^BOLD%^%^CYAN%^ "+
                "as it slices into "+targ->QCN+"%^BOLD%^%^CYAN%^"+
                "!%^RESET%^",({ETO, targ}));

                tell_room(targ, ETOQCN+"%^BOLD%^%^CYAN%^'s iridescent "+
                "dagger glows a dark %^RESET%^%^BLUE%^blue%^BOLD%^%^CYAN%^ "+
                "as it slices into you!%^RESET%^");
                charges++;
                ETO->set_property("magic", 1);
                targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(3,4), "slashing");
                ETO->set_property("magic", -1);
                return 0;
                break;

            case 15..18:
                lim = targ->return_target_limb();
                tell_object(ETO, "%^BOLD%^%^GREEN%^You feel your wounds "+
                "begin mending on their own as your %^BOLD%^%^CYAN%^iridescent "+
                "dagger%^BOLD%^%^GREEN%^ slashes across "+targ->QCN+
                "%^BOLD%^%^GREEN%^'s "+lim+"!%^RESET%^");

                tell_object(targ, ETOQCN+"%^BOLD%^%^GREEN%^ slashes "+ETO->QP+
                " %^BOLD%^%^CYAN%^iridescent dagger%^BOLD%^%^GREEN%^ across "+
                "your "+lim+" some of "+ETO->QP + " wounds "+
                "begin mending on their own!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ slashes "+ETO->QP+
                " %^BOLD%^%^CYAN%^iridescent dagger%^BOLD%^%^GREEN%^ across "+
                targ->QCN+"%^BOLD%^%^GREEN%^'s "+lim+" and some of "+ETO->QCN+
                "%^BOLD%^%^GREEN%^'s wounds begin mending on their "+
                "own!%^RESET%^", ({ETO, targ}));
                charges++;
                dam = roll_dice(4,4);
                ETO->heal(dam);
                targ->cause_typed_damage(targ, lim, dam, "slashing");
                break;
            case 19:
                if(charges < 10) return 0;

                tell_object(ETO, "%^BOLD%^%^RED%^A violent wave of "+
                "sonic %^BOLD%^%^CYAN%^energy%^BOLD%^%^RED%^ "+
                "erupts from the blade of your iridescent dagger!%^RESET%^");

                tell_room(EETO, "%^BOLD%^%^RED%^A violent wave of "+
                "sonic %^BOLD%^%^CYAN%^energy%^BOLD%^%^RED%^ "+
                "erupts from the blade of "+ETOQCN+"%^BOLD%^%^RED%^'s "+
                "%^BOLD%^%^CYAN%^iridescent dagger%^BOLD%^%^RED%^!%^RESET%^", ETO);

                vics = ETO->query_attackers();
                if(!sizeof(vics)) return 0;
                for(x = 0;x < sizeof(vics);x++)
                {
                    if(vics[x]->will_save(32))
                    {
                        tell_room(EETO, "%^BOLD%^%^WHITE%^The wave of %^BOLD%^"+
                        "%^CYAN%^sonic energy%^BOLD%^%^WHITE%^ washes over "+
                        vics[x]->QCN+"%^BOLD%^%^WHITE%^, but "+
                        vics[x]->QS+ " %^BOLD%^%^WHITE%^manages to "+
                        "%^BOLD%^%^RED%^shake%^BOLD%^%^WHITE%^ off its "+
                        "effect!%^RESET%^", vics[x]);

                        tell_object(vics[x], "%^BOLD%^%^WHITE%^The wave of "+
                        "%^BOLD%^%^CYAN%^sonice energy%^BOLD%^%^WHITE%^ washes "+
                        "over you but you manage to %^BOLD%^%^RED%^shake"+
                        "%^BOLD%^%^WHITE%^ off its effect!%^RESET%^");
                        continue;
                    }
                    tell_room(EETO, "%^BOLD%^%^WHITE%^The wave of %^BOLD%^"+
                    "%^CYAN%^sonic energy%^BOLD%^%^WHITE%^ washes over "+
                    vics[x]->QCN+"%^BOLD%^%^WHITE%^, %^BOLD%^"+
                    "%^RED%^knocking%^BOLD%^%^WHITE%^ "+vics[x]->QO+
                    " backwards and to the ground!%^RESET%^", vics[x]);

                    tell_object(vics[x], "%^BOLD%^%^WHITE%^The wave of "+
                    "%^BOLD%^%^CYAN%^sonic energy%^BOLD%^%^WHITE%^ "+
                    "washes over you, %^BOLD%^%^RED%^knocking%^BOLD%^%^WHITE%^ "+
                    "you backwards and to the ground!%^RESET%^");

                    vics[x]->cause_typed_damage(vics[x], 0, roll_dice(4, 5), "sonic");
                    vics[x]->set_paralyzed(6, "%^BOLD%^CYAN%^You struggle to "+
                    "get back to your feet!%^RESET%^");
                    continue;
                }
                    charges = 0;
                    break;
        }
    }
}
