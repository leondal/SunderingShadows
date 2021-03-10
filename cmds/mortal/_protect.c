#include <std.h>

inherit DAEMON;

int cmd_protect(string str)
{
    object ob, protectee;

    if (!str) {
        return notify_fail("Protect who?\n");
    }


    if (TP->query_bound() || TP->query_tripped()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    protectee = find_player((string)TP->realNameVsProfile(str));
    if ((!objectp(protectee)) || (!ob = present(protectee, ETP))) {
        if (!ob = present(str, ETP)) {
            return notify_fail("You can't seem to find that to protect.\n");
        }
    }
    if (!newbiep(TP) && newbiep(ob)) {
        return notify_fail("You can only protect those of your social status.\n");
    }

    if (ob == TP) {
        return notify_fail("Yeah, right.  NOT!\n");
    }


    if (!living(ob)) {
        tell_object(TP, "You can only protect living creatures!");
        return 1;
    }

    if (member_array(ob, TP->query_attackers()) != -1) {
        tell_object(TP, "You cannot protect something that you are already fighting!");
        return 1;
    }
    if (interactive(TP) && member_array(ob, TP->query_protectors()) != -1) {
        return notify_fail("They're trying to protect you!\n");
    }

    if ((int)TP->query_stats("intelligence") < random(15)) {
        write("You can't find a good way to protect " + ob->query_cap_name() + "!!\n");
        return 1;
    }

    tell_room(ETP, "%^RED%^" + TPQCN + " stands boldly in protection of " + ob->query_cap_name() + "!", ({ ob, TP }));
    tell_object(ob, "%^RED%^" + TPQCN + " stands boldly in protection of you.");
    write("%^RED%^You boldly stand in protection of " + ob->query_cap_name() + ".");
    ob->add_protector(TP);
    return 1;
}

int help()
{
    write (
"
%^CYAN%^NAME%^RESET%^

protect - protect someone

%^CYAN%^SYNTAX%^RESET%^

protect TARGET

%^CYAN%^DESCRIPTION%^RESET%^

He protecc.

%^CYAN%^SEE ALSO%^RESET%^

unprotect, kill, wimpy
"
   );
   return 1;
}
