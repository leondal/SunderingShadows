#include <std.h>
#include "arctic.h"

inherit WATER;

void create(){::create();}

int say_func(string str)
{
    if(!TP->query_true_invis())
    {
        tell_object(TP,"%^CYAN%^You open your mouth to speak and many bubbles escape.  "
            "You realize it will be impossible to speak underwater.%^RESET%^");
        tell_room(ETP,"%^CYAN%^"+TP->QCN+" opens "+TP->QP+" mouth as if to speak and "
            "many bubbles come out instead.%^RESET%^",TP);
        return 1;
    }
    return 0;
}

int whisper_func(string str)
{   
    if(!TP->query_true_invis())
    {
        tell_object(TP,"%^CYAN%^You lean in to whisper and tiny bubbles come out instead.  "
            "You realize it will be impossible to whisper underwater.%^RESET%^");
        tell_room(ETP,"%^CYAN%^"+TP->QCN+" opens "+TP->QP+" mouth as if to speak and "
            "very tiny bubbles come out instead.%^RESET%^",TP);
        return 1;
    }
    return 0;
}   

int yell_func(string str)
{
    int LANG,GRAM,language,grammar;

    if(!interactive(TP)) { return 1; }
    
    LANG = TP->query_lang(TP->query_spoken());
    GRAM = TP->querry_grammar(TP->query_spoken());
    language = (LANG*50)/100;
    grammar = (GRAM*50)/100;

    if(!TP->query_true_invis())
    {
        TP->set_lang(TP->query_spoken(), language);
        TP->set_grammar(TP->query_spoken(), grammar);

        tell_object(TP,"%^CYAN%^You yell into the water but realize your words "
            "will be difficult to understand.%^RESET%^");
        tell_room(ETP,"%^CYAN%^"+TP->QCN+" opens "+TP->QP+" mouth and yells, the "
            "water garbles the sound making it difficult to understand.%^RESET%^",TP);
        this_player("/cmds/mortal/_yell.c"->cmd_yell(str));
        TP->set_lang(TP->query_spoken(), LANG);
        TP->set_grammar(TP->query_spoken(), GRAM);
        return 1;
    }

    TP->set_lang(TP->query_spoken(), LANG);
    TP->set_grammar(TP->query_spoken(), GRAM);
    this_player("/cmds/mortal/_yell.c"->cmd_yell(str));
    return 1;
}

int charge_func(string str)
{   
    if(!TP->query_true_invis())
    {
        tell_object(TP,"%^MAGENTA%^Your horse is underwater, it "
            "would be impossible to charge here.%^RESET%^");
        tell_room(ETP,"%^MAGENTA%^"+TP->QCN+" looks as if "+TP->QS+" is about "
            "to spur "+TP->QP+" horse into a charge but changes "+TP->QP+" mind.%^RESET%^",TP);
        return 1;
    }
    tell_object(TP,"%^MAGENTA%^Your horse is underwater, it "
        "would be impossible to charge here.%^RESET%^");
    return 1;
}   

void init() 
{
    ::init();
    add_action("yell_func", "yell");
    add_action("say_func", "say");
    add_action("whisper_func", "whisper");
    add_action("light", "light_lantern");
    add_action("charge_func", "charge");
    return;
}


