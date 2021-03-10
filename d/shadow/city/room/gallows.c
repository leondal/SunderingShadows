#include <std.h>
inherit VAULT;

object ob;
int HUNG;

void hanging(object tp, int num);
void make_dead(object tp);
void give_chance(object tp);

void create(){
   	::create();
    	set_name("End's Square");
    	set_short("End's Square");
    	set_long(
            "%^BOLD%^%^CYAN%^End's Square%^RESET%^
%^RESET%^%^CYAN%^You are standing in a large cobblestone courtyard. The area is walled and in the middle of the courtyard is a wooden structure called a %^BOLD%^%^ORANGE%^gallows. %^RESET%^%^ORANGE%^S%^BOLD%^%^ORANGE%^tai%^RESET%^%^ORANGE%^r%^BOLD%^%^ORANGE%^s%^RESET%^%^CYAN%^ lead up the side of the gallows to its main platform. The cobblestones are mostly free of debris except for the occasional pile of horse %^BOLD%^%^ORANGE%^manure%^RESET%^%^CYAN%^ and %^BOLD%^%^ORANGE%^straw.%^RESET%^%^CYAN%^ Many people mill about this courtyard. A %^BOLD%^%^ORANGE%^b%^RESET%^%^ORANGE%^a%^ORANGE%^s%^BOLD%^%^ORANGE%^ket%^RESET%^%^CYAN%^ of rotting fruits and vegetables is against the south wall%^RESET%^."
    	);
    	set_terrain(CITY);
    	set_travel(PAVED_ROAD);
    	set_property("indoors",0);
    	set_property("light",2);
    	set_smell("default","The air smells of old stone, unwashed bodies, and horse manure.");
    	set_listen("default","You hear the noises of a hushed, but overeager crowd.");
    	set_items(([
    		"gallows" : "This wooden structure is made from rough hewn "+
    			"lumber.  The gallows consist of a wooden platform "+
    			"supported above the ground, about 15 feet, by 4 thick "+
    			"logs like a very large table.  Atop the platform is "+
    			"what can be called a scaffold.  A sturdy rope tied to "+
    			"the crossbeam of the scaffold and dangles to rest on the "+
    			"floor of the platform with about a foot of slack and a "+
    			"noose tied into the end.  The scaffold crossbeam is "+
    			"approximately 10 feet above the platform  and  a lever "+
    			"is attached to one of the upright portions of the scaffold.  "+
    			"A rope runs from the lever, down the upright portion of "+
    			"the scaffold, and disappears under the platform.  In the "+
    			"middle of the platform, just beneath where the rope is "+
    			"tied is a trapdoor.\n",
    		"manure" : "This is horse shit you ninny!\n",
    		"straw" : "This is nothing more than a pile of straw, sometimes "+
    			"people throw it onto piles of horse manure to keep the crap "+
    			"from being tracked all over the place.\n",
    		"scaffold" : "This is a portion of the gallows from which the "+
    			"noose is hung.  It is very stout and can handle a great "+
    			"amount of weight.\n",
    		"stairs" : "The stairs lead up to the wooden platform of the "+
    			"gallows.  A person could %^BOLD%^climb "+
    			"%^RESET%^or %^BOLD%^descend %^RESET%^the stairs.",
    		"basket" : "The basket contains rotting fruit and vegetables.  "+
    			"You have seen unsavory people in the crowd getting those "+
    			"rotted pieces of food and using them to "+
    			"%^BOLD%^%^humiliate%^RESET%^ the condemned.\n"
	]));

        set_exits(([
                       "west" : "/d/shadow/city/room/jail_main",
                       "north" : "/d/shadow/city/room/moffice",
               ]));
	set_property("knock unconscious",1);
    	HUNG = 0;
}

void init() {
  	::init();
  	add_action("climb_em","climb");
  	add_action("descend_em","descend");
  	add_action("hang_em","hang");
  	add_action("reset_em","reload");
}

void reset() {
   ::reset();
   if(!present("street_light",TO))
      new("/d/common/obj/misc/street_light")->move(TO);
   if(!present("shadow guard"))
      new("/d/shadow/city/mon/city_guard")->move(TO);
   if(!present("shadow guard 2"))
      new("/d/shadow/city/mon/city_guard")->move(TO);
}

