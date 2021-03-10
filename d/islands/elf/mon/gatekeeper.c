#include <std.h>
#include "../elf.h"
inherit MONSTER;

int step;
int guards;

void reply_snarl(string str);
void reply_yell(string str);
void reply_ask(string str);

void create() {
   ::create();
   set_name("gatekeeper");
   set_id( ({"gatekeeper","elf","feanor","Faenor"}) );
   set_short("Feanor, Ashta'Rathai's Gatekeeper");
   set_long("The young looking moon elf is dressed"+
   " in simple clothing.  He has green eyes and "+
   "black hair.  He is of a slender build and "+
   "looks to keep a keen eye on the gate.  Usually"+
   " he keeps up inside the battlements but "+
   "sometimes comes down to question those wishing to enter.");
   set_race("elf");
   set_gender("male");
   set_alignment(1);
   set_hd(20,20);
   set_max_hp(280);
   set_hp(280);
   set_overall_ac(-2);
   enable_commands();
   set_class("fighter");
   new(OBJ"gatekey")->move(TO);
   force_me("wearall");
   set_new_exp(30,"very low");
   set_max_level(35);
   set_base_damage_type("bludgeoning");
}
void init() {
   ::init();
   add_action("kill","kill");
   step = 0;
}
void reset() {
   ::reset();
   guards = 0;

   if(objectp(ETO) ) {
      tell_room(ETO,"The Gatekeeper shrugs and heads off.");
      move("/d/shadowgate/void");
      remove();
   }
}

int kill(string str) {
   if(str != "gatekeeper") return 0;
   if(guards == 1) {
     force_me("say %^BOLD%^%^RED%^You try ta kill me ??!!");
     force_me("say I won't let you in.  I'm leaving.");
     tell_room(ETO,"The Gatekeeper scowls and leaves.");
     move(ROOMS"grove2");
     return 1;
   }     
   reply_snarl("You attack me?!");
   reply_yell("%^BOLD%^GUARDS!!!!");
   tell_room(ETO,"The Gatekeeper opens the gate to get more "
           "reinforcements as his call has been answered "+
		   "by a pair of guards.");
   if(!present("guard",ETO)) {
      new(MON"guard.c")->move(ETO);
      new(MON"guard2.c")->move(ETO);
   }
  
   
   guards = 1;
   return 1;
}

void start_grumble(string str) {
   string time;
   time = "daemon/events_d"->query_time_of_day();
   if(!present(TP->query_name(),ETO)) {
      tell_room(ETO,"The elf comes to the gate and looks around.");
      reply_snarl("What is it?");
      tell_room(ETO,"The elf shrugs and leaves.");
      move("/d/shadowgate/void");
      remove();
      return;
   }
   if(time == "day") {
      reply_snarl("What are you doing here?");
      tell_room(ETO,"The elf comes to the gate "
                "and carefully looks "+TPQCN+" over.",TP);
      tell_object(TP,"The elf comes to the gate and"+
	  " carefully looks you over.");
      call_out("start_exam",5);
      return 1;
   }
   else {
      reply_snarl("Who is sneaking about down there at night?");
      tell_room(ETO,"The elf comes to the gate "
                "and carefully looks "+TPQCN+" over.",TP);
      tell_object(TP,"The elf comes to the gate and"+
	  " carefully looks you over.");
      call_out("start_exam",10);
      return 1;
   }
}

void start_exam(string str) {
   if(!present(TP->query_name(),ETO || TP->query_invis() || TP->query_hidden())) {
      reply_snarl("Fair enough.");
      tell_room(ETO,"The elf turns around and "+
        "heads back inside");
	  reply_snarl("Where did they go?.");
      move("/d/shadowgate/void");
      remove();
      return;
   }
   if((string)TP->query_race() != "elf" &&
       (string)TP->query_race() != "nymph" &&
       (string)TP->query_race() != "voadkyn" &&
       (string)TP->query_race() != "dryad" &&
       (string)TP->query("subrace") != "szarkai") {
      reply_snarl("I will only open the gate for elves and fey.  Go back the way you came.");
      tell_room(ETO,"The elf turns around and "
       "heads back into the gatehouse, locking it behind him.");
      move("/d/shadowgate/void");
      remove();
      return;
   }
   else {
      add_action("say_stuff","say");
      reply_ask("Do you wish to enter Ashta'Rathai?, "
	  +TP->query_race()+"?");
      step = 1;
   }
}

int say_stuff(string str) {
   object roomy;
   roomy = ROOMS"gate";
   if( (strsrch(str,"yes") != -1 || strsrch(str,"Yes") != -1) && (step ==
1)) {
      tell_room(ETO,"The elf unlocks the gate and allows "
	  +TPQCN+" to pass.",TP);
      tell_object(TP,"The elf unlocks the gate and allows"+
	  " you to pass on into Ashta'Rathai.");
	   force_me("say Welcome to our remote keep cousin.");
      force_me("unlock gate with key");
      tell_room(ETO,"The elf then turns on his "
            "heels and goes back inside the gatehouse."+
			"  He closes the door behind him");
      move("/d/shadowgate/void");
      remove();
      return 1;
   }
   if((strsrch(str,"no") != -1) && (step == 1)) {
      reply_snarl("Then leave and go back where you belong.");
      tell_room(ETO,"Faenor whirls around and "
                "heads back inside.");
      move("/d/shadowgate/void");
      remove();
      return 1;
   }
   return 0;
}

void reply_snarl(string str) {
   tell_room(ETO,"%^MAGENTA%^Feanor says cautiously: "
             "%^RESET%^"+str, TO);
}

void reply_yell(string str) {
   tell_room(ETO,"%^MAGENTA%^Faenor shouts: "
             "%^RESET%^"+str, TO);
}

void reply_ask(string str) {
   tell_room(ETO,"%^MAGENTA%^Faenor asks: "
             "%^RESET%^"+str, TO);
}