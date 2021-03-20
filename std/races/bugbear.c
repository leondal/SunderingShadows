#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 10, 33, 44, 65 }); }

int *restricted_alignments(string subrace) { return ({ 1, 2, 4, 5, 7 }); }

string *restricted_classes(string subrace) {
    return ({ "mage", "magus",  "bard", "psion", "psywarrior",  "paladin", "monk", "warlock", "cleric" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "anhur","helm","lathander","mielikki","selune","sune","torm","tymora","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 2, 2, 0, 0, 0, -2 }); }

mapping skill_mods(string subrace) { return ([ "stealth" : 2, "endurance" : 2 ]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace) { return -2; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 8, 8, 8, 3, 3, 3 }); }
int *max_stats() { return ({ 19, 17, 18, 16, 18, 14 }); }
int *stat_adj() { return ({ 1, 0, 0, -1, 0, -1 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "bugbear"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 8000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 1, "con" : 0, "int" : -1, "wis" : 0, "dex" : 0, "cha" : 0 ]); }

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
    if(gender == "male") return 80;
    return 75;
}

int height_mod(string gender) {
    return 10;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 250;
    return 240;
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
        map["base"] = 210;
        switch(height)
        {
        case 72..77: map["adjust"] = -30; map["die"] = 15; break;
        case 78..86: map["adjust"] = 0;   map["die"] = 10; break;
        case 87..92: map["adjust"] = 0;   map["die"] = 15; break;
        case 93..98: map["adjust"] = 10;  map["die"] = 18; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 180;
        switch(height)
        {
        case 68..73: map["adjust"] = -30; map["die"] = 15; break;
        case 74..82: map["adjust"] = 0;   map["die"] = 10; break;
        case 83..88: map["adjust"] = 0;   map["die"] = 15; break;
        case 89..94: map["adjust"] = 10;  map["die"] = 18; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"sable", "russet", "auburn"});
    choices += ({"brown", "red"});
    return choices;
}

string *query_eye_colors(string subrace) { return ({"green"}); }

int is_pk_race()
{
    return 1;
}


string *query_languages(string subrace)
{
    return (["required":({"goblin","undercommon"}),"optional":({"orcish","drow","giant"})]);
}
