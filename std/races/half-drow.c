// Bonuses in lib: +2 vs charm spells, sleep immunity. See /std/magic/spell.
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 45, 60, 90 }); }

int *restricted_alignments(string subrace) { return ({ 1, 4, 7 }); }

string *restricted_classes(string subrace) { return ({ "bard", "paladin" }); }

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "helm","torm","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 0, 2, 0, 0, 0, 0 }); }

mapping skill_mods(string subrace) { return ([ "perception" : 2 ]); }


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return -1; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 6, 6, 4, 3, 3 }); }
int *max_stats() { return ({ 18, 19, 17, 18, 18, 16 }); }
int *stat_adj() { return ({ 0, 1, 0, 0, 0, -2 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "half-drow"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 7500; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 0, "wis" : 0, "dex" : 1, "cha" : -2 ]); }

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
    return 55;
}

int height_mod(string gender) {
    return 16;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 95;
    return 85;
}

int weight_mod(string gender) {
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 3;

    switch(gender)
    {
    case "male":
        map["base"] = 100;
        switch(height)
        {
        case 55..57: map["adjust"] = -18; map["die"] = 18; break;
        case 58..63: map["adjust"] = -10; map["die"] = 12; break;
        case 64..67: map["adjust"] = 0;   map["die"] = 18; break;
        case 68..70: map["adjust"] = 10;  map["die"] = 20; break;
        default:     map["adjust"] = 0;   map["die"] = 12; break;
        }
    default:
        map["base"] = 110;
        switch(height)
        {
        case 57..59: map["adjust"] = -18; map["die"] = 18; break;
        case 60..65: map["adjust"] = -5;  map["die"] = 12; break;
        case 66..69: map["adjust"] = 0;   map["die"] = 18; break;
        case 70..72: map["adjust"] = 15;  map["die"] = 20; break;
        default:     map["adjust"] = 0;   map["die"] = 12; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"platinum"});
    choices += ({"silver"});
    choices += ({"blonde", "brown"});
    choices += ({"white"});
    return choices;
}

string *query_eye_colors(string subrace, int cha) {
    string *choices = ({});
    choices += ({"blue"});
    choices += ({"brown", "chocolate", "coffee", "sable"});
    choices += ({"black", "red"});
    return choices;
}

int is_pk_race()
{
    return 1;
}

string* query_subraces(object who)
{
    return "/std/races/human"->query_subraces(who);
}

string *query_languages(string subrace)
{
    return (["required":({"common","undercommon"}),"optional":({"drow","goblin","giant","orcish","elven",})]);
}
