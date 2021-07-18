//jontar.c - The Old Priest                                 
// Coded by Lujke 29/12/06
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
inherit MOB + "QNPC.c";

void set_responses();

void create(){
   ::create();
   set_name("Taluc the betrayer");
   set_id( ({"taluc","betrayer","Taluc", "ghost", "tecqumin", "xxtalucxx"}) );
   set_short("Taluc the betrayer");
   set_long("A slightly more substantial ghost than most");
   set_gender("male");
   set_race("ghost");
   set_body_type("human");
   set_hd(90,5);
   set_alignment(5);
   set_max_hp(3500);
   set_hp(query_max_hp());
   set_overall_ac(-55);
   set_class("fighter");
   set_mlevel("fighter",45);
   set_level(45);
   set_stats("wisdom",19);
   set_stats("strength",28);
   set_stats("constitution",28);
   set_stats("intelligence",18);
   set_stats("charisma",16);
   set_stats("dexterity",20);
   set_exp(60);
   set_new_exp(45, "normal");

   set("aggressive",0);
   set_responses();
   will_open = 1;
   set_property("untrackable", 1);
}

set_responses(){
  set_response(({"hello", "greetings", "good day", "gooday"}), 
          ({"What? Who's that?", "Ah! How interesting. The living"
    +" come to visit the dead city of the %^CYAN%^Tecqumin%^RESET%^."
    +" And you are from far away, I think."}) );
  set_response(({"tecqumin"}), ({"A faded race, my people,"
    +" though they didn't know it. They were grand enough on their"
    +" little island here, even venturing across the seas to wage"
    +" their wars. But I did not see how small they were until I"
    +" %^CYAN%^left and returned%^RESET%^" }) );
  set_response(({"leave and return"}), ({"I was the first"
    +" %^CYAN%^Tecqumin%^RESET%^ in an age to travel in the wider"
    +" world. I journeyed far and saw much. I was gone so long that"
    +" few remembered me when I returned.",
     "But by then, I knew the truth about their %^ORANGE%^gods"
    +"%^RESET%^" }) );
  set_response(({"left and returned"}), ({"I was the first"
    +" %^CYAN%^Tecqumin%^RESET%^ in an age to travel in the wider"
    +" world. I journeyed far and saw much. I was gone so long that"
    +" few remembered me when I returned.",
     "But by then, I knew the truth about their %^ORANGE%^gods"
    +"%^RESET%^" }) );
  set_response(({"foreign gods"}), ({"When I travelled in the world,"
    +" I encountered priests and worshippers of Gods who were"
    +" strange to me. I learned of Lathander, the Morninglord, god"
    +" of the Sun, who also has charge of rebirth and renewal. I"
    +" could not understand how this could be so, when I believed"
    +" that An-Tehp was Lord of the Sun.", "I heard tales of"
    +" Silvanus, whose desmene seemed to overlap with that of Quali."
    +" I learned of Malar and Anhur, Shaundakul, Akadi and Grumbar"
    +" and many others. What's more, I witnessed miracles performed"
    +" by the priests of these Gods that were far greater in power"
    +" than anything our priests could achieve.", "In time, I was"
    +" convinced that these foreign Gods were real, and that our"
    +" Gods were no Gods at all, but simply powerful spirits who had"
    +" taken interest in our people."  }));
  set_response(({"far away"}), ({"Indeed. In my youth, I travelled"
    +" abroad myself. It was a shock to learn how small the %^CYAN%^Tecqumin"
    +" %^RESET%^world really was when I %^CYAN%^left and returned%^RESET%^."}));
  set_response(({"gods"}), ({"Gods? Hah! The gods of the%^CYAN%^"
    +" Tecqumin%^RESET%^ may have been great and powerful spirits,"
    +" but they were no true gods.", 
     "Yes, I see in your eyes you know the truth of it.%^RED%^"
    +" An-Tehp%^RESET%^ does not carry the sun across the sky,"
    +" nor ensure the sunrise each day. That job goes to Lathander,"
    +" as the humans call him.", 
     "The real Gods may have ignored the %^CYAN%^Tecqumin%^RESET%^"
    +" for a while, but they are jealous of their status. As I"
    +" learned more of them I realised they would not let my people"
    +" persist in their old ways. I realised we needed%^CYAN%^"
    +" protection%^RESET%^" }) );
  set_response(({"terrible revenge", "revenge"}),({"The ferocity of"
    +" the revenge of the %^ORANGE%^true Gods%^RESET%^ against the"
    +" %^CYAN%^Tecqumin%^RESET%^ surprised even me - and I had been"
    +" waiting for it.", 
     "The city was smote into ruins in a single devastating wave of"
    +" destruction, one that could only, I think, have been created"
    +" by Talos.", 
     "Following that there was a curse of sickness on all the"
    +" survivors. They died in agony, making me suspect the hand of"
    +" Beshaba in their demise.", 
     "And then all were gone, nothing remaining of the%^CYAN%^"
    +" Tecqumin%^RESET%^ but ghosts living in ruins. As far as I"
    +" know, even our %^ORANGE%^Gods%^RESET%^ were destroyed.",
     "You haven't seen any of our %^ORANGE%^Gods%^RESET%^, I"
    +" suppose?"}) ); 
  set_response(({"protection"}), ({"I was the only%^CYAN%^"
    +" Tecqumin %^RESET%^who realised it, but I knew the true"
    +" %^ORANGE%^Gods%^RESET%^ would not allow them to continue"
    +" worshipping their home-spun %^ORANGE%^gods%^RESET%^ forever.",
     "I knew that if the %^CYAN%^Tecqumin%^RESET%^ were to survive,"
    +" they would need the protection of a%^ORANGE%^ real god"
    +" %^RESET%^of their own. And it just happened that I knew where"
    +" to find one. All I had to do was to persuade them to worship"
    +" Him."}) );
  set_response(({"sacrifice"}), ({"The %^CYAN%^Tecqumin%^RESET%^"
    +" made sacrifices to the %^ORANGE%^Gods%^RESET%^ in ritual"
    +" ceremonies at the very summit of the%^CYAN%^ Ziggurat"
    +"%^RESET%^."}) );
  set_response(({"unfettered"}), ({"He contacted me in my dreams. He"
    +" let me see the fate of my people, the %^BOLD%^%^RED%^terrible"
    +" revenge%^RESET%^ the %^ORANGE%^Gods%^RESET%^ would wreak upon"
    +" them for their false worship.", 
     "He was right about the fate that was in store for the%^CYAN%^"
    +" Tecqumin%^RESET%^, but He also showed me how it could be"
    +" averted, how He could protect them if only they would worship"
    +" him with the offer of souls and %^RED%^blood gift%^RESET%^"
    +" they gave so freely to their false%^ORANGE%^ gods%^RESET%^" })
     ,"sigh", ({"Heard of the Unfettered"}) );
  set_response( ({"real god"}), ({"In my travels in the wider world,"
    +" I had learned of the being known as the %^MAGENTA%^Unfettered"
    +"%^RESET%^. Not one of the %^ORANGE%^Gods%^RESET%^ of this"
    +" Realm, He was nevertheless a being of unfathomable power and"
    +" I was sure he could protect the %^CYAN%^Tecqumin%^RESET%^"
    +" from the %^ORANGE%^Gods%^RESET%^."}),"reality"); 
  set_response( ({"blood gift"}), ({"The blood gift was the"
    +" sacrifice of life the %^CYAN%^Tecqumin%^RESET%^ made to their"
    +" %^ORANGE%^gods%^RESET%^. The power of %^CYAN%^life force%^RESET%^"
    +" passed to them from those given the %^CYAN%^flowery death"
    +"%^RESET%^. I planned, with %^ORANGE%^Epithon's%^RESET%^ aid,"
    +" to use the power of the blood gift to elevate the%^MAGENTA%^"
    +" Unfettered%^RESET%^ to a strength such that he could protect"
    +" us from the foreign gods. Now, our only hope to lift the"
    +" curse of our undeath is to use it to free him from his"
    +" %^BLUE%^entrapment%^RESET%^."}), 
       "sigh", ({"Heard of the Unfettered"}));
  set_response(({"life force"}), ({"In each being there is a force"
    +" of life. Even plants and animals contain life force, but it"
    +" is strongest in sentient beings. This is the power that the"
    +" %^CYAN%^Tecqumin%^RESET%^ priests passed to their gods, and"
    +" which I tried to use to aid the %^MAGENTA%^Unfettered"
    +"%^RESET%^, to gain His protection for my people."}) );
  set_response(({"flowery death"}), ({"Flowery death? That's what"
    +" the priests used to call the way they butchered their"
    +" sacrifices at the top of the ziggurat. They were always a bit"
    +" soft about how they talked about things.", "They would"
    +" stretch the 'sacrifice' backwards over a stone slab"
    +" and cut their heart out of their chest with an obsidian"
    +" knife. I'm not sure what was supposed to be flowery about"
    +" it."}) );  
  set_response(({"lift the curse", "break the curse"}), ({"The only"
    +" way I can think to lift the curse would be to free the%^BLUE%^"
    +" Unfettered%^RESET%^ from His imprisonment, and gift Him with"
    +" sufficient power to win a fight against the%^ORANGE%^"
    +" foreign gods%^RESET%^.",  "We are working at it, but it is"
    +" slow work to gather sufficient power.",  "Maybe the life-force"
    +" of a God, would to it,"
    +" if you have seen one such around anywhere?"}));
  set_response(({"seen a god"}), ({"You have seen a God?", 
    "Which one did you see?"}));
  set_response(({"quali"}), ({"Quali lives?", "Now that is"
    +" interesting news. And he is maddened, you say? No doubt the"
    +" after effect of the drubbing he received during the%^CYAN%^"
    +" downfall of our people%^RESET%^. But still, if we could"
    +" sacrifice HIS soul, it would surely be a great boost to our"
    +" efforts to free the%^MAGENTA%^ Unfettered%^RESET%^ and"
    +" reverse the %^CYAN%^curse of the Tecqumin%^RESET%^. Perhaps,"
    +" in his maddened state he might even be killable.", 
     "But the ghosts of the %^CYAN%^Tecqumin%^RESET%^ cannot leave"
    +" this city, save at greatest peril. This task would have"
    +" to fall to you. Would you take on the challenge to%^BLUE%^"
    +" slay a God%^RESET%^ and reverse the %^CYAN%^curse of the"
    +" Tecqumin%^RESET%^?"}), "surprise", 
      ({"Discovered the Madness of Quali"}) );
  set_response(({"take on the task"}), ({"Very well, I hope you are"
    +" up to the job. First you will need to obtain the"
    +" %^BOLD%^%^BLACK%^Jetstone%^RESET%^ if you do not have it"
    +" already. You can ask %^MAGENTA%^Epithon%^RESET%^ where it is."
    +" Once you have it, you will need to slay the mad God"
    +" %^BOLD%^%^GREEN%^Q%^RESET%^%^GREEN%^u%^BOLD%^a%^RESET%^"
    +"%^GREEN%^li%^RESET%^ while you hold the stone, so that it can"
    +" absorb the power of his spirit. Once that is done, the stone"
    +" should contain sufficient power to get past the stone gateway"
    +" and open the %^BOLD%^%^GREEN%^mystic s%^RESET%^%^GREEN%^e"
    +"%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^, to release the"
    +" %^BLUE%^Unfettered %^RESET%^and see all of my plans reach fruition!"}),
     "give_quest", ({"Was asked to slay Quali"}) );
  set_response(({"slay a god"}), ({"If you wish to help us collect"
    +" the life force of the maddened Spirit of the Jungle,"
    +" %^GREEN%^Q%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^al%^BOLD%^"
    +"%^GREEN%^i%^RESET%^, you will need to first obtain the"
    +" %^BOLD%^%^BLACK%^Jetstone%^RESET%^. It is the vessel in"
    +" which we have been storing the %^CYAN%^life force %^RESET%^of"
    +" %^ORANGE%^sacrifices%^RESET%^ to the %^MAGENTA%^Unfettered"
    +"%^RESET%^. When we have enough, we will be able to use those"
    +" forces to free him from his %^BLUE%^entrapment%^RESET%^.",
      "The life force of %^BOLD%^%^GREEN%^Q%^RESET%^"
    +"%^GREEN%^u%^BOLD%^ali%^RESET%^m  would greatly empower the"
    +" %^BOLD%^%^BLACK%^Jetstone%^RESET%^. Of course, to get it,"
    +" you will have to kill the maddened spirit while holding the"
    +" stone. Tell me if you would like to %^BLUE%^take on the task"
    +"%^RESET%^."}),
      "tell_slay" );
  set_response(({"jetstone"}), ({"The %^BOLD%^%^BLACK%^Jetstone"
    +" %^RESET%^is an artefact of our ancestors. I gave it to our"
    +" prince, %^CYAN%^Epithon%^RESET%^, to place near the"
    +" sacrificial altar on the ziggurat. That way, it would be able"
    +" to absorb the %^CYAN%^life forces%^RESET%^ from the%^CYAN%^"
    +" sacrifices."}), "grin", ({"Heard of the Jetstone"}) );
  set_response(({"epithon"}),({"Epithon is the prince of the"
    +" Tecqumin, and their rightful ruler, even though he did have"
    +" to depose his own half sister in order to take up the throne."
    , "His claim was always stronger than hers, but she refused to"
    +" listen to me about the imminent threat from the%^ORANGE%^"
    +" foreign gods%^RESET%^, and that was the final reason I"
    +" implored him to take the throne from her, so that something"
    +" could be done about it."}));
  set_response(({"entrapment"}), ({"The Unfettered was defeated by"
    +" the foreign gods when they came to punish the Tecqumin for"
    +" their worship of false gods. They came too soon for our plan"
    +" to bear fruit. The Unfettered had not sufficient power to"
    +" defend us from them. And so, beaten, He was trapped and"
    +" imprisoned, behind a stone gateway in the jungle. The"
    +" power of Helm watches over the mystic seal that imprisons Him.", 
     "Perhaps as a joke, perhaps as a warning, they decorated the"
    +" gateway with symbols of two of the %^CYAN%^Tecqumin%^RESET%^"
    +" gods: %^BOLD%^%^BLACK%^Nobach Eri%^RESET%^ and %^BOLD%^"
    +"%^RED%^Teoctauoc%^RESET%^, the Jaguar god and the feathered"
    +" serpent.",
     "They also set the spirits of naive Tecqumin, those who refused"
    +" the worship of the Unfettered, to guard the entrance to the"
    +" chamber."}), "entrap_func" );
  set_response( ({"stone gateway", "where is the stone gateway", 
     "where is the unfettered", "find the stone gateway", 
     "find the unfettered", "find unfettered", 
     "where is the unfettered imprisoned", "where is the prison", 
     "where is the unfettered's prison", "find the unfettered's prison"}), 
    ({"The stone gateway that guards the entrance to the"
    +" %^BLUE%^Unfettered's%^RESET%^ prison is to the east of the city,"
    +" across a %^ORANGE%^broad river canyon%^RESET%^ that was formed"
    +" when %^BOLD%^%^BLACK%^T%^YELLOW%^a%^BLACK%^l%^YELLOW%^o%^BLACK%^s"
    +" smote the earth during the destruction of the Tecqumin", 
      "I think there is a bridge"}) );
  set_response( ({"bridge"}), ({"I'm told the rope bridge is safe to"
    +" cross.", "More or less."}) );
  set_response( ({"carved gate", "gate in jungle", "face gate", 
       "gate with faces", "decorated gate"}), ({"That would be the"
    +" gate behind which The %^BLUE%^Unfettered%^RESET%^"
    +" was sealed.", "The power in the jetstone might be able to"
    +" open it.  Try to %^ORANGE%^release %^RESET%^the power when"
    +" you are standing in before the gate.", "When you get inside,"
    +" if you can reveal the %^BLD%^%^GREEN%^mystic"
    +" s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l%^RESET%^,"
    +" you may be able to unleash the %^BLUE%^jetstone's%^RESET%^"
    +" power fully to free the %^BLUE%^Unfettered%^RESET%^"}), "gate_func",
      ({"Found the carved gate"}));
  set_response(({"mystic seal"}), ({"When the Unfettered was defeated"
   +" by the %^ORANGE%^foreign Gods%^RESET%^, the one called"
   +" %^BOLD%^%^RED%^Helm%^RESET%^ set a watchful seal over His prison."
   +" The seal bears %^BOLD%^%^RED%^Helm's symbol%^RESET%^. We have"
   +" been working from a distance to corrupt it, but it takes time,"
   +" so much time. If you can get close and unleash the power of the"
   +" %^BLUE%^jetstone%^RESET%^ - augmented with the power of Quali's"
   +" spirit - aginst it He will be free before we"
   +" know it, and the undying curse on the %^CYAN%^Tecqumin%^RESET%^"
   +" will be lifted."}), "blank_func", ({"Learned of the Unfettered's entrapment"}));
  set_response(({"helm's symbol", "symbol of helm"}), ({"Helm's symbol"
   +" is a watchful %^BOLD%^%^BLUE%^blue %^CYAN%^e%^BLUE%^y%^CYAN%^e"
   +" %^RESET%^set on an upright war gauntlet. You must have seen it,"
   +" coming from foreign lands as you do?" }));
  set_response(({"blue eye", "watchful blue eye", "watchful eye"}), 
    ({"Feh, I would like to poke Helm in that %^BOLD%^%^BLUE%^blue"
   +" %^CYAN%^e%^BLUE%^y%^CYAN%^e%^RESET%^ of his if I could. Maybe"
   +" the %^BLUE%^Unfettered%^RESET%^ can do more than that for us,"
   +" though, when he is free." }) );
}

