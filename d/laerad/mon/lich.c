//Coded by Bane//
//added dark, eerie haze message around whoever gets the deed to die function
//so players have a hint of who got credit to be able to finish the quest
//also added some checks for valid object & environment on functions *Styx* 6/2002

#include <std.h>
#include <daemons.h>
inherit "/d/laerad/mon/wander/liwander.c";
int num, stoned, done;
object ob, phy, tooth;
void create()
{
    int num;
    ::create();
    set_id(({ "lich", "hansoth" }));
    set_name("hansoth");
    set_short("Hansoth the decayed Lich");
    set_long(
        "This is perhaps the most terrifying undead creature known to man.  It " +
        "is a Lich, a master of the arcane arts.  Liches were formerly mortal mages " +
        "who became so powerful that even in death they continue to walk amongst us.  " +
        "Its flesh is rotting right off its body, almost a complete skeleton now.  " +
        "It is dressed in a long brown robe, and covered in mystical amulets and gems."
        );
    set_race("lich");
    set_body_type("human");
    set_gender("male");
    set_alignment(9);
    set_size(2);
    set_class("mage");
    set_hd(20 + (random(6)), 2);
    set_mlevel("mage", query_hd());
    set_exp(40000);
    set_guild_level("mage", query_hd());
    set_attack_bonus(10);
    set_mob_magic_resistance("average");
    set_property("no dominate", 1);
    set_property("no death", 1);
    set_property("no rush", 1);
    set_property("strength", "cold");
    set_property("swarm", 1);
    set_property("magic", 1);
    set_stats("strength", 19);
    set_stats("dexterity", 18);
    set_overall_ac(-6);
    set_spells(({
        "magic missile",
        "acid orb",
        "acid orb",
        "greater shout",
        "greater shout",
        "acid breath",
        "vampiric touch",
        "prismatic spray",
        "scorcher",
        "powerword stun",
    }));
    //ob = new("/d/common/obj/potion/healing");
    //ob->move(TO);
    //ob->set_uses(50);
    set_property("add kits", 25);
    if (random(2)) {
        if (TO->query_level() < 20) {
            num = random(7);
        } else {
            num = random(9);
        }
        if (num) {
            ob = new("/d/laerad/obj/bracers" + num)->move(TO);
        } else {
            ob = new("/d/laerad/obj/bracers")->move(TO);
        }
        //if(objectp(ob) && random(2)) ob->set_property("monsterweapon",1);
        command("wear bracers");
    }
    ob = new("/d/laerad/obj/ring_regen");
    ob->move(TO);
    command("wear ring");
    ob = new("/d/laerad/obj/wand_para");
    ob->move(TO);
    if (random(20) < 12) {
        ob->set_property("monsterweapon", 1);
    }
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("lich dust");
    ob->move(TO);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_damage(1, 10);
    set_hit_funcs((["right hand" : (: TO, "stop_me" :),
                    "left hand" : (: TO, "stop_me" :)]));
    set_spell_chance(85);
    stoned = 0;
}

void init()
{
    ::init();
    if (TP->query_level() < 9) {
        if (!SAVING_D->saving_throw(TP, "spell")) {
            call_out("me_run", 2, TP);
        }
    }
    if (wizardp(TP) || TP->query_true_invis()) {
        return 1;
    }
    if (!interactive(TP)) {
        return 1;
    }
    TO->kill_ob(TP, 1);
    new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO, query_hd(), 100, "mage");
}

void me_run()
{
    if (TP == TO) {
        return 1;
    }
    tell_object(TP, "You take one look at the Lich and decide to run for your life!");
    tell_room(ETO, TPQCN + " takes one look at the Lich and decides to run!", TP);
    TP->run_away();
    TP->run_away();
    TP->run_away();
    return 1;
}

