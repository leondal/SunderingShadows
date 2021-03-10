//quali.c - The Jungle Spirit                                 
// Coded by Lujke 29/12/06
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
#define ATTACK_LIMBS ({"first branch","second branch","third branch","fourth branch","fifth branch","sixth branch","seventh branch","eighth branch" ,"ninth branch"});
inherit WEAPONLESS;

int maddened, settled, going_to_gate;
string bridge_direction;

void set_responses();

void create(){
   ::create();
   bridge_direction = "none";
   going_to_gate =0;
   maddened = 1;
   settled = 1;
   set_name("Quali, Spirit of the Jungle");
   set_id( ({"quali","spirit","jungle spirit", "spirit of the jungle"}) );
   set_short("%^GREEN%^Quali, spirit of the j%^BOLD%^%^GREEN%^u%^RESET%^%"
            +"^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^RESET%^");
   set_long("%^RESET%^The spirit of the jungle has taken the form of a great tree."
           +" Its thick trunk branches out into a broad spread of canopy"
           +" at the top, and into two knobbly legs at the bottom. A"
           +" woody head sits in between its upper branches, its large"
           +" eyes swimming with the colours of %^ORANGE%^amber%^RESET%^"
           +" and %^GREEN%^green%^RESET%^. The %^GREEN%^f%^BOLD%^"
           +"%^GREEN%^o%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^a%^RESET%^"
           +"%^GREEN%^ge %^RESET%^of the canopy stirs and whispers almost"
           +" constantly in the wind.");
   set_gender("male");
   set_race("tree");
   add_limb("trunk","trunk",0,0,0);
   add_limb("right leg","trunk",0,0,0);
   add_limb("root","trunk",0,0,0);
   add_limb("left leg","trunk",0,0,0);
   add_limb("first branch","trunk",0,0,0);
   add_limb("second branch","trunk",0,0,0);
   add_limb("third branch","trunk",0,0,0);
   add_limb("fourth branch","trunk",0,0,0);
   add_limb("fifth branch","trunk",0,0,0);
   add_limb("sixth branch","trunk",0,0,0);
   add_limb("seventh branch","trunk",0,0,0);
   add_limb("eighth branch","trunk",0,0,0);
   add_limb("ninth branch","trunk",0,0,0);
   set_attacks_num(7);
   set_overall_ac(-80);
   set_size(3);
   add_attack_bonus(79); 
   set_attack_limbs(({"left leg","right leg","first branch","second branch","third branch","fourth branch","fifth branch","sixth branch","seventh branch","eighth branch" ,"ninth branch"}));
   set_hd(90,5);
   set_alignment(5);
   set_max_hp(12500);
   set_hp(query_max_hp());
   set_class("fighter");
   set_mlevel("fighter",59);
   set_level(59);
   set_stats("wisdom",29);
   set_stats("strength",30);
   set_stats("constitution",30);
   set_stats("intelligence",20);
   set_stats("charisma",16);
   set_stats("dexterity",24);
      set_new_exp(60, "normal");
   set_emotes(20, ({"The jungle spirit wails","The jungle spirit whines", "The jungle spirit shudders as if in pain", "The jungle spirit groans as if in torment", "Wind whistles madly through the foliage of the jungle spirit", "The jungle spirit shrieks his suffering to the winds", "The jungle spirit writhes in silent agony"}), 0);
   set("aggressive",0);
   set_spoken("wizish");
    set_hp(17000);
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void init(){ 
  object * people, killer;
  string * quests;
  int i;
  ::init();
  if (maddened == 1 && settled == 1){
    settled = 0;
    call_out ("rave", 1);
    if (!objectp(ETO)){
      return;
    }
  }
  killer = EVENT_RECORDS_D->has_anyone_here_killed(ETO, base_name(TO), DAY *30);
  if (objectp(killer)){
    tell_room(ETO, "The spirit of Quali shimmers out of existence in the presence of  " + killer->QCN, killer );
    tell_object(killer, "The spirit of Quali shimmers out of existence in your presence." );
    move("/d/shadowgate/void");
    return;
  }
  people = all_living(ETO);
  if (sizeof(people)<1){return;}
  if (maddened ==1){
    for (i=0;i<sizeof(people);i++){
      if (interactive(people[i])){
        quests = people[i]->query_mini_quests();
        if (member_array("Discovered the Madness of Quali", quests)==-1){
          people[i]->set_mini_quest("Discovered the Madness of Quali");
        }
      }
    }
  }
}

void clean_up(){
  return;
}

void rave(){
  switch (random(6)){
  case 0:
    force_me("emote shudders and shakes");
    break;
  case 1: 
    force_me("emote rolls His great %^ORANGE%^amber%^RESET%^ and%^GREEN%^"
            +" green%^RESET%^ eyes back in their sockets, showing the"
            +" woody whites underneath");
    break;
  case 2: 
    force_me("emote %^ORANGE%^trembles in the wind");
    break;
  case 3: 
    force_me("emote %^ORANGE%^raises his branches, throws back his head and"
            +" howls toward the sky");
    break;
  case 4: 
    force_me("emote %^ORANGE%^creaks loudly as He twists around to see who"
            +" is there");
    break;
  case 5: 
    force_me("emote %^ORANGE%^creaks loudly in the wind");
    break;
  }
  switch (random(8)){
  case 0:
    force_me("say %^GREEN%^Root and branch! The pain! Burning, aching,"
            +" boiling pain! Aaaaargh!");
    break;
  case 1:
    force_me("say %^GREEN%^Terrible serpents! Flying, the night skies to"
            +" fill. Why come they here?");
    break;
  case 2:
    force_me("say %^GREEN%^Breath of the jaguar take them. Take them all!"
            +" Dieeeee!");
    break;
  case 3:
    force_me("say %^GREEN%^Where have they gone? My people why have you"
            +" left me in terror and pain?");
    break;
  case 4:
    force_me("say %^GREEN%^For all the ages, let the trees grow and the"
            +" life live through the forest. Don't cut them down!");
    break;
  case 5:
    force_me("say %^GREEN%^Termites, damn them all! Crawling and eating,"
            +" they get right under my bark!");
    break;
  case 6:
    force_me("say %^GREEN%^Come, my lovelies. Lean against my trunk and"
            +" rest. I have some foliage you could clean for me.");
    break;
  case 7:
    force_me("say %^GREEN%^Grasp and grow, my children. Stretch your"
            +" branches to the sun. Light on the leaves, soil on the roots."
            +" Grow and live. stretch yourselves.");
    break;
  }
}

void heal6(object healer){
  string name;
  name = healer->query_true_name();
  force_me("emoteat " + name + " points a trembling, branchlike arm towards $N" );
  force_me("say You... what did you do? My mind is clear now, after so long. So long.");
}

void heal5(object healer){
  object room;
  room =  ETO;
  if (!objectp(healer)||!objectp(room)||!present(healer, room)){return;}
  tell_room(room,"After longer than you imagined that you could bear it, the"
           +" sound ceases. The jungle stills and quietens, and Quali sags,"
           +" his branches and leaves seeming to weigh heavily upon him."
           +" Then he looks up, and begins to speak");
  fix_mind();
  set_emotes(0, ({""}), 0);
  call_out("heal6", 2, healer);
}

void heal4(object healer){
  object room;
  room =  ETO;
  if (!objectp(healer)||!objectp(room)||!present(healer, room)){return;}
  tell_room(room,"%^BLUE%^A sickly, %^MAGENTA%^purplish light%^BLUE%^ rises"
                +" behind %^GREEN%^Quali's%^BLUE%^ eyes. He stiffens as if"
                +" in pain, then throws back his head and roars a wordless"
                +" scream, louder than the stormwinds in the tree, a sound"
                +" that makes the ground tremble and your ears feel as"
                +" though they might burst.");
  call_out("heal5", 6, healer);
}

void heal3(object healer){
  object room;
  room = ETO;
  if (!objectp(healer)||!objectp(room)||!present(healer, room)){return;}
  tell_object(healer, "As you extend the %^BOLD%^%^BLACK%^jetstone%^RESET%^"
                     +" toward %^GREEN%^Quali%^RESET%^, a low humming sound"
                     +" emmanates from it.");
  tell_room(room, "As " + healer->QCN + " %^RESET%^extends the"
                 +" %^BOLD%^%^BLACK%^jetstone%^RESET%^ toward"
                 +" %^GREEN%^Quali%^RESET%^, a low humming sound emmanates"
                 +" from it", healer);
  call_out("heal4", 4, healer);
}

void heal2(object healer){
  object room;
  room = ETO;
  if (!objectp(room)){return;}
  tell_room(room, "%^BLUE%^The air around you suddenly stills. The jungle"
                 +" falls silent and nothing moves.");
  call_out("heal3", 4,healer);
}

void heal_mind(object healer){
  force_me("emote brings a couple of arm-like branches in to cover his"
          +" eyes.");
  force_me("yell %^MAGENTA%^Aaaah! The perfect skies! Tree and shrub,"
          +" release meeee!");
  call_out("heal2", 2, healer);
}

void settle(){
  settled = 1;
}

void heart2(){
  force_me("say If you think you can manage either thing, ask me to give"
    +" you the heart");
}

void reply_func(string msg, object speaker){
  string * triggers, trigger, func, * response, resp, * people, *quests;
  object room;
  int i, count;
  msg = lower_case(msg);
  if (maddened == 1){
    rave();
    return;
  }
  if (!interactive(speaker)){
    return;
  }
  room = ETO;
  if (!objectp(ETO)){
    force_me("emote looks disturbed by " + TO->QP + " surroundings, which"
            +" may well be broken");
  }
  if (!objectp(speaker)||!present(speaker, room)){
    return;
  }
  if ((interact("heart", msg) && interact ("give", msg)) || interact("give it to me", msg)){
    quests = speaker->query_mini_quests();
    if (member_array("Knows of the Heart of the Jungle", quests, 1)!=-1){
      force_me("say Very well. It is yours.");
      call_out("give_heart2", 2, speaker);
      return;
    }
  }
  if (interact("heart of the jungle", msg)){
    quests = speaker->query_mini_quests();
    if (member_array("Knows of the Heart of the Jungle", quests, 1)!=-1){
      force_me("say It is a part of my being, and holds much of my power. "
       +"It should have sufficient power to strengthen the seal - or, if"
       +" you are truly mighty, to open the seal to have a chance to"
       +" defeat the Unfettered once and for all.");
      call_out("heart2", 3);
      return;
    }
  }
  if (interact("tecqumin", msg)){
    force_me("say The Tecqumin were my people for many years. Mine and the"
            +" other %^ORANGE%^Gods%^RESET%^. But it is long since they"
            +" worshipped us. ");
    return;
  }
  if ((interact("seal", msg) && interact("chamber", msg)) ){
    force_me("say Once you are sure you have found the chamber with the"
            +" mystic seal, you need to get inside and use the power of the"
            +" %^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng"
           +"%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e %^BOLD%^%^YELLOW%^H"
            +"%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^rt%^RESET%^ to"
            +" strengthen the seal. The seal will not last forever, but"
             +" it will give protection for a time.");
    call_out("seal2",2, TP);
    return;
  }
  if (interact("healed you", msg) || interact("healed your mind", msg) ||
      interact("healed Quali", msg) || interact("I healed your madness", msg)){
    force_me("say My thanks are due for healing me. I am grateful.");
     call_out("great_spirits2", 3);
    return;
  }   
  if (interact("how can I help", msg) || interact("how can you help", msg) || (interact("how", msg) && (interact("help", msg) || interact ("assist", msg)))){
    force_me("say There remains a danger that the %^BLUE%^Unfettered%^RESET%^"
     +" could get free.");
    call_out("unfettered2",2);
  }
  if (interact("mystic seal", msg)){ 
    force_me("say The seal that imprisons the %^BLUE%^Unfettered%^RESET%^ is very"
      +" strong, but it is not unbreakable. Time degrades it, and enough power"
      +" could open it.");
  }
  if (interact("gateway", msg)){
    force_me("The gateway to the cavern where the %^BLUE%^Unfettered%^RESET%^ is"
     +" imprisoned is in the east of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
     +"%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^. It is kept closed by"
     +" spirits of %^CYAN%^Tecqumin%^RESET%^ loyalists, who never succumbed to the"
     +" worship of the creature, and has carvings of my brothers %^BOLD%^%^BLACK%^"
     +"Nobach Eri%^RESET%^ and %^BOLD%^%^RED%^Teoctauoc%^RESET%^.");
  }
  if (interact("mystic seal", msg)){
    force_me("say");
  }
  if (interact("how can you help", msg) || interact("I can help", msg) || interact("can I help", msg) || (interact("help", msg) && interact("save", msg)) ){
    force_me("say The Unfettered, foe of the true interests of the %^CYAN%^Tecqumin"
      +"%^RESET%^, and danger to all the Realms, is in an unsafe prison. The seal"
      +" that keeps it in weakens. I can give you the %^ORANGE%^he%^GREEN%^a%^ORANGE%^rt"
      +" of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l"
      +"%^BOLD%^e%^RESET%^, which has the power needed to deal with this threat.");
    people = all_living(ETO);
    count = sizeof(people);
    for (i=0;i<count;i++){
      if (!objectp(people[i])){
        continue;
      }
      if (!userp(people[i])) continue;
      quests = people[i]->query_mini_quests();
      if (member_array("Knows of the Heart of the Jungle", quests, 1)==-1){
        people[i]->set_mini_quest("Knows of the Heart of the Jungle");
      }
    } 
    return;
  }
  if (interact("life force", msg) || interact("sacrifices", msg) ){
    force_me("say Once upon a time all the life forces from the sacrifices"
            +" made by the %^CYAN%^Tecqumin%^RESET%^ people went to nourish"
            +" me and my brother spirits as we watched over their lives. But"
            +" then one of them placed a secret stone near the altar at the"
            +" top of the Ziggurat. That stone drained and stored the life"
            +" forces of those who were slain there. Stored them for a"
            +" terrible purpose. They were to be used as a payment to"
            +" the %^MAGENTA%^Unfettered");
    return;
  }
  
  if (interact("great spirits", msg)){
     force_me("say Some say they were the Gods of foreign lands. Great they"
       +" were, and terrible! The came from far away, but it seemed they"
       +" had always been here. The very%^BOLD%^%^CYAN%^"
       +" sk%^WHITE%^i%^CYAN%^es%^RESET%^ and"
       +" %^ORANGE%^e%^GREEN%^a%^ORANGE%^rth%^RESET%^ responded to their"
       +" %^BOLD%^%^YELLOW%^Will%^RESET%^. %^BOLD%^%^YELLOW%^L%^WHITE%^i"
       +"%^YELLOW%^ghtn%^RESET%^i%^BOLD%^%^YELLOW%^ng%^RESET%^ rained down"
       +" on the city and %^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^re%^RESET%^"
       +" swept through the streets as they battled with the%^BLUE%^"
       +" Unfettered%^RESET%^. I remember fleeing, sheltering a few of my"
       +" followers in the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
       +"%^GREEN%^ngl%^RESET%^%^GREEN%^e%^RESET%^. But the trees were"
       +" screaming, lashing out in their pain and I could not keep the"
       +" %^CYAN%^Tecqumin%^RESET%^ safe. They died, so many died, and"
       +" even the trees suffered. My mind fled, and so it has been, until"
       +" I was made better in a %^BOLD%^%^YELLOW%^heroic%^RESET%^ act of"
       +" healing.");
     force_me("emote smiles warmly. As much as a tree can smile");
     call_out("great_spirits2", 3);
  }
  if (interact("unfettered", msg)){
    force_me("say The %^BLUE%^Unfettered%^RESET%^ is a malignant thing of"
      +" evil and hate. For some reason or madness, the %^CYAN%^Tecqumin"
      +" %^RESET%^people summoned it from whatever unlifed place it"
      +" resides. They tried to install it as a new God, but then the" 
      +" %^ORANGE%^Great Spirits%^RESET%^ came and threw it down.");
    call_out("unfettered2", 2);
    return;
  }
  if (interact("gods", msg)){
    force_me("say An-Tehp and Inami. Nobach Eri and Teoctauoc. My brothers"
            +" are gone, dead and dispersed in the %^CYAN%^terrible"
            +" destruction%^RESET%^. I was the only one to survive, it"
            +" seems.");
    return;
  }
  if (interact("destruction", msg)){
    force_me("say It came without warning. A fire raged in the sky, then a"
            +" blast. Louder than thunder, it was; the ground shook and"
            +" trembled at the noise.");
    call_out("destruction2",2);
    return; 
  }
  if ((interact("defeat", msg)||interact("destroy", msg)) && interact("unfettered", msg)){
    force_me("say The Unfettered is a being of great Power. I cannot guess how"
      +" it could be defeated, but I will aid in the attempt if I can.");
  }
  if (interact("strengthen", msg) && interact("seal", msg)){
   seal3();
  }
  if (interact("jungle", msg)){
    force_me("say The jungle still echoes in the memory of my madness. It"
            +" is not safe, not safe at all.");
    return;
  }
  if (   ( interact("way to help", msg) ||( interact("destroy", msg)&& interact ("seal", msg) ) 
          || (interact("open", msg) && interact("seal", msg))  )){
    quests = speaker->query_mini_quests();
    if (member_array("Secret of the Chamber", quests, 1)){
     force_me("say If you are willing to help protect these Realms from"
            +" the threat of the return of the %^MAGENTA%^Unfettered"
            +" %^RESET%^, just ask me and I will give you the%^GREEN%^."
            +" Heart of the Jungle%^RESET%^. It contains a sizeable amount"
            +" of my power and you could use it to strengthen the seal"
            +" which imprisons the abomination's spirit. Or, if you have"
            +" the power, you could open the seal and take the risk of"
            +" attempting to defeat it in its own realm. But beware - its"
            +" power was enough to challenge the Gods, and if you fail you"
            +" will unleash its malice on the world.");
      people = all_living(ETO);
      count = sizeof(people);
      for (i=0;i<sizeof(people);i++){
        if (!interactive(people[i])){
          continue;
        } 
        quests = people[i]->query_mini_quests();
        if (member_array("Knows of the Heart of the Jungle",quests)!=-1){
          continue;
        }
        people[i]->set_mini_quest("Knows of the Heart of the Jungle");
      }
      call_out("destroy_crystal2",2);
    }
    return; 
  }
} 

void die(){
  object * critters, jetstone, * attackers, slayer;
  int i, count;
  string mob_file, slayer_name;
  slayer = query_current_attacker();
  attackers = query_attackers();
  if (sizeof(attackers)<1){
    attackers = ({slayer});
  }
  if (member_array (slayer, attackers) == -1){
    attackers += ({slayer});
  }
  count = sizeof(attackers);
  if (count > 0){
    mob_file = base_name(TO);
    for (i=0;i<count;i++){
      slayer = attackers[i];
      if (objectp(slayer) && slayer->is_player()){
        slayer_name = slayer->query_name();
        "/daemon/kill_and_event_records_d.c"->record_kill(slayer_name, mob_file, time());
      }
    }
  }

  critters = all_living(ETO);
  count = sizeof(critters);
  for (i=0;i<count;i++){ 
    jetstone = present("healing stone", critters[i]);
    if (objectp(jetstone)){
      jetstone->move("/d/shadowgate/void");
      jetstone = new(OBJ + "jetstone");
      jetstone->move(critters[i]);
      break;
    }    
    jetstone = present("jetstone", critters[i]);
    if (objectp(jetstone)){
      power_up_jetstone(jetstone);
      break;
    }
  }
  ::die();
}

void cross_bridge( string direction){
  bridge_direction = direction;
}

void heart_beat(){
  ::heart_beat();
  if (bridge_direction != "none" && objectp(ETO) && 
    (base_name(ETO) == JUNG_ROOM + "ropebridge0" || base_name(ETO) == JUNG_ROOM + "ropebridge1"
    || base_name(ETO) == JUNG_ROOM + "ropebridge2" || base_name(ETO) == JUNG_ROOM + "ropebridge3" 
      || base_name(ETO) == JUNG_ROOM + "ropebridge4" || base_name(ETO) == JUNG_ROOM + "ropebridge5")){
    force_me(bridge_direction);
  }
}

void power_up_jetstone(object jetstone){
  object holder;
  if (!objectp(jetstone)){ return;}
  holder = environment(jetstone);
  if (!objectp(holder)){ return;}
  tell_object(holder, "As %^RESET%^%^GREEN%^Q%^BOLD%^u%^RESET%^%^GREEN%^"
    +"a%^ORANGE%^l%^GREEN%^i%^BOLD%^ falls, a swathe of %^BOLD%^%^GREEN%^"
    +"br%^BOLD%^%^WHITE%^i%^GREEN%^ght gr%^RESET%^%^GREEN%^ee%^BOLD%^n"
    +" %^WHITE%^l%^GREEN%^i%^WHITE%^ghts%^RESET%^ issue from his body and"
    +" start to ascend toward the heavens. The %^BLUE%^jetstone%^RESET%^"
    +" you hold %^BLUE%^p%^BOLD%^u%^BLUE%^l%^RESET%^%^BLUE%^ses%^RESET%^,"
    +" and the %^BOLD%^%^GREEN%^l%^WHITE%^ights%^RESET%^ arch away from"
    +" their original path as they are drawn toward it.");
  tell_room(ETO, "As %^RESET%^%^GREEN%^Q%^BOLD%^u%^RESET%^%^GREEN%^a"
    +"%^ORANGE%^l%^GREEN%^i%^BOLD%^ falls, a swathe of"
    +" %^BOLD%^%^GREEN%^br%^BOLD%^%^WHITE%^i%^GREEN%^ght"
    +" gr%^RESET%^%^GREEN%^ee%^BOLD%^n %^WHITE%^l%^GREEN%^i%^WHITE%^ghts"
    +" %^RESET%^issue from his body and start to ascend toward the"
    +" heavens. The %^BLUE%^jetstone%^RESET%^ held by " + holder->QCN 
    +" %^RESET%^%^BLUE%^p%^BOLD%^u%^BLUE%^l%^RESET%^%^BLUE%^ses%^RESET%^,"
    +" and the %^BOLD%^%^GREEN%^l%^WHITE%^ights%^RESET%^ arch away from"
    +" their original path as they are drawn toward it.", holder);
  jetstone->absorb_quali();
}

void great_spirits2(){
  force_me("say Now that I can think again, so many things become clear"
    +" to me. The trees and rocks and creepers of the%^BOLD%^%^GREEN%^"
    +" j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ngl%^RESET%^%^GREEN%^e%^RESET%^"
    +" share their thoughts and memories with me. It all becomes clear to"
    +" me what has been happening since the disaster. Oh, the suffering of"
    +" my %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ngl"
    +"%^RESET%^%^GREEN%^e%^RESET%^, and the woes of the%^CYAN%^"
    +" Tecqumin%^RESET%^ people!");
  call_out("great_spirits3", 2);
}

void great_spirits3(){
  force_me("say Perhaps now I am restored there is a way to help.");
}

void seal2(object speaker){
  if (!objectp(speaker)||!objectp(ETO)||!present(speaker, ETO)){return;}
  if (present("xxjungheartxx", speaker)){
    force_me("say You already have the %^BOLD%^%^YELLOW%^H%^RESET%^"
          +"%^ORANGE%^ea%^BOLD%^%^YELLOW%^rt %^RESET%^%^ORANGE%^of the"
          +" %^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng"
          +"%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^");
    return;
  }
  force_me("say If you want to try sealing the chamber, just ask me for the"
          +" %^BOLD%^%^YELLOW%^H%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^rt"
          +" %^RESET%^%^ORANGE%^of the %^BOLD%^%^GREEN%^J%^RESET%^"
          +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^"
          +"%^GREEN%^e%^RESET%^");
  call_out("seal3", 2);
}

void destroy_crystal4(){
  force_me("say The safer path would be to use the power of the %^BOLD%^"
          +"%^GREEN%^J%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^%^GREEN%^e %^BOLD%^%^YELLOW%^H%^RESET%^"
          +"%^ORANGE%^ea%^BOLD%^%^YELLOW%^rt%^RESET%^ to strengthen the"
          +" %^CYAN%^seal that imprisons the creature instead. That would not"
          +" actually destroy the %^MAGENTA%^Unfettered%^RESET%^, but simply"
          +" make it"
          +" more difficult to free him.");
}

void seal3(){
  force_me("say To strengthen the seal with the power of the %^BOLD%^"
          +"%^GREEN%^J%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^"
          +"%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^ %^BOLD%^%^YELLOW%^H"
          +"%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^rt %^RESET%^, you will"
          +" need to speak special words. Only a faithful priest of the"
          +" %^CYAN%^Tecqumin%^RESET%^ can teach you these. Ask one such to"
          +" teach you the %^GREEN%^sacred chant");
}

void destroy_crystal3(object speaker){
  force_me("say Of course, to do either thing, you would first"
           +" have to find your way into the sealed chamber, beyond the"
           +" gate carved with the faces of %^BOLD%^%^BLACK%^Nobach Eri"
           +" %^RESET%^and %^BOLD%^%^RED%^Teoctauoc%^RESET%^. It is kept"
           +" shut by loyal spirits of the Tecqumin, worshippers of"
           +" Nobach Eri who resisted the call to sacrifice to the"
           +" Unfettered. They will not open willingly, unless for one of"
           +" their own.");
  call_out("destroy_crystal4", 2, speaker);
}

void destroy_crystal2(object speaker){
  if (!objectp(speaker)||speaker->query_highest_level()<45){
    force_me("say I fear that you would likely not survive such an"
            +" encounter");
    return;
  } else {
    force_me("say I am sure that, strong as you are, if you could gather"
            +" some allies, you would at least have a chance to defeat the"
            +" %^MAGENTA%^Unfettered%^RESET%^ and make these Realms safe"
            +" from it forever");
  }
  call_out("destroy_crystal3", 2);
}


void give_heart(object speaker){
  int when;
  object room;
  room = ETO;
  if (!objectp(room)){return;}
  if (!present(speaker, room)){return;}
  force_me("emote shudders from %^ORANGE%^root%^RESET%^ to %^BOLD%^"
          +"%^GREEN%^l%^RESET%^%^GREEN%^ea%^BOLD%^%^GREEN%^f%^RESET%^,"
          +" before reaching back into his %^GREEN%^f%^BOLD%^%^GREEN%^o"
          +"%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^ge with"
          +" a single armlike branch. After a few moments, he pulls the"
          +" branch back, a strange object %^ORANGE%^gl%^BOLD%^%^YELLOW%^o"
          +"%^RESET%^%^ORANGE%^w%^BOLD%^%^YELLOW%^i%^RESET%^%^ORANGE%^ng"
          +" %^RESET%^like %^ORANGE%^amb%^BOLD%^%^YELLOW%^e%^RESET%^"
          +"%^ORANGE%^r%^RESET%^ cradled between his twigs.");
  call_out("give_heart", 2, speaker);
  when = now();
  EVENT_RECORDS_D->record_event(speaker->query_name(), "Agreed to help Quali", when);
}

void go_to_gate(){
  mapping waystations;
  string next_dest, room_name, maze_path, maze_path2, maze_path3;
  int maze_time, maze_time2, maze_time3, destination_time, stringlen;
  going_to_gate = 1;
  room_name = base_name(ETO);
  tell_room(ETO, "Quali going to gate");
  stringlen = strlen(JUNG_ROOM1)-1;
  if (room_name[0..stringlen] == JUNG_ROOM1|| room_name == JUNG_ROOM + "j_link1"){
    tell_room(ETO, "Quali in a junglea room, or j_link1");
    maze_path = JUNG_ROOM1 + "j_maze";
    maze_path2 = JUNG_ROOM8 + "j_maze";
    maze_path3 = JUNG_ROOM2 + "j_maze";
    next_dest = JUNG_ROOM + "j_link8a";
  }
  stringlen = strlen(JUNG_ROOM2)-1;
  if (room_name[0..stringlen] == JUNG_ROOM2|| room_name == JUNG_ROOM + "j_link1a"){
    tell_room(ETO, "Quali in a jungleb room, or j_link1a");
    next_dest = JUNG_ROOM + "j_link2";
    maze_path = JUNG_ROOM2 + "j_maze";
    maze_path2 = JUNG_ROOM1 + "j_maze";
    maze_path3 = JUNG_ROOM3 + "j_maze";
  }
  stringlen = strlen(JUNG_ROOM3)-1;
  if (room_name[0..stringlen] == JUNG_ROOM3|| room_name == JUNG_ROOM + "j_link2a"){
    tell_room(ETO, "Quali in a junglec room, or j_link2a");
    next_dest = JUNG_ROOM + "j_link3";
    maze_path = JUNG_ROOM3 + "j_maze";
    maze_path2 = JUNG_ROOM4 + "j_maze";
    maze_path3 = JUNG_ROOM2 + "j_maze";

  }
  stringlen = strlen(JUNG_ROOM4)-1;
  if (room_name[0..stringlen] == JUNG_ROOM4|| room_name == JUNG_ROOM + "j_link3a"){
    tell_room(ETO, "Quali in a jungled room, or j_link3a");
    next_dest = JUNG_ROOM + "j_link4";
    maze_path = JUNG_ROOM4 + "j_maze";
    maze_path2 = JUNG_ROOM5 + "j_maze";
    maze_path3 = JUNG_ROOM6 + "j_maze";
  }
  stringlen = strlen(JUNG_ROOM5)-1;
  if (room_name[0..stringlen] == JUNG_ROOM5|| room_name == JUNG_ROOM + "j_link4a"
                                  || room_name = JUNG_ROOM + "j_link5"){
    tell_room(ETO, "Quali in a junglee room, or j_link4a");
    next_dest = JUNG_ROOM + "j_link9";
    maze_path = JUNG_ROOM5 + "j_maze";
    maze_path2 = JUNG_ROOM4 + "j_maze";
    maze_path3 = JUNG_ROOM6 + "j_maze";
  }
  stringlen = strlen(JUNG_ROOM6)-1;
  if (room_name[0..stringlen] == JUNG_ROOM6|| room_name == JUNG_ROOM + "j_link6"){
    tell_room(ETO, "Quali in a junglef room, or j_link6");
    next_dest = JUNG_ROOM + "j_link5a";
    maze_path = JUNG_ROOM6 + "j_maze";
    maze_path2 = JUNG_ROOM7 + "j_maze";
    maze_path3 = JUNG_ROOM5 + "j_maze";

  }
  stringlen = strlen(JUNG_ROOM7)-1;
  if (room_name[0..stringlen] == JUNG_ROOM7|| room_name == JUNG_ROOM + "j_link7"){
    tell_room(ETO, "Quali in a jungleg room, or j_link7");
    next_dest = JUNG_ROOM + "j_link6a";
    maze_path = JUNG_ROOM7 + "j_maze";
    maze_path2 = JUNG_ROOM8 + "j_maze";
    maze_path3 = JUNG_ROOM6 + "j_maze";
  }
  stringlen = strlen(JUNG_ROOM8)-1;
  if (room_name[0..stringlen] == JUNG_ROOM8|| room_name == JUNG_ROOM + "j_link8"){
    tell_room(ETO, "Quali in a jungleh room, or j_link8");
    next_dest = JUNG_ROOM + "j_link7a";
    maze_path = JUNG_ROOM8 + "j_maze";
    maze_path2 = JUNG_ROOM7 + "j_maze";
    maze_path3 = JUNG_ROOM1 + "j_maze";

  }
  stringlen = strlen(JUNG_ROOM9)-1;
  if (room_name[0..stringlen] == JUNG_ROOM9|| room_name == JUNG_ROOM + "j_link9a"){
    tell_room(ETO, "Quali in a junglei room, or j_link9a");
    next_dest = JUNG_ROOM + "j_link10";
    maze_path = JUNG_ROOM9 + "j_maze";
  }
  stringlen = strlen(JUNG_ROOM10)-1;
  if (room_name[0..stringlen] == JUNG_ROOM10|| room_name == JUNG_ROOM + "j_link10a"){
    tell_room(ETO, "Quali in a junglej room, or j_link10a");
    next_dest = ROOMS + "carved_gate";
    maze_path = JUNG_ROOM10 + "j_maze";
  }
  tell_room(ETO, "Next destination: " + next_dest);
  waystations = DESTINATIONS_D->query_waystations(next_dest);
  maze_time = MAZE_D->query_timing(maze_path);
  maze_time2 = MAZE_D->query_timing(maze_path2);
  maze_time3 = MAZE_D->query_timing(maze_path3);
  destination_time = DESTINATIONS_D->query_timing(next_dest);
  if (sizeof(waystations)<1 || maze_time > destination_time || maze_time2>destination_time || maze_time3>destination_time){
    if (sizeof(waystations) >0){
      tell_room(ETO, "Waystations out of date. Removing old ones");
      DESTINATIONS_D->remove_destination(next_dest);
    }
    tell_room(ETO, "Generating new waystations");
    DESTINATIONS_D->generate_waystations(next_dest, 5, 4);
  }
  start_walking(next_dest);
}


void open_gate5(){
  if (base_name(ETO) != JUNG_ROOM10 + "carved_gate"){
    return;
  }
  ETO->grant_entry2();
}

void open_gate4(object helper){
  if (!objectp(helper) || !objectp(ETO) || !present(helper, ETO)){
    tell_room(ETO, "A voice that is not one voice, but a myriad whispering tongues"
              +" speaking together issues clearly from the gateway:"
             +" %^CYAN%^Who do you mean, Lord Quali? We shall let pass who you wish");
    return;
  }
  force_me("emote turns toward the gate");
  tell_room(ETO, "A voice that is not one voice, but a myriad whispering tongues"
              +" speaking together issues clearly from the gateway:"
             +" %^CYAN%^Yess, Lord Quali. We shall let " + helper->QO + " through.");
  call_out("open_gate5", 2);
}


void open_gate3(object helper){
  if (!objectp(helper) || !objectp(ETO) || !present(helper, ETO)){
    return;
  }
  force_me("emote turns toward the gate");
  force_me("say My fellows, this is a loyal helper of the Tecqumin people. Will you let " + helper->QO + " through?");
  call_out("open_gate4", 2, helper);
}

void open_gate2(object helper){
  if (!objectp(helper) || !objectp(ETO) || !present(helper, ETO)){
    return;
  }
  force_me("say Ahh, you have found the gate. Are you having trouble getting through?");
  call_out("open_gate3", 3, helper);
}

void open_gate(object helper){
  if (!objectp(helper) || !objectp(ETO) || !present(helper, ETO)){
    return;
  }
  force_me("emoteat " + helper->query_name() + " nods to $N");
  call_out("open_gate2", 3, helper);
}

void give_heart2(object speaker){
  object heart, room;
  room = ETO;
  if (!objectp(room)){return;}
  if (!objectp(speaker) || !present(speaker, room)){return;}
  tell_object(speaker, "Quali hands you a %^ORANGE%^strange looking object");
  tell_room (room, "Quali hands a %^ORANGE%^strange looking object to%^RESET%^ "
           + speaker->QCN, speaker);
  heart = new(OBJ + "jungle_heart.c");
  heart->move(speaker);
  EVENT_RECORDS_D->record_event(speaker->query_name(), "Agreed to help Quali");
}

void unfettered2(){
  string * quests;
  object * people, room;
  int i;
  room = ETO;
  force_me("say I cannot understand. But what seems clear to me now is that"
          +" the world will not be safe from the Unfettered while its"
          +" spirit survives here. What is needed is for someome to find"
          +" entrance to the chamber, %^BOLD%^%^RED%^open the seal%^RESET%^"
          +" and defeat the Unfettered. Perhaps if this is done, the curse"
          +" on the%^CYAN%^ Tecqumin%^RESET%^ might be lifted.");
  if (!objectp(room)){return;}
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Secret of the Chamber",quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Secret of the Chamber");
  }
}

