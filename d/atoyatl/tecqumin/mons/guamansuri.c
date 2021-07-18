//guamansuri.c - The Tecqumin spirit in an Urn                                 
// Coded by Lujke 29/12/06
#include <std.h>
#include "../tecqumin.h"
#include "../chants.h"
inherit QNPC;

int greeted;
void set_responses();

string pourer;

void create(){
   ::create();
   set_name("Guamansuri");
   set_id( ({"guamansuri","spirit","figure", "ghostly figure",
                                         "ghost", "tecqumin", "xxguamansurixx"}) );
   set_short("Guamansuri, a ghostly %^CYAN%^tecqumin %^BOLD%^"
     +"%^WHITE%^sp%^RESET%^i%^BOLD%^%^WHITE%^r%^RESET%^i%^BOLD%^"
     +"%^WHITE%^t%^RESET%^");
   set_long( (: TO, "long_desc" :) );
   set_gender("male");
   set_race("tecqumin");
   set_body_type("human");
   add_attack_bonus(68); 
   set_overall_ac(-68);
   set_alignment(8);
   set_max_hp(2000);
   set_hp(query_max_hp());
   set_overall_ac(-68);
   set_class("fighter");
   set_mlevel("fighter",49);
   set_level(49);
   set_stats("wisdom",14);
   set_stats("strength",26);
   set_stats("constitution",28);
   set_stats("intelligence",23);
   set_stats("charisma",26);
   set_stats("dexterity",23);
   set_new_exp(50, "normal");
   set("aggressive",0);
   set_response(({"tecqumin"}), ({"yes, I am of the%^CYAN%^"
    +" Tecqumin%^RESET%^. I was a prince among them, before my life"
    +" ended, and consort to the Empress." }));
  force_me("speech speak with a shakey tone, his words interspersed"
    +" with sighing, reedy breaths");
   greeted = 0;
}


string long_desc(){
  string desc;
  desc = "This tall %^CYAN%^Tecqumin ghost%^RESET%^ appears bare chested, with a fine quality %^BOLD%^%^CYAN%^s%^WHITE%^k%^CYAN%^y %^BLUE%^bl%^CYAN%^u%^BLUE%^e %^CYAN%^k%^RESET%^%^CYAN%^i%^BOLD%^lt%^RESET%^.";
  switch(greeted)
  {
  case 0:
    desc += " His face is placid, but an air of ineffable %^CYAN%^sadness%^RESET%^ can be made out in his eyes.";
    break;
  case 1:
    desc += " His face is placid, but an air of wondrous %^BOLD%^%^CYAN%^hope%^RESET%^ can be made out in his eyes.";
    break;
  }
  desc += " He has %^BOLD%^%^RED%^b%^RESET%^%^RED%^a%^BOLD%^ttl%^RESET%^%^RED%^e %^BOLD%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^n%^RED%^t%^RESET%^ carefully applied to his torso and face, and carries a fine %^ORANGE%^macana%^RESET%^ - a sword made of wood. A neat %^RED%^wound%^RESET%^ can be made out just underneath his left pectoral.";
  return desc;
}

void set_pourer(string p){
  pourer = p;
}

void pour_me(object ob){
  object * critters;
  int i, num;
  string n;
  set_pourer((string)ob->query_true_name());
  if (!objectp(ETO)){
    return;
  }
  if (!objectp(ob) || present(ob, ETO)==-1){
    critters = all_living(ETO);
    num = sizeof(critters);
    if (num<1){
      return;
    }
    ob = critters[random(num)];
  }
  meet_me(ob);
  n = (string)ob->query_true_name();
  force_me("emoteat " + n + " shudders and stretches, as though"
   +" waking from a deep sleep. His eyes remain closed for a few"
   +" moments, then snap open, fixing on $N.");
  call_out ("pour2", 3, ob);
}

void meet_me(){
  object * critters;
  int i, num;
  if (!objectp(ETO)){
    return;
  }
  for (i=0;i<num;i++){
    if (objectp(critters[i]) && critters[i]->is_player()){
      critters[i]->set_mini_quest("Met the ghost of Guamansuri,"
             +" consort to the %^CYAN%^Tecqumin%^RESET%^ Empress",1000000,"%^BOLD%^Met the ghost of Guarmansuri, constor to the %^CYAN%^Tecqumin %^RESET%^Empress.");
    }
  }
}

void pour2(object ob){
  force_me("say ...and so the light finds me again. It seems an age"
    +" that it has let me sleep, my slumber undisturbed by the"
    +" arrival of you. Why do you disturb my rest?");
}

void warn_unfettered2(){
  force_me("say %^BLUE%^The %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt"
    +"%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^RESET%^ will most likely"
    +" make for the top of the great Ziggurat. From there, it can absorb"
    +" the power it needs to free itself completely and challenge the"
    +" %^MAGENTA%^Gods%^RESET%^.");
}

