#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 50, 300, 400, 500 }); }

int query_unbound_age()
{
    return 1;
}

int *restricted_alignments(string subrace) { return ({ 1,2,3 }); }

string *restricted_classes(string subrace) {
    return ({  "paladin", "fighter", "barbarian", "thief", "psion", "psywarrior", "monk", "inquisitor" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({});
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 0, 0, 0, 0, 0, 2 }); }

mapping skill_mods(string subrace) { return ([ "survival" : 2, "healing" : 2]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace) { return 2; }

mapping daily_uses(string subrace) { return (["treeshape":1,"commune with nature":1,"meld into nature":1]); }

mapping query_racial_innate(string subrace) {
	return (["treeshape" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
             "commune with nature" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
             "meld into nature" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
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

int is_gender_locked(string mygender)
{
    if(mygender!="female")
        return 1;
    return 0;
}

// Stuff needed to replace what was in the old race database

string race_name() { return "dryad"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 7500; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 0, "wis" : 0, "dex" : 2, "cha" : 2 ]); }

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
    return 60;
}

int height_mod(string gender) {
    return 15;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    return 120;
}

int weight_mod(string gender) {
    return 8;
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
    choices += ({"ebony", "ivory"});
    choices += ({"sable", "auburn", "scarlet", "crimson"});
    choices += ({"black", "brown", "red", "white", "gray", "green"});
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"amber", "sapphire", "silver", "emerald" });
    choices += ({"black", "yellow", "blue", "green"});
    return choices;
}

string *query_languages(string subrace)
{
    return (["required":({"common","sylvan",}),"optional":({"elven","aquan","gnomish","abyssal"})]);
}
