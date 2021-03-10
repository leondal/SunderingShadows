#include <std.h>
#include "../../fways.h"
inherit WEAPONLESS;

void create()
{
    object myob;
    ::create();
    set_name("thorn riddled beast");
    set_id(({"beast", "thorn riddled beast", "thorn beast", "dallyhallyevil", "greater thorn beast"}));

    set_short("%^BOLD%^%^GREEN%^th%^RESET%^o%^BOLD%^%^GREEN%^rn "+
    "%^BOLD%^%^GREEN%^r%^RESET%^i%^BOLD%^%^GREEN%^ddl%^RESET%^e%^BOLD%^"+
    "%^GREEN%^d b%^RESET%^ea%^BOLD%^%^GREEN%^st%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This monstrous beast has a body that resembles that "+
    "of a lion at first glance. However, its body is not flesh and blood but a mass of "+
    "writhing vines. Each vine is covered entirely with sharp, vicious looking "+
    "thorns of varying lengths. There are six thicker vines upon which it walks and you "+
    "figure that they serve as appendages. The appendages get shorter and thicker toward the "+
    "back of its body with the last two appendages only perhaps six inches long. It has "+
    "no visible eyes that you can discern but manages to sense the world around it "+
    "some other way.%^RESET%^");

    set_gender("neuter");

    set_level(45);
    set_hd(56, 4);
    set_new_exp(45, "high");

    set_alignment(9);
    set_size(4);
    set_overall_ac(-20);
    set_hp(2000+random(1000));

    set_body_type("briar");

    set_race("thorny beast");

    add_limb("torso", 0, 0, 0, 0);
    add_limb("right forehand ", "torso", 0, 0, 0);
    add_limb("left forehand", "torso", 0, 0, 0);
    add_limb("right middle hand", "torso", 0, 0, 0);
    add_limb("left middle hand", "torso", 0, 0, 0);
    add_limb("right hindleg", "torso", 0, 0, 0);
    add_limb("left hindleg", "torso", 0, 0, 0);
    set_attack_limbs(({"right forehand", "left forehand", "right middle hand", "left middle hand"}));

    set_num_attacks(6);
    set_damage(4,20);
    set_base_damage_type("piercing");

    set_stats("strength", 30);
    set_stats("dexterity", 6);
    set_stats("intelligence", 5);
    set_stats("wisdom", 10);
    set_stats("charisma", 7);
    set_stats("constitution", 30);

    set_resistance("fire", 200);
    set_resistance("electricity", 400);

    set("aggressive", 30);

    set_funcs(({"trample", "impale", "thorn_blast"}));
    set_func_chance(40);

    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_property("weapon resistance", 4);
    set_moving(1);
    set_speed(30);
    //set_nogo(({DDOCK, FRPATH"road1"}));
}

void thorn_blast(object targ)
{
    object *vics;
    int x, dam, mod;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    vics = all_living(ETO);
    vics -= ({TO});
    tell_room(ETO, TOQCN+"%^BOLD%^%^GREEN%^ raises up on its hindlegs and snaps its body forward, "+
    "launching a %^BOLD%^%^BLACK%^VOLLEY%^BOLD%^%^GREEN%^ of thorns!%^RESET%^");
    if(!intp(mod = TO->query("damage mod")) || mod < 1) mod = 1;
    dam = roll_dice(30,4) * mod;
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(vics[x]->id("dallyhallyevil")) continue;
        if(vics[x]->query_true_invis()) continue;
        if(vics[x]->reflex_save(20))
        {
            tell_object(vics[x], "%^BOLD%^%^GREEN%^You are able to move in time to "+
            "avoid most of the thorns!%^RESET%^");

            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^GREEN%^ is able to move in time to "+
            "avoid most of the thorns!%^RESET%^", vics[x]);

            vics[x]->cause_typed_damage(vics[x], 0, dam/2, "piercing");
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^GREEN%^Numerous thorns imbed themselves into "+
        "your body as you are unable to move in time!%^RESET%^");

        tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^GREEN%^ is unable to move in time to "+
        "avoid the numerous thorns!%^RESET%^", vics[x]);

        vics[x]->cause_typed_damage(vics[x], 0, dam, "piercing");
        continue;
    }
    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ emits a horrid %^BOLD%^%^GREEN%^"+
    "SHRIEKING%^BOLD%^%^RED%^ as its volley of thorns ends!%^RESET%^");
    return;
}

