#include <std.h>
#include "../kildare.h"
inherit NPC;

void create()
{
   ::create();
   set_name("caldon");
   set_id(({"caldon","leader","village leader"}));
   set_short("Caldon, village reeve");
   set_long(
      "The distinguished leader of Kildare Glen for several decades, "+
      "Caldon's mobility is limited now due to permanent injuries sustained "+
      "while defending the town.  He is unable to leave his home often and "+
      "presides over town matters while seated behind his desk.  He is dressed "+
      "well in a dark gray wool coat worn over a white button down shirt.  His "+
      "short black hair is speckled with gray, and his storm gray eyes hold a "+
      "wisdom developed over the years.  The only jewelry he wears is a silver "+
      "signet ring with the crest of Kildare Glen, a shepherd's crook slanted "+
      "across a backdrop of mountain peaks."
      );
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(16,4);
   set_stats("strength",15);
   set_exp(1);
   new(OBJ"sigring.c")->move(TO);
   force_me("wear ring");
   new(OBJ"brasskey.c")->move(TO);
   new("/d/common/obj/misc/pouch.c")->move(TO);
   force_me("put key in pouch");
   force_me("wear pouch");
}

void catch_say(string msg){
    if(!objectp(TO)) return;
    ::catch_say(msg);    
    if(!objectp(TP)) return;
    if(interactive(TP)){
        call_out("reply_func",0,msg,TP);
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
      force_me("say Greetings, traveller.  What brings you to Kildare Glen?");
      return;
   }
   if(strsrch(msg,"proof") != -1 || strsrch(msg,"Proof") != -1){
      force_me("say If you bring back proof that you have defeated the king of the beasts that "
         "plague us, give it to Guyon, our spiritual leader.  He will cleanse it and give you a "
         "fitting reward.");
      return;
   }
   if(strsrch(msg,"eart") != -1){
      force_me("emote straightens in his seat and looks impressed."); 
      force_me("say You returned with the heart of the king?  Amazing!  That will "
         "slow them down for a time at least ... and if we are lucky, it might end "
         "their reign of terror!");
      force_me("smile "+TPQN+"");
      force_me("say For this, Guyon will craft you something wonderful!  "
         "Please, take the heart to him.  He's just in the next room.  "
         "Thank you ... and well done!");
      return;
   }
   if(strsrch(msg,"ntler") != -1 || strsrch(msg,"horn") != -1 || strsrch(msg,"Horn") != -1){
      force_me("emote looks up and smiles.");
      force_me("say You've returned with the horn of the beast? Fantastic!  "
         "They are very sharp and hard to handle, but Guyon knows the secret of "
         "harnessing their power into a wonderful weapon.");
      force_me("say Please, see him in the next room.  If you give it to him, "
         "he will give you your reward.  I thank you for your aid!");
      return;
   }
   if(strsrch(msg,"claw") != -1 || strsrch(msg,"Claw") != -1 || strsrch(msg,"alon") != -1){
      force_me("say Ahh...the claw of the beast.  They are quite sharp and never "
         "seem free of the stains they bear.  I am sure it has something to do with their demonic nature...");
      force_me("say I am impressed that you were able to defeat the king!  Guyon will "
         "make something from that to help protect you as your reward.  Please, take it to "
         "him in the next room.  And I thank you for your aid!  It will be remembered.");
      force_me("smile "+TPQN+"");
      return;
   }
   if(strsrch(msg,"rail") != -1){
      force_me("emote frowns deeply and nods.");
      force_me("say The trails north of here are filled with danger, I'm afraid.  I cannot "
         "ensure your safety if you choose to venture there.");
      force_me("emote sighs and looks out the window.");
      force_me("say Our village is besieged by corrupt winged beasts called perytons. They "
         "are twisted and evil.  If you are brave and strong, we could greatly use your aid.  "
         "If you could bring back proof of the peryton king's destruction, you would be rewarded.");
      return;
   }
   if(strsrch(msg,"help") != -1 || strsrch(msg,"Help") != -1 || strsrch(msg,"aid") != -1){
      force_me("emote raises an eyebrow.");
      force_me("say You are truly interested in helping our village?");
      force_me("say If you are, I must stress that I cannot guarantee your safety.  "
         "However, I will reward you as best I can if you bring back some sort of proof "
         "of the peryton king's death.  A body part perhaps... I'm afraid I'm not quite "
         "sure what you'll find.");
      force_me("say When you have defeated the king, bring back whatever you can.  "
         "I will have Guyon, our Guide, fashion you a fitting reward.  You simply need to "
         "give him whatever you bring back.");
      return;
   }
   if(strsrch(msg,"illage") != -1 || strsrch(msg,"eryton") != -1){
      force_me("say I have been the leader of this village for many years now.  At one time, "
         "I was captain of the guard.  Not long after the perytons discovered our home, I led "
         "a group to defeat them.");
      force_me("emote shakes his head, and his eyes grow dark.");
      force_me("say Sadly, I was one of the only two to return ... the other survivor had to "
         "drag me back, as I had taken a grievous wound.  I am unable to stand or walk for long now.  "
         "And I am sorry to say my brother-in-arms has since lost his life to the perytons.");
      force_me("emote looks up, his expression grave.");
      force_me("say Never have I seen beasts like these.  I urge you, please use caution.");
      return;
   }
   return;
}

