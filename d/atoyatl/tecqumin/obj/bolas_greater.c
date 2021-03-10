#include <std.h>
#include "../tecqumin.h"
inherit THROWING_WEAPON;

void store_me();

int last_moved, attack_score;
object tangled;

create() {
   ::create();
   attack_score = 0;
   set_name("bolas");
   set_id(({ "bolas","weapon", "thong", "thong", "thongs", "weight", "weights"
             }));
   set_obvious_short("three weights connected by leather thongs");
   set_short("%^CYAN%^manhunter's bolas%^RESET%^");
   set_long( (: TO, "long_desc" :) );
   set_weight(5);
   set_size(1);
   set("value", 500);
   set_wc(1,1);
   set_large_wc(1,1);
   set_type("bludgeoning");
   set_weapon_speed(3);
   set_lore("Rumours speak of tabaxi hunters who used the bolas to trap men as well as beasts. The greatest of these were thought to hold enchantments designed to combat magical means of escape");
   set_thrown_hit_func((:TO, "hit_func":));
   set_wield((:TO, "wield_func":));
}

void init(){
  ::init();
  add_action("untangle", "untangle");
  add_action("drop_me", "drop");
  add_action("drop_me", "give");
  add_action("drop_me", "throw");
  add_action("drop_me", "offer");
  add_action("drop_me", "sell");
  add_action("drop_me", "hide");
  add_action("drop_me", "plant");
  add_action("drop_me", "donate");
  add_action("drop_me", "disenchant");
  add_action("drop_me", "put");
  add_action("drop_me", "repair");

}

int untangle(string str){
  if (!id(str)){
    return notify_fail("That's not something you can untangle");
  }
  if (!objectp(tangled)|| tangled!= ETO || !interactive(ETO)){
    return notify_fail("That's not tangled at the moment");
  }
  if (TP!=ETO ){
    tell_object(TP, "You start untangling the bolas that is wrapped around " + ETO->QCN + "%^RESET%^'s legs");
    tell_object(ETO, TPQCN + " starts untangling the bolas that is wrapped around your legs");
    if (objectp(EETO)){
      tell_room(EETO,  TPQCN + " starts untangling the bolas that is wrapped around " + ETO->QCN + "%^RESET%^'s legs",
TP, ETO);
    }
    return 1;
  }
  tell_object(TP, "You start untangling the bolas that is wrapped around your legs");
  if (objectp(EETO)){
    tell_room(EETO,  TPQCN + " starts untangling the bolas that is wrapped around " + TP->QP + " legs", TP);
  }
  call_out("untangle2", 3 + random(5), TP); 
  return 1;
}

void untangle2(object untangler){
  if (!objectp(untangler)){
    return;
  }
  if (!objectp(tangled)|| tangled!= ETO || !interactive(ETO)){
    tell_object(untangler, "Someone must have untangled the bolas already");
    return;
  }
  if (untangler!=ETO ){
    tell_object(untangler, "You finish untangling the bolas from " + ETO->QCN + "%^RESET%^'s legs");
    tell_object(ETO, untangler->QCN + " finishes untangling the bolas from your legs");
    if (objectp(EETO)){
      tell_room(EETO,  untangler->QCN + " finishes untangling the bolas from " + ETO->QCN + "%^RESET%^'s legs",
untangler, ETO);
    }
    tangled = 0;
    move(untangler);
    if (untangler->query_internal_encumbrance()> untangler->query_max_internal_encumbrance()){
      tell_object(untangler, "%^BLUE%^The bolas is too heavy for you to carry, so you drop it.");
      tell_room("%^BLUE%^" + untangler->QCN + "%^RESET%^%^BLUE%^ drops the bolas on the ground", untangler);
      move(EETO);
    }
    ETO->set_tripped(0);
    return;
  }
  tell_object(TP, "You finish untangling the bolas from your legs");
  if (objectp(EETO)){
    tell_room(EETO,  untangler + " finishes untangling the bolas from " + untangler->QP + " legs", untangler);
  }
  tangled = 0;
  untangler->set_tripped(0);
  untangler->remove_property("teleport proof");
  if (untangler->query_internal_encumbrance()> untangler->query_max_internal_encumbrance()){
    tell_object(untangler, "%^BLUE%^The bolas is too heavy for you to carry, so you drop it.");
    tell_room("%^BLUE%^" + untangler->QCN + "%^RESET%^%^BLUE%^ drops the bolas on the ground", untangler);
    move(EETO);
  }
}

