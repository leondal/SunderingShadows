#include <std.h>
#include <security.h>
inherit OBJECT;
#include "/d/magic/obj/races.h"

#define BACKUP_DIR "/d/magic/obj/companions/"
int lvl, gender, stype;
object caster;

void create(){
   ::create();
   set_name("scompanion");
   set_id(({"scompanion"}));
   set_short("");
   set_long("");
   set_weight(0);
   set_property("no animate", 1);
   set_property("no steal", 1);
}

void save_me(string file){return 1;}

void init(){
   ::init();

   if(!objectp(ETO)) 
   { 
       TO->remove();
       return;
   }
   if(!userp(ETO))
   {
       TO->remove();
       return;
   }
   caster = ETO;
   	if (caster->is_class("mage")) lvl = caster->query_guild_level("mage");
	else if(caster->is_class("sorcerer")) lvl = caster->query_guild_level("sorcerer");
   	else if(caster->is_class("warlock")) lvl = caster->query_guild_level("warlock");
    else lvl = caster->query_guild_level("bard");
	
   tell_object(caster,"%^ORANGE%^You draw forth a handful of charcoal and a stick of incense.  Lighting the "
"incense, you begin the chant to call forth a creature companion.%^RESET%^\n\n");
   tell_object(caster,"%^RESET%^%^GREEN%^What gender do you wish your summoned creature to be?  Choices: "
"%^YELLOW%^male%^RESET%^%^GREEN%^ or %^YELLOW%^female%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ "
"to abort the spell.%^RESET%^\n");
   input_to("step1");
}

void step1(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
   if(!str){
     tell_object(caster,"%^RESET%^%^RED%^You have not entered the gender of the creature you wish to summon. "
" Try again.\n%^GREEN%^What gender do you wish your summoned creature to be? Choices: %^YELLOW%^male "
"%^RESET%^%^GREEN%^or %^YELLOW%^female%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ to abort the "
"spell.%^RESET%^\n");
     input_to("step1");
     return;
   }
   if(str == "~q") {
     TO->dest_effect();
     return;
   }
   if(str != "male" && str != "female") {
     tell_object(caster,"%^RESET%^%^RED%^That isn't a valid choice. Try again.\n%^GREEN%^What gender do you "
"wish your summoned creature to be? Choices: %^YELLOW%^male%^RESET%^%^GREEN%^ or %^YELLOW%^female"
"%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ to abort the spell.%^RESET%^\n");
     input_to("step1");
     return;
   }
   if (str == "male") gender = 0;
   else gender = 1;
   call_out("step2",0);
   return;
}

void step2() {
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
   if (lvl < 15) {
     tell_object(caster,"%^RESET%^%^GREEN%^What type of creature do you wish to summon? Choices: "
"%^YELLOW%^weak%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ to abort the spell.%^RESET%^\n");
     input_to("step3");
     return;
   }
   if (lvl < 30) {
     tell_object(caster,"%^RESET%^%^GREEN%^What type of creature do you wish to summon? Choices: "
"%^YELLOW%^weak%^RESET%^%^GREEN%^ or %^YELLOW%^moderate%^RESET%^%^GREEN%^, or %^YELLOW%^~q "
"%^RESET%^%^GREEN%^to abort the spell.%^RESET%^\n");
     input_to("step3");
     return;
   }
   tell_object(caster,"%^RESET%^%^GREEN%^What type of creature do you wish to summon? Choices: "
"%^YELLOW%^weak%^RESET%^%^GREEN%^, %^YELLOW%^moderate%^RESET%^%^GREEN%^ or "
"%^YELLOW%^powerful%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ to abort the spell.%^RESET%^\n");
   input_to("step3");
   return;
}

void step3(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
   if(!str){
     tell_object(caster,"%^RESET%^%^RED%^You have not entered the type of creature you wish to summon. Try "
"again.%^RESET%^\n");
     call_out("step2",0);
     return;
   }
   if(str == "~q") {
     TO->dest_effect();
     return;
   }
   if(str != "weak" && str != "moderate" && str != "powerful") {
     tell_object(caster,"%^RESET%^%^RED%^That isn't a valid choice. Try again.%^RESET%^\n");
     call_out("step2",0);
     return;
   }
   call_out("step4",0,str);
   return;
}

