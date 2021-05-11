#include <std.h>
inherit DAEMON;

#define BLASTTYPES (({ "frightful", "glacial", "brimstone", "lifedrinker", "vitriolic", "beshadowed", "binding", "utterdark" }))

int cmd_blasttype(string str)
{
    string spellname, currenttype;
    mixed masteredspells;

    if (!TP->is_class("warlock")) {
        tell_object(TP,"You fail to connect to eldritch powers.");
        return 1;
    }
    
    if(!strlen(str))
    {
        tell_object(this_player(), "You need to choose a valid blast type.");
        return 1;
    }

    currenttype = TP->query("warlock_blast_type");

    if (lower_case(str) == "none") {
        if (currenttype) {
            TP->delete("warlock_blast_type");
        }
        tell_object(TP, "%^BOLD%^%^WHITE%^You will now cast your eldritch blast with no essence applied.%^RESET%^");
        return 1;
    }

    spellname = str + " blast";

    masteredspells = ({});
    masteredspells += TP->query_mastered_spells("warlock");

    if (!sizeof(masteredspells)) {
        if (currenttype) {
            TP->delete("warlock_blast_type");
        }
        tell_object(TP, "%^BOLD%^%^WHITE%^You don't know any essences!%^RESET%^");
        return 1;
    }

    if (currenttype && member_array(currenttype + " blast", masteredspells) == -1) {
        TP->delete("warlock_blast_type");
        tell_object(TP,"%^BOLD%^%^WHITE%^Invalid warlock eldritch blast type has been reset!%^RESET%^");
        return 1;
    }

    if (!str) {
        tell_object(TP, "%^BOLD%^%^WHITE%^You have set your eldritch essence to " + str + " blast" + ".%^RESET%^");
        return 1;
    }

    if (member_array(spellname, masteredspells) == -1) {
        tell_object(TP, "%^BOLD%^%^WHITE%^You haven't learned that eldritch essence yet.%^RESET%^");
        return 1;
    }

    if (member_array(str, BLASTTYPES) == -1) {
        tell_object(TP, "%^BOLD%^%^WHITE%^That is not a valid eldritch essence.%^RESET%^");
        return 1;
    }

    TP->set("warlock_blast_type", str);
    tell_object(TP, "%^BOLD%^%^WHITE%^You have set your eldritch essence to " + spellname + ".%^RESET%^");
    return 1;
}

int help()
{
    write("
%^CYAN%^NAME%^RESET%^

blasttype - change warlock blast essence

%^CYN%^SYNOPSIS%^RESET%^

blasttype [TYPE] | none
     OR
blasttype

%^CYAN%^DESCRIPTION%^RESET%^

This command will set your eldritch blast essence to the specified type. If no argument is given, you will cast without an essence applied. You may only apply an essence that you have learned with master.

If you use 'none' as the blast type, you will clear your eldritch blast essence.

%^CYAN%^SEE ALSO%^RESET%^

cast, warlock, spells, master
");
    return 1;
}
