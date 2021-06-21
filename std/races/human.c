// Bonuses in lib:
// genasi: +1 to caster level, /std/Object.c; all planetouched: 10MR, /std/Object.c
// all the rest of planetouched details are in this file. Human ethnicities as follows:
// all non-planetouched humans; +4 skills at L1, see /std/skills.c
// PLEASE NOTE in setting ethnicities to players, that spelling including ' and no caps is integral.

// heartlander: +1 influence (here), +1 saves vs spells (spell.c)
// zin'charu: +1 spellcraft (here), det magic x3 (here)
// aesatri: +1 fort (saving_throw_d), +1 dodge bonus to ac (here)
// attayan: +1 academics (here), immune to fear (/cmds/spells/fear; other IC applications?)
// tsarven: +1 stealth/percept in urban (skills.c), +1 init (combat.c)
// morinnen: +1 survival (here), +1 BAB when mounted (combat.c)
// tonaz'tlacar: +1 stealth/percept in wilderness (skills.c), +10 hp (/adm/daemon/advance_d)
// senzokuan: +1 reflex (saving_throw_d), +1 L1 spell slot (spellcaster.c & /cmds/mortal/_recall)
// maalish: +1 will (saving_throw_d), +5 SR (Object.c)

#include <std.h>
#include <objects.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 45, 60, 90 }); }

int *restricted_alignments(string subrace) {
    return ({});
}

string *restricted_classes(string subrace) {
    switch(subrace) {
      case "tiefling": return ({ "druid" });
      case "aasimar": return ({ "druid" });
      case "dhampir": return ({ "druid" });
      case "air genasi": case "earth genasi": case "fire genasi": case "water genasi":  return ({ "warlock" });
    }
    return ({});
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) { return ({}); }

int *stat_mods(string subrace) { // stats in order: str, dex, con, int, wis, cha
    if(!subrace || subrace == "") return ({ 0, 0, 2, 0, 0, 0 }); //temporary until +2 stat of choice is written
    switch(subrace) {
      case "aasimar": return ({ 0, 0, 0, -2, 2, 2 }); break;
      case "air genasi": return ({ 0, 2, 0, 2, 0, -2 }); break;
      case "earth genasi": return ({ 2, 0, 2, 0, 0, -2 }); break;
      case "feytouched": return ({ 0, 2, -2, 0, 0, 2 }); break;
      case "fire genasi": return ({ 0, 0, 0, 2, 2, -2 }); break;
      case "tiefling": return ({ 0, 2, 0, 2, 0, -2 }); break;
      case "water genasi": return ({ 0, 0, 2, 0, 2, -2 }); break;
      case "dhampir": return ({ 0, 2, -2, 0, 0, 2 }); break;
      default: return ({ 0, 0, 0, 0, 0, 0 }); break;
    }
}

int is_statmod_race(string subrace)
{
    if (member_array(subrace, ({ "heartlander", "zin'charu", "aesatri", "attayan", "tsarven", "morinnen", "tonaz'tlacar", "senzokuan", "maalish" })) == -1) {
        return 0;
    }
    return 1;
}

int is_pk_race(string subrace)
{
    if (!subrace || subrace == "") {
        return 0;
    }
    if (subrace == "dhampir") {
        return 1;
    }
}

mapping skill_mods(string subrace) {
    if(!subrace || subrace == "") return ([]);
    switch(subrace) {
      case "tiefling": return ([ "stealth" : 2, "influence" : 2 ]); break;
      case "aasimar": return ([ "perception" : 2, "influence" : 2 ]); break;
      case "feytouched": return ([ "perception" : 2, "influence" : 2 ]); break;
      case "dhampir": return ([ "perception" : 2, "influence" : 2 ]); break;
      case "heartlander": return ([ "influence" : 1 ]); break;
      case "zin'charu": case "zincharu": return ([ "spellcraft" : 1 ]); break;
      case "attayan": return ([ "academics" : 1]); break;
      case "morinnen": return ([ "survival" : 1]); break;
      default: return ([]); break;
    }
}

int natural_AC(string subrace) {
    if(!subrace || subrace == "") return 0;
    switch(subrace) {
      case "aesatri": return 1; break; // in place for +1 dodge bonus to AC
      default: return 0; break;
    }
}

int sight_bonus(string subrace) {
    if(!subrace || subrace == "") return 0;
    if(subrace == "tiefling" ||
       subrace == "aasimar" ||
       subrace == "air genasi" ||
       subrace == "earth genasi" ||
       subrace == "dhampir" ||
       subrace == "fire genasi" ||
       subrace == "water genasi" ||
       subrace == "feytouched")
        return 2;
    return 0;
}

