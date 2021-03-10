#include <std.h>
#include "../keep.h"

//Saide's original file updated with a few objectp checks by Lujke on December 12 2005
//This will hopefully prevent a bug which was apparently causing users' heartbeats to fail.
inherit VAULT;

void create() 
{
	::create();
    	set_property("no teleport",1);
    	set_property("light",0);
    	set_property("indoors",1);
    	set_property("no sticks",1);
    	set_name("marble chamber");
    	set_short("%^BOLD%^%^WHITE%^Marble Chamber%^RESET%^");
    	set_terrain(BUILT_TUNNEL);
    	set_travel(PAVED_ROAD);
    	set_long("%^BOLD%^%^WHITE%^This chamber is made from solid marble.  The floor of this "+
    	"chamber is completely level and suprisingly well kept.  Inset directly into the "+
    	"center of the southern wall are heavy %^RESET%^%^WHITE%^iron double doors "+
    	"%^BOLD%^%^WHITE%^.  Inset directly into the center of the northern wall are heavy "+
    	"%^YELLOW%^gold double doors%^BOLD%^%^WHITE%^.  The walls of this chamber are "+
    	"completely decorated with %^CYAN%^hieroglyphic symbols%^BOLD%^%^WHITE%^.  A thick, "+
    	"%^BLUE%^cold %^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^ lingers here, permeating "+
    	"your very %^RED%^being%^BOLD%^%^WHITE%^.%^RESET%^\n");
    	set_smell("default","The stench of decay lingers here.");
    	set_listen("default","Growls echo from deep within the darkness.");
    	set_exits(([
        "south": KEEPR + "blacktonguelair10","north" : KEEPR + "blacktonguelair12",
    	] ));
    	set_door("iron double doors",KEEPR + "blacktonguelair10","south");
    	set_door("gold double doors",KEEPR + "blacktonguelair12","north");
    	set_string("iron double doors", "open", "%^RED%^The massive iron doors swing "+
	"open with suprising ease.%^RESET%^");
    	set_door_description("iron double doors","%^WHITE%^These heavy doors are "+
	"made completely from iron.  A massive wolf head is engraved into the "+
	"center of them.%^RESET%^");
    	set_string("gold double doors", "open", "%^RED%^The massive gold doors "+
	"swing open with suprising ease.%^RESET%^");
    	set_door_description("gold double doors","%^YELLOW%^These heavy gold doors "+
	"are made from solid gold.  A massive upright wolf-like creature is engraved "+
	"into the center of them.%^RESET%^");
    	set_items(([
      	({"hieroglyphics","hieroglyphic symbols",
		"hieroglyphic symbol","hieroglyphic","symbols"}) : "%^BOLD%^%^BLACK%^"+
		"These symbols depict numerous wolf-like creatures kneeled "+
		"before a massive wolf-like creature seated on a %^YELLOW%^"+
		"golden%^BOLD%^%^BLACK%^ throne and garbed with an %^BLUE%^"+
		"obsidian%^BOLD%^%^BLACK%^ robe.  An uneasy feeling stirs within you.%^RESET%^",
        	({"floor","Floor"}) : "%^BOLD%^%^WHITE%^The floor of this "+
		"chamber is completely level and suprisingly well kept.%^RESET%^",
        	"walls" : "%^BOLD%^%^WHITE%^The walls of this chamber are decorated "+
		"with hieroglyphic symbols.  Inset into the southern wall are "+
		"heavy %^RESET%^%^WHITE%^iron double doors%^BOLD%^%^WHITE%^.  Inset "+
		"into the northern wall are heavy %^YELLOW%^gold double doors"+
		"%^BOLD%^%^WHITE%^.%^RESET%^",
        	"darkness" : "%^BOLD%^%^BLACK%^This darkness is thick and very "+
		"cold.  It permeates your being, soaking into you, and sending "+
		"chills through your body.  You fear what may be concealed by "+
		"it as growls echo from deep within.%^RESET%^",
        	"being" : "%^RED%^Your very being is assaulted by this "+
		"%^RESET%^%^BLUE%^cold%^RED%^, thick, darkness.%^RESET%^",		
    	]));

//    set_trap_functions(({"north"}),({"fried"}),({"north"}));
//    set_trap_functions(({"south"}),({"fried2"}),({"south"}));

}

void do_save(object person) 
{
	return "daemon/saving_d"->saving_throw(person,"spell");
}

