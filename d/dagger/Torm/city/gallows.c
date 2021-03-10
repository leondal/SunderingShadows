//Coded by Diego//
// maybe we can have gates to the square so that no unauthorized hangings take place?//
// Added broadcasting sound of execution to jail rooms & adjacent street -
//    Styx 3/31/02

#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
#include <daemons.h>
#define LIST "torm_official_position_list"

inherit VAULT;

object ob;
int HUNG;

void hanging(object tp, int num);
void make_dead(object tp);
void give_chance(object tp);

void create(){
    ::create();
    set_name("Torm's Gallows");
    set_short("Torm's Gallows");
    set_long(
    "%^RESET%^"+
    "You stand just beneath the northern wall of the city of "+
    "Torm and just north of one of the roads that crisscross "+
    "the massive city.  This main structure of this area is "+
    "what has become quite well known as the '%^RED%^dreaded "+
    "gallows%^RESET%^'.  The wooden structure serves the purpose "+
    "of putting to death those who have been sentenced "+
    "to such a fate by the city.  Stairs lead up the side of "+
    "the structure to reach its main platform where the "+
    "sentences are actually carried out.  The area around "+
    "the gallows is quite littered, as can be expected "+
    "of a city this large, with both trash and manure "+
    "from the horses that occassional bring prisoner and guardsman "+
    "here.  Many people linger near the gallows, even "+
    "during the night, some of them hushed and others quite "+
    "vocal.");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The air smells of old stone, unwashed bodies, and horse manure.");
    set_listen("default","You hear the noises of a hushed, but "+
    "overeager crowd.");
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
        "trash" :  "Common waste from the people who come here, "+
        "articles of paper, straw, and various other debris.",
    	"scaffold" : "This is a portion of the gallows from which the "+
    	"noose is hung.  It is very stout and can handle a great "+
    	"amount of weight.\n",
    	"stairs" : "The stairs lead up to the wooden platform of the "+
    	"gallows.  A person could %^BOLD%^climb "+
    	"%^RESET%^or %^BOLD%^descend %^RESET%^the stairs.",
   ]));

  	set_exits(([
    "south" : TCITY+"c5",
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
int is_npc(){
	return 1;
}
void check(object who) {
    if(!present("guard",TO) && !present("sergeant",TO)) return 1;
   //if(member_array(who->query_name(),SAVE_D->query_array(LIST)) != -1) return 1;
   //tell_room(TO,"The guards fail to recognize "+who->QCN+" and "+
   //"will not let him proceed!%^RESET%^",who);
   //tell_object(who,"The guards fail to recognize you and "+
   //"will not let you proceed.%^RESET%^");
   //return 0;
}
int climb_em(string str) {
    if(!str) {
        tell_object(TP,"%^BOLD%^%^CYAN%^You can't climb that, try the stairs!");
        return 1;
    }
    //if(!check(TP)) return 0;
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
   //if(!check(TP)) return 0;
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
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" "+
					"struggles against "+tp->QP+" "+
					"bindings as "+tp->QS+" slowly "+
					"turns a dark purple.\n",tp);
				break;
			case(1):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" spasms "+
					"and gasps while struggling futiley against the "+
					"noose and the bindings.\n",tp);
				break;
			case(2):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" kicks "+
					"as "+tp->QP+" eyes bulge "+
					"and "+tp->QP+" face blackens.\n",tp);
				break;
			case(3):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" convulses "+
					"as "+tp->QS+" chokes to death "+
					"slowly.\n",tp);
				break;
			case(4):
				tell_room(ETP,"%^BOLD%^Blood vessels burst "+
					"in "+tp->QCN+"'s eyes turning "+
					"the whites of "+tp->QP+" eyes a "+
					"bright red.\n",tp);
				break;
			case(5):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" coughs, "+
					"wheezes, and gurgles.\n",tp);
				break;
			case(6):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" "+
					"soils "+tp->QP+" clothing.\n",tp);
				break;
			case(7):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" weakens "+
					"in "+tp->QP+" struggles as the "+
					"noose begins to do its job.\n",tp);
				break;
			case(8):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" "+
					"rolls "+tp->QP+" eyes back "+
					"into "+tp->QP+" head and "+
					"twitches spasmodically.\n",tp);
				break;
			case(9):
				tell_room(ETP,"%^BOLD%^"+tp->QCN+"'s face "+
					"blackens to a dark purple and "+
					""+tp->QP+" tongue rolls out "+
					"of the side of "+tp->QP+" mouth.\n",tp);
				break;
			default:
				tell_room(ETP,"%^BOLD%^"+tp->QCN+" will soon "+
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
   //if(!check(TP)) return 0;
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
		tell_object(TP,"%^BOLD%^I don't think "+deadguy->QCN+" will "+
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
      			"hanging "+tp->QCN+"!");
      		tell_object(TP,"%^BOLD%^You place the noose "+
      			"about "+tp->QCN+"'s neck.\n");
      		tell_object(tp,"%^BOLD%^"+TPQCN+" places the noose about your neck.\n");
                	tell_room(ETP,"%^BOLD%^"+TPQCN+" places the noose "+
                		"about "+tp->QCN+"'s neck.\n",({TP,tp}));
                 	break;
           	case(1):
               hang_mess = "%^BOLD%^You hear a sharp crack as the gallows " 
                 "trapdoor in the next room is released.  Almost immediately "
                 "you also hear a dull thud and shouts from the crowd.";
           	   tell_room("/d/dagger/Torm/city/c5", hang_mess);
           	   tell_object(TP,"%^BOLD%^You reach over and pull the lever decisively.\n");
      		   tell_object(tp,"%^BOLD%^"+TPQCN+" pulls the lever and you hear a "+
      			"loud thud and then the trapdoor falls away beneath "+
      			"your feet.\n");
                	tell_room(TO,"%^BOLD%^"+TPQCN+" pulls the lever and a large "+
                		"counter weight falls beaneath the platform releasing "+
                		"the lock on the trapdoor.\nThe trapdoor "+
                		"beneath "+tp->QCN+"'s feet slams open "+
                		"with a loud thud.\n",({TP,tp}));
                  break;
          	case(2):
          		tell_object(tp,"%^BOLD%^The trapdoor falls away suddenly and you "+
          			"feel yourself begin to fall.\n");
			switch(random(10)){
          			case(0):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" looks "+
          					"surprised as the trapdoor falls away.\n",tp);
          				break;
          			case(1):
           				tell_room(ETP,"%^BOLD%^"+tp->QCN+" tenses up as "+
           					"the trapdoor falls away.\n",tp);
         				break;
          			case(2):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" gasps as the "+
          					"trapdoor falls away.\n",tp);
          				break;
          			case(3):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" cries like a "+
          					"baby as the trapdoor starts to fall away.\n",tp);
          				break;
          			case(4):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" mumbles "+
          					"something unintelligible as the trap door "+
          					"falls away.\n",tp);
          				break;
          			case(5):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+"'s face clouds "+
          					"with fear as the trapdoor falls away.\n",tp);
          				break;
          			case(6):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" goes berserk "+
          					"and tries to snap "+tp->QP+" bindings "+
          					"as the trap door swings open.\n",tp);
          				break;
          			case(7):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" begs "+
          					"for "+tp->QP+" life "+
          					"miserably as the trapdoor swings open.\n",tp);
          				break;
          			case(8):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" tenses the "+
          					"muscles in "+tp->QP+" neck "+
          					"in an effort defy the hangman as the trapdoor "+
          					"swings open.\n",tp);
          				break;
          			case(9):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" suddenly goes "+
          					"limp as the trapdoor opens.\n",tp);
          				break;
          			default:
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" pisses all "+
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
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" falls "+
          					"through the trapdoor like a rock and comes "+
          					"to a sudden stop as the rope goes taut.\n",tp);
          				break;
          			case(1):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" falls "+
          					"through the trapdoor like a sack of potatoes "+
          					"and bangs "+tp->QP+" head on "+
          					"the edge of the door opening a huge gash "+
          					"over "+tp->QP+" left eye.\n",tp);
          				break;
          			case(2):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" tumbles "+
          					"through the trapdoor and slams to a stop at the "+
          					"end of the rope.\n",tp);
          				break;
          			case(3):
            			tell_room(ETP,"%^BOLD%^"+tp->QCN+" falls "+
            				"forward and slams "+tp->QP+" abdomen "+
						"against the edge of the trapdoor opening "+
						"as "+tp->QS+" falls through "+
						"and then comes to a sudden stop at the end of "+
						"the rope.\n",tp);
        				break;
          			case(4):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" falls "+
          					"through the opening with a yelp and then comes "+
          					"to a sudden stop at the end of the rope.\n",tp);
          				break;
          			case(5):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" screams "+
          					"in abject terror as "+tp->QS+" "+
          					"falls through the trapdoor.\nThe screams "+
          					"are reduced, suddenly, to a gurgle as the rope "+
          					"goes taut.\n",tp);
          				break;
          			case(6):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" falls "+
          					"limply through the trapdoor opening and "+
          					"grunts as the rope stops "+tp->QP+" "+
						"fall with a jerk.\n",tp);
          				break;
          			case(7):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" is "+
          					"heard whimpering as "+tp->QS+" "+
          					"falls through the trapdoor.\n  The sudden stop "+
          					"at the end of the rope reduces the whipmer to "+
          					"a gurgle.\n",tp);
          				break;
          			case(8):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" drops "+
          					"through the trapdoor like a lead weight and "+
          					"comes to a sudden stop at the end of the rope.\n",tp);
          				break;
          			case(9):
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" catches "+
          					"a foot on the edge of the trapdoor opening, "+
          					"balances precariously for a brief moment, "+
          					"then falls through coming to a sudden stop at "+
          					"the end of the rope.\n",tp);
          				break;
          			default:
          				tell_room(ETP,"%^BOLD%^"+tp->QCN+" looks "+
          					"surprised and falls through the trapdoor.\n",tp);
          				break;
          		}
                	break;
          	case(4):
          		switch(random(10)){
          			case(0):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud snap echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck break "+
          					"with finality.\n\n"+
          					""+tp->QCN+" swings limply at "+
          					"the end of the rope "+
          					"as "+tp->QP+" life ebbs "+
          					"away.\n",tp);
          				make_dead(tp);
          				break;
          			case(1):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck snap "+
          					"like a twig.\n\n"+tp->QCN+" bucks "+
          					"at twitches wildly as "+tp->QP+" "+
          					"life spark is snuffed out.\n",tp);
          				make_dead(tp);
          				break;
          			case(2):
          				tell_room(ETP,"%^BOLD%^%^RED%^"+tp->QCN+"'s "+
          					"boots fly off when the rope suddenly "+
          					"stops "+tp->QP+" "+
          					"fall.\n\nA loud crunching sound echoes through "+
          					"the square as you hear "+
          					""+tp->QCN+"'s neck break loudly.\n",tp);
          				make_dead(tp);
          				break;
          			case(3):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck snap like "+
          					"a dry twig.\n\nAs "+tp->QCN+" dies, "+
          					""+tp->QP+" body betrays "+
          					""+tp->QO+" in a most lowly "+
          					"fashion releasing "+tp->QP+" "+
          					"bladder and bowels.\n",tp);
          				make_dead(tp);
          				break;
          			case(4):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck snap.\n\n"+
          					""+tp->QCN+" body weight, combined "+
          					"with the force of the fall and the rope "+
          					"violently stopping "+tp->QO+" with "+
          					"such finality, rips "+tp->QP+" head "+
          					"from "+tp->QP+" shoulders with a "+
          					"grisly sucking sound.\n",tp);
