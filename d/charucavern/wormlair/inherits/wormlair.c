#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include "/d/common/common.h"

inherit CROOM;
int larva = 0, searched;
mixed WhoIsSmashing;

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
    "makeshift nest you realize that it appears to be empty.%^RESET%^";
}

void create() 
{
    ::create();
    set_name("A massive chamber of stone and earth");
    set_short("%^BOLD%^%^MAGENTA%^A massive chamber of %^BOLD%^%^WHITE%^stone"+
    "%^BOLD%^%^MAGENTA%^ and %^RESET%^%^ORANGE%^earth%^RESET%^");

    set_long("%^BOLD%^%^MAGENTA%^This massive chamber has been burrowed out from "+
    "a composition of %^BOLD%^%^WHITE%^stone%^BOLD%^%^MAGENTA%^ and %^RESET%^%^ORANGE%^"+
    "earth%^BOLD%^%^MAGENTA%^. It is much more difficult to determine the origins of "+
    "this chamber, as it is much larger and almost perfectly circular. The walls, ceiling, and "+
    "floor are perfectly smooth. Gone is the lingering filth that has been "+
    "present in the rest of the cavern. It is almost as if there has been a "+
    "conscious effort into maintaining some measure of order and cleanliness in "+
    "this chamber. The piles of dirt and rock have been pushed neatly into the "+
    "center of the chamber and have been arranged in what you believe is a "+
    "makeshift %^RESET%^%^ORANGE%^nest%^BOLD%^%^MAGENTA%^ of some sort. You believe "+
    "that this chamber is more structurally sound than the rest of the cavern.%^RESET%^");

    set_smell("default","\nAn odor that reminds you of unwashed filth lingers here.");
    
    set_listen("default","The sound of earth rumbling fills the air.");				
	
    set_items(([
    
       ({"wall", "walls", "floor", "ceiling", "chamber", 
       "stone", "earth"}) : "%^RESET%^%^ORANGE%^This chamber is more structurally "+
       "sound than the rest of the cavern, though it is still formed from the same "+
       "composition of stone and earth. The walls, floor, and ceiling are "+
       "perfectly smooth, as if something has spent a good deal of time "+
       "creating it. This makes it much more difficult to determine the "+
       "origins of this chamber. There has also been a conscious effort "+
       "made to maintain some measure of order and cleanliness here, as most of "+
       "the filth present in the rest of the cavern is missing.%^RESET%^",
       
       ({"piles", "rocks", "stones", "piles of rock and stone"}) : "%^RESET%^%^WHITE%^"+
       "The piles of dirt and rock have been pushed neatly into the "+
       "center of the chamber and have been arranged in what you believe is "+
       "a makeshift %^RESET%^%^ORANGE%^nest%^RESET%^%^WHITE%^.%^RESET%^",
       
       ({"nest", "makeshift nest", "larva", "moving larva"}) : (:TO, "nest_check":),
       
    ]));
      
    set_property("light",-2);
    set_property("indoors",1);

    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
	
    searched = random(3);
    
    set_search("default", "%^RESET%^%^ORANGE%^You think that the "+
    "piles of dirt and rocks could possibly hide something.%^RESET%^");
    
    set_search("nest", (:TO, "mySearch":));
    set_search("makeshift nest", (:TO, "mySearch":));    
    WhoIsSmashing = ({});
}

void allow_search() { searched = 0; }

void init()
{
    ::init();
    add_action("smash_act", "smash");
    add_action("stop_act", "stop");
}

void burn_me(object who)
{
    if(!objectp(who)) return;
    if(!objectp(TO)) return;
    tell_object(who, "%^BOLD%^%^GREEN%^Your feet begin burning painfully "+
    "as you realize too late that the thick slime is acidic!%^RESET%^");
    
    if(!who->query_invis())
    {
        tell_room(TO, who->QCN+"%^BOLD%^%^GREEN%^'s feet are burned by the "+
        "thick slime!%^RESET%^", who);
    }    
    who->cause_typed_damage(who, 0, roll_dice(1, 10), "acid");
    return;   
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
        who->add_exp(800);
        larva--;
        if(!random(3)) call_out("burn_me", 6, who);
        if(larva < 0) larva = 0;
    }
    if(!larva)
    {
        tell_object(who, "%^BOLD%^%^CYAN%^There are no more larva in the nest!%^RESET%^");
        if(member_array(who, WhoIsSmashing) != -1) WhoIsSmashing -= ({who});
        searched = 0;
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

int stop_act(string str)
{
    if(!str) return 0;
    if(str != "smashing" && str != "smash") return 0;
    if(!objectp(TP)) return 0;
    if(member_array(TP, WhoIsSmashing) == -1) return 0;
    
    if(member_array(TP, WhoIsSmashing) != -1) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You quit trying to smash the larva.%^RESET%^");
        if(!TP->query_invis()) tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ quits trying to smash the larva.%^RESET%^");
        WhoIsSmashing -= ({TP});
        return 1;
    }
    return 0;
}

int smash_act(string str)
{    
    int amt;
    if(!str) return 0;
    if(str != "larva" && str != "larvas") return 0;
    if(!objectp(TP)) return 0;
    amt = 4 + random(5);
   
    if(!larva) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You approach the makeshift nest and realize it is "+
        "already empty.%^RESET%^");
        return 1;
    }
    if(present("wormlairsaideguardxx", TO))
    {
        tell_object(TP, "%^RESET%^%^MAGENTA%^The purple worm will not let you near the larva!%^RESET%^");
        return 1;
    }
    if(present("saidewormkeeperhowne", TO))
    {
        tell_object(TP, "%^RESET%^%^MAGENTA%^Howne will not let you near the larva!%^RESET%^");
        return 1;
    }
    if(member_array(TP, WhoIsSmashing) != -1) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You are already attempting to smash larva!%^RESET%^");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^You approach the makeshift nest and begin attempting to "+
    "smash "+str+"! You can <%^RESET%^stop smashing%^BOLD%^%^WHITE%^> if you ever get tired of it.%^RESET%^");
    
    if(!TP->query_invis()) 
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ approaches the makeshift nest and "+
        "begins attempting smash "+str+"!%^RESET%^", TP);
    }
    WhoIsSmashing += ({TP});
    call_out("keep_smashing", 4, TP, amt);        

    return 1;
}


void test() { return WORMTREAS; }

int mySearch(string str)
{
    object ob;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(larva)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^The larva get in the way of your attempt to "+
        "search the "+str+"!%^RESET%^");
        return 1;
    }
    if(searched) 
    {
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+" but find nothing "+
        "of interest.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ searches the "+str+
            "carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }	
    ob = test()->find_stuff();
    if(!objectp(ob)) 
    {
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+" but find nothing "+
        "of interest.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ searches the "+str+
            "carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }	
    tell_object(TP, "%^RESET%^%^MAGENTA%^You search the "+str+" carefully and "+
    "manage to find "+ob->query_short()+"%^RESET%^%^MAGENTA%^!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^RESET%^%^MAGENTA%^ searches the "+str+" carefully and "+
        "manages to find "+ob->query_short()+"%^RESET%^%^MAGENTA%^!%^RESET%^", TP);
    }
    if(ob->move(TP) != MOVE_OK)
    {
        tell_object(TP, "%^BOLD%^%^RED%^You drop "+ob->query_short()+"%^BOLD%^%^RED%^!%^RESET%^");
        ob->move(TO);
    }
    searched = 1;
    
    return 1;
}

void reset()
{
    object Mon;
    ::reset();
    searched = random(3);
    if(!random(2))
    {
        larva = 10 + random(11);
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
    
}
