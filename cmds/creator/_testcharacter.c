#include <std.h>

int cmd_testcharacter(string str)
{
    object ob;

    if(!str || str == "" || str == " ")
    {
        tell_object(TP,"Syntax: testcharacter <target>");
        return 1;
    }

    if(!objectp(ob = find_player(str)))
    {
        tell_object(TP,"Can't find a player named "+str+".");
        return 1;
    }

    ob->set("test_character",1);
    ob->set("last done",50);
    ob->set_hm_quest(1);
    ob->add_exp(100000000);
    ob->set_description("test desc");
    ob->set_property("no starve",1);

    tell_object(TP,"Setting character "+capitalize(str)+" as a test character, no need for trainers or the annoying hm quest...");
    return 1;
}

int help(string str)
{
    tell_object(TP,"Syntax: testcharacter <target>\n\n"
        "This makes test characters slightly less annoying, removes the need for trainers "
        "and for the high mortal quest.");
    return 1;
}