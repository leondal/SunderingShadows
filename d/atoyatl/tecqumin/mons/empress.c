//empress.c - The Tecqumin Empress                                 
// Coded by Lujke 29/12/06
#include <std.h>
#include "../tecqumin.h"
inherit QNPC;

nosave int BEAT;

void set_responses();
void receive_spirit(object giver, string spirit_name);
void bridge_speech();
void retreat_speech();
void defeat_speech();

void create(){
   ::create();
   set_name("Mehaq");
   set_id( ({"mehaq","empress","empress mehac", "ghost", "Mehaq",
             "Empress Mehaq", "empress Mehaq", "tecqumin"}) );
   set_short("Mehaq, Empress of the Tecqumin");
   set_long("%^RESET%^The spirit of %^CYAN%^Mehaq%^RESET%^ shines with a"
     +" strange, %^BOLD%^%^WHITE%^insubstantial%^RESET%^ light. Her"
     +" %^CYAN%^ghostly form%^RESET%^ is that of a middle aged woman, tall"
     +" and slender, with an erect and dignified posture. Her skin"
     +" is of an amber hue, and her face is round in shape, with"
     +" prominent cheekbones. She has dark, almond shaped eyes. She"
     +" wears %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
     +"%^YELLOW%^ld h%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^op"
     +"%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^d%^RESET%^ earrings and"
     +" her cheeks are decorated with%^RESET%^ geometric %^BLUE%^blue tattoo"
     +" lines%^RESET%^ and a few dots of scarification. On her head,"
     +" she wears a %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
     +"%^YELLOW%^ld c%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^rcl"
     +"%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^t%^RESET%^, which is mirrored by"
     +" a %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^"
     +"ld t%^RESET%^%^ORANGE%^or%^BOLD%^%^YELLOW%^c%^RESET%^ at her"
     +" throat.");
   set_gender("female");
   set_race("ghost");
   set_body_type("human");
   set_hd(90,5);
   set_alignment(5);
   set_max_hp(2500);
   set_hp(query_max_hp());
   set_overall_ac(-55);
   set_class("fighter");
   set_mlevel("fighter",55);
   set_level(55);
   set_stats("wisdom",19);
   set_stats("strength",18);
   set_stats("constitution",18);
   set_stats("intelligence",18);
   set_stats("charisma",16);
   set_stats("dexterity",18);
       set_new_exp(55, "normal");
   set("aggressive",0);
   set_responses();
   will_open = 1;
   set_property("untrackable", 1);
   BEAT = 0;
   check_my_heart();
}

void check_my_heart()
{
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}


void die(){
  object slayer, * attackers, ectoplasm;
  string slayer_name;
  int i, tmp_size, count;
   message("other_action", "%^RED%^"+query_cap_name()+
     " swirls, loses form and is banished%^RESET%^", 
     environment(this_object()), ({ this_object()}));
   message("other_action", "%^BLUE%^A smeary residue is left behind", 
     environment(this_object()), ({ this_object()}));
  ectoplasm = new (OBJ + "ectoplasm");
  ectoplasm->set_spirit_name(TO->query_name());
  ectoplasm->move(tmp);
  attackers = query_attackers();
  count = sizeof(attackers);
  if (count > 0){
    for (i=0;i<count;i++){
      slayer = attackers[i];
      if (objectp(slayer) && slayer->is_player()){
        slayer_name = slayer->query_name();
        "/daemon/kill_and_event_records_d.c"->record_kill(slayer_name, base_name(TO), time());
      }
    }
  }
  ::die();
}


