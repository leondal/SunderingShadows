#include <std.h>
#include "../defs.h"
#include <daemons.h>
inherit MONSTER;

// Coral Sea Area - Created January 2009 by Ari

object ob;
int step1;
int step2;
int step3;
string *asked;

create(){
	::create();
	set_name("grizon");
	set_id(({"pirate","grizon","privateer","Grizon"}));
	set_gender("male");
	set_race("human");
	set_short("Grizon the Privateer");
	set_long("%^RESET%^%^CYAN%^Grizon is a stout, thick set, bald man "+
		"with a %^BOLD%^%^BLACK%^graying beard %^RESET%^%^CYAN%^"+
		"sprouting from his oval face.  His %^RED%^ruddy skin %^CYAN%^"+
		"is blotchy from too much ale and there's a glassy glaze to "+
		"his %^BOLD%^blue eyes %^RESET%^%^CYAN%^which you doubt will "+
		"ever go away.  A small puggish nose makes his face look "+
		"puffy and thick.  Only five-foot tall on a good day, his "+
		"stature is round with sausage-like fingers, short, stubby "+
		"legs and a %^RED%^big beer-gut %^CYAN%^that gives his body "+
		"a barrel shape.  Oddly, despite the lack of care to his "+
		"health, his clothing is rather crisp and clean, free of "+
		"wrinkles or stains.  And there is a glitter here and there "+
		"of %^BOLD%^jewels %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^"+
		"precious metals %^RESET%^%^CYAN%^to accent the fine cloth "+
		"and skilled tailoring.  He looks like a man used to "+
		"hireing others when he needs a %^BOLD%^%^BLACK%^<job> "+
		"%^RESET%^%^CYAN%^done for him.  Maybe he'd give you one, "+
		"if you mentioned you were interested.");
	set_body_type("human");
	set_spoken("wizish");
	set_alignment(8);
	set_hd(22,10);
	set_stats("strength",22);
	set_stats("aggressive",3);
	set_size(2);
	set_property("swarm",1);
	set_wielding_limbs(({"right hand","left hand"}));
	set_overall_ac(-1);
	set_hp(300+random(100));
	set_exp(2500);
	set_max_level(30);	
	
	ob = new(OBJ"coral_ale");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	ob = new("/d/dagger/road/obj/studded+3.c");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear studded");
	command("wield mug");
	
	set_emotes(3,({"%^RESET%^%^MAGENTA%^Grizon looks around the room: "+
		"%^RESET%^Anyone here interested in a job?", "Grizon takes a "+
		"long drink from his mug.", "%^RESET%^%^MAGENTA%^Grizon "+
		"grumbles:%^RESET%^ There's got to be someone here that doesn't "+
		"mind getting wet.  I have a job that needs doing.", "%^RESET%^"+
		"%^MAGENTA%^Grizon yawns and leans back in his chair:%^RESET%^ "+
		"Someone that can do this job best come along soon.  Getting "+
		"sleepy."})); 
}

void heart_beat(){
        ::heart_beat();
		if(!objectp(TO)){return;}
		if(!objectp(ETO)){return;}
        if(!objectp(TO) || !objectp(ETO)) return;
        if(query_hp()< 200 && present("vial",TO)){
            force_me("quaff vial");
            force_me("quaff vial");
        }
}

void reset(){
	::reset();
		step1 = 0;
		step2 = 0;
		step3 = 0;
}

void catch_say(string msg){
	call_out("give_quest",1,msg,TP);
	call_out("repeat_this",1,msg,TP);
}

