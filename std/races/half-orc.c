// Bonuses in lib: +1 saves vs spells. See /std/magic/spell.
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 14, 30, 40, 60 }); }

int *restricted_alignments(string subrace) { return ({}); }

string *restricted_classes(string subrace) {
  return ({ "mage", "magus",  "bard",  "paladin", "monk" });
}

string *restricted_deities(string subrace) { return ({}); }

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 2, 0, 0, 0, 0, 0 }); }

mapping skill_mods(string subrace) { return ([ "endurance" : 2 ]); }


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return 0; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 6, 3, 13, 3, 3, 3 }); }
int *max_stats() { return ({ 19, 17, 19, 17, 17, 12 }); }
int *stat_adj() { return ({ 1, 0, 1, 0, 0, -2 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "half-orc"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 6000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 1, "con" : 1, "int" : 0, "wis" : 0, "dex" : 0, "cha" : -2 ]); }

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
    if(gender == "male") return 60;
    return 55;
}

int height_mod(string gender) {
    return 24;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 150;
    return 110;
}

int weight_mod(string gender) {
    return 12;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height) {
    mapping map=([]);

    map["num"]  = 6;

    switch(gender)
    {
    case "male":
        map["base"] = 135;
        switch(height)
        {
        case 60..62: map["adjust"] = -50; map["die"] = 15; break;
        case 63..69: map["adjust"] = 0;   map["die"] = 10; break;
        case 70..72: map["adjust"] = 0;   map["die"] = 15; break;
        case 73..75: map["adjust"] = 15;  map["die"] = 17; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 95;
        switch(height)
        {
        case 58..60: map["adjust"] = -15; map["die"] = 15; break;
        case 61..67: map["adjust"] = 0;   map["die"] = 10; break;
        case 68..70: map["adjust"] = 0;   map["die"] = 15; break;
        case 71..73: map["adjust"] = 10;  map["die"] = 17; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }
    return map;
}

string* query_subraces(object who)
{
    return "/std/races/human"->query_subraces(who) + "/std/races/orc"->query_subraces(who);
}

string* query_hair_colors(string subrace)
{
    return distinct_array("/std/races/human"->query_hair_colors(subrace) + "/std/races/orc"->query_hair_colors(subrace));
}

string* query_eye_colors(string subrace)
{
    return distinct_array("/std/races/human"->query_eye_colors(subrace) + "/std/races/orc"->query_eye_colors(subrace));
}

string *query_languages(string subrace)
{
    return (["required":({"common","orcish",}),"optional":({"abyssal", "draconic", "giant", "beast", "goblin", "undercommon"})]);
}
