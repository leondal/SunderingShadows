#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 45, 60, 90 }); }

int *restricted_alignments(string subrace) { return ({ 1, 2, 3, 4, 7 }); }

string *restricted_classes(string subrace) {
    return ({ "thief", "mage", "magus",  "bard", "ranger", "paladin", "druid", "warlock", "monk", "psion"});
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "helm","torm","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 4, 0, 2, -2, 0, -2 }); }

mapping skill_mods(string subrace) { return ([ "endurance" : 2 ]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace) { return -1; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 14, 3, 14, 3, 2, 2 }); }
int *max_stats() { return ({ 19, 12, 19, 12, 12, 8 }); }
int *stat_adj() { return ({ 1, 0, 1, -1, 0, -1 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "half-ogre"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 10000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 1, "con" : 1, "int" : -1, "wis" : 0, "dex" : 0, "cha" : -1 ]); }

int size() { return 3; }

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
    if(gender == "male") return 84;
    return 78;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 300;
    return 275;
}

int weight_mod(string gender) {
    return 6;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 6;

    switch(gender)
    {
    case "male":
        map["base"] = 270;
        switch(height)
        {
        case 84..86: map["adjust"] = -20; map["die"] = 15; break;
        case 87..93: map["adjust"] = 0;   map["die"] = 10; break;
        case 94..96: map["adjust"] = 0;   map["die"] = 15; break;
        case 97..99: map["adjust"] = 10;  map["die"] = 17; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 220;
        switch(height)
        {
        case 78..80: map["adjust"] = -20; map["die"] = 15; break;
        case 81..87: map["adjust"] = 0;   map["die"] = 10; break;
        case 88..90: map["adjust"] = 0;   map["die"] = 15; break;
        case 91..93: map["adjust"] = 10;  map["die"] = 17; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"ebony"});
    choices += ({"black", "blue-black", "dark green", "brown"});
    return choices;
}

string* query_subraces(object who)
{
    return "/std/races/human"->query_subraces(who);
}

string *query_eye_colors(string who) { return ({"blue", "brown", "gray"}); }

string *query_languages(string subrace)
{
    return (["required":({"common","giant",}),"optional":({"orcish","undercommon","dwarvish","gnomish",})]);
}
