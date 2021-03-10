#include <std.h>
#include "../arctic.h"

inherit CROOM;

void make_creatures();
void find_stuff();
void searchroom();
void find_crystal();

int searched;
int pried;

void create()
{
    make_creatures();
    set_repop(50);

    ::create();
    set_name("Ice Cave");
    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
    set_property("indoors", 1);
    set_property("light", 1);
    set_climate("arctic");
    
    set_short("%^BLUE%^Inside an icy cave.%^RESET%^");
    set_long( (: TO,"long" :) );
    set_items(([
                "ice" : "%^RESET%^%^BOLD%^The walls of the cave "
                "seem to be several feet of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
                "%^RESET%^%^BOLD%^covering the smooth gray stone of the mountain.%^RESET%^",
                
                ({"pool","pools","water"}) : "%^RESET%^%^BOLD%^"
                "Small %^RESET%^%^BLUE%^pools %^RESET%^%^BOLD%^of "
                "%^BLUE%^wat%^RESET%^e%^BLUE%^r %^RESET%^%^BOLD%^have "
                "been formed in places where the moisture has not "
                "been frozen.%^RESET%^",
                
                ({"stalagmite","stalagmites","stalactite","stalactites"}) : 
                "%^RESET%^%^BOLD%^Some of the stalagmites and "
                "stalactites are made only of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e, "
                "%^RESET%^%^BOLD%^while others are made of the smooth "
                "gray stone of the mountain.  Still others are "
                "stone covered with several inches of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.%^RESET%^",
                
                ({"stone","granite","gray stone"}) : "%^RESET%^%^BOLD%^"
                "The smooth %^BOLD%^%^BLACK%^stone%^RESET%^%^BOLD%^ "
                "of the mountain cave can been seen through thin places in the "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.%^RESET%^",
                
                "icicles" : "%^RESET%^%^BOLD%^"
                "i%^RESET%^%^CYAN%^c%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^c"
                "%^RESET%^%^BOLD%^l%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^s "
                "cling to every possible vantage "
                "point.  Untold thousands of them, small to large, new "
                "to ancient, line the insides of the "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^y "
                "%^RESET%^%^BOLD%^cave.",
                
                ({"crystals","light","glow"}) : "%^RESET%^%^BOLD%^"
                "Small crystals are imbedded in the stone of the "
                "mountain.  The crystals "
                "%^RESET%^%^BOLD%^g%^YELLOW%^lo%^RESET%^%^BOLD%^w "
                "very softly, allowing for normal vision in most places "
                "without another source of light.%^RESET%^",
             ]));                

    set_smell("default", "The scent of water and ice mix in the air.");
    set_listen("default", "Echoing splashes of water can be heard throughout the cave.");

    searched = 0;

    set_search("crystals", "%^RESET%^%^BOLD%^It looks as if some of the "
        "crystals could be pried out of the walls.%^RESET%^");
    set_search("default",  (: TO, "searchroom" :) );
    set_search("ice",      (: TO, "find_stuff" :) );
    set_search("pools",    (: TO, "find_stuff" :) );
    set_search("stone",    (: TO, "find_stuff" :) );

    set_exits(([
      "out"   : ROOMS"caveb",
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
    add_action("find_crystal", "pry");

}

void reset()
{
    ::reset();
    if(!random(3)) { searched = 0; pried = 0; }
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

void find_crystal()
{
    object obj;
    if(pried) 
    {
        tell_object(TP,"%^BOLD%^Someone has already tried to pry the crystals here.%^RESET%^");
        return 1;
    }

    if(!random(3))
    {
        tell_object(TP,"%^BOLD%^You carefully pry free a crystal!%^RESET%^");
        tell_room(ETP, "%^BOLD%^"+TP->QCN+" carefully pries free a crystal.%^RESET%^",TP);
        if(!random(3)) { obj = new(OBJ"light_crystal"); obj->move(TO); return 1; }
        obj = new(OBJ"clear_crystal");
        obj->move(TO);
        pried = 1;
        return 1;
    }

    tell_object(TP,"%^BOLD%^You pry about here and there but find no loose crystals.%^RESET%^");
    tell_room(ETP, "%^BOLD%^"+TP->QCN+" pries about but doesn't seem to find anything.%^RESET%^",TP);
    pried = 1; 
    return 1;
}

void find_stuff()
{
    object ob,ob1,ob2;
    int i;

    if(searched == 1) { tell_object(TP, "It looks like someone already searched here."); return;}

    if(!random(4))
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
    return("%^RESET%^%^BLUE%^The walls inside the frozen "
             "cave seem to be made of %^RESET%^%^BOLD%^solid "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.  "
             "%^RESET%^%^BLUE%^The air inside is not as cold as the "
             "f%^RESET%^r%^BLUE%^ig%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^d "
             "air outside and as a result, small "
             "pools of water have formed all about the floor.  "
             "%^RESET%^%^BOLD%^Stalagmites %^RESET%^%^BLUE%^"
             "and %^RESET%^%^BOLD%^stalactites %^RESET%^"
             "%^BLUE%^of both crystal clear "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
             "%^RESET%^%^BLUE%^and slick gray "
             "%^RESET%^%^BOLD%^stone %^RESET%^%^BLUE%^are in abundance "
             "while %^RESET%^%^BOLD%^"
             "i%^RESET%^%^CYAN%^c%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^c"
             "%^RESET%^%^BOLD%^l%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^s "
             "%^RESET%^%^BLUE%^hang from every place they can "
             "find purchase.  Here and there tiny "
             "%^RESET%^%^BOLD%^cr%^YELLOW%^yst%^RESET%^%^BOLD%^a"
             "%^BLUE%^l%^RESET%^%^BOLD%^s %^RESET%^%^BLUE%^"
             "inside the granite walls of the mountain "
             "give off a small amount of %^RESET%^light "
             "%^RESET%^%^BLUE%^that shines through the "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.  "
             "%^RESET%^%^BLUE%^The walls of "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
             "%^RESET%^%^BLUE%^over the smooth "
             "stone of the mountain, along with the multitude of "
             "colors created by the "
             "%^RESET%^%^BOLD%^g%^YELLOW%^lo%^RESET%^%^BOLD%^w "
             "%^RESET%^%^BLUE%^from the "
             "%^RESET%^%^BOLD%^cr%^YELLOW%^yst%^RESET%^%^BOLD%^a"
             "%^BLUE%^l%^RESET%^%^BOLD%^s %^RESET%^%^BLUE%^"
             "shining through the various layers of "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
             "%^RESET%^%^BLUE%^and the echoing sounds of dripping "
             "water lend the whole of the cavern "
             "a surreal atmosphere.%^RESET%^");
}

