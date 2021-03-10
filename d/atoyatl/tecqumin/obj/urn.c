//Coded by Lujke


#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"
inherit OBJECT;

int full, greeted;

void create() {
    full = 1;
    ::create();
    set_name("large stoneware urn");
    set_id( ({"urn","stoneware urn", "large urn" }) );
    set_short("large stoneware urn");
    set_weight(20);
    set_long( (:TO, "long_desc" :) );
    greeted = 0;
}

void fill_me(){
  if (objectp(ETO) && interactive(ETO))
  {
    tell_object(ETO, "The %^CYAN%^urn%^RESET%^ %^BOLD%^%^BLACK%^v%^WHITE%^i%^BOLD%^%^BLACK%^br%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s and %^RED%^warms%^RESET%^ slightly for a moment");
  }
  full = 1;
}

void check_full(){
  if (full <1)
  {
    if (find_object(MOB + "guamansuri") == 0) fill_me();
  }
}

void init(){
  ::init();
  add_action( "pour_me", "empty");
  add_action("pour_me", "pour");
  add_action("pour_me", "tip"); 
}

void set_full(int f){
  full = f;
}

int query_greeted(){
  return greeted;
}

void set_greeted(int greet){
  greeted = greet;
}

/*
int examine_me(string str){
  str = lower_case(str);
  if (str != "urn" && str!= "large urn" && str != "stoneware urn"
       && str != "large stoneware urn" && str != "the urn" 
       && str != "the large urn" && str != "the large stoneware urn"
       && str != "the stoneware urn"){
    return notify_fail("Do you want to examine the urn?");
  }
  switch (full){
  case 0:
    tell_object(TP, "The urn is empty now, but it looks like it"
      +" would have held something quite special once.");
    
    break;
  case 1:
    tell_object(TP, "The s%^BOLD%^%^WHITE%^p%^RESET%^ar%^BOLD%^"
      +"%^WHITE%^k%^RESET%^ly %^BOLD%^%^WHITE%^d%^RESET%^u%^BOLD%^"
      +"%^WHITE%^st%^RESET%^ in the bottom of the urn looks"
      +" interesting. Perhaps you could pour it out.");
    break;
  }
  if (objectp(ETO)){
    if (living(ETO)){
      if (objectp(EETO)){
        tell_room(ETO, TPQCN + " examines the urn closely", TP);
        return 1;
      }
    } else {
      tell_room(ETO, TPQCN + " examines the urn closely", TP);
      return 1;
    }
  }
}
*/

int pour_me(string str){
  object env;
  str = lower_case(str);  
  if (str != "urn" && str != "dust" && str != "dust from urn" 
      && str != "large urn" && str != "out urn" && str != "the urn" 
      && str != "the large urn" && str != "dust from the large urn" 
      && str != "out the large urn" && str != "out the urn"){
    return notify_fail("do you want to empty out the urn?");
  }
  check_full();
  if (objectp(ETO)){
    if (living(ETO)){
      if (objectp(EETO)){
        env = EETO;
      }
    } else {
      env = ETO;
    }
  }
  if (!objectp(env)){
    tell_object(TP, "There is a problem with the urn's environment."
     +" Please make a bug report");
    return 1;
  }
  if (full ==0)
  {
    tell_object(TP, "You tip the urn upside down, but there is nothing remaining inside to pour out");
    tell_room(ETP, TPQCN + " tips the urn " + TP->QS + " is carrying upside down, but nothing comes out", TP);
    return 1;
  }
  tell_object(TP, "You strain a bit, but manage to upend the urn"
    +" enough to pour a thin stream of %^BOLD%^%^WHITE%^s%^RESET%^i"
    +"%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^ry d%^RESET%^us"
    +"%^BOLD%^%^WHITE%^t%^RESET%^ from its lip. As the %^BOLD%^"
    +"%^WHITE%^d%^RESET%^u%^BOLD%^%^WHITE%^st%^RESET%^ falls, you"
    +" notice that it gl%^BOLD%^%^WHITE%^i%^RESET%^tt%^BOLD%^"
    +"%^WHITE%^e%^RESET%^rs and sp%^BOLD%^%^WHITE%^a%^RESET%^rkl"
    +"%^BOLD%^%^WHITE%^e%^RESET%^s as if it contained its own source"
    +" of l%^BOLD%^%^YELLOW%^i%^RESET%^%^ORANGE%^g%^RESET%^ht.");
  tell_room(env, TPQCN + "strains a bit, but manages to tip the urn"
    +" enough to pour a thin stream of %^BOLD%^%^WHITE%^s%^RESET%^i"
    +"%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^ry d%^RESET%^us"
    +"%^BOLD%^%^WHITE%^t%^RESET%^ from its lip. As the %^BOLD%^"
    +"%^WHITE%^d%^RESET%^u%^BOLD%^%^WHITE%^st%^RESET%^ falls, you"
    +" notice that it gl%^BOLD%^%^WHITE%^i%^RESET%^tt%^BOLD%^"
    +"%^WHITE%^e%^RESET%^rs and sp%^BOLD%^%^WHITE%^a%^RESET%^rkl"
    +"%^BOLD%^%^WHITE%^e%^RESET%^s as if it contained its own source"
    +" of l%^BOLD%^%^YELLOW%^i%^RESET%^%^ORANGE%^g%^RESET%^ht.", TP);
  call_out("pour2",3, TP);
  return 1;
}