void surprise(){
  force_me("emote 's face registers his surprise");
}

void grin(){
  object * critters, jetstone;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  force_me("emote grins wickedly");
  critters = all_living(ETO);
  count = sizeof(critters);
  for (i=0;i<count;i++){
    if (critters[i]==TO) {continue;}
    jetstone = present("xxjetstonexx", critters[i]);
    if (objectp(jetstone)){
      call_out("acknowledge_jetstone", 3, critters[i]);
    }
  }
}

void acknowledge_jetstone(object ob){
  object jetstone;
  if (!objectp(ETO)){ return;}
  if (!objectp(ob) || !present(ob, ETO)){ return;}
  tell_object(ob, "Taluc nods to you");
  tell_room(ETO, "Taluc nods to " + ob->QCN, ob);
  jetstone = present("jetstone", ob);
  if (!objectp(jetstone)){
    return;
  }
  if (jetstone->is_powered()){
    call_out("acknowledge_powerstone", 2);
    return;
  }
  call_out("acknowledge_jetstone2", 2);
}

void acknowledge_jetstone2(object ob){
  if (!objectp(ETO)){ return;}
  if (!objectp(ob) || !present(ob, ETO)){ return;}
  force_me("say I see you have obtained the %^BLUE%^Jetstone%^RESET%^."
    +" To raise it to its full power, slay the maddened spirit of"
    +" %^BOLD%^%^GREEN%^Q%^RESET%^%^GREEN%^u%^BOLD%^ali %^RESET%^while"
    +" you hold it. The stone will absorb his essence to boost its own"
    +" strength.");
}

