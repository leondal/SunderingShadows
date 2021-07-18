#include <std.h>

inherit MONSTER;

int flag;

void create(){
    object obj;
    ::create();
    set_name("Cassius");
    set_short("Cassius, a flamboyant young nobleman");
    set_id(({"cassius","Cassius","nobleman","man","young nobleman","young man"}));
    set_long(
       "Cassius is dressed in the flamboyant manner common to young "+
       "noblemen in Torm.  His %^BOLD%^%^WHITE%^half-cloak %^RESET%^"+
       "%^CYAN%^is lined with %^BOLD%^silk %^RESET%^%^CYAN%^and edged "+
       "in %^ORANGE%^l%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^n%^BOLD%^"+
       "%^BLACK%^x %^RESET%^%^ORANGE%^fur%^CYAN%^, the mark of house "+
       "%^BOLD%^%^WHITE%^Gallini%^RESET%^%^CYAN%^.  The cloak is kept "+
       "'casually' thrown over one shoulder, allowing his sword arm to "+
       "remain free.  Sheathed at his side is a magnificent %^BOLD%^"+
       "rapier%^RESET%^%^CYAN%^ couched in an intricately wrought "+
       "sheath.  He wears form-fitting %^BOLD%^%^BLACK%^leather "+
       "trousers %^RESET%^%^CYAN%^with a color-coordinated %^BOLD%^"+
       "%^BLUE%^tunic%^RESET%^%^CYAN%^, and not a hair on his %^YELLOW%^"+
       "blonde head %^RESET%^%^CYAN%^is out of place.  His face is "+
       "kept smoothly shaven, save for a narrow, pointed %^YELLOW%^"+
       "goatee%^RESET%^%^CYAN%^.  Eyes of %^BOLD%^%^BLUE%^crystal "+
       "blue %^RESET%^%^CYAN%^regard his "+
       "surroundings with an air of superiority, and he permanently looks "+
       "as though he's smelled something bad.  He would likely not "+
       "take kindly to any %^BOLD%^<%^BLUE%^insult%^CYAN%^> %^RESET%^"+
       "%^CYAN%^or %^BOLD%^<%^BLUE%^challenge%^CYAN%^>%^RESET%^%^CYAN%^.  "+
       "Careful, though, pompous as he may be, you get the feeling "+
       "he could easily defend himself."
    );
    set_heart_beat(1);
    set_mob_magic_resistance("average");
    set_exp(35000);
    set_race("human");
    set_body_type("human");
    set_hd(33, 0);
    set_class("fighter");
    set_mlevel("fighter",33);
    set_fighter_style("swashbuckler");
    set_max_hp(400);
    set_hp(query_max_hp());
    set_alignment(3);
    add_search_path("/cmds/fighter");
    set_property("full attacks",1);
    set_stats("strength", 19);
    set_stats("constitution", 16);
    set_stats("dexterity", 18);
    set_stats("intelligence", 15);
    set_stats("charisma", 16);
    set_stats("wisdom", 13);
    new("/d/dagger/Torm/obj/duel")->move(TO);
    new("/d/dagger/Torm/obj/duel_sheath")->move(TO);
    force_me("sheath duel");
    obj = new("/d/deku/sanctuary/obj/armguard");
    if(random(3)) obj->set_property("monsterweapon",1);
    obj->move(TO);
    obj = new("/d/common/obj/armour/studded");
    obj->set_property("monsterweapon",1);
    obj->move(TO);
    obj = new("/d/shadow/obj/clothing/silkcloak");
    if(random(4)) obj->set_property("monsterweapon",1);
    obj->move(TO);
    command("wearall");
    set_overall_ac(-8);
    add_money("gold",500+random(500));
    set_funcs(({"flashit","flashit","flashit","flashit","fancy","fancy","fancy","strut"}));
    set_func_chance(55);
    set_speed(80);
    flag = 0;
    set_emotes(3,({
       "%^CYAN%^Cassius pauses to flick an imaginary speck of dust from his cloak.",
       "Cassius stands still for a moment, looking casually up at the sky as though he knows what a striking image he creates.",
       "Cassius smiles at a passing young lady, who giggles and blushes.",
       "%^CYAN%^Cassius brushes back his %^YELLOW%^blonde hair %^RESET%^%^CYAN%^with a flick of his wrist.",
       "Cassius adjusts his cloak, keeping his sword-arm free."
    }),0);
    set_nogo(({"/d/dagger/Torm/city/c107","/d/dagger/Torm/city/c111","/d/dagger/Torm/city/c45"}));
}

void init(){
  ::init();
  add_action("xstab", "stab");
  add_action("xstab", "kill");
  add_action("xstab", "rush");
  add_action("xlook","look");
  add_action("insult_me","insult");
  add_action("challenge_me","challenge");
}
//xstab functions borrowed from /d/azha/mon/alradin.c

int insult_me(string str){
   object shape;
   string mrace;
   if(TP->query_invis()) return 1;

   mrace = (string)TP->query_race();
   if(objectp(shape = TP->query_property("shapeshifted"))) mrace = (string)shape->query_shape_race();

   if((!str) || (str != "cassius" && str != "Cassius")){
      tell_object(TP,"You need to <insult cassius>, if that is your goal.");
      return 1;
   }
   if(sizeof(TO->query_attackers()) > 0){
      tell_object(TP,"Cassius is too busy to notice your insult.");
      return 1;
   }
   tell_object(TP,"%^RED%^You call out an insult to Cassius, who stops "+
      "dead in his tracks.");
   tell_room(ETO,"%^RED%^"+TPQCN+" calls out an insult to Cassius, "+
      "who stops dead in his tracks as the crowd gasps and begins to gather "+
      "around.",TP);
   TO->force_me("say No one...especially not some no-name "+
      ""+mrace+" like you can talk to me that way.");
   TO->force_me("yell Do you have any idea who my father is?!");
   TO->force_me("emote snarls and draws his sword.");
   TO->force_me("draw duel");
   TO->force_me("rush "+TPQN);
   flag = 1;
   return 1;
}

