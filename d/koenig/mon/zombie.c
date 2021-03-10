//zombie.c - Updated by Circe 11/29/03
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("zombie");
    set_id(({ "zombie", "a zombie", "monster", "undead" }));
    set_short("a zombie");
    set_long("This wretched humanoid was once peacefully at rest.  Now it " +
             "has been brought back to some semblance of life, though it hardly " +
             "seems to know it.  Rotting flesh still clings to the bones, and worms " +
             "writhe within its body, feeding on what is left.  It is dressed in tattered " +
             "clothes that are decaying with time, and a horrid stench follows wherever " +
             "it goes.  It uses its powerful fists to slam into its opponent, following the " +
             "orders of its new master.");
    set("agressive", 18);
    set_property("swarm", 1);
    set_alignment(9);
    set_gender(random(2) ? "male" : "female");
    set_property("undead", 1);
    set_body_type("human");
    set_size(2);
    set_race("undead");
    set_hd(9, 10);
    set_max_hp(random(40) + 70);
    set_hp(query_max_hp());
    set_max_level(9);
    set_exp(900);
    set_stats("strength", 10);
    set_stats("charisma", 2);
    set_stats("dexterity", 7);
    set_stats("constitution", 4);
    set_stats("wisdom", 3);
    set_stats("intelligence", 3);
    set_attack_limbs(({ "right hand", "left hand", }));
    set_base_damage_type("bludgeoning");
    set_attacks_num(2);
    set_damage(3, 4);
    set_func_chance(10);
    set_funcs(({ "slam", "stench" }));
    set_achats(3, ({
        "%^BOLD%^%^RED%^The zombie swings mindlessly!%^RESET%^",
        "%^BOLD%^%^RED%^The zombie shambles toward you!%^RESET%^"
    }));
}

void slam(object targ)
{
    int dex, roll;
    dex = targ->query_stats("dexterity");
    roll = random(20);
    if (roll > dex) {
        tell_object(targ, "%^BOLD%^%^RED%^The zombie slams you with both fists, stunning you!");
        tell_room(ETO, "%^BOLD%^%^RED%^The zombie slams into " + targ->query_cap_name() + " with " +
                  "both fists, stunning " + targ->query_objective() + "!", targ);
        targ->set_tripped(1, "You're still recovering from the zombie's attack.");
        targ->do_damage("torso", random(3) + 4);
        return 1;
    }
    tell_object(targ, "%^BOLD%^%^RED%^The zombie tries to pummel you, but you dodge deftly out of the way!");
    tell_room(ETO, "%^BOLD%^%^RED%^" + targ->query_cap_name() + " moves quickly out of the way as the " +
              "zombie tries to slam " + targ->query_objective() + "!", targ);
    return 1;
}

void stench(object targ)
{
    int con, roll;
    con = targ->query_stats("constitution");
    roll = random(20);
    if (roll > con) {
        tell_object(targ, "%^YELLOW%^The horrid stench of the zombie causes you to choke!");
        tell_room(ETO, "%^YELLOW%^A horrid stench rises from the zombie, making " + targ->query_cap_name() + " choke!", targ);
        targ->set_paralyzed(1, "You're still choking from the stench of the zombie.");
        return 1;
    }
    tell_object(targ, "%^YELLOW%^A horrid stench rises from the zombie, but you withstand its effects!");
    tell_room(ETO, "%^YELLOW%^A horrid stench rises from the zombie!", targ);
    return 1;
}
