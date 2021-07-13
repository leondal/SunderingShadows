// Bonuses in lib:
// rock gnome; +2 vs illusion spells, see /std/magic/spell; +1BAB vs goblinoids, see /std/living/combat.c
// forest gnome; +2 vs illusion spells, see /std/magic/spell.
// svirfneblin/deep gnome: +2 all saves, see /daemon/saving_throw_d; 10MR, /std/Object.c
#include <std.h>
#include <objects.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() {
      return ({ 60, 100, 150, 200 });
/*    if(!subrace || subrace == "") return ({ 60, 100, 150, 200 });
    switch(subrace) {
      case "forest gnome": return ({ 60, 150, 225, 300 }); break;
      case "svirfneblin": case "deep gnome": return ({ 50, 80, 120, 160 }); break;
      default: return ({ 60, 100, 150, 200 }); break;
    }*/
}

int *restricted_alignments(string subrace) { return ({ 3, 6, 9 }); }

string* restricted_classes(string subrace)
{
    if (!subrace || subrace == "") {
        return ({ "paladin", "ranger", "psion", "psywarrior", "druid", "inquisitor" });
    }
    switch (subrace) {
    case "svirfneblin": case "deep gnome": return ({ "paladin", "psion", "psywarrior", "bard", "druid", "warlock", "inquisitor" }); break;
    case "forest gnome": return ({ "paladin", "psion", "psywarrior", "inquisitor" }); break;
    case "rock gnome": return ({ "paladin", "psion", "psywarrior", "inquisitor" }); break;
    case "trixie": return ({ "paladin", "psion", "psywarrior", "inquisitor" }); break;
    default: return ({ "paladin", "ranger", "psion", "psywarrior", "druid", "inquisitor" }); break;
    }
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    if(!subrace || subrace == "") return ({ "shar","mask","bane","beshaba","cyric","auril","talos" });
    switch(subrace) {
      case "svirfneblin": case "deep gnome": return ({ "shar","bane","beshaba","cyric","auril","talos" }); break;
      default: return ({ "shar","mask","bane","beshaba","cyric","auril","talos" }); break;
    }
}

int* stat_mods(string subrace)   // stats in order: str, dex, con, int, wis, cha
{
    if (!subrace || subrace == "") {
        return ({ -2, 0, 2, 0, 0, 0 });
    }
    switch (subrace) {
    case "svirfneblin": case "deep gnome": return ({ -2, 2, 0, 0, 2, -2 }); break;
    case "trixie":return ({ -2, 2, 0, 2, 0, 0 }); break;
    case "deep gnome": return ({ -2, 2, 0, 0, 2, 0 }); break;
    case "forest": case "forest gnome": return ({ -2, 0, 2, 0, 0, 2 }); break;
    default: return ({ -2, 0, 2, 2, 0, 0 }); break; //rock gnome default
    }
}

mapping skill_mods(string subrace) {
    switch (subrace) {
    case "forest gnome": case "svirfneblin": case "deep gnome": case "trixie":
        return ([ "stealth" : 2 ]);
        break;
    default: //rock gnome default
        return ([ "academics" : 2 ]);
        break;
    }
}

int natural_AC(string subrace) {
    if(!subrace || subrace == "") return 0;
    switch(subrace) {
      case "svirfneblin": case "deep gnome": return 2; break; // in place for +2 dodge bonus to AC
      default: return 0; break;
    }
}

