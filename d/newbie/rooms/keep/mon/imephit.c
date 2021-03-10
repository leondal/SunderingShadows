#include <std.h>
#include "../../inherit/keep.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("ice mephit");
    set_id(({ "mephit", "imp", "ice mephit" }));
    set_short("%^BOLD%^%^CYAN%^an ice mephit%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^This little outsider is a relative of the "
             "%^RESET%^%^RED%^imp%^BOLD%^%^CYAN%^. It is an %^BLUE%^icy blue color%^CYAN%^"
             ", with %^WHITE%^sharp white claws %^CYAN%^and over-large ears. The air "
             "around it seems to turn %^RESET%^%^CYAN%^frigid %^BOLD%^as it passes. It "
             "leers with a malicious grin as it surveys its surroundings.  A %^RESET%^"
             "%^CYAN%^glossy orb %^BOLD%^%^CYAN%^is clutched tightly in one of its "
             "claws.%^RESET%^");
    set_gender("neuter");
    set_race("imp");
    set_body_type("humanoid");
    set_size(1);
    set_hd(4, 6);
    set_level(4);
    set_class("thief");
    set_mlevel("thief", 4);
    set_alignment(3);
    set_overall_ac(4);
    set_max_hp(random(20) + 40);
    set_hp(query_max_hp());
    add_limb("right claw", "right hand", 0, 0, 0);
    add_limb("left claw", "left hand", 0, 0, 0);
    set_damage(1, 6);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "mouth", "left claw", "right claw" }));
    set_hit_funcs((["mouth" : (: TO, "breath" :) ]));
    set_property("swarm", 1);
    set("aggressive", 25);
    //set_exp(800);
    set_funcs(({ "frost" }));
    set_func_chance(10);
    set_new_exp(1, "very low");
}

void init()
{
    ::init();
    if (avatarp(TP) && TP->query_invis()) {
        return;
    }
    force_me("kill " + TPQCN + "");
}

int breath(object targ)
{
    int i, j;
    object* inven;

    inven = all_living(ETO);
    j = sizeof(inven);
    tell_object(targ, "%^BOLD%^%^CYAN%^The mephit breathes a cone of chilling "
                "ice directly at you!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^CYAN%^The mephit breathes a cone of chilling ice "
              "directly at " + targ->QCN + "!%^RESET%^", targ);
    targ->do_damage("torso", random(5) + 8);
    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        if (inven[i] == targ) {
            continue;
        }
        if (random(2)) {
            tell_object(inven[i], "%^BOLD%^%^CYAN%^You are hit by the edge of "
                        "the blast!%^RESET%^");
            tell_room(ETO, "%^BOLD%^%^CYAN%^" + inven[i]->QCN + " is hit by the edge "
                      "of the blast!%^RESET%^", inven[i]);
            inven[i]->do_damage("torso", random(4) + 4);
        }
    }
    return 1;
}

void cloud(object targ)
{
    int i, j;
    object* inven;

    inven = all_living(ETO);
    j = sizeof(inven);
    tell_room(ETO, "%^BOLD%^%^WHITE%^The air around the mephit suddenly turns "
              "icy cold!%^RESET%^");
    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        if (avatarp(TO)) {
            continue;
        }
        if (random(3)) {
            targ->set_paralyzed(6, "%^BOLD%^%^WHITE%^Your movements "
                                "are slowed by the freezing air!%^RESET%^");
        }
    }
    return;
}

void die(object ob)
{
    tell_room(ETO, "%^CYAN%^The mephit lets out a dying wail, and its claws "
              "release their vice-grip on the glossy orb it had been guarding.%^RESET%^");
    new(OBJ2 "stafforb")->move(TO);
    ::die(ob);
}
