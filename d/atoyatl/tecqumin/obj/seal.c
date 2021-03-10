
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit OBJECT;

void create(){
  ::create();
  set_long("This octagonal stone %^ORANGE%^seal%^RESET%^ is about"
    +" the size of a human hand, and is carved with eight symbols."
    +" Each symbol aligns with one of the edges of the octagon, and"
    +" their inner edges meet to form a smaller octagon in the centre"
    +" of the seal. A ninth symbol sits in this nexus, seemingly"
    +" absorbing and redirecting the power of the other eight.");
  set_obvious_short("octagonal stone seal");
  set_short("%^CYAN%^Tecqumin %^RESET%^seal of %^ORANGE%^capture");
  set_weight(5);
  set_id(({"seal","stone seal", "octagonal seal","octagonal stone seal"})); 
  set_lore("One of the great secrets of the %^CYAN%^Tecqumin%^RESET%^ court"
    +" was the method of production of %^ORANGE%^magic seals%^RESET%^ that"
    +" could aid in the capture of enemies. Once activated, the seal would"
    +" allow no escape from a hunter until its magic faded or was defeated."
    +" The %^CYAN%^Tecqumin%^RESET%^ would use them to capture dangerous"
    +" enemies or those of great value, ready to go to the%^BOLD%^%^BLUE%^"
    +" flowery death. To use a seal like this, it is necessary to decipher"
    +" the symbols upon it.");
  set("lore difficulty", 40);
  set_read("There is no writing on the seal, as such, but you might be able to decipher something from the symbols?");
}

void init(){
  ::init();
  add_action("set_seal", "set");
  add_action("decipher", "decipher");
}

int set_seal(string str){
  string * quests;
  object seal_mob;
  if(!id(str)){
    return notify_fail("Do you want to <set seal> ?");
  }
  if (!objectp(ETO)){ 
    return notify_fail("ERROR - seal is in an invalid environment. "
       + "Please make a bug report");
  }
  if(!living(ETO)){
    return notify_fail("You have to be holding the seal to use it");
  }
  if(!EETO->is_room()){
    return notify_fail("ERROR - room you are in is invalid. "
       + "Please make a bug report");
  }
  
//insert code to make it dependent on a quest / event
  quests = TP->query_quests();
  if (sizeof(quests)<1 || (member_array ("Fettered the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt"
    +"%^MAGENTA%^e%^BLUE%^red", quests) == -1 && member_array("%^RED%^Defeated %^RESET%^%^BLUE%^The"
     +"%^MAGENTA%^ U%^BLUE%^n%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt"
     +"%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d", quests) == -1) ){
   
    tell_object(TP, "The seal will not work for you - you have not earned the gratitude of the spirits of the %^CYAN%^Tecqumin%^RESET%^ ancestors.");
    return 1;
  }
  
  tell_object(ETO, "With a dramatic gesture, you slam the seal"
  +" down on the floor!");
  tell_room(EETO, "With a dramatic gesture, "
   + ETO->QCN  
   +" slams a strange octagonal"
   +" stone seal down on the floor!", ETO);
  seal_mob = new(MOB + "seal_mob");
  seal_mob->move(EETO);
  seal_mob->activate();
  TO->move("/d/shadowgate/void");
  TO->remove();
  return 1;
}

int decipher(string str){
  int roll;
  string result;
  if (!stringp(str)|| ( !id(str) && !interact("symbol", str) ) ){ 
    return notify_fail("what do you want to decipher?");
  }
  roll = TP->query_skill("academics");
   if (roll <16){
    tell_object(TP, "You don't have the sort of learning you would need to interpret these symbols");
    return 1;
  }
  roll += random(roll);
  if (roll<30){
    tell_object(TP, "You don't manage to make sense of the symbols, though you think you may be on the right track.");
    return 1;
  }
  tell_object(TP, "You aren't able to decipher the symbols completely, but you have the impression that you could <set> the seal down with some interesting results");
  return 1;
}