void step4(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
   switch(str) {
     case "weak":
       tell_object(caster,"%^RESET%^%^GREEN%^Which of the following do you wish to summon? Choices: "
"%^YELLOW%^cat%^RESET%^%^GREEN%^, %^YELLOW%^rat%^RESET%^%^GREEN%^, %^YELLOW%^bat%^RESET%^%^GREEN%^, "
"%^YELLOW%^hawk%^RESET%^%^GREEN%^, %^YELLOW%^lizard%^RESET%^%^GREEN%^, %^YELLOW%^owl%^RESET%^%^GREEN%^, "
"%^YELLOW%^snake%^RESET%^%^GREEN%^, %^YELLOW%^toad%^RESET%^%^GREEN%^, %^YELLOW%^frog%^RESET%^%^GREEN%^, "
"%^YELLOW%^dog%^RESET%^%^GREEN%^, %^YELLOW%^weasel%^RESET%^%^GREEN%^, %^YELLOW%^spider%^RESET%^%^GREEN%^, "
"%^YELLOW%^newt%^RESET%^%^GREEN%^, %^YELLOW%^monkey%^RESET%^%^GREEN%^, %^YELLOW%^beetle%^RESET%^%^GREEN%^ "
"or %^YELLOW%^wasp%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ to abort the spell.%^RESET%^\n");
       input_to("step5a");
     break;
     case "moderate":
       if (lvl < 15) {
         tell_object(caster,"%^RESET%^%^RED%^That isn't a valid choice. Try again.%^RESET%^\n");
         call_out("step2",0);
         return;
       }
       tell_object(caster,"%^RESET%^%^GREEN%^Which of the following do you wish to summon? Choices: "
"%^YELLOW%^ape%^RESET%^%^GREEN%^, %^YELLOW%^cheetah%^RESET%^%^GREEN%^, %^YELLOW%^wolf%^RESET%^%^GREEN%^, "
"%^YELLOW%^badger%^RESET%^%^GREEN%^, %^YELLOW%^leopard%^RESET%^%^GREEN%^, %^YELLOW%^iguana%^RESET%^%^GREEN%^,"
" %^YELLOW%^viper%^RESET%^%^GREEN%^, %^YELLOW%^tarantula%^RESET%^%^GREEN%^, %^YELLOW%^hyena%^RESET%^%^GREEN%^"
", %^YELLOW%^fox%^RESET%^%^GREEN%^, %^YELLOW%^raven%^RESET%^%^GREEN%^, %^YELLOW%^scorpion%^RESET%^%^GREEN%^ "
"or %^YELLOW%^ghost%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ to abort the spell.%^RESET%^\n");
       input_to("step5b");
     break;
     case "powerful":
       if (lvl < 30) {
         tell_object(caster,"%^RESET%^%^RED%^That isn't a valid choice. Try again.%^RESET%^\n");
         call_out("step2",0);
         return;
       }
       tell_object(caster,"%^RESET%^%^GREEN%^Which of the following do you wish to summon? Choices: "
"%^YELLOW%^imp%^RESET%^%^GREEN%^, %^YELLOW%^tressym%^RESET%^%^GREEN%^, %^YELLOW%^pseudo-dragon%^RESET%^"
"%^GREEN%^, %^YELLOW%^pixie%^RESET%^%^GREEN%^, %^YELLOW%^beholderkin%^RESET%^%^GREEN%^, %^YELLOW%^eyeball"
"%^RESET%^%^GREEN%^, %^YELLOW%^basilisk%^RESET%^%^GREEN%^, %^YELLOW%^stirge%^RESET%^%^GREEN%^, %^YELLOW%^"
"hellhound%^RESET%^%^GREEN%^, %^YELLOW%^mephit%^RESET%^%^GREEN%^, %^YELLOW%^wraith%^RESET%^%^GREEN%^, "
"%^YELLOW%^ghoul%^RESET%^%^GREEN%^, %^YELLOW%^dryad%^RESET%^%^GREEN%^ or %^YELLOW%^unicorn%^RESET%^%^GREEN%^,"
" or %^YELLOW%^~q%^RESET%^%^GREEN%^ to abort the spell.%^RESET%^\n");
       input_to("step5c");
     break;
   }
   return;
}

void step5a(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
   if(!str){
     tell_object(caster,"%^RESET%^%^RED%^You have not entered the type of creature you wish to summon. Try "
"again.%^RESET%^\n");
     call_out("step4",0,"weak");
     return;
   }
   if(str == "~q") {
     TO->dest_effect();
     return;
   }
   if(str != "cat" && str != "rat" && str != "bat" && str != "hawk" && str != "lizard" && str != "owl" && str != "snake" && str != "toad" && str != "frog" && str != "dog" && str != "weasel" && str != "spider" && str != "newt" && str != "monkey" && str != "beetle" && str != "wasp") {
     tell_object(caster,"%^RESET%^%^RED%^That isn't a valid choice. Try again.%^RESET%^\n");
     call_out("step4",0,"weak");
     return;
   }
   switch(str) {
     case "cat":
       stype = 1;
     break;
     case "rat":
       stype = 2;
     break;
     case "bat":
       stype = 3;
     break;
     case "hawk":
       stype = 4;
     break;
     case "lizard":
       stype = 5;
     break;
     case "owl":
       stype = 6;
     break;
     case "snake":
       stype = 7;
     break;
     case "toad":
       stype = 8;
     break;
     case "frog":
       stype = 9;
     break;
     case "dog":
       stype = 10;
     break;
     case "weasel":
       stype = 11;
     break;
     case "spider":
       stype = 12;
     break;
     case "newt":
       stype = 13;
     break;
     case "monkey":
       stype = 14;
     break;
     case "beetle":
       stype = 15;
     break;
     case "wasp":
       stype = 16;
     break;
   }
   if (gender == 0) tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a male "+str+".");
   else tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a female "+str+".");
   tell_object(caster,"%^RESET%^%^GREEN%^Is this correct?  Select %^YELLOW%^yes%^RESET%^%^GREEN%^ to call "
"forth your creature, %^YELLOW%^no%^RESET%^%^GREEN%^ to restart the choices, or %^YELLOW%^~q "
"%^RESET%^%^GREEN%^to abort the spell.%^RESET%^\n");
   input_to("step6");
   return;
}

