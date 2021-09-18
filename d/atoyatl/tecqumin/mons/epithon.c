//epithon.c - The Tecqumin Prince                                 
// Coded by Lujke 29/12/06
#include <std.h>
#include "../tecqumin.h"
inherit QNPC;

void set_responses();
void receive_gift();
void receive2();
void receive3();
void receive4();


void create(){
   ::create();
   set_name("Epithon");
   set_id( ({"epithon","prince","prince epithon", "ghost", 
                                            "tecqumin"}) );
   set_short("Epithon, Prince of the Tecqumin");
   set_long("Epithon's spirit form reveals him to have been a man"
     +" perhaps in his late thirties. He has the %^ORANGE%^amber"
     +" %^RESET%^skin colouring and broad, high cheekboned face"
     +" typical of the %^CYAN%^Tecqumin%^RESET%^. He is of medium"
     +" height and has a lithe, wirey build. His nose is pierced and"
     +" decorated with a spike of %^BOLD%^%^WHITE%^bone%^RESET%^,"
     +" and he wears much %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o"
     +"%^BOLD%^%^YELLOW%^ld%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^n"
     +" j%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^wel%^RESET%^"
     +"%^ORANGE%^e%^BOLD%^%^YELLOW%^ry%^RESET%^, including necklaces"
     +", bangles and earrings. He is dressed in a simple, short"
     +" %^BOLD%^%^WHITE%^white kilt%^RESET%^ and %^ORANGE%^thonged"
     +" sandals%^RESET%^. The %^BOLD%^%^WHITE%^kilt%^RESET%^ is held"
     +" closed with a belt of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^"
     +"o%^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^d %^BOLD%^%^YELLOW%^l"
     +"%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^n%^RESET%^%^ORANGE%^k"
     +"%^BOLD%^%^YELLOW%^s%^RESET%^. At his side, he wears a fine"
     +" looking %^ORANGE%^amber hafted%^RESET%^ sword.");
   set_gender("male");
   set_race("ghost");
   set_body_type("human");
   set_hd(90,5);
   set_alignment(5);
   set_max_hp(2500);
   set_hp(query_max_hp());
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
   add_attack_bonus(75); 
   set_overall_ac(-75);
   set("aggressive",0);
   set_responses();
   will_open = 1;
   set_property("untrackable", 1);

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

/*
void die(object ob) {
   object money_ob, ectoplasm;
   object *contents;
   int i, tmp_size;
   string *currs;

   message("other_action", "%^RED%^"+query_cap_name()+
     " swirls, loses form and is banished%^RESET%^", 
     environment(this_object()), ({ this_object()}));
   message("other_action", "%^BLUE%^A smeary residue is left behind", 
     environment(this_object()), ({ this_object()}));
   tmp = ETO;
   tmp_size=sizeof(currs=query_currencies());
   if(tmp_size && has_value()) {
      money_ob = new("/std/obj/coins");
      for(i=0; i<tmp_size; i++) {
         money_ob->add_money(currs[i], query_money(currs[i]));
         add_money(currs[i], -query_money(currs[i]));
      }
      money_ob->move(tmp);
   }
   contents = all_inventory(this_object());
   for(i=0;i<sizeof(contents);i++) {
      if(contents[i]->query_property("monsterweapon"))
         continue;
      else
         if(!contents[i]->query_short()) continue;
      else contents[i]->move(tmp);
   }
   contents = all_inventory(this_object());
   for(i=0;i<sizeof(contents);i++) contents[i]->remove();
   if(TO->query_property("riding"))
      if(TO->query_owner() && objectp(TO->query_owner()))
         (TO->query_owner())->remove_pet(TO);

	if(TO->query_property("death effects")) 
	{
		"/daemon/death_effects_d"->get_death_effect(TO);
	}
   ectoplasm = new (OBJ + "ectoplasm");
   ectoplasm->set_spirit_name(TO->query_name());
   ectoplasm->move(tmp);
   remove();
} */

set_responses(){
  set_response(({"hello", "greetings"}), ({"What?","No-one has"
    +" approached the Throne of the %^CYAN%^Tecqumin%^RESET%^ since"
    +" the %^BLUE%^downfall of our people%^RESET%^." }),"lookup" );
  set_response(({"tecqumin"}), ({"We are the people of this island."
    +" We lived here many years, proud and powerful under the"
    +" auspices of our %^ORANGE%^Gods%^RESET%^. But now our city"
    +" lies in ruins, our many victories no more than distant"
    +" memories"}) );
  set_response(({"fountain", "fountain of youth"}), ({"The priests"
   +" told me of a fountain that would restore youth to the old.",
    "I had the soldiers of the %^CYAN%^Tecqumin%^RESET%^ empire seek"
   +" it out, but the end of our people came before they could bring"
   +" me its location." }) );
  set_response(({"island", "river island"}), ({"I once fancied that"
   +" I glimpsed an island in the river, through the foliage of the"
   +" jungle. The jungle was too thick there to reach the riverbank,"
   +" though. If the island was real, it would only be reached by"
   +" boat." }) );

  set_response( ({"foreign gods"}), ({"When %^ORANGE%^Taluc%^RESET%^"
    +" returned from his travels, he brought word of strange"
    +" %^ORANGE%^Gods%^RESET%^ he had encountered in foreign lands."
    +" Many laughed at him, and I might have done the same, had I"
    +" not heard the sincerity in his voice when he tried to warn"
    +" the %^CYAN%^Empress%^RESET%^.", 
        "A pity that she would not believe him, and refused to take"
    +" the action that was needed. It was because of this that I was"
    +" left with no option but to %^BLUE%^take the throne%^RESET%^"
    +" myself."}));
  set_response(({"gods" }), ({"We of the %^CYAN%^Tecqumin%^RESET%^"
    +" worshipped our Gods for many ages. Why should we give them"
    +" up?", 
       "I was outraged when I learned from %^BLUE%^Taluc%^RESET%^ that"
    +" those foreign Gods he heard of on his travels had plans to"
    +" prevent us being able to continue to %^ORANGE%^worship our"
    +" Gods%^RESET%^." }) );
  set_response(({"prince"}), ({"I am the Prince of the%^CYAN%^"
    +" Tecqumin%^RESET%^, and their ruler."}) );
  set_response( ({"taluc"}), ({"Taluc is a most loyal subject of the"
    +" %^CYAN%^Tecqumin%^RESET%^ throne. Some had their suspicions"
    +" about him because he travelled so far from our home for so"
    +" long, but I was sure that he remained true to our people.", 
       "It was he who warned me of the threat we faced from the"
    +" %^ORANGE%^foreign gods%^RESET%^."}) );
  set_response(({"take the throne"}),({"Yes, I took the throne from"
    +" my sister, the %^CYAN%^Empress%^RESET%^.", 
       "It was not the proud moment I might have wanted it to be,"
    +" for all that the people applauded my ascension. I had"
    +" respected my sister and let her rule for many years, even"
    +" though her claim to the throne was in truth less than my own."
    +" But the fact she refused to take action to %^CYAN%^protect the"
    +" Tecqumin people%^RESET%^ left me with no choice."}), "lower");
  set_response(({"protect the tecqumin"}), ({"The word that"
    +" %^CYAN%^Taluc%^RESET%^ brought to my sister was clear; to"
    +" protect our people from the insurgence of the%^ORANGE%^"
    +" foreign gods%^RESET%^, we must needs begin worship of another"
    +", one who could protect us from them.",
       " Taluc brought us that answer, but she would not listen to"
    +" him, and so he turned to me.", 
       "It was I who took up the challenge; I who was willing to"
    +" take the risk to %^BLUE%^save our people%^RESET%^."}) );
  set_response(({"save our people", "save your people"}), ({"Taluc"
    +" told me of the God he called the %^BLUE%^Unfettered%^RESET%^."
    +" He said it was not one of the %^ORANGE%^foreign gods%^RESET%^"
    +" who were a threat to us, but that it was powerful enough to"
    +" defend us from them.",
        "He said that all we would need to do was to offer some of"
    +" the sacrifices we were currently making to our own %^ORANGE%^"
    +"Gods%^RESET%^ to the %^BLUE%^Unfettered %^RESET%^instead, and"
    +" once enough sacrifices had been made, the %^BLUE%^Unfettered"
    +"%^RESET%^ would protect us.",
        "The %^CYAN%^downfall of our people%^RESET%^ was that we"
    +" were not able to make the sacrifices quickly enough, and the"
    +" %^ORANGE%^foreign gods%^RESET%^ cursed and destroyed our race"
    +" before the %^BLUE%^Unfettered%^RESET%^ could intervene."}), 
        "unfetter"  ); 
  set_response(({"lift the curse"}), ({"I do not know a way. Maybe Taluc does."}));

  set_response(({"curse", "cursed", "ghosts"}), ({"My people, the once"
   +" proud %^CYAN%^Tecqumin%^RESET%^ race are cursed by the%^ORANGE%^"
   +" foreign gods%^RESET%^ to wander these lands in undeath as ghosts.",
   "Only if we lift the curse can we be free of this existence"}));
  set_response(({"end of our people", "end of your people", 
    "end of the tecqumin", "downfall of our people", 
    "downfall of your people", "downfall of the tecqumin"}), 
    ({"The %^ORANGE%^foreign gods%^RESET%^ came in great wrath,"
   +" before we had managed to complete the work to raise the"
   +" %^MAGENTA%^Unfettered%^RESET%^ to its full power.", "Taluc was"
   +" right; so jealous they were of their own power, they would not"
   +" allow it to be challenged!", "And yet, though its power was"
   +" incomplete, still the %^BLUE%^Unfettered%^RESET%^ was too great"
   +" a foe for them to defeat easily.", "The battle shattered our"
   +" city and destroyed us as a people, leaving just these cursed"
   +" ghosts you see now."}), "nod", ({"Heard of the Unfettered"}));
  set_response( ({"unfettered"}), ({"It is a being of some mystery,"
    +" to me at least. Taluc may know more about it."}),"nod",
                ({"Heard of the Unfettered"}));
  set_response(({"jontar", "old priest"}),({"That old fool was too"
    +" much the traditionalist to understand why we needed extra"
    +" help. He resisted everything Taluc and I were trying to do.",
        "I wonder what became of him"}) );
  set_response(({"empress", "mehaq"}),({"My half sister was the"
    +" Empress, before I found myself forced to take power from her."
    +" A sad day, but necessary."}) );
  set_response(({"jetstone"}),({"So you want the Jetstone, hmm?", 
       "Very well, you may borrow it. But first, you need to do"
    +" something for me. Deep inside the ziggurat of the Sun Lord,"
    +" is an ancient relic. The shrunken head of my ancestor,"
    +" Qualtaolheth. Retrieve it for me, and I shall release the"
    +" jetstone to you."}) );
  set_response(({"shrunken head", "qualtaolheth", "relic"}),({"When"
    +" you have the relic, return it to my hand and we shall see"
    +" about your reward"}) );
}

void lookup(object speaker){
  force_me("emote looks up sharply");
}

void nod(object speaker){
  force_me("emote nods");
}
void lower(object speaker){
  force_me("emote lowers his head");
}

void unfetter(object speaker){
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
    if (member_array("Heard of the Unfettered",quests)!=-1){
      continue;
    }
    people[i]->set_mini_quest("Heard of the Unfettered");
  }
}

