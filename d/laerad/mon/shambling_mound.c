//Shambling Mound for the ruins of Asgard by ~Circe~ 5/27/13
//Loosely based on /d/laerad/mon/gearth.c

#include <std.h>
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("shambling mound");
    set_id(({ "shambling mound", "shambler", "plant", "mound", "forestmon" }));
    set_short("%^RESET%^%^GREEN%^sha%^ORANGE%^m%^GREEN%^bl%^ORANGE%^i"
              "%^GREEN%^ng mo%^ORANGE%^u%^GREEN%^nd%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This massive mound looks like a moving "
             "pile of brush and leaves.  Spreading over eight feet wide and "
             "standing six feet tall, the mass of %^BOLD%^vines %^RESET%^"
             "%^GREEN%^is tinged with m%^ORANGE%^o%^RESET%^t%^GREEN%^t%^ORANGE%^"
             "l%^RESET%^e%^GREEN%^d spots of %^ORANGE%^brown %^GREEN%^and "
             "%^RESET%^gray%^GREEN%^, as if the creature is in a state of "
             "arrested %^BOLD%^%^BLACK%^decay%^RESET%^%^GREEN%^.  No eyes can "
             "be found, but the creature moves deliberately, making you feel "
             "as though it can see - or sense - its prey quite well.%^RESET%^");
    set_race("shambling mound");
    set_alignment(5);
    set_gender("neuter");
    set_body_type("human");
    set_hd(20, 2 + random(10));
    set_overall_ac(-20);
    set_size(4);
    set_max_level(25);
    set_max_hp(200 + random(100));
    set_hp(query_max_hp());
    set("aggressive", 20);
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_fake_limbs(({ "body mass", "right vine", "left vine" }));
    set_attack_limbs(({ "right vine", "left vine" }));
    set_damage(3, 10);
    set_stats("strength", 21);
    set_stats("dexterity", 10);
    set_stats("constitution", 17);
    set_stats("intelligence", 7);
    set_stats("wisdom", 10);
    set_stats("charisma", 9);
    set_new_exp(20, "normal");
    if (!random(3)) {
        add_money("gold", random(2000) + 250);
    }
    if (!random(3)) {
        add_money("silver", random(2000) + 250);
    }
    if (!random(3)) {
        add_money("copper", random(2000) + 250);
    }
    set_func_chance(15);
    set_funcs(({ "smash", "smash", "smash", "constrict" }));
    command("message in shambles in");
    command("message out shambles $D");
    set_moving(1);
    set_speed(10);
}

void die(mixed ob)
{
    object obj;
    if (!random(4)) {
        switch (random(12)) {
        case 0: obj = new("/d/common/obj/rand/epants");
            obj->set_property("enchantment", 1);
            obj->move(TO);
            break;

        case 1: obj = new("/d/common/obj/rand/cloak");
            obj->set_property("enchantment", 2 + random(2));
            obj->move(TO);
            break;

        case 2: obj = new("/d/common/obj/rand/mage_robes");
            obj->set_property("enchantment", 1);
            obj->move(TO);
            break;

        case 3: obj = new("/d/common/obj/rand/menshirt");
            obj->move(TO);
            break;

        case 4: obj = new("/d/common/obj/rand/r_helm");
            obj->move(TO);
            break;

        case 5: obj = new("/d/common/obj/rand/r_shoes");
            obj->set_property("enchantment", 1);
            obj->move(TO);
            break;

        case 6: obj = new("/d/common/obj/rand/rand_chain");
            obj->set_property("enchantment", 1);
            obj->move(TO);
            break;

        case 7: obj = new("/d/common/obj/rand/rand_leath_head");
            obj->move(TO);
            break;

        case 8: obj = new("/d/common/obj/rand/rand_shirts");
            obj->set_property("enchantment", 1);
            obj->move(TO);
            break;

        case 9: obj = new("/d/common/obj/rand/s_curiass");
            obj->set_property("enchantment", 1);
            obj->move(TO);
            break;

        case 10: obj = new("/d/common/obj/rand/steelshield");
            obj->move(TO);
            break;

        default: obj = new("/d/common/obj/rand/womendress");
            obj->move(TO);
            break;
        }
        tell_room(ETO, "%^RESET%^%^GREEN%^As the shambling mound dies, you "
                  "catch sight of something in the mess of vines.%^RESET%^");
    }
    ::die(ob);
}

void smash(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    tell_object(targ, "%^BOLD%^%^GREEN%^The thick vines of the shambling "
                "mound slam into you!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^GREEN%^The thick vines of the shambling "
              "mound slam into " + targ->QCN + "!%^RESET%^", targ);
    targ->do_damage(targ->return_target_limb(), random(10) + 30);
    return;
}

void constrict(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if ("/daemon/saving_throw_d.c"->reflex_save(targ, 20)) {
        tell_object(targ, "%^RESET%^%^ORANGE%^The shambling mound reaches out, its vines wrapping around you.%^RESET%^");
        tell_object(targ, "%^BOLD%^%^CYAN%^You dodge out of the way just in time!%^RESET%^");
        tell_room(ETO, "%^YELLOW%^The shambling mound's vines reach out at " + targ->QCN + ", bug misses!%^RESET%^", targ);
        return;
    }
    tell_object(targ, "%^ORANGE%^The shambling mound reaches out, its "
                "vines wrapping around you.%^RESET%^");
    tell_object(targ, "%^YELLOW%^You are constricted by the vines!%^RESET%^");
    tell_room(ETO, "%^ORANGE%^The shambling mound's vines wrap around " + targ->QCN + ", " +
              "constricting tightly!%^RESET%^", targ);
    targ->do_damage((string)targ->return_target_limb(), 35 + random(15));
    targ->set_paralyzed((30 + random(30)), "%^BOLD%^You are held tightly by the vines!%^RESET%^");
    return;
}
