//forest9c.c - High in the Oak tree

#include <std.h>
#include "../../newbie.h"
#include "forest.h"

inherit ROOM;

int items;
object ob;
string str;

void create(){
items = 1;
   ::create();
   set_property("light",1);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_short("%^GREEN%^High in the Oak Tree%^RESET%^");
   set_terrain(BRANCHES);
   set_travel(FRESH_BLAZE);
   set_long(
@STYX
The limbs are getting smaller as you get higher in the tree, most of them around you now are more the size of a human thigh.  Smaller branches are more numerous now and the squirrels seem to have made their homes in them.  There are %^ORANGE%^piles of acorns %^RESET%^in some of the forks where numerous branches join the trunk close together.  The thick leaves block out much of the light. 
STYX
   );
   set_smell("default","The nutty smell of the acorns drifts among the branches.");
   set_listen("default","You hear squirrels chattering all around.");
   set_items( ([ 
   	({"limb","limbs"}):"These limbs are still large enough to stand on comfortably and nearby limbs give you plenty to hold on to and keep your balance.",
	({"acorns", "pile", "piles"}):"It looks like the squirrels have been storing their nuts for the winter.  One pile is large enough there could easily be other things underneath.  If you're feeling lucky you might want to search it.",
	]) );
   set_search("pile", (: TO, "search_pile" :) );
   set_search("acorns", (: TO, "search_pile" :) );
   set_exits( ([
      "down":FOREST"forest9b",
      ]) );
}

void search_pile() 
{
  if((items > 0)) { 
   	if(random(3) < 2) {
       write("On searching you find what looks like a trap door!\n"        "%^YELLOW%^Suddenly, a giant spider jumps out from behind it at you!\n");
       tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches the pile and finds what looks "
		 "like a trap door, just as a giant spider jumps out from behind it!\n",TP);
       new(MONST"spidertd")->move(TO);
       switch(random(6)){
		  case 0:
			tell_room(ETP,"%^BOLD%^Thankfully there only seems to be one of them.\n");
			break;
		  case 1:
		  	if(random(2) == 0){
		  		new("/d/azha/obj/mr_ring")->move(TO);
		  	}
		  	else {
		  		object ob;
		  		ob = new("/std/obj/coins");
				ob->set_money("gold", random(50)+5);
				ob->set_money("silver", random(500)+100);
				ob->move(TO);
			}
				tell_room(ETP,"%^BOLD%^Thankfully there only seems to be one of them.");
				write("%^BOLD%^You catch a glimpse of something shiny too!\n");
				break;
		  case 2:
		  	new(MONST"spidertd")->move(TO);
			tell_room(ETP,"%^ORANGE%^OOPS!  Another spider pops out to join the first one!");
		case 3..5:
			write("%^BOLD%^Thankfully there is only one of them and you found something else too.");
			tell_room(ETP,"%^BOLD%^Thankfully there is only one of them and "+TPQCN+" found something else too.",TP);
			call_out("add_comp",0,TP);
			break;
		}	
   	   items = 0;
   	   return;
 	}
       else {
      	 write("You only find nuts and twigs this time.");
             tell_room(ETP,TPQCN+" seems to be disappointed from searching the pile.",TP);
    	 items = 0;
       }
  }           
    else {
  	write("It looks like this has been thoroughly searched recently.");
  	}
}

void reset() {
	::reset();
	if(random(4) < 3)
	if (!items) items=1;
}

int add_comp(string str) {
   object obj;
   int num;
   switch(random(18)) {
      case 0:
         str = "eyelash";
         num = random(10)+5;
         break;
      case 1..2:
         str = "powdered rhubarb leaf";
         num = random(10)+4;
         break;
      case 3..4:
         str = "gum arabic";
         num = random(6)+2;
         break;
      case 5:
         str = "owlfeather";
         num = random(5)+3;
         break;
      case 6..7:
         str = "spider web";
         num = random(10)+5;
         break;
      case 8:
         str = "talc";
         num = random(4)+1;
         break;
      case 9..10:
         str = "adders stomach";
         num = random(10)+3;
         break;
      case 11:
         str = "dart";
         num = random(10)+5;
         break;
      case 12:
         str = "tiny bag";
         num = random(10)+4;
         break;
      case 13:
         str = "small candle";
         num = random(10)+3;
         break;
      case 14..17:
         str = "blessed leather";
         num = random(8)+2;
         break;
    }
   tell_object(TP,"%^BOLD%^You found some "+str+", whatever that might be good for.");
   obj = new("/d/magic/store_comp.c");
   obj->set_name(str);
   obj->set_id(({"str","component","spell component"}));
   obj->set_short(capitalize(str)+" (a spell component)");
   obj->set_long("     "+num+" "+str+""+ ""+obj->query_long());
   obj->set_comp_quantity(num);
   obj->move(ETP);
   return 1;
}

