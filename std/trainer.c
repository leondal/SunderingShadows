//trainer.c inheritable
//added a temporary fix to the trainer problem with protecting objects 12/9/04 - tsera
#include <std.h>
#include <daemons.h>
//#define NOT ({})

// Fix for buggy weapons?

#define NOT ({ 0 })

#define PROFS (["fighter":({3,5}),"cleric":({3,5}),"mage":({1,5}),"psion":({1,5}),"thief":({4,10})])

inherit NPC;

void create() {
  ::create();
  set_body_type("human");
  set_use_monster_flag(0);
  add_dbs(({"trainers"}));
}


void do_training() {

  object wielded, *inven,*protectors;
  int i,j,num;
  string skill,name;

  if(!objectp(TO)) { return; }
  if(!objectp(ETO)) { return; }

  if(!sizeof(inven = query_attackers())) {
    return;
  }
  j = sizeof(inven);

  for(i=0;i<j;i++) {
    if(!objectp(inven[i])) continue;
    protectors = inven[i]->query_protectors();
    if(!interactive(inven[i])) {
      force_me("say I cannot train you with "+inven[i]->query_cap_name()+" protecting you!");
      //force_me("say I have no use for you "+inven[i]->query_cap_name());
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
      //inven[i]->move("/d/shadowgate/void");
      //inven[i]->remove(); 
      continue;
    }
    if(inven[i]->query_paralyzed()){
      force_me("say You seem to have become disabled in some fashion, let us begin when you are able.");
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
      continue;
    }
    if(sizeof(protectors)){ // added some checks here so he only refused to train if the protectors were in the room -Ares
        for(num=0;num<sizeof(protectors);num++){
            if(!objectp(protectors[num])) { continue; }
            if(!present(protectors[num],ETO)) { continue; }
            force_me("say How do you expect to train with someone protecting "+
                "you like that?");
            remove_attacker(inven[i]);
            inven[i]->cease_all_attacks();
            continue;
//This continue was below the bracket instead of above
//Moving it to try to fix bugs.  ~Circe~ 6/1/08
        }
    }
    if(inven[i]->query_hp_percent() < 50) {
      force_me("say You have fought well, "+inven[i]->query_cap_name()+", but you should tend to your wounds now.");
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
      continue;
    }
    if(sizeof(distinct_array(inven[i]->query_wielded())) != 1 ) {
      force_me("whisper "+inven[i]->query_name()+" You need to wield one weapon to train in that weapon.");
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
      continue;
    }
    wielded =  ((object *)inven[i]->query_wielded())[0];
    if(!objectp(wielded)) continue;
    if (!wielded->is_ok_wield()) {
        force_me("whisper "+inven[i]->query_name()+" I can not train you in that weapon, you simply lack the knack.");
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
        continue;
    }
    skill = ((object *)inven[i]->query_wielded())[0]->query_prof_type();
    if(member_array(skill, NOT) != -1) {
      force_me("say I can not train you in the weapon type "+skill+".");
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
      continue;
    }
    if(!SKILLS_D->training_formula(inven[i], skill)) {
      force_me("say You are incapable of learning more in the weapon type "+skill+", "+inven[i]->query_cap_name()+".");
      remove_attacker(inven[i]);
      inven[i]->cease_all_attacks();
      continue;  
    }
  }
}


void heart_beat() {
  ::heart_beat();
  do_training();
}

void die(object ob) {
  tell_room(ETO,"%^BOLD%^Ahhh good shot my student, lets keep it going...");
  set_hp(query_max_hp());
}

init() {
  ::init();
  add_action("apply","apply");
  add_action("specialize","specialize");
  add_action("rescueem","rescue");
  add_action("protectem","protect");
}

