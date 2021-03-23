//         Magic Daemon for ShadowGate MUD
//         Kayla 10/10/94

//  functions:
//    int can_cast(object target, int spell_level, string spell_type);
//  This function returns a true if the target object can cast
//  a spell based on the spell's level, and the type, which is
//  either priest or wizard.  illusionist and mage spells will
//  use type wizard, cleric and druid will use type priest.
//  ex:
//    if(can_cast(this_player(),3,"priest")) {
//      write("Joy! I can cast a level 3 priest spell!");
//    }
//updated by ~Circe~ 7/14/05 to allow for psions
//modding the daemon to accept global spell settings for PrCs. Nienne, 06/10.
#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>
#include <schoolspells.h>
#include <master_limits.h>

#define CQCN spell->query_caster()->query_cap_name()
#define VCASTERS ({"bard", "mage", "psion", "cleric", "ranger", "sorcerer", "paladin", "druid", "psywarrior", "magus"})
inherit DAEMON;

#define MAGIC_D_SAVE "/daemon/save/magic_d"

void index_spells();
mapping allSpells;
mapping domain_spells;
mapping spellIndex;

mapping quick_names;

void create()
{
    ::create();

    seteuid(UID_ROOT);
    restore_object(MAGIC_D_SAVE);
    seteuid(geteuid());

    if (!sizeof(spellIndex)) {
        index_spells();
    }
}

/**
 * For most classes this spell check whether you have spell memorized,
 * sufficient amount of arcana, ki or power points to cast it.
 */
int can_cast(object target, int spell_level, string spell_type, string spell_name, int spell_delay) {
    string myexp;
    int x;
// casting so errors don't show up from other places in lib.
    if (spell_type == "priest") {
        spell_type = "cleric";
    }
    if (spell_type == "wizard") {
        spell_type = "mage";
    }
    if (spell_type == "psionics") {
        spell_type = "psion";
    }

    spell_name = replace_string(spell_name, "_", " ");
    if (!spell_name) {
        return 0;
    }

    // This snippet is to allow certain spells to be cast without being memorized
    {
        string* supreme_healer_spells,
            * raging_healer_spells,
            * natures_gift_spells;

#include <prc_improv_spells.h>

        if (mapp(spellIndex[spell_name])) {
            if (FEATS_D->usable_feat(target, "supreme healer") && member_array(spell_name, supreme_healer_spells) != -1) {
                return 1;
            }
            if (FEATS_D->usable_feat(target, "natures gift") && member_array(spell_name, MAGIC_SS_D->query_class_special_spells("archdruid", "all")) != -1) {
                return 1;
            }
            if (FEATS_D->usable_feat(target, "raging healer") && member_array(spell_name, raging_healer_spells) != -1) {
                return 1;
            }
            if (FEATS_D->usable_feat(target, "inspired necromancy") && spell_level < 7 && spellIndex[spell_name]["sphere"] == "necromancy") {
                return 1;
            }
        }
    }


    if (FEATS_D->usable_feat(target, "expanded knowledge 1")) {
        myexp = target->query("expanded_knowledge_1");
        if (spell_name == myexp) {
            return 1;
        }
    }
    if (FEATS_D->usable_feat(target, "expanded knowledge 2")) {
        myexp = target->query("expanded_knowledge_2");
        if (spell_name == myexp) {
            return 1;
        }
    }
    if (FEATS_D->usable_feat(target, "expanded knowledge 3")) {
        myexp = target->query("expanded_knowledge_3");
        if (spell_name == myexp) {
            return 1;
        }
    }
    if (FEATS_D->usable_feat(target, "body cognition") || FEATS_D->usable_feat(target, "mind over matter")) {
        if (spell_name == "true metabolism") {
            return 1;
        }
    }
    if (FEATS_D->usable_feat(target, "presence of mind") || FEATS_D->usable_feat(target, "mental fortress")) {
        if (spell_name == "timeless body") {
            return 1;
        }
    }

    if (!target->query_memorized(spell_type, spell_name)) {
        if (!(spell_type == "magus" && target->query_property("spell recall"))) {
            return 0;
        }
    }

    x = target->query_guild_level(spell_type);
    if (x < 1) {
        return 0;
    }

    //Checking if discipline spells could actually be mastered and cast at current level
    if(spell_type == "psion" && spell_level > to_int(ceil(to_float(target->query_prestige_level("psion")) / 2.00)))
        return 0;

    if (spell_type == "monk") {
        if (x >= spell_level) {
            return 1;
        } else {
            return 0;
        }
    }
    return 1;
}

