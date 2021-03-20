#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 12, 35, 46, 70 }); }

int *restricted_alignments(string subrace) { return ({ 3, 6, 9 }); }

string *restricted_classes(string subrace) {
    return ({ "thief", "cleric", "mage", "magus",  "psion", "psywarrior", "paladin", "sorcerer", "monk", "warlock", "inquisitor" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "auril","bane","beshaba","cyric","helm","malar","shar","talos","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 4, 2, 2, -2, -2, -2 }); }

mapping skill_mods(string subrace) { return ([ "endurance" : 2 ]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace) { return 2; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 11, 6, 11, 3, 3, 3 }); }
int *max_stats() { return ({ 19, 17, 18, 18, 18, 18 }); }
int *stat_adj() { return ({ 1, -1, 0, 0, 0, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "centaur"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 10000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 1, "con" : 0, "int" : 0, "wis" : 0, "dex" : -1, "cha" : 0 ]); }

int size() { return 3; }

string *limbs() {
    return ({   "head",
                "right arm",
                "right hand",
                "left arm",
                "left hand",
                "left foreleg",
                "left forehoof",
                "right foreleg",
                "right forehoof",
                "left hindleg",
                "left hindhoof",
                "right hindleg",
                "right hindhoof",
                "tail",
                "waist",
                "lower torso",  });
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender) {
    if(gender == "male") return 84;
    return 80;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 975;
    return 950;
}

int weight_mod(string gender) {
    return 18;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 4;

    switch(gender)
    {
    case "male":
        map["base"] = 700;
        switch(height)
        {
        case 78..84:  map["adjust"] = -40; map["die"] = 30; break;
        case 85..92:  map["adjust"] = 0;   map["die"] = 20; break;
        case 93..97:  map["adjust"] = 0;   map["die"] = 30; break;
        case 98..101: map["adjust"] = 30;  map["die"] = 32; break;
        default:      map["adjust"] = 0;   map["die"] = 20; break;
        }
    default:
        map["base"] = 670;
        switch(height)
        {
        case 75..81:  map["adjust"] = -40; map["die"] = 30; break;
        case 82..89:  map["adjust"] = 0;   map["die"] = 20; break;
        case 90..94:  map["adjust"] = 0;   map["die"] = 30; break;
        case 95..98:  map["adjust"] = 30;  map["die"] = 32; break;
        default:      map["adjust"] = 0;   map["die"] = 20; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"golden", "crimson", "scarlet", "auburn", "ebony"});
    choices += ({"red", "blonde", "sable"});
    choices += ({"brown", "black"});
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"emerald", "sable"});
    choices += ({"brown", "green", "hazel"});
    return choices;
}

string *query_languages(string subrace)
{
    return (["required":({"elven","common"}),"optional":({"gnomish","halfling","orcish"})]);
}
