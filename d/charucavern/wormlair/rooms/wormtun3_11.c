#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMLAIR;
int flag;

string nest_check()
{
    string tmp, tmp2;
    if(larva == 1) 
    {
        tmp = "is a"; 
        tmp2 = "it";
    }
    else
    {
        tmp = "are"; 
        tmp2 = "them";
    }
    if(larva) 
    {
        if(member_array(TP, WhoIsSmashing) == -1)
        {
            return "%^RESET%^%^ORANGE%^After carefully looking over the "+
            "makeshift nest you realize that there " +tmp+ " " +consolidate(larva, "larva")+
            " wiggling about in it. You could probably <%^BOLD%^%^RED%^smash%^RESET%^%^ORANGE%^>"+
            " "+tmp2+" if you wanted to.%^RESET%^";
        }
        else
        {
            return "%^RESET%^%^ORANGE%^You are in the makeshift nest attempting "+
            "to smash larva. There "+tmp+" " +consolidate(larva, "larva")+ 
            " still wiggling about in it. You could <%^BOLD%^%^RED%^stop smashing%^RESET%^%^ORANGE%^>"+
            " for now if you wanted to.";
        }
    }
    return "%^RESET%^%^ORANGE%^After carefully looking over the "+
    "makeshift nest you realize that it appears to be empty. You see an "+
    "opening directly in the center of it leading down into "+
    "%^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^.%^RESET%^";
}

void keep_smashing(object who, int amt)
{
    int dam;
    if(!objectp(who)) return;
    if(!objectp(TO)) return;
    if(TO != environment(who)) 
    {
        if(member_array(who, WhoIsSmashing) != -1) WhoIsSmashing -= ({who});
        tell_object(who, "%^BOLD%^%^RED%^You quit attempting to smash larva.%^RESET%^");
        return;
    }
    if(member_array(who, WhoIsSmashing) == -1) return;
    if(!larva)
    {
        tell_object(who, "%^BOLD%^%^CYAN%^There are no more larva in the nest!%^RESET%^");
        if(member_array(who, WhoIsSmashing) != -1) WhoIsSmashing -= ({who});
        return;
    }
    if(present("wormlairsaideguardxx", TO))
    {
        tell_object(who, "%^RESET%^%^MAGENTA%^The purple worm will not let you near the larva!%^RESET%^");
        if(member_array(who, WhoIsSmashing) != -1) WhoIsSmashing -= ({who});
        return;
    }  
    if(present("saidewormkeeperhowne", TO))
    {
        tell_object(who, "%^RESET%^%^MAGENTA%^Howne will not let you near the larva!%^RESET%^");
        if(member_array(who, WhoIsSmashing) != -1) WhoIsSmashing -= ({who});
        return;
    }
    
    if(!random(3))
    {
        tell_object(who, "%^BOLD%^%^RED%^You stomp and kick at the larva but fail "+
        "to smash it!%^RESET%^");
        if(!who->query_invis()) tell_room(TO, who->QCN+"%^BOLD%^%^RED%^ stomps and kicks at the "+
        "larva but fails to smash it!%^RESET%^", who);
    }
    else
    {
        tell_object(who, "%^BOLD%^%^GREEN%^You smash a larva and your feet are "+
        "covered in thick green slime!%^RESET%^");
        if(!who->query_invis()) tell_room(TO, who->QCN+"%^BOLD%^%^GREEN%^ smashes a larva and "+
        who->QP+" feet are covered in a thick green slime!%^RESET%^", who);
        larva--;
        who->add_exp(1000);
        if(!random(3)) call_out("burn_me", 6, who);
        if(larva < 0) larva = 0;
    }
    if(!larva)
    {
        tell_object(who, "%^BOLD%^%^CYAN%^There are no more larva in the nest but you now "+
        "notice an opening leading down into %^BOLD%^%^BLACK%^darkness%^RESET%^%^BOLD%^"+
        "%^CYAN%^!%^RESET%^");
        if(member_array(who, WhoIsSmashing) != -1) WhoIsSmashing -= ({who});
        searched = 1;
        set_climb_exits((["descend": ({WROOMS+"wormnar4_1", 20, 10, 100}) ]));
        set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
    
        add_item(({"opening", "passageway"}), "%^RESET%^%^ORANGE%^This opening "+
        "reveals a passageway of dirt and stone that goes down into "+
        "darkness. You could <%^RESET%^descend%^RESET%^%^ORANGE%^> into it "+
        "if you were brave enough to do so.%^RESET%^");
        flag = 1;
        return;
    }
    amt--;
    if(amt < 0) amt = 0;
    if(amt) call_out("keep_smashing", 4, who, amt);  
    else if(member_array(who, WhoIsSmashing) != -1) 
    {
        WhoIsSmashing -= ({who});
        tell_object(who, "%^BOLD%^%^WHITE%^You quit smashing larva for now.%^RESET%^");
        return;
    }
    return;    
}

void create() 
{
    ::create(); 
    set_exits((["southwest" : WROOMS + "wormtun3_10"]));	
    flag = 0;    
}

void reset()
{
    object Mon;
    ::reset();   
  
    if(flag == 0 || flag == 3)
    {      
        searched = 0;
        larva = 10 + random(11); 
        remove_item(({"opening", "passageway"}));
        set_climb_exits(([]));
        flag = 0;
        if(!present("saidewormkeeperhowne", TO))
        {
            new(WMON+"howne.c")->move(TO);
        }
        if(!present("greater purple worm 2", TO))
        {
            Mon = new(WMON+"greater_purple_worm");
            Mon->move(TO);
            Mon->set_speed(0);
            Mon->set_moving(0);
        }
        if(!present("greater purple worm 2", TO))
        {
            Mon = new(WMON+"greater_purple_worm");
            Mon->move(TO);
            Mon->set_speed(0);
            Mon->set_moving(0);
        }
    }
    else flag++;
}
