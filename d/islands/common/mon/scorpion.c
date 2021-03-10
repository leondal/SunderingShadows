#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_name("king scorpion");
    set_id(({ "king scorpion", "scorpion", "insect" }));
    set_short("King scorpion");
    set_long("
     The King Scorpion is a potent killer.  It has deadly venom and a poisoned barb at the end of its tail.  The King scorpion also has a thick exoskeleton making it damage resistant.
");
    set_race("king scorpion");
    set_hd(20, 10);
    set_level(20);
    set_size(3);
    set_overall_ac(-8);
    set_class("fighter");
    set_guild_level("fighter", 20);
    set_max_hp(210);
    set_hp(210);
    set_wielding_limbs(({ "right claw", "left claw" }));
    add_limb("right claw", "right claw", 96, 1, 4);
    add_limb("left claw", "left claw", 96, 1, 4);
    add_limb("tail", "tail", 96, 1, 4);
    add_limb("stinger", "stinger", 96, 1, 4);
    set_attacks_num(2);
    set_attack_limbs(({ "left claw", "tail", "right claw" }));
    set_base_damage_type("bludgeoning");
    set_funcs(({ "sting" }));
    set_func_chance(35);
    set_damage(2, 6);
    set_body_type("arachnid");
    set_property("swarm", 1);
    set_property("no bump", 1);
    set_stats("strength", 18);
    set_stats("dexterity", 16);
    set_stats("constitution", 17);
    set("aggressive", "aggfunc");
    set_mob_magic_resistance("average");
    set_exp(5000 + random(2500));
    set_alignment(5);
}

void die(object ob)
{
    message("environment",
            "King scorpion's tail drops from its striking position.\n" "%^RED%^The scorpion backs away from you."
            , environment(TO));
    :: die(ob);
}

int aggfunc()
{
    TP->kill_ob(TO, 0);
    force_me("emote raises its tail above its body in a striking position!");
}

void sting(object targ)
{
    string tlimb;
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    tlimb = targ->return_target_limb();
    if (targ->fort_save(10) || !POISON_D->can_be_poisoned(targ)) {
        tell_object(targ, "%^RED%^King scorpion strikes you with its stinger but you " +
                    "resist its venom!%^RESET%^");
        targ->cause_typed_damage(targ, tlimb, roll_dice(6, 6), "piercing");
        return;
    }

    tell_object(targ,
                "%^RED%^King scorpion pierces you in the " + tlimb + " with its stinger, pumping " +
                "its potent %^BOLD%^%^GREEN%^VENOM%^RESET%^%^RED%^ into you!%^RESET%^");

    tell_room(environment(targ),
              "%^BLUE%^King scorpion pierces " + targ->query_cap_name() + " in the " + tlimb + " with its stinger, pumping its " +
              "potent %^BOLD%^%^GREEN%^VENOM%^RESET%^%^BLUE%^ into " + targ->query_objective() + "!", targ);

    targ->cause_typed_damage(targ, tlimb, roll_dice(12, 6), "piercing");
    targ->add_poisoning(40);
    tell_object(targ,
                "You feel a horrible numbness in your body as the poison takes effect.");
    targ->set_paralyzed(random(30) + 10, "You are paralyzed.");

    return;
}
