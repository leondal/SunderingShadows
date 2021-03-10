#include <std.h>
#include <daemons.h>
#include <move.h>
#include "../lothwaite.h"
inherit MONSTER;

string *asked;
string *killers;
int step1;
int step2;
int step3;
int FLAG;

#define ALIGN_D "/daemon/alignment_d.c"

void create(){
object obj;
	::create();
	set_name("firbolg king");
	set_id(({"ghost","undead","monster","firbolg","giant","firbolg ghost","giant ghost","king","firbolg king"}));
	set_short("A regal firbolg ghost");
	set_gender("male");
	set_size(3);
      set_long(
        "This looming ghost stands well over fourteen feet tall.  "+
        "His translucent form still sports a simple %^RESET%^"+
        "%^ORANGE%^leather breastplate %^CYAN%^and %^ORANGE%^skirt "+
        "%^CYAN%^while his feet are clad in %^ORANGE%^leather shoes"+
        "%^CYAN%^.  A most impressive %^BOLD%^sword %^RESET%^%^CYAN%^"+
        "the color of %^BOLD%^%^WHITE%^ice%^RESET%^%^CYAN%^ still "+
        "peeks from the sheath slung across his back.  His long hair "+
        "is %^RESET%^colorless %^CYAN%^and flows in waves to his "+
        "shoulders.  It is held back from his face by a simple "+
        "braided leather headband, and he wears a beautiful amulet "+
        "that glistens a %^RESET%^ghostly white%^CYAN%^."
      );
	set_property("undead",1);
	set_hd(30,6);
	set_max_level(35);
	set_body_type("firbolg");
	set_overall_ac(-10);
	set_alignment(4);
	set_race("ghost");
	set_max_hp(random(100)+750);
	set_hp(query_max_hp());
	set_class("fighter");
	set_mlevel("fighter",30);
	set_level(30);
      new(OBJ"health_amulet")->move(TO);
      command("wear amulet");
      obj = new(OBJ"ethereal_bplate");
         if(random(4)){
            obj->set_property("monsterweapon",1);
         }
      obj->move(TO);
      command("wear breastplate");
      new(OBJ"ghostsword")->move(TO);
      new(OBJ"frost_sheath")->move(TO);
      command("put sword in sheath");
      command("wear sheath");
	set_funcs(({"touch","drain","scare"}));
      set_func_chance(10);
	set_exp(10000+random(1500));
      set_property("full attacks",1);
 	add_money("platinum",random(150)+100);
	set_property("swarm",1);
	set("aggressive",0);
	set_property("weapon resistance",2);
	set_mob_magic_resistance("average");
      command("speech speak with a rolling rumble");
}

int touch(object targ){
	if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
		tell_object(targ,"%^BOLD%^%^CYAN%^The ghost reaches "+
               "out and touches your cheek, draining your strength!");
		tell_room(ETO,"%^BOLD%^%^CYAN%^The ghost"+
		   " touches "+targ->query_cap_name()+"'s cheek and seems to drain"+
		   " "+targ->query_objective()+" of "+targ->query_possessive()+""+
		   " strength.",targ);
		   targ->add_stat_bonus("strength",-1);
		   return 1;
	}else{
		tell_object(targ,"You successfully resist the icy"+
		   " touch of the ghost.");
		tell_room(ETO,"The ghost touches "+targ->query_cap_name()+","+
		   " but "+targ->query_subjective()+" seems to be alright.",targ);
		return 1;
	}
	return 1;
}

int drain(object targ){
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^The ghost seems to drain"+
			" your life force from you!");
			tell_room(ETO,"%^BOLD%^The ghost seems"+
			" to drain "+targ->query_cap_name()+"'s life force"+
			" from "+targ->query_objective()+"!",targ);
                     targ->resetLevelForExp(-(random(500)+500));
			return 1;
		}else {
			tell_object(targ,"%^BOLD%^The ghost attempts to drain"+
			" away some of your life but fails.");
			tell_room(ETO,"The ghost tries to drain"+
			" away "+targ->query_cap_name()+"'s life force but"+
			" nothing seems to happen.",targ);
			return 1;
		}
		return 1;
}