void acknowledge_powerstone(object ob){
  if (!objectp(ETO)){ return;}
  if (!objectp(ob) || !present(ob, ETO)){ return;}
  force_me("say I see you have obtained the %^BLUE%^Jetstone%^RESET%^,"
    +" and it glows with its full power. Take it to the stone gateway"
    +" and release its power to find a way in. Once there, you will"
    +" need to reveal the %^BOLD%^%^GREEN%^mystic"
    +" s%^RESET%^%^GREEN%^e%^ORANGE%^a%^BOLD%^%^GREEN%^l %^RESET%^and"
    +" then unleash the %^BLUE%^jetstone%^RESET%^ against it to free"
    +" the %^BLUE%^Unfettered");

} 

void sigh(){
  force_me("emote sighs");
}

void entrap_func(){
  object * people;
  string * quests;
  int i;
  people = all_living(ETO);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Learned of the Unfettered's entrapment"
                                               ,quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Learned of the Unfettered's"
                             +" entrapment",10000000,"%^BOLD%^%^BLUE%^Learned of the Unfettered's entrapment!");
  }
}

void gate_func(){
  jetstone();
}

void jetstone(){
  string * quests;
  object * people, room;
  int i;
  room = ETO;
  if (!objectp(room)){return;}
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Heard of the Jetstone",quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Heard of the Jetstone",10000000,"%^BOLD%^Heard of the Jetstone!");
  }
}

