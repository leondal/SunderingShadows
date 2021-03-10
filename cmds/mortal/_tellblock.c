//      Tellblock
//      A wiz utility to block tells only by Gregon@Nightmare
//      based on _codeblock.c by Descartes of Borg.
//      06Nov1993


#include <std.h>

inherit DAEMON;

#define CHANNELS "bin/daemon/channels"

int cmd_tellblock() {
    this_player()->set_blocked("reply");
    if(this_player()->query_blocked("reply")) write("Tellblock on.\n");
    else write("Tellblock off.\n");
    return 1;
}

void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

tellblock - block incoming tells

%^CYAN%^SYNOPSIS%^RESET%^

tellblock on|off

%^CYAN%^DESCRIPTION%^RESET%^

This command will toggle blocking of all tells.

%^CYAN%^SEE ALSO%^RESET%^

tell, ignore, line use
");
}
