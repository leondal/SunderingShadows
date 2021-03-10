#include <std.h>
#include "../kildare.h"
inherit NPC;
int step1,step2,step3,busy;

void create(){
   ::create();
   set_name("soren");
   set_id(({"soren","old woman","old lady","woman","lady","storyteller","aged woman"}));
   set_short("Soren, an aged woman");
   set_long(
      "Grizzled gray hair hangs limply beside a pale face with "+
      "skin so thin it is nearly transluscent, marking Soren "+
      "as quite an older woman.  Her milky gray eyes stare blankly "+
      "into space, never focusing on any one thing.  She keeps her "+
      "chin raised, so that she often seems to be staring at the air "+
      "above her head.  Her thin lips are faded to a dull cream barely "+
      "distinguisable from her parchment-colored skin.  She wears a "+
      "tattered dress that was perhaps brown at one time.  It now "+
      "bears many rips and tears, though no attempt has been made to "+
      "repair it.  Her arms and legs are slender as twigs and look "+
      "as though they would snap just as easily."
      );
   set_gender("female");
   set_race("human");
   set_body_type("human");
   set_hd(2,1);
   set_stats("strength",6);
   set_stats("charisma",12);
   set_stats("dexterity",6);
   set_stats("constitution",12);
   set_stats("wisdom",22);
   set_stats("intelligence",18);
   set_exp(1);
   force_me("speech say slowly");
   set_emotes(3,({"Soren rocks slowly in her chair, her bony fingers gripping the arms.",
      "Soren tilts her head slightly and listens carefully, breathing lightly."}),0);
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string name;
   set_spoken("wizish");
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(busy) return;
   if((strsrch(msg,"Hi") != -1 || strsrch(msg,"hail") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ello") != -1 ||
      strsrch(msg,"Hail") != -1) && !step1) {
      force_me("emote tilts her head to the side and listens.");
      force_me("say I can hear you there.... What is your name?");
      force_me("say I am Soren.  This village has been my home these many years.  "
         "A strange plague has come upon us of late.  If you would like, I can tell you our story.");
      step1=1;
      step2=0;
      step3=0;
      return;
   }
   if((strsrch(msg,"story") != -1 || strsrch(msg,"tell") != -1 ||
      strsrch(msg,"hear") != -1 || strsrch(msg,"listen") != -1 || strsrch(msg,"yes") != -1 ||
      strsrch(msg,"Yes") != -1) && !step2) {
      force_me("emote nods with a grim expression.");
      force_me("say Our story is a tragic one.  It begins many, many years ago...");
      force_me("say Back then, this village was peaceful.  My twin sister and I were "
         "raised here, in this home.  My parents were tanners, and we were well-respected...");
      force_me("emote sighs briefly and breathes laboriously before continuing.");
      force_me("say I never had cause to believe things would be any different.  Our world "
         "never changed, and that was just how I liked it.  But that was before...");
      step1=0;
      step2=1;
      step3=0;
      busy=1;
      call_out("story_1",7);
      return;
   }
   if((strsrch(msg,"more") != -1 || strsrch(msg,"hear") != -1 ||
      strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1) && (!step3)){
      force_me("emote nods briefly, her face tightening a bit.");
      force_me("say I will continue the story, only because I want to warn those who "
         "come after me.  She is still out there... I know this, even if no one believes me.");
      force_me("say I lost my sister that day.  She ran off into the woods and became a "
         "beast that plagued my mind.  I would catch glimpses of her at times, running "
         "wild in skins with blood streaked in her hair.  She was savage and cruel, "
         "sometimes catching townspeople and torturing them with a chilling chase up "
         "the mountain passes.");
      force_me("say She never returned here again ... and after a time, she was not seen "
         "anymore.  The beast she became, the one that chased down my townspeople ... it "
         "looked nothing like her any longer.");
      force_me("emote grips the handles of her rocking chair and rocks slowly.");
      force_me("say Would you like to know what I believe happened?");
      step1=0;
      step2=0;
      step3=1;
      return;
   }
   if((strsrch(msg,"appen") != -1 || strsrch(msg,"yes") != -1 ||
      strsrch(msg,"Yes") != -1 || strsrch(msg,"what") != -1 ||
      strsrch(msg,"What") != -1) && step3){
      force_me("say I think my sister changed further, became something darker.  "
         "I can feel her, still living, even though she is no longer my sister.");
      force_me("say A few decades after she vanished, the perytons descended upon us.  "
         "Born hunters, they are ... made by a twisted deity who no longer exists himself.  "
         "They hunt down humans for their hearts.");
      force_me("emote rocks her chair slowly as she sighs.");
      force_me("say It is no coincidence they found us after she vanished.  She brought "
         "them here ... and I believe I know where she lives.");
      force_me("say My vision may be gone, but I see her in my mind, see the trails north "
         "of the village, the way they wist and wind, hiding her in plain sight.");
      force_me("say I don't know what end she will meet, but I think we are tied together still.");
      force_me("emote begins rocking in her chair once more, growing completely silent.");
      step1=0;
      step2=0;
      step3=0;
      return;
   }
   return;
}

void story_1(){
   force_me("emote shakes her head, and her eyes grow dark.");
   force_me("say When I was around twelve years old, my sister began to change.  "
      "Her beautiful golden hair darkened and grew dim.  The light in her eyes burned out...");
   force_me("say She would spend days alone in the forest, when before she had always "
      "taken me with her.  One day, I followed her...and there I saw something I will never forget.");
   force_me("emote sucks air through her thin lips.");
   force_me("say My beautiful sister ... she was there with a strange man.  I had "
      "never seen anything like him before.  He was dressed in a cloak made of skins "
      "that covered every inch of him.  He had a knife over my sister and was asking "
      "her something... Did she accept?  That was his question.");
   call_out("story_2",7);
   return;
}

void story_2(){
   force_me("say I tried to scream but couldn't.  And as I rushed forward, I heard her voice, calm and clear.");
   force_me("say \'I accept the Faceless One and will make him my all\' were the words that pierced my heart on that day.");
   force_me("emote pauses and tilts her head, listening carefully.");
   force_me("say Are you still there? did you want to hear more?");
   step2=1;
   busy=0;
   return;
}