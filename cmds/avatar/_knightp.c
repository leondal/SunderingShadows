#include <std.h>



int cmd_knightp(string str)
{
    string *info;
    object ob;

    if(!stringp(str) || str == "" || str == " ")
    {
        tell_object(TP,"Syntax: knightp <player> <on> | <off>");
        return 1;
    }
    str = lower_case(str);
    info = explode(str," ");
    if(sizeof(info) != 2)
    {
        tell_object(TP,"Syntax: knightp <player> <on> | <off>");
        return 1;
    }
    if(!objectp(ob=find_player(info[0])))
    {
        tell_object(TP,"Can't find a player named "+info[0]+", please check "
            "your spelling and try again.");
        return 1;
    }

    switch(info[1])
    {
    case "on":
        tell_object(TP,""+info[0]+" is now allowed to become a paladin/antipaladin.");
        ob->set("squired",1);
        return 1;
    case "off":
        tell_object(TP,""+info[0]+" is no longer allowed to be a paladin/antipaladin.");
        ob->set("squired",0);
        return 1;
    default:
        tell_object(TP,"Syntax: knightp <player> <on> | <off>");
        return 1;
    }
    return 1;
}

int help()
{
    tell_object(TP,"Syntax: knightp <player> <on> | <off>\n"
        "    This command will allow a person to advance to a paladin/antipaladin after "
        "they reach the next level block.");
    return 1;
}
    
