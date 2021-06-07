
// Horse Race bunny girl

#include "../horse.h"
#include <std.h>
#include <daemons.h>

inherit NPC;

int x,y,w,q;
int run_a_race();
void run_the_race(int num);

void create() 
{
   	::create();
        set_name("Clarise");
        set_id( ({ "clarise", "vendor", "casino vendor", "bunny girl", "girl"}) );
set_short("%^RESET%^%^CYAN%^Clari%^RESET%^%^BOLD%^"+
"%^CYAN%^s%^RESET%^%^CYAN%^e%^RESET%^%^WHITE%^,"+
" %^RESET%^%^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^"+
"a%^RESET%^%^BOLD%^%^ORANGE%^sino bun%^RESET%^"+
"%^ORANGE%^n%^RESET%^%^BOLD%^%^ORANGE%^y girl%^RESET%^");
   	set("aggressive", 0);
   	set_level(19);
    set_long("%^RESET%^%^ORANGE%^Clarise is employed by the casino in the "+
	"merchant exchange to operate the horse race betting parlor. She is young, "+
	"perhaps only twenty summers old, and is dressed provocatively in "+
	"a %^BLACK%^%^BOLD%^tight short black dress%^RESET%^%^ORANGE%^ that "+
	"would be far too risque for the outside world. A %^RESET%^%^BOLD%^small "+
	"fluffy white tail%^RESET%^%^ORANGE%^ is attached to the back of the "+
	"dress and a %^RESET%^%^BOLD%^headband of two white bunny ears%^RESET%^%^ORANGE%^ "+
	"rises above her %^YELLOW%^long blonde hair%^RESET%^%^ORANGE%^. Around her "+
	"neck she wears a very large %^GREEN%^un%^BOLD%^c%^RESET%^%^GREEN%^ut "+
	"emera%^BOLD%^l%^RESET%^%^GREEN%^d on a %^RESET%^silv%^BOLD%^e%^RESET%^r "+
	"chain%^RESET%^%^ORANGE%^ that her hand rises to every once and awhile. It "+
	"is suggested that her ability to relay the events at the far flung race "+
	"tracks are bound to that necklace and its magical powers.%^RESET%^");
    set_gender("female");
   	set_alignment(3);
   	set("race", "human");
   	add_money("gold", random(500));
   	set_body_type("human");
   	set_property("no attack", 1);
   	set_hd(19,3);
   	set_max_hp(query_hp());
   	set_max_sp(query_hp());
   	set_sp(query_max_sp());
   	set_mp(random(500));
  	set_stats("strength", 18);
  	set_stats("constitution", 17);
  	set_stats("dexterity", 16);
  	set_stats("wisdom", 10);
  	set_stats("intelligence", 14);
  	set_exp(10);
   	set_class("fighter");
	set_spoken("wizish");
    command("speech %^CYAN%^speak in a clear melodic voice%^RESET%^");
	set_emotes(2, ({
"%^RESET%^%^RED%^A half-elf in a red robe tears up his betting stubs and storms off%^RESET%^",
"%^RESET%^%^BOLD%^Clarise adjusts her bunny ears with a demure smile",
"%^BLACK%^%^BOLD%^A squad of Dragoon soldiers does a quick patrol of the area before leaving%^RESET%^",
"%^RED%^%^BOLD%^A dwarf walks by with a pile of books, replacing older ones with new copies",
}), 0);
	y = 1200;
}

void heart_beat(){
    ::heart_beat();
    x = random(20);
	y++;
    if(x == 1){
        if(y > 100){ //one race every 10 minutes if people are here
	    run_a_race();
		return;
	}
    }

}


int run_a_race(){
y = 0;
run_the_race(0);
return 1;
}

void run_the_race(int num){
            switch(num){
                case(0):
	            tell_room(ETP,"%^RESET%^%^MAGENTA%^Clarise jumps up onto the stage.\n%^RESET%^");			
				force_me("pose %^RED%^standing on the stage%^RESET%^");
				force_me("say I have been informed that a race is scheduled to start in four minutes!%^RESET%^");
                force_me("setup_as_immortal race");
                force_me("say Betting is now open, you have four minutes to place your bets!");					
                break;
                case(1): 
				force_me("say A race is scheduled to start in two minutes! You have two more minutes to place your bets before the windows close!");
				tell_room(ETP,"%^RESET%^%^ORANGE%^Several men and women flock to the windows to place bets.%^RESET%^");
				break;
				case(3):
				force_me("say The betting windows are now closed! the race is starting!");
				force_me("say Good luck!");
				tell_room(ETP,"%^BLACK%^%^BOLD%^A hush falls over the crowd as Clarise holds the emerald from her necklace and begins!");
				force_me("run_as_immortal race");
				tell_room(ETP,"%^RESET%^%^MAGENTA%^Clarise bends over for a rag, "+
	            "and carefully cleans the chalk boards, leaving them perfectly "+
	            "%^BLACK%^%^BOLD%^pitch black%^RESET%^%^MAGENTA%^ before hopping off "+
	            "the stage%^RESET%^\n%^RESET%^");
                force_me("pose clear");
			    break;
				
				return;
			}
    num++;
    call_out("run_the_race",120,num);
    return;
}

void catch_say(string message){
    if(strsrch(message,"24601") != -1) {
      call_out("reply_24601",1,TP,message);
    }
}

void reply_24601(string msg, object who){
    tell_room(ETO,"%^RED%^%^BOLD%^x = "+x+" and y = "+y+" \n");
}