int challenge_me(string str){
   if((!str) || (str != "cassius" && str != "Cassius")){
      tell_object(TP,"You need to <challenge cassius>, if that is your goal.");
      return 1;
   }
   if(sizeof(TO->query_attackers()) > 0){
      tell_object(TP,"Cassius is too busy to notice your challenge.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You issue a challenge to Cassius, who turns "+
      "with a raised eyebrow.");
   tell_room(ETO,"%^BOLD%^"+TPQCN+" issues a challenge to Cassius, "+
      "who turns with a raised eyebrow.  A few people in the gathering "+
      "crowd grin to one another and move a little closer to watch.",TP);
   TO->force_me("say Well, well...a challenger, eh?  Let us see if "+
      "you are as worthy as you think you are.");
   TO->force_me("smirk "+TPQN+"");
   TO->force_me("draw duel");
   TO->force_me("emote %^BOLD%^%^BLUE%^salutes with a simple turn "+
      "of his sword in front of "+
      "his face and falls back into a position to attack.");
   TO->force_me("kill "+TPQN);
   flag = 1;
   return 1;
}

int xstab(string str){
  object ob;
  if(flag == 1) return 0;
  if(member_array(str, query_id()) != -1) {
     TO->force_me("emote seems to sense you and blocks your attempt at "+
        "an attack.");
     TO->force_me("say Tsk, tsk, tsk...such dishonor.  You will never "+
        "know the honor of being a nobleman!");
     flag = 1;
     TO->force_me("say Very well, we will do things your way.");
     TO->force_me("draw duel");
     TO->force_me("rush "+TPQN);
     return 1;
  }
  return 0;
}

int xlook(string str){
  object ob;
  if(sizeof(TO->query_attackers()) > 0) return 0;
  if(TP->query_invis()) return 0;
  if(member_array(str, query_id()) != -1) {
    if(TP->query_blind()){
        write("You are blind and cannot see anything.");
        return 1;
    }
    if(TP->light_blind(0))  {
        write(TP->light_blind_fail_message(TP->light_blind(1)));
        return 1;
    }
    if(total_light(this_player()) < 1) write("It is dark.");
     if(TP->query_ansi())
        write(ansi_str( (string)TO->query_long(str) ));
     else
        write((string)TO->query_long(str));
     TO->force_me("emote seems to realize he's fallen under scrutiny "+
        "and sneers.");
     TO->force_me("say Why don't you have an artist paint you a "+
        "picture?  In truth, it would last longer.");
     return 1;
  }
  return 0;
}

void heart_beat(){
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(query_hp() < 400){
       add_hp(random(3)+2);
    }
    if(sizeof(TO->query_attackers()) < 1){
       if(sizeof(TO->query_wielded()) > 0){
          force_me("emote wipes the blood from his blade.");
          remove_property("rushed");
          flag = 0;
          force_me("sheath duel");
       }
    }
}


int flashit(object targ){
   if(!objectp(TO)) return 0;
   if(!objectp(targ)) return 0;
   force_me("flash");
   return 1;
}

int fancy(object targ){
   if(!objectp(TO)) return 0;
   if(!objectp(targ)) return 0;
   tell_room(ETO,"%^BOLD%^%^CYAN%^Cassius moves deftly, turning a "+
      "somersault in the air before landing behind "+targ->QCN+" "+
      "and scoring a gruesome hit!",targ);
   tell_object(targ,"%^BOLD%^%^CYAN%^In a flash, you lose sight of "+
      "Cassius!\n%^RED%^You feel a sharp puncture in your back as "+
      "he strikes!");
   targ->do_damage("torso",random(4)+7);
   TO->execute_attack();
   return 1;
}

int strut(object targ){
   if(!objectp(TO)) return 0;
   if(!objectp(targ)) return 0;
   tell_room(ETO,"%^CYAN%^Cassius turns from "+targ->QCN+" with a "+
      "confident look on his face and waves his arms, as if for the "+
      "crowd's approval!",targ);
   tell_object(targ,"%^CYAN%^Cassius turns his back on you and waves "+
      "his arms for the crowd's approval!  Arrogant ass.");
   return 1;
}

void die(object ob){
   object targ;
   targ = TO->query_current_attacker();
   if(present(targ,ETO)){
      tell_room(ETO,"%^RED%^Cassius falls dramatically to the ground with a look "+
         "of pure hatred directed at "+targ->QCN+".",targ);
      tell_object(targ,"%^RED%^Cassius falls dramatically to the ground with a look "+
         "of pure hatred directed at you.");
      tell_room(ETO,"%^MAGENTA%^Cassius says%^RESET%^: You...will pay...");
      if(objectp(targ)){
         if(member_array("Defeated Cassius in a Duel",targ->query_mini_quests()) == -1){
            tell_object(targ,"%^BOLD%^%^CYAN%^You've just defeated Cassius "+
               "in a duel!%^RESET%^");
            targ->set_mini_quest("Defeated Cassius in a Duel",1000000,"%^BOLD%^%^CYAN%^Defeated Cassius in a Duel%^RESET%^");
         }
      }
   }else{
      tell_room(ETO,"%^RED%^Cassius falls dramatically to the ground "+
         "and shudders to his death.");
   }
   ::die(ob);
}

int query_watched(){
   return 150;
}