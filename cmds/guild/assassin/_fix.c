//	quick fix for title problem.

#include <std.h>

inherit DAEMON;

int cmd_fix(string str) {
    string pre, post, title;

    if(!str || str != "title") 
        return notify_fail("Fix what?\n");
    title = (string)this_player()->query_env("TITLE");
    if(sscanf(title, "%s$N%s", pre, post) != 2)
        return notify_fail("Your title doesn't need fixing.\n");
    if((int)this_player()->query_level() < 20)
    this_player()->set_env("TITLE", "$N"+post);
    else
        this_player()->set_env("TITLE", "High mortal $N"+post);
    return 1;
}