string *query_opposite_sphere(string str) {
    return SCHOOL_OPPOSITION[str];
}

string *query_mastering_classes() {
    return ({ "bard", "sorcerer", "inquisitor", "oracle", "psion", "psywarrior", "magus" });
}

int is_mastering_class(string str) {
    return member_array(str, query_mastering_classes()) > -1;
}

int query_spell_cost(int x, string player_sphere, string spell_sphere) {
    mixed* ret;
    int i;
    if (player_sphere == "monster sphere") {
        return x;
    }
    if (x == 0) {
        return -1;
    }
    if (player_sphere == spell_sphere) {
        return x / 2;
    }
    ret = query_opposite_sphere(player_sphere);
    for (i = 0; i < sizeof(ret); i++) {
        if (ret[i] == spell_sphere) {
            return x * 2;
        }
    }
    return x;
}

int cast_spell(string spell_name, object caster, string target, int ob_level) {
    string spell_file;

    seteuid(getuid());
    if (!file_exists(spell_file = "/cmds/spells/" + spell_name[0..0] + "/_" + replace_string(spell_name, " ", "_") + ".c")) {
        return 0;
    }
    new(spell_file)->use_spell(caster, target, ob_level);
    return 1;
}

string query_title(object magi) {
    if ((string)magi->query_class() == "bard") {
        return "bard";
    }
    switch (magi->query_sphere()) {
    case "invocation_evocation":
        return "invoker";
    case "conjuration_summoning":
        if ((string)magi->query_gender() == "female") {
            return "conjuress";
        }
        return "conjurer";
    case "alteration":
        return "transmuter";
    case "necromancy":
        return "necromancer";
    case "greater divination":
        if ((string)magi->query_gender() == "female") {
            return "diviness";
        }
        return "diviner";
    case "abjuration":
        if ((string)magi->query_gender() == "female") {
            return "abjuress";
        }
        return "abjurer";
    case "enchantment_charm":
        if ((string)magi->query_gender() == "female") {
            return "enchantress";
        }
        return "enchanter";
    case "illusion":
        return "illusionist";
    default:
        return "mage";
    }
}

object get_spell_from_array(object* spellary, string spellname)
{
    int i;

    for (i = 0; i < sizeof(spellary); i++) {
        if (!objectp(spellary[i])) {
            continue;
        }
        if ((string)spellary[i]->query_spell_name() == spellname) {
            return spellary[i];
        }
    }
}

/**
 * Adds all spells to allSpells property. class:spells:level mapping
 */
void index_spells()
{
    string key, tclass;

    build_index();

    allSpells = ([]);

    foreach(key in keys(spellIndex))
    {
        if (!sizeof(spellIndex[key]["levels"])) {
            continue;
        }

        foreach(tclass in keys(spellIndex[key]["levels"]))
        {
            if (!mapp(allSpells[tclass])) {
                allSpells[tclass] = ([]);
            }
            allSpells[tclass] += ([key:spellIndex[key]["levels"][tclass]]);
        }
    }

    seteuid(UID_ROOT);
    save_object(MAGIC_D_SAVE);
    seteuid(geteuid());

}

/**
 * Adds all spells to spellIndex property. spell:spelltable mapping;
 * spelltable contains at least levels map
 */