void catch_tell(string str){
  str = strip_colors(str);
  str = lower_case(str);

  if (interact("gives you", str) && interact( "shrunken human head", str)){
    call_out("receive_gift", 1);
  }
}

void receive_gift(){
  object * stuff, thing;
  string name;
  stuff = all_inventory(TO);
  if (sizeof(stuff)>0){
    thing = stuff[0];
  }
  if (objectp(thing)){
    if (thing->id("blackened head")){
      force_me("say The head of Qualtaolheth! You found it!");
      call_out("receive2",2);
     return; 
    }
    force_me("say This is nothing that I require");
    name = thing->query_short();
    force_me ("emote drops " + name);
    thing->move(ETO);
  }
}

void receive2(){
  force_me("emote smiles");
  force_me("say Very well, I am sure you wish to have access to your"
          +" reward.");
  call_out("receive3", 2);
}

void receive3(){
  object room;
  room = ETO;
  if (objectp(room)){
    room->pull_lever2(TO);
  }
//  force_me("pull lever");
  call_out("receive4", 1);
}

void receive4(){
  force_me("say The jetstone is located in a guard chamber inside the"
   +" top of the Sun Lord's ziggurat. You can find it there now, in"
   +" an opening in the north wall. I should hurry, if I were you, in"
   +" case someone else gets there first");
}