void fix_mind(){
  maddened = 0;
  set_emotes(20, ({"The jungle spirit's leaves rustle in the breeze", "Quali creaks softly to himself", "A shaft of light breaks through the jungle spirit's branches to strike the ground", "Quali creaks", "Quali rustles", "Quali emits a gentle groaning sound", "The jungle spirit moves around a bit" }));
}

void destruction2(){
  force_me("say I heard the screaming of my brother Gods as they perished."
           +" It rent the ether at the pitch of despair and I raced to the"
           +" city to lend aid. But then there was a second blast and the"
           +" noise of it maddened me. I ran from that place, visions of"
           +" the death of my people playing before my eyes, and two names"
           +" ringing in my ears. %^BOLD%^%^BLACK%^T%^RESET%^a%^BOLD%^"
           +"%^WHITE%^l%^BOLD%^%^BLACK%^o%^BOLD%^%^YELLOW%^s%^RESET%^,"
           +" %^BOLD%^%^BLACK%^the d%^YELLOW%^e%^BOLD%^%^BLACK%^str"
           +"%^RESET%^o%^BOLD%^%^WHITE%^y%^BOLD%^%^BLACK%^er%^RESET%^,"
           +" who brought this end to the %^CYAN%^Tecqumin%^RESET%^ and"
           +" %^BOLD%^%^RE%^L%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^v%^BOLD%^"
           +"%^RED%^i%^WHITE%^a%^RED%^t%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^r"
           +"%^RESET%^, who cursed their spirits to wander the world in"
           +" suffering.");
  call_out("destruction3",3);
}

void destruction3(){  
  string * quests;
  object * people, room;
  int i;
  room = ETO;
  force_me("emote trembles in rage at a memory passing before his eyes");
  force_me("say And they cursed and destroyed the Tecqumin because they had"
          +" been gathering %^CYAN%^life forces%^RESET%^ from the"
          +" %^ORANGE%^sacrifices%^RESET%^ made to their %^ORANGE%^gods"
          +"%^RESET%^, in order to break the seals on the prison of the"
          +" %^BLUE%^abomination%^RESET%^ known as the%^MAGENTA%^"
          +" Unfettered%^RESET%^!");

  if (!objectp(room)){return;}
  people = all_living(room);
  if (sizeof(people)<1){return;}
  for (i=0;i<sizeof(people);i++){
    if (!interactive(people[i])){
      continue;
    }
    quests = people[i]->query_mini_quests();
    if (member_array("Heard of the Unfettered",quests)){
      return;
    }
    people[i]->set_mini_quest("Heard of the Unfettered");
  }
}

