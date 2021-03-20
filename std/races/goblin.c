#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 12, 20, 27, 40 }); }

int *restricted_alignments(string subrace) { return ({ 1, 4, 5, 7 }); }

string *restricted_classes(string subrace) {
    return ({ "mage", "magus",  "bard", "psion", "psywarrior",  "paladin", "monk", "druid", "inquisitor" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "anhur","helm","lathander","mielikki","oghma","selune","sune","torm","tymora","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ -2, 4, 0, 0, 0, -2 }); }

mapping skill_mods(string subrace) { return ([ "stealth" : 4, "athletics": 4, "thievery" : 4 ]); }


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return -2; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 4, 4, 5, 3, 3, 3 }); }
int *max_stats() { return ({ 15, 17, 16, 18, 18, 12 }); }
int *stat_adj() { return ({ -1, 0, 0, 0, 0, -1 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "goblin"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 6000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : -1, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : -1 ]); }

int size() { return 1; }

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
    if(gender == "male") return 43;
    return 41;
}

int height_mod(string gender) {
    return 10;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 55;
    return 52;
}

int weight_mod(string gender) {
    return 1;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 5;

    switch(gender)
    {
    case "male":
        map["base"] = 72;
        switch(height)
        {
        case 43..45: map["adjust"] = -10; map["die"] = 6; break;
        case 46..50: map["adjust"] = 0;   map["die"] = 4; break;
        case 51..53: map["adjust"] = 0;   map["die"] = 6; break;
        case 54..56: map["adjust"] = 5;   map["die"] = 7; break;
        default:     map["adjust"] = 0;   map["die"] = 4; break;
        }
    default:
        map["base"] = 68;
        switch(height)
        {
        case 41..43: map["adjust"] = -10; map["die"] = 6; break;
        case 44..48: map["adjust"] = 0;   map["die"] = 4; break;
        case 49..51: map["adjust"] = 0;   map["die"] = 6; break;
        case 52..54: map["adjust"] = 5;   map["die"] = 7; break;
        default:     map["adjust"] = 0;   map["die"] = 4; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"dark brown"});
    choices += ({"black"});
    return choices;
}

string *query_eye_colors(string subrace, int cha) {
    string *choices = ({});
    choices += ({"amber"});
    choices += ({"crimson"});
    choices += ({"red", "yellow"});
    return choices;
}

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    return (["required":({"goblin","undercommon"}),"optional":({"orcish","draconic","giant",})]);
}