void build_index()
{
    string* all_spells, str2, * dirset;
    int x, i;
    mapping level, spelltable;

    spellIndex = ([]);
    domain_spells = ([]);

    quick_names = ([]);

    dirset = get_dir(DIR_SPELLS + "/");
    if (sizeof(dirset)) {
        for (i = 0; i < sizeof(dirset); i++) {
            if (file_size(DIR_SPELLS + "/" + dirset[i]) == -2) {
                all_spells = get_dir(DIR_SPELLS + "/" + dirset[i] + "/_*.c");
                for (x = 0; x < sizeof(all_spells); x++) {
                    all_spells[x] = replace_string(all_spells[x], "_", "", 1);
                    all_spells[x] = replace_string(all_spells[x], ".c", "", 1);
                    all_spells[x] = replace_string(all_spells[x], "_", " ");
                    str2 = DIR_SPELLS + "/" + dirset[i] + "/_" + replace_string(all_spells[x], " ", "_") + ".c";
                    if (file_exists(str2)) {
                        if (catch(level = str2->query_spell_level_map())) {
                            continue;
                        }
                        if (!mapp(level)) {
                            continue;
                        }
                        spelltable = ([]);

                        spelltable["quick"] = add_quick_name(all_spells[x]);
                        spelltable["levels"] = level;
                        spelltable["sphere"] = str2->query_spell_sphere(); //aka school
                        spelltable["way"] = str2->query_monk_way();
                        spelltable["discipline"] = str2->query_discipline();
                        spelltable["feats"] = str2->query_feats_required();
                        if(sizeof(str2->query_domains()))
                        {                          
                            spelltable["divine_domain"] = str2->query_domains();
                            domain_spells += ([ all_spells[x] : spelltable ]);
                        }
                        spellIndex += ([ all_spells[x] : spelltable]);
                    }
                }
            }
        }
    }
    return 1;
}

/**
 * Returns some of the spell properties
 */
mapping query_index_row(string spell)
{
    return spellIndex[spell];
}

/**
 * Filters spellist based on player class and feats and returns it.
 */
mapping index_castable_spells(object player, string myclass)
{
    mapping all_spells, tmp;
    string* all_spell_names, spellfile, featneeded, domain, pclass;
    int lvl;
    string playerdisc = player->query_discipline();
    string playerway = player->query("monk way");
    string classfile;

    // Pseudoclass for classes that use other classes spell lists, such as sorcerers.
    // Myclass -- player's real class.
    pclass = myclass;
    if (myclass == "sorcerer") {
        pclass = "mage";
    } 

    if (myclass == "oracle") {
        pclass = "cleric";
    }

    all_spells = query_index(pclass);

    if (!sizeof(all_spells)) {
        return ([]);
    }

    all_spell_names = keys(all_spells);
    all_spell_names = keys(spellIndex);
    all_spells = ([]);
    tmp = ([]);

    foreach(spellfile in all_spell_names)
    {
        if (!(lvl = spellIndex[spellfile]["levels"][pclass])) {
            continue;
        }

        featneeded = spellIndex[spellfile]["feats"][pclass];
        if (featneeded != "me" && stringp(featneeded) && !FEATS_D->usable_feat(player, featneeded)) {
            continue;
        }

        if (pclass == "psion") {
            domain = spellIndex[spellfile]["discipline"];
            if (domain &&
                domain != "me" &&
                domain != playerdisc) {
                continue;
            }
        }
        
        if(pclass == "cleric" || pclass == "druid")
        {   
            int success = 0;
            int exclude = 0;
            
            domain = spellIndex[spellfile]["divine_domain"];
            
            if(sizeof(domain))
            {
                foreach(string str in domain)
                {
                    if(member_array(str, player->query_divine_domain()) >= 0)
                        success++;
                    
                    if(pclass == "druid")
                    {
                        if(str == "sun" || str == "cold" || str == "knowledge")
                            success++;
                    }
                }
                
                if(!success)
                    continue;
            }
        }
        
        /*
        if(pclass == "druid")
        {   
            int success = 0;
            
            domain = spellIndex[spellfile]["divine_domain"];
            
            if(sizeof(domain))
            {
                foreach(string str in domain)
                {
                    if(member_array(str, player->query_divine_domain()) >= 0)
                        success++;
                }
                
                if(!success)
                    continue;
            }
        }
        */
        
            
        if (pclass == "monk" &&
            !FEATS_D->usable_feat(player, "grandmaster of the way")) {
            domain = spellIndex[spellfile]["way"];
            if (domain &&
                domain != "" &&
                domain != playerway) {
                continue;
            }
        }
        
        tmp[spellfile] = lvl;
    }
    return tmp;
}

