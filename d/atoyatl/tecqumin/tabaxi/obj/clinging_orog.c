//Coded by Lujke

#include <std.h>

inherit OBJECT; 

object orog;
string limb, orig_desc;
int ac_bonus;

create() {
  ::create();
  ac_bonus = -2;
  set_name("clinging orog");    
                        
  set_id(({"clinging orog"}));   

  set_short( (:TO, "short_desc":));   
  set_long( (:TO, "long_desc" :) );
  set_weight(0);          
  set_value(0);        
}

void init(){
  ::init();
  add_action("shake_em", "shake");
  if (!objectp(ETO)){
    move("/d/shadowgate/void");
  }
  if (!objectp(EETO)){
    ETO->add_ac_bonus(ac_bonus);
    ac_bonus = 0;
    move("/d/shadowgate/void");
  }
}

int query_ac_bonus(){
  return ac_bonus;
}

string long_desc(){
  return "A heroically muscular orog, clinging determinedly to your "+ limb + " and slowing you down."
          +"\nYou can try to %^BOLD%^%^YELLOW%^<shake> %^RESET%^%^GREEN%^it off, if you wish";
}

string short_desc(){
  return "%^RESET%^%^GREEN%^an orog clinging to your " + limb;
}

int drop(){
  if (objectp(ETO)){
    tell_object(ETO, "You can't just drop that. You'll have to try to %^BOLD%^%^YELLOW%^<shake>"
                    +" %^RESET%^it off");
  }
  return 1;
}

void stab(object ob){
  string stab_limb;
  stab_limb = ob->return_target_limb();
  tell_object(ob, "%^BOLD%^%^RED%^The orog stabs you viciously in the " + stab_limb);
  if (objectp(EETO)){
    tell_room(EETO, "%^BOLD%^%^RED%^The orog clinging to " + ob->QCN + "'s " + limb 
                  + " stabs " + ob->QO + " in the " + stab_limb, ob); 
  }
  ob->do_damage(stab_limb,20 + random(20));
  ob->continue_attack();
}

int shake_em(string str){
  int b, st, de, flag;
  if (!objectp(ETO)){
    return 1;
  }
  if (!interact("off", str) || !interact("orog", str)){
    tell_object(ETO, "%^BOLD%^%^YELLOW%^Do you want to 'shake off orog'?");
    return 1;
  }
  st = TP->query_stats("strength");
  de = TP->query_stats("dexterity");
  flag = 0;
  if (random(st) > 14){
    tell_object(ETO, "You manage to shake off the orog clinging to your " + limb);
    tell_room(EETO, ETOQCN + " shakes off the orog clinging to " + ETO->QP + " " + limb, ETO);
    flag = 1;
  } else {
    if (random(de) > 14){
      tell_object(ETO, "%^MAGENTA%^You manage to wriggle free from the orog clinging to your " + limb);
      tell_room(EETO, "%^MAGENTA%^" + ETOQCN + " manages to wriggle free of the orog clinging to " + ETO->QP + " " + limb, ETO);
      flag = 1;
    }
  }
  if (flag == 0){
    tell_object(TP, "%^MAGENTA%^You struggle a bit, but the orog clings on for dear life");
    stab(TP);
    return 1;
  }
  return shake_off();
}

int shake_off(){
  ac_bonus = 2;
  report("%^BOLD%^%^GREEN%^Clinging orog -shaking off. Adding AC bonus: " + ac_bonus);
  if (objectp(ETO))
  {
    ETO->add_ac_bonus(ac_bonus);
  }
  if (objectp(orog)){
    orog->set_clinging(0);
    orog->set_short(orig_desc);
    orig_desc = "";
  }
  TO->move("/d/shadowgate/void");
  return 1;
}

void report(string str){
  "/daemon/reporter_d.c"->report("lujke", str);
}


void cling(object ob){
  string * limbs;
  int bonus;
  report("clinging orog - starting to cling");
  limbs = ob->query_limbs();
  limb = limbs[random(sizeof(limbs))];
  TO->move(ob);
  tell_object(ob, "%^BOLD%^%^YELLOW%^An orog launches itself at you and clings on to your " + limb);
  set_short("%^RESET%^%^GREEN%^an orog clinging to your " + limb);   
  set_long("%^GREEN%^A heroically muscular orog, clinging determinedly to your " + limb 
          + " and slowing you down. You can try to %^BOLD%^%^YELLOW%^<shake>%^RESET%^"
          +" %^GREEN%^it off, if you wish");
  report ("Clinging orog - %^BOLD%^%^YELLOW%^starting to cling. AC adjustment: " + ac_bonus);
  ob->add_ac_bonus(ac_bonus);
  set_heart_beat(1); 
  if (objectp(orog)){
    orog->set_clinging(1);
    orig_desc = orog->query_short();
    orog->set_short("orog clinging to " + ob->QCN + "'s " + limb);
  }
  ac_bonus = 2;
}

void set_orog(object ob){
  orog = ob;
}

object query_orog(){
  return orog;
}

void heart_beat(){
  int bonus;
  if (!objectp(ETO)||!living(ETO)||!objectp(EETO)){
    TO->move("/d/shadowgate/void");
    return;
  }
  if (!objectp(orog) || !present(orog, EETO)){
    tell_object(ETO, "The orog has let go of your leg");
    bonus =2;
    ETO->add_ac_bonus(bonus);
    if (objectp(orog)){
      orog->set_clinging(0);
      orog->set_short(orig_desc);
      orig_desc = "";
    }
    TO->move("/d/shadowgate/void");
  }
}