int scare(object targ){
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes and you feel yourself "+
                     "frozen in fear!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^"+targ->QCN+" looks "+
                     "terrified as "+targ->QS+" gazes at the ghost!",targ);
                  targ->set_tripped(3,"%^BOLD%^You are frozen in fear of the ghost.");
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes, but you resist its power!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^The ghost stares "+
                     "at "+targ->QCN+" but nothing happens.",targ);
			return 1;
		}
		return 1;
}

void heart_beat(){
   ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!random(2)){
       if(query_hp() < query_max_hp()){
         add_hp(random(4));
       }
    }
    if(query_attackers() == ({})){
       force_me("sheath sword");
    }else{
       if(!present("frost brand")){
          force_me("draw sword");
       }
    }
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name.
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   object ob;
   object ob2;
   object obj,obj2;
   string race;
   string name;
   set_spoken("wizish");
   if (!objectp(who)) {
       return;
   }
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("lothwaite_asked");
   killers = SAVE_D->query_array("lothwaite_killers");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("emote snarls as his visage grows fearsome.");
      force_me("say %^CYAN%^Vile betrayer!  It is your kind "+
         "who will bring ruin on all!  I will never forget your "+
         "attack on me!");
      force_me("draw frost brand");
      force_me("kill "+name+"");
      return;
   }
   if (objectp(current) && who != current) {
     force_me("emote looks right through those who try to interrupt "+
        "his earnest conversation with "+current->QCN+".");
     return;
   }
   if(FLAG == 1){
      if(strsrch(msg,"gold") != -1) {
         force_me("say %^CYAN%^Very well, here is your chosen reward "+
            "for your aid!  Spend it well!");
         who->add_money("gold",15000);
         force_me("emoteat "+name+" gives $N a large sack of gold.");
         FLAG = 0;
         call_out("go_away",0);
         return;
      }
      if(strsrch(msg,"staff") != -1) {
         force_me("say %^CYAN%^Very well, here is your chosen reward "+
            "for your aid!  Use it well!");
         ob = new(OBJ"ghoststaff");
         force_me("emote lifts the intricate staff from the pile.");
//         force_me("give staff to "+name+"");
         force_me("emoteat "+who->query_name()+" presents $N with a grand staff.");
         if (ob->move(who) != MOVE_OK){
            force_me("say Hmm...it seems you cannot carry this, so I will "+
               "rest it at your feet.");
            ob->move(ETP);
         }
         FLAG = 0;
         call_out("go_away",0);
         return;
      }
      if(strsrch(msg,"steel") != -1) {
         force_me("say %^CYAN%^Very well, here is your chosen reward "+
            "for your aid!  Use it well!");
         force_me("emote sighs softly as he removes the scabbard from "+
            "his back and hands the sword over ceremoniously.");
         if(!present("frost sheath")){
            obj = new(OBJ"ghostsword");
            obj->move(TO);
            obj2 = new(OBJ"frost_sheath");
            obj2->move(TO);
            force_me("put sword in sheath");
         }
         ob = present("frost sheath");
         if (ob->move(who) != MOVE_OK){
            force_me("say %^CYAN%^Hmm...it seems you cannot carry this, so I will "+
               "rest it at your feet.");
            ob->move(ETP);
         }
         force_me("say %^CYAN%^This blade was granted me by my loyal "+
            "citizens.  May all your days be blessed as mine were.");
         FLAG = 0;
         call_out("go_away",0);
         return;
      }
      if((strsrch(msg,"nothing") != -1 || strsrch(msg,"no reward") != -1) && !ALIGN_D->is_evil(TP)) {
         force_me("emote pauses for a moment with a thoughtful expression.");
         force_me("say %^CYAN%^It is not often, friend, that we "+
            "find one with a heart as generous as yours.  Such "+
            "selflessness deserves its own reward.%^RESET%^");
         force_me("emote ponders briefly before nodding to himself.");
         force_me("say %^CYAN%^Here, you should have this, as you "+
            "have reminded me of the goodness inherent in some.  "+
            "I thank you for your aid, your kindness...and your lesson.%^RESET%^");
         if(!present("belt of giant strength")){
            obj = new(OBJ"ghostbelt");
            obj->move(TO);
         }
         ob = present("belt of giant strength");
         while(ob->query_property("enchantment") < 1){
            ob->remove_property("enchantment");
            ob->set_property("enchantment",1);
         }
         if (ob->move(who) != MOVE_OK){
            force_me("say %^CYAN%^Hmm...it seems you cannot carry this, so I will "+
               "rest it at your feet.");
            ob->move(ETP);
         }
         force_me("say %^CYAN%^This belt has meant much to my "+
            "people, but I think that with it in the possession "+
            "of one so kind-hearted, I can return them to rest.%^RESET%^");
         force_me("emote gives up possession of the belt.");
         FLAG = 0;
         call_out("go_away",0);
         return;
      }
      force_me("say %^CYAN%^I am sorry, my friend.  I did not understand "+
         "that.  Simply say %^YELLOW%^gold%^RESET%^, %^GREEN%^staff"+
         "%^RESET%^, or %^BOLD%^steel%^RESET%^%^CYAN%^.");
      return;
   }
   if(who->query_quests()) {
     if(member_array("Lothwaite Quest",who->query_quests()) != -1) {
       switch( (string)who->query("lothwaitequest") ) {
         case "G" :
           force_me("say %^CYAN%^Thank you again for your aid.  You "+
              "are ever welcome in my kingdom.");
           force_me("say %^CYAN%^If you are looking for a way out, "+
              "speak with the shaman.");
           break;
         case "E" :
           force_me("say %^CYAN%^I have heard of your foul dealings with "+
              "imps and lesser sorts.  Begone!");
           force_me("snarl "+name);
           break;
         default: tell_object(TP,"Oops, you must have done the quest "+
            "early!  Tell Circe so she can fix you.");
         break;
       }
        return;
     }
   }
   if(strsrch(msg,"out") != -1 || strsrch(msg,"way out") != -1 ) {
      force_me("say %^CYAN%^I will release you from the barrows when "+
         "you return the belt to me.  Else, you will have to fight "+
         "your way out!");
      return;
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say %^CYAN%^Have you returned with my belt?");
     if(!random(3))
      force_me("say %^CYAN%^I do hope you have had some luck.  "+
         "My kinsmen are without rest until it is returned.");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("emote hovers over you imposingly, his hair "+
         "dancing on an unfelt breeze.");
      force_me("say %^CYAN%^Hail, traveler!  I am King Celyddon, "+
         "ruler of Lothwaite during the time of the Giant Wars.");
      if(race == "firbolg") {
         force_me("say %^CYAN%^Blessings upon you...it is good "+
            "to see one of my own kind.");
         force_me("smile "+name);
         force_me("say %^CYAN%^No doubt you will aid me?");
         return;
      }
      else {
         force_me("eye "+name);
         force_me("say %^CYAN%^I do not know what one of your kind "+
            "is doing lingering here.");
         force_me("say %^CYAN%^Yet...if you were allowed in, "+
            "perhaps your heart is purer than it would seem.  "+
            "Will you aid me?");
         return;
      }
   }
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 ||
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 ||
    strsrch(msg,"how") != -1  || strsrch(msg,"not evil") != -1)&& step1 && !step2){
      force_me("emote sighs, a rumble that echoes around the hall.");
      force_me("say %^CYAN%^During the Giant Wars, our people were "+
         "graced with a powerful shaman, Helgatha Rothmar.  Helgatha "+
         "had mysterious powers that reached beyond the ordinary "+
         "healing.  He could manipulate things...some even whisper "+
         "that he touched the Weave.");
      force_me("emote shrugs.");
      force_me("say %^CYAN%^Whatever he touched, his power was "+
         "great, and I believe he was blessed by the gods.  He "+
         "made for me a fantastic golden belt that shimmered "+
         "as the rainbow.");
      force_me("say %^CYAN%^Have you seen such a belt?");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"belt") != -1 || strsrch(msg,"golden belt") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"gem") != -1 ||
   strsrch(msg,"no") != -1 || strsrch(msg,"Yes") != -1) && step2 == 1) {
      force_me("say %^CYAN%^Please, look for the belt.  I "+
         "know that until it is returned, my people will "+
         "not rest.");
      force_me("emote pauses and looks thoughtful.");
      force_me("say %^CYAN%^They will not be kind, and they "+
         "will likely see you as a threat...be forewarned.");
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("lothwaite_asked", name);
      }
      step3 == 1;
		return;
  }
  switch(random(10)){
      case 0:
         force_me("say %^CYAN%^Have you been helping in my search?");
         break;
      case 1:
         force_me("say %^CYAN%^Beware my kindred...they are kind "+
            "souls, but that foul thief has disturbed their rest.");
         break;
      case 2:
         force_me("say %^CYAN%^There are many things hidden in "+
            "these caverns.  You are welcome to explore, but be "+
            "careful to not anger the spirits.");
         break;
      case 3:
         force_me("emote mutters to himself as he floats around the room.");
         break;
      case 4:
         force_me("emote looks at you thoughtfully.");
         break;
      case 5:
         force_me("emote listens to something on the wind.");
         break;
      default:
         force_me("emote floats before the statue, his eyes on "+
            "it thoughtfully.");
   }
   return;
}

