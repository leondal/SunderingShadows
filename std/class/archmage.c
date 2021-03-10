#include <std.h>
#include <dirs.h>

inherit DAEMON;

object base_class_ob(object ob)
{
    object class_ob;
    if(!objectp(ob))
    {
        class_ob = find_object_or_load(DIR_CLASSES+"/mage.c");
    }
    else { class_ob = find_object_or_load(DIR_CLASSES+"/"+ob->query("base_class")+".c");
        if(!ob->query("base_class"))
        {
            if(ob->is_class("sorcerer"))
                ob->set("base_class","sorcerer");
            if(ob->is_class("mage"))
                ob->set("base_class","mage");
        }
    }
    if(!objectp(class_ob)) { class_ob = find_object_or_load(DIR_CLASSES+"/mage.c"); }
    return class_ob;
}

void create()
{
    ::create();
}

string *query_base_classes() { return ({ "mage", "sorcerer" }); }

int is_prestige_class() { return 1; }

string *search_paths(object ob) { return base_class_ob(ob)->search_paths(); } // temporary

int caster_class() { return ; }

string *restricted_races(object ob) { return base_class_ob(ob)->restricted_races(); }

string *restricted_classes(object ob) { return base_class_ob(ob)->restricted_classes(); }

int *restricted_alignments() { return ({}); }

string *restricted_gods() { return ({}); }

string requirements() // string version, maybe we'll need this, maybe not, can remove later if not
{
    string str;
    str = "Prerequisites:\n"
        "    10 Skill points spent in the spellcraft skill\n"
        "    20 Base class levels\n"
        "    20 Stat used for casting for your class\n";

    return str;
}


int prerequisites(object player)
{
    object race_ob;
    string race;
    int adj;
    if (!objectp(player)) {
        return 0;
    }

    race = player->query("subrace");
    if (!race) {
        race = player->query_race();
    }
    race_ob = find_object_or_load(DIR_RACES + "/" + player->query_race() + ".c");
    if (!objectp(race_ob)) {
        return 0;
    }

    if (player->is_class("mage")) {
        if ((player->query_class_level("mage")) < 20) {
            return 0;
        }
        if (player->query_base_stats("intelligence") < 20) {
            return 0;
        }
        player->set("base_class", "mage");
    }
    if (player->is_class("sorcerer")) {
        if ((player->query_class_level("sorcerer") + adj) < 20) {
            return 0;
        }
        if (player->query_base_stats("charisma") < 20) {
            return 0;
        }
        player->set("base_class", "sorcerer");
    }
    return 1;
}

mapping stat_requirements(object ob) {
    if(!objectp(ob) || ob->is_class("mage")) { return ([ "intelligence" : 20 ]); }
    return ([ "charisma" : 20 ]);
}

int *saving_throws(object ob) { return base_class_ob(ob)->saving_throws(); }

string *combat_styles(object ob) { return ({}); }

string *class_feats(string myspec) { return base_class_ob(0)->class_feats(); }

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "mage":
            level = player->query_class_level("mage");
            level += player->query_class_level("archmage");
            return level;
        case "sorcerer":
            level = player->query_class_level("sorcerer");
            level += player->query_class_level("archmage");
            return level;
        case "archmage":
            level = player->query_class_level("archmage");
            level += player->query_class_level("mage");
            level += player->query_class_level("sorcerer");
            return level;

        default:
            return player->query_class_level(the_class);
    }
    return 0;
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "school familiarity", "magic school"}), 4 : ({ "greater spell mastery" }), 7 : ({ "arcane perfection" }), ]);
}

string *class_skills(object ob)
{
    return base_class_ob(ob)->class_skills();
}

int skill_points(object ob) { return base_class_ob(ob)->skill_points(); }

string old_save_type(object ob) { return base_class_ob(ob)->old_save_type(); }

string new_save_type(object ob) { return base_class_ob(ob)->new_save_type(); }

// unsure on this one, will have to investigate
void advanced_func(object player) { return base_class_ob(player)->advance_func(player); }

int hit_dice(object ob) { return base_class_ob(ob)->hit_dice(); }  // hit dice rolled for hitpoints each level

int default_hitpoints(object ob) { return base_class_ob(ob)->default_hitpoints(); } // hitpoints per level above level 20

string armor_allowed(object ob) { return base_class_ob(ob)->armor_allowed(); }

string weapons_allowed(object ob) { return base_class_ob(ob)->weapons_allowed(); }

int max_stance_offensive(object ob) { return base_class_ob(ob)->max_stance_offensive(); }

int max_stance_defensive(object ob) { return base_class_ob(ob)->max_stance_defensive(); }

int attack_bonus(object player) { return 0; }

int number_of_attacks(object player) { return base_class_ob(player)->number_of_attacks(player); }

string newbie_choice(object ob) { return base_class_ob(ob)->newbie_choice(); }

string *query_newbie_stuff(object ob) { return base_class_ob(ob)->query_newbie_stuff(); }

void process_newbie_choice(object who, string str) { return base_class_ob(who)->process_newbie_choice(who,str); }

string query_casting_stat(object ob) { return base_class_ob(ob)->query_casting_stat(); }

mapping query_class_spells(object ob) { return base_class_ob(ob)->query_class_spells(); }
