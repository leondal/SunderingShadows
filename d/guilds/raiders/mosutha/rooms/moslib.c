//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^ORANGE%^Library%^RESET%^");
    	set_long(
    		"%^RESET%^%^CYAN%^"+
    		"This is a library with many texts and tomes almost exclusively of, "+
    		"or dealing with, magic.  The shelves run from the floor to ceiling "+
    		"with a ladder on rollers to access the upper shelves.  The shelves "+
    		"are only partially full, but it seems there is a firm foundation of "+
    		"books to work from.  A large table dominates the middle of the room "+
    		"with six chairs around it.  There are several dog-eared books setting "+
    		"on the table.  A fireplace in the north wall provides heat to this room.  "+
    		"The rooms has doors in the west and the south with alcoves in the "+
    		"corners of the room.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The smell of old, dry, crumbling parchment dominates "+
    		"this room and keeps you on the verge of a sneezing fit.");
    	set_listen("default","The room is very quiet.");
    	set_items(([
        	"ladder" : "The ladder is on rollers and is connected with a metal track "+
        		"that parallels the book shelves.  The ladder can be moved to anyplace "+
			"there is a shelf due to the track and roller system.  The ladder is "+
			"used to access the books, tomes, and scrolls on the upper shelves.\n",
		({"books","book","tomes","tome"}) : "Various sizes of books and tomes "+
			"partially fill the shelves and the table in this room.  A quick "+
			"glance reveals that all the material refers to some aspect of magic, "+
			"or its use.\n",
		({"shelf","shelves"}) : "The shelves look sturdy and able to hold many "+
			"texts.\n",
		"table" : "The table is impressive and made of oak.  There is much "+
			"space on top of the table and the table cane hold many texts at "+
			"once.  Six chairs surround the table.\n",
		({"chairs","chair"}) : "Six chairs surround the table in the middle of "+
			"the room.  The chairs are mostly made for human sized individuals, "+
			"but one is made extremely large and one extremely small.  The large "+
			"chair is heavily reinforced and could easily hold the weight of a "+
			"voadkyn or firbolg.  The small chair is obviously a courtesy for "+
			"the smaller races who may visit.\n",
		"fireplace" : "The fireplace provides warmth for the room and keeps the air "+
			"dry to protect the precious pages of the texts.  No smoke or "+
			"smell is detected from the fireplace and the wood inside does not "+
			"appear to be consumed in the flames.\n"
     	]));
     	set_exits(([
   		"west" : MROOMS+"moslab",
   		"south" : MROOMS+"moscom",
   		"northeast" : MROOMS+"mosal1",
   		"southeast" : MROOMS+"mosal2",
   		"southwest" : MROOMS+"mosal3",
   		"northwest" : MROOMS+"mosal4"
 	]));

    	set_door("brown door",MROOMS+"moslab","west","guild earring");
    	set_locked("brown door",1,"lock");
     		(MROOMS+"moslab")->set_locked("brown door",1,"lock");
    	set_door_description("brown door","This is a normal "+
		"looking wooden door painted %^RESET%^%^ORANGE%^brown %^RESET%^with a "+
		"simple lock.  There are burn marks on the edges of the door as if there "+
		"has been an intense fire on the other side of the door.");
    	lock_difficulty("brown door",10,"lock");
   	set_string("brown door","open","You open the "+
   		"door noiselessly into a room full equipment and smells.\n");

    	set_door("green door",MROOMS+"moscom","south","guild earring");
    	set_door_description("green door","The door is a normal "+
    			"looking door made from oak and painted %^GREEN%^green %^RESET%^with a "+
    			"simple lock and a %^BOLD%^%^RED%^red X %^RESET%^in the middle.");
    	set_string("green door","open","You open the door to the antechamber.\n");

	set_trap_functions(({"brown door"}),({"poison_me"}),({"pick"}));

	restore_room();
}
void init() {
  	::init();
  	add_action("reset_em","reset");
  	add_action("open_em","open");
  	add_action("push_em","push");
}
int open_em(string str) {
  	if(!str) {
        	tell_object(TP,"Open what?");
        	return 1;
    	}
  	if(str == "green door"){
		tell_room(ETO,""+TPQCN+" tries to open the green door and fails.\n",TP);
		tell_object(TP,"You try to open the green door and fail.\n");
     		return 1;
     }
}
int push_em(string str) {
  	if(!str) {
        	tell_object(TP,"Push what?");
        	return 1;
    	}
  	if(str == "green door"){
		tell_room(ETO,""+TPQCN+" pushes open the green door.\n",TP);
		tell_object(TP,"You push open the green door and see the next room.\n");
    		set_door_description("green door","The door is a normal looking door made "+
    			"from oak and painted %^GREEN%^green %^RESET%^with a simple lock.");
    		(MROOMS+"moscom")->set_door_description("green door","The door is a normal "+
    			"looking door made from oak and painted %^GREEN%^green %^RESET%^with a "+
    			"simple lock and a %^BOLD%^%^RED%^red X %^RESET%^in the middle.");
    	    	set_open("green door",1);
     			(MROOMS+"moscom")->set_open("green door",1);
     		save_room_shallow();
    			(MROOMS+"moscom")->save_room_shallow();
     		return 1;
     }
}
int reset_em(string str) {
  	if(!str) {
        	tell_object(TP,"Reset what?");
        	return 1;
    	}
  	if(str == "green door"){
		tell_room(ETO,""+TPQCN+" pushes on the green door again making it flip "+
			"around.\n",TP);
		tell_object(TP,"You push on the green door again and the %^BOLD%^%^RED%^red X "+
			"%^RESET%^flips around to the this side resetting the door.\n");
    		set_door_description("green door","The door is a normal looking door made "+
    			"from oak and painted %^GREEN%^green %^RESET%^with a simple lock and "+
    			"a %^BOLD%^%^RED%^red X %^RESET%^in the middle.");
    		(MROOMS+"moscom")->set_door_description("green door","The door is a normal "+
			"looking door made from oak and painted %^GREEN%^green %^RESET%^with "+
			"a simple lock.");
    	    	set_open("green door",0);
     			(MROOMS+"moscom")->set_open("green door",0);
    		save_room_shallow();
    			(MROOMS+"moscom")->save_room_shallow();
    		return 1;
     }
}int poison_me(string str){
	int poison;
	poison = roll_dice(40,10);
	TP->add_poisoning(poison);
	TP->setPoisoner(TO);
	tell_object(TP,"%^BOLD%^%^GREEN%^You feel a sharp prick in your hand as you work "+
		"the lock.");
	TP->force_me("emote pulls his hand back in pain and shakes it slightly");
      toggle_trap("brown door","poison_me","lock"); //added by Circe to allow traps to be disabled
    	return 1;
}
