// Coded by Lujke. These are the bracelets of compliance, used in
// conjunction with the circlet of control to keep another character in 
// thrall.

#define DAY 24000
#include <std.h>
#include <move.h>


inherit ARMOUR;

int death, last_message;
string master;
string query_master();
void set_master(string str);
int query_death();
void set_death(int i);
string help();
void finish_me();

void create()
{
  ::create();
  last_message = 0;
  death = 0;
  set_obvious_short("%^RESET%^dull gray bracelets");
  set_name("gray bracelets");
  set_short("%^BOLD%^%^BLACK%^br%^RESET%^a%^BOLD%^%^BLACK%^c%^RESET%^e"
           +"%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^ts %^RESET%^of"
           +" %^CYAN%^c%^RESET%^o%^CYAN%^mpli%^RESET%^a%^CYAN%^nce");
  set_id(({"bracelet","bracelets","gray bracelet","dull bracelet",
           "dull gray bracelet","dull bracelets",
           "dull gray bracelets","gray bracelets", 
           "bracelets of compliance"}));
  set_long("A pair of bracelets of dull gray metal. They fit snugly round"
          +" the wrists, and can be worn under other clothing or"
          +" armour.");
  set_lore("");
  set_property("lore difficulty",14);
  set_weight(5);
  set_type("ring");
  set_limbs(({"left arm","right arm"}));
  set_ac(1);
   set_property("enchantment",-1);
    set_property("no remove",1);
   if(query_property("enchantment") > -1){
      remove_property("enchantment");
      set_property("enchantment",-1);
   } 
  set_wear((:TO,"wearme":));
  set_remove((:TO,"removeme":));
  switch (random(6))
  {
  case 0:
    set_size(1);
    break;
  case 1:
    set_size(3);
  default:
    set_size(2);
  }
  set("language", "wizish");
  set("read","To use these bracelets of compliance requires you to also"
            +" have the circlet of command in your control. To make a"
            +" helpless victim into your slave, you must"
            +" %^BOLD%^%^YELLOW%^'attach bracelets to <victim name>'"
            +"%^RESET%^" );
  set_heart_beat(1);
}

void init(){
  ::init();
  add_action("attach_bracelets", "attach");
}

string query_master(){
  return master;
}

void set_master(string str){
  master= str;
}

int query_death(){
  return death;
}

void set_death(int i){
  death = i;
}

void finish_me(){
  int hp;
  if (!objectp(ETO)||!objectp(TO)||!interactive(ETO)){return;}
  tell_object(ETO, "%^BOLD%^%^RED%^Pain%^RESET%^ %^RED%^ripples through your body, as the last of your strength is leeched away by"
                  +" the %^RESET%^slave bracelets");
  hp = (int)ETO->query_max_hp()/3;
  ETO->do_damage(ETO->return_target_limb(),random(hp));
  ETO->add_attacker(TO);
  ETO->continue_attack();
  if(objectp(ETO)){
    ETO->remove_attacker(TO);
  }
  if ((int)ETO->query_hp()>0){
    call_out("finish_me", random (10));
  }
  else { death = 0;}
}



int wearme(){
//  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if (objectp(ETO)){
    tell_object(ETO,"The bracelets fasten tightly round your forearms");
  }
  if (objectp(EETO)){
    tell_room(EETO,(string)ETO->QCN + " shivers slightly as the bracelets"
                +" are fastened tightly around " + (string)ETO->QP 
                + " wrists", ETO);
  }
  return 1;
}

void die(){
}

