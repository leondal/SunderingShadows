#include <std.h>

int cmd_history(string args)
{
    string fname;

    if(!avatarp(TP))
        fname = "/log/tshlog/player/"+TP->query_name();
    else {
        if (wizardp(TP)) {
            fname = "/log//tshlog/wizard/"+TP->query_name();
        } else {
            fname = "/log/tshlog/avatar/"+TP->query_name();
        }
    }
    if(args=="all")
        TP->more(fname);
    else
    {
        write("%^BOLD%^Last 100 commands:%^RESET%^");
        tail(fname);
    }
    return 1;
}

void help(){
  write(
"
%^CYAN%^NAME%^RESET%^

history - display your command history

%^CYAN%^SYNOPSIS%^RESET%^

history [all]

%^CYAN%^DESCRIPTION%^RESET%^

This will display last 100 commands you have enetered.

Argument 'all' will allow the display of everything stored in the recent command log.

%^CYAN%^SEE ALSO%^RESET%^

prompt, set, score, hp, money
"
	);
}