int is_npc(){
	return 1;
}
int climb_em(string str) {
    	if(!str) {
        	tell_object(TP,"%^BOLD%^%^CYAN%^You can't climb that, try the stairs!");
        	return 1;
    	}
  	if(str == "stairs" || str == "the stairs"){
  		tell_room(ETO,"%^BOLD%^"+TPQCN+" climbs the stairs to the gallows "+
  			"platform slowly, but with due deliberation.",TP);
  		tell_object(TP,"%^BOLD%^You climb the stairs slowly, but deliberately.");
  		if(!present("writ",TP)){
  			tell_room(ETP,"A minor bureaucrat hands a slip of paper to "+TPQCN+".");
   			tell_object(TP,"%^BOLD%^%^CYAN%^The bureaucrat whispers to "+
   				"you: %^RESET%^offer that when you finish the job so it "+
   				"will not fall into the wrong hands.\n\nThe bureaucrat "+
   				"nods to the document he handed you.");
 			ob=new("/d/tharis/obj/paper");
  			ob->set_name("writ");
  			ob->set_short("a writ of execution");
  			ob->set_long("This is a small piece of parchment giving you "+
  				"permission to execute the criminal.");
  			ob->set_weight(1);
  			ob->move(TP);
  		}
		return 1;
      }
}
int reset_em(string str) {
    	if(!str) {
        	tell_object(TP,"%^BOLD%^%^CYAN%^You can't reload that, try "+
        		"reloading the trapdoor!");
        	return 1;
    	}
  	if(str == "trapdoor" || str == "the trapdoor"){
  		if(HUNG == 0)return notify_fail("The trapdoor is already reloaded"+
  			", the gallows await your justice.\n");
  		tell_room(ETP,"%^BOLD%^"+TPQCN+" orders two guards to reload the lever and "+
  			"close the trapdoor.",TP);
  		tell_object(TP,"%^BOLD%^You command two guards to reload and close the "+
  			"trapdoor for the next condemned prisoner.");
  		HUNG = 0;
  		if(!present("writ",TP)){
   			tell_room(ETP,"A minor bureaucrat hands a slip of paper to "+TPQCN+".");
   			tell_object(TP,"%^BOLD%^%^CYAN%^The bureaucrat whispers to "+
   				"you: %^RESET%^offer that when you finish the job so it "+
   				"will not fall into the wrong hands.\n\nThe bureaucrat "+
   				"nods to the document he handed you.");
			ob=new("/d/tharis/obj/paper");
  			ob->set_name("writ");
  			ob->set_short("a writ of execution");
  			ob->set_long("This is a small piece of parchment giving you "+
  				"permission to execute the criminal.");
  			ob->set_weight(1);
  			ob->move(TP);
  		}
		return 1;
      }
}
int descend_em(string str) {
    	if(!str) {
        	tell_object(TP,"%^BOLD%^%^CYAN%^You can't descend that, try the stairs!");
        	return 1;
    	}
  	if(str == "stairs" || str == "the stairs"){
  		tell_room(ETO,"%^BOLD%^"+TPQCN+" descends the stairs slowly.",TP);
  		tell_object(TP,"%^BOLD%^You descend the stairs slowly.");
		return 1;
      }
}
void make_dead(object tp){
	tell_object(tp,"You feel a sharp pain radiate throughout your body "+
		"from your neck then blessed numbness.\n");
    	set_property("magic",1);
	tp->do_damage("neck",2000);
	set_property("magic",-1);
	tp->add_attacker(TO);
	tp->continue_attack();
	return;
}
void give_chance(object tp){
	string name;

	if(!objectp(tp))return;
	name = tp->query_name();
	if(present(name)){
		tell_object(tp,"%^BOLD%^%^RED%^You feel the noose tightening about "+
			"your neck and strangling you closer to death!\n");
		switch(random(10)){
			case(0):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" "+
					"struggles against "+tp->query_possessive()+" "+
					"bindings as "+tp->query_subjective()+" slowly "+
					"turns a dark purple.\n",tp);
				break;
			case(1):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" spasms "+
					"and gasps while struggling futiley against the "+
					"noose and the bindings.\n",tp);
				break;
			case(2):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" kicks "+
					"as "+tp->query_possessive()+" eyes bulge "+
					"and "+tp->query_possessive()+" face blackens.\n",tp);
				break;
			case(3):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" convulses "+
					"as "+tp->query_subjective()+" chokes to death "+
					"slowly.\n",tp);
				break;
			case(4):
				tell_room(ETP,"%^BOLD%^Blood vessels burst "+
					"in "+tp->query_cap_name()+"'s eyes turning "+
					"the whites of "+tp->query_possessive()+" eyes a "+
					"bright red.\n",tp);
				break;
			case(5):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" coughs, "+
					"wheezes, and gurgles.\n",tp);
				break;
			case(6):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" "+
					"soils "+tp->query_possessive()+" clothing.\n",tp);
				break;
			case(7):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" weakens "+
					"in "+tp->query_possessive()+" struggles as the "+
					"noose begins to do its job.\n",tp);
				break;
			case(8):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" "+
					"rolls "+tp->query_possessive()+" eyes back "+
					"into "+tp->query_possessive()+" head and "+
					"twitches spasmodically.\n",tp);
				break;
			case(9):
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+"'s face "+
					"blackens to a dark purple and "+
					""+tp->query_possessive()+" tongue rolls out "+
					"of the side of "+tp->query_possessive()+" mouth.\n",tp);
				break;
			default:
				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" will soon "+
					"be dead you ghoulish bastards!\n",tp);
				break;
		}
    		set_property("magic",1);
		tp->do_damage("neck",roll_dice(3,6));
	    	set_property("magic",-1);
		tp->add_attacker(TO);
		tp->continue_attack();
		call_out("give_chance",5,tp);
	}
}
int hang_em(string str){
	object deadguy;

	deadguy = present(str);

  	if(HUNG == 1) return notify_fail("You must reload the trapdoor "+
  		"before you may hang another prisoner!\n");
  	if(!deadguy) return notify_fail("That person is not here!\n");
  	if(deadguy->query_unconscious())return notify_fail("You would not "+
  		"hang a prisoner unshriven would you?\n");
  	if(!present("writ",TP)) return notify_fail("You cannot execute "+
  		"someone from down here, climb the stairs to the platform first.  "+
  		"Don't forget to carry your prisoner with you.\n");
  	if(deadguy->query_bound()){
  		HUNG = 1;
		hanging(deadguy,0);
		return 1;
	}else{
		tell_object(TP,"%^BOLD%^I don't think "+deadguy->query_cap_name()+" will "+
			"let you do that!");
		tell_object(deadguy,"%^BOLD%^"+TPQCN+" is trying to hang you.");
		return 1;
	}
}

