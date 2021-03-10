//_Sign

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help(){
    write(

"
%^CYAN%^NAME%^RESET%^

sign - sign objects

%^CYAN%^SYNOPSIS%^RESET%^

sign OBJECT [as NAME]

%^CYAN%^DESCRIPTION%^RESET%^

This allows you to sign an object indicating an authentic signature.

You can forge signatures signing as NAME. Ability to detect signature is forged will depend on the reader's academic skill versus your academics skill.

%^CYAN%^SEE ALSO%^RESET%^

seal, write, languages
"
        );
    return 1;

}

int cmd_sign(string str)
{
    string what, who, who2;
    object ob;

    if (!str) {
        return help();
    }
    if (sscanf(str, "%s as %s", what, who) != 2) {
        what = str;
    }

    ob = present(what, TP);
    if (!objectp(ob)) {
        ob = present(what, ETP);
        if (!objectp(ob)) {
            return notify_fail("Can not find " + what + " to sign.\n");
        }
    }
    if (!stringp(who)) {
        ob->sign(TP, TP->query_name(), TP->query_skill("academics"));
        write("You sign your name to the " + ob->query_short() + ".");
        tell_room(ETP, TPQCN + " signs " + TP->query_possessive() + " name to the " + ob->query_short() + ".", TP);
        return 1;
    }

    who2 = TP->realNameVs(who);
    if (!stringp(who2)) {
        write("You can't forge a signature of someone you don't know.");
        return 1;
    }
    if (!user_exists(who2)) {
        write("You can't forge a signature of someone who doesn't exist.");
        return 1;
    }

    ob->sign(TP, who, TP->query_skill("academics"));

    write("You forge " + capitalize(who) + "'s name on the " + ob->query_short() + ".");
    tell_room(ETP, TPQCN + " signs " + TP->query_possessive() + " name is the " + ob->query_short() + ".", TP);
    return 1;
}
