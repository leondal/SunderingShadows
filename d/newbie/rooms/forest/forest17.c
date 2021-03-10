//forest17.c

#include "../../newbie.h"
#include "forest.h"

inherit ROOM;

int items;

void create(){
    items = 1;
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_short("%^BLUE%^Bugbear lair%^RESET%^");
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
   set_long(
@STYX
This is a very large cavern with irregular walls.  Even with light it's difficult to see well into some of the niches.  Definintely the home of something crude but somewhat intelligent, pine branches and leaves are piled in various places along the walls with skins over them, perhaps crude beds.  There is a pile of broken weapons, pieces of armor, and who knows what else in the far corner.
STYX
   );
   set_smell("default","The air is stale and musty.");
   set_listen("default","Even the sound of your breathing echoes off the walls.");
   set_items( ([ "walls": "The walls and ceiling are irregular and mostly rock.  They have moss growing on them in places that look damp from water seeping through.", 
	({"pile", "weapons", "pieces of armor"}):"%^MAGENTA%^Maybe some of it is usable or something worthwhile is buried underneath.  Perhaps you should search it.%^RESET%^",
	]) );
    set_search("default", "That pile of weapons and pieces of armor looks interesting.");
    set_search("pile", (: TO, "search_pile" :) );
    set_search("weapons", (: TO, "search_pile" :) );
    set_search("armor", (: TO, "search_pile" :) );
    set_exits(([
       "northwest":FOREST"forest8",
       "west":FOREST"forest16",
   ]));
}
void search_pile() {
  object ob,ob2;
  if(items > 0) { 
       switch(random(10)){
		  case 0:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
			new("/d/common/obj/armour/leather")->move(TO);
			new("/d/common/obj/armour/buckler")->move(TO);
			break;
		  case 1:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
			new("/d/newbie/obj/misc/gem")->move(TO);
			new("/d/common/obj/weapon/pick")->move(TO);
			new("/d/common/obj/armour/chain")->move(TO);
			break;
		  case 2:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
			new("/d/common/obj/armour/studded")->move(TO);
			new("/d/common/obj/weapon/morningstar")->move(TO);
			break;
		  case 3:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
			new("/d/common/obj/weapon/flail")->move(TO);
			new("/d/common/obj/weapon/longsword")->move(TO);
			break;
		  case 4:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
			new("/d/common/obj/weapon/two_hand_sword")->move(TO);
			new("/d/common/obj/armour/bronze")->move(TO);
        		ob=new("/d/magic/scroll");
		    	ob->set_spell(2);
  	            ob->move(TO);
                  break;
              case 5:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
		  	ob = new("/std/obj/coins");
			ob->set_money("gold", random(50)+5);
			ob->set_money("silver", random(500)+100);
			ob->move(TO);
                  break;
		  case 6:
		     tell_room(TO,"%^BOLD%^%^RED%^One of the bugbears "+
                    "must have heard the armor clanging from the "+
                    "searching!!\nIt snarls and growls angrily as "+
                    "it rushes in and attacks.");
		     new("/d/newbie/obj/misc/gem")->move(TO);
		     ob=new(MONST"bugbeark");
		     ob->set("aggressive",19);
		     ob->move(TO);
		     ob->force_me("block north");
		     ob->force_me("rush "+TPQN);
		     ob->force_me("say OURS!!!  No steal!  I kill you!!");
		     if(random(4) == 0){
			ob->force_me("say AARRRGGGHHH!  Thief!!");
			ob->force_me("say Help kill em!!!");
			tell_room(TO,"%^BOLD%^Another bugbear rushes "+
                     "in after hearing the commotion.");
		  	ob=new(MONST"bugbeark");
		    	ob->set("aggressive",19);
		 	ob->move(TO);
			ob->force_me("say %^YELLOW%^I come help kill thief!!");
		 	ob->force_me("get gem");
		     }
		    break;
		  case 7..8:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
		  		ob = new("/d/common/obj/potion/healing");
				ob->set_uses(random(4)+3);
				ob->move(TO);
                  break;
              default:  
                 tell_object(TP,"The bugbears must have all the good stuff with "+
                    "them at the moment.");
                 tell_room(ETP,""+TPQCN+" looks disappointed.",TP);
                 break;
		}	
   	   items = 0;
   	   return;
   } else {
  	tell_object(TP,"Looks like it's been searched pretty recently.");
  	}
}
void reset() {
   ::reset();
   if(random(3) < 2)
     if(!items) items=1;
   if ( (random(8) < 2 ) && (!present("bugbear")) ) {	
    	switch(random(4)) {
    		case 0: 
   		    	new(MONST"bugbear")->move(TO);
   		    	break;
		case 1:
    		   	new(MONST"bugbeark")->move(TO);
			new(MONST"bugbear")->move(TO);
			break;
    		case 2:	
    			new(MONST"bugbearh")->move(TO);
			new(MONST"bugbear")->move(TO);
			break;
		case 3:
    			new(MONST"bugbearch")->move(TO);
			break;			
	}
   }
}
