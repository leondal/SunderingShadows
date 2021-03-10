#include <std.h>
#include "../area_stuff.h"
#include "../dragon_words.h"

inherit TOMBHALL;
string *cur_words, passphrase, open;

void randomize_words()
{
    cur_words = ({});
    cur_words += ({MYWORDS[random(sizeof(MYWORDS))]});
    cur_words += ({MYWORDS[random(sizeof(MYWORDS))]});
    cur_words += ({MYWORDS[random(sizeof(MYWORDS))]}); 
    if(objectp(TO)) tell_room(TO, "%^BOLD%^%^WHITE%^The symbols suddenly and rapidly change before your very eyes!%^RESET%^");
}

int query_open_or_closed() { return open; }

string hroom() { return ELROOMST + "4_19.c"; }

void open_room()
{
    if(!objectp(TO)) return;
    if(!open)
    {
        tell_room(TO, "%^BOLD%^%^BLACK%^A loud grating sound echoes off of the ebon stones "+
        "as one of them slides down into the floor revealing an %^BOLD%^%^WHITE%^"+
        "opening%^BOLD%^%^BLACK%^ on the west wall!%^RESET%^");
        add_exit(ELROOMST+"4_19", "west");   
        open = 1;
        hroom()->open_room(); 
        return;
    }
}

void close_room()
{   
    if(!objectp(TO)) return;
    if(open)
    {
        tell_room(TO, "%^BOLD%^%^BLACK%^A loud grating sound echoes off of the ebon stones "+
        "as one of them slides up from the floor, closing the %^BOLD%^%^WHITE%^"+
        "opening%^BOLD%^%^BLACK%^ on the west wall!%^RESET%^");
        remove_exit("west");
        open = 0;      
        hroom()->close_room();
    }
}



void create()
{
    ::create();
    set_exits(([
        "north" : ELROOMST + "4_9",
        //"northeast" : ELROOMST + "3_1",
        //"east" : ELROOMST + "4_9",
        //"southeast" : ELROOMST + "3_3",
        "south" : ELROOMST + "4_11",  
        //"southwest" : ELROOMST + "3_2",
        //west" : ELROOMST + "4_8",
        //"northwest" : ELROOMST + "3_9",        
    ]));
    
    passphrase = "nif wer idol";
    
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ A series of symbols have been inscribed on the west wall here.%^RESET%^");
    add_item(({"symbols", "west wall", "series of symbols", "series"}), (:TO, "series_describe":));
    randomize_words();  
    open = 0;
}

string series_describe()
{
    string ret, def;
    int comp, x;
    def = "%^BOLD%^%^WHITE%^These strange symbols look like a language of some sort. You are not sure which language or if they "+
        "actually mean anything at all. However, there are three sets of symbols inscribed into the western wall.\n\n";
    if(!objectp(TP)) ret = def;    
    else
    {
        //comp = (int)TP->query_skills("spellcraft") + (int)TP->query_skills("academics");
        if(comp >= 45)
        {
            ret = "%^BOLD%^%^WHITE%^These strange symbols look like they were written in the draconic language. You are not sure by "+
            "looking at them exactly what they mean, however, you sense that it is important. There are three sets of them inscribed into the western wall.\n\n";
        }
        else ret = def;
    }
    for(x = 0;x < sizeof(cur_words);x++)
    {
        ret += "\n  %^BOLD%^%^CYAN%^"+arrange_string(ROMANSYMBOLS[x], 4)+":  "+ arrange_string(capitalize(cur_words[x]), 25);
        continue;
    }
    ret += "\n\n%^BOLD%^%^WHITE%^You have a feeling that touching any of the symbols might somehow change them. Beneath the symbols is what appears to be a blank "+
    "square, it almost reminds you of a button that you could push.";
    return ret;    
}

void init()
{
    ::init();
    add_action("touch_act", "touch");
    add_action("will_act", "will");
    add_action("push_act", "push");
}

