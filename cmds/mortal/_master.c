
#include <magic.h>
#include <daemons.h>
#include <master_limits.h>

/**
 * @file
 */

mapping CLASSMAP=(["mage":MAGEKNOWN,
                   "sorcerer":SORCKNOWN,
                   "oracle":SORCKNOWN,
                   "psion":PSIONKNOWN,
                   "psywarrior":PWKNOWN,
                   "inquisitor":INQKNOWN,
                   "bard":INQKNOWN,
                   "magus" : INQKNOWN,
                   "warlock":WARLOCKKNOWN]);

mapping query_mastering_classes()
{
    return CLASSMAP;
}

int cmd_master(string args)
{
    string myclass = TP->query_class();
    int slvl;
    string sarg,sarg2;
    if (sizeof(TP->query_classes()) > 1) {
        write("%^CYAN%^You are posing as a %^BOLD%^%^WHITE%^" + myclass + "%^RESET%^%^CYAN%^. To change that use %^ORANGE%^<pose>%^CYAN%^.");
    }

    if (member_array(myclass, keys(CLASSMAP)) == -1) {
        write("%^ORANGE%^Your currently posed class doesn't master.");
        return 1;
    }

    validate_mastered();

    if (!args || args == "map") {
        int mylvl = TP->query_prestige_level(myclass);
        mapping spell_index = MAGIC_D->query_index(myclass);
        int i;
        int bonuslimit, max_spells, spell_access;
        int* spelllevels = allocate(9);
        string sname;
        string* myspells = TP->query_mastered_base()[myclass];

        mylvl = mylvl > 50?50:mylvl;

        if (sizeof(myspells)) {
            foreach(sname in myspells)
            {
                spelllevels[spell_index[sname] - 1] += 1;
            }
        }

        if (myclass == "magus" && FEATS_D->usable_feat(TP, "greater spell access")) {
            spell_access = 2;
        }

        write("%^CYAN%^You have spells as follows:");
        for (i = 0; i < 9; i++) {
            max_spells = CLASSMAP[myclass][mylvl][i] + spell_access;
            if (CLASSMAP[myclass][mylvl][i]) {
                write("%^CYAN%^Level " + (i + 1) + ": %^RESET%^" + spelllevels[i] + " of " + max_spells);
            }
        }
        if (FEATS_D->usable_feat(TP, "spell knowledge")) {
            bonuslimit += 2;
        }
        if (FEATS_D->usable_feat(TP, "tome of ancient secrets")) {
            bonuslimit += 2;
        }
        if (FEATS_D->usable_feat(TP, "greater spell knowledge")) {
            bonuslimit += 5;
        }
        if (bonuslimit) {
            write("%^CYAN%^You can learn " + bonuslimit + " spells above limit due to your spell knowledge feat.");
        }

        return 1;
    }

    if (args == "list") {
        mapping spell_index = MAGIC_D->query_index(myclass);
        string* myspells = TP->query_mastered_base()[myclass];
        string spell;
        mixed* spellist = allocate(9);
        int mylvl = TP->query_prestige_level(myclass);
        int i;

        if (sizeof(myspells)) {
            foreach(spell in myspells)
            {
                spellist[spell_index[spell] - 1] = (spellist[spell_index[spell] - 1]?spellist[spell_index[spell] - 1]:({}))
                    + ({ spell }); //If LHS is not emply check
            }

            write("%^CYAN%^You have mastered:");
        }

        for (i = 0; i < 9; i++) {
            if (CLASSMAP[myclass][mylvl][i]) {
                write("%^CYAN%^Level " + (i + 1) + ": %^RESET%^" +
                      (spellist[i]?implode(sort_array(spellist[i], 1), ", "):"none"));   //Non empty check
            }
        }
        {
            string* bonusspells = TP->query_mastered_bonus()[myclass];

            if (sizeof(bonusspells)) {
                write("%^CYAN%^Additional spells you know:%^RESET%^");
                write(implode(sort_array(bonusspells, 1), ", "));
            }
        }

        return 1;
    }

    if (sscanf(args, "level %d", slvl) == 1) {
        string* myspells = TP->query_mastered_spells(myclass);
        mapping spell_index = MAGIC_D->index_masterable_spells(TP, myclass);
        string* savail;

        savail = keys(filter_mapping(spell_index, (: $2 == $3:), slvl));
        if (sizeof(myspells)) {
            savail -= myspells;
        }

        write("%^CYAN%^Spells available to master at level " + slvl + ":%^RESET%^");
        if (sizeof(savail)) {
            write(implode(sort_array(savail, 1), ", "));
        }else {
            write("none");
        }
        return 1;
    }

    if (sscanf(args, "forget %s", sarg) == 1) {
        mapping spell_index = MAGIC_D->index_masterable_spells(TP, myclass);
        string* myspells = TP->query_mastered_base()[myclass];
        int forgettime = (int)TP->query("last_master_forget");

        {
            if (!spell_index[sarg]) {
                write("%^ORANGE%^The spell %^BOLD%^%^RED%^" + sarg + "%^RESET%^%^ORANGE%^ does not exist.%^RESET%^");
                return 1;
            }
            if (member_array(sarg, myspells) == -1) {
                write("%^ORANGE%^You don't know %^BOLD%^%^RED%^" + sarg + "%^RESET%^%^ORANGE%^.%^RESET%^");
                return 1;
            }

            if (forgettime > time() - 32400) {
                write("%^ORANGE%^You can forget a spell %^RED%^%^BOLD%^once per nine hours%^RESET%^%^ORANGE%^.%^RESET%^");
                return 1;
            }
        }
        if (TP->is_class("warlock")) {
            TP->delete("warlock_blast_type");
        }
        TP->set("last_master_forget", time());
        TP->remove_mastered(myclass, sarg);
        write("%^CYAN%^You have forgotten %^BOLD%^%^WHITE%^" + sarg + "%^RESET%^%^CYAN%^.%^RESET%^");
        return 1;
    }
    else
    {
        mapping spell_index = MAGIC_D->index_masterable_spells(TP, myclass);
        int mylvl = TP->query_prestige_level(myclass);
        int bonuslimit = 0;
        int *knownperlevel = allocate(9);
        int i, max_spells, spell_access;
        string sname;
        string *myspells = TP->query_mastered_base()[myclass];

        {
            if (!spell_index[args]) {
                write("%^ORANGE%^The spell %^BOLD%^%^RED%^" + args + "%^RESET%^%^ORANGE%^ does not exist.%^RESET%^");
                return 1;
            }
            if (sizeof(myspells)) {
                if (member_array(args, myspells) > -1) {
                    write("%^ORANGE%^You already know %^BOLD%^%^RED%^" + args + "%^RESET%^%^ORANGE%^.%^RESET%^");
                    return 1;
                }
            }
        }

        if (sizeof(myspells)) {
            foreach(sname in myspells)
            {
                if (!spell_index[sname]) {
                    tell_object(TP, "Possibly wrong spell level: " + sname);
                    continue;
                }

                knownperlevel[spell_index[sname] - 1] += 1;
            }
        }

        mylvl = mylvl>50?50:mylvl;

        if (myclass == "magus" && FEATS_D->usable_feat(TP, "greater spell access")) {
            spell_access = 2;
        }

        {
            for (i = 0; i < 9; i++) {
                max_spells = CLASSMAP[myclass][mylvl][i] + spell_access;
                if (knownperlevel[i] > max_spells) {
                    bonuslimit -= knownperlevel[i] - max_spells;
                }
            }
            if (FEATS_D->usable_feat(TP, "spell knowledge")) {
                bonuslimit += 2;
            }
            if (FEATS_D->usable_feat(TP, "tome of ancient secrets")) {
                bonuslimit += 2;
            }
            if (FEATS_D->usable_feat(TP, "greater spell knowledge")) {
                bonuslimit += 5;
            }
        }

        if (CLASSMAP[myclass][mylvl][spell_index[args] - 1] &&
            (knownperlevel[spell_index[args] - 1] < CLASSMAP[myclass][mylvl][spell_index[args] - 1] + spell_access ||
            bonuslimit > 0)) {
            TP->add_mastered(myclass, args);
            write("%^CYAN%^You have just mastered %^BOLD%^%^WHITE%^" + args + "%^RESET%^%^CYAN%^!%^RESET%^");
            if (myclass == "mage") {
                object sb;
                if (objectp(sb = present("spellbook", TP))) {
                    sb->init();
                }
            }

            return 1;
        }else {
            write("%^ORANGE%^You have exceeded your limit for level " + (spell_index[args]) + " spells!%^RESET%^");
        }
    }
    return 1;
}