//rend head from corpse?//
          				make_dead(tp);
          				break;
          			case(5):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck snap.\n\n"+
          					""+tp->QCN+" stiffens and then "+
          					"convulses violently vomitting thoroughly "+
          					"over "+tp->QP+" chest.\n",tp);
          				make_dead(tp);
          				break;
          			case(6):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck snap "+
          					"profoundly.\n\nBlood vessels and arteries burst "+
          					"in "+tp->QCN+"'s face and neck "+
          					"forcing blood to issue forth "+
          					"from "+tp->QP+" "+
          					"nose, ears, mouth, and eyes.\n",tp);
          				make_dead(tp);
					break;
          			case(7):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s vertebrae "+
          					"crunch.\n\n"+tp->QCN+" eyes bulge "+
          					"lifeless and cloudy as "+
          					""+tp->QP+" tongue rolls "+
          					"out of "+tp->QP+" mouth "+
          					"and "+tp->QP+" head twists "+
          					"unnaturally to one side.\n",tp);
          				make_dead(tp);
          				break;
          			case(8):
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck snap.\n\n"+
          					"Gurgles as drool rolls out of "+
          					""+tp->QP+" lifeless mouth "+
          					"and falls to the ground.\n",tp);
          				make_dead(tp);
          				break;
          			case(9):
          				tell_room(ETP,"%^BOLD%^%^RED%^"+
          					""+tp->QCN+" comes to a sudden stop "+
          					"at the end of the rope, but something is "+
          					"%^YELLOW%^wrong%^RED%^.\n\n"+
          					""+tp->QCN+" is not "+
          					"dead yet and is turning various shades of blue "+
          					"purple, and black as the life is slowly choked "+
          					"out of "+tp->QO+".\n",tp);
          				give_chance(tp);
          				break;
          			default:
          				tell_room(ETP,"%^BOLD%^%^RED%^A loud crack echoes "+
          					"through the square as you "+
          					"hear "+tp->QCN+"'s neck snap.\n\n"+
          					""+tp->QCN+" dies in such a "+
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

void reset() {
    ::reset();
    if(!present("sergeant")) new(MON+"guardse")->move(TO);
    if(!present("guard 2")) new(MON+"guard2")->move(TO);
    if(!present("guard 3")) new(MON+"guard4")->move(TO);
}