void step5b(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
   if(!str){
     tell_object(caster,"%^RESET%^%^RED%^You have not entered the type of creature you wish to summon. Try "
"again.%^RESET%^\n");
     call_out("step4",0,"moderate");
     return;
   }
   if(str == "~q") {
     TO->dest_effect();
     return;
   }
   if(str != "ape" && str != "cheetah" && str != "wolf" && str != "badger" && str != "leopard" && str != "iguana" && str != "viper" && str != "tarantula" && str != "hyena" && str != "fox" && str != "raven" && str != "scorpion" && str != "ghost") {
     tell_object(caster,"%^RESET%^%^RED%^That isn't a valid choice. Try again.%^RESET%^\n");
     call_out("step4",0,"moderate");
     return;
   }
   switch(str) {
     case "ape":
       stype = 17;
     break;
     case "cheetah":
       stype = 18;
     break;
     case "wolf":
       stype = 19;
     break;
     case "badger":
       stype = 20;
     break;
     case "leopard":
       stype = 21;
     break;
     case "iguana":
       stype = 22;
     break;
     case "viper":
       stype = 23;
     break;
     case "tarantula":
       stype = 24;
     break;
     case "hyena":
       stype = 25;
     break;
     case "fox":
       stype = 26;
     break;
     case "raven":
       stype = 27;
     break;
     case "scorpion":
       stype = 28;
     break;
     case "ghost":
       stype = 29;
     break;
   }
   if (gender == 0) tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a male "+str+".");
   else tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a female "+str+".");
   tell_object(caster,"%^RESET%^%^GREEN%^Is this correct?  Select %^YELLOW%^yes%^RESET%^%^GREEN%^ to call "
"forth your creature, %^YELLOW%^no%^RESET%^%^GREEN%^ to restart the choices, or %^YELLOW%^~q "
"%^RESET%^%^GREEN%^to abort the spell.%^RESET%^\n");
   input_to("step6");
   return;
}

void step5c(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
   if(!str){
     tell_object(caster,"%^RESET%^%^RED%^You have not entered the type of creature you wish to summon. Try "
"again.%^RESET%^\n");
     call_out("step4",0,"powerful");
     return;
   }
   if(str == "~q") {
     TO->dest_effect();
     return;
   }
   if(str != "imp" && str != "tressym" && str != "pseudo-dragon" && str != "pixie" && str != "beholderkin" && str != "eyeball" && str != "basilisk" && str != "stirge" && str != "hellhound" && str != "mephit" && str != "wraith" && str != "ghoul" && str != "dryad" && str != "unicorn") {
     tell_object(caster,"%^RESET%^%^RED%^That isn't a valid choice. Try again.%^RESET%^\n");
     call_out("step4",0,"powerful");
     return;
   }
   switch(str) {
     case "imp":
       stype = 30;
     break;
     case "tressym":
       stype = 31;
     break;
     case "pseudo-dragon":
       stype = 32;
     break;
     case "pixie":
       stype = 33;
     break;
     case "beholderkin":
       stype = 34;
     break;
     case "eyeball":
       stype = 35;
     break;
     case "basilisk":
       stype = 36;
     break;
     case "stirge":
       stype = 37;
     break;
     case "hellhound":
       stype = 38;
     break;
     case "mephit":
       stype = 39;
     break;
     case "wraith":
       stype = 40;
     break;
     case "ghoul":
       stype = 41;
     break;
     case "dryad":
       stype = 42;
     break;
     case "unicorn":
       stype = 43;
     break;
   }
   if (gender == 0) tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a male "+str+".");
   else tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a female "+str+".");
   tell_object(caster,"%^RESET%^%^GREEN%^Is this correct?  Select %^YELLOW%^yes%^RESET%^%^GREEN%^ to call "
"forth your creature, %^YELLOW%^no%^RESET%^%^GREEN%^ to restart the choices, or %^YELLOW%^~q "
"%^RESET%^%^GREEN%^to abort the spell.%^RESET%^\n");
   input_to("step6");
   return;
}