set_responses(){
  set_response(({"hello", "greetings", "good day", "gooday"}), 
   ({"Hello there."}), "greet_func" );
  set_response(({"fountain", "fountain of youth"}), ({"The priests"
   +" told stories of a fountain that would restore a mortal's"
   +" youth, but I never saw evidence of one.", "Idle chatter,"
   +" most likely" }) );
  set_response(({"island", "river island"}), ({"There might well"
   +" be an island in the river that flows through the jungle."
   +" Certainly it is wide enough. I have not seen one, though." }) );

  set_response(({"gods"}), ({"Our Gods were many. We worshipped"
    +" %^RED%^An-Tehp%^RESET%^, the %^BOLD%^%^RED%^S%^YELLOW%^u"
    +"%^RED%^n Lord%^RESET%^, %^GREEN%^Quali%^RESET%^, the"
    +" %^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ngle"
    +" Sp%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^i"
    +"%^BOLD%^%^GREEN%^t%^RESET%^, %^ORANGE%^Nobach Eri%^RESET%^,"
    +" the%^BLUE%^ jaguar%^RESET%^, %^ORANGE%^Inami%^RESET%^, the"
    +" %^RED%^hero of the flame%^RESET%^ and %^CYAN%^Teoctauoc"
    +"%^RESET%^, the %^BOLD%^%^GREEN%^fe%^BOLD%^%^BLUE%^a%^BOLD%^"
    +"%^GREEN%^th%^YELLOW%^e%^GREEN%^r%^CYAN%^e%^GREEN%^d s%^RESET%^"
    +"%^GREEN%^e%^BOLD%^%^GREEN%^rp%^RESET%^%^GREEN%^e%^BOLD%^"
    +"%^GREEN%^nt%^RESET%^, among others.", 
        "You should ask %^CYAN%^Jontar%^RESET%^, the old priest,"
    +" about them." }) );
  set_response(({"empress"}), 
     ({"Yes, I ruled my people once, but I was usurped by my younger"
    +" brother, %^CYAN%^Epithon%^RESET%^, who had me cast down from"
    +" the throne while I grieved for my consort,%^ORANGE%^"
    +" Guamansuri%^RESET%^.",
       " Epithon persuaded the people a woman in grief was unfit to"
    +" rule in the eyes of the %^ORANGE%^Gods%^RESET%^, especially"
    +" in a time of trouble.", 
       "Little did my people know the harm his reign would bring,"
    +" for his mind had been turned by the wretched worm,%^CYAN%^"
    +" Taluc%^RESET%^.", 
       "I care not for my own loss of station, but I grieve for the"
    +" terrible path down which they were led by %^CYAN%^Epithon"
    +" %^RESET%^and %^CYAN%^Taluc%^RESET%^, arm in arm." }) );
  set_response( ({"taluc"}), ({"He is a worm."}),
    "unfetter");
  set_response( ({"unfettered"}), ({"Even now, I can hardly speak of"
    +" it.", 
       "The %^MAGENTA%^Unfettered%^RESET%^ was brought to us by"
    +" %^CYAN%^Taluc%^RESET%^, I am sure. He taught the worship of"
    +" it to %^CYAN%^Epithon%^RESET%^, who in turn forced that"
    +" worship on the people.", 
      " The %^ORANGE%^sacrifices%^RESET%^ made before to the%^BOLD%^"
    +"%^RED%^ S%^YELLOW%^u%^RED%^n Lord%^RESET%^ flowed instead in"
    +" gift to the Unfettered. And as it grew in power, so my people"
    +" waned. It was like a leech upon us. And thus it brought about"
    +" the %^CYAN%^end of my people%^RESET%^."}),
       "flash_func",({"Heard of the Unfettered"}));
  set_response(({ "epithon"}), ({"Hmm" }),"epithon"  );
  set_response( ({"betrayed"}), ({"Yes, we were betrayed. The false"
    +" priest %^CYAN%^Taluc%^RESET%^ deceived my brother%^CYAN%^"
    +" Epithon %^RESET%^into usurping my throne."}) );
  set_response(({"jontar", "old priest"}),({"I believe he took"
    +" refuge in the lower areas of the Ziggurat after %^CYAN%^Taluc"
    +" %^RESET%^displaced him.", "He is likely still there."}) );
  set_response( ({"guamansuri", "consort", "love"}), ({"Gaumansuri"
    +" was my lover, my life.", 
         "I loved him more truly and more deeply than I can tell"
    +" you. When he died in battle, my life was as good as ended. I"
    +" cared little even to resist Epithon's efforts to take over my"
    +" throne. Perhaps had I not grieved so hard, I could have"
    +" prevented it, and even saved our people from the awful fate"
    +" that awaited them."}),
    "cry_func");
  set_response(({"end of your people", "the end", "end of my people", 
        "end of our people", "end of the people", "end of the Tecqumin"}),
    ({ "Surely"
    +" we were cursed by the Gods for the betrayals of Taluc and"
    +" Epithon and their courting of the Unfettered.",
       "I remember the day of our fall well. First there was the"
    +" breaking of the mountain. Stormy skies came, and the sound of"
    +" a myriad ancestors wailing in torment, deafening our ears."
    +" The buildings shook, and the ground quaked under them. Many"
    +" died in the ruins of our city, and the mountain was struck in"
    +" twain. ", "After that there were no more children for the"
    +" Tecqumin, and those of us who were left did not join our"
    +" ancestors when we died, but were stuck here, undying shades"
    +" trapped in our ruined city while the %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^ grew back, gradually hiding the last"
    +" traces of our once proud city." }) );
  set_response(({"end of my people"}), ({ "Surely"
    +" we were cursed by the Gods for the betrayals of Taluc and"
    +" Epithon and their courting of the Unfettered.",
       "I remember the day of our fall well. First there was the"
    +" breaking of the mountain. Stormy skies came, and the sound of"
    +" a myriad ancestors wailing in torment, deafening our ears."
    +" The buildings shook, and the ground quaked under them. Many"
    +" died in the ruins of our city, and the mountain was struck in"
    +" twain. ", "After that there were no more children for the"
    +" Tecqumin, and those of us who were left did not join our"
    +" ancestors when we died, but were stuck here, undying shades"
    +" trapped in our ruined city while the %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^ grew back, gradually hiding the last"
    +" traces of our once proud city." }) );
  set_response(({"downfall"}),
     ({ "Surely"
    +" we were cursed by the Gods for the betrayals of Taluc and"
    +" Epithon and their courting of the Unfettered.",
       "I remember the day of our fall well. First there was the"
    +" breaking of the mountain. Stormy skies came, and the sound of"
    +" a myriad ancestors wailing in torment, deafening our ears."
    +" The buildings shook, and the ground quaked under them. Many"
    +" died in the ruins of our city, and the mountain was struck in"
    +" twain. ", "After that there were no more children for the"
    +" Tecqumin, and those of us who were left did not join our"
    +" ancestors when we died, but were stuck here, undying shades"
    +" trapped in our ruined city while the %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^ grew back, gradually hiding the last"
    +" traces of our once proud city." }) );
  set_response(({"end of the tecqumin"}),
     ({ "Surely"
    +" we were cursed by the Gods for the betrayals of Taluc and"
    +" Epithon and their courting of the Unfettered.",
       "I remember the day of our fall well. First there was the"
    +" breaking of the mountain. Stormy skies came, and the sound of"
    +" a myriad ancestors wailing in torment, deafening our ears."
    +" The buildings shook, and the ground quaked under them. Many"
    +" died in the ruins of our city, and the mountain was struck in"
    +" twain. ", "After that there were no more children for the"
    +" Tecqumin, and those of us who were left did not join our"
    +" ancestors when we died, but were stuck here, undying shades"
    +" trapped in our ruined city while the %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^ grew back, gradually hiding the last"
    +" traces of our once proud city." }) );
  set_response(({"end of the people"}),
     ({ "Surely"
    +" we were cursed by the Gods for the betrayals of Taluc and"
    +" Epithon and their courting of the Unfettered.",
       "I remember the day of our fall well. First there was the"
    +" breaking of the mountain. Stormy skies came, and the sound of"
    +" a myriad ancestors wailing in torment, deafening our ears."
    +" The buildings shook, and the ground quaked under them. Many"
    +" died in the ruins of our city, and the mountain was struck in"
    +" twain. ", "After that there were no more children for the"
    +" Tecqumin, and those of us who were left did not join our"
    +" ancestors when we died, but were stuck here, undying shades"
    +" trapped in our ruined city while the %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^ grew back, gradually hiding our once"
    +" proud city." }) );
  set_response( ({"sacrifice", "sacrifices",}), ({"Our priests"
    +" offered sacrifices to the gods. Many types of sacrifices were"
    +" made, but the greatest of all was the sacrifice of %^RED%^"
    +"blood%^RESET%^. It flowed down the steps of the great ziggurat"
    +", appeasing the Gods' hunger. But then, %^MAGENTA%^Epithon"
    +"%^RESET%^, spurred on by %^CYAN%^Taluc%^RESET%^, diverted the"
    +" flow to the worship of the %^BLUE%^Unfettered%^RESET%^. And"
    +" that was our downfall; our Gods abandoned us and we were"
    +" cursed. "}) );
  set_response(({"tecqumin"}), ({"Ah, my people. They have suffered"
    +" so much torment. We were a great and %^ORANGE%^proud nation"
    +" %^RESET%^once, before we were %^CYAN%^betrayed%^RESET%^ from"
    +" within." }) );
  set_response(({"proud nation"}),({"A proud nation, yes. We were"
    +" great and lordly, conquerers in battle and beloved of the"
    +" %^ORANGE%^Gods%^RESET%^" }) );
  set_response( ({"how are you", "whats up", "What's up"}), 
   ({"I am tired, in truth. The long years of living as a ghost have"
    +" wearied me."}) );  
}