void give_quest(string msg, object who){
	string name;
	name = who->query_name();
	asked = SAVE_D->query_array("coral_quest_asked");
		if(!msg || !objectp(who)) return;
		if(who->query_quests()){
			if(member_array("Finished Grizon's Job",
				who->query_quests()) != -1){
				force_me("say Thanks for your help earlier, "+
					"but I don't have any more jobs for you "+
					"right now.");
				tell_room(ETO,"Grizon nods.",who);
			return 1;
			}
			if(member_array("Failed Grizon's Job",who->query_quests()) != -1){
				force_me("Grizon looks you over in disgust and returns "+
					"back to what he was doing.  You hear him mumble: "+
					"Can't even do a simple fetch job.  Got no use for "+
					"that kind.");
				tell_room(ETO,"Grizon smirks.",who);
			return 1;
			}
		}
		
		if((strsrch(msg,"repeat") != -1 || strsrch(msg,"Repeat") 
			!= -1) && (member_array(name, asked) != -1)){
				force_me("emote takes a long swig of his drink then "+
					"nods.\n");
				force_me("say Right, like I told you, the Kitter - "+
					"that's the ship, remember - went down a bit ago.");
				force_me("say Word has it that she might have gone "+
					"aground by that coral reef a bit south of this "+
					"here dock.  But who knows.  Search the sea and "+
					"you'll find her.");
				force_me("say Just remember.  The first one to find me "+
					"that golden chest, untampered with, gets the "+
					"money.");
				force_me("emote nods dismissively.\n");
				force_me("say Best get going, unless you don't want "+
					"all that gold I'm offering.");
			return;
		}

		if(member_array(name, asked) != -1){
			if(!random(3)){
				tell_object(ETO,"Grizon glances at your belongings.");
				force_me("say %^RESET%^Finish that job yet?  Need me to "+
					"%^YELLOW%^repeat %^RESET%^the details?");
			}
		return;
		}
	
		if((strsrch(msg,"treasure") != -1 || strsrch(msg,"job") != -1
			|| strsrch(msg,"work") != -1 || strsrch(msg,"yes") != -1
			|| strsrch(msg,"Yes") != -1) && !step1){
			tell_room(ETO,"Grizon glances up over the rim "+
				"of his drink and studies "+who->QCN+".\n",TP);
			tell_object(TP,"Grizon glances up over the rim "+
				"of his drink and studies you.");
			force_me("say So, you're interested in a job "+
				"are you?");
			force_me("say I've got one that might be "+
				"something you can do.  I wonder though..");
			force_me("say Can you swim?");
			step1 = 1;
			return 1;
		}
		
		if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1)
			&& step1 && !step2){
			force_me("say Alright then, I might just have a job "+
				"for someone like you.  If you don't mind a little "+
				"danger.");
			tell_room(ETO,"Grizon looks "+who->QCN+"'s gear over.\n",TP);
			tell_object(TP,"Grizon looks your gear over.\n");
			force_me("say No, didn't think as much.  Not with that "+
				"kind of set up.");
			force_me("say Alright then, here's the job in a nut "+
				"shell.  Or a clam shell for that matter.");
			tell_room(ETO,"Grizon takes a swig of his brew and "+
				"glances around a bit before leaning forward and "+
				"dropping his voice.\n");
			force_me("say First, lets have a bit of a story. "+
				"A few years back there was a very big storm out at "+
				"sea.  Big nasty one.  Turned the Saakrune into the "+
				"Saaking, if you get my drift.");
			force_me("say The %^GREEN%^Emerald Kitter%^RESET%^ had "+
				"the misfortune to be caught in her gusts.  And word "+
				"has that she ran aground of something deep in the "+
				"sea. Well out southeast of this here port.");
			force_me("say Still with me?");
			step2 = 1;
			return 1;
		}
		
		if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1)
			&& step1 && step2 && !step3){
			tell_room(EETO,"Grizon nods and takes a deep drink of "+
				"his brew.\n");
			force_me("say Good to hear.  Now, like I was saying.."+
				"The Kitter went down a few years back.  All "+
				"hands on deck, from what I hear.  Sorry lot.");
			tell_room(ETO,"Grizon lifts his mug in the air, silently "+
				"toasting the Kitter's fate.\n");
			force_me("say Sorry lads. Istishia watch over your souls.");
			force_me("say So they, their ship and their cargo all "+
				"went the way of the sea.  And that may be bad "+
				"enough, but it gets worse.");
			force_me("say See, the Kitter was carrying a special bit "+
				"of cargo.  And no, I aint going to tell you why "+
				"it is so special. You don't need to know that.");
			tell_room(ETO,"Grizon narrows his eyes, studying you "+
				"closely.\n");
			force_me("say What you do need to know, for this job at "+
				"least, is that I'm willing to pay a lot of gold "+
				"for you to go and fetch back what was lost. Although, "+
				"how much is entirely up to you.");
			force_me("say You see, what I need isn't what you're "+
				"fetching.  It's what's inside what you're fetching "+
				"that I want.  And I'm willing to pay well if it "+
				"isn't tampered with.  So listen up!");
			force_me("say You're going to go find the remains of the "+
				"Kitter and see if you can locate a solid gold chest. "+
				"and by solid gold, I mean solid gold.  Completely "+
				"made of gold, from hasp to hinge. You bring that "+
				"back to me, unopened, and I'll fill your pockets "+
				"with 25,000 gold.  How's that sound to you?  Good?");
			tell_room(ETO,"Grizon gives "+TP->QCN+" an expectant look.\n",TP);
			tell_object(TP,"Grizon gives you an expectant look");
			step3 = 1;
			return 1;
		}
		
		if((strsrch(msg,"good") != -1 || strsrch(msg,"Good") != -1
			|| strsrch(msg, "yes") != -1 || strsrch(msg,"great") != -1
			|| strsrch(msg, "excellent") != -1) && step3){
				if(member_array(name, asked) == -1) {
				SAVE_D->set_value("coral_quest_asked", name); 
				}
			tell_room(ETO,"Grizon looks pleased and settles back "+
				"in his chair.\n");
			force_me("say Good then! Excellent! Knew I could count on "+
				"you.");
			force_me("say Now, I'm not sure where the Kitter went "+
				"down exactly, so you'll have to go search for "+
				"her on your own.  There's a coral reef nearby, and "+
				"word has it, she went aground on something just "+
				"under the waves.  So maybe start there.");
			force_me("say Just remember.  I want that chest back "+
				"sealed and untampered with.  I aint paying for "+
				"curiosity but for a clean job.  Got it?");
			force_me("say Good... Now, get going.  First one to the "+
				"prize gets my gold.  Nothing for runner ups.");
			return 1;
		}
		
		switch(random(10)){
			case 0: force_me("%^RESET%^%^MAGENTA%^Grizon looks around "+
				"the room: %^RESET%^Anyone here interested in a job?"); 
			break;
			case 1: force_me("Grizon takes a long drink from his mug."); 
			break;
			case 2: force_me("%^RESET%^%^MAGENTA%^Grizon grumbles:"+
				"%^RESET%^ There's got to be someone here that doesn't "+
				"mind getting wet.  I have a job that needs doing."); 
			break;
			case 3: force_me("%^RESET%^%^MAGENTA%^Grizon yawns and "+
				"leans back in his chair:%^RESET%^ Someone that can do "+
				"this job best come along soon.  Getting sleepy."); 
			break;
		}
		
	return 1;
}