void receive_given_item(object obj){
   object item;
   int size;
   asked = SAVE_D->query_array("lothwaite_asked");
   killers = SAVE_D->query_array("lothwaite_killers");
   if(!objectp(obj)) return;
   if(member_array(TPQN, killers) != -1) {
      force_me("emote snarls as his visage grows fearsome.");
      force_me("say %^CYAN%^Vile betrayer!  It is your kind "+
         "who will bring ruin on all!  I will never forget your "+
         "attack on me!");
      force_me("kill "+TPQN+"");
     return;
   }
   if(member_array("Lothwaite Quest",TP->query_quests()) != -1) {
      if((string)obj->query_name() == "belt of giant strength" && (string)TP->query("lothwaitequest") == "G"){
         force_me("say %^CYAN%^I thank you for your dedication.  Your "+
            "loyalty will be well-rewarded.  You may choose one of these "+
            "three rewards - %^YELLOW%^gold%^RESET%^, %^GREEN%^staff"+
            "%^RESET%^, or %^BOLD%^steel%^RESET%^.");
         force_me("emote motions to a pile of gold, an intricate "+
            "staff, and his magnificent sword in turn.");
         force_me("say %^CYAN%^Be warned, though, that the staff "+
            "may only be wielded by one of the church who is purely dedicated to "+
            "the service of a deity.");
         force_me("say %^CYAN%^Simply say the word of which you choose, "+
            "and it will be yours.");
         if(ALIGN_D->is_good(TP)){
            tell_object(TP,"%^YELLOW%^As you listen to the king, "+
               "you realize that you might also choose %^CYAN%^"+
               "nothing %^YELLOW%^as your reward, should your "+
               "heart be full enough from a good deed well done.%^RESET%^");
         }
         FLAG = 1;
         call_out("reset_give_out",30);
         call_out("open_up",1);
         return;
      }
       switch( (string)TP->query("lothwaitequest") ) {
         case "G" :
            force_me("say %^CYAN%^Thank you for the gift!  But after "+
               "returning the belt, you have already given so much.");
            force_me("smile "+TPQN);
            force_me("say %^CYAN%^Here, return to the world of light "+
               "and leave this dim place!");
            call_out("open_up",1);
            break;
         case "E" :
           force_me("say %^CYAN%^I have heard of your foul dealings with "+
              "imps and lesser sorts.  Begone!");
           force_me("snarl "+TPQN);
           break;
         default:  tell_object(TP,"Ack! You must have done the quest "+
            "early.  Tell Circe so she can fix you.");
            break;
       }
      return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("say %^CYAN%^Hail, traveler, and thank you for "+
        "the gift.  But...why are you bringing this to me?  Have "+
        "we met?");
     force_me("emote looks doubtful.");
     return;
   }
   if((string)obj->query_name() != "belt of giant strength") {
       force_me("say %^CYAN%^Hail, traveler!  But I am afraid this "+
          "is of no help to me.  Thank you, nonetheless.");
       return;
   }
   if((string)obj->query_name() == "belt of giant strength") {
      force_me("emote takes the belt with a wide smile.");
      obj->remove();
      if(member_array(TPQN, asked) != -1)
        SAVE_D->remove_name_from_array("lothwaite_asked", TPQN);
//to clean up the array after it's not needed any more
      if(member_array("Lothwaite Quest",TP->query_quests()) == -1){
      force_me("say %^CYAN%^I thank you for your dedication.  Your "+
         "loyalty will be well-rewarded.  You may choose one of these "+
         "three rewards - %^YELLOW%^gold%^RESET%^, %^GREEN%^staff"+
         "%^RESET%^, or %^BOLD%^steel%^RESET%^.");
      force_me("emote motions to a pile of gold, an intricate "+
         "staff, and his magnificent sword in turn.");
        force_me("say %^CYAN%^Be warned, though, that the staff "+
           "may only be wielded by one of the church who is purely dedicated to "+
           "the service of a deity.");
        force_me("say %^CYAN%^Simply say the word of which you choose, "+
           "and it will be yours.");
        if(ALIGN_D->is_good(TP)){
           tell_object(TP,"%^YELLOW%^As you listen to the king, "+
              "you realize that you might also choose %^CYAN%^"+
              "nothing %^YELLOW%^as your reward, should your "+
              "heart be full enough from a good deed well done.%^RESET%^");
        }
        FLAG = 1;
        tell_object(TP,"%^YELLOW%^You have finished the Quest of "+
           "Lothwaite and returned the spirits to their rest!");
        TP->set_quest("Lothwaite Quest");
        TP->set("lothwaitequest","G");
        TP->fix_exp(150000,TP);
        "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" returned the belt to "+
           "the firbolgs of Lothwaite.");
        call_out("reset_give_out",30);
        call_out("open_up",1);
        return;
      }
      force_me("say %^CYAN%^Thank you again for all your help!");
      call_out("open_up",1);
      return;
   }
   return;
}