void bridge_speech3(){
  if (!objectp(ETO) || file_name(ETO) != JUNG_ROOM + "ropebridge0"){
    return;
  }
  ETO->tell_bridge( "%^MAGENTA%^Mehac's voice rings out across the"
    +" bridge: %^RESET%^There is no knowing what destruction it will"
    +" wreak if it accesses the power that is hidden there! %^BOLD%^"
    +"%^RED%^Stop it now! %^BOLD%^%^BLUE%^It %^WHITE%^must%^BLUE%^"
    +" not cross the %^RESET%^%^ORANGE%^bridge%^BOLD%^%^BLUE%^!");
}
void bridge_speech2(){
  if (!objectp(ETO) || file_name(ETO) != JUNG_ROOM + "ropebridge0"){
    return;
  }
  ETO->tell_bridge( "%^MAGENTA%^Mehac's voice rings out across the"
    +" bridge: %^RESET%^Beware! The %^BLUE%^Unfettered%^RESET%^ seeks"
    +" access to the city of the %^CYAN%^Tecqumin%^RESET%^!");
  call_out("bridge_speech3", 1); 
}

void bridge_speech(){
  object room;
  if (!objectp(ETO) || file_name(ETO) != JUNG_ROOM + "ropebridge0"){
    room = find_object_or_load(JUNG_ROOM + "ropebridge0");
    if (!objectp(ETO)){
      return;
    }
    move(room);
  }
  ETO->tell_bridge( query_short() + " %^BOLD%^%^WHITE%^appears"
    +" %^RESET%^at the east end of the %^ORANGE%^bridge"); 
  call_out("bridge_speech2", 1);
}

