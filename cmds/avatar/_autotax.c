#include <std.h>

int cmd_autotax(string str)
{
    object ob;
    int tax;

    if(!stringp(str) || str == "" || str == " " || !objectp(ob=find_player(str)))
    {
        tell_object(TP,"Syntax autotax <player>");
        return 1;
    }
    tax = (int)ob->query("autotax");

    tell_object(TP,"%^RESET%^"+str+" was last autotaxed at %^BOLD%^"+tax+"%^RESET%^ percent.");
    return 1;
}

int help()
{
    tell_object(TP,"Syntax: autotax <player>\n"
        "  This command will return the last autotax level that <player> had "
        "the last time they gained exp.  It is only updated when a player gains "
        "experience points, so may not be up to date if it has been several "
        "hours since they gained experience.");
    return 1;
}
    