int push_act(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(str != "button" && str != "square" && str != "blank square") return 0;
    
    tell_object(TP, "%^BOLD%^%^WHITE%^You reach out and push the %^BOLD%^%^CYAN%^"+str+".%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ reaches out and pushes the %^BOLD%^%^CYAN%^"+
    str+".%^RESET%^", TP);
    
    if(passphrase == implode(cur_words, " "))
    {
        if(open) close_room();
        else if(!open) open_room();
    }
    return 1;    
}

int will_act(string str)
{
    string thisword, thissymbol, num, curword;
    int x;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(sscanf(str, "%s to %s", thissymbol, thisword) != 2)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You must will '%^BOLD%^%^CYAN%^symbol 1 to word"+
        "%^BOLD%^%^WHITE%^' in order to change the symbol.%^RESET%^");
        return 1;
    }
    
    if(thissymbol == "symbol 1" || thissymbol == "first symbol") { x = 0; num = "first"; }
    else if(thissymbol == "symbol 2" || thissymbol == "second symbol") { x = 1; num = "second"; }
    else if(thissymbol == "symbol 3" || thissymbol == "third symbol") { x = 2; num = "third"; }
    else 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You must will '%^BOLD%^%^CYAN%^symbol 1, symbol 2, or "+
        "symbol 3 to word%^BOLD%^%^WHITE%^' in order to change it.%^RESET%^");
        return 1;
    }
    
    if(member_array(thisword, MYWORDS) == -1)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^"+capitalize(thisword)+" is not a word that you can "+
        "will "+thissymbol+" to.%^RESET%^");
        return 1;
    }
    curword = cur_words[x];
    cur_words[x] = thisword;
    tell_object(TP, "%^BOLD%^%^WHITE%^You will the "+num+" symbol to change and watch in awe as it "+
    "changes from '%^BOLD%^%^CYAN%^"+curword+
    "%^BOLD%^%^WHITE%^' to '%^BOLD%^%^CYAN%^"+thisword+"%^BOLD%^%^WHITE%^'!%^RESET%^");
    
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ stares at the "+num+" symbol and you watch in awe as it "+
    "changes from '%^BOLD%^%^CYAN%^"+curword+"%^BOLD%^%^WHITE%^' to '%^BOLD%^%^CYAN%^"+
    thisword+"%^BOLD%^%^WHITE%^'!%^RESET%^", TP);
    return 1;    
}


int touch_act(string str)
{
    string *tmp, thisword, num;
    int x;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(str == "symbol" || str == "symbols")
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Which symbol do you want to try touching? Symbol 1, symbol 2, or symbol 3.%^RESET%^");
        return 1;
    }
    if(str == "symbol 1" || str == "first symbol") { x = 0; num = "first"; }
    else if(str == "symbol 2" || str == "second symbol") { x = 1; num = "second"; }
    else if(str == "symbol 3" || str == "third symbol") { x = 2; num = "third"; }
    else return 0;
    tmp = MYWORDS;
    tmp -= ({cur_words[x]});
    thisword = cur_words[x];
    cur_words[x] = tmp[random(sizeof(tmp))];
    tell_object(TP, "%^BOLD%^%^WHITE%^You touch the "+num+" symbol and watch in awe as it changes from '%^BOLD%^%^CYAN%^"+
    thisword+"%^BOLD%^%^WHITE%^' to '%^BOLD%^%^CYAN%^"+cur_words[x]+"%^BOLD%^%^WHITE%^'!%^RESET%^");
    
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ touches the "+num+" symbol and you watch in awe as it changes from '%^BOLD%^%^CYAN%^"+
    thisword+"%^BOLD%^%^WHITE%^' to '%^BOLD%^%^CYAN%^"+cur_words[x]+"%^BOLD%^%^WHITE%^'!%^RESET%^", TP);
    
    if(roll_dice(1, 20) > 10) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You sense that if you knew a specify word for the "+num+" symbol that you could '%^BOLD%^%^CYAN%^will "+
        "the "+num+" symbol to%^BOLD%^%^WHITE%^' that word.%^RESET%^");
    }
    return 1;
}
