#include <std.h>
#include "../arctic.h"

inherit CROOM;

void make_creatures();
void find_stuff();
void searchroom();

int searched;

void create()
{
    make_creatures();
    set_repop(50);

    ::create();
    set_name("Ice Cave");
    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
    set_property("indoors", 1);
    set_property("light", -1);
    set_climate("arctic");
    
    set_short("%^BLUE%^Inside an icy cave.%^RESET%^");
    set_long( (: TO,"long" :) );
    set_items(([
                "ice" : "%^RESET%^%^BOLD%^The gray stone walls of "
                "the cave are covered in a thin layer of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.%^RESET%^",
                
                ({"pool","pools","water"}) : "%^RESET%^%^BOLD%^"
                "Small %^RESET%^%^BLUE%^pools %^RESET%^%^BOLD%^of "
                "%^BLUE%^wat%^RESET%^e%^BLUE%^r %^RESET%^%^BOLD%^have "
                "been formed in places where the moisture has not "
                "been frozen.%^RESET%^",
                
                ({"stalagmite","stalagmites","stalactite","stalactites"}) : 
                "%^RESET%^%^BOLD%^The stone %^BOLD%^%^BLACK%^stalagmites "
                "%^RESET%^%^BOLD%^struggle their way up from the floor of "
                "the cave to reach those %^BOLD%^%^BLACK%^stalactites %^RESET%^%^BOLD%^"
                "that are extending ever downwards in their centuries long "
                "journey to meet in the middle.%^RESET%^",
                
                ({"stone","granite","gray stone"}) : "%^RESET%^%^BOLD%^"
                "The smooth %^BOLD%^%^BLACK%^stone%^RESET%^%^BOLD%^ "
                "of the mountain cave can been seen through the thin layer of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.%^RESET%^",
                
                "icicles" : "%^RESET%^%^BOLD%^A few "
                "i%^RESET%^%^CYAN%^c%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^c"
                "%^RESET%^%^BOLD%^l%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^s "
                "cling to the %^BOLD%^%^BLACK%^stone%^RESET%^%^BOLD%^ "
                "in various places.  Most small and wet, with %^RESET%^water%^BOLD%^ "
                "dripping from the tips into the %^RESET%^%^BLUE%^"
                "shallow pools %^RESET%^%^BOLD%^around "
                "the cave.%^RESET%^",
             ]));                

    set_smell("default", "The scent of water and ice mix in the air.");
    set_listen("default", "Echoing splashes of water can be heard throughout the cave.");

    searched = 0;

    set_search("default",  (: TO, "searchroom" :) );
    set_search("ice",      (: TO, "find_stuff" :) );
    set_search("pools",    (: TO, "find_stuff" :) );
    set_search("stone",    (: TO, "find_stuff" :) );

    set_exits(([
      "out"   : ROOMS"cave",
             ]));

}

void make_creatures()
{
   int monsters;
   monsters = has_mobs();
   if(!monsters) 
   {
        if(mons) { mons = ([]); }
        
        switch(random(120))
        {
        case 0..30:
            break;
        case 31..40:
            set_monsters( ({MON"wolf.c"}),({random(2)+1}) );
            break;
        case 41..50:
            set_monsters( ({MON"yeti.c"}),({1}) );
            break;
        case 51..60:
            set_monsters( ({MON"yetis.c"}),({random(2)+1}) );
            break;
        case 61..75:
            set_monsters( ({MON"yeti.c"}),({random(4)+1}) );
            break;
        case 76..85:
            set_monsters( ({MON"winterwolf.c"}),({random(2)+1}) );
            break;
        case 86..95:
            set_monsters( ({MON"mammoth.c"}),({1}) );
            break;
        case 96..99:
            set_monsters( ({MON"cryohydra.c"}),({1}) );
            break;
        case 100..119:
            break;
        }
   }
   return;
}

void init()
{
    ::init();

}

void reset()
{
    ::reset();
    if(!random(3)) { searched = 0;}
    return;
}

