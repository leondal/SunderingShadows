// Bonuses in lib: all have +1 to saves vs spells; /std/magic/spell.
#include <std.h>
#include <objects.h>

inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 15, 30, 40, 50 }); }

int *restricted_alignments(string subrace) { return ({ 1, 4, 5, 7 }); }

string *restricted_classes(string subrace) {
  if(!subrace || subrace == "") return ({ "bard",  "paladin", "mage", "magus",  "psion", "psywarrior", "monk", "druid", "warlock" });
  switch(subrace) {
  case "tanarukk": return ({ "bard",  "paladin", "mage", "magus",  "psion", "psywarrior", "monk", "druid","inquisitor" }); break;
     default: return ({ "bard",  "paladin", "mage", "magus",  "psion", "psywarrior", "monk", "druid", "warlock" }); break;
   }
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "anhur","helm","lathander","mielikki","oghma","selune","sune","torm","tymora","tyr" });
}

int *stat_mods(string subrace) { // stats in order: str, dex, con, int, wis, cha
    if(!subrace || subrace == "") return ({ 2, 0, 2, 0, -2, -2 });
    switch(subrace) {
      case "mountain orc": return ({ 4, 0, 0, -2, 2, -2 }); break;
      case "orog" : return ({ 4, -2, 0, 0, -2, 2 }); break;
      case "tanarukk" : return ({ 4, 2, 0, 0, -2, -2 }); break;
      default: return ({ 4, 0, 2, 0, -2, -2 }); break; // gray orc default
    }
}

mapping skill_mods(string subrace) {
    if(!subrace || subrace == "") return ([ "survival" : 2, "endurance" : 2 ]);
    switch(subrace) {
      case "mountain orc": return ([ "survival" : 2, "endurance" : 2 ]); break;
      case "orog": return ([ "craft, armorsmith" : 2, "craft, weaponsmith" : 2 ]); break;
      case "tanarukk": return ([ "endurance" : 2 ]); break;
      default: return ([ "survival" : 2, "endurance" : 2 ]); break; // gray orc default
    }
}

int natural_AC(string subrace) {
    if(!subrace || subrace == "") return 0;
    switch(subrace) {
      case "mountain orc": return 0; break;
      case "orog": return 2; break;
      case "tanarukk": return 2; break;
      default: 0; break;
    }
}

int sight_bonus(string subrace) { return -2; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 6, 3, 8, 3, 3, 3 }); }
int *max_stats() { return ({ 19, 17, 18, 16, 16, 12 }); }
int *stat_adj() { return ({ 1, 0, 0, 0, 0, -2 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "orc"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 6000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 1, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : -2 ]); }

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
    return 24;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 150;
    return 110;
}

int weight_mod(string gender) {
    return 12;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 6;

    switch(gender)
    {
    case "male":
        map["base"] = 130;
        switch(height)
        {
        case 58..60: map["adjust"] = -30; map["die"] = 15; break;
        case 61..67: map["adjust"] = 0;   map["die"] = 10; break;
        case 68..70: map["adjust"] = 0;   map["die"] = 15; break;
        case 71..73: map["adjust"] = 15;  map["die"] = 17; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 90;
        switch(height)
        {
        case 56..58: map["adjust"] = -30; map["die"] = 15; break;
        case 59..65: map["adjust"] = 0;   map["die"] = 10; break;
        case 66..68: map["adjust"] = 0;   map["die"] = 15; break;
        case 69..71: map["adjust"] = 10;  map["die"] = 17; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"black"});
    if(!stringp(subrace) || subrace == "gray orc" || subrace == "tanarukk") {
        choices += ({"gray"});
    }
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"crimson"});
    choices += ({"red"});
    if(!stringp(subrace) || subrace == "gray orc" || subrace == "tanarukk") {
        choices += ({"amber"});
        choices += ({"yellow", "orange"});
    }
    return choices;
}

string *query_subraces(object who) {
    string *subraces;
    subraces = ({"gray orc"});
    if(OB_ACCOUNT->is_experienced(who->query_true_name()) || OB_ACCOUNT->is_high_mortal(who->query_true_name()) || avatarp(who) || who->query("is_valid_npc")) {
        subraces += ({"mountain orc", "orog", "tanarukk"});
    }
    return subraces;
}

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    switch(subrace)
    {
    case "thanarukk":
        return (["required":({"infernal","undercommon"}),"optional":({"drow","goblin","kobold",})]);
        break;
    default:
        return (["required":({"orcish","common"}),"optional":({"drow","goblin","kobold","elven",})]);
        break;
    }
}
