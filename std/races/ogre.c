#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 15, 45, 60, 90 }); }

int *restricted_alignments(string subrace) { return ({ 1, 2, 3, 4, 5, 7 }); }

string *restricted_classes(string subrace) {
  return ({ "cleric", "thief", "mage", "magus",  "bard", "ranger", "psion", "psywarrior",  "paladin", "sorcerer", "monk", "druid", "warlock" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "anhur","helm","lathander","mielikki","oghma","selune","sune","torm","tymora","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 6, -2, 4, -2, 0, -4 }); }

mapping skill_mods(string subrace) { return ([ "endurance" : 2, "athletics" : 2 ]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace) { return -1; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 16, 2, 14, 2, 2, 2 }); }
int *max_stats() { return ({ 20, 8, 20, 8, 9, 8 }); }
int *stat_adj() { return ({ 2, 0, 2, -2, 0, -2 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "ogre"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 10000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 2, "con" : 2, "int" : -2, "wis" : 0, "dex" : 0, "cha" : -2 ]); }

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
    return 106;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 600;
    return 590;
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
        map["base"] = 320;
        switch(height)
        {
        case 96..101:  map["adjust"] = -30; map["die"] = 30; break;
        case 102..114: map["adjust"] = 0;   map["die"] = 20; break;
        case 115..120: map["adjust"] = 0;   map["die"] = 30; break;
        case 121..127: map["adjust"] = 20;  map["die"] = 32; break;
        default:       map["adjust"] = 0;   map["die"] = 20; break;
        }
    default:
        map["base"] = 280;
        switch(height)
        {
        case 93..98:   map["adjust"] = -30; map["die"] = 30; break;
        case 99..111:  map["adjust"] = 0;   map["die"] = 20; break;
        case 112..117: map["adjust"] = 0;   map["die"] = 30; break;
        case 118..124: map["adjust"] = 20;  map["die"] = 32; break;
        default:       map["adjust"] = 0;   map["die"] = 20; break;
        }
    }

    return map;
}

string *query_hair_colors(string who) {
    string *choices = ({});
        choices += ({"ebony"});
        choices += ({"black", "blue-black", "dark green"});
    return choices;
}

string *query_eye_colors(string who) { return ({"purple"}); }

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    return (["required":({"undercommon","giant",}),"optional":({"orcish","gnomish",})]);
}
