#include <std.h>
#include <objects.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 13, 40, 53, 80 }); }

int *restricted_alignments(string subrace) { return ({ 3, 6, 9 }); }

string *restricted_classes(string subrace) {
    return ({ "paladin", "mage", "magus",  "monk", "psion", "psywarrior", "warlock",});
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "bane","beshaba","cyric","helm","talos","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 0, 2, 0, -2, 2, 0 }); }

mapping skill_mods(string subrace) { return ([ "survival" : 2, "stealth" : 2 ]); }


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return 1; }

mapping daily_uses(string subrace) { return ([ "calm animal" : 1 ]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 6, 6, 6, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 19, 16, 18, 18, 17 }); }
int *stat_adj() { return ({ 0, 1, 0, 0, 0, -1 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

string race_name() { return "beastman"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 8000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "dex" : 1, "con" : 0, "int" : 0, "wis" : 0, "cha" : -1 ]); }

mapping query_racial_innate(string subrace)
{
	return (["calm animal" : ({"spell", 0.5, 1, 1, 1, -1})]);
}

int size() { return 2; }

string *limbs() {
    return ({  "head",
               "right arm",
               "right hand",
               "left arm",
               "left hand",
               "left leg",
               "left foot",
               "right leg",
               "right foot",
               "waist",
               "neck" });
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender) {
    if(gender == "male") return 55;
    return 50;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 85;
    return 80;
}

int weight_mod(string gender) {
    return 6;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 3;

    switch(gender)
    {
    case "male":
        map["base"] = 105;
        switch(height)
        {
        case 55..57: map["adjust"] = -15; map["die"] = 15; break;
        case 58..64: map["adjust"] = 0;   map["die"] = 10; break;
        case 65..67: map["adjust"] = 0;   map["die"] = 15; break;
        case 68..70: map["adjust"] = 10;  map["die"] = 18; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 85;
        switch(height)
        {
        case 50..52: map["adjust"] = -10; map["die"] = 15; break;
        case 53..59: map["adjust"] = 0;   map["die"] = 10; break;
        case 60..62: map["adjust"] = 0;   map["die"] = 15; break;
        case 63..65: map["adjust"] = 10;  map["die"] = 18; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}


string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"olive","crimson","silver","auburn"});
    choices += ({"green", "brown","red","white"});
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"amber", "emerald"});
    choices += ({"yellow"});
    choices += ({"brown", "black", "green"});
    return choices;
}


string *query_languages(string subrace)
{
    return (["required":({"beast","common"}),"optional":({"halfling","gnomish","orcish"})]);
}