mixed query_racial_innate(string subrace)
{
    if (!subrace || subrace == "") {
        return 0;
    }
    switch (subrace) {
    case "svirfneblin": case "deep gnome":
        return (["blindness" : (["type" : "spell", "casting level" : 0.5,
                                 "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                 "refresh time" : -1, "level required" : 0,
                                 "class specific" : 0]),
                 "displacement" : (["type" : "spell", "casting level" : 0.5,
                                    "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                    "refresh time" : -1, "level required" : 0,
                                    "class specific" : 0]),
                 "misdirection"      : (["type" : "spell", "casting level" : 0.5,
                                         "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                         "refresh time" : -1, "level required" : 0,
                                         "class specific" : 0]),
                 "dancing lights" : (["type" : "spell", "casting level" : 0.5,
                                      "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                      "refresh time" : -1, "level required" : 0,
                                      "class specific" : 0]),
                 "alter self" : (["type" : "spell", "casting level" : 0.5,
                                  "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                  "refresh time" : -1, "level required" : 0,
                                  "class specific" : 0]), ]);
        break;
    case "forest gnome": case "trixie":
        return (["ghost step" : (["type" : "spell", "casting level" : 0.5,
                                  "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                  "refresh time" : -1, "level required" : 0,
                                  "class specific" : 0])]);
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

int sight_bonus(string subrace)
{
    return 3;
}                                             // what to set for svirfneblin?

mapping daily_uses(string subrace) {
    if(!subrace || subrace == "") return ([]);
    switch(subrace) {
      case "forest gnome": return ([ "ghost step" : 1 ]); break;
      case "svirfneblin": case "deep gnome": // please add change-self 1/day to svirfneblin when disguise code is in.
        return ([ "blindness" : 1, "displacement" : 1, "misdirection" : 1, "dancing lights" : 1, "alter self" : 1 ]); break;
      default: return ([]); break;
    }
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 6, 3, 8, 7, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 19, 17, 18 }); }
int *stat_adj() { return ({ 0, 0, 0, 1, -1, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "gnome"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 8000; }

int fingers() { return 4; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : -1, "con" : -1, "int" : 5, "wis" : 5, "dex" : 1, "cha" : -7 ]); }

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
    if(gender == "male") return 36;
    return 34;
}

int height_mod(string gender) {
    return 8;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 40;
    return 35;
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
        case 38..40: map["adjust"] = -10; map["die"] = 6; break;
        case 41..43: map["adjust"] = 0;   map["die"] = 4; break;
        case 44..45: map["adjust"] = 0;   map["die"] = 6; break;
        default:     map["adjust"] = 0;   map["die"] = 4; break;
        }
    default:
        map["base"] = 68;
        switch(height)
        {
        case 36..38: map["adjust"] = -10; map["die"] = 6; break;
        case 39..41: map["adjust"] = 0;   map["die"] = 4; break;
        case 42..43: map["adjust"] = 0;   map["die"] = 6; break;
        default:     map["adjust"] = 0;   map["die"] = 4; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    if(!stringp(subrace) || subrace == "rock gnome") {
        choices += ({"silver", "golden"});
        choices += ({"brown", "blonde", "gray", "white", "bald"});
    }
    if(subrace == "trixie") {
        choices += ({"green", "blue", "pink", "cyan"});
    }
    if(subrace == "forest gnome") {
        choices += ({"ebony"});
        choices += ({"sable"});
        choices += ({"black", "brown"});
    }
    if(subrace == "deep gnome") {
        choices += ({"gray", "white", "bald"});
    }
    return choices;
}

string* query_eye_colors(string subrace)
{
    string* choices = ({});
    if (!stringp(subrace) || subrace == "rock gnome") {
        choices += ({ "violet", "amethyst" });
        choices += ({ "sapphire", "azure" });
        choices += ({ "blue", "gray" });
    }
    if (subrace == "forest gnome" || subrace == "trixie") {
        choices += ({ "sable", "chocolate", "coffee", "emerald", "sapphire" });
        choices += ({ "brown", "hazel", "azure" });
        choices += ({ "green", "blue" });
    }
    if (subrace == "deep gnome") {
        return ({ "black", "gray" });
    }
    return choices;
}

string* query_subraces(object who)
{
    string* subraces;
    subraces = ({ "rock gnome", "forest gnome", "deep gnome", "trixie" });
    // if (OB_ACCOUNT->is_experienced(who->query_true_name()) || avatarp(who) || who->query("is_valid_npc")) {
    //     subraces += ({ "deep gnome", "trixie" });
    // }
    return subraces;
}

string *query_languages(string subrace)
{
    return (["required":({"gnomish","common","undercommon"}),"optional":({"draconic", "dwarvish", "elven", "giant", "goblin", "orcish","sylvan",})]);
}