void warn_unfettered_loose(){
  force_me("say The prison is empty! %^BLUE%^The Un%^BLUE%^f%^MAGENTA%^e"
    +"%^BLUE%^tt%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^RESET%^ has"
    +" got loose! If you would save these Realms, you must seek it out"
    +" and destroy it or drive it back.");
  call_out("warn_unfettered2", 2);
}

void set_responses(){
  set_response(({"disturb", "rest"}), 
     ({"I slept so long, since my murderer took my life with his"
    +" blade. I do not wish to wake again, until I can be reunited"
    +" with my love." }) );
  set_response(({"tecqumin"}), ({"Yes, I am of the %^CYAN%^Tecqumin"
    +"%^RESET%^. I was a prince among them, consort to the %^BOLD%^"
    +"%^GREEN%^Empress%^RESET%^, before my life was ended."}) );
  set_response(({"murder", "death", "murderer", "killer", "slayer",
                                                 "took your life","battle"}),
   ({"I still see the eyes of my murderer, my wife's brother,"
    +" %^RED%^Epithon%^RESET%^, holding me close to his breast even"
    +" as his blade slid into my chest and pierced my lung. My life"
    +" drained from me, but I could not cry out or call of aid. All"
    +" went %^BOLD%^%^BLACK%^dark%^RESET%^, and I descended into my"
    +" long rest." }) );
  set_response(({"Epithon","epithon"}), ({"%^RED%^Epithon%^RESET%^ and I were"
    +" close, once. As a child, when I first knew his sister, he was"
    +" like the younger brother I never had.", 
      "I don't know why he killed me, but he whispered that he loved"
    +" me and was sorry, but that it was for the good of our people."
        }) );
  set_response( ({"prince", "consort","empress","Empress"}), ({"As the lover and husband"
    +" of the %^BOD%^%^GREEN%^Empress%^RESET%^,  I held the status"
    +" of one beloved of the Gods."}) ); 
  set_response( ({"good of our people", "good of your people", 
                                          "good of the people"}),
      ({"I cannot fathom what purpose my death would have served,"
    +" but if it was for the good of our people, I have no regrets."
    +" I wish only to be reunited with my love."}) );
  set_response(({"reunited"}), ({"I would give anything to see her"
    +" face again, or to hear her voice. Not that I have anything to"
    +" give but my love and thanks. "}) );
  set_response(({"dust"}), ({"The dust is all that remains of my"
    +" body. I know not what sustains it as the vessel for my spirit"
    +", but I feel bound to it, and to the urn as well. Even now, I"
    +" feel the urge to return."}) );
  set_response(({"return"}),({"Yes, I will return to my rest now."}),
       "return" );
  set_response(({"farewell", "goodbye", "so long", "adios"}), 
    ({"Farewell, strangers. May the Gods treat you kindly in the"
    +" lands of the Tecqumin."}), "retreat" );
}

void retreat(object speaker){
  object urn;
  if (!objectp(ETP)){ return;}
  urn = present("urn", ETP);
  if (objectp(urn)){
    force_me("emote %^CYAN%^swirls and %^BOLD%^%^WHITE%^disappears"
      +"%^RESET%^%^CYAN%^ in a flight of %^RESET%^dust%^CYAN%^ into"
      +" the %^ORANGE%^urn%^CYAN%^.");
    urn->set_full(1);
    urn->set_greeted(greeted);
    move("/d/shadowgate/void");
  }
}

int query_greeted(){
  return greeted;
}

void set_greeted(int greet){
  greeted = greet;
}

void greet_empress(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  tell_room(ETO, "%^CYAN%^As the %^RESET%^dusty%^CYAN%^ sp%^BOLD%^"
    +"%^WHITE%^i%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^i%^RESET%^"
    +"%^CYAN%^t form coalesces, it seems to notice the presence of"
    +" the spirit of the %^BOLD%^%^MAGENTA%^Empress%^RESET%^%^CYAN%^"
    +" in the room. It starts to speak, then stammers into shocked"
    +" silence.");
  call_out("greet_empress2", 4);
}

void greet_empress2(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("emote turns toward the dust formed spirit, and"
   +" instantly cries out. It is a strangled sound of intense grief"
   +" and choking pain. ");
  mehaq->force_me("speech crie");
  mehaq->force_me("say %^BOLD%^%^CYAN%^Guam!");
  call_out("greet_empress3", 3);
}

void greet_empress3(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("say %^BOLD%^%^CYAN%^Guamansuri, my love! You have"
    +" returned to me!");
  call_out("greet_empress4", 4);
}

