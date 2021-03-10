#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/barbarian" }); } //temporary

int caster_class() { return 0; }

string *restricted_races() { return ({}); }

string *restricted_classes() { return ({  "antipaladin" }); }

int *restricted_alignments() { return ({ 1,2,3 }); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 1,0,0 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({
        "light armor proficiency",
        "medium armor proficiency",
        "shield proficiency",
        "simple weapon proficiency",
        "martial weapon proficiency",
        "rage",
        "powerattack",
        "unarmored defense"
    });
}
/*Added unarmored defense - Octothorpe 1/15/16*/
mapping class_featmap(string myspec) {
    return ([ 1 : ({ "light armor proficiency", "medium armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "rage", "powerattack", "unarmored defense" }), 2 : ({ "dodge" }), 7 : ({ "damage resistance" }), 10: ({"damage reduction"}), 11 : ({ "greater rage"}), 14 : ({ "mobility" }), 17:({"tireless rage"}), 20 : ({ "mighty rage"}) ]);
}

string *class_skills()
{
    return ({ "athletics", "dungeoneering", "endurance", "survival" });
}

int skill_points() { return 4; }

string old_save_type() { return "fighter"; }

string new_save_type() { return "fighter"; }

void advanced_func(object player)
{

player->set_guild_level("barbarian",(int)player->query_class_level("barbarian"));

    return;
}

int hit_dice() { return 12; }

int default_hitpoints() { return 5; }

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level;
    level = (int)player->query_prestige_level("barbarian");
    return level;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num =
"/daemon/bonus_d.c"->attack_bonus("barbarian",player->query_class_level("barbarian"),player);
    num = num / 7;
    return num;
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "barbarian":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