void retreat_speech3(){
  force_me("say  Now go back. Go back and restore the %^BOLD%^"
    +"%^GREEN%^s%^RESET%^%^GREEN%^ea%^BOLD%^l%^RESET%^, that it may" 
    +" be locked away for %^ORANGE%^years%^RESET%^ to come!");
}
void retreat_speech2(){
  force_me("say You have driven it back into the %^BLUE%^void"
    +"%^RESET%^! That is an %^BOLD%^%^WHITE%^astonishing%^RESET%^"
    +" feat!");
  call_out("retreat_speech3", 2);
}

void retreat_speech(){
  force_me("emote %^CYAN%^gasps");
  call_out("retreat_speech2", 1);
}

void cry_func(object speaker){
  force_me("emote 's eyes well up, then spill silent tears as she"
    +" continues, her voice betraying deep emotion.");
}

void flash_func(object speaker){
  force_me("emote flashes her eyes fiercely");
}

void greet_func(object speaker){
  string * quests;
  if (!objectp(ETO)){
    return;
  }
  if (!objectp(speaker)||present(speaker, ETO)==-1){
    force_me("say where did you go?");
  }
  quests = speaker->query_mini_quests();
  if (member_array("Tasked to slay Epithon", quests)!=-1 ||
        member_array("Tasked to slay Taluc", quests )!=-1){
    force_me("say have you slain Epithon or Taluc?");
    force_me("say If you have, hand me the evidence.");
    return;
  }
  force_me("say why, you are of the living and not of the %^CYAN%^"
    +"Tecqumin%^RESET%^!");
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

void unfetter(object speaker){
  string * quests;
  object * people, room;
  int i;
  room = ETO;
  if (!objectp(room)){return;}
  if (!objectp(speaker)||(present(speaker, room)==-1)){
    force_me("say where did you go?");
    return;
  }
  quests = speaker->query_mini_quests();
  if (member_array("Tasked to slay Taluc", quests)!=-1){
    force_me("say Have you killed him for me yet? If you have,"
      +" please give me the evidence!");
    return;
  }
  force_me("say Taluc was a priest,"
    +" or so he seemed when he arrived and fastened himself to"
    +" %^CYAN%^Epithon%^RESET%^. But he was subtle and false and"
    +" whispered darkly in my brother's ear. It was after this that"
    +" %^CYAN%^Epithon%^RESET%^ began giving service to a God none"
    +" had known before. It was Taluc, I believe, who was the cause"
    +" of the descent of the %^CYAN%^Tecqumin %^RESET%^to the"
    +" worship of the %^MAGENTA%^Unfettered%^RESET%^.");
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Heard of the Unfettered",quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Heard of the Unfettered");
  }
}

