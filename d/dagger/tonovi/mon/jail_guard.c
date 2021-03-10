// further adapted from Styx's code by Circe for the Tonovi jail ;)
// Circe is a thief.

// Circe is awesome and welcome to plunder my code anytime :) *Styx*
// Updated to use the new jail inheritable stuff by Styx 9/2005

#include <std.h>
#include <daemons.h>
#include "/d/dagger/tonovi/town/short.h"
//#define GUARD_D "/d/dagger/tonovi/mon/guards/guard_d"

inherit "/std/jailer";

void create()
{
    ::create();
    set_jail_location("Tonovi");
    set_jail("/d/dagger/tonovi/town/jail1");
    set_cell("/d/dagger/tonovi/town/cell");
    set_property("knock unconscious", 1);
    set_id(({ "jailer", "supervisor", "Tonovi jailer", "tonovi law", "waynon", "Waynon" }));
    set_name("Tonovi Jailer");
    set_short("Waynon Simpson, jail supervisor");
    set_long("%^BOLD%^%^RED%^This human is the jail supervisor, " +
             "determined by looking at the insignia on his uniform.  " +
             "While not readily recognized as being armored, if you " +
             "look at him carefully you can see that he wears padded " +
             "leather armor.  His cloak is tied behind him and the " +
             "city seal is embroidered into it prominently.  A small " +
             "set of keys is secured to his waist.  He is crisp in " +
             "appearance and is imposing.  He stands at attention " +
             "behind the desk most of the time, but occasionly he can " +
             "be seen sitting in a chair.  He carefully watches all " +
             "visitors to the office.%^RESET%^"
             );
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(30 + (random(9)), 6);
    set_hp(350 + (random(50)));
    set_max_level(30);
    set_overall_ac(-15);
    set_exp(100);
    set_alignment(3);
    set_class("fighter");
//    set_guild_level("fighter",24);
    set_stats("charisma", 12);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "right hand", "left hand", "right foot", "left foot" }));
    set_attacks_num(5);
    set_damage(2, 5);
    set_mob_magic_resistance("average");
    set_property("swarm", 1);
    set_property("no bows", 1);
    set_property("no dominate", 1);
    set_funcs(({ "leg_sweep", "neck_jab" }));
    set_func_chance(70);
    new(OPATH "jail_key")->move(TO);
    force_me("wear key");
}

void reset()
{
    object ob;
    ::reset();
    if (ob = present("skeleton key")) {
        if (!ob->query_worn()) {
            command("wear key");
        }
    }
}

void init()
{
    ::init();
    if (base_name(ETO) == JailFile) {
        add_action("guard_check", "pick");
        add_action("guard_check", "unlock");
    }
    add_action("no_way", "rush");
    add_action("no_way", "stab");
}

int kill_ob(object ob, int i)
{
    int hold;
    hold = ::kill_ob(ob, i);
    if (hold) {
        tell_room(ETO, "The guard yells loudly for help.");
        new("/d/dagger/tonovi/mon/guard1_city")->move(ETO);
        new("/d/dagger/tonovi/mon/guard1_city")->move(ETO);
        new("/d/dagger/tonovi/mon/guard1_city")->move(ETO);
    }
    return hold;
}

void guard_check(string str)
{
    string* jailers;
    jailers = AREALISTS_D->query_jailer_names(JailLoc);
    if (str != "lock on cell door" && str != "cell door with key") {
        return 0;
    }
    if (member_array(TPQN, jailers) != -1) {
        return 1;
    }
    if (str == "lock on cell door") {
        tell_room(ETP, "%^YELLOW%^The jailer catches " + TPQCN + " trying to pick "
                  "the lock to the cell door!", TP);
        tell_object(TP, "%^YELLOW%^The jailer catches you trying to pick the "
                    "lock and attacks!");
    }
    if (str == "cell door with key" || str == "cell door with skeleton key") {
        if (TP->query_true_invis()) {
            return 0;
        }
        tell_room(ETP, "%^YELLOW%^The jailer catches " + TPQCN + " trying to unlock "
                  "the cell door!", TP);
        tell_object(TP, "%^YELLOW%^The jailer catches you trying to unlock "
                    "the cell door and attacks!");
    }
    force_me("kill " + TPQN);
    command("block south");
    return 0;
}

void neck_jab(object targ)
{
    if (!objectp(TO)) {
        return;
    }
    if (!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death")) {
        tell_object(targ, "%^BOLD%^%^RED%^The jailer moves swifly, " +
                    "jabbing you in the neck!\nYou double over in pain!");
        tell_room(ETO, "%^BOLD%^RED%^The jailer swiftly jabs " +
                  "" + targ->QCN + " in the neck, doubling " + targ->QO + " " +
                  "over in pain!", targ);
        targ->do_damage("neck", roll_dice(5, 10) + 10);
        return 1;
    }
    tell_object(targ, "%^BOLD%^RED%^The jailer makes a jab for you, " +
                "but you slip partially out of the way!");
    tell_room(ETO, "%^BOLD%^RED%^The jailer attempts to jab " +
              "" + targ->QCN + ", but " + targ->QS + " slips partially out of the way!", targ);
    targ->do_damage(targ->return_target_limb(), roll_dice(3, 5) + 10);
    return 1;
}

void leg_sweep(object targ)
{
    if (!objectp(TO)) {
        return;
    }
    if (!"daemon/saving_d"->saving_throw(targ, "rod_staff_wand")) {
        tell_object(targ, "%^BOLD%^The jailer sweeps your leg out and " +
                    "sends you crashing to the floor!\n%^RED%^You hit your head!");
        tell_room(ETO, "%^BOLD%^The jailer sweeps " + targ->QCN + "'s legs " +
                  "out from under " + targ->QO + ", sending " + targ->QO + " " +
                  "crashing to the floor!", targ);
        targ->do_damage(targ->return_target_limb(), roll_dice(5, 10) + 10);
        targ->set_paralyzed(50, "You are recovering from hitting your head on the floor.");
        return 1;
    }
    tell_object(targ, "%^RED%^The jailer tries to sweep your " +
                "leg, but you stand straight!");
    tell_room(ETO, "%^RED%^The jailer tries to sweep " + targ->QCN + "'s " +
              "leg but misses!", targ);
    return 1;
}

int no_way()
{
    write("The jailer easily catches you at your pitiful attempt in "
          "this small room.");
    return 1;
}