void trample(object targ)
{
    int dam, mod;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;

    tell_object(targ, TOQCN+"%^BOLD%^%^RED%^ drops down onto all six appendages and "+
    "%^BOLD%^%^BLACK%^CHARGES%^BOLD%^%^RED%^ at you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ drops down onto all six appendages and "+
    "%^BOLD%^%^BLACK%^CHARGES%^BOLD%^%^RED%^ at "+targ->QCN+
    "%^BOLD%^%^RED%^!%^RESET%^", targ);
    if(!intp(mod = TO->query("damage mod")) || mod < 1) mod = 1;
    dam = roll_dice(18,10) * mod;
    if(targ->reflex_save(20))
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You move out of the way just in time "+
        "as "+TOQCN+"%^BOLD%^%^WHITE%^ charges past you!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ manages to move out of the way "+
        "just in time as "+TOQCN+"%^BOLD%^%^WHITE%^ charges past "+
        targ->QO+"!%^RESET%^", targ);
        return;
    }
    tell_object(targ, TOQCN+"%^BOLD%^%^RED%^ SLAMS%^BOLD%^"+
    "%^BLACK%^ into you, knocking "+
    "you to the ground and trampling you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ SLAMS%^BOLD%^%^BLACK%^ "+
    "into "+targ->QCN+"%^BOLD%^%^BLACK%^, knocking "+targ->QO+" to "+
    "the ground and trampling "+targ->QO+"!%^RESET%^", targ);

    targ->cause_typed_damage(targ, 0, dam, "bludgeoning");
    targ->set_paralyzed(10, "%^BOLD%^%^RED%^The intense pain is all that you can focus "+
    "on!%^RESET%^");
    return;
}


void impale(object targ)
{
    int dam, mod;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;

    tell_object(targ, TOQCN+"%^RESET%^%^ORANGE%^ swings both its "+
    "forehands at you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^RESET%^%^ORANGE%^ swings both its vicious "+
    "forehands at "+targ->QCN+"%^RESET%^%^ORANGE%^!%^RESET%^", targ);
    if(!intp(mod = TO->query("damage mod")) || mod < 1) mod = 1;
    dam = roll_dice(30,6) * mod;
    if(targ->reflex_save(14))
    {
        tell_object(targ, "%^BOLD%^%^RED%^You duck out of the way just in time and "+
        "are only hit with one of the vicious appendages!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ ducks just in time and is hit with "+
        "only one of the vicious appendages!%^RESET%^", targ);

        targ->cause_typed_damage(targ, 0, dam/2, "piercing");
        return;
    }
    tell_object(targ, TOQCN+"%^BOLD%^%^BLACK%^ POUNDS%^BOLD%^%^RED%^ you with "+
    "both of its vicious appendages, impaling you with a particularly "+
    "%^BOLD%^%^BLUE%^brutal%^BOLD%^%^RED%^ thorn!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^BLACK%^ POUNDS%^BOLD%^%^RED%^ "+targ->QCN+
    "%^BOLD%^%^RED%^ with both of its vicious appendages, impaling "+targ->QO+
    " with a particularly %^BOLD%^%^BLUE%^brutal%^BOLD%^%^RED%^"+
    "thorn!%^RESET%^", targ);

    targ->cause_typed_damage(targ, 0, dam, "piercing");
    return;
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    DYN_UP_D->dynamic_update(TO);
    return;
}
