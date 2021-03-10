//Octothorpe (12/21/09)
//Attaya, Warlock
//Original by Thundercracker
//Changed over from mage to warlock class and spells - Octothorpe 4/5/16

#include <std.h>
inherit WEAPONLESS;

void create()
{
    object ob;
    int i;
    object obj;
    ::create();
    set_name("kinnesarudan warlock");
    set_id(({ "warlock", "hooded", "apparition", "hooded apparition" }));
    set_short("%^BOLD%^%^BLACK%^h%^RESET%^oo%^BOLD%^%^BLACK%^d%^RESET%^e" +
              "%^BOLD%^%^BLACK%^d %^RESET%^a%^BOLD%^pp%^RESET%^a%^BOLD%^r" +
              "%^RESET%^i%^BOLD%^t%^RESET%^io%^BOLD%^n%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This hooded apparition is a former " +
             "member of the cabal of spellcasters that served C'Taro, the last " +
             "Kinnesarudan emperor. It is cloaked in a long, ragged robe which " +
             "completely hides the form of the apparition. The hood of the " +
             "robe is pulled down low over the head, and those parts not " +
             "obscured by the hood are enveloped in complete darkness, " +
             "making it completely impossible to determine if anything is " +
             "actually there or not.%^RESET%^");
    set_race("undead");
    set_gender("male");
    set_body_type("human");
    set_hd(24, 1);
    //set_class("mage");
    set_class("warlock");
    set_level(40);
    //set_mlevel("mage",24);
    set_mlevel("warlock", 40);
    set_property("swarm", 1);
    set_spell_chance(90);
    //set_guild_level("mage",24);
    set_guild_level("warlock", 40);
    set_mob_magic_resistance("average");
    set_property("spell penetration", random(10));
    set("warlock_blast_type", "vitriolic");
    set_stats("strength", 12);
    set_stats("dexterity", 16);
    set_stats("constitution", 17);
    set_stats("intelligence", 19);
    set_stats("wisdom", 15);
    set_stats("charisma", 26);
    set_overall_ac(-4);
    set_spells(({
        "dark discorporation",
        "eldritch burst",
        "binding blast",
        "devour magic",
        "wall of fire",
        "phantasmal killer",
        "mire the mind",
        "nightmares made real",
    }));
    /*set_spells(({
       "cone of cold",
       "lightning bolt",
       "meteor swarm",
       "fireball",
       "magic missile",
       "acid breath",
       "static field",
       "ray of enfeeblement",
       "powerword stun",
       "timestop",
       }));*/
    set_moving(1);
    set_speed(99);
    set_alignment(9);
    set_emotes(5, ({
        "%^BOLD%^The apparition slowly scans the surrounding area.",
        "%^BOLD%^The hooded apparition begins chuckling softly to itself."
    }), 0);
    set_size(2);
    set_max_hp(300);
    set_hp(query_max_hp());
    set_new_exp(35, "very high");
    command("message in enters silently.");
    command("message out silently leaves to the $D.");
    set_resistance("negative energy", 20);
    set_resistance("positive energy", -20);
}

void init()
{
    string mrace = TP->query_race();
    ::init();
    if (wizardp(TP)) {
        return;
    }
    if (TP->query_true_invis()) {
        return;
    }
    if (!mrace == "undead") {
        TO->force_me("kill " + TPQN);
    }
}

void die(object ob, object obj, int i)
{
    tell_room(ETO, "%^BOLD%^The apparition groans and the empty robe " +
              "falls to the ground, disintegrating instantly.");
    if (!random(20)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("bone dust");
        ob->move(ETO);
    }
    for (i = 0; i < random(5); i++) {
        obj = new("/d/magic/scroll");
        obj->set_spell(7);
        obj->move(ETO);
    }
    TO->move("/d/shadowgate/void");
    TO->remove();
}
