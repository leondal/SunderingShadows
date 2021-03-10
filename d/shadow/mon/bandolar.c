#include "melnmarn.h"

inherit MONSTER;

int deliver;
int builder;
object player;
string reply;
string player_name;

void say_it(string who,string what);

void create() {
    ::create();
  	set_name("bandolar");
	set_id( ({ "bandolar","human","lady","young","young lady" }) );
        set("race","human");
	set_gender("female");
	set_level(19);
	set_short("The young lady, Bandolar");
	set_long("Bandolar.\n"
		"She looks to be in her mid twenties, and is very attractive.\n"
		"She is busy reading and writing on the desk she sits at.\n"
		"When she notices you, she smiles and returns to her work.\n"
		"You need to say something to get her attention."
	);
	set_body_type("human");
	set_class("mage");
	set("aggressive", 0);
	set_alignment(9);
	set_size(1);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("strength",18);
	set_stats("charisma",18);
	set_stats("dexterity",18);
	set_stats("constitution",18);
	set_max_mp(500);
   	set_mp(query_max_mp());
	set_hd(19, 1);
      set_max_hp(query_hp());
        set_max_sp(query_hp());
    	set_sp(query_max_sp());
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
        set_exp(50);
        player_name = "";
}
void init(){
    ::init();
}

void catch_say(string str) {
    string who,what,junk;
    if(TP->query_invis()) {
       force_me("emote looks around with a curious look on her face");
       return;
   }
	reply = "";
    who = TP->query_cap_name();
          if(sscanf(str,"%s: %s",junk,what) != 2) return;
           player = TP;
        if(!interactive(player)) return;
        if(member_array("Pipe Quest",player->query_quests()) != -1){
 	    reply = "You have already solved the quest "+who+"! Go away!";
	    what = "";
	    call_out("say_it",1,who,reply);
	}
	if(strsrch(what,"hello") != -1) {
	    reply = "Hello there "+who+", how are you %^BOLD%^feeling%^RESET%^ today?";
	    if(player_name == "") player_name = TPQN;
	}
	if((string)TPQN != player_name) return;
	if(strsrch(what,"feel") != -1) 
	    reply = "Are you feeling up to an %^BOLD%^adventure%^RESET%^, "+who+"?";
	if(strsrch(what,"adventure") != -1) 
	    reply = "Yes, adventure, perhaps even a %^BOLD%^quest%^RESET%^, "+who+"?";
	if(strsrch(what,"quest") != -1) 
	    reply = "Yes, a quest. Deliver a %^BOLD%^note%^RESET%^ for me, "+who+".";
	if(strsrch(what,"note") != -1) 
	    reply = who+" deliver it to a wizard, called %^BOLD%^Rufsu%^RESET%^.";
	if(strsrch(what,"rufsu") != -1) 
	    reply = "Rufsu lives north of Shadow,"+who+", in a %^BOLD%^cave%^RESET%^.";
	if(strsrch(what,"cave") != -1) 
	    reply = "The %^BOLD%^Dragon%^RESET%^ Den Caves, "+who+".";
	if(strsrch(what,"dragon") != -1) 
	    reply = "There really isn't any dragons, "+who+", though there were in the %^BOLD%^past%^RESET%^.";
	if(strsrch(what,"past") != -1) 
	    reply = "Those days are gone though, "+who+". But the caves still have some of the old %^BOLD%^rewards%^RESET%^.";
	if(strsrch(what,"rewards") != -1) 
	    reply = who+" like the healing %^BOLD%^pool%^RESET%^,the %^BOLD%^statue%^RESET%^, and %^BOLD%^other%^RESET%^ rewards. Not to mention, the %^BOLD%^pitfalls%^RESET%^.";
	if(strsrch(what,"pool") != -1) 
	    reply = "There are 3 pools. One is a healing pool, one is a poison pool, and the third is merely plain water. Drink wisely, "+who+".";
	if(strsrch(what,"statue") != -1) 
	    reply = "The statue, it is an interesting peice of work. Solve it's puzzle, "+who+", and you'll find Rufsu.";
	if(strsrch(what,"other") != -1) 
	    reply = "There is lot's of treasure and experience! But don't try it alone, "+who+"!";
	if(strsrch(what,"pitfalls") != -1) 
	    reply = "The caves are a dangerous place. Don't go alone. Be well prepared for battle. Can you %^BOLD%^deliver%^RESET%^ the note "+who+"?";
    	if(strsrch(what,"deliver") != -1) { deliver = 1;  
	    reply = "Please answer %^BOLD%^Yes%^RESET%^ or %^BOLD%^No%^RESET%^.";}
	if((strsrch(what,"yes") != -1) && (deliver == 1)){
	    reply = "I thank thee, honorable "+who+"! Here, take this note and be off with it, quickly!";
	    new("/d/shadowgate/quests/cave_note")->move(player);
	    player_name = "";
	    deliver = 0;
	}
	if((strsrch(what,"no") != -1) && (deliver == 1)){
	    reply = "As you wish, perhaps another time, "+who+"...";
	    player_name = "";
	    deliver = 0;
	}

	if(strlen(reply) > 1) call_out("say_it",1,who,reply);
}

void say_it(string who,string what){
	tell_room(environment(player),"%^MAGENTA%^Bandolar says%^RESET%^: "+what,TO);
	reply = "";
}



