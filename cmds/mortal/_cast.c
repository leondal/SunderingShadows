//     Casts spells
//     Written by Kayla@Shadowgate
//     Added a check for scrambling to keep people from casting while scrambling 11/20/04 -Tsera
//     Converting to global spell command. Nienne, 05/10.
// Updated to use power points for psychic characters by ~Circe~ 9/17/15
#include <std.h>
#include <daemons.h>
#include <schoolspells.h>
#include <spell_domains.h>

inherit DAEMON;

#include <cleric_spells.h>

void help();

int light_armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_armor_prof() == "light") {
        return 0;
    }
    return 1;
}

int armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_armor_prof() == "light" || ob->query_armor_prof() == "medium" || ob->query_armor_prof() == "heavy") {
        return 1;
    }
    return 0;
}

int cmd_cast(string str)
{
    object targ, * armor, * wielded;
    int i, j, align, healharm, schoolspell, mylvl, * mapkeys, domain, slevel, maguslvl;
    string str2, tmp, type, spell, tar, * known, myschool, myexp, myexp1, myexp2, myexp3, domain_name;
    mapping mymapp = ([]), mymapp2 = ([]);

    seteuid(getuid());
    if (!str) {
        write("Cast what on/at what?");
        return 1;
    }
    type = "none";

    if (TP->query_casting() && objectp(TP->query_property("spell_casting"))) {
        return notify_fail("You are already doing something!\n");
    }

    if (TP->query_property("using instant feat")) {
        return notify_fail("You are already doing something!\n");
    }

    // clerical checks for spontaneous healing/harming casts
    if (strsrch(str, "as healing") != -1) {
        healharm = 1;
        str = replace_string(str, "as healing", "", 1);
    } else if (strsrch(str, "as harming") != -1) {
        healharm = -1;
        str = replace_string(str, "as harming", "", 1);
    } else {
        healharm = 0;
    }

    if (regexp(str, implode(PLAYER_D->list_classes(), "|") + "|innate|cantrip")) {
        if (!sscanf(str, "%s %s", type, str2)) {
            return notify_fail("Syntax: <cast CLASS CAST_STRING>\n");
        }
    }else {
        type = TP->query_class();
        str2 = str;
    }

    if (!sscanf(str2, "%s on %s", str2, tar)) {
        if (!sscanf(str2, "%s at %s", str2, tar)) {
            if (!sscanf(str2, "%s to %s", str2, tar)) {
                if (!sscanf(str2, "%s as %s", str2, tar)) {
                    tar = 0;
                }
            }
        }
    }

    if (!TP->is_class(type) && !avatarp(TP) && type != "innate" && type != "cantrip") {
        return notify_fail("You can't cast spells as a " + type + "!\n");
    }

    align = TP->query_true_align();
    if (healharm || domain) {
        if (!(type == "cleric" ||
              type == "druid")) {
            write("Only certain classes can cast spells as domain or healing magic.");
            return 1;
        }
        if ((align % 3 == 1 && healharm < 0) || (align % 3 == 0 && healharm > 0)) {
            write("Your alignment does not allow you to do that!");
            return 1;
        }
        str2 = replace_string(str2, "  ", " ", 1);
        if (str2[0] == ' ') {
            str2 = replace_string(str2, " ", "", 1);
        }
        if (str2[strlen(str2) - 1] == ' ') {
            str2 = arrange_string(str2, strlen(str2) - 1);
        }
    }

    if (domain) {
        if (member_array(domain_name, TP->query_divine_domain()) == -1) {
            write("You don't have a " + domain_name + " domain.");
            return 1;
        }
    }

    if (type == "bard" ||
        type == "sorcerer" ||
        type == "inquisitor" ||
        type == "magus" ||
        type == "oracle" ||
        type == "psion" ||
        type == "psywarrior") {
        known = TP->query_mastered_spells(type);
        if (member_array(str2, known) == -1) {
            tell_object(TP, "You haven't mastered such a power!");
            return 1;
        }
    }

    if (type == "bard") {
        if (TP->is_wearing_type("armor") && !avatarp(TP)) {
            tell_object(TP, "You can't cast in all that armor.");
            return 1;
        }
    }
    
    if(type == "druid")
    {
        if(this_player()->query_property("negative energy affinity"))
        {
            tell_object(this_player(), "Your negative energy affinity has severed your tie to nature.");
            return 1;
        }
    }

    if (type == "monk") {
        known = TP->query_ki_spells();
        if (member_array(str2, known) == -1) {
            tell_object(TP, "You know no such ability!");
            return 1;
        }
        if (!TP->is_ok_armour("barb")) {
            tell_object(TP, "You must be unarmored in order to use your monk spells.");
            return 1;
        }
        wielded == (object*)TP->query_wielded();
        for (i = 0; i < sizeof(wielded); i++) {
            if (!objectp(wielded[i])) {
                continue;
            }
            if ((int)wielded[i]->query_size() > 1) {
                tell_object(TP, "Your " + wielded[i]->query_short() + " interferes " +
                            "with your ability to cast your monk spells!%^RESET%^");
                return 1;
            }
        }
    }

    if (type == "wizard" ||
        type == "mage" ||
        type == "sorcerer" ||
        type == "warlock") {
        armor = TP->all_armour();
        armor = distinct_array(armor);
        armor = filter_array(armor, "armor_filter", TO);
        if (FEATS_D->usable_feat(TP, "armored caster") ||
            type == "warlock") {
            armor = filter_array(armor, "light_armor_filter", TO);
        }
    }
    if (type == "psywarrior" || type == "psion") {
        if (FEATS_D->usable_feat(TP, "armored manifester") || FEATS_D->usable_feat(TP, "mind before matter")) {
            armor = ({});
        }else {
            armor = TP->all_armour();
            armor = distinct_array(armor);
            armor = filter_array(armor, "armor_filter", TO);
            if (FEATS_D->usable_feat(TP, "armored caster")) {
                armor = filter_array(armor, "light_armor_filter", TO);
            }
        }
    }
    if (type == "magus") {
        maguslvl = TP->query_class_level("magus");
        if (maguslvl > 12) {
            armor = ({});
        }
        else if (maguslvl > 6) {
            armor = TP->all_armour();
            armor = distinct_array(armor);
            armor = filter_array(armor, "armor_filter", TO);
            armor = filter_array(armor, "medium_armor_filter", TO);
        }
        else {
            armor = TP->all_armour();
            armor = distinct_array(armor);
            armor = filter_array(armor, "armor_filter", TO);
            armor = filter_array(armor, "light_armor_filter", TO);
        }
    }
    if (FEATS_D->usable_feat(TP, "eldritch conditioning")) {
        armor = ({});
    }
    if (sizeof(armor) && !avatarp(TP)) {
        tell_object(TP, "You cannot cast while wearing all that armor!");
        return 1;
    }

    if (TP->query("relationship_profile")) {
        if (strsrch((string)TP->query("relationship_profile"), "druid_") >= 0) {
            if (TP->query_property("shapeshifted") && type != "innate" && type != "cantrip" && type != "druid") {
                tell_object(TP, "You can only cast druid spells or innate abilities while in druidic form.");
                return 1;
            }
        }
    }

    spell = str2;
    spell = MAGIC_D->expand_quick_name(spell);
    spell = replace_string(spell, " ", "_");
    tmp = "/cmds/spells/" + spell[0..0] + "/_" + spell + ".c";
    if (!file_exists(tmp)) {
        write("Either that spell does not exist, or you do not know it!");
        return 1;
    }

    if (healharm) {
        targ = find_object_or_load(tmp);
        if (healharm > 0) {
            tmp = HEALS[(int)targ->query_spell_level(type) - 1];
        } else {
            tmp = HARMS[(int)targ->query_spell_level(type) - 1];
        }
        if (!file_exists(tmp)) {
            return 1;
        }
    }

    if (domain) {
        targ = find_object_or_load(tmp);
        slevel = targ->query_spell_level(type);
        if (slevel - 1 < 0) {
            write("Source spell is not in your class.");
            return 1;
        }

        tmp = MAGIC_D->get_spell_file_name((MAGIC_SS_D->query_domain_spells(domain_name))[slevel - 1]);
        if (tmp == "") {
            return 1;
        }
    }

    if (!tar) {
        tar = 0;
    }
    targ = new(tmp);

    if (healharm || domain) {
        targ->set_property("improvised", spell);
    }

    if (domain) {
        targ->set_spell_level(([type: slevel]));
    }

    spell = "level " + (int)tmp->query_spell_level(type); //spontaneous caster classes!

    if (type == "bard" ||
        type == "sorcerer" ||
        type == "inquisitor" ||
        type == "magus" ||
        type == "oracle" ||
        type == "psywarrior" ||
        type == "psion") {
        targ->set_property("improvised", spell);
    }
    TP->remove_property("spell_casting");
    TP->set_property("spell_casting", targ);

    if (FEATS_D->usable_feat(TP, "surprise spells") || FEATS_D->usable_feat(TP, "elusive spellcraft")) {
        targ->set_silent_casting(1);
    }

    if (type != "innate" && type != "cantrip") {
        targ->wizard_interface(TP, type, tar);
    }
    if (type == "innate") {
        targ->use_spell(TP, tar, (int)TP->query_innate_ability_level(str2), 100, "innate");
    }
    if (type == "cantrip") { //this should really use wizard interface somehow to pick up the proper clevels, might need to define cantrips differently
        targ->use_spell(this_player(), tar, TP->query_base_character_level(), 100, "cantrip");
    }

    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

cast

%^CYAN%^SYNOPSIS%^RESET%^

cast [%^ORANGE%^%^ULINE%^CLASS%^RESET%^] %^ORANGE%^%^ULINE%^SPELL%^RESET%^ [as %^ORANGE%^%^ULINE%^DOMAIN_NAME%^RESET%^ domain] [on self|here|rand|%^ORANGE%^%^ULINE%^SPELL_ARGS%^RESET%^]
cast [cleric] %^ORANGE%^%^ULINE%^SPELL%^RESET%^ as healing|harming on %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Ivokes %^ORANGE%^%^ULINE%^SPELL%^RESET%^ using character's %^ORANGE%^%^ULINE%^CLASS%^RESET%^. If %^ORANGE%^%^ULINE%^CLASS%^RESET%^ is ommited uses currently posed class you can change with %^ORANGE%^<pose>%^RESET%^. If you're single class character, uses your only class.

A %^ORANGE%^%^ULINE%^SPELL%^RESET%^ might or might not have arguments. A %^ORANGE%^%^ULINE%^SPELL%^RESET%^ might be its quick name referenced in the helpfile. Don't use spell quick names in aliases as they change as new spells get added.

By default, spell accepts %^ORANGE%^%^ULINE%^SPELL_ARGS%^RESET%^, a set of parameters that might be target of the spell or something else. Special argument 'self' will indicate you as the target, 'here' will indicate the room you're in, and 'rand' will indicate a random attacker.

See individual spell help files for specific syntax.

%^CYAN%^DOMAIN CASTING%^RESET%^

You can expend any spell slot to cast it as a domain spell of that domain. Refer to spell domain helpfile to see which spell will be cast.

For example, to cast prepared 'succor' spell as plant domain spell of the same level, Shambler, as cleric, one must do:

  %^ORANGE%^<cast cleric succor as plant domain>%^RESET%^

If the domain spell has target, it has to be applied eiter in the end of cast string or in the beginning. In next example fire domain cleric will cast succor as fire domain spell elemental swarm on goblin:

  %^ORANGE%^<cast cleric succor as fire domain on goblin>%^RESET%^

%^CYAN%^CLERICAL CHANNELING%^RESET%^

If you're of good alignment you can add the keywords %^ORANGE%^<as healing>%^RESET%^ to your cast invocation to convert the spell you name into a relevant healing (positive energy) spell.

If you're of evil alignment you can add the keywords %^ORANGE%^<as harming>%^RESET%^ to your cast invocation to convert the spell you name into a relevant harming (negative energy) spell.

Neutral clerics can do both.

For example, if you have light spell prepared you can cast it as cure/cause light wounds the next way:

  %^ORANGE%^<cast cleric light as healing on %^ORANGE%^%^ULINE%^TARGET%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<cast cleric light as harming on %^ORANGE%^%^ULINE%^TARGET%^RESET%^%^ORANGE%^>%^RESET%^

Positive energy heals living and harms undead.
Negative energy harms living and heals undead.

%^CYAN%^INNATE CASTING%^RESET%^
Some spells are innate.   They can be cast without preparing them.
EX:   cast innate undeath ward

Would cast undeath ward if you are a crypt stalker with enough levels for that ability.

%^CYAN%^CANTRIP CASTING%^RESET%^
Casting classes also get a few cantrip spells, which can be cast without preparation.
EX:   cast cantrip acid splash


%^CYAN%^SEE ALSO%^RESET%^

forget, buff, prepare, spells, recall, dispell
"
        );
}