void heart_beat(){
  int deathtime, conbonus, current_loss;
  if(!objectp(ETO)||!living(ETO)){ return;}
  if (time()<death+3600){
    return;
  }
  if (death==0){
    return;
  }
  else {
    deathtime = ((time()- death)/DAY);
  }
  if (deathtime >0){
    conbonus = deathtime *-1;
    current_loss = (int)ETO->query_stats("constitution") - (int)ETO->query_base_stats("constitution");
    if (current_loss > conbonus){
      conbonus -= current_loss;
      ETO->add_stat_bonus("constitution", conbonus);
    }
  }
  if (last_message >time() - 1200) {
    return; // just one of these messages every 20 minutes
  }
  last_message = time();
  switch((int)ETO->query_stats("constitution")){
  case 2..3:
    tell_object(ETO, "%^BOLD%^%^BLUE%^You feel horribly weakened and"
                    +" close to %^BOLD%^%^BLACK%^death%^BLUE%^ as the"
                      +" %^RESET%^bracelets%^BOLD%^%^BLUE%^ continue to"
                      +" sap your strength"); 
    break;
  case 4..7:
    tell_object(ETO, "%^BOLD%^%^BLUE%^You feel weak, and you are aware"
                    +" that the %^RESET%^bracelets%^BOLD%^%^BLUE%^"
                    +" are sucking the %^BOLD%^%^GREEN%^life%^BLUE%^"
                    +" from you."); 
    break;
  case 8..10:
    tell_object(ETO, "%^BOLD%^%^BLUE%^You are starting to feel"
                    +" definitely %^RESET%^%^GREEN%^weakened%^BOLD%^"
                    +"%^BLUE%^ and have the distinct feeling that the"
                    +" %^RESET%^bracelets%^BOLD%^%^BLUE%^ are slowly"
                    +" killing you."); 
     break;
  case 11..15:     
    tell_object(ETO, "%^BOLD%^%^BLUE%^You are aware that the"
                    +" %^RESET%^bracelets%^BOLD%^%^BLUE%^ are "
                    +" draining your strength"); 
    break;
  case 0..1:
    tell_object(ETO, "%^BOLD%^%^BLUE%^In your weakened state, you can"
                      +" feel the end is near, as the bracelets have"
                      +" drained nearly all of your strength.\n"
                      +"%^RESET%^This might be a good time to make peace"
                      +" with your friends and with the Gods."); 
      call_out("finish_me", 5);
      set_heart_beat(-1);
    break;
  default:     
    tell_object(ETO, "%^BOLD%^%^BLUE%^You feel faintly weakened."
                    +" Perhaps it is the %^RESET%^bracelets%^BOLD%^%^BLUE%^"
                    +" affecting you."); 
    break;
  };
}

int removeme(){
  string who;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO,"" + query_short() + " ");
  tell_object (ETO, "You struggle to get the " + query_short() +" off"
                   +" your wrists.");
  tell_room(EETO, (string)ETO->query_cap_name()+" struggles out of the " 
                  + query_short() +" and slides them off " 
                  + (string)ETO->QP + " wrists.",ETO);
  set_ac(0);
  if (ETO->query("compliant")!=0){
    who = ETO->query("compliant");
    ETO->set("compliant_"+who, 0);
  }
  ETO->set("compliant", 0);
  set_death(0);
  last_message=0;
  return 1;
}

int attach_bracelets(string str){
  object targ, circlet;
  string targname, objname, slavername;
  if (!objectp(TO)||!objectp(ETO)||!interactive(ETO)){return 0;}
  if (sscanf(str, "%s to %s", objname, targname)<2){
    return 0;
  }
  // prevent players and newbies being able to attach the bracelets to 
  // another player - this ability for HMs and Imms only, due to trust
  // issues

  if(!id(objname)){return 0; }
   if ((string)ETO->query_position()== "newbie"){
    tell_object (ETO,"You do not have the power to attach the bracelets");
    return 1;
  }
  circlet = present("circlet of control", ETO);
  if (!circlet||!circlet->query_worn()){
    tell_object(ETO, "You must be wearing the circlet of control to"
                    +" claim a slave!");
    return 1;
  }
  slavername = (string)circlet->query_worn()->query_name();
  if ((string)circlet->query_owner()!=slavername){
    tell_object(ETO, "Only the true owner of the circlet can claim a new"
                    +" slave!");
    return 1;
  }
  targ = present(targname, EETO);
  if (!objectp(targ)){
    tell_object(ETO, targname + " is not here.");
    return 1;
  }
  if (!targ->query_unconscious()&&!targ->query_bound()){
    tell_object(ETO, targ->QCN+" isn't likely to just let you do that.");
    return 1;
  }

//  TP->force_me("give " + objname + " to " + targname);
  tell_object(ETO, "Moving swiftly, you secure the bracelets on "
                 + targ->QCN +"'s wrists.");
  if (!targ->query_unconscious()){
    tell_object(targ, (string)ETO->QCN + " secures a pair of dull gray"
                      +" bracelets on your wrists.");
  }
  tell_room(EETO,(string)ETO->QCN + " secures a pair of dull gray"
                     +" bracelets onto " + targ->QCN + "'s wrists."
                     , targ, ETO); // not sure why the binder still sees 
                                  //this message. Lujke.
  set_master(slavername);
  move(targ);
  set_worn(targ);
  set_death(0);
  ETO->set("compliant",slavername);
  ETO->set("compliant_" + slavername, 100);
  return 1;
}

string help(){
  return "Try 'attach bracelets to <target name>'";
}
