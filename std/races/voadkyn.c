#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 75, 125, 167, 250 }); }

int *restricted_alignments(string subrace) { return ({ 3, 6, 9 }); }

string *restricted_classes(string subrace) {
    return ({ "cleric", "bard", "psion", "psywarrior",  "paladin", "mage", "magus",  "monk", "warlock","inquisitor", "oracle" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "auril","bane","beshaba","cyric","helm","malar","shar","talos","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 4, -2, 2, -2, 0, 0 }); }

mapping skill_mods(string subrace) { return ([ "stealth" : 2, "survival" : 2, "perception" : 2  ]); }


int natural_AC(string subrace) { return 4; }

int sight_bonus(string subrace) { return 2; }

mapping daily_uses(string subrace) { return ([]); } //requires change-self when disguise lib is in.

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 11, 13, 8, 11, 3, 3 }); }
int *max_stats() { return ({ 19, 20, 16, 17, 16, 18 }); }
int *stat_adj() { return ({ 1, 2, -1, 0, -2, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "voadkyn"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 10000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 1, "con" : -1, "int" : 0, "wis" : 0, "dex" : 2, "cha" : -2 ]); }

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
    if(gender == "male") return 108;
    return 102;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 440;
    return 340;
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
        map["base"] = 675;
        switch(height)
        {
        case 108..110: map["adjust"] = -30; map["die"] = 15; break;
        case 111..117: map["adjust"] = 0;   map["die"] = 10; break;
        case 118..120: map["adjust"] = 0;   map["die"] = 15; break;
        case 121..123: map["adjust"] = 15;  map["die"] = 18; break;
        default:       map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 650;
        switch(height)
        {
        case 102..104: map["adjust"] = -30; map["die"] = 15; break;
        case 105..111: map["adjust"] = 0;   map["die"] = 10; break;
        case 112..114: map["adjust"] = 0;   map["die"] = 15; break;
        case 115..117: map["adjust"] = 10;  map["die"] = 18; break;
        default:       map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string who) { return ({"bald", "brown", "black", "auburn", "green", "ebony", "blonde"}); }

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"yellow", "amber"});
    choices += ({"violet", "purple"});
    choices += ({"silver", "emerald", "sapphire", "azure", "cyan", "sable", "chocolate", "coffee"});
    choices += ({"green", "hazel"});
    choices += ({"brown", "blue", "gray"});
    return choices;
}

string *query_languages(string subrace)
{
    return (["required":({"common","elven",}),"optional":({"giant","orcish","gnomish","halfling",})]);
}

mapping query_racial_innate(string subrace) {
	return ([
                    "ghost step" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "speak with animals" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "treeshape" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    ]);
}
