#include <std.h>

int cmd_mindnet(string str)
{
    if(!stringp(str)) 
    {
        tell_object(TP,"Toggling mindnet listening off.");
        TP->delete("listen mindnet");
        return 1;
    }
    if(str == "listen")
    {
        tell_object(TP,"Toggling mindnet listening on.");
        TP->set("listen mindnet",1);
        return 1;
    }
    return 0;
}

int help(string str) 
{
    write(
@HELP
Syntax:  mindnet || mindnet listen

This toggles the on and off the ability to listen in on all 
mindnet spells cast by players.  Off is the default setting, 
you need to turn this on if you want to listen to mindnets.

HELP
);
return 1;
}
