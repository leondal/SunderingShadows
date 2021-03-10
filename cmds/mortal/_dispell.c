#include <std.h>

inherit DAEMON;

int help();

int cmd_dispell(string str)
{
    object* spells;

    TP->clear_targeted_spells();

    spells = TP->query_property("dispellable spells");

    if (pointerp(spells)) {
        spells = filter_array(spells, (: objectp($1) :));
    } else {
        message("info", "%^BOLD%^%^WHITE%^You have nothing listed as effecting you.", TP);
        return 1;
    }

    if (!strlen(str)) {
        int i;

        if (!sizeof(spells)) {
            tell_object(TP,"%^BOLD%^%^WHITE%^You have no spells you maintain consciously.");
            return 1;
        }


        message("info", "%^RESET%^%^BOLD%^%^BLUE%^--==%^RESET%^%^BOLD%^%^CYAN%^< %^RESET%^%^BOLD%^Spells you maintain %^RESET%^%^BOLD%^%^CYAN%^>%^RESET%^%^BOLD%^%^BLUE%^==--%^RESET%^", TP);
        for (i = 0; i < sizeof(spells); i++) {
            if (objectp(spells[i])) {
                message("info", "%^BOLD%^%^BLUE%^" + sprintf("%2d", i) + ". " + spells[i]->query_spell_display(), TP);
            }
        }
        return 1;
    }

    if (regexp(str, "^[0-9]+")) {
        if (atoi(str) > (sizeof(spells) - 1)) {
            write("%^BOLD%^%^CYAN%^No spell under this number.");
        } else if (objectp(spells[atoi(str)])) {
            write("BOLD%^%^CYAN%^You dispell " + spells[atoi(str)]->query_spell_display());
            spells[atoi(str)]->dest_effect();
        } else {
            write("%^BOLD%^%^CYAN%^No spell under this number.");
        }
        return 1;
    }

    if (str == "all") {
        object spell;
        foreach(spell in spells) {
            if (objectp(spell)) {
                write("%^BOLD%^%^CYAN%^You dispell " + spell->query_spell_display());
                spell->dest_effect();
            }
        }
        return 1;
    }

    {
        int allflag, tflag;
        object spell, target;
        string sname;
        string tname, targ;

        if (regexp(str, "all")) {
            allflag = 1;
        }

        if (regexp(str, " on ")) {
            tflag = 1;
        }


        sname = str;

        if (allflag && !tflag && strsrch(str, "all") == 0 && sscanf(str, "all %s", sname) != 1) {
            write("%^BOLD%^%^CYAN%^You must provide the spell name.");
            return 1;
        }

        if (tflag && allflag && strsrch(str, "all on") == 0 && sscanf(str, "all on %s", tname) != 1) {
            write("%^BOLD%^%^CYAN%^You must provide the target.");
            return 1;
        }

        if (tflag && !allflag && sscanf(str, "%s on %s", sname, tname) != 2) {
            write("%^BOLD%^%^CYAN%^You must provide both spell name and target.");
            return 1;
        }

        foreach(spell in spells)
        {
            if (objectp(spell)) {

                if (sizeof(tname)) {
                    if (objectp(target = spell->query_target_object())) {
                        targ = lower_case(target->getParsableName());
                    } else {
                        targ = "";
                    }

                    if (objectp(present(tname, TP))) {
                        targ = tname;
                    }
                }

                if (spell->query_spell_name() == sname ||
                    tname = targ) {
                    write("%^BOLD%^%^CYAN%^You dispell " + spell->query_spell_display());
                    spell->dest_effect();
                    if (!allflag) {
                        break;
                    }
                }
            }
        }
        return 1;

    }


}

int
help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

dispell - display and manage active spells

%^CYAN%^SYNOPSIS%^RESET%^

dispell
dispell [%^ORANGE%^%^ULINE%^NUM%^RESET%^]
dispell [all] [%^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^]
dispell all | %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^ on %^ORANGE%^%^ULINE%^TARGET_NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument, this command will list all spells you have casted and that are currently active. The list will update as spells go up and down. It won't list, however, spells someone casted on you.

Provide %^ORANGE%^%^ULINE%^NUM%^RESET%^ as an argument and spell on that list under that %^ORANGE%^%^ULINE%^NUM%^RESET%^ will be dispelled. Note that list numbering will be renewed after that.

Provide %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ and you will cancel effects of first spell with that name.

Provide keyword all and you will dispell all spells. If you follow keyword 'all' by %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^, you will dispell all spells with that %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^

Provide keyword all or %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ followed by %^ORANGE%^%^ULINE%^TARGET%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ and you will dispell all effects caused by %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ on said %^ORANGE%^%^ULINE%^TARGET%^RESET%^. %^ORANGE%^%^ULINE%^TARGET%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ can use any of target's valid ids.

%^CYAN%^SEE ALSO%^RESET%^

cast, prepare, buff, bonuses

"
        );
    return 1;
}