void greet_empress4(){
  force_me("emote swirls momentarily, his form sputtering and almost"
    +" disolving before returning with renewed intensity. He speaks"
    +" at last, his voice deep and vibrant.");
  call_out("greet_empress5",2);
}

void greet_empress5(){
  force_me("speech speak in a deep tone");
  force_me("say %^BLUE%^Mehaq, my lover. I cannot believe that it"
    +" is you. I had thought this day would never come.");
  call_out("greet_empress6", 6);
}

void greet_empress6(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("emoteat guamansuri moves toward $N and the"
    +" %^CYAN%^spirits%^RESET%^ appear to embrace, their forms"
    +" partly merging for a moment. After a brif time, they separate"
    +" once more and continue to speak, their eyes locked on one"
    +" another's faces." );
  call_out("greet_empress7", 4);
} 

void greet_empress7(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("speech say");
  mehaq->force_me("say %^BOLD%^%^CYAN%^My love, I cried so hard when"
    +" you were lost. My grief cost me my kingdom, but I can regret"
    +" it not, if the strength of my love has brought you back to me"
    +" now.");
  call_out("greet_empress8", 4);
}

void greet_empress8(){
  force_me("say %^BLUE%^You lost your kingdom? What do you mean?");
  call_out("greet_empress9", 3);
}

void greet_empress9(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("say %^BOLD%^%^CYAN%^After you died in battle, I"
    +" mourned for you for so long, and withdrew so much from the"
    +" life of our people, that Epithon was able to persuade them"
    +" that he would be better able than I to lead them through the"
    +" crisis. I was so lost in my grief, I had not the heart to"
    +" resist him.");
  call_out("greet_empress10", 6);
}

void greet_empress10(){
  force_me("emote looks shocked.");
  call_out("greet_empress11",2);
}

void greet_empress11(){
  force_me("say %^BLUE%^Lost in battle? But, my love, I did not"
   +" die in battle. We won the battle! Afterwards, when the last of"
   +" the Meccari had fallen, fled or been captured, Epithon"
   +" summoned me to speak, so I supposed, in celebration of the"
   +" victory. But in the privacy of his tent, your half-brother"
   +" betrayed me and slid his knife into my chest without warning."
   +" As my life slid from me, he said he was sorry, but that my"
   +" death was for the good of our people.");
  call_out("greet_empress12", 7);
}

void greet_empress12(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("emote looks stunned");
  call_out("greet_empress13",2);
}

void greet_empress13(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("say %^BOLD%^%^CYAN%^He... he murdered you? I knew"
    +" he had taken advantage of my grief, but I never suspected he"
    +" would have stooped so low. To murder not just a peasant, but"
    +" one of his own class!");
  call_out("greet_empress14", 4);
}

void greet_empress14(){
  object mehaq;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("emote 's %^ORANGE%^eyes%^RESET%^ %^BOLD%^"
    +"%^WHITE%^fl%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^sh%^RESET%^"
    +" angrily. She looks around.");
  call_out("greet_empress15",3);
}

void greet_empress15(){
  object mehaq, *critters;
  int i, num;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("speech shout angrily");
  mehaq->force_me("say %^BOLD%^%^RED%^This outrage shall not go"
    +" unavenged!");
  call_out("greet_empress16",3);
}

void greet_empress16(){
  object mehaq, *critters;
  int i, num;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("emote draws herself up to her full height, her"
    +" face set with cold, simmering rage.");
  call_out("greet_empress17",2);
}

void greet_empress17(){
  object mehaq, *critters, *quests;
  int i, num;
  if (!objectp(ETO)){
    return;
  }
  mehaq = present("mehaq", ETO);
  if (!objectp(mehaq)){
    return;
  }
  mehaq->force_me("speech proclaim in a regal tone");
  mehaq->force_me("say %^BOLD%^%^RED%^To all those present, let it"
    +" be known that my brother Epithon is a betrayer of my people."
    +" Both he and his accomplice Taluc are worthy of the worst"
    +" eternal punishments the Gods can inflict upon them. If any"
    +" can bring the remains of their spiritual souls to me, I shall"
    +" see it done - and amply reward the deed!");
  critters = all_living(ETO);
  num = sizeof(critters);
  if (num<1){return;}
  for (i=0;i<num;i++){
    if ((int)critters[i]->is_player()==1){
      quests = critters[i]->query_mini_quests();
      if (member_array("Tasked to slay Epithon", quests)==-1){
        critters[i]->set_mini_quest("Tasked to slay Epithon",1000000,"%^BOLD%^Tasked to slay Epithon.");
      }
      if (member_array("Tasked to slay Taluc", quests)==-1){
        critters[i]->set_mini_quest("Tasked to slay Taluc",1000000,"%^BOLD%^Tasked to slay Taluc.");
      }
    }
  }
}
