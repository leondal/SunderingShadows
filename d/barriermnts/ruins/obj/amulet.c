#include <std.h>
#include <daemons.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

int timer,totalhp;

void create(){
   ::create();
   set_name("amulet of the true voice");
   set_id(({ "amulet","Amulet","crystalline amulet","crystal amulet","amulet of the voice" }));
   set_short("%^BLUE%^%^BOLD%^amulet of the %^CYAN%^T%^BLUE%^r%^CYAN%^u%^BLUE%^e %^CYAN%^V%^BLUE%^o%^CYAN%^i%^BLUE%^c%^CYAN%^e%^RESET%^");
   set_obvious_short("%^BLUE%^%^BOLD%^crystalline amulet%^RESET%^");
   set_long("%^YELLOW%^A single perfect, step-cut %^BLUE%^blue crystal%^YELLOW%^ forms this amulet.  It catches the %^WHITE%^light%^YELLOW%^ in its many facets, though it seems not to reflect this light, instead %^BLACK%^absorbing%^YELLOW%^ it into the depths of the gem.  An ornate %^WHITE%^platinum clasp %^YELLOW%^holds the gem upon a delicate chain of the same metal.  It looks like quite a valuable piece of jewelry.%^RESET%^\n");
   set_weight(2);
   set_value(7505);
   set_lore("%^WHITE%^%^BOLD%^This amulet once belonged to the archmage Archemond, who is referred to in history as the leader of a cult known only as 'the Faithful of the True Voice'.  He was never seen without the amulet, and rumours abound about its true nature, and the evil forces that may or may not be contained within it.%^RESET%^");
   set_property("lore difficulty",19);
   set_type("ring");
   set_limbs(({"neck"}));
   set_size(2);
   set_ac(0);
   set_property("enchantment",0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_heart_beat(1);
}

int wear_fun(){
    if (timer < time()) { timer = time() + 300 + random(300); }
    tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" wears the amulet, and shivers slightly.%^RESET%^",ETO);
    tell_object(ETO,"%^BLUE%^%^BOLD%^A shiver runs down your spine as you wear the amulet.%^RESET%^");
    return 1;
}

int remove_fun(){
    tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" relaxes visibly as "+ETO->QS+" removes the amulet.%^RESET%^",ETO);
    tell_object(ETO,"%^BLUE%^%^BOLD%^You feel as if a weight is lifted from your shoulders as you remove the amulet.%^RESET%^");
    return 1;
}

void heart_beat() {
   object *pplz;
   int i,dam,totaldam;
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!objectp(EETO)) return;
   if(TO->query_worn()) {
     if(!random(1000)) {
       switch(random(5)) {
       case 0:
       tell_object(ETO,"%^BLACK%^%^BOLD%^The amulet at your throat pulses softly, and you feel a malevolent force touch briefly upon your mind.  Then, it is gone again like it never happened.%^RESET%^");
       break;
       case 1:
       tell_object(ETO,"%^CYAN%^%^BOLD%^A voice whispers in your mind:%^RESET%^%^WHITE%^ More... give me their lives!");
       break;
       case 2:
       tell_object(ETO,"%^WHITE%^%^BOLD%^The amulet at your throat warms slightly, and you find your hand involuntarily drawn toward it.%^RESET%^");
       if (!ETO->query_invis()) {
         tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" absently brushes a hand over the amulet at "+ETO->QP+" throat.%^RESET%^",ETO);
       }
       break;
       case 3:
       tell_object(ETO,"%^BLUE%^The amulet at your throat pulses once, and you feel the world around you become distant and vague.  You have to shake your head to clear it.%^RESET%^");
       if (!ETO->query_invis()) {
         tell_room(EETO,"%^BLUE%^"+ETO->QCN+"'s eyes glaze over for a few seconds, before "+ETO->QS+" shakes "+ETO->QP+" head once and returns to normal.%^RESET%^",ETO);
       }
       break;
       case 4:
       tell_object(ETO,"%^RED%^A chill feeling runs down your spine, as the amulet brushes lightly against your throat.%^RESET%^");
       if (!ETO->query_invis()) { tell_room(EETO,"%^RED%^"+ETO->QCN+" shivers slightly.",ETO); }
       break;
       }
     }
     if (timer < time()) {
       timer = time() + 28800;
       pplz = all_living(EETO);
       totaldam = 0;
       for(i=0;i<sizeof(pplz);i++){
         if (pplz[i] != ETO && !avatarp(pplz[i])) {
           dam = roll_dice(1,6);
           tell_object(pplz[i],"%^BLACK%^%^BOLD%^You feel a momentary weakness, as if some force is pulling at your mind.%^RESET%^");
           pplz[i]->do_damage("torso",dam);
           totaldam = totaldam + dam;
         }
       }
       if (totaldam > 0) {
         tell_object(ETO,"%^BLACK%^%^BOLD%^The amulet at your throat %^RESET%^%^RED%^warms %^BLACK%^%^BOLD%^momentarily and pulses with a dark energy, leaving you feeling invigorated.");
         ETO->do_damage("torso",(-1)*dam);
         totalhp = totalhp + totaldam;
       }
     }
     if (totalhp > 300) {
       while((int)TO->query_property("enchantment") >= 0) {
         TO->remove_property("enchantment");
         TO->set_property("enchantment",-1);
       }
       totalhp = 0;
       ETO->set_property("amuletawakening",0);
       call_out("awaken",5,ETO);
     }
   }
}

