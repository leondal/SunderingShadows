#include <std.h>
#include "../vesprus.h"

inherit "/std/drink.c";

int uses;

void create(){
        ::create();
        set_name("whiskey");
        set_id(({"whisky","fine brandy","drink","flask"}));
        set_short("A flask of whiskey");
        set_long("This %^ORANGE%^dark colored drink %^RESET%^s%^ORANGE%^w%^RESET%^ir%^ORANGE%^l%^RESET%^s around in a wide but thin %^ORANGE%^dark brown bottle %^RESET%^with a %^ORANGE%^cork top.  %^RESET%^There is a simple %^ORANGE%^label %^RESET%^on the front of the bottle.");
        set_strength(35);
        set_type("alcoholic");
        set_weight(2);
        set_language("common");
        set_read("%^RESET%^%^MAGENTA%^Melorn's Whiskey%^RESET%^");
        uses = 5;
}
void init(){
   ::init();
   add_action("drink","drink");
   add_action("refill_flask","refill");
   add_action("check_flask","check");
   add_action("dump_flask","dump");
}

void drink(string str){
   if(!living(ETO)) {
      notify_fail("You must be holding the flask to drink from it.\n");
      return 0;
   }
   if(!ETO->add_intox(100)) {
   notify_fail("You decide it would not be a good idea to drink anymore right now.\n");
   return 0;
   }
   if(!interactive(ETO)) {
   notify_fail("You must be holding the flask to drink from it.\n");
   return 0;
   }
   if(str == "from flask" || str == "from whiskey bottle" || str == "whiskey" || str == "from bottle") {
	if(!uses==0){
         tell_object(ETO,"%^ORANGE%^You pull out the cork top and raise the bottle to your lips, taking a large swig of the contents.\n%^RED%^The liquid burns your throat on the way down.%^RESET%^");
         tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" pulls out the cork and raises the bottle to "+ETO->query_possessive()+" lips.\nTaking a long drink, "+ETO->query_subjective()+" coughs as the liquid goes down.%^RESET%^",ETO);
         ETO->add_intox(100);
         uses -= 1;
         return 1;
      }
	if(uses==0) {
         tell_object(ETO,"%^ORANGE%^You pull out the cork top and raise the bottle to your lips, only to be disappointed that there is no more liquid inside.");
         tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" pulls out the cork and raises the bottle to "+ETO->query_possessive()+" lips, tilting "+ETO->query_possessive()+" head way back to get every last drop.\nAfter a moment "+ETO->query_subjective()+" frowns intently and sets the empty flask back down.%^RESET%^",ETO);
         new(VESPRUSOBJS+"eflask.c")->move(ETO);
         TO->remove();
         return 1;
      }
   }
}
void refill_flask(string str){
   object ob;
   if(!living(ETO)) {
   notify_fail("You must be holding the flask to be able to refill it.\n");
   return 1;
   }
   if(!interactive(ETO)) {
   notify_fail("You must be holding the flask to be able to refill it.\n");
   return 0;
   }
   if(str != "flask" && str != "bottle") {
   tell_object(ETO,"Try refill flask.\n");
   return 1;
   }
   if(uses == 5) {
   tell_object(ETO,"The flask is already full!");
   return 1;
   }
   if(present("bartender",environment(ETO))) {
      if(!ETO->query_funds("gold",150)) {
      tell_object(ETO,"The price is 150 gold, you do not have enough money.\n");
      return 1;
      }
      else {
      tell_object(ETO,"%^RESET%^%^CYAN%^You hand your flask to the barkeep and get it refilled for a small fee.%^RESET%^");
      tell_room(environment(ETO),""+ETO->query_cap_name()+" hands "+ETO->query_possessive()+" flask over to the barkeep and anxiously awaits as it gets refilled and handed back.",ETO);
      ETO->use_funds("gold",150);
      uses = 5;
      return 1;
      }
   }
   else if(present("barkeep",environment(ETO))) {
      if(!ETO->query_funds("gold",150)) {
      tell_object(ETO,"The price is 150 gold, you do not have enough money.\n");
      return 1;
      }
      else {
      tell_object(ETO,"%^RESET%^%^CYAN%^You hand your flask to the barkeep and get it refilled for a small fee.%^RESET%^");
      tell_room(environment(ETO),""+ETO->query_cap_name()+" hands "+ETO->query_possessive()+" flask over to the barkeep and anxiously awaits as it gets refilled and handed back.",ETO);
      ETO->use_funds("gold",150);
      uses = 5;
      return 1;
      }
   }
   else{
      if(environment(ETO)->query_property("fill waterskin")) {
         if(uses==0){
            tell_object(ETO,"You bend down and refill the flask.");
            tell_room(environment(ETO),""+ETO->query_cap_name()+" bends down and dunks "+ETO->query_possessive()+" flask into the water, refilling it.",ETO);
            ob=new(VESPRUSOBJS+"whiskey.c");
            ob->move(ETO);
            ob->set_drinks(5);
            TO->remove();
            return 1;
         }
         if(!uses==0){
            tell_object(ETO,"You should probably get rid of the whiskey first.");
            return 1;
         }
      }
      else if(present("water",environment(ETO))){
         if(uses==0){
            tell_object(ETO,"You bend down and refill the flask.");
            tell_room(environment(ETO),""+ETO->query_cap_name()+" bends down and dunks "+ETO->query_possessive()+" flask into the water, refilling it.",ETO);
            ob=new(VESPRUSOBJS+"whiskey.c");
            ob->move(ETO);
            ob->set_drinks(5);
            TO->remove();
            return 1;
         }
         if(!uses==0){
            tell_object(ETO,"You should probably get rid of the whiskey first.");
            return 1;
         }
      }
      else {
      tell_object(ETO,"You must either be at a pond or find a bartender to fill this flask.\n");
      return 1;
      }
   }
}

