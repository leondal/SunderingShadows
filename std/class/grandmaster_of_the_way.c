#include <std.h>
#include <dirs.h>
#include <daemons.h>

inherit DAEMON;

#define BASE_CLASS find_object_or_load(DIR_CLASSES+"/monk.c")

void create()
{
    ::create();
}

string *query_base_classes() { return ({ "monk" }); }

int is_prestige_class() { return 1; }

string *search_paths() { return BASE_CLASS->search_paths(); } // temporary

int caster_class() { return BASE_CLASS->caster_class(); }

string *restricted_races() { return BASE_CLASS->restricted_races(); }

string *restricted_classes() { return BASE_CLASS->restricted_classes(); }

int *restricted_alignments() { return BASE_CLASS->restricted_alignments(); }

string *restricted_gods() { return BASE_CLASS->restricted_gods(); }

string requirements() // string version, maybe we'll need this, maybe not, can remove later if not
{
    string str;
    str = "Prerequisites:\n"
        "    20 Monk Levels (level adjustments considered part of required levels)\n"
        "    20 Wisdom stat, before equipment modifiers\n";

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

    if ((player->query_class_level("monk")) < 20) {
        return 0;
    }
    if (player->query_base_stats("wisdom") < 20) {
        return 0;
    }
    return 1;
}

mapping stat_requirements() { return ([ "wisdom" : 20 ]); }

int *saving_throws() { return BASE_CLASS->saving_throws(); }

string *combat_styles() { return BASE_CLASS->combat_styles(); }

string *class_feats(string myspec) { return BASE_CLASS->class_feats(); }

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "grandmaster_of_the_way":
        case "monk":
            level = player->query_class_level("monk");
            level += player->query_class_level("grandmaster_of_the_way");
            return level;

        default:
            return player->query_class_level(the_class);
    }
    return 0;
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "way of the learned pupil" }), 4 : ({ "way of the merciful soul" }), 7 : ({ "grandmaster of the way" }), ]);
}

string *class_skills()
{
    return BASE_CLASS->class_skills();
}

string *way_skills(string way)
{
    string *mySkills;
    mySkills = ({ "endurance", "athletics" });

    switch(way)
    {
        case "way of the elements":
            mySkills += ({"spellcraft", "academics"});
            break;
        case "way of the shadow":
            mySkills += ({"stealth", "perception"});
            break;
        case "way of the fist":
            mySkills += ({"survival", "perception"});
            break;
    }
    return mySkills;
}


int unarmed_damage(object player)
{
    int myLev, amt = roll_dice(1,4);
    if(!objectp(player)) return roll_dice(1,4);
    myLev = (int)player->query_guild_level("monk");
    switch(myLev)
    {
        case 0..10:
            amt = roll_dice(1, 6);
            break;
        case 11..20:
            amt = roll_dice(1, 8);
            break;
        case 21..30:
            amt = roll_dice(1, 10);
            break;
        case 31..50:
            amt = roll_dice(1, 12);
            break;
       /*     break;
        case 26..30:
            return (roll_dice(1, 12) + roll_dice(1, 6));
            break;
        case 31..35:
            return (roll_dice(1, 12) + roll_dice(1, 8));
            break;
        case 36..50:
            return (roll_dice(1, 12) + roll_dice(1, 10));
            break;
        default:
            return (roll_dice(1, 12) + roll_dice(1, 10));*/
    }
    if(FEATS_D->usable_feat(player, "fists of fury")) amt += roll_dice(1,2);
    return amt;
}

int monk_check(object player, string type) { BASE_CLASS->monk_check(player,type); }

int effective_enchantment(object player)
{
    int amt;
    if(!objectp(player)) return 0;
    if(!(int)player->query_guild_level("monk")) return 0;
    amt = ((int)player->query_guild_level("monk") / 6);
    if(FEATS_D->usable_feat(player, "enchanted fists")) amt += 1;
    return amt;
}

int critical_multiplier(object player)
{
    if(!objectp(player)) return 0;
    return ((int)player->query_guild_level("monk") / 10);
}

int critical_damage(object player)
{
    if(!objectp(player)) return 0;
    else return unarmed_damage(player);
}


int skill_points() { return BASE_CLASS->skill_points(); }

string old_save_type() { return BASE_CLASS->old_save_type(); }

string new_save_type() { return BASE_CLASS->new_save_type(); }

// unsure on this one, will have to investigate
void advanced_func(object player) { return BASE_CLASS->advance_func(player); }

int hit_dice() { return BASE_CLASS->hit_dice(); }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return BASE_CLASS->default_hitpoints(); } // hitpoints per level above level 20

string armor_allowed() { return BASE_CLASS->armor_allowed(); }

string weapons_allowed() { return BASE_CLASS->weapons_allowed(); }

int max_stance_offensive() { return BASE_CLASS->max_stance_offensive(); }

int max_stance_defensive() { return BASE_CLASS->max_stance_defensive(); }

int attack_bonus(object player) { return 0; }

int number_of_attacks(object player) { return BASE_CLASS->number_of_attacks(player); }

string newbie_choice() { return BASE_CLASS->newbie_choice(); }

string *query_newbie_stuff() { return BASE_CLASS->query_newbie_stuff(); }

void process_newbie_choice(object who, string str) { return BASE_CLASS->process_newbie_choice(who,str); }

string query_casting_stat() { return BASE_CLASS->query_casting_stat(); }

mapping query_class_spells() { return BASE_CLASS->query_class_spells(); }