void validate_mastered()
{
    string myclass;
    string myspell;
    mapping mymastered = TP->query_mastered_base();
    mapping mymasteredbonus = TP->query_mastered_bonus();


    if (sizeof(mymastered)) {
        foreach(myclass in keys(mymastered))
        {
            string* spell_index;
            mapping index_map = MAGIC_D->query_index(myclass);
            mapping myunrestricted = MAGIC_D->index_masterable_spells(TP, myclass);

            if (!sizeof(index_map)) {
                spell_index = ({});
            } else {
                spell_index = keys(index_map);
            }

            foreach(myspell in mymastered[myclass])
            {
                if (member_array(myspell, spell_index) == -1) {
                    tell_object(TP, "Wrong spell in " + myclass + " class, removing: " + myspell);
                    TP->remove_mastered(myclass, myspell);
                }
                if (arrayp(mymasteredbonus[myclass])) {
                    if (member_array(myspell, mymasteredbonus[myclass]) != -1) {
                        tell_object(TP, "Spell gained as a bonus for " + myclass + ", removing: " + myspell);
                        TP->remove_mastered(myclass, myspell);
                    }
                }
                if (mapp(myunrestricted)) {
                    if (member_array(myspell, keys(myunrestricted)) == -1) {
                        tell_object(TP, "Spell no longer unrestricted for " + myclass + " special, removing: " + myspell);
                        TP->remove_mastered(myclass, myspell);
                    }
                }
            }
        }
    }
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

master - manage spells you know

%^CYAN%^SYNOPSIS%^RESET%^

master
master list
master level %^ORANGE%^%^ULINE%^NUM%^RESET%^
master %^ORANGE%^%^ULINE%^SPELL%^RESET%^
master forget %^ORANGE%^%^ULINE%^SPELL%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command is an extensive interface to your knowledge of spells. Some caster classes use it to learn spells, some don't. This command is essential for sorcerers, warlocks, psions and psywarriors. Without spell being on their mastered list they won't be able to cast it. Mages can expand their spell knowledge through this command, although the main way they obtain new spells is through the spellbook.

%^ORANGE%^<master>%^RESET%^
  Without an argument this command will display all available knowledge slots for each level.

%^ORANGE%^<master list>%^RESET%^
  This will display list of spells you know grouped by level.

%^ORANGE%^<master %^ORANGE%^%^ULINE%^SPELL%^RESET%^%^ORANGE%^>%^RESET%^
  With this command you will commit to learning a %^ORANGE%^%^ULINE%^SPELL%^RESET%^.

%^ORANGE%^<master forget %^ORANGE%^%^ULINE%^SPELL%^RESET%^%^ORANGE%^>%^RESET%^
  Once per 30 hours you can forget a %^ORANGE%^%^ULINE%^SPELL%^RESET%^ and learn a new one.

%^CYAN%^SEE ALSO%^RESET%^

recall, cast, prepare, buff, spellbook, classes, warlock, psion, sorcerer, psywarrior, prompt, ki
");
}
