//meadow.c - inherited room for meadow with rats, snakes, wild dogs 
#include <std.h>
#include "../meadow.h"
inherit CROOM;

object ob;
void pick_critters();

void create(){
   pick_critters();
   set_repop(60);
   ::create();
   set_name("An overgrown meadow");
   set_property("light",2);
   set_property("no teleport",1);
   set_short("%^BOLD%^%^GREEN%^An overgrown meadow%^RESET%^");
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_long("%^BOLD%^%^GREEN%^An overgrown meadow\nYou've entered an overgrown meadow.  "+
   "Beneath your feet there is a path that looks as if it might have once been traveled "+
   "frequently, however, nature has since taken over. There are clumps of %^YELLOW%^w%^MAGENTA%^"+
   "i%^YELLOW%^ld fl%^MAGENTA%^o%^YELLOW%^w%^MAGENTA%^e%^YELLOW%^rs %^GREEN%^and thick stalks "+
   "of %^RESET%^%^GREEN%^weeds%^BOLD%^%^GREEN%^ growing about chaotically. There are areas of "+
   "%^RESET%^%^ORANGE%^soil%^BOLD%^%^GREEN%^ visible, as if animals have bedded down "+
   "frequently through the meadow.%^RESET%^");

   set_smell("default","The smell of wet animal mixes with nature.");
   set_listen("default","A loud wind blows constantly through the meadows.");
   
   set_items( ([
    ({"path", "overgrown path", "nature"}) : "%^RESET%^%^GREEN%^This path may have once been "+
    "regularly traveled, however, nature has long since taken over. It is barely visible now.%^RESET%^", 
    ({"wildflowers", "weeds", "clumps", "stalks"}) : "%^RESET%^%^GREEN%^Wildflowers and thick stalks of weeds "+
    "grow up chaotically through this meadow. Some of them are matted down as if animals "+
    "have used them frequently as bedding.%^RESET%^",
    ({"bedding", "soil"}) : "%^RESET%^%^ORANGE%^These visible segments of soil look as if they "+
    "were once also filled with weeds or flowers, but animals have used them as bedding frequently "+
    "enough to wear away the natural growth. You believe that the soil is soft enough in places that "+
    "you could %^BOLD%^dig%^RESET%^%^ORANGE%^ into it, if you wanted.%^RESET%^",
   ]) );
}

void init()
{
    ::init();
    add_action("dig_em", "dig");
}

int dig_em(string str)
{
    string myRoom;
    object myOb;
    int flag;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    myRoom = TP->query("NewbieMeadowRoom");
    
    tell_room(TO, TPQCN+"%^RESET%^%^ORANGE%^ finds a soft spot of soil and digs a "+
    "small hole.%^RESET%^", TP);
    
    tell_object(TP, "%^RESET%^%^ORANGE%^You find a soft spot of soil and dig a "+
    "small hole.%^RESET%^");
    
    if(!stringp(myRoom)) flag = 0;
    else if(myRoom != base_name(TO) + ".c") flag = 0;
    else flag = 1;
    if(objectp(myOb = present("newbiemeadowob", TP)))
    {
        if((string)myOb->query_belongs_to() == (string)TPQN) flag = 0;
        else flag = 1;
    }
    if(!flag) 
    {
        tell_room(TO, TPQCN+"%^RESET%^%^ORANGE%^ doesn't seem to find anything worthwhile.%^RESET%^", TP);
        tell_object(TP, "%^RESET%^%^ORANGE%^You find nothing worth keeping and give up digging.%^RESET%^");
    }
    if(flag)
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^GREEN%^ finds a small %^BOLD%^%^BLACK%^black%^BOLD%^%^GREEN%^ gem!%^RESET%^", TP);
        tell_object(TP, "%^BOLD%^%^GREEN%^You find a small %^BOLD%^%^BLACK%^black%^BOLD%^%^GREEN%^ gem!%^RESET%^");
        myOb = new(OBJS"newbie_gem");
        myOb->move(TP);
        myOb->set_belongs_to(TPQN);
    }
    return 1;
}



void reset() 
{
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
}

void pick_critters() 
{
    switch(random(9))
    {
       case 0: set_monsters(({MON"rat"}),({1 + random(2)}) ); break;
       case 1: set_monsters(({MON"snake"}),({1 + random(2)}) ); break;
       case 2: set_monsters(({MONS"dog"}),({1 + random(2)}) ); break;
    }
}