void reality(){
  string * quests;
  object * people, room;
  int i;
  room = ETO;
  if (!objectp(room)){return;}
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (interactive(people[i])==0){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Heard of the Unfettered",quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Heard of the Unfettered",10000000,"%^BOLD%^Heard of the Unfettered!");
  }
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Nature of the Unfettered",quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Nature of the Unfettered",10000000,"%^BOLD%^Nature of the Unfettered");
  }
}

void tell_slay(){
  object * critters;
  string * quests;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count<1){ return;}
  for (i=0;i<count;i++){
    if (!interactive(critters[i])){
      continue;
    }
    quests = critters[i]->query_mini_quests();
    if (sizeof(quests)<1 || member_array("Was asked to slay Quali", quests) == -1){
      critters[i]->set_mini_quest("Was asked to slay Quali",10000000,"%^BOLD%^Was asked to slay Qauli");
    }
  }
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
  ectoplasm->move(ETO);
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


void give_quest(){
  object * critters;
  int i, count;
  if (!objectp(ETO)){
    return;
  }
  critters = all_living(ETO);
  count = sizeof(critters);
  if (count<1){ return;}
  for (i=0;i<count;i++){
    if (!interactive(critters[i])){
      continue;
    }
    EVENT_RECORDS_D->record_event(critters[i]->query_name(), "Agreed to aid Taluc", time());
  }
}
