#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 45, 60, 90 }); }

int *restricted_alignments(string subrace) { return ({ 1, 4, 5, 7 }); }

string *restricted_classes(string subrace) {
  return ({ });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "anhur","helm","lathander","mielikki","selune","sune","torm","tymora","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 0, 2, 0, 0, -2, 2 }); }

mapping skill_mods(string subrace) { return ([ "rope trick" : 2, "stealth" : 2 ]); }


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return 2; }

mapping daily_uses(string subrace) { return ([ "viper form" : -1 ]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

mapping query_racial_innate(string subrace){
   return ([
   "viper form" : (["type" : "spell", "casting level" : 0.5, "daily uses" : -1, "delay" : 1, "uses left" : -1, "refresh time" : -1, "level required" : 0, "class specific" : 0]),]);
}

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 3, 3, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj()  { return ({ 0, 0, 0, 0, 0, 0 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "yuan-ti"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 9000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 2, "wis" : 2, "dex" : 2, "cha" : -2 ]); }

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
    return 20;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 120;
    return 85;
}

int weight_mod(string gender) {
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 8;

    switch(gender)
    {
    case "male":
        map["base"] = 150;
        switch(height)
        {
        case 60..65: map["adjust"] = -40; map["die"] = 15; break;
        case 66..74: map["adjust"] = -10; map["die"] = 10; break;
        case 75..80: map["adjust"] = 20;  map["die"] = 15; break;
        case 81..86: map["adjust"] = 30;  map["die"] = 25; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 110;
        switch(height)
        {
        case 55..60: map["adjust"] = -10; map["die"] = 15; break;
        case 61..69: map["adjust"] = -5;  map["die"] = 10; break;
        case 70..75: map["adjust"] = 0;   map["die"] = 15; break;
        case 76..81: map["adjust"] = 15;  map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string who) {
    string *choices = ({});
    choices += ({"ebony", "golden", "silver"});
    choices += ({"sable", "auburn", "scarlet", "crimson"});
    choices += ({"black", "brown", "blonde", "red", "white", "gray", "bald"});
    return choices;
}

string *query_eye_colors(string who) {
    string *choices = ({});
    choices += ({"violet", "purple"});
    choices += ({"yellow", "amber"});
    choices += ({"silver", "emerald", "sapphire", "azure", "cyan", "sable", "chocolate", "coffee"});
    choices += ({"green", "hazel"});
    choices += ({"brown", "blue", "gray"});
    return choices;
}

string *query_languages(string subrace)
{
    return (["required":({"common","yuan-ti",}),"optional":({"aklo", "draconic", "elven", "undercommon", "goblin", "sylvan"})]);
}
