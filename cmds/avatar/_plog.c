#include <std.h>

int cmd_plog(string str)
{
    string * args, arg;
    string name;
    int bytes = 2048;

    if (!sizeof(str)) {
        tell_object(TP, "Provide name of a player as an argument, at least.");
    }

    args = explode(str, " ");

    foreach(arg in args)
    {
        if (regexp(arg, "[0-9]+")) {
            bytes = atoi(arg);
        }else {
            name = arg;
        }
    }

    tail("/log/tshlog/player/"+name, 2048);
    return 1;
}

void help(){
  write(
"
%^CYAN%^NAME%^RESET%^

plog - review recent player activity

%^CYAN%^SYNTAX%^RESET%^

plog %^ORANGE%^%^ULINE%^NAME%^RESET%^ [BYTES]

%^CYAN%^DESCRIPTION%^RESET%^

This will display command history typed in by aa with the %^ORANGE%^%^ULINE%^NAME%^RESET%^.

Optional byes argument will display last %^ORANGE%^%^ULINE%^BYTES%^RESET%^ of the file. Default is 2048.

%^CYAN%^SEE ALSO%^RESET%^

elog, log, replog, log_file()
"
	);
}