/**
 * Filters index by unrestricted spells only, spells one can master.
 */
mapping index_masterable_spells(object player, string myclass)
{
    
    mapping all_spells, tmp;
    string* all_spell_names, spellfile, featneeded, domain, pclass;
    int lvl;
    
    {
    return index_castable_spells(player, myclass);
    }
    
    /*
    pclass = myclass;
    if (pclass == "sorcerer") {
        pclass = "mage";
    }
    if (pclass == "oracle") {
        pclass = "cleric";
    }

    all_spells = query_index(pclass);
    if (!sizeof(all_spells)) {
        return ([]);
    }

    all_spell_names = keys(all_spells);
    all_spell_names = keys(spellIndex);
    all_spells = ([]);
    tmp = ([]);

    foreach(spellfile in all_spell_names)
    {
        if (!(lvl = spellIndex[spellfile]["levels"][pclass])) {
            continue;
        }

        featneeded = spellIndex[spellfile]["feats"][pclass];
        if (featneeded != "me" && stringp(featneeded) && !FEATS_D->usable_feat(player, featneeded)) {
            continue;
        }

        if (pclass == "psion") {
            domain = spellIndex[spellfile]["discipline"];
            if (domain &&
                domain != "me") {
                continue;
            }
        }

        tmp[spellfile] = lvl;;
    }
    return tmp;
    
    */
}

/**
 * level:spells mapping for monks
 *
 * This is compatibility function for old way of defining monk spells
 * in monk.h
 */
mapping index_ki_spells_by_level(object player)
{
    mapping tmp = ([]);
    mapping sindex = index_castable_spells(player, "monk");
    string key;
    foreach(key in keys(sindex))
    {
        if (!pointerp(tmp[sindex[key]])) {
            tmp += ([sindex[key] : ({})]);
        }
        tmp[sindex[key]] += ({ key });
    }
    return tmp;
}

/**
 * Returns random spell from the db, available filters are level (except for monk levels) and class.
 *
 * @param myclass class to choose spell from. Optional. If not chosen selects random class
 * @param lev level to choose spell from, between 1 and 9. Optional. If not chosen selects random level
 * @return random spell row
 */
mixed query_random_spell(string myclass, int lev)
{
    string cspell, * rspell;
    int x;
    if (!myclass) {
        myclass = "random";
    }
    if (!lev || lev < -1 || lev > 9) {
        lev = -1;
    }
    if (member_array(myclass, keys(allSpells)) == -1 && myclass != "random") {
        myclass = "random";
    }
    if (myclass == "random") {
        myclass = keys(allSpells)[random(sizeof(keys(allSpells)))];
    }
    if (myclass == "sorcerer") {
        myclass = "mage";
    }
    if (myclass == "oracle") {
        myclass = "cleric";
    }
    if (lev < 0) {
        return keys(allSpells[myclass])[random(sizeof(keys(allSpells[myclass])))];
    }
    switch (myclass) {
    case "ranger": case "paladin":
        if (lev > 4) {
            lev = 4;
        }
    case "bard": case "psywarrior": case "inquisitor": case "magus":
        if (lev > 6) {
            lev = 6;
        }
    default:
        if (lev > 9) {
            lev = 9;
        }
    }
    rspell = ({});
    for (x = 0; x < sizeof(keys(allSpells[myclass])); x++) {
        cspell = keys(allSpells[myclass])[x];
        if (allSpells[myclass][cspell] == lev) {
            rspell += ({ cspell });
        }
        continue;
    }
    if (!pointerp(rspell) || !sizeof(rspell)) {
        return keys(allSpells[myclass])[random(sizeof(keys(allSpells[myclass])))];
    }
    return rspell[random(sizeof(rspell))];
}