int apply(string str) {
  string skill, type,theclass,type2,*classes;
  int level, total, how,i,j,profs1,profs2,num;
  mapping profs;
  string *skills;
  object wielded;

  if (!str) {
    return notify_fail("Usage: apply prof to <skill name>\n");
  }

  if (sscanf(str,"prof to %s",skill) != 1) {
    return notify_fail("Usage: apply prof to <skill name>\n");
  }

  if (!TP->query_skill(skill)) {
    return notify_fail("You have no knowledge of that skill.\n");
  }

  if (skill == "magic weapons")
    return notify_fail("The magic weapons type does not use proficiencies.\n");
  // I'm massaging the following code with parenthesis to make the code
  // clearer and easier to read. Also fixing bug with fighter specialization.
  // was > 12 on the last comparison, when it should have been 11.
  //
  // - Garrett

  if ( ((int)TP->query_profs(skill) > 1)
    && ( (skill != (string)TP->query("specialized")) 
       || ((int)TP->query_profs(skill) > 11) ) ) {
    return notify_fail("You have maxed the profs available for that skill.\n");
  }

  if(TP->is_class("cleric") || TP->is_class("warlord")) { // temporary
    type= "cleric";
  }
  else if( (TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin"))) {
    type= "fighter";
  }
  else if((TP->is_class("thief")) || TP->is_class("assassin")) {
    type = "thief";
  }
  else {
    type= "mage";
  }

   // This is just ugly -Ares
   if(theclass = TP->get_dual_class())
   {
       classes = TP->query_classes();
       classes -= ({ theclass });

       if(TP->query_lowest_level() < TP->query_class_level(theclass))
       {
           if(theclass == "cleric" || theclass == "warlord") { type2 = "cleric"; } // temporary
           else if(theclass == "fighter" || theclass == "bard" || theclass == "ranger" || theclass == "paladin" || theclass == "antipaladin" || theclass == "cavalier")
           {
               type2 = "fighter";
           }
           else if(theclass == "thief" || theclass == "assassin")
           { 
               type2 = "thief";
           }           
           else { type2 = "mage"; }
           
           num = PROFS[type2][0] * ((int)TP->query_level(theclass)/PROFS[type2][1] + 1);
           theclass = classes[0]; // Just in case their first theclass happens to have more profs than their second

           if(theclass == "cleric" || theclass == "warlord") { type2 = "cleric"; } // temporary
           else if(theclass == "fighter" || theclass == "bard" || theclass == "ranger" || theclass == "paladin" || theclass == "antipaladin" || theclass == "cavalier")
           {
               type2 = "fighter";
           }
           else if(theclass == "thief" || theclass == "assassin")
           { 
               type2 = "thief";
           }
           else { type2 = "mage"; }

           profs2 = PROFS[type2][0] * ((int)TP->query_level(theclass)/PROFS[type2][1] + 1);

           if(num > profs2) { profs2 = num; }
       }
   }

  level = TP->query_lowest_level();
  profs1 = PROFS[type][0] * (level/PROFS[type][1] + 1);
  if(profs2 && profs2 > profs1)
  {
      total = profs2;
  }
  else { total = profs1; }

  profs = TP->query_profs_map();
  skills = keys(profs);
  j = sizeof(skills);
  for(i=0;i<j;i++) {
    how+= profs[skills[i]];
  }
  if(how >= total) {
    notify_fail("You may not spend another proficency at this level.\n");
    return 0;
  }
// added to solve the problems with profs applied that can't be used *Styx* 9/24/05
  if(sizeof(distinct_array(TP->query_wielded())) != 1 ) {
    write("Please wield the weapon (and only one) as you apply profs to be sure you can use it.");
    return 1;
  }
  wielded =  ((object *)TP->query_wielded())[0];
  if(!objectp(wielded)) {
    write("There is a problem with the weapon you were wielding.");
    return 1;
  }
  if(!wielded->is_ok_wield()) {
    write("No point in applying profs to a weapon you can't train in.");
    return 1;
  }
// end additions of 9/24/05
  TP->use_prof(skill);

  if ( ((int)TP->query_profs(skill) == 2) 
    && (skill == (string)TP->query("youth weapon")) ) {
    TP->set("max "+skill,120);
  } 
  if ( (int)TP->query_profs(skill) > 2) {
    if(!TP->query("max "+skill)) {
      TP->set("max "+skill, 110); 
    } else {
      TP->set("max "+skill, (int)TP->query("max "+skill)+10); 
    }
  }

  write("You have used a proficiency on "+skill+"!!");
  return 1;

}


int specialize(string str) {
  string skill;

  if(!str) {
    return notify_fail("Specialize in what?\n");
  }

  if(TP->query("specialized")) {
    return notify_fail("You have already specialized in something.\n");
  }
  if(!TP->is_class("fighter") || sizeof(TP->query_classes()) > 1) {
    return notify_fail("Only single theclass fighters can specialize.\n");
  }

  if(sscanf(str,"in %s",skill) != 1) {
    return notify_fail("Specialize in what?\n");
  }


  if(member_array(skill,keys(TP->query_skills())) == -1) {
    return notify_fail("You need to have skill in a weapon type before specializing.\n");
  }

  TP->set("specialized",skill);

  message("info","%^BOLD%^You have selected to specialize in "+skill+".",TP);
  return 1;
}

int rescueem(string str){
   if(!str) return 0;
   force_me("say I cannot let you rescue someone while I'm trying to train "+
      "them.  I won't kill them!");
   return 1;
}

int protectem(string str){
   if(!str) return 0;
   force_me("say I cannot let you protect someone while I'm trying to train "+
      "them.  I won't kill them!");
   return 1;
}

int is_townsman() { return 0;  }