void hanging(object tp,int num){
   string hang_mess;
    	switch(num){
      	case(0):
      		TP->set_paralyzed(5000,"%^BOLD%^You are busy "+
      			"hanging "+tp->query_cap_name()+"!");
      		tell_object(TP,"%^BOLD%^You place the noose "+
      			"about "+tp->query_cap_name()+"'s neck.\n");
      		tell_object(tp,"%^BOLD%^"+TPQCN+" places the noose about your neck.\n");
                	tell_room(ETP,"%^BOLD%^"+TPQCN+" places the noose "+
                		"about "+tp->query_cap_name()+"'s neck.\n",({TP,tp}));
                 	break;
           	case(1):
               hang_mess = "%^BOLD%^You hear a sharp crack as the gallows "
                 "trapdoor in the next room is released.  Almost immediately "
                 "you also hear a dull thud and shouts from the crowd.";
           	   tell_room("/d/shadow/room/city/jail", hang_mess);
           	   tell_room("/d/shadow/room/city/jail", "A cold chill runs up "
           	     "your spine as you wonder if you'll be next.");
           	   tell_room("/d/shadow/room/city/jail_main", hang_mess);
           	   tell_room("/d/shadow/room/city/sroad", hang_mess);
           		tell_object(TP,"%^BOLD%^You reach over and pull the lever decisively.\n");
      		tell_object(tp,"%^BOLD%^"+TPQCN+" pulls the lever and you hear a "+
      			"loud thud and then the trapdoor falls away beneath "+
      			"your feet.\n");
                	tell_room(ETP,"%^BOLD%^"+TPQCN+" pulls the lever and a large "+
                		"counter weight falls beaneath the platform releasing "+
                		"the lock on the trapdoor.\nThe trapdoor "+
                		"beneath "+tp->query_cap_name()+"'s feet slams open "+
                		"with a loud thud.\n",({TP,tp}));
                  break;
          	case(2):
          		tell_object(tp,"%^BOLD%^The trapdoor falls away suddenly and you "+
          			"feel yourself begin to fall.\n");
			switch(random(10)){
          			case(0):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" looks "+
          					"surprised as the trapdoor falls away.\n",tp);
          				break;
          			case(1):
           				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" tenses up as "+
           					"the trapdoor falls away.\n",tp);
         				break;
          			case(2):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" gasps as the "+
          					"trapdoor falls away.\n",tp);
          				break;
          			case(3):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" cries like a "+
          					"baby as the trapdoor starts to fall away.\n",tp);
          				break;
          			case(4):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" mumbles "+
          					"something unintelligible as the trap door "+
          					"falls away.\n",tp);
          				break;
          			case(5):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+"'s face clouds "+
          					"with fear as the trapdoor falls away.\n",tp);
          				break;
          			case(6):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" goes berserk "+
          					"and tries to snap "+tp->query_possessive()+" bindings "+
          					"as the trap door swings open.\n",tp);
          				break;
          			case(7):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" begs "+
          					"for "+tp->query_possessive()+" life "+
          					"miserably as the trapdoor swings open.\n",tp);
          				break;
          			case(8):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" tenses the "+
          					"muscles in "+tp->query_possessive()+" neck "+
          					"in an effort defy the hangman as the trapdoor "+
          					"swings open.\n",tp);
          				break;
          			case(9):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" suddenly goes "+
          					"limp as the trapdoor opens.\n",tp);
          				break;
          			default:
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" pisses all "+
          					"over the place as the trapdoor falls open.\n",tp);
          				break;
          		}
                 	break;
           	case(3):
                 	TP->set_paralyzed(0);
          		tell_object(tp,"%^BOLD%^You fall through the trapdoor in what "+
          			"seems to be a surrealistic slow motion.\n\nYour life "+
          			"begins to flash before your eyes.\n\nYou suddenly stop "+
          			"as the rope goes taut and and searing pain flashes "+
          			"through your neck and up and down your spine, then "+
          			"numbness.\n");
          		switch(random(10)){
          			case(0):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" falls "+
          					"through the trapdoor like a rock and comes "+
          					"to a sudden stop as the rope goes taut.\n",tp);
          				break;
          			case(1):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" falls "+
          					"through the trapdoor like a sack of potatoes "+
          					"and bangs "+tp->query_possessive()+" head on "+
          					"the edge of the door opening a huge gash "+
          					"over "+tp->query_possessive()+" left eye.\n",tp);
          				break;
          			case(2):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" tumbles "+
          					"through the trapdoor and slams to a stop at the "+
          					"end of the rope.\n",tp);
          				break;
          			case(3):
            			tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" falls "+
            				"forward and slams "+tp->query_possessive()+" abdomen "+
						"against the edge of the trapdoor opening "+
						"as "+tp->query_subjective()+" falls through "+
						"and then comes to a sudden stop at the end of "+
						"the rope.\n",tp);
        				break;
          			case(4):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" falls "+
          					"through the opening with a yelp and then comes "+
          					"to a sudden stop at the end of the rope.\n",tp);
          				break;
          			case(5):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" screams "+
          					"in abject terror as "+tp->query_subjective()+" "+
          					"falls through the trapdoor.\nThe screams "+
          					"are reduced, suddenly, to a gurgle as the rope "+
          					"goes taut.\n",tp);
          				break;
          			case(6):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" falls "+
          					"limply through the trapdoor opening and "+
          					"grunts as the rope stops "+tp->query_possessive()+" "+
						"fall with a jerk.\n",tp);
          				break;
          			case(7):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" is "+
          					"heard whimpering as "+tp->query_subjective()+" "+
          					"falls through the trapdoor.\n  The sudden stop "+
          					"at the end of the rope reduces the whipmer to "+
          					"a gurgle.\n",tp);
          				break;
          			case(8):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" drops "+
          					"through the trapdoor like a lead weight and "+
          					"comes to a sudden stop at the end of the rope.\n",tp);
          				break;
          			case(9):
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" catches "+
          					"a foot on the edge of the trapdoor opening, "+
          					"balances precariously for a brief moment, "+
          					"then falls through coming to a sudden stop at "+
          					"the end of the rope.\n",tp);
          				break;
          			default:
          				tell_room(ETP,"%^BOLD%^"+tp->query_cap_name()+" looks "+
          					"surprised and falls through the trapdoor.\n",tp);
          				break;
          		}
                	break;
          	case(4):
          		switch(random(10)){
          			case(0):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud snap echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck break "+
          					"with finality.\n\n"+
          					""+tp->query_cap_name()+" swings limply at "+
          					"the end of the rope "+
          					"as "+tp->query_possessive()+" life ebbs "+
          					"away.\n",tp);
          				make_dead(tp);
          				break;
          			case(1):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck snap "+
          					"like a twig.\n\n"+tp->query_cap_name()+" bucks "+
          					"at twitches wildly as "+tp->query_possessive()+" "+
          					"life spark is snuffed out.\n",tp);
          				make_dead(tp);
          				break;
          			case(2):
          				tell_room(ETP,"%^BOLD%^%^RED%^"+tp->query_cap_name()+"'s "+
          					"boots fly off when the rope suddenly "+
          					"stops "+tp->query_possessive()+" "+
          					"fall.\n\nA loud crunching sound echoes through "+
          					"the square as you hear "+
          					""+tp->query_cap_name()+"'s neck break loudly.\n",tp);
          				make_dead(tp);
          				break;
          			case(3):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck snap like "+
          					"a dry twig.\n\nAs "+tp->query_cap_name()+" dies, "+
          					""+tp->query_possessive()+" body betrays "+
          					""+tp->query_objective()+" in a most lowly "+
          					"fashion releasing "+tp->query_possessive()+" "+
          					"bladder and bowels.\n",tp);
          				make_dead(tp);
          				break;
          			case(4):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck snap.\n\n"+
          					""+tp->query_cap_name()+" body weight, combined "+
          					"with the force of the fall and the rope "+
          					"violently stopping "+tp->query_objective()+" with "+
          					"such finality, rips "+tp->query_possessive()+" head "+
          					"from "+tp->query_possessive()+" shoulders with a "+
          					"grisly sucking sound.\n",tp);
