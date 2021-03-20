#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
//fearless in player_d.c
int *age_brackets() { return ({ 17, 40, 200, 250 }); }

int *restricted_alignments(string subrace) { return ({ 1, 4, 7}); }

string *restricted_classes(string subrace) {
    return ({ "mage", "magus",  "psion", "psywarrior",  "paladin", "sorcerer", "monk", "warlock", "inquisitor"});
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 4, 0, 4, -2, 0, -4}); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

mapping skill_mods(string subrace) { return ([ "perception" : 2 ]); }


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return -1; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 14, 8, 12, 8, 8, 3 }); }
int *max_stats() { return ({ 20, 15, 18, 18, 18, 14 }); }
int *stat_adj() { return ({ 2, 0, 0, 0, 0, -2 }); }

// Stuff needed to replace what was in the old race database

string race_name() { return "troll"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 10000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 2, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : -2 ]); }

int size() { return 3; }

mapping query_racial_innate(string subrace)
{
	return ([]);
}


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
    if(gender == "male") return 120;
    return 114;
}

int height_mod(string gender) {
    return 18;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 900;
    return 800;
}

int weight_mod(string gender) {
    return 120;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 6;

    switch(gender)
    {
    case "male":
        map["base"] = 780;
        switch(height)
        {
        case 120..122: map["adjust"] = -30; map["die"] = 15; break;
        case 123..129: map["adjust"] = 0;   map["die"] = 10; break;
        case 130..132: map["adjust"] = 0;   map["die"] = 15; break;
        case 133..135: map["adjust"] = 10;  map["die"] = 18; break;
        default:       map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 740;
        switch(height)
        {
        case 114..116: map["adjust"] = -30; map["die"] = 15; break;
        case 117..123: map["adjust"] = 0;   map["die"] = 10; break;
        case 124..126: map["adjust"] = 0;   map["die"] = 15; break;
        case 127..129: map["adjust"] = 10;  map["die"] = 18; break;
        default:       map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"black", "brown"});
    choices += ({"green", "auburn", "white", "crimson"});
    choices += ({"red", "silver", "gray"});
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"black", "green", "white"});
    return choices;
}

string* query_subraces(object who)
{
    return ({ "moss", "hill", "rock" });
}

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    return (["required":({"giant","undercommon"}),"optional":({"orcish","goblin","sylvan"})]);
}
