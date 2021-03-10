//_speak

#include <std.h>

inherit DAEMON;

int cmd_speak(string str)
{
    if(!str)
    {
        return notify_fail("speak <language>\n");
    }

    if(!TP->set_spoken(str))
    {
        return notify_fail("You do not know that language well enough to speak it.\n");
        if(!wizardp(TP) && str == "wizish") { return notify_fail("If you have that language, its useless to you.\n"); }

    }

    write("You have set your spoken language to "+str+".");
    return 1;
}

int help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

speak - choose spoken language

%^CYAN%^SYNOPSIS%^RESET%^

speak %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will set the language that you speak in says and tells.

%^CYAN%^SEE ALSO%^RESET%^

spoken languages, languages, say, yell, mail, communication
");
    return 1;
}