mixed* query_index(string myclass)
{
    string theclass = myclass;
    if (theclass == "sorcerer") {
        theclass = "mage";
    }
    if (theclass == "oracle") {
        theclass = "cleric";
    }
    return allSpells[theclass];
}

mapping *query_global_index()
{
    return spellIndex;
}

mapping *filter_global_index(function filter)
{
    return filter_mapping(spellIndex,filter);
}

int query_spell_level(string myclass, string spell)
{
    if (myclass == "sorcerer") {
        myclass = "mage";
    }
    if (myclass == "oracle") {
        myclass = "cleric";
    }
    if (!allSpells[myclass]) {
        return 0;
    }
    if (!allSpells[myclass][spell]) {
        return 0;
    }
    return allSpells[myclass][spell];
}

void fizzile(object spell){
    switch(random(10)){
    case 0:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^As you weave your hands, you feel the magic fizzle and disperse");
        tell_room(spell->query_place(),"%^BOLD%^%^YELLOW%^As "+CQCN+" weaves "+spell->query_caster()->query_possessive()+" hands, you feel the magic in the air fizzle and disperse.");
        return;
    case 1:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^Magic start to grow about you, then suddenly with a sizzle and a pop, the magic releases without focus.");
        tell_room(spell->query_place(),"%^BOLD%^%^YELLOW%^You feel magic grow about "+CQCN+", then suddenly with a s sizzle and a pop, the magic is released without any focus.");
        spell->query_caster()->force_me("emote winces");
        spell->query_caster()->do_damage("torso",random(5)+1);
        return;
    case 2:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^Magic starts to eminate forth from you, but instead of the expected results, a lovely rainbow of colors fills the room.");
        spell->query_caster()->force_me("emote looks perplexed.");
        tell_room(spell->query_place(),"%^BOLD%^%^YELLOW%^You see magic start to eminate from"+CQCN+"'s hands, a beautiful rainbow of colors fills the room.");
        return;
    case 3:
        tell_object(spell->query_caster(),"%^BOLD%^%^RED%^You realize the spell failed miserably, your just not sure what the result was.");

        tell_room(spell->query_place(),"%^BOLD%^%^RED%^POP.");
        return;
    case 4:
        tell_object(spell->query_caster(),"%^BOLD%^%^RED%^Your hands become really relly warm... hotter ... oh shit.");
        spell->query_caster()->force_me("emote dances around blowing on "+spell->query_caster()->query_possessive()+" fingers");
        return;
    case 5:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^A shower of sparks starts to fall from the sky as you finish the spell.");
        tell_room(spell->query_place(),"%^BOLD%^%^YELLOW%^As "+CQCN+" finished the spell, a shower of sparks float harmlessly to the ground..");
        return;
    case 6:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^As you mumble the magic words, your mind suddenly goes blank, and you have no idea what you were doing.");
        spell->query_caster()->force_me("emote looks about confused, sort of lost.");
        return;
    case 7:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^The magic starts to condense and you begin to manipulate it to your ends.");
        spell->query_caster()->force_me("cough");
        spell->query_caster()->force_me("swear");
        return;
    case 8:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^You said the words correctly, you waved the hands in the right pattern, but still nothing happens.");
        tell_room(spell->query_place(),"%^BOLD%^%^YELLOW%^"+CQCN+" seems to finish a spell, but absolutely nothing happens.");
        return;
    case 9:
        tell_object(spell->query_caster(),"%^BOLD%^%^YELLOW%^The magic overwelms you and stuns your mind as you loose control.");
        tell_room(spell->query_place(),"%^BOLD%^%^YELLOW%^As "+CQCN+" weaves "+spell->query_caster()->query_possessive()+" spell, "+spell->query_caster()->query_subjective()+" suddenly passes out.");
        spell->query_caster()->set_unconscious(2);
        return;
    }

}

