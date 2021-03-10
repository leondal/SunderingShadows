//	/bin/user/_cls.c
//	from the Nightmare mudlib
//	Command to clear the screen for terminals with ANSI code support
//	created by Otto@Nightmare 07 march 1993

#include "ansi.h"

#define CLS ESC+"[H"+ESC+"[2J"

#include <std.h>

inherit DAEMON;

int cmd_cls() {
    string str;

    if((str = (string)this_player()->getenv("TERM")) != "ansi" &&
      str != "xterm" && str != "ansi-status") {
	notify_fail("You do not have ansi set.  Try <help set>.\n");
	return 0;
    }
    message("prompt", CLS, this_player());
    return 1;
}

void help() {
    write("
%^CYAN%^%^NAME%^RESET%^

clear - clear screen

%^CYAN%^%^DESCRIPTION%^RESET%^

This command will clear your screen, then it will output prompt.

It sends ANSI sequence to your terminal so you must support it, and have your terminal set to ansi via <setenv TERM ansi>

%^CYAN%^%^SEE ALSO%^RESET%^

set
");
}