void step6(string str) {
   object ob, ob2;
   if(!objectp(TO)) return 0;
   if(!objectp(caster)) return 0;
	if(!objectp(environment(caster))) return 0;

   if(!str){
     tell_object(caster,"%^RESET%^%^RED%^That isn't a valid response. Try again.%^RESET%^");
     if (gender == 0) tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a male "+str+".");
     else tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a female "+str+".");
     tell_object(caster,"%^RESET%^%^GREEN%^Is this correct?  Select %^YELLOW%^yes%^RESET%^%^GREEN%^ to call "
"forth your creature, %^YELLOW%^no%^RESET%^%^GREEN%^ to restart the choices, or %^YELLOW%^~q "
"%^RESET%^%^GREEN%^to abort the spell.%^RESET%^\n");
     input_to("step6");
     return;
   }
   if(str == "~q") {
     TO->dest_effect();
     return;
   }
   if(str == "no"){
     tell_object(caster,"%^RESET%^%^RED%^Restarting.%^RESET%^");
     tell_object(caster,"%^RESET%^%^GREEN%^What gender do you wish your summoned creature to be? Choices: "
"%^YELLOW%^male%^RESET%^%^GREEN%^ or %^YELLOW%^female%^RESET%^%^GREEN%^, or %^YELLOW%^~q%^RESET%^%^GREEN%^ "
"to abort the spell.%^RESET%^\n");
     input_to("step1");
     return;
   }
   if(str != "yes") {
     tell_object(caster,"%^RESET%^%^RED%^That isn't a valid response. Try again.%^RESET%^");
     if (gender == 0) tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a male "+str+".");
     else tell_object(caster,"%^RESET%^%^RED%^You are trying to summon: a female "+str+".");
     tell_object(caster,"%^RESET%^%^GREEN%^Is this correct?  Select %^YELLOW%^yes%^RESET%^%^GREEN%^ to call "
"forth your creature, %^YELLOW%^no%^RESET%^%^GREEN%^ to restart the choices, or %^YELLOW%^~q "
"%^RESET%^%^GREEN%^ to abort the spell.%^RESET%^\n");
     input_to("step6");
     return;
   }

// set caster flags
   caster->set_property("scompanion",1);
   ob = new("/d/magic/obj/scompanioncaller.c");
   ob->move(caster);
   ob->add_flag();
   caster->add_pet(ob);

// summon the creature here
   ob2 = new("/d/magic/obj/companion.c");
   ob->set_kritter(ob2);
   if (gender == 0) {
     ob2->set_gender("male");
     ob2->set_long("This is a male "+RACES[stype]+".  It looks like a normal creature, except for an "
"occasional shimmering around it, like a strange hint of a magical aura.");
   }
   else {
     ob2->set_gender("female");
     ob2->set_long("This is a female "+RACES[stype]+".  It looks like a normal creature, except for an "
"occasional shimmering around it, like a strange hint of a magical aura.");
   }
   // creature attributes
   ob2->set_race(RACES[stype]);
   ob2->set_name(RACES[stype]);
   ob2->set_short("A "+RACES[stype]+"");
   ob2->set_id(({""+RACES[stype]+"","companion"}));
   ob2->set_max_hp(lvl*4);
   ob2->set_hp(ob2->query_max_hp());
   ob2->set_alignment(caster->query_alignment());
   ob2->set_owner(caster);
/*   ob2->set_class("fighter");
   ob2->set_level("fighter",lvl); */
   // set body type as per creature?

   tell_object(caster,"%^RESET%^%^ORANGE%^You make a careful gesture to the air before you, and it shimmers "
"and parts to allow your companion to pass through, closing in its wake!%^RESET%^");
   tell_room(environment(caster),"%^RESET%^%^ORANGE%^"+caster->QCN+" makes a gesture to the air before "
+caster->QO+", and it shimmers and parts to allow a creature to pass through, closing in its "
"wake!%^RESET%^",caster);

   ob2->move(environment(caster));
   ob2->do_backup();
   TO->move("/d/shadowgate/void");
   TO->remove();
   return;
}

void dest_effect() {
	if(objectp(caster)) 
	{
   		tell_object(caster,"%^RESET%^%^ORANGE%^You stop chanting and douse the incense, letting the spell fizzle "
		"and die.%^RESET%^");
	}
	if(objectp(environment(caster))) 
	{
   		tell_room(environment(caster),"%^RESET%^%^ORANGE%^"+
		caster->QCN+" suddenly just leans back, and douses "
		"the incense to stop the ritual.%^RESET%^",caster);
	}
   TO->move("/d/shadowgate/void");
   TO->remove();
}