void fall_off(){
  if (!objectp(tangled) || ETO!= tangled){
     return;
  }
  if (objectp(EETO)){
    tell_object(tangled, "The bolas finally unwinds and falls off your legs");
    tangled->remove_property("teleport proof");
    tell_object(tangled, "%^CYAN%^The feathery blue net of energy falls away at the same time");
    tell_room(EETO, "The bolas unwinds and falls from " + ETO->QCN + "'s legs", ETO);
    tell_object(EETO, "%^CYAN%^The feathery blue net of energy falls away at the same time", ETO);
    move (EETO);
  } else {
    tell_object(ETO, "The bolas finally untangles itself, but there is a problem with the room you are in, so you hold on to
it.");
  }
  tangled = 0;
}

dest_effect(){
  remove();
}

int wield_func(){
  attack_score = (random(50)+1)*(int)ETO->query_level()
                             +(int)ETO->query_stats("dexterity");
  return 1;
}

string long_desc(){
  string desc;
  desc = "Two heavy %^BOLD%^%^BLACK%^obs%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^dian%^RESET%^ weights are connected by a thong,"
           +" apparently made of some kind of %^GREEN%^d%^ORANGE%^i%^GREEN%^nos%^RESET%^a%^GREEN%^ur hide%^RESET%^. A second"
           +" thong is attached to the centre of the first, and one more"
           +" %^BOLD%^%^BLACK%^obsidian%^RESET%^ weight is attached to the end of it. The weights all glow with a %^CYAN%^we%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^rd bl%^BOLD%^u%^RESET%^%^CYAN%^e inner l%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^ght";
  if(tangled == ETO){
    if (TP == ETO){
      desc += "\n%^BOLD%^%^CYAN%^It is %^YELLOW%^tangled %^CYAN%^around"
        +" your legs\n%^RESET%^You could %^BOLD%^%^YELLOW%^untangle"
        +" %^RESET%^it if you have time";
    } else {
      desc += "%^BOLD%^%^CYAN%^It is %^YELLOW%^tangled %^CYAN%^around "
        + tangled->QCN + "%^BOLD%^%^CYAN%^'s legs";
    }
  }
  return desc;
}

int drop_me(string str){
  string id1, id2, id3, id4, id5, id6;
  int i, num, flag;
  sscanf (str, "%s %s %s %s %s %s", id1, id2, id3, id4, id5, id6);
  if (!id(str)&&!id(id1)&&!id(id2)&&!id(id3)&&!id(id4)&&!id(id5)&&!id(id6)){
    return 0;
  }
  if (!objectp(ETO) ||!objectp(tangled) || tangled != ETO){
    return 0;
  }

  if (tangled == TP){ 
    tell_object(TP, "You can't do that with the bolas wrapped round your legs; you would have to untangle it first.");
    return 1;
  }
  return 0;
}


int hit_func(object targ){
  object room, throw_room;
  if (!objectp(targ)){
    return 0;
  }
  if (!objectp(TP)){
    return 0;
  }
  room = environment(targ);
  if (!objectp(room)){
    return 0;
  }
  throw_room = environment(TP);
  if (!objectp(throw_room)){
    return 0;
  }
  attack_score = (int)ETO->query_level();
  if (!targ->reflex_save(attack_score)){
    tell_object(targ, "%^BOLD%^%^YELLOW%^The thongs of the %^BOLD%^%^BLACK%^bolas %^YELLOW%^wrap around
your legs, making you stumble!");
    tell_object(targ, "%^CYAN%^Tendrils of feathery energy shoot out from the bolas, wrapping round you like a net");
    tell_room(room, targ->QCN + "%^RESET%^ stumbles, as the " + query_short() 
                   +"%^RESET%^wraps itself around " + targ->QP +" legs."
                   , targ);
    tell_room(room, "%^CYAN%^Tendrils of feathery energy shoot out from the bolas, wrapping round " + targ->QCN + "%^RESET%^%^CYAN%^ like a net", targ);
    if (!present(TP, room)){
       tell_room(throw_room, targ->QCN + "%^RESET%^ stumbles, as the " + query_short() 
                 +"%^RESET%^wraps itself around " + targ->QP +" legs.");
       tell_room(throw_room, "%^CYAN%^Tendrils of feathery energy shoot out from the bolas, wrapping round " + targ->QCN + "%^RESET%^%^CYAN%^ like a net", targ);
    }
    move(targ);
    targ->set_property("teleport proof", 45);
    tangled = targ;
  }
  last_moved = time()-10;
  call_out("fall_off", 30 + random(30));
}

int pre_exit_fun(string str){
  if (!objectp(tangled) || tangled != ETO){
    return 0;
  }
  if (time() > last_moved +2){
    last_moved = time();
    return 0;
  }
 
  if (!tangled->reflex_save(attack_score + 10)){
    tangled->set_tripped(1);
    tell_object(tangled, "You trip over the bolas wrapped around your legs");
    tell_room(EETO, ETO->QCN + " %^RESET%^trips over the bolas wrapped around "
     + ETO->QP + " legs");
    return 1;
  }    
  last_moved = time();
  return 0;
}