void pour2(object ob){
  object env;
  if (objectp(ETO)){
    if (living(ETO)){
      if (objectp(EETO)){
        env = EETO;
      }
    } else {
      env = ETO;
    }
  }
  if (!objectp(env) && objectp(ob)){
    tell_object(ob, "There is a problem with the urn's environment."
     +" Please make a bug report");
    return;
  }
  tell_room(env, "The falling %^BOLD%^%^WHITE%^d%^RESET%^u%^BOLD%^"
    +"%^WHITE%^st%^RESET%^ doesn't settle the way it should, but"
    +" seems to rise slightly, initially in the form of a swirling"
    +" cone building from the bottom, then slowly shaping into the"
    +" increasingly distinct form of a %^CYAN%^gh%^RESET%^o%^CYAN%^"
    +"stly%^RESET%^ f%^CYAN%^i%^RESET%^g%^BOLD%^%^WHITE%^u%^RESET%^"
    +"re.");
  call_out("pour3", 3, ob);
}

void pour3(object ob){
  object spirit, env, * critters;
  int i, count, t;
  if (objectp(ETO)){
    if (living(ETO)){
      if (objectp(EETO)){
        env = EETO;
      }
    } else {
      env = ETO;
    }
  }
  if (!objectp(env) && objectp(ob)){
    tell_object(ob, "There is a problem with the urn's environment."
     +" Please make a bug report");
    return;
  }
  t = time();
  critters = all_living(env);
  count = sizeof(critters);
  for (i=0; i<count; i++){
    if (!interactive(critters[i])){
      continue;
    }
    EVENT_RECORDS_D->record_event(critters[i]->query_name(), "Discovered Guamansuri", t);
  }
  tell_room(env, "The last of the d%^BOLD%^%^WHITE%^u%^RESET%^st"
    +" swirls and settles into the form of a %^CYAN%^gh%^RESET%^o"
    +"%^CYAN%^st%^BOLD%^%^WHITE%^l%^RESET%^%^CYAN%^y %^BOLD%^"
    +"%^WHITE%^sp%^RESET%^i%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^i"
    +"%^BOLD%^%^WHITE%^t%^RESET%^.");
  spirit = new(MOB + "guamansuri");
  spirit->set_pourer(ob->query_true_name());
  spirit->move(env);  
  spirit->set_greeted(greeted);
  if (!greeted && present("mehaq", env)){
    for (i=0; i<count; i++){
      if (!interactive(critters[i])){
        continue;
      }
      EVENT_RECORDS_D->record_event(critters[i]->query_name(), "Reunited Guamansuri and Mehaq", t);
    }
    spirit->meet_me();
    spirit->greet_empress();
  } else {
    spirit->pour_me(ob);
  }
  full = 0;
}
string long_desc(){
  check_full();
  switch (full){
  case 1:
    return "This large urn stands nearly four feet high and has"
    +" the classic shape of a narrow neck above a footed pedestal."
    +" It clearly has some considerable age, and its %^ORANGE%^pa"
    +"%^CYAN%^int%^RESET%^e%^ORANGE%^d decor%^RESET%^a%^CYAN%^ti"
    +"%^ORANGE%^on%^RESET%^ is badly chipped and worn. What little"
    +" remains is suggestive that this would have been a high"
    +" status item, perhaps connected with funerary rites. Looking"
    +" inside, you can make out a little dust, and some odd,"
    +" slightly random %^BOLD%^%^WHITE%^sp%^RESET%^a%^BOLD%^"
    +"%^WHITE%^r%^RESET%^kl%^BOLD%^%^WHITE%^es%^RESET%^.\nPerhaps"
    +" you could pour it out, if you think that sort of thing is a"
    +" good idea.";
    break;
  case 0:
    return "This large urn stands nearly four feet high and has"
    +" the classic shape of a narrow neck above a footed pedestal."
    +" It clearly has some considerable age, and its %^ORANGE%^pa"
    +"%^CYAN%^int%^RESET%^e%^ORANGE%^d decor%^RESET%^a%^CYAN%^ti"
    +"%^ORANGE%^on%^RESET%^ is badly chipped and worn. What little"
    +" remains is suggestive that this would have been a high"
    +" status item, perhaps connected with funerary rites. It"
    +" appears to be empty.";
    break;
  }
  full = 0;
}
