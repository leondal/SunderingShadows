#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/thief" }); }

int caster_class() { return 0; }

string *restricted_races() {
    return ({ "firbolg","half-ogre","ogre","wemic" });
}

string *restricted_classes() { return ({ }); }

int *restricted_alignments() {
    return ({ });
}

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([ "dexterity" : 14 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 0,1,0 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({ "light armor proficiency",
              "simple weapon proficiency",
              "martial weapon proficiency" });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "light armor proficiency", "simple weapon proficiency", "martial weapon proficiency", "dodge" }), 4 : ({ "combat reflexes" }), 7 : ({ "mobility" }), 10 : ({ "tools of the trade" }), 11 : ({ "evasion" }), 14 : ({ "scramble" }), 17 : ({ "spring attack" }) ]);
}

string *class_skills()
{
    return ({ "athletics","dungeoneering","stealth","thievery" });
}

int skill_points() { return 6; }

string old_save_type() { return "thief"; }

string new_save_type() { return "thief"; }

void advanced_func(object player)
{
    player->set_guild_level("thief",(int)player->query_class_level("thief"));
    player->set_advanced((int)player->query_advanced() + 1);
    return;
}
int hit_dice() { return 8; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "thief"; }

string weapons_allowed() { return "thief"; }

int max_stance_offensive() { return 6; }

int max_stance_defensive() { return 3; }

int attack_bonus(object player)
{
    int bonus;
    float penalty, full_level, class_level;
    
    full_level = to_float(player->query_base_character_level());
    class_level = to_float(player->query_prestige_level("thief"));
    
    if(full_level < 20.00)
    {
        bonus = (to_int(class_level) * 3 / 4);
        return bonus;
    }
    
    // Above 20
    // 3/4 BAB gets half penalty to BAB
    // Weighted average of class level compared to total level
    penalty = (10.00 * (class_level / full_level)) / 2.00;
    bonus = to_int(class_level - penalty);
    
    return bonus;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("thief",player->query_class_level("thief"),player);
    num = num / 7;
    return num;
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "thief":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