//rend head from corpse?//
          				make_dead(tp);
          				break;
          			case(5):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck snap.\n\n"+
          					""+tp->query_cap_name()+" stiffens and then "+
          					"convulses violently vomitting thoroughly "+
          					"over "+tp->query_possessive()+" chest.\n",tp);
          				make_dead(tp);
          				break;
          			case(6):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck snap "+
          					"profoundly.\n\nBlood vessels and arteries burst "+
          					"in "+tp->query_cap_name()+"'s face and neck "+
          					"forcing blood to issue forth "+
          					"from "+tp->query_possessive()+" "+
          					"nose, ears, mouth, and eyes.\n",tp);
          				make_dead(tp);
					break;
          			case(7):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s vertebrae "+
          					"crunch.\n\n"+tp->query_cap_name()+" eyes bulge "+
          					"lifeless and cloudy as "+
          					""+tp->query_possessive()+" tongue rolls "+
          					"out of "+tp->query_possessive()+" mouth "+
          					"and "+tp->query_possessive()+" head twists "+
          					"unnaturally to one side.\n",tp);
          				make_dead(tp);
          				break;
          			case(8):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck snap.\n\n"+
          					"Gurgles as drool rolls out of "+
          					""+tp->query_possessive()+" lifeless mouth "+
          					"and falls to the ground.\n",tp);
          				make_dead(tp);
          				break;
          			case(9):
          				tell_room(ETP,"%^BOLD%^%^RED%^"+
          					""+tp->query_cap_name()+" comes to a sudden stop "+
          					"at the end of the rope, but something is "+
          					"%^YELLOW%^wrong%^RED%^.\n\n"+
          					""+tp->query_cap_name()+" is not "+
          					"dead yet and is turning various shades of blue "+
          					"purple, and black as the life is slowly choked "+
          					"out of "+tp->query_objective()+".\n",tp);
          				give_chance(tp);
          				break;
          			default:
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->query_cap_name()+"'s neck snap.\n\n"+
          					""+tp->query_cap_name()+" dies in such a "+
          					"grisly fashion that everyone in the gallery "+
          					"pukes.\n",tp);
          				make_dead(tp);
          				break;
          		}
			return;
          	}
    	num++;
    	call_out("hanging",0,tp,num);
    	return;
}