void stop_me(object targ)
{
    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }
    if (!SAVING_D->saving_throw(targ, "paralyzation_poison_death")) {
        tell_object(targ, "%^BOLD%^BLUE%^The Lich's touch sends a chill through your body making you as stiff as stone!");
        tell_room(ETO, "%^BOLD%^BLUE%^The Lich's touch makes " + targ->query_cap_name() + " stiffen!", targ);
        targ->set_paralyzed(1000, "You are paralyzed from the Lich's touch!");
        return 1;
    }
}

void heart_beat()
{
    object att;

    ::heart_beat();

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }

    if (base_name(ETO) != "/d/laerad/cavern2/lair") {
        set_exp(15000);
    }else {
        set_exp(40000);
    }
    if (!random(5)) {
        return;
    }
    if (!query_stoneSkinned() && stoned < 5 && random(15) < 5) {
        if (done) {
            return 1;
        }
        new("/cmds/spells/s/_stoneskin.c")->use_spell(TO, TO, query_hd(), 100, "mage");
        done = 1;
        stoned += 1;
        call_out("check_me", 5, TP);
    }
    if (!present(query_name() + " summoned", ETO) && random(20) < 5) {
        if (done) {
            return 1;
        }
        new("/cmds/spells/m/_monster_summoning_vii")->use_spell(TO, 0, query_level(), 100, "mage");
        done = 1;
        call_out("check_me", 5, TP);
    }
    if (!present("wall of fire") && random(20) < 5) {
        if ((string*)TO->query_attackers() == ({})) {
            return 1;
        }
        if (done) {
            return 1;
        }
        new("/cmds/spells/w/_wall_of_fire")->use_spell(TO, 0, query_level(), 100, "mage");
        done = 1;
        call_out("check_me", 5, TP);
    }
    if (present("snake", ETO)) {
        new("/cmds/spells/d/_dispel_magic.c")->use_spell(TO, 0, query_level(), 100, "mage");
    }
    /*if(TO->query_hp() < 75 && present("kit",TO)) {
        force_me("open kit");
        force_me("quaff kit");
        force_me("offer bottle");
        force_me("quaff kit");
        force_me("offer bottle");
        force_me("quaff kit");
        force_me("offer bottle");
       }*/
    att = TO->query_current_attacker();
    if (present("maple wand")) {
        if (random(50) < 5) {
            if (!att) {
                return 1;
            }
            if (!att->query_paralyzed()) {
                force_me("aim maple wand at " + att->query_name());
            }
        }
    }
    if (present("bottle")) {
        force_me("offer bottle");
    }
}

void check_me()
{
    done = 0;
}

void reset()
{
    ::reset();
    stoned = 0;
}

// Fixed typo to be paralyzed from paralyed - Styx 4/29/02
void set_paralyzed(string message, int time)
{
    return 1;
}

void die(object targ)
{
   object who, *killers;
   int i;
   killers = ({});
   killers = filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
    if (objectp(TO) && objectp(ETO) && present("phylactery", ETO)) {
        phy = present("phylactery", ETO);
        tell_room(ETO, "The body of the lich withers away into dust.");
        tell_room(ETO, "%^BOLD%^The power inside the phylactery escapes in a huge explosion!");
        phy->remove();
        tooth = new("/d/laerad/cavern2/special/tooth");
        tooth->move(ETO);
        who = query_current_attacker();
        for(i=0;i<sizeof(killers);i++){
        if(!objectp(killers[i])) { continue; }
            killers[i]->set_mini_quest("Killed Hansoth", 500000, "Killed Hansoth");
            tell_room(ETO, who->query_cap_name() + " is briefly surrounded by a "
                      "%^BOLD%^%^BLACK%^dark, eerie haze %^RESET%^from the explosion.", who);
            tell_object(who, "You are briefly surrounded by a %^BOLD%^%^BLACK%^"
                        "dark, eerie haze %^RESET%^from the explosion.");
        }
        ::die(targ);
        return 1;
    }
    tell_room(ETO, "The liches body starts to collapse in a smoky mist and it seeps into the ground.");
    TO->move("/d/laerad/cavern2/lair");
    TO->set_hp(query_max_hp());
    return 1;
}
