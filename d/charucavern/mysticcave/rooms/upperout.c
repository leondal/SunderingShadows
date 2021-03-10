#include <std.h>
#include "../inherits/area_stuff.h"
inherit UPPER;
object *moving;
void create() 
{
    ::create();

    set_exits((["south" : CRROOMS+"upper1"]));		
   // set_climb_exits((["climb": ({OE, 20, 30, 100}) ]));
   // set_fall_desc("%^BOLD%^%^RED%^You stumble and fall landing hard on the floor of the cavern!%^RESET%^");
    
   // add_item("hole", "%^BOLD%^%^BLACK%^This small hole has been hollowed out by something or "+
   // "someone in the ceiling of the cavern, near the top of the north wall. You have no way of knowing "+
    //"where it leads to as it seems to be "
}

void init()
{
    ::init();
    add_action("say_function","say");
}

void move_them_out()
{
    object curTarg;
    int x;
    if(!objectp(TO)) return;
    if(!pointerp(moving)) return;
    if(!sizeof(moving)) return;
    for(x = 0;x < sizeof(moving);x++)
    {
        if(!objectp(moving[x])) continue;
        curTarg = moving[x];
        if(!objectp(environment(curTarg))) continue;
        if(environment(curTarg) != TO) continue;
        
        
        tell_object(curTarg, "%^RESET%^%^CYAN%^A distorted voice whispers to you: %^RESET%^"+
        "we hear your pleas.... give us a moment... and you'll be safely out of there soon... "+
        "yeah, safely out, just hold a moment.");
        
        if(sizeof(curTarg->query_attackers()))
        {
            tell_object(TP, "%^RESET%^%^CYAN%^A distorted voice whispers to you: %^RESET%^"+
            "we can't pull you out!!!! something is interfering with our attempts!!");
            continue;
        }
        tell_room(TO, "%^BOLD%^%^WHITE%^An faint outline suddenly surround "+
        curTarg->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", curTarg);
        
        tell_object(curTarg, "%^BOLD%^%^WHITE%^You suddenly feel a force pulling at you and you "+
        "feel gravely ill......");
        
        curTarg->set_paralyzed(25, "%^BOLD%^%^GREEN%^You feel gravely ill...");
        
        tell_object(curTarg, "%^RESET%^%^CYAN%^A distorted voice whispers to you: %^RESET%^"+
        "Oh... oh I see.... almost got you out of there, hang on just a second longer....");
        
        tell_object(curTarg, "%^BOLD%^%^WHITE%^You suddenly feel as if you are suddenly "+
        "%^BOLD%^%^RED%^RIPPED%^BOLD%^%^WHITE%^ through a tiny hole!%^RESET%^");
        
        curTarg->set_paralyzed(20, "%^BOLD%^%^RED%^You are recovering from the immense pain!%^RESET%^");
        
        tell_object(curTarg, "%^BOLD%^%^WHITE%^You suddenly find yourself somewhere else!%^RESET%^");
       
        curTarg->move_player(OE);
        
        tell_object(curTarg, "%^RESET%^%^CYAN%^A distorted voice whispers to you: %^RESET%^"+
        "See!! There you go, out safe and sound!");
        continue;
    }
    moving = ({});
    return;
}


int say_function(string str) 
{
    int flag, i;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if((string)TP->query("last say") == str) 
    {
        return 0;
    }
    if(strsrch(str, "help") != -1 || strsrch(str, "get me out") != -1 
    || strsrch(str, "take me home") != -1 || strsrch(str, "take me out of here") != -1
    || strsrch(str, "bring me home") != -1 || strsrch(str, "go home") != -1
    || strsrch(str, "me home") != -1)
    {
        if(!sizeof(moving)) moving = ({TP});
        else moving += ({TP});
        call_out("move_them_out", 2);
        return 0;
    }    
    return 0;
}