void receive_given_item(object obj){
	string name;
	name = TPQN;
	asked = SAVE_D->query_array("coral_quest_asked");
	
	if(!objectp(obj)) return;

/* If they return another chest after finishing the quest. */
	if(member_array("Finished Grizon's Job",TP->query_quests()) != -1){
		force_me("say What's this? You already brought the gold chest "+
			"back.  Where'd this fake come from?");
		force_me("say It's of no use to me.");
		tell_room(EETO,"Grizon tosses the piece of junk away.");
		obj->remove();
		return;
	}
	
	if(member_array(TPQN, asked) == -1){
		force_me("say Yeah, thanks kid.  Now get lost.");
		return;
	}

/* If they have broken open the chest & try to return it. */	
	if(member_array("coralbadchest",(string)obj->query_id()) != -1){
		force_me("say What's this?!");
		tell_room(ETO,"Grizon looks down at the chest then back "+
			"up.  Rage fills his eyes that quickly turns to a hot "+
			"violent anger.");
		force_me("say By Istishia's Stormy Seas! What is this? You greedy, "+
			"useless fool!  Didn't I tell you more then once that I "+
			"wanted this chest back in one piece?!");
		tell_room(ETO,"Grizon shakes the chest before him, anger "+
			"turning his face bright red.");
		force_me("say Now it is useless! USELESS!");
		force_me("say Get out of my sight! I've no use for your kind!");
			if(member_array(TPQN, asked) != -1) { 
				SAVE_D->remove_name_from_array("coral_quest_asked",TPQN);
			}
			if(member_array(("Failed Grizon's Job" || "Finished Grizon's Job"),
				TP->query_quests()) == -1){
					TP->fix_exp(2000000,TP);
					TP->set_quest("Failed Grizon's Job");
					tell_object(TP,"You failed Grizon's job!");
					"/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" Failed Grizon's Job!");
			}
		obj->remove();
               return 1;
	}
	
/* If they bring back the good chest. */	
	if(member_array("coralgoodchest",(string)obj->query_id()) != -1){
		tell_room(ETO,"Grizon looks the chest over carefully "+
			"inspecting it from every side and testing then unbroken "+
			"hasp.");
		force_me("say Well now, this looks just like what I was "+
			"expecting.");
		force_me("say Alright then, a deal's a deal.  Here's your "+
			"well earned gold.");
		tell_room(ETO,"Grizon tucks the chest away and pulls out "+
			"a large sack of gold!");
			if(member_array(TPQN, asked) != -1) { 
				SAVE_D->remove_name_from_array("coral_quest_asked",TPQN);
			}
			if(member_array(("Failed Grizon's Job" || "Finished Grizon's Job"),
				TP->query_quests()) == -1){
					add_money("gold",25000);
					force_me("give "+query_money("gold")+" gold coins to "+TPQN);
					TP->set_quest("Finished Grizon's Job");
					TP->fix_exp(100000,TP);
					tell_object(TP,"You finished Grizon's job!");
					"/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" "+
						"Finished Grizon's Job!");
			}
		obj->remove();
		return 1;
	}
return 1;
}

	
