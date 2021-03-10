//blacksmith.c - The Tabaxi blacksmith                                 
// Coded by Lujke 29/12/06
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
#include "../chants.h"
inherit QNPC;

void set_responses();

object helper;

void create(){
   object flask;
   ::create();
   set_name("Milintica");
   set_id( ({"milintica","tabaxi","tabaxi smith", "smith", "tabaxi blacksmith", "blacksmith"}) );
   set_short("Milintica, the tabaxi smith");
   set_race("tabaxi");
   set_body_type("humanoid");
   set_hd(25,12);
   set_size(2);
   set_long( (:TO, "long_desc" :));
   set_gender("female");
   set_hd(30, 1);
   set_alignment(8);
   set_max_hp(200 + (8*query_hd()));
   set_hp(query_max_hp());
   set_overall_ac(-60);
   set_class("fighter");
   set_mlevel("fighter",45);
   set_level(45);
   set_stats("wisdom",14);
   set_stats("strength",16);
   set_stats("constitution",18);
   set_stats("intelligence",13);
   set_stats("charisma",16);
   set_stats("dexterity",13);
      set_new_exp(45, "normal");
   set("aggressive",0);
   set_responses();
   flask = new (TABAXOBJ + "hip_flask");
   flask->move(TO);
   "/daemon/feat_d.c"->add_my_feat(TO,"other","craft, weaponsmith");
   "/daemon/feat_d.c"->add_my_feat(TO,"other","craft, armorsmith");
   set_skill("craft, weaponsmith", 100);
   set_skill("craft, armorsmith", 100);
}

void init(){
  ::init();
  set_responses();
}

void set_responses(){
//  remove_response(({"hello", "greetings", "good day", "gooday"}));
  set_response(({"hello", "greetings", "good day", 
                "gooday"}), 
            ({"Whut?", "Wheresh my drink?" }) , "greet" );
  set_response(({"sober", "drunk", "drunkard" }), 
            ({ "Uh" }), "drunk" );
  set_response(({"dead", "deaths", "family", "children", "mate"}), 
            ({"Hmmph" }), "deaths" );
//  remove_response(({"request aid for the village", "request", "aid"}));
  set_response(({"request aid for the village", "request", "aid"}), 
                ({"Um"}), "request");
  set_response(({"fix catapult", "repair catapult", "restore catapult",
      "fix the catapult", "repair the catapult", "restore the catapult"}), 
                ({"Oh"}), "fix_catapult");
  set_response(({"catapult"}), 
                ({"Hmm"}), "catapult");
  set_response(({"make weapons", "make equipment", "make armour", "make bows"}), 
                ({"Ahem"}), "make_em");
}

void goto_smithy(){
  mapping waystations;
  waystations = DESTINATIONS_D->query_waystations(TABAXROOM + "smithy");
  if (sizeof(waystations)<1){
    DESTINATIONS_D->generate_waystations(TABAXROOM + "smithy", 3, 2);
  }
  DESTINATIONS_D->generate_waystations(TABAXROOM + "smithy", 3, 2);
  start_walking(TABAXROOM + "smithy");
}

void commence_me(object speaker){
  if (!objectp (speaker) || !present(speaker, ETO)){
    force_me("say Hey! Wherre'd you go? I hadn't finished speaking!");
    remove_call_out("respond");
  }
  if(!objectp(helper) || helper != speaker){
    helper = speaker;
  } 
}

int reach_destination(){
  mapping waystations;
  if (!objectp(ETO)){ return 1;}
  if (file_name(ETO) == TABAXROOM + "southeast_corner"){
    if (query_intox()>5){
      force_me("say wha' did I come here for?");
      goto_smithy();
      return 1;
    }
    force_me("repair catapult");
    call_out("repair2", 5);
  }
}

void make_weapons(){
  if (!objectp(ETO)){
    return;
  }
  if (query_intox()>5){
    force_me("emote sits down, with her head swimming");
    return;
  }
  if (file_name(ETO)!= TABAXROOM + "smithy"){
    goto_smithy();
    return;
  }
  if ((int)ETO->query_weapons()<1){
    force_me("make weapons");
    call_out("make weapons", 12);
    return;
  }
  if ((int)ETO->query_armour()<1){
    force_me("make armour");
    call_out("make weapons", 12);
    return;
  }
  if ((int)ETO->query_bows()<1){
    force_me("make bows");
    call_out("make weapons", 12);
    return;
  }
  switch (random(2)){
  case 0:
    force_me("make weapons");
    break;
  case 1: 
    force_me("make armour");
    break;
  case 2:
    force_me("make bows");
    break;
  }
  call_out("make weapons", 12);
}

void repair2(){
  object catapult;
  if (!objectp(ETO)){
    return;
  }
  catapult = present("catapult", ETO);
  if (!objectp(catapult)){
    goto_smithy();
    return;
  }
  if (catapult->query_overallStatus()<100){
    force_me("repair catapult");
    call_out("repair2", 5);
  } else {
    goto_smithy();
  }
}

void make_em(){
  if (query_intox()>5){
    force_me("say I think I'm too drrunk too hold my hammersh");
    return;
  }
  force_me("say Okay, I weel make thee equipment wee need tha most");
  force_me("pose making things at the forge");
  make_weapons();
}

void fix_catapult(object ob){
  mapping waystations;
  if (query_intox()>5){
    force_me("say Whash tha? I don' know no catapilla");
  } else {
    force_me("say Alright, I'll jus' go fix it.");
    waystations = DESTINATIONS_D->query_waystations(TABAXROOM + "southeast_corner");
    if (sizeof(waystations)<1){
      DESTINATIONS_D->generate_waystations(TABAXROOM + "southeast_corner", 2,3);
    }
    start_walking(TABAXROOM + "southeast_corner");
  }   
}

void catapult(object ob){
  if (query_intox()>5){
    force_me("say Whash tha? I don' know no catapilla");
  } else {
    force_me("say Yeah, the catapult's bin out of use a long time. If you wan me ta fix it, jus' ask.");
  }   
}

void greet(object ob){
  if (query_intox()>5){
    force_me("say Wheresh my drink?");
  } else {
    force_me("say Ello. strangers. 'Scuse me being a bit strange. My head hurts.");
  }   
}

void drunk(object ob){
  if (query_intox()>5){
    force_me("say Sho whut if I'm drunk?. They're all dead.");
  } else {
    force_me("say Yeah, I wanna drink.");
    force_me("drink drink");
  } 
}

void deaths(object ob){
  if (query_intox()>5){
    force_me("say No! They can't be dead!");
    force_me("drink drink");
  } else {
    force_me("say Been talking to Nobacherie, haf jew? Yes, my mate an kids all died."
    +" I haf been drinking to try to forget. Now I jus wanna elp kill all thee orogs");
  } 
}

void request(object ob){
if (query_intox()>5){
    force_me("say I can't help jew. I'm too drrunk!");
  } else {
    force_me("say I can help make weapons, or fix things if you need");
  }
}

void heart_beat(){
  ::heart_beat();
  if (random (15)==0){
    force_me("drink drink");
  }
}

string long_desc(){
  string desc; 
  desc = "A middle aged female tabaxi with a powerful shoulders, a barrel torso and thickly muscled"
            +" arms. Her fur is grubby and dishevelled, and her teeth are a bit yellow. She carries a smithing hammer,"
            +" which suggests she might possibly be a smith.";
  return desc;
}
