//strength.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("guardian of dexterity");
    set_short("Guardian of dexterity");
    set_id(({ "guardian", "dexterity", "guardian of dexterity" }));
    set_long("This is the guardian of dexterity. He stands watch over the dexterity of the monks. He looks like a middle aged man of average height and weight. He is a wiry built man, skinny but hard. His eyes dart about much like the movements of a skilled artist.");
    set_race("guardian");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(-20);
    set_hd(55, 1);
    set_class("thief");
    set_mlevel("thief", 90);
    set_hp(550);
    set_exp(45000);
    set_new_exp(35, "boss");
    set_max_level(36);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_damage(2, 8);
    set_base_damage_type("bludgeoning");
    set_thief_skill("hide in shadows", 100);
    set_thief_skill("move silently", 100);
    add_search_path("/cmds/thief/");
    set_stats("dexterity", 100);
    set_scrambling(1);
    set_stats("wisdom", 1);
    set_stats("intelligence", 1);
    set_stats("charisma", 1);
    new(MONASTERY + "dex")->move(TO);
}

void init()
{
    ::init();
    if (!TP->query_true_invis() && member_array("guardian", (string*)TP->query_id()) == -1) {
        kill_ob(TP, 1);
    }
}

void set_paralyzed(int time, string message)
{
    tell_room(ETO, "%^BOLD%^The paralysis has no effect.");
    return;
}

int do_damage(string limb, int dam)
{
    if (base_name(PO) == "/cmds/assassin/_stab" || base_name(PO) == "/cmds/thief/_stab") {
        return ::do_damage(limb, dam / 2);
    }
    if (PO->is_spell()) {
        return ::do_damage(limb, dam);
    }

    return ::do_damage(limb, dam);
}

int query_watched()
{
    return 100;
}
