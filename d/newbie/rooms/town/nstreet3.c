#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Starlight Avenue in Offestry");
   set_short("%^RESET%^%^GREEN%^Starlight Avenue in Offestry");
   set_long("%^RESET%^%^GREEN%^Starlight Avenue in Offestry%^RESET%^\n"
"You are standing on Starlight Avenue, which leads south back to the Offestry town square.  The road ends here at an opening that allows passage beyond the town.  The cobblestone %^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but "
"steady stream of %^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  The street is bordered on both "
"sides by a jumble of %^RED%^buildings%^RESET%^.  "
"To the west the closet of which is a shop full of musical instruments with its doors open to welcome potential customers.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.");

   
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Starlight Avenue leads south back to the Offestry town square. It ends here in an "
"opening in the palisade which surrounds the town to allow passage beyond its borders.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along both sides of the street.  Their age and vastly varied "
"styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearby is a shop full "
"of musical instruments.%^RESET%^",
   ]));
   set_exits(([
      "north":ROAD"froad1",
      "south":MAINTOWN"nstreet2",
      "west":MAINTOWN"instruments",
   ]));
   set_post_exit_functions( ({"north"}), ({"ready"}) );
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}

void ready(string str) 
{
    //if(!random(4))  return;
    if(!userp(TP)) return;
    if((int)TP->query_level() > 5) return;
    if( ((int)TP->query_hp()*100)/(int)TP->query_max_hp() < 90) 
    { 
        switch(TP->query_level()) 
        {
            case 0..2 :  
                tell_room(TP, "%^CYAN%^A concerned citizen points to your "
                "wounds and suggests that you should try to %^YELLOW%^<heal> "
                "%^RESET%^%^CYAN%^yourself.");
                break;
            case 3..5 :
                tell_room(TP, "%^YELLOW%^A concerned citizen points to "
                "your wounds and suggests you visit the healer for potions or training "
                "in healing.  %^CYAN%^(help skills)%^RESET%^.");
                break;
            default: 
                return;
                break;           
        }
        return;
    }
    if(sizeof(TP->query_wielded()) == 0) 
    {
        switch(TP->query_level()) 
        {
            case 0..3:  
                tell_room(TP, "%^YELLOW%^As you leave the protection of the city, "+
                "you realize it might be wise to wield your weapons and be prepared "+
                "for battle.%^RESET%^");
                break;
            default:
                return;
                break;
        }
        return;
    }
    return;
}