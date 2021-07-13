#include <std.h>
#include <daemons.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

int coreparty;

void create()
{
    object ob;
    ::create();

    set_name("The Dead God");
    set_id(({ "the dead god", "avatar", "god", "dead god","outsider" }));
    set_short("%^BOLD%^%^WHITE%^The Dead God");
    set_long("This is a god's chosen form. Standing before you as a giant humanoid figure. The striations of his muscles ripple across his chest. His lean and thick arms flex and unflex before you. The powerful tail swishes back and forth across the floor. The long tongue tests the air. There is a %^RED%^Glow%^CYAN%^ about the creature. After all this is a GOD.");
    set_body_type("human");
    add_limb("tail", "", 0, 0, 0);
    set_gender("male");
    set_race("god");
    set_hd(60, 9);
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_mlevel("fighter", 70);
    set_mlevel("mage", 70);
    set_mlevel("cleric", 70);
    set_guild_level("cleric", 70);
    set_guild_level("mage", 70);
    set_attack_limbs(({ "right claw", "left claw", "mouth" }));
    set_base_damage_type("slashing");
    set_damage(16, 6);
    set_hit_funcs((["mouth" : (: TO, "mouth" :)]));
    set_attacks_num(5);
    set_property("no death", 1);
    set_property("no bows", 1);
    set_mob_magic_resistance("average");
    set_overall_ac(-70);
    set_max_hp(50000);
    set_hp(query_max_hp());
    set_property("add kits", 40);
    set_new_exp(50, "boss");

    set_emotes(30, ({ "%^MAGENTA%^The Dead God growls%^RESET%^: I SHALL RETURN TO THE MORTAL PLANE AND HAVE MY REVENGE ON ALL OF YOU..", "%^MAGENTA%^The Dead God growls%^RESET%^: YOU SHALL FEEL MY PAIN AND THE PAIN OF MY SUBJECTS." }), 20);
    set_funcs(({ "summoning" }));
    set_func_chance(40);
    set_monster_feats(({
        "spell focus",
        "spell penetration",
        "perfect caster",
        "blind fight",
        "spell reflection"
    }));
    set_spells(({ "hellball",
                  "sunburst",
                  "chain lightning",
                  "storm of vengeance",
                  "incendiary cloud",
                  "sleet storm",
                  "entropic storm",
                  "horrid wilting",
                  "acid fog",
                  "meteor swarm",
                  "shadow nova",
                  "prismatic burst" }));
    set_spell_chance(100);
    add_money("platinum", random(100000));
    set_property("no paralyze", 1);
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("divine essence");
    ob->move(TO);
    set_resistance_percent("divine", 100);
    set_resistance_percent("negative energy", 100);
    set_resistance_percent("fire", 50);
    set_resistance_percent("lightning", 50);
    coreparty = 0;
}

int mouth(object targ)
{
    return 10;
}

void set_paralyzed(int time, string message)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^BOLD%^%^RED%^The Dead God seems totally unaffected!%^RESET%^");
    return;
}

int do_typed_damage_effects(victim, limb, damage, damage_type)
{
    if (damage_type == "divine") {
        tell_room(ETO, "%^BOLD%^%^WHITE%^The Dead God seems immune to divine damage!%^RESET%^");
    }
    return damage;
}

void summoning(object targ)
{
    object ob;
    if (present("ibrandlin")) {
        return execute_attack();
    }
    if (present("warrior")) {
        return execute_attack();
    }
    tell_room(ETO, "%^BOLD%^%^RED%^The Dead God summons a follower to assist him in his battle.");
    if (!random(5)) {
        ob = new(MON + "ibrandlin");
        ob->set_attackers(query_attackers());
        ob->set_property("allied_with", TO);
        ob->move(ETO);
    }else {
        ob = new(MON + "followerg");
        ob->set_attackers(query_attackers());
        ob->set_property("allied_with", TO);
        ob->move(ETO);
    }
}

void init()
{
    int psize;
    ::init();
    if (wizardp(TP) || TP->query_true_invis()) {
        return;
    }
    if (!TP->query_ibrandul()) {
        kill_ob(TP, 1);
    }

    if (!interactive(TP) && !TP->query_ibrandul() && !TP->is_merc()) {
        TP->set_hp(-1);
    }
    psize = sizeof(filter_array(all_inventory(ETO), (: userp($1) :)));
    psize = psize < 1 ? 1 : psize;
    if (psize > coreparty) {
        set_max_hp(25000 * psize);
        set_hp(query_max_hp());
        set_damage(16, 5 + psize);
        coreparty = psize;
    }
}

die(object ob)
{
    message("shout", "%^MAGENTA%^The Dead God shouts%^RESET%^: I WILL NOT FALL FOREVER. I WILL BE BACK FOR MY REVENGE.", users());
    tell_room(ETO, "%^BOLD%^%^BLACK%^An audible sigh escapes from the mask as the god slumps to the ground.  With the "
              "release of breath, the horrific visage of the mask upon his face begins to crumble away, leaving only a plain ivory "
              "half-mask behind.%^RESET%^");
    new(OBJ + "newmask")->move(TO);

    WORLD_EVENTS_D->kill_event("Waking A Mad God");
    WORLD_EVENTS_D->inject_event((["Banished The Dead God" : (["start message" : "%^BOLD%^%^WHITE%^The Dead God has been banished, you feel yourself somehow more capable! For the next two hours all experience gained will award an additional %^BOLD%^%^CYAN%^20%%^BOLD%^%^WHITE%^!%^RESET%^", "event type" : "exp bonus", "length" : 120, "notification" : "20% Bonus Exp",
                                                               "event name" : "Banished The Dead God", "modifier" : 20, "announce" : 1, "announce to" : "world" ]), ]));
    return ::die();
}

void heart_beat()
{
    if (!objectp(TO)) {
        return;
    }
    if (query_attackers() == ({}) && coreparty) {
        coreparty = 0;
    }
    ::heart_beat();
}
