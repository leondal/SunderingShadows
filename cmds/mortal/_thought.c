#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_thought(string str)
{
    if (!stringp(str)) {
        return notify_fail("Have no thoughts of your own?\n");
    }
// if (TP->query_unconscious()) return notify_fail("You think that you are ill equipped to do that currently.\n");
//  if(!avatarp(TP)) return 0;

    CHAT_D->force_chat(TP, "petition", this_player()->QCN + " %^BOLD%^. o O ( " + str + " )%^RESET%^", 1);
    write(capitalize((string)TP->query_name()) + " %^BOLD%^. o O ( " + str + " )%^RESET%^");
    return 1;
}
void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

thought - think something

%^CYAN%^SYNOPSIS%^RESET%^

thought %^ORANGE%^%^ULINE%^THOUGHT%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This allows the avatars (Your dungeon masters) to know what you are thinking or some details about the situation. No response is guaranteed, nor is it always possible that any responses may be forthcoming.

%^BOLD%^%^WHITE%^N.B.%^RESET%^ This method of communication is for IC messages only! If you need to convey something secretly about some problem you're experiencing you must use tells, or you have to get attention of an imm on the inform line.

%^CYAN%^SEE ALSO%^RESET%^

avatarmail, say, tell, whisper, line use
"
        );
    return 1;
}
