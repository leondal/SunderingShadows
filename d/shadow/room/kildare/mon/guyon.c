//guyon.c
#include <std.h>
#include "../kildare.h"
#include <daemons.h>
inherit NPC;

void create(){
   ::create();
   set_name("guyon");
   set_id(({"guyon","Guyon","guide","Guide","cleric"}));
   set_short("Guyon, Kildare Glen Guide");
   set_long("The spiritual leader of Kildare Glen is a rather impressive figure, "+
      "standing around six and a half feet tall.  He has a calm demeanour, though "+
      "he looks as if he could handle himself.  He has long light brown hair "+
      "pulled back at the base of his neck and wears a leather cord with a strange "+
      "hooked talon dangling from it.  He is dressed in a long black robe gathered "+
      "at the waist with a leather belt and covered with a long green and gold "+
      "tabard bearing a shepherd's crook over a range of mountain peaks.  His feet "+
      "are covered in tall black leather boots, and he wears a braided leather "+
      "bracelet on his right wrist.  He seems quite serious but kind, and would "+
      "probably have a wealth of information about this town."
   );
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(15,5);
   set_alignment(2);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-6);
   set_class("cleric");
   set_mlevel("cleric",15);
   set_level(15);
   set_stats("wisdom",18);
   set_stats("strength",18);
   set_stats("constitution",16);
   set_stats("intelligence",14);
   set_stats("charisma",14);
   set_stats("dexterity",12);
   set_exp(500);
   set_spells(({
   "limb attack",
   "cause blindness",
   "hold person",
   }));
   set_spell_chance(100);
   set("aggressive",0);
}

void catch_say(string msg){
    if(!objectp(TO)) return;
    ::catch_say(msg);    
    if(!objectp(TP)) return;
    if(interactive(TP)){
        call_out("reply_func",1,msg,TP);
        return;
    }
    return;
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1 || strsrch(msg,"Hey") != -1){
      force_me("emote nods and gives a small smile.");
      force_me("say Hello there, traveller.  What brings you to our valley?");
      return;
   }
   if(strsrch(msg,"proof") != -1 || strsrch(msg,"Proof") != -1){
      force_me("emote raises an eyebrow.");
      force_me("say If you have brought back proof of the peryton king's demise, please "
         "give it to me.  I will fashion a fitting reward for you!");
      force_me("say Our village is greatly in need of aid.  We have few warriors, and not many "
         "of them are left, but this place is our home.");
      return;
   }
   if(strsrch(msg,"hadow") != -1){
      force_me("say The peryton's shadow is the msot disturbing ... even more so than "
         "the sight of a twisted stag's head on an eagle's body.  Casting the shadow of a man...");
      force_me("emote shakes his head and narrows his eyes.");
      force_me("say That is purely demonic.");
      return;
   }
   if(strsrch(msg,"eryton") != -1){
      force_me("say Never has there been a beast more foul than the dread peryton!");
      force_me("say A twisted creation ... it surely cannot exist in nature!  A giant "
         "green eagle with the head of a black stag.  Antlers that twist and turn, "
         "glittering black as the abyss itself.  Horrible fangs and empty red eyes "
         "that glow with the fires of hell.  Their claws tear flesh, and they can rip "
         "the heart right out of a full-grown man where he stands.");
      force_me("emote sighs and shakes his head, glancing down at his hands.");
      force_me("say Fell beasts ... beware them.");
      return;
   }
   if(strsrch(msg,"rail") != -1){
      force_me("emote nods and frowns.");
      force_me("say The trails north of Kildare Glen were once pleasant and safe "
         "for our people.  We foraged for food there, and there our children played.");
      force_me("emote shakes his head slowly.");
      force_me("say Now the perytons have taken over, and we can no longer venture far "
         "from the village.  Some of our people are even too frightened to leave their homes.");
      return;
   }
   if(strsrch(msg,"eart") != -1){
      force_me("say Aye, 'tis true, I'm afraid.  These demonic beasts eat the hearts "
         "of those who cannot escape them.  They seem interested in only humans or those "
         "of similar form.");
      force_me("say Legend has it that they hate all life and believe they can escape this "
         "world by consuming the perfect heart.  I vow to make them leave this world by the "
         "might of my mace instead.");
      return;
   }
   return;
}

void receive_given_item(object obj){
   object ob;
   if(!objectp(obj)) return;
   if(!objectp(TP)) return;
   if((string)obj->query_name() == "peryton talon") {
      obj->remove();
         force_me("say This is indeed a claw from the dread beast!  "+
            "You have slain one of them and as such should be "+
            "rewarded for aiding our people.");
         force_me("emote takes up a strip of leather and, speaking "+
            "a quiet incantation, begins slowly binding the talon.");
         force_me("say May the spirit of our village protect you "+
            "in your travels.");
         tell_object(TP,"Guyon holds up a leather necklace with a "+
            "talon before giving it to you.");
         ob = new(OBJ"talisman");
         if((int)TP->query_size() == 1) {
            ob->set_size(1);
         }
         if((int)TP->query_size() == 2) {
            ob->set_size(2);
         }
         if((int)TP->query_size() == 3) {
            ob->set_size(3);
         }
         ob->move(TP);
   }
   else if((string)obj->query_name() == "peryton horn") {
      obj->remove();
      force_me("emote turns the twisting horn over in his hands with "+
         "an expression of mild surprise.");
      force_me("say Removing the horn of a peryton without harming "+
         "yourself is a tough task indeed.  Because you have done "+
         "so well and helped defend us, I will make this into an "+
         "impressive sword for you.");
      force_me("emote carefully handles the horn so as not to cut "+
         "himself.");
      force_me("emote mutters quietly and chants softly as he sprinkles "+
         "reddish dust from a pouch at his side over the horn.");
      force_me("emote wraps the base of the horn in leather cording, "+
         "rhythmically chanting as he works.");
      force_me("say This blade will defend you well as it holds within "+
         "it the fighting spirit of the beast itself.");
      tell_object(TP,"Guyon carefully gives you the newly-forged blade.");
      new(OBJ"hornblade.c")->move(TP);
   }
   else if((string)obj->query_name() == "peryton heart") {
      obj->remove();
      force_me("emote raises his eyebrows and shakes his head slightly.");
      force_me("say Most impressive, bringing back the heart of the beast!  "+
         "Rarely can a heart be found within one of them.  The king of "+
         "the foul beasts will now be put down for a time, until they find "+
         "a new one.");
      force_me("emote lays the heart upon the table and chants softly "+
         "as he sprinkles black powder over it.  He closes his eyes "+
         "and concentrates deeply before the heart fades to black and "+
         "crumbles, disintegrating into a fine black vapor which he "+
         "gathers into a vial and stoppers.");
      force_me("say Do not fear to use the vial when you are in danger.  The "+
         "beast's spirit is bound only to protect the one who smashes the vial "+
         "now.  I thank you again for your great deed.  Your charity will be "+
         "remembered.");
      tell_object(TP,"Guyon hands you a small glass vial.");
      new(OBJ"peryvial.c")->move(TP);
   }
}