void awaken(object wearer) {
   int dam,checker;
   dam = (int)wearer->query_hp() / 10;
   if(!objectp(wearer)) return;
   checker = wearer->query_property("amuletawakening");
   wearer->remove_property("amuletawakening");
   switch (checker) {
     case 0:
     tell_object(ETO,"%^BLUE%^%^BOLD%^The amulet at your throat begins to warm against your skin.");
     wearer->set_property("amuletawakening",1);
     call_out("awaken",4,wearer);
     break;
     case 1:
     tell_room(environment(wearer),"%^BLUE%^%^BOLD%^The amulet at "+wearer->QCN+"'s throat begins to glow.%^RESET%^",wearer);
     tell_object(wearer,"%^BLUE%^%^BOLD%^The amulet begins to glow, getting warmer by the second.%^RESET%^");
     wearer->set_property("amuletawakening",2);
     call_out("awaken",4,wearer);
     break;
     case 2:
     tell_room(environment(wearer),"%^BLUE%^%^BOLD%^The amulet's glow increases.%^RESET%^",wearer);
     tell_object(wearer,"%^BLUE%^%^BOLD%^The amulet is becoming uncomfortably hot.%^RESET%^");
     wearer->set_property("amuletawakening",3);
     call_out("awaken",4,wearer);
     break;
     case 3:
     tell_room(environment(wearer),"%^BLUE%^%^BOLD%^"+wearer->QCN+"'s eyes glaze over.%^RESET%^",wearer);
     tell_object(wearer,"%^CYAN%^%^BOLD%^A voice whispers in your mind:%^RESET%^ Finally, I have the strength I need!  Your body is mine, mortal!\n%^BLUE%^%^BOLD%^You feel a strong force surge up against your mind, and you struggle to fight it off.");
     wearer->set_property("amuletawakening",4);
     call_out("awaken",4,wearer);
     break;
     case 4:
     tell_object(wearer,"%^BLUE%^%^BOLD%^You feel yourself weakening under the pressure.%^RESET%^");
     wearer->do_damage("torso",dam);
     wearer->set_property("amuletawakening",5);
     call_out("awaken",4,wearer);
     break;
     case 5:
     tell_room(environment(wearer),"%^BLUE%^%^BOLD%^"+wearer->QCN+" seems to be struggling with something.%^RESET%^",wearer);
     tell_object(wearer,"%^BLUE%^%^BOLD%^The force becomes stronger.\n%^CYAN%^The voice whispers again:%^RESET%^ Fool mortal, you think you can fight me?.\n%^BLUE%^%^BOLD%^Laughter echoes through your mind.%^RESET%^");
     wearer->do_damage("torso",dam);
     wearer->set_property("amuletawakening",6);
     call_out("awaken",4,wearer);
     break;
     case 6:
     tell_room(environment(wearer),"%^BLUE%^%^BOLD%^The light from "+wearer->QCN+"'s amulet is nearly blinding.%^RESET%^",wearer);
     tell_object(wearer,"%^BLUE%^%^BOLD%^The light from your amulet is blinding, as the force bears down upon you yet again.%^RESET%^");
     wearer->do_damage("torso",dam*2);
     wearer->set_property("amuletawakening",7);
     call_out("awaken",4,wearer);
     break;
     case 7:
     tell_object(wearer,"%^BLUE%^%^BOLD%^You gather the final reserves of your strength, making a last desperate attempt to fight off the voice.%^RESET%^");
     if(!SAVING_D->saving_throw(wearer,"paralyzation_poison_death")) { 
       wearer->set_property("amuletawakening",9);
     }
     else { wearer->set_property("amuletawakening",8); }
     call_out("awaken",4,wearer);
     break;
     case 8:
     tell_room(environment(wearer),"%^BLUE%^%^BOLD%^"+wearer->QCN+" staggers to the ground, breathing heavily, but finally blinks "+wearer->QP+" eyes and regains "+wearer->QP+" senses.%^RESET%^",wearer);
     tell_object(wearer,"%^BLUE%^%^BOLD%^Your willpower overcomes the voice in your head; a scream of defeat echoes through your mind, but finally it is gone.\nYou stagger to the ground, weakened by the effort.%^RESET%^");
     wearer->set_property("amuletawakening",10);
     call_out("awaken",1,wearer);
     break;
     case 9:
     tell_room(environment(wearer),"%^BLUE%^%^BOLD%^"+wearer->QCN+" groans and slumps to the ground, unconscious!%^RESET%^",wearer);
     tell_object(wearer,"%^BLUE%^%^BOLD%^Your willpower overcomes the voice in your head; a scream of defeat echoes through your mind, and with its last strength the force sends a fiery pain burning through your skull.\nYou try to keep focussed, but the world around you fades to black.%^RESET%^");
     wearer->set_unconscious(1);
     wearer->set_property("amuletawakening",10);
     call_out("awaken",1,wearer);
     break;
     case 10:
     tell_room(environment(wearer),"The amulet flashes with bright light and disappears!");
     TO->remove();
     break;
   }
}

int isMagic(){
 int i;
 i = ::isMagic();
 i = i + 1;
 return i;
}