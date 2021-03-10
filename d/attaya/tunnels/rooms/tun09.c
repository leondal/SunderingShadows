
#include <std.h>
#include "../tunnel.h"

inherit MTUNNEL;

void GoThroughDoor();
void crawl_hole(string str);
string long_desc();

void create(){
  ::create();
  set_long((:TO,"long_desc":));

  set_items( ([ 
    ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of black"
                        +" s%^RESET%^l%^BOLD%^%^BLACK%^ate. They are"
                        +" smooth in places, but cracked and uneven in"
                        +" others, making it hard to know whether they"
                        +" have been worked or not.",
  
  "ceiling" : "the ceiling is so high up as to be out of sight.", 

  "hole": "%^BOLD%^%^BLACK%^The hole is dark and damp looking, but it"
         +" seems like you would be able to %^RESET%^crawl%^BOLD%^"
         +"%^BLACK%^ through it",

  ({"cracks", "fissures"}):"the larger cracks look big enough for"
                          +" something to go into of come out of, most of"
                          +" them are way up out of reach. However, the"
                          +" largest hole you have seen so far is in"
                          +" front of you, about three feet from the"
                          +" ground", 

  "crack" : "The largest hole in the wall you have seen so far is in"
           +" front of you, about three feet from the ground it seems"
           +" like you would be able to %^RESET%^crawl%^BOLD%^%^BLACK%^"
           +" through it",
 ]) );

  set_exits(([
              "south":TUNNELS + "tun08",
        ]));
  set_post_exit_functions(({"south",}),({"GoThroughDoor",}));
}

string long_desc(){
   return "%^BOLD%^%^BLACK%^This is a narrow tunnel cut through the"
          +" black rock. It is unclear whether this is a crudely"
          +" constructed tunnel or simply a natural fissure, but the"
          +"walls are steep and tall, and the ceiling is way out of sight"
          +" overhead. The tunnel comes to an end here, as the walls"
          +" close together to the north. However, the largest hole"
          +" you have seen so far is in front of you, about three feet"
          +" from the ground.%^RESET%^";
}

void GoThroughDoor(){
  find_object_or_load(TUNNELS+"tun08")->on_entry(TP);
}

void init(){
  ::init();
  add_action("crawl_hole","crawl");
  add_action("crawl_hole","enter");
  add_action("crawl_hole","scramble");
  find_object_or_load(TUNNELS + "wormhole.c");
 }

void crawl_hole(string str)
{
	object bigweapon;
  	object *myweapons;
  	int i;
  	int flag = 0;
  	if (!objectp(TP)){return;}  
  	if (str != "hole" && str != "into hole" && str != "crack" && str !=
 	"into crack" && str != "through crack" && str != "through hole")
	{
    		if (query_verb() == "scramble")
		{
      		return 0;
    		}
    	tell_object(TP, query_verb()+" where?");
    	return 1;
  	}
  	if (sizeof(TP->query_wielded())>0)
	{
    		myweapons = TP->query_wielded();
    		for (i = 0;i<sizeof(TP->query_wielded());i++)
		{
      		if(myweapons[i]->query_size() > 1) 
			{
        			flag = 1; 
        			bigweapon = myweapons[i];
      		}
    		}
    		if (flag)
		{
      		tell_object(TP, "You're not able to crawl into the hole while"
                  +" carrying a weapon the size of your " 
                  + bigweapon->query_name() 
                  +". It's just too cumbersome."  );
      		return 1;
    		}	
  	}
  	if (find_object_or_load(TUNNELS+"wormhole")->is_empty()==0)
	{
    		tell_object(TP, "You struggle a bit, but there is someone in the"
                   +" way and you can't get into the hole.");	

    		tell_room(TO, TPQCN + " struggles a bit, but can't get into the"
                         +" hole.", TP);

    		return 1;	
  	}
 	tell_object(TP, "You struggle a bit, but mangage to scramble up into"
                 +" the hole...");	
  	tell_room(TO, TPQCN + " scrambles up and pulls " + TP->QO + "self up"
              +" into the large hole in the wall.", TP);
  	if (TP->query_ghost()){return 1;}
  	TP->move_player(TUNNELS + "wormhole.c");
  	find_object_or_load(TUNNELS+ "wormhole.c")->enter_south();
 	return 1;
}