mapping daily_uses(string subrace) {
    if(!subrace || subrace == "") return ([]);
    switch(subrace) {
      case "aasimar": return ([ "light" : 1 ]); break;
      case "air genasi": return ([ "levitate" : 1 ]); break;
      case "earth genasi": return ([ "ghost step" : 1 ]); break;
      case "fire genasi": return ([ "produce flame" : 1 ]); break;
      case "feytouched": return ([ "faerie fire" : 1 ]); break;
      case "tiefling": return ([ "darkness" : 1 ]); break;
      case "water genasi": return ([ "water breathing" : 1 ]); break;
      case "zin'charu": case "zincharu": return ([ "detect magic" : 3 ]); break;
      default: return ([]); break;
    }
}

mapping query_racial_innate(string subrace)
{
	if(!subrace || subrace == "") return 0;
	switch(subrace)
	{
		case "tiefling":
				return (["darkness" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "aasimar":
				return (["light" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "feytouched":
				return (["faerie fire" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
        case "dhampir":
                return ([
                        "invisibility" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
                         "darkvision" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
                         "gaseous form" : (["type" : "spell", "daily uses" : -1, "level required" : 0,]),
                        ]);
                        ;
               break;
		case "air genasi":
                                return (["levitate" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "earth genasi":
				return (["ghost step" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "fire genasi":
				return (["produce flame" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "water genasi":
				return (["water breathing" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "zin'charu": case "zincharu":
				return (["detect magic" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 3, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		default:
			return 0;
			break;
	}
	return 0;
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 3, 3, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj()  { return ({ 0, 0, 0, 0, 0, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "human"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 9999; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : 0 ]); }

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
int weight_base(string gender)
{
    if (gender == "male") {
        return 120;
    }
    return 85;
}

int weight_mod(string gender)
{
    return 30;
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
        case 55..60: map["adjust"] = -10; map["die"] = 14; break;
        case 61..69: map["adjust"] = -5;  map["die"] = 10; break;
        case 70..75: map["adjust"] = 0;   map["die"] = 15; break;
        case 76..81: map["adjust"] = 15;  map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    if(!stringp(subrace) ||
       member_array(subrace,({"aasimar", "feytouched","tiefling","air genasi","earth genasi","fire genasi","water genasi","heartlander"})) != -1) {
        choices += ({"ebony", "golden", "silver"});
        choices += ({"sable", "auburn", "scarlet", "crimson"});
        choices += ({"black", "brown", "blonde", "red", "white", "gray", "bald"});
    }
    else if(subrace == "air genasi") { // extras for specific planetouched subtypes
        choices += ({ "light blue" });
    }
    else if(subrace == "water genasi") { // extras for specific planetouched subtypes
        choices += ({ "blue-green" });
        choices += ({ "green" });
    }
    else if(subrace == "senzokuan" || subrace == "maalish" || subrace == "zin'charu" || subrace == "tonaz'tlacar") {
        choices += ({"ebony"});
        choices += ({"sable"});
        choices += ({"black", "brown", "white", "gray", "bald"});
    }
    else if(subrace == "aesatri") {
        choices += ({"golden", "silver"});
        choices += ({"auburn", "scarlet", "crimson"});
        choices += ({"blonde", "red", "white", "gray", "bald"});
    }
    else {
        choices += ({"ebony"});
        choices += ({"sable", "auburn", "scarlet", "crimson"});
        choices += ({"black", "brown", "red", "white", "gray", "bald"});
    }
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    if(!stringp(subrace) ||
       member_array(subrace,({"aasimar","feytouched","tiefling","air genasi","earth genasi","fire genasi","water genasi","heartlander","attayan"})) != -1) {
        choices += ({"violet", "purple", "silver"});
        choices += ({"emerald", "sapphire", "yellow", "amber"});
        choices += ({"azure", "cyan", "sable", "chocolate", "coffee"});
        choices += ({"green", "hazel"});
        choices += ({"brown", "blue", "gray"});
    }
    else if(subrace == "water genasi") { // extras for specific planetouched subtypes
        choices += ({ "aquamarine" });
        choices += ({ "blue-green" });
    }
    else if(subrace == "earth genasi") { // extras for specific planetouched subtypes
        choices += ({ "black" });
    }
    else if(subrace == "tiefling") { // extras for specific planetouched subtypes
        choices += ({ "red" });
    }
    else if(subrace == "aasimar" ||
       subrace == "feytouched") { // extras for specific planetouched subtypes
        choices += ({ "golden" });
        choices += ({ "topaz" });
    }
    else if(subrace == "tonaz'tlacar") {
        choices += ({"silver"});
        choices += ({"emerald", "yellow", "amber"});
        choices += ({"sable", "chocolate", "coffee"});
        choices += ({"green", "hazel"});
        choices += ({"brown", "gray"});
    }
    else if(subrace == "aesatri" || subrace == "zin'charu") {
        choices += ({"violet", "purple", "silver"});
        choices += ({"emerald", "sapphire"});
        choices += ({"azure", "cyan"});
        choices += ({"green"});
        choices += ({"blue", "gray"});
    }
    else {
        choices += ({"yellow", "amber"});
        choices += ({"sable", "chocolate", "coffee"});
        choices += ({"hazel"});
        choices += ({"brown", "gray"});
    }
    return choices;
}

string* query_subraces(object who)
{
    string* subraces;
    subraces = ({ "heartlander", "zin'charu", "aesatri", "attayan", "tsarven", "morinnen", "tonaz'tlacar", "senzokuan", "maalish", "aasimar", "feytouched", "tiefling", "air genasi", "fire genasi", "water genasi", "earth genasi" });
    if (OB_ACCOUNT->is_experienced(who->query_true_name()) ||
        OB_ACCOUNT->is_high_mortal(who->query_true_name()) ||
        avatarp(who) ||
        who->query("is_valid_npc")) {
        subraces += ({ "dhampir" });
        //subraces += ({ "tiefling", "aasimar", "feytouched", "air genasi", "earth genasi", "fire genasi", "water genasi", "dhampir" });
    }
    return subraces;
}

string *query_languages(string subrace)
{
    if (subrace == "feytouched") {
        return (["required":({"common","aklo"}),
                 "optional":({"abyssal","auran","aquan","beast","celestial","draconic","drow","dwarvish","elven","giant","gnomish","halfling","ignan","infernal","orcish","saurian","tengu","sylvan","terran","undercommon","yuan-ti"})]);
    }

    if (subrace == "aasimar") {
        return (["required":({"common","celestial"}),
                 "optional":({"abyssal","aklo","auran","aquan","beast","draconic","drow","dwarvish","elven","giant","gnomish","halfling","ignan","infernal","orcish","saurian","tengu","sylvan","terran","undercommon","yuan-ti"})]);
    }

    if (subrace == "tiefing") {
        return (["required":({"common","abyssal","infernal"}),
                 "optional":({"aklo","auran","aquan","beast","celestial","draconic","drow","dwarvish","elven","giant","gnomish","halfling","ignan","orcish","saurian","tengu","sylvan","terran","undercommon","yuan-ti"})]);
    }

    if (subrace == "air genasi") {
        return (["required":({"common","auran"}),
                 "optional":({"abyssal","aklo","aquan","beast","celestial","draconic","drow","dwarvish","elven","giant","gnomish","halfling","ignan","infernal","orcish","saurian","tengu","sylvan","terran","undercommon","yuan-ti"})]);
    }

    if (subrace == "earth genasi") {
        return (["required":({"common","terran"}),
                 "optional":({"abyssal","aklo","auran","aquan","beast","celestial","draconic","drow","dwarvish","elven","giant","gnomish","halfling","ignan","infernal","orcish","saurian","tengu","sylvan","undercommon","yuan-ti"})]);
    }

    if (subrace == "fire genasi") {
        return (["required":({"common","ignan"}),
                 "optional":({"abyssal","aklo","auran","aquan","beast","celestial","draconic","drow","dwarvish","elven","giant","gnomish","halfling","infernal","orcish","saurian","tengu","terran","sylvan","undercommon","yuan-ti"})]);
    }

    if (subrace == "water genasi") {
        return (["required":({"common","aquan"}),
                 "optional":({"abyssal","aklo","auran","beast","celestial","draconic","drow","dwarvish","elven","giant","gnomish","halfling","ignan","infernal","orcish","saurian","tengu","terran","sylvan","undercommon","yuan-ti"})]);
    }

    return (["required":({"common",}),
             "optional":({"abyssal","aklo","auran","aquan","beast","celestial","draconic","drow","dwarvish","elven","giant","gnomish","halfling","ignan","infernal","orcish","saurian","sylvan","terran","undercommon","yuan-ti"})]);
}
