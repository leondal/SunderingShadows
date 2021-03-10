#include <std.h>
#include "../gantioch.h"
#include <daemons.h>

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
    set_name("mound");
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("indoors", 1);
    set_property("light", -1);
    set_property("no teleport",1);
    set_short("%^RESET%^%^ORANGE%^Within a Mound%^RESET%^");
    set_long( (: TO,"long" :) );
    set_items(([
      "marks"    : "%^RESET%^%^RED%^The marks on the walls are obviously made by a massive clawed creature.",
      "leathers" : "%^RESET%^%^ORANGE%^The piles of leather are scattered about, obviously scraps from other materials made.",
      "drawings" : "%^BOLD%^%^YELLOW%^These tribal paintings depict many things, mostly violent and having the general theme of "+
                   "hunting, killing, and torturing various creatures from animals to elves, humans, gnomes, and other creatures.",
    ]) );

    set_smell("default","\n%^BOLD%^%^BLACK%^The smell stench of rotting food within this lair.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear yips and barks from down the hall.%^RESET%^");

    searched = 0;

    set_search("default",  (: TO, "searchroom" :) );
    set_search("leathers", (: TO, "find_stuff" :) );

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

        switch(random(20)){
        case 0..5:
            break;
        case 6..19:
            set_monsters( ({MON"gnollcleric.c"}),({random(2)+1}) );
            set_monsters( ({MON"gnollthief.c"}),({random(2)+1}) );
            set_monsters( ({MON"gnollfighter.c"}),({random(2)+1}) );
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
    if(!random(2)) { searched = 0;}
    return;
}

void searchroom()
{
    tell_object(TP,"There is nothing worth searching, save the scattered pieces"+
                " of %^RESET%^%^ORANGE%^leather%^RESET%^.");
    return;
}

void find_stuff()
{
    object ob,ob1,ob2;
    int i;

    if(searched == 1) { tell_object(TP, "It looks like someone already searched here."); return;}

    if(!random(2))
    {
switch(random(25)){
      case 0..2:
         write("%^BOLD%^%^BLACK%^You find nothing.");
         tell_room(TO,"%^RESET%^%^ORANGE%^"+TPQCN+" searches the leather scraps and finds nothing.",TP);
         searched = 0;
         break;
      case 3..8:
         write("%^BOLD%^%^YELLOW%^You find some coins scattered about the leathers!");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds some coins scattered about the %^RESET%^%^ORANGE%^leathers%^RESET%^.",TP);
         ob = new("/std/obj/coins");
         ob->set_money("gold", random(1000)+1000);
         ob->move(TO);
         searched = 0;
         break;
      case 9..12:
         write("%^BOLD%^%^YELLOW%^You search through the leathers and find a %^RESET%^%^ORANGE%^headband%^BOLD%^%^YELLOW%^ amidst the trash!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a %^RESET%^%^ORANGE%^headband%^BOLD%^%^YELLOW%^ on the floor amidst some trash.%^RESET%^",TP);
      new(OBJ+"headband")->move(TO);
         searched = 0;
         break;
      case 13..14:
         write("%^BOLD%^%^YELLOW%^You search through the leathers and find a %^RESET%^%^ORANGE%^sheath%^BOLD%^%^YELLOW%^ amidst the trash!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a %^RESET%^%^ORANGE%^sheath%^BOLD%^%^YELLOW%^ on the floor amidst some trash.%^RESET%^",TP);
      new(OBJ+"beadedmsheath")->move(TO);
         searched = 0;
         break;
      case 15..16:
         write("%^BOLD%^%^YELLOW%^You search through the leathers and find a %^RESET%^%^ORANGE%^sheath%^BOLD%^%^YELLOW%^ amidst the trash!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a %^RESET%^%^ORANGE%^sheath%^BOLD%^%^YELLOW%^ on the floor amidst some trash.%^RESET%^",TP);
      new(OBJ+"beadedlsheath")->move(TO);
         searched = 0;
         break;
      case 17..18:
         write("%^BOLD%^%^YELLOW%^You search through the leathers and find a %^RESET%^%^ORANGE%^sleeve%^BOLD%^%^YELLOW%^ amidst the trash!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a %^RESET%^%^ORANGE%^sleeve%^BOLD%^%^YELLOW%^ on the floor amidst some trash.%^RESET%^",TP);
      new(OBJ+"beadedmsleeve")->move(TO);
         searched = 0;
         break;
      case 19..20:
         write("%^BOLD%^%^YELLOW%^You search through the leathers and find a %^RESET%^%^ORANGE%^sleeve%^BOLD%^%^YELLOW%^ amidst the trash!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a %^RESET%^%^ORANGE%^sleeve%^BOLD%^%^YELLOW%^ on the floor amidst some trash.%^RESET%^",TP);
      new(OBJ+"beadedlsleeve")->move(TO);
         searched = 0;
         break;
      case 21..22:
         write("%^BOLD%^%^YELLOW%^You search through the leathers and find a %^RESET%^%^ORANGE%^sheath%^BOLD%^%^YELLOW%^ amidst the trash!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a %^RESET%^%^ORANGE%^sheath%^BOLD%^%^YELLOW%^ on the floor amidst some trash.%^RESET%^",TP);
      new(OBJ+"beadedssheath")->move(TO);
        searched = 0;
         break;
      case 23..24:
         write("%^BOLD%^%^YELLOW%^You search through the leathers and find a %^RESET%^%^ORANGE%^earrings%^BOLD%^%^YELLOW%^ amidst the trash!%^RESET%^");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a %^RESET%^%^ORANGE%^earrings%^BOLD%^%^YELLOW%^ on the floor amidst some trash.%^RESET%^",TP);
      new(OBJ+"earrings")->move(TO);
         searched = 0;
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
    return("%^RESET%^%^ORANGE%^The ground is packed dirt and has slight %^BOLD%^%^YELLOW%^marks %^RESET%^%^ORANGE%^all across the"+
           " ground. Piles of %^BOLD%^%^YELLOW%^leathers %^RESET%^%^ORANGE%^ are thrown about the room. Crude %^RESET%^%^RED%^drawings%^RESET%^%^ORANGE%^ cover the walls around you, depicting an"+
           " obvious tribal living area.");
}
