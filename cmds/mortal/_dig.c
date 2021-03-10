#include <std.h>

inherit DAEMON;
int check_activity(string str);
void move_rubble(string ext, object tp);

int cmd_dig(string str)
{
    string* buried_exits;
    object ob;

    if (!str) {
        tell_object(TP, "You dig a hole in the ground.");
        tell_room(ETP, TPQCN + " digs a hole in the ground.", TP);
        return 1;
    }

    buried_exits = keys(ETP->query_orig_exits());
    if (member_array(str, buried_exits) == -1) {
        return notify_fail("That exit isn't buried.\n");
    }
    ob = new("/cmds/mortal/obj/digob.c");
    ob->move(TP);
    return ob->begin_dig(str, TP);
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

dig - dig out buried exit

%^CYAN%^SYNOPSIS%^RESET%^

dig %^ORANGE%^%^ULINE%^EXI%^RESET%^T

%^CYAN%^DESCRIPTION%^RESET%^

This command will remove rubble placed on %^ORANGE%^%^ULINE%^EXIT%^RESET%^.

The speed and success of your action will depend largely on your dexterity score.

%^CYAN%^SEE ALSO%^RESET%^

bury, sneak, trap

");
}
