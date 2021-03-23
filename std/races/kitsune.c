#include <std.h>
inherit DAEMON;

void create()
{
    ::create();
}

// age at which each age cat starts: normal, middle, old, venerable
int* age_brackets()
{
    return ({ 15, 100, 150, 300 });
}

int* restricted_alignments(string subrace)
{
    return ({ 1, 3, 7, 9});
}

string* restricted_classes(string subrace)
{
    return ({ "paladin", "inquisitor", "barbarian", "psion", "psywarrior", });
}

string* restricted_deities(string subrace)
{
    return ({});
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ -2, 2, 0, 0, 0, 2 }); }

mapping skill_mods(string subrace) { return ([ "academics" : 2, "thievery":2]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace)
{
    return 2;
}

mapping daily_uses(string subrace) { return (["alter self":1,"dancing lights":1]); }

mapping query_racial_innate(string subrace) {
    return (["alter self" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
             "dancing lights" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
                ]);
}

int misc_bonuses(string subrace, string bonus) { return 0; }

//Undeeded trash, move along
// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 16, 3, 8, 3, 3, 3 }); }
int *max_stats() { return ({ 20, 17, 18, 16, 16, 12 }); }
int *stat_adj() { return ({ 0, 0, 2, 0, 0, 2 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 0; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "kitsune"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 7500; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : -2, "con" : 0, "int" : 0, "wis" : 0, "dex" : 2, "cha" : 2 ]); }

int size() { return 2; }

string *limbs() {
    return ({  "head",
               "right arm",
               "right hand",
               "left arm",
               "left hand",
               "left leg",
               "left hoof",
               "right leg",
               "right hoof",
               "waist",
           "neck"});
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender) {
    return 48;
}

int height_mod(string gender) {
    return 16;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if (gender == "female") {
        return 85;
    }
    return 100;
}

int weight_mod(string gender) {
    return 80;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 3;

    map["base"] = 70;
    switch(height)
    {
    case 50..52: map["adjust"] = -15; map["die"] = 15; break;
    case 53..57: map["adjust"] = 0;   map["die"] = 10; break;
    case 58..60: map["adjust"] = 0;   map["die"] = 15; break;
    case 61..63: map["adjust"] = 5;   map["die"] = 15; break;
    default:     map["adjust"] = 0;   map["die"] = 10; break;
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"silver", "crimson", "ebony"});
    choices += ({"black","white", "red"});
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"sapphire", "azure", "cyan"});
    choices += ({"emerald", "golden"});
    choices += ({"violet","purple", "green"});
    return choices;
}

string *query_languages(string subrace)
{
    return (["required":({"common","sylvan",}),"optional":({"elven","aklo", "celestial", "gnomish", "tengu"})]);
}
