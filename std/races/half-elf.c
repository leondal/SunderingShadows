// Bonuses in lib: +2 vs charm spells, sleep immunity. See /std/magic/spell.
// added tiefling to the template to support Niccoli on the half-elf race. N, 3/11.
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 45, 60, 90 }); }

int *restricted_alignments(string subrace) {
    return ({});
}

string *restricted_classes(string subrace) { return ({  "paladin" }); }

string *restricted_deities(string subrace) { return ({}); }

// stats in order: str, dex, con, int, wis, cha
int* stat_mods(string subrace)
{
        return ({ 0, 0, 0, 0, 0, 0 });
}

int is_statmod_race(string subrace)
{
    return 1;
}

mapping skill_mods(string subrace) {
    return ([ "influence" : 2 ]);
}

int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace)
{
        return 2;
}

mapping daily_uses(string subrace) {
    if(!subrace || subrace == "") return ([]);
}

mapping query_racial_innate(string subrace) {
	if(!subrace || subrace == "") return 0;
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 6, 6, 4, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj() { return ({ 0, 0, 0, 0, 0, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database
string race_name() { return "half-elf"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 7500; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : -2, "int" : -2, "wis" : -5, "dex" : 4, "cha" : 2 ]); }

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
    return 53;
}

int height_mod(string gender) {
    return 16;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 100;
    return 80;
}

int weight_mod(string gender) {
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height){
    mapping map=([]);

    map["num"]  = 3;

    switch(gender)
    {
    case "male":
        map["base"] = 110;
        switch(height)
        {
        case 60..62: map["adjust"] = -18; map["die"] = 18; break;
        case 63..68: map["adjust"] = 0;   map["die"] = 12; break;
        case 69..72: map["adjust"] = 0;   map["die"] = 18; break;
        case 73..75: map["adjust"] = 15;  map["die"] = 20; break;
        default:     map["adjust"] = 0;   map["die"] = 12; break;
        }
    default:
        map["base"] = 85;
        switch(height)
        {
        case 58..60: map["adjust"] = -18; map["die"] = 18; break;
        case 61..66: map["adjust"] = -5;  map["die"] = 12; break;
        case 67..70: map["adjust"] = 0;   map["die"] = 18; break;
        case 71..73: map["adjust"] = 10;  map["die"] = 20; break;
        default:     map["adjust"] = 0;   map["die"] = 12; break;
        }
    }

    return map;
}

string* query_subraces(object who)
{
    return "/std/races/human"->query_subraces(who) + "/std/races/elf"->query_subraces(who);
}

string* query_hair_colors(string subrace)
{
    return distinct_array("/std/races/human"->query_hair_colors(subrace) + "/std/races/elf"->query_hair_colors(subrace));
}

string* query_eye_colors(string subrace)
{
    return distinct_array("/std/races/human"->query_eye_colors(subrace) + "/std/races/elf"->query_eye_colors(subrace));
}

int is_pk_race(string subrace)
{
    if (!subrace || subrace == "") {
        return 0;
    }
    if (subrace == "fey'ri" ||
        subrace == "szarkai") {
        return 1;
    }
}

string *query_languages(string subrace)
{
    return (["required":({"common","elven"}),"optional":({"abyssal","aklo","auran","aquan","beast","celestial","draconic","drow","dwarvish","giant","gnomish","halfling","ignan","infernal","orcish","saurian","tengu","sylvan","terran","undercommon","yuan-ti"})]);
}