int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("lothwaite_killers", "stringname")
    int hold;
    killers = SAVE_D->query_array("lothwaite_killers");
    hold = ::kill_ob(victim, which);
    if(member_array((string)victim->query_name(), killers) != -1 || !interactive(victim) || !victim->is_player()) return hold;
    SAVE_D->set_value("lothwaite_killers", victim->query_name());
    command("say %^CYAN%^Your vile actions will not be forgotten!");
    command("draw sword");
    return hold;
}

void reset_give_out() { FLAG = 0; }

void go_away() {
   force_me("emote shimmers faintly, then disappears.");
   TO->move("/d/shadowgate/void");
   TO->remove();
}

void open_up() {
   tell_room(ETO,"%^BOLD%^%^CYAN%^The dome overhead shimmers with "+
      "a faint light before it begins to open slowly!");
   tell_room(ETO,"%^YELLOW%^It finally opens, and a stairway appears "+
      "leading upwards!");
   "/d/barriermnts/lothwaite/rooms/b60"->add_exit(PATHEXIT"stones2","out");
   return;
}

void die(mixed ob){
   open_up();
   ::die(ob);
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}

// Added a couple of functions to allow wizzes to check the killers array
// and to remove players names from it if they got there by accident
// (eg auto-attacked by other mobs in the king's room).
//  Lujke, January 28th 2007

void pardon_killer(string killer){
  SAVE_D->remove_name_from_array("lothwaite_killers", killer);
}

string * query_killers(){
  return SAVE_D->query_array("lothwaite_killers");
}
