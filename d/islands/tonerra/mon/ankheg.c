//Updated description and mechanics - Octothorpe 11/29/10

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

object caught;
int blah;

void create()
{
    ::create();
    set_name("ankheg");
    set_id(({ "ankheg", "Ankheg" }));
    set_short("%^ORANGE%^chitinous ankheg%^RESET%^");
    set_long("%^ORANGE%^This creature is a rather large, six-legged " +
             "insect that reaches a little over ten feet in length.  Its six " +
             "legs end in sharp hooks suitable to burrowing and grasping.  Its " +
             "powerful mandibles look like they are quite capable of snapping a " +
             "small tree in half with a single bite.%^RESET%^");
    set_hd(13 + random(10), 8);
    set_hp(300 + random(75));
    //set_exp(query_hd() * 325);
    set_new_exp(query_hd(), "high");
    set_max_level(25);
    set_overall_ac(-11);
    set_body_type("snake");
    add_limb("right front leg", "body", 0, 0, 0);
    add_limb("right middle leg", "body", 0, 0, 0);
    add_limb("right rear leg", "body", 0, 0, 0);
    add_limb("left front leg", "body", 0, 0, 0);
    add_limb("left middle leg", "body", 0, 0, 0);
    add_limb("left rear leg", "body", 0, 0, 0);
    add_limb("mandibles", "mouth", 0, 0, 0);
    set_attack_limbs(({ "mandibles" }));
    set_hit_funcs((["mandibles" : (: TO, "crushing" :)]));
    set_funcs(({ "spit" }));
    set_func_chance(25);
    set_damage(3, 12);
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_alignment(5);
    set_gender("female");
    set_race("ankheg");
    set_property("swarm", 1);
    set("aggressive", 25);
    set_stats("strength", 21);
    set_stats("dexterity", 10);
    set_stats("constitution", 17);
    set_stats("intelligence", 1);
    set_stats("wisdom", 13);
    set_stats("charisma", 6);
    set_new_exp(25, "very high");
}

int crushing(object targ)
{
    if (!objectp(targ)) {
        return 0;
    }
    caught = targ;
    tell_object(targ, "%^BOLD%^%^RED%^You are grasped firmly by the " +
                "ankheg's mandibles!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^RED%^" + targ->QCN + " is caught " +
              "tightly by the ankheg's mandibles!%^RESET%^", targ);
    //targ->set_disable(1000,TO);
    //crazy high number and should not be using set_disable anyway - Saide
    targ->set_paralyzed(55, "%^BOLD%^%^RED%^You are grasped " +
                        "firmly by the ankheg's mandibles!%^RESET%^");
    blah = 4;
    return random(4);
}

void spit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!"/daemon/saving_throw_d.c"->reflex_save(targ, -14)) {
        tell_object(targ, "%^ORANGE%^The ankheg expectorates a %^GREEN%^" +
                    "greenish %^ORANGE%^spray at you, that splatters over your " +
                    "body.%^RESET%^");
        tell_room(ETO, "%^ORANGE%^The ankheg expectorates a %^GREEN%^" +
                  "greenish %^ORANGE%^spray at " + targ->QCN + ", splattering " +
                  "over " + targ->QP + " body.%^RESET%^", targ);
        targ->do_damage(targ->return_target_limb(), random(20) + 60);
    }else {
        tell_object(targ, "%^ORANGE%^The ankheg expectorates a %^GREEN%^" +
                    "greenish %^ORANGE%^spray at you, but you are able to dodge " +
                    "most of it.%^RESET%^");
        tell_room(ETO, "%^ORANGE%^The ankheg expectorates a %^GREEN%^" +
                  "greenish %^ORANGE%^spray at " + targ->QCN + ", but " + targ->QCN + " " +
                  "is able to dodge most of it.%^RESET%^", targ);
        targ->do_damage(targ->return_target_limb(), random(10) + 30);
    }
    return;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(caught) || caught->query_ghost() || !present(caught, ETO)) {
        set_attacks_num(1);
        caught = 0;
        return;
    }
    set_attacks_num(0);
    if (!blah--) {
        tell_object(caught, "%^YELLOW%^You feel the mandibles crush you " +
                    "further and the enzymes eat at your body!%^RESET%^");
        tell_room(ETO, "%^YELLOW%^You see " + caught->QCN + " " +
                  "being eaten alive by the ankheg!", caught);
        caught->do_damage("torso", roll_dice(3, 6) + random(4));
        blah = 4;
    }
}
