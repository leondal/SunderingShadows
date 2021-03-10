#include <std.h>
#include <move.h>
#include "../inherits/area_stuff.h"
inherit ROOM;
int searched;
void create() 
{
    ::create(); 
    set_exits(([
       "south" : MROOMS"hidden27",       
    ] ));    
    set_property("light",-1);
    set_property("indoors",0);
    set_property("no teleport", 1);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("chamber within the mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Chamber within the mausoleum of the damned%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^You find yourself in an ancient chamber. It is "+
    "constructed entirely from a %^RESET%^%^RED%^dark red%^BOLD%^%^BLACK%^ stone "+
    "that radiates a powerful and old %^BOLD%^%^CYAN%^magic%^BOLD%^%^BLACK%^. "+
    "It looks as if at one point the chamber continued in all directions, but "+
    "a large portion of the %^RESET%^%^RED%^ceiling%^BOLD%^%^BLACK%^ has collapsed. "+
    "The ceiling now meets with the floor and forms a northern, eastern, and "+
    "western wall. The rest of the floor is mostly smooth and bare and you think that "+
    "in the past this chamber was quite ornate and well-kept, but that time "+
    "has gone. The only thing that seems out of place here is a %^RESET%^%^ORANGE%^"+
    "wooden desk%^BOLD%^%^BLACK%^ that itself looks as ancient as the chamber. It is "+
    "mostly decayed now and almost entirely caved in. An opening on the "+
    "original southern wall provides an exit from the chamber.%^RESET%^");
    
    set_listen("default","Eerie moans and groans echo all around you.");
    set_smell("default","The aroma of death and decay hangs heavily here."); 
     
    set_items(([
       ({"structure", "chamber"}) : "%^RESET%^%^RED%^This ancient chamber "+
        "has long since been abandoned. At one in time you think that it "+
        "must have been quite grand and well-kept. However, that time has gone. "+
        "A large portion of the ceiling has collapsed and meets with the floor "+
        "forming a northern, eastern, and western wall. The rest of the floor is "+
        "quite smooth and exceptionally bare, excluding a %^RESET%^%^ORANGE%^"+
        "wooden desk%^RESET%^%^RED%^ that seems both out of place and "+
        "as ancient as the chamber itself.%^RESET%^",
       ({"walls", "eastern wall", "northern wall", 
       "western wall", "ceiling"}) : "%^RESET%^%^RED%^A large portion of the ceiling "+
       "has collapsed and formed northern, eastern, and western walls which prevent "+
       "exploring the chamber any further. The rest of the ceiling looks to still be sturdy. "+
       "Only one wall, the southern wall looks intention and an opening in it provides the "+
       "one exit from this chamber.%^RESET%^", 
       ({"floor"}) : "%^RESET%^%^RED%^The floor here is smooth and bare, except "+
       "for an ancient %^RESET%^%^ORANGE%^wooden desk%^RESET%^%^RED%^ that has seen "+
       "better days.%^RESET%^",        
       ({"desk", "wooden desk"}) : "%^RESET%^%^ORANGE%^This is the remains of a "+
       "once grand desk. You can tell that it was crafted from the highest quality "+
       "wood. However, it has not survived the relentless onslaught of time. You could "+
       "perhaps search through it, but the possibility of finding anything interesting "+
       "is faint.%^RESET%^",
    ] ));        
    set_search("default", "%^RESET%^%^ORANGE%^The desk looks interesting.%^RESET%^");
    set_search("desk", (:TO, "desk_search":));
}

int desk_search()
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    
    if(searched)
    {
        tell_object(TP, "%^RESET%^%^ORANGE%^You search through the "+
        "remains of the decaying desk but find nothing of interest.%^RESET%^");
        tell_room(TO, TPQCN+"%^RESET%^%^ORANGE%^ searches through the "+
        "remains of the decaying desk but doesn't seem to find anything of interest.%^RESET%^", TP);
        return 1;
    }
    tell_object(TP, "%^RESET%^%^ORANGE%^You search through the remains "+
    "of the decaying desk and find a leather bound tome.%^RESET%^");
    tell_room(TO, TPQCN+"%^RESET%^%^ORANGE%^ searches through the remains of the "+
    "decaying desk and pulls out a leather bound tome.%^RESET%^", TP);
    ob = new(MOBJ"devar_tome");
    if(ob->move(TP) != MOVE_OK)
    {
        tell_object(TP, "%^RESET%^%^ORANGE%^You can't carry the tome and "+
        "drop it!%^RESET%^");
        tell_room(TO, TPQCN+"%^RESET%^%^ORANGE%^ drops the tome!%^RESET%^", TP);
        ob->move(TO);
    }
    searched = 1;
    return 1;    
}
