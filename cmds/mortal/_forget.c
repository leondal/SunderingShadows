#include <std.h>
#include <daemons.h>

#define SYNOPSIS "Syntax:  forget <classtype> <spellname>\n"

inherit DAEMON;

int cmd_forget(string str)
{
    string myclass, myspell, file;

    if (!str) {
        return notify_fail("Forget what?\n");
    }

    if (regexp(str, implode(PLAYER_D->list_classes(), "|") + "|innate")) {
        if (!sscanf(str, "%s %s", myclass, myspell)) {
            return notify_fail("Syntax: <forget CLASS SPELL>\n");
        }
    } else {
        myclass = TP->query_class();
        myspell = str;
    }

    if (!TP->is_class(myclass)) {
        return notify_fail("You cannot cast spells as a " + myclass + "!\n");
    }

    if (myclass == "antipaladin") {
        myclass = "paladin";
    }
    TP->set_property("forgetting spell", 1);
    file = MAGIC_D->get_spell_file_name(myspell);

    if (!TP->forget_memorized(myclass, myspell, 1)) {
        TP->remove_property("forgetting spell");
        return notify_fail("The spell, '" + myspell + "' is not in your memory! Use <fixspells> if this is wrong.\n");
    } else {
        TP->remove_property("forgetting spell");
        file = MAGIC_D->get_spell_file_name(myspell);
        if (!file_exists(file)) {
            myspell = capitalize(myspell);
            tell_object(TP, "" + myspell + " is not a spell!");
        }else {
            tell_object(TP, "The spell '" + myspell + "' has been forgotten successfully!");
        }
    }
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

forget - forget a spell

%^CYAN%^SYNOPSIS%^RESET%^

forget %^ORANGE%^[%^ULINE%^CLASS%^RESET%^%^ORANGE%^]%^RESET%^ %^ORANGE%^%^ULINE%^SPELL%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Removes spell from your memorized list. If it fails and spell is still there you might want to look into %^ORANGE%^<fixspells>%^RESET%^ command.

%^CYAN%^SEE ALSO%^RESET%^

fixspells, recall, prepare, cast, master
");
}
