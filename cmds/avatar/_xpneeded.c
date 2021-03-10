#include <std.h>
#include <daemons.h>

int no_str_message(object player)
{
    if(!objectp(player)) { return 1; }
    tell_object(player,"%^RESET%^%^BOLD%^xpneeded can work with any of the following syntax%^RESET%^:\n"
        "%^RESET%^%^BOLD%^    xpneeded <player name>%^RESET%^"
        "\n\t Will return exp needed for next level\n"
        "%^RESET%^%^BOLD%^    xpneeded <player name> <class>%^RESET%^"
        "\n\t Will return exp needed for player's <class>\n"
        "%^RESET%^%^BOLD%^    xpneeded <player name> <class> <level>%^RESET%^"
        "\n\t Will return exp needed for player's <class> at <level>\n"
        "%^RESET%^%^BOLD%^    xpneeded <class>%^RESET%^"
        "\n\t Will return a table of exp for all levels for <class>\n"
        "%^RESET%^%^BOLD%^    xpneeded <class> <level>%^RESET%^"
        "\n\t Will return the exp needed for a <class> to reach <level>\n");
    return 1;
}

int display_class_info(object tp,object player,string *classes)
{
    int total_exp,total_difference,current,needed,i,diff;
    string name;

    if(!objectp(tp))        { return 1; }
    if(!objectp(player))    { return 1; }
    if(!pointerp(classes))  { return 1; }
    if(!sizeof(classes))    { return 1; }

    name = lower_case((string)player->query_true_name());
    
    tell_object(tp,"Classes for player "+capitalize(name)+" are as follows:  "+implode(classes," ")+"");

    for(i=0;i<sizeof(classes);i++)
    {
        current          = player->get_general_exp(classes[i]);
        needed           = ADVANCE_D->get_exp((int)player->query_class_level(classes[i])+1, classes[i], player);
        diff             = needed - current;
        
        total_exp        += current;
        total_difference += diff;

        tell_object(tp,""+capitalize(name)+" currently has %^BOLD%^"+current+"%^RESET%^ exp in "
            "the %^BOLD%^"+classes[i]+"%^RESET%^ class and needs %^BOLD%^"+needed+"%^RESET%^ exp for the "
            "next level.");
        tell_object(tp,"    Difference for %^BOLD%^"+classes[i]+"%^RESET%^: %^BOLD%^"+diff+"%^RESET%^\n");
    }  

    tell_object(tp,""+capitalize(name)+" has %^BOLD%^"+sizeof(classes)+"%^RESET%^ total classes with a total "
        "exp of %^BOLD%^"+total_exp+"%^RESET%^ and a combined exp to level all classes "
        "equal to %^BOLD%^"+total_difference+"%^RESET%^.");
    return 1;
}

varargs int display_single_class_info(object tp,object player,string theclass,int num)
{
    int level,current,needed,difference;
    string *classes=({}),name;

    if(!objectp(tp)) { return 1; }
    if(!objectp(player)) { return 1; }
    if(!stringp(theclass)) { return 1; }

    level = 0;
    if(intp(num)) { level = num; }

    classes = player->query_classes();
    name    = player->query_true_name();

    if(member_array(theclass,classes) == -1)
    {
        tell_object(tp,""+capitalize(name)+" does not have the class "+theclass+".");
        return 1;
    }

    current    = player->get_general_exp(theclass);

    if(!level)
    {
        needed = ADVANCE_D->get_exp((int)player->query_class_level(theclass) + 1, theclass,player);
    }
    else
    {
        needed = ADVANCE_D->get_exp(level,theclass,player);
    }

    difference = needed - current;

    if(level)
    {
        tell_object(TP,""+capitalize(name)+" has "+current+" exp in the "+theclass+" class, and needs "
            ""+needed+" before reaching level "+level+".");
        tell_object(TP,"Difference:  "+difference+"\n");
    }
    else
    {
        tell_object(TP,""+capitalize(name)+" has "+current+" exp in the "+theclass+" class and needs "
            ""+needed+" before reaching the next level.");
        tell_object(TP,"Difference:  "+difference+"\n");
    }
    return 1;
}

int cmd_xpneeded(string str)
{
    string *info=({}),*valid_classes=({}),type,*classes=({});
    int i,size,table_exp,level;
    object dummy,player; // needed to trick the daemon since I can't change it -Ares

    if(!objectp(TP)) { return 1; }
    if(!stringp(str) || str == "" || str == " ") { no_str_message(TP); return 1; }

    valid_classes = ({ "psion", "mage", "cleric", "cavalier", "thief", "ranger", "paladin", "antipaladin", "fighter", "bard" });

    info = explode(lower_case(str)," ");

    if(!sizeof(info) || sizeof(info) == 0) { no_str_message(TP); }

    size = sizeof(info);
    
    if(member_array(info[0],valid_classes) != -1) { type = "class"; }
    else if(user_exists(info[0])) { type = "player"; }
    else 
    {
        tell_object(TP,"Either that user does not exist or you picked a class that is not valid, please "
            "check your spelling and try again.");
        return 1;
    }

    switch(type)
    {
    case "class":
        if(size == 1)
        {
            dummy = new("/realms/ares/testdummy.c"); // can be any object that's not an immortal -Ares
            for(i=1;i<41;i++) // i = 1 on purpose
            {
                table_exp = ADVANCE_D->get_exp(i,info[0],dummy);
                tell_object(TP,"%^BOLD%^%^CYAN%^   Exp needed for level "+i+" "+capitalize(info[0])+":  %^RESET%^"+table_exp+"");
            }
            dummy->remove();
            return 1;
        }
        else if(size == 2)
        {
            level = to_int(info[1]);
            if(!intp(level))
            {
                tell_object(TP,"Syntax: xpneeded <class> <level>\n");
                return 1;
            }
            dummy = new("/realms/ares/testdummy.c"); // can be any object that's not an immortal -Ares
            table_exp = ADVANCE_D->get_exp(level,info[0],dummy);
            dummy->remove();
            tell_object(TP,"%^BOLD%^%^CYAN%^   Exp needed for a "+capitalize(info[0])+ " of level "+info[1]+":  %^RESET%^"+table_exp+"\n");
            return 1;
        }

    //xpneeded <player name>
    //xpneeded <player name> <class>
    //xpneeded <player name> <class> <level>

    case "player":

        if(!find_player(info[0]))
        {
            tell_object(TP,"That player does not appear to be online.\n");
            return 1;
        }

        player = find_player(info[0]);

        if(size == 1)
        {
            classes = player->query_classes();
            display_class_info(TP,player,classes);
            return 1;
        }

        else 
        {
            classes = player->query_classes();
            if(member_array(info[1],classes) == -1)
            {
                tell_object(TP,"The class "+info[1]+" is not valid, please pick a valid class.");
                return 1;
            }
            if(size == 2)
            {
                display_single_class_info(TP,player,info[1]);
                return 1;
            }            
            if(size == 3)
            {
                level = to_int(info[2]);
                if(!intp(level))
                {
                    tell_object(TP,"Syntax: xpneeded <player name> <class> <level>\n");
                    return 1;
                }
                display_single_class_info(TP,player,info[1],level);
                return 1;
            }
        }
    }
    return 1;
}