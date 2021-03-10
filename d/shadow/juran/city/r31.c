//Coded by Diego//

#include <std.h>
#include "../juran.h"
inherit JROAD;
object *monsArray;
int i;

void make_em();

void create(){
   ::create();
	monsArray = allocate(2);
    	set_exits(([
   		"southwest" : JROOMS+"r30",
		"northwest" : JROOMS+"r32",
		"east" : JROOMS+"r40"
    	]));
	make_em();
}
void reset() {
   ::reset();
	if(!present("monster")) make_em();
}
void make_em(){
	object ob,ob2;

      for(i = 0;i < sizeof(monsArray);i++){
        	if(!objectp(monsArray[i])){
        		if(!present("monster")){
        		if(query_night() == 1){
       			switch(random(5)){
        				case 0:
        					ob = new(JMONS+"kobold");
            			ob->move(TO);
            			if(!random(1)){
								ob2 = new(JMONS+"kobold1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
   						if(!random(1)){
							ob2 = new(JMONS+"kobold1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"kobold1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
   						if(!random(3)){
								ob2 = new(JMONS+"kobold1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
   						if(!random(3)){
								ob2 = new(JMONS+"kobold1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
             			monsArray[i] = ob;
           				break;
            		case 1:
            			ob = new(JMONS+"jgnoll");
            			ob->move(TO);
            			if(!random(2)){
								ob2 = new(JMONS+"gnoll1");
								ob2->move(TO);
								ob->add_follower(ob2);
							}
							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

            			monsArray[i] = ob;
							break;
            		case 2:
             			ob = new(JMONS+"drow_cleric");
            			ob->move(TO);
           				if(!random(2)){
								ob2 = new(JMONS+"drow_mage");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
   						if(!random(2)){
								ob2 = new(JMONS+"drow_thief");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"drow_fight");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"drow_fight");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"drow_fight");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"drow_fight");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
            			monsArray[i] = ob;
							break;
           			case 3:
            			ob = new(JMONS+"jhob");
            			ob->move(TO);
           				if(!random(2)){
								ob2 = new(JMONS+"jhob1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
           				if(!random(2)){
								ob2 = new(JMONS+"jhob1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
           				if(!random(2)){
								ob2 = new(JMONS+"jhob1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
           				if(!random(2)){
								ob2 = new(JMONS+"jhob1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
            			monsArray[i] = ob;
							break;
           			case 4:
           				break;
            	}
        		}else{
          		switch(random(7)){
        				case 0:
            			ob = new(JMONS+"jgnoll");
            			ob->move(TO);
            			if(!random(2)){
								ob2 = new(JMONS+"gnoll1");
								ob2->move(TO);
								ob->add_follower(ob2);
							}
							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

							ob2 = new(JMONS+"slave");
							ob2->move(TO);
							ob->add_follower(ob2);

            			monsArray[i] = ob;
							break;
            		case 1:
            			ob = new(JMONS+"jogre");
            			ob->move(TO);
							if(!random(2)){
								ob2 = new(JMONS+"jogre1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
 							if(!random(2)){
								ob2 = new(JMONS+"jogre1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
							if(!random(2)){
								ob2 = new(JMONS+"jogre1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
							if(!random(2)){
								ob2 = new(JMONS+"jogre1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
             			monsArray[i] = ob;
             			break;
     					case 2:
            			ob = new(JMONS+"jbugbear");
            			ob->move(TO);
            			if(!random(2)){
								ob2 = new(JMONS+"bugbear1");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
            			if(!random(2)){
								ob2 = new(JMONS+"bugbear1");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
            			if(!random(2)){
								ob2 = new(JMONS+"bugbear1");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
            			monsArray[i] = ob;
							break;
            		case 3:
            			ob = new(JMONS+"leadgob");
            			ob->move(TO);
							if(!random(2)){
								ob2 = new(JMONS+"magegob");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
   						if(!random(2)){
								ob2 = new(JMONS+"fightgob");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"fightgob");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"fightgob");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
   						if(!random(2)){
								ob2 = new(JMONS+"fightgob");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
            			monsArray[i] = ob;
            			break;
            		case 4:
            			ob = new(JMONS+"jogre_mage");
            			ob->move(TO);
							if(!random(2)){
								ob2 = new(JMONS+"jogre1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
							if(!random(2)){
								ob2 = new(JMONS+"jogre1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
							if(!random(2)){
								ob2 = new(JMONS+"jogre1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
            			monsArray[i] = ob;
            			break;
            		case 5:
            			ob = new(JMONS+"jorc");
            			ob->move(TO);
            			if(!random(2)){
								ob2 = new(JMONS+"jorc1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
            			if(!random(2)){
								ob2 = new(JMONS+"jorc1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
            			if(!random(2)){
								ob2 = new(JMONS+"jorc1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
   						if(!random(2)){
								ob2 = new(JMONS+"jorc_cleric");
    							ob2->move(TO);
    							ob->add_follower(ob2);
    						}
            			if(!random(2)){
								ob2 = new(JMONS+"jorc1");
     							ob2->move(TO);
   							ob->add_follower(ob2);
   						}
            			monsArray[i] = ob;
							break;
            		case 6:
            			break;
        			}
           	}
       }
	}
}
}