void epithon(object speaker){
  string * quests;
  object * people, room;
  int i;
  room = ETO;
  if (!objectp(room)){return;}
  if (!objectp(speaker)||(present(speaker, room)==-1)){
    force_me("say where did you go?");
    return;
  }
  quests = speaker->query_mini_quests();
  if (member_array( "Tasked to slay Epithon", quests)!=-1){
    force_me("say Have you killed him for me yet? If you have,"
      +" please give me the evidence!");
    return;
  }
  force_me("say My brother grew up in envy of the"
    +" throne. I think he always believed that the station should"
    +" have passed to him on our father's death, that his claim of"
    +" %^RED%^blood%^RESET%^ was stronger than mine, because he was"
    +" the first son, and his mother was our father's favourite wife"
    +" when he died. But the first marriage is held sacred in the"
    +" traditions of my people.");
  call_out("epithon2", 4);
}

void epithon2(){
  force_me("say The priests teach that a wedding joins two souls"
    +" together inextricably, such that even death cannot part them."
    +" The taking of a second wife, such as Epithon's mother, is of"
    +" little consequence. And so I took up the mantle of %^ORANGE%^"
    +"Empress%^RESET%^, ruling as our father's rightful successor.");
  call_out("epithon3",3);
}

void epithon3(){
  force_me("say But of course, that was all before%^CYAN%^ Epithon"
    +"%^RESET%^ met %^CYAN%^Taluc%^RESET%^");
}

void reply_func(string msg, object speaker){
  msg = strip_colors(msg);
  msg = lower_case(msg);
  if (interact("quali", msg)){
    if (interact("kill", msg)||interact("slay", msg)||
        interact("destroy", msg) || interact("sacrifice", msg)){
      force_me("say No! To harm Quali would be a terrible thing to"
        +" do!");
      return;
    }
  }
  base_reply_func(msg, speaker);
}

void  receive_given_item(object ob){
  if (ob->id("ectoplasm")){
    if ((string)ob->query_spirit_name()=="Epithon"){ 
      receive_spirit(TP, "Epithon");
      return;
    }
    if ((string)ob->query_spirit_name()=="Taluc the betrayer"){
      receive_spirit(TP, "Taluc");
      return;
    }
  }
}

void receive_spirit(object giver, string spirit_name){
  object * quests, *party;
  int i, num, flag;
  if (!objectp(giver) || !objectp(ETO) || !present(giver, ETO)){
    return;
  }
  flag = 0;
  party = giver->query_party();
  if (sizeof(party)<1){ party = ({giver}); }
  if (member_array(giver, party)==-1){
    party += ({giver});
  }
  num = sizeof(party);
  for (i=0;i<num;i++){
    if (!objectp(party[i])){  continue;  }
    quests = party[i]->query_mini_quests();
    if (member_array("Tasked to slay " + spirit_name, quests)!=-1){
      flag = 1;
      party[i]->remove_mini_quest("Tasked to slay " + spirit_name);
    }
  }
  if (flag ==0){
    force_me("say I do not know you. Why are you giving me this?");
    tell_object(giver, "It seems that neither you nor anyone in your"
      +" party has been given the task to slay " + spirit_name);
    return;
  }
  force_me("say The remains of " + spirit_name + "!");
  call_out("receive_spirit2", 2, spirit_name, giver);
}

void receive_spirit2(string spirit_name, object giver){
  force_me("emote smiles %^BOLD%^%^YELLOW%^fiercely");
  force_me("say This deed is well done, stranger. I will see to it"
    +" that " + spirit_name + "'s spirit spends his eternity in the"
    +" agony of %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^"
    +"%^RED%^mes%^RESET%^.");
  call_out("receive_spirit3", 3, spirit_name, giver);
}

void receive_spirit3(string spirit_name, object giver){
  object * party, keystone, * quests;
  int i, num;
  force_me("say here is a keystone to my treasury. Help yourself to"
    +" one item as a reward.");
  party = giver->query_party();
  if (sizeof(party)<1){ party = ({giver}); }
  if (member_array(giver, party)==-1){
    party += ({giver});
  }
  num = sizeof(party);
  for (i=0;i<num;i++){
    if (!objectp(party[i])){continue;}
    tell_object(party[i], "The spirit of Empress Mehaq reaches out"
      +" to you personally and passes across a small gemstone.");
    keystone = new (OBJ + "keystone");
    keystone->move(party[i]);
    quests = party[i]->query_mini_quests();
    if (member_array("Delivered justice to " + spirit_name, quests)==-1){
      party[i]->set_mini_quest("Delivered justice to " + spirit_name);
      party[i]->add_exp(20000000);
    }
  }
}