void do_kill(object spell)
{
    object caster;
    if(!objectp(spell)) return;
    caster = spell->query_caster();
    if(!objectp(caster)) return;

    caster->do_damage("torso",caster->query_hp()+100);
    caster->add_attacker(spell);
    caster->continue_attack();
    caster->remove_attacker(spell);
}

int is_spell(){
    return 1;
}

void spell_failure(object spell, int prof){

    int difference;

    difference = random(100+prof) - 100;
    tell_object(spell->query_caster(),"prof = "+prof+" difference = "+difference);
    //-30 -> 99
    if(spell->do_failure(difference)) {
        return;
    }

    switch(difference) {
    case -30..-25:
        do_kill(spell);
        break;
    case -24..24:
        spell->reverse_spell();
        break;
    case 25..74:
        fizzile(spell);
        break;
    case 75..99:
        spell->spell_effect(prof);
    }
}

string add_quick_name(string spell_name)
{
    string orig, *origs;
    string final = "";
    int i = 0, j = 1;

    if (!stringp(spell_name)) {
        return "";
    }

    if (!sizeof(spell_name)) {
        return "";
    }

    orig = replace_string(spell_name, " ", "");
    origs = explode(spell_name, " ");

    do {
        final += orig[i..i];
        i++;
        if (sizeof(origs) > j) {
            orig = origs[j];
            j++;
            i = 0;
        }
    } while (i < sizeof(orig) && member_array(final, keys(quick_names)) != -1);

    quick_names[final] = spell_name;
    return final;
}

string expand_quick_name(string quick_name)
{
    if (!stringp(quick_names[quick_name])) {
        return quick_name;
    } else {
        return quick_names[quick_name];
    }
}

/**
 * Cleans quick names. You'll need to regenerate index with
 * index_spells() to generate new set. Use this for debug only.
 */
void clean_quick_names()
{
    quick_names = ([]);
}

//special function for the way of the elements monk feat
//elemental opportunist - Saide, December 2016
void elemental_opportunist(object caster, object target)
{
    int max;
    object EO;
    if(!objectp(caster)) return;
    if(!FEATS_D->usable_feat(caster, "elemental opportunist")) return;
    max = (int)caster->query_class_level("monk");
    if(!max) return;
    if(roll_dice(1, 100) > (max+random(20))) return;
    max = (max / 5) + 1;
    if(objectp(EO = present("monkeledevice99x", caster)))
    {
        if((int)EO->query_my_guardians() < max)
        {
            EO->add_guardian();
            return;
        }
        return;
    }
    else
    {
        EO = new("/d/magic/obj/monkeledevice");
        EO->set_caster(caster);
        EO->move(caster);
        EO->add_guardian();
        return;
    }
    return;
}

/**
 * Converts spell filename to spell name
 */
string spell_file_to_spell_name(string spellfile)
{
    spellfile = replace_string(spellfile,"_","",1);
    spellfile = replace_string(spellfile,".c","",1);
    spellfile = replace_string(spellfile,"_"," ");
    return spellfile;
}

/**
 * Converts spell name to corresponding spell file
 */
string get_spell_file_name(string spell)
{
	if(!spell) return "";
	spell = DIR_SPELLS + "/"+ explode(spell, "")[0] + "/_" + replace_string(spell, " ", "_") + ".c";
	if(!file_exists(spell)) return "";
	return spell;
}