void searchroom()
{

    tell_object(TP,"%^BOLD%^Your attention is drawn to the "
        "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e"
        "%^RESET%^%^BOLD%^, the shallow %^RESET%^%^BLUE%^pools%^RESET%^%^BOLD%^ "
        "of water, and the %^BOLD%^%^BLACK%^stone%^RESET%^%^BOLD%^ walls of the "
        "cave.%^RESET%^");
    return;
}

void find_stuff()
{
    object ob,ob1,ob2;
    int i;

    if(searched == 1) { tell_object(TP, "It looks like someone already searched here."); return;}

    if(!random(10))
    {
        switch(random(1000))
        {
        case 0..350:
            if(!random(2)) ob = new("/d/common/obj/potion/det_invis");
                else ob = new("/d/common/obj/potion/invisible");
            ob->move(TO);
            tell_object(TP,"%^BOLD%^You search carefully and find a potion!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;    
        case 351..500:
            for(i=0;i<random(3)+2;i++)
            {
                ob = new(OBJ"gems");
                ob->move(TO);
                if(i>100){break;}
            }
            tell_object(TP,"%^BOLD%^You search carefully and find some gems!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;        
        case 501..700:
            ob = new(OBJ"scroll_case");
            ob->move(TO);
            tell_object(TP,"%^BOLD%^You search carefully and find a scroll case!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;        
        case 701..800:
            ob = new("/d/magic/safe_scroll");
            if(!random(3)) 
            { 
                ob1 = new("/d/magic/safe_scroll");
                ob1->set_spell(random(3)+3);
                ob1->move(TO);
            }
            ob->set_spell(random(3)+3);
            ob->move(TO);
            tell_object(TP,"%^BOLD%^You search carefully and find a scroll!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;        
        case 801..875:
            ob = new("/d/magic/scroll");
            ob->set_spell(random(3)+3);
            ob->move(TO);
            tell_object(TP,"%^BOLD%^You search carefully and find a scroll!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;
        case 876..935:
            ob1 = new(OBJ"scroll_case");
            if(!random(3)) ob2 = new("/d/magic/scroll"); 
                else ob2 = new("/d/magic/safe_scroll"); 
            ob2->set_spell(random(6)+3);
            ob2->move(ob1);
            ob1->move(TO);
            tell_object(TP,"%^BOLD%^You search carefully and find a scroll case!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;
        case 936..984:
            ob = new(OBJ"lesserjade");
            ob->move(TO);
            tell_object(TP,"%^BOLD%^You search carefully and find a ring!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;
        case 985..999:
            ob = new("/d/common/obj/special/sp_randwpn");
            ob->move(TO);
            tell_object(TP,"%^BOLD%^You search carefully and find a weapon!%^RESET%^");
            tell_room(ETP, "%^BOLD%^"+TP->QCN+" searches around and finds something.%^RESET%^",TP);
            break;
        }
        searched = 1;
        return;
    }

    tell_object(TP, "%^BOLD%^You find nothing of interest.%^RESET%^");
    tell_room(ETP, "%^BOLD%^"+TP->QCN+" takes a quick look around but doesn't find anything.%^RESET%^",TP);
    searched = 1;
    return;
}


string long(string str)
{
    return("%^RESET%^%^BOLD%^The cave is somewhat dark here, the "
           "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
           "%^RESET%^%^BOLD%^is not as thick and the %^BOLD%^%^BLACK%^"
           "stone %^RESET%^%^BOLD%^of the mountain is more apparent.  "
           "There are many %^RESET%^%^BLUE%^pools of water %^RESET%^%^BOLD%^"
           "here, and the air is somewhat warm although not comfortably "
           "so.  A few stray "
           "i%^RESET%^%^CYAN%^c%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^c"
           "%^RESET%^%^BOLD%^l%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^s "
           "cling to the walls and gray slush "
           "is piled in places on the "
           "floor.  Smooth stone %^BOLD%^%^BLACK%^stalagmites "
           "%^RESET%^%^BOLD%^and %^BOLD%^%^BLACK%^stalactites "
           "%^RESET%^%^BOLD%^adorn the room, some running the "
           "entire length from floor to ceiling, touching in "
           "the middle.");
}

