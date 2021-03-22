#include <std.h>

int cmd_wizlog(string str)
{

    string * args, arg;
    string name;
    int bytes = 2048;

    if (!sizeof(str)) {
        tell_object(TP, "Provide name of a wiz as an argument, at least.");
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

    bytes = (bytes > 10 * 1024) ? (10 * 1024) : bytes;

    tail("/log/tshlog/wizard/"+name, 2048);
    return 1;
}

void help(){
  write(
"
%^CYAN%^NAME%^RESET%^

wizlog - review activity of creators and above

%^CYAN%^SYNOPSIS%^RESET%^

wizlog %^ORANGE%^%^ULINE%^NAME%^RESET%^ [%^ORANGE%^%^ULINE%^BYTES%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

To enforce transparency, this command will display the recent command history typed in by a wizard with the %^ORANGE%^%^ULINE%^NAME%^RESET%^.

This command won't display the activity of avatars. It only affects the conduct of wizards, your coder and administration staff. Please consider applying to become one and help the mud!

Optional %^ORANGE%^%^ULINE%^BYTES%^RESET%^ argument will display last %^ORANGE%^%^ULINE%^BYTES%^RESET%^ of the file. Default is 2048. 

%^CYAN%^SEE ALSO%^RESET%^

help, help *player commands
"
	);
}
