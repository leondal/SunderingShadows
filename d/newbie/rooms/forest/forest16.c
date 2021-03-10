//forest16.c

#include "../../newbie.h"
#include "forest.h"

inherit ROOM;

int items;
object ob;

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
This is a very large cavern with irregular walls.  Even with light it's difficult to see well into some of the niches.  Definintely the home of something crude but somewhat intelligent, pine branches and leaves are piled in various places along the walls with skins over them, perhaps crude beds.  A pile of what looks like skins and scraps of clothing is in a far corner.
STYX
   );
   set_smell("default","The air is stale and musty.");
   set_listen("default","Even the sound of your breathing echoes off the walls.");
   set_items( ([ "walls": "The walls and ceiling are irregular and mostly rock.  They have moss growing on them in places that look damp from water seeping through.", 
	({"pile", "scraps", "skins"}):"%^BOLD%^%^RED%^The skins and scraps of clothing appear to be blood-stained and they smell rather rank but who knows what else might be under there.%^RESET%^",
	]) );
   set_search("pile", (: TO, "search_pile" :) );
   set_search("skins", (: TO, "search_pile" :) );

   set_exits(([
       "north":FOREST"forest8",
       "east":FOREST"forest17",
   ]));
}

void search_pile() {
  object ob2;
  if(items > 0) { 
       switch(random(8)){
		  case 0..1:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
			new("/d/newbie/obj/misc/gem")->move(TO);
			break;
		  case 2:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
			ob=new("/d/magic/scroll");
    			ob->set_spell(2);
		    	ob->move(TO);
                  break;
		  case 3:
                  tell_object(TP,"%^BOLD%^Lucky you, you indeed find "+
                     "some things of value in the pile.");
                  tell_room(ETP,"%^BOLD%^"+TPQCN+" searches the pile "+
                     "and uncovers some useful things.",TP);
		  		ob = new("/std/obj/coins");
				ob->set_money("gold", random(50)+5);
				ob->set_money("silver", random(500)+100);
				ob->move(TO);
                  break;
		  case 4:
		  	tell_object(TP,"%^BOLD%^%^RED%^One of the bugbears "+
                     "must have just returned and noticed you "+
                     "searching!!\nIt snarls and growls angrily "+
                     "as it rushes in and attacks.");
			tell_room(ETP,"%^BOLD%^%^RED%^One of the bugbears "+
                     "must have just returned and noticed the "+
                     "searching!!\nIt snarls and growls angrily as "+
                     "it rushes in and attacks.",TP);
			new("/d/newbie/obj/misc/gem")->move(TO);
		  	ob=new(MONST"bugbeark");
		      ob->set("aggressive",19);
		 	ob->move(TO);
			ob->force_me("say No steal!  I kill you!!");
			ob->force_me("rush "+TPQN);
			if(!random(4)){
				ob->force_me("yell AARRGGGHHH!  Help "+
                           "kill thief!!!");
				ob->force_me("say Come help kill "+
                           "thief!!!");
				tell_room(TO,"%^BOLD%^Another bugbear "+
                           "rushes in after hearing the call "+
                           "for help.");
		  		ob2=new(MONST"bugbeark");
		      	ob2->set("aggressive",19);
		 		ob2->move(TO);
				ob2->force_me("say %^YELLOW%^I kill dem!  "+
                           "Smash and eat!!");
		 		ob2->force_me("get gem");
			}
		      break;
		  case 5..6:
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
	if (!items) items=1;
	if ( (random(8) < 2 ) && (!present("bugbear")) ) {	
    	switch(random(4)) {
    		case 0: 
   		    	new(MONST"bugbear")->move(TO);
   		    	break;
   		    case 1:
    		   	new(MONST"bugbeark")->move(TO);
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
