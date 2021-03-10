//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void sitting(object tp, int num);

void create(){
	object ob;
    ::create();
    set_short("%^CYAN%^Scrying Room%^RESET%^");
    set_long(
        "%^GREEN%^"+
        "Centered in this room is a large finely crafted mirror.  In front of the "+
        "mirror is a large, padded, comfortable looking %^ORANGE%^leather chair.  "+
        "%^GREEN%^The walls are bare, as is the floor and ceiling, and the room is "+
        "barely illuminated.\n"+
        "%^RESET%^");
    set_property("indoors",1);
	set_travel(FOOT_PATH);
    set_terrain(STONE_BUILDING);
    set_property("light",2);
    set_smell("default","The room smells clean and dry.");
    set_listen("default","You hear nothing save the noises you make yourself.");
    set_items(([
        "mirror" : "The mirror is very large and very expensive looking.  The "+
        "surface of the mirror is without flaw and almost ripples as if it "+
        "were made of liquid metal rather than glass.  The frame of the "+
        "mirror is made of gold and inlaid with precious gems and platinum.\n",
        "chair" : "The chair is padded for ultimate comfort and covered in soft "+
        "supple leather.  The chair is set facing the mirror for some "+
        "reason, maybe it was placed there so someone could sit on it and view "+
        "the mirror in comfort.\n"]));
    
    ob = new("/d/magic/obj/mirror");
    ob->move(TO);

    set_search("walls","You notice a very small hole in the south wall, but you only "+
    "see darkness when you try to look through it.  The hole is much too small "+
    " to see well through, being less the half an inch in diameter.\n");
}
void init() {
  	::init();
  	add_action("pull_em","pull");
  	add_action("push_em","push");
  	add_action("bind_me","sit");
}
int pull_em(string str) {
    	if(!str) {
        	tell_object(TP,"Pull what?");
        	return 1;
    	}
  	if((str == "shelf closed") || (str=="shelves closed")){
      	if(member_array("south",TO->query_exits()) != -1) {
     			tell_object(TP,"You pull the shelf to you and close the secret "+
     				"door leaving no trace of the entrance!  \n");
     			tell_room(ETP,""+TPQCN+" pulls the shelf closing the secret "+
     				"door and leaves no trace of the entrance.\n",TP);
     			remove_exit("south");
      		(MROOMS+"moslab")->remove_exit("north");
           	return 1;
            }
     		tell_object(TP,"What shelf?  There is no shelf here!\n");
    		return 1;
     }
}
int push_em(string str) {
    	if(!str) {
        	tell_object(TP,"Push what?");
        	return 1;
    	}
  	if(str == "south wall"){
     		if(member_array("south",TO->query_exits()) != -1) {
        		tell_object(TP,"You almost fall through the already opened door. \n");
            	return 1;
            }
     		tell_object(TP,"You push the south wall and the secret door opens to "+
     			"the laboratory!  \n");
     		tell_room(ETP,""+TPQCN+" pushes on the south wall and the secret passage "+
			"open to the laboratory.\n",TP);
     		add_exit(MROOMS+"moslab","south");
     		(MROOMS+"moslab")->add_exit(MROOMS+"mosscry","north");
     		return 1;
     }
}
int bind_me(string str){
    	if(!str) {
        	tell_object(TP,"Sit on what?");
        	return 1;
    	}
  	if((str == "chair") || (str=="in chair") || (str=="on chair")){
    		if(wizardp(TP) || present("raider ring",TP)){
			tell_object(TP,"You sit in the chair and relax in comfort "+
            		"sinking deep into the leather padding.\n");
                	tell_room(ETP,""+TPQCN+" smiles in comfort while sitting in "+
                		"the chair.\n",TP);
			return 1;
		}
      	TP->set_paralyzed(5000,"You are unable to do that, the chair has got you!");
      	sitting(TP,0);
		return 1;
	}
}
void sitting(object tp,int num){
    	switch(num){
      	case(0):tell_object(TP,"You sit in the chair and relax in comfort "+
            		"sinking deep into the leather padding.\n");
                	tell_room(ETP,""+TPQCN+" smiles in comfort while sitting in "+
                		"the chair.\n",TP);
                 	break;
           	case(1):tell_object(TP,"You are shaken from the moment of rest as "+
            		"you feel the chair leather start to warm.\n");
                	tell_room(ETP,""+TPQCN+"'s smile fades suddenly.\n",TP);
                  break;
          	case(2):tell_object(TP,"You try to pull free of the chair, but find "+
            		"you are stuck fast to the leather!\n");
			tell_room(ETP,""+TPQCN+" tries to pull away from the chair, but "+
				"seems to be stuck fast!!! \n",TP);
                 	break;
           	case(3):tell_object(TP,"You see fibers from the chair extend out "+
            		"and start wrapping you up and you are helpless to "+
                		"stop the process.\n");
                	tell_room(ETP,"Fibers extend from the chair and start to "+
                		"wrap "+TPQCN+" up binding "+TPQCN+" securely!!! \n",TP);
                	break;
          	case(4):tell_object(TP,"Within moments you are bound and gagged by "+
            		"the chair and left laying helpless on the floor!\n");
                	tell_room(ETP,""+TPQCN+" is rapidly bound and gagged by the "+
                		"chair!!! \n",TP);
                 	break;
           	case(5):tell_object(TP,"How will you get out of here now that you are "+
            		"bound and gagged?\n");
			TP->set_bound(random(1000)+1000,"You are bound with magical strands "+
				"and cannot do that!");
			TP->set_gagged(random(1000)+1000,"Magical strands cover your mouth "+
				"preventing any talking!");
                  TP->set_paralyzed(0);
                 	tell_room((MROOMS+"moslab"),"%^BOLD%^%^BLUE%^A bell rings two times.",TP);
			tell_room((MROOMS+"moslib"),"%^BOLD%^%^BLUE%^A bell rings two times.",TP);
			tell_room((MROOMS+"moslib1"),"%^BOLD%^%^BLUE%^A bell rings two times.",TP);
			tell_room((MROOMS+"moslib2"),"%^BOLD%^%^BLUE%^A bell rings two times.",TP);
			tell_room((MROOMS+"moslib3"),"%^BOLD%^%^BLUE%^A bell rings two times.",TP);
			tell_room((MROOMS+"moslib4"),"%^BOLD%^%^BLUE%^A bell rings two times.",TP);
			tell_room((MROOMS+"mossmok"),"%^BOLD%^%^BLUE%^A bell rings two times.",TP);
			return;
          	}
    	num++;
    	call_out("sitting",0,tp,num);
    	return;
}