void check_flask(string str){
   if(!living(ETO)) {
   notify_fail("You must be holding the flask to be able to check it.\n");
   return 0;
   }
   if(!interactive(ETO)) {
   notify_fail("You must be holding the flask to be able to check it.\n");
   return 0;
   }
   if(str != "flask" && str != "bottle") {
   notify_fail("Check what?\n");
   return 0;
   }
   switch(uses) {
      case 5:
	tell_object(ETO,"%^RESET%^%^ORANGE%^You shake the flask to find that it is still quite full%^RESET%^.");
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" holds the flask up and shakes it%^RESET%^.",ETO);
	break;
	case 4:
	tell_object(ETO,"%^RESET%^%^ORANGE%^You hold the flask up and shake it.  liquid sloshes around inside, but it still feels fairly full%^RESET%^.");
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" holds the flask up and shakes it, the sound of the sloshing liquid can be heard from inside it%^RESET%^.",ETO);
	break;
	case 3:
	tell_object(ETO,"%^RESET%^%^ORANGE%^You hold the flask up and shake it.  liquid sloshes around and it feels about half full.%^RESET%^");      
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" holds the flask up and shakes it, the sound of the sloshing liquid can be heard from inside it%^RESET%^.",ETO);
	break;
	case 2:
	tell_object(ETO,"%^RESET%^%^ORANGE%^You hold the flask up and shake it.  liquid sloshes around, but it's feeling pretty light.%^RESET%^");
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" holds the flask up and shakes it, the sound of the sloshing liquid can be heard from inside it, though it doesn't sound that full%^RESET%^.",ETO);
	break;
	case 1:
	tell_object(ETO,"%^RESET%^%^ORANGE%^You hold up the flask and shake it lightly.  A little bit of liquid sloshes around and it feels really light%^RESET%^.");
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" holds the flask up and shakes it, the sound of the sloshing liquid can be heard from inside it, though it doesn't sound that full%^RESET%^.",ETO);
	break;
	case 0:
	tell_object(ETO,"%^RESET%^%^ORANGE%^You hold the flask up and shake it only to find that no sound comes from within.  You pull open the cork and peer in to confirm your suspicions. ...Yep, it's empty%^RESET%^.");
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" holds the flask up and shakes it, though it makes no sound...  Pulling out the cork top and peering inside, "+ETO->query_subjective()+" frowns%^RESET%^.",ETO);
	break;
   }
	return 1;
}
void dump_flask(string str){
   object ob;
   if(!living(ETO)) {
   notify_fail("You must be holding the flask in order to dump it out.\n");
   return 1;
   }
   if(!interactive(ETO)) {
   notify_fail("You must be holding the flask in order to dump it out.\n");
   return 0;
   }
   if(str != "flask" && str != "bottle") {
   tell_object(ETO,"Try dump flask.\n");
   return 1;
   }
   if(uses == 0) {
   tell_object(ETO,"The flask is already empty!");
   return 1;
   }
   if(!uses==0){
     tell_object(ETO,"You tip the flask upside down and dump out the contents.");
     tell_room(environment(ETO),""+ETO->query_cap_name()+" tips the flask upside down and dumps out the contents.",ETO);
     uses =0;
     return 1;
   }
}


