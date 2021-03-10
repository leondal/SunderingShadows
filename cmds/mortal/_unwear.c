#include <std.h>
inherit DAEMON;

int cmd_unwear(string str)
{
    return "/cmds/mortal/_remove"->cmd_remove(str);
}

void help()
{
    "/cmds/mortal/_remove"->help();
}
