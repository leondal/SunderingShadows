#include <std.h>
#include <magic.h>

void unstuck(object obj);

int cmd_stuck(string str)
{
    object stuck;
    if(!objectp(TP)) { return 1; }
    if(str) { return 0; }

    if((int)TP->query_property("used_stuck") > time())
    {
        tell_object(TP,"You can not use this command so soon.");
        return 1;
    }

    TP->set_casting(0);
    TP->remove_property("using instant feat");
    TP->remove_property("used_stuck");
    TP->set_property("used_stuck",time() + ROUND_LENGTH);
    tell_object(TP,"%^B_RED%^%^BOLD%^%^CYAN%^Unsticking you. Time is: "+ctime(time())+"  This command is for "
        "OOC game mechanic use only.");
    log_file("player/stuck",""+TP->query_true_name()+" used stuck on "+ctime(time())+"\n");

    return 1;
}




int help(string str)
{
    tell_object(TP,"Syntax: stuck\n\n"
        "This command will free you up when you are stuck in the middle of casting.  Please do not "
        "exploit this command to attempt to cast more spells than you should be able to, all uses "
        "of the command are logged.");
    return 1;
}
