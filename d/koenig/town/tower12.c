#include <std.h>
inherit VAULT;

void create(){
  	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  	set_name("tower12");
  	set_property("light", 1);
  	set_property("indoors", 1);
  	set_short("A Huge Room");
  	set_long("%^BOLD%^%^WHITE%^Oh my. The room you have just entered is huge, and is "+
                "filled with many %^CYAN%^wondrous%^BOLD%^%^WHITE%^ things. In this "+
           	"section of the room that you are now standing in, you see "+
           	"%^MAGENTA%^tapestries%^BOLD%^%^WHITE%^ along the wall, %^RED%^rugs%^BOLD%^%^WHITE%^ upon the floor, and there is "+
           	"some %^RESET%^%^ORANGE%^furniture%^BOLD%^%^WHITE%^ here. You notice that further into the room to "+
           	"the west there are two %^BOLD%^%^BLACK%^fireplaces%^BOLD%^%^WHITE%^ along the west wall. You "+
           	"also notice that there is a very large %^RESET%^%^ORANGE%^table%^BOLD%^%^WHITE%^ set before both, "+
           	"with lots of chairs around it. Who ever lives here appears "+
           	"to have many friends and tons of money at their beck and call."+
           	"%^RESET%^\n"
    	);
  	set_smell("default", "The smoke from the burning fire place smells "+
  		"good, almost alluring in fact.");
  	set_listen("default", "The firewood crackles and pops as it burns slowly.");
  	set_items( ([
     		"tapestries" : "Along this stretch of wall there are 3 more very "+
     			"large tapestries that stand out, although you notice there are many more of them "+
     			"in this room. You might try looking at them individually.",
     		"tapestry 1" : "This tapestry depicts a very bloody battle that you do not recognize.",
                "tapestry 2" : "When you first look upon this one its image seems "+
     			"to waver, but as it comes clear you see yourself shackled "+
     			"down on a table!",
     		"tapestry 3" : "The only impression you get from this one is a shadow "+
     			"lurking just beyond your means of vision.",
     		"rugs" : "The majority of the rugs that lay upon this floor are made of wolf "+
     			"fur.",
     		"furniture" : "In this part of the room there is a small table "+
     			"surrounded by some rather comfortable looking furniture. There is a "+
     			"couch, two chairs, and of all things, a love seat.",
     		"table" : "It looks to be made of very high quality wood.",
     		"couch" : "This couch looks like it could comfortably sit your "+
     			"whole party, or you could stretch out on it for a bit of a nap.",
     		"chair" : "This chair is the twin to the other that sits beside "+
     			"it. Both appear to be covered in very expensive material.",
     		"love seat" : "This love seat is made of high quality everything and "+
                       "the wood appears to be inlaid with gold. It's quite ornate."
	]) );
  	set_exits( ([
     		"west" : "/d/koenig/town/tower13",
     		"east" : "/d/koenig/town/tower11",
     		"north" : "/d/koenig/town/tower15"
	]) );
   	set_trap_functions( 
    		({"couch","love seat"}),
   		({"pins_needles","pins_needles"}),
  		({"sit","sit"})
    	);
}
void pins_needles() {
  	int pins, damage;
  	tell_object(TP,"Ohhh it feels so comfortable that you think you could "+
  		"almost fall asleep here.");
  	tell_room(ETP,"It would appear that "+TPQCN+" is very comfortable "+
  		"sitting there...hmmmm",TP);
  	tell_room(ETP,"Makes you consider joining them...",TP);
  	tell_object(TP,"Suddenly you feel sharp pains down every part of your "+
  		"body that is in contact with the furniture!");
  	tell_object(TP,"Especially down your back and across your pride...");
  	TP->force_me("emote jumps up fast!");
        TP->force_me("emote screams, curses, and rubs "+TP->query_possessive()+" pride and back vigorously!");
  	tell_object(TP,"%^BOLD%^RED%^It feels like you have been stabbed by "+
  		"thousands of pins and needles all at once and all over!");
  	pins = random(4)+1;
  	damage = random(10)+1;
  	TP->do_damage("torso", (damage*pins));
	TP->add_attacker(TO);
	TP->continue_attack();
      return;
}
/*
void init(){
  	::init();
  	add_action("sit_chair", "sit");
}
int sit_chair(string str){
  	if(!str)return notify_fail("Try again.\n");
  	if(lower_case(str) != "chair")return notify_fail("You cant sit there you idiot!\n");
  	tell_object(TP,"You sit down in the chair.");
  	tell_room(ETP,"You see "+TPQCN+" sit down in a chair.",TP);
  	return 1;
}
*/