int fried()
{
    	object *alive;
    	int x;
    	alive = all_living(TO);
    	alive -= ({TP});
    	toggle_trap("north","north");
    	if (objectp(TP)){ // objectp check added as a precaution. Lujke December 12 2005
      	if(!TP->query_true_invis())
		{
          		tell_object(TP,"%^RED%^A massive ball of fire explodes into you!%^RESET%^");
          		tell_room(ETP,"%^RED%^A massive ball of fire explodes into "
          		+TP->query_cap_name() +"%^RED%^!%^RESET%^",TP);	
          		set_property("magic",1);
          		if(do_save(TP)) 
			{
              		TP->do_damage("torso",roll_dice(12,6));
          		}
          		else 
			{
              		TP->do_damage("torso",roll_dice(6,6));
  			}
          		set_property("magic",-1);
          		TP->add_attacker(TO);
          		TP->continue_attack();
          		if(objectp(TP))
			{
            		TP->remove_attacker(TO);
          		}
      	}
    	}

    	for(x = 0;x < sizeof(alive);x++) 
	{
      	if (!objectp(alive[x]))
		{  
					    /// objectp check added because alive[0] 
					    //will be called otherwise
                                  // even if 'alive' is an empty array, 
					    //in which case alive[0] won't
                                  // be valid. Lujke December 12 2005
          		continue;
        	}
        	if(!alive[x]->query_true_invis()) 
		{
          		tell_object(alive[x],"%^RED%^You are scorched by "+
			"the flames from the explosion!%^RESET%^");
          		tell_room(environment(alive[x]),alive[x]->query_cap_name() 
			+ "%^RED%^ is scorched by the "+
          		" flames from the explosion!%^RESET%^",alive[x]);
         		set_property("magic",1);
          		if(do_save(alive[x])) 
			{	
              		alive[x]->do_damage("torso",roll_dice(4,6));
          		}
          		else 
			{
            		alive[x]->do_damage("torso",roll_dice(8,6));
          		}
          		set_property("magic",-1);
        	}

        	alive[x]->add_attacker(TO);
        	alive[x]->continue_attack();
        	if(objectp(alive[x])) 
		{
            	alive[x]->remove_attacker(TO);
        	}
    	}
    	return 1;
}

int fried2(){
    object *alive;
    int x;
    alive = all_living(TO);
    alive -= ({TP});
    toggle_trap("south","south");
    if (objectp(TP)){ // objectp check added as a precaution. Lujke December 12 2005
      if(!TP->query_true_invis()) {
          tell_object(TP,"%^RED%^A massive ball of fire explodes into you!%^RESET%^");
          tell_room(ETP,"%^RED%^A massive ball of fire explodes into "
          +TP->query_cap_name() +"%^RED%^!%^RESET%^",TP);	
          set_property("magic",1);
          if(do_save(TP)) {
              TP->do_damage("torso",roll_dice(12,6));
          }
          else {
              TP->do_damage("torso",roll_dice(6,6));
	  }
          set_property("magic",-1);
          TP->add_attacker(TO);
          TP->continue_attack();
          if(objectp(TP)) {
              TP->remove_attacker(TO);
          }
       }
    }

    for(x = 0;x < sizeof(alive);x++) {
      if (!objectp(alive[x])){  // objectp check added because alive[0] will be called otherwise
                                // even if 'alive' is an empty array, in which case alive[0] won't
                                // be valid. Lujke December 12 2005
        continue;
      }
      if(!alive[x]->query_true_invis()) {
        tell_object(alive[x],"%^RED%^You are scorched by the flames from the explosion!%^RESET%^");
        tell_room(environment(alive[x]),alive[x]->query_cap_name() + "%^RED%^ is scorched by the "+
        "flames from the explosion!%^RESET%^",alive[x]);
        set_property("magic",1);
        if(do_save(alive[x])) {
          alive[x]->do_damage("torso",roll_dice(4,6));
        }
        else {
          alive[x]->do_damage("torso",roll_dice(8,6));
        }
        set_property("magic",-1);
      }

      alive[x]->add_attacker(TO);
      alive[x]->continue_attack();
      if(objectp(alive[x])) {
          alive[x]->remove_attacker(TO);
      }
    }
    return 1;
}

void reset() 
{
	object myob;
	int i,x, flag;
    	::reset();
    	i = random(3) + 2;
    	if(!present("massive werewolf")) 
	{
      	for(x = 0;x < i;x++) 
		{
            	new(KEEPM + "massivewerewolf")->move(TO);
        	}
    	}
	if(sizeof(children(KEEPM+"siere"))) 
	{
		myob = children(KEEPM+"siere")[0];
	}
	else myob = find_object(KEEPM+"siere");
	if(!objectp(myob)) flag = 1;		
	if(objectp(myob))
	{
		if(!objectp(environment(myob))) flag = 1;		
	}
    	if(random(3) != 2) 
	{
		if(flag) 
		{
			if(!objectp(myob)) myob = new(KEEPM+"siere");
			myob->move(TO);
		}
        	return;
    	}
}
