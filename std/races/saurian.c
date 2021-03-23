#include <std.h>
inherit DAEMON;

void create() { ::create(); }

int *age_brackets() { return ({ 20, 70, 200, 300 }); }

int *restricted_alignments(string subrace) { return ({ 1,3,7,9 }); }

string* restricted_classes(string subrace)
{
    if (!subrace || subrace == "") {
        subrace = "lani-ele";
    }
    switch (subrace) {
    case "hon-ele": return ({ "psion", "monk", "mage", "magus", "psywarrior", "sorcerer", "druid", "ranger", "cleric", "bard", "warlock" }); break;
    default: return ({ "warlock", "monk", "bard", "barbarian","magus", "psywarrior", "sorcerer", "fighter", "paladin", "ranger", "inquisitor" });
    }
}

string *restricted_deities(string subrace) {
    return ({ });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) {
    if(!subrace || subrace == "") return ({ -2, 2, -2, 0, 2, 0 });
    switch(subrace)
    {
    case "hon-ele": return ({ 2, 4, 0, -2, -2, 0 }); break;
    default: return ({ -2, 4, -2, 2, 0, 0 });
    }
}

mapping skill_mods(string subrace) { return ([ "perception" : 2 ]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace) { return 2; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 4, 4, 3, 3, 3 }); }
int *max_stats() { return ({ 16, 18, 15, 17, 18, 14 }); }
int *stat_adj() { return ({ -1, 0, -1, 0, 0, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "saurian"; }

// gets used in a forumla based on con to determine actual weight
int weight() {
    return 8000;
}

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : -1, "con" : -1, "int" : 0, "wis" : 0, "dex" : 0, "cha" : 0 ]); }

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
                "neck",
                "tail"});
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender) {
    return 60;
}

int height_mod(string gender) {
    return 10;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 120;
    return 90;
}

int weight_mod(string gender) {
    return 20;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 3;

    switch(gender)
    {
    case "male":
        map["base"] = 90;
        switch(height)
        {
        case 55..57: map["adjust"] = -10; map["die"] = 15; break;
        case 58..62: map["adjust"] = 0;   map["die"] = 10; break;
        case 63..65: map["adjust"] = 0;   map["die"] = 15; break;
        case 66..68: map["adjust"] = 15;  map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 70;
        switch(height)
        {
        case 50..52: map["adjust"] = -15; map["die"] = 15; break;
        case 53..57: map["adjust"] = 0;   map["die"] = 10; break;
        case 58..60: map["adjust"] = 0;   map["die"] = 15; break;
        case 61..63: map["adjust"] = 5;   map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string who) { return ({"bald"}); }

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"sapphire","azure","cyan","emerald"});
    choices += ({"green","blue"});
    return choices;
}

string *query_subraces(object who) {
    return ({"lani-ele", "hon-ele"});
}

string *query_languages(string subrace)
{
    return (["required":({"common","saurian",}),"optional":({"elven","abyssal","infernal",})]);
}
