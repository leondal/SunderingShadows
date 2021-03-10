#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

void create() {
  ::create();
  set_body_type("fowl");
  set_size(1);
  set_alignment(5);
  set_overall_ac(-10);
  set("aggressive",0);
  set_hd(100,10);
  set_level(1);
  set_class("fighter");
  set_mlevel("fighter",1);
  set_max_level(1);
  set_max_hp(1000);
  set_hp(query_max_hp());
  set_exp(0);
  set_damage(1,2);
  set_attacks_num(0);
  set_base_damage_type("pierce");
  set_attack_limbs(({"right claw","left claw"}));
  set_stats("intelligence",14);
  set_stats("wisdom",11);
  set_stats("strength",1);
  set_stats("charisma",12);
  set_stats("dexterity",16);
  set_stats("constitution",16);
  set_emotes(1,({"%^ORANGE%^The bird peers around with its alert eyes.%^RESET%^",
"%^ORANGE%^The bird flexes the sharp talons upon one of its clawed feet.%^RESET%^",
"%^ORANGE%^The bird turns its head and begins preening its feathers.%^RESET%^",
"%^ORANGE%^The bird stretches its wings, revealing their impressive span.%^RESET%^",
"%^ORANGE%^The bird tilts its head, watching its surroundings closely.%^RESET%^"}), 0);
  set_heart_beat(1);
}

void init(){
   ::init();
   add_action("stroke_fun","stroke");
   add_action("sendto_fun","sendto");
   add_action("dismiss_fun","dismiss");
}

int stroke_fun(string str) {
    if(!str) {
      notify_fail("Stroke what?");
      return 0;
    }
    if(member_array(str,(string)TO->query_id()) == -1) { return 0; }
    if((string)TPQN != (string)TO->query_property("owner")) {
      force_me("emoteat "+TPQN+" hisses and snaps its beak at $N.");
      return 1;
    }
    force_me("emoteat "+TPQN+" tilts its head to the side to let $N stroke its feathers.");
    return 1;
}

int sendto_fun(string str) {
    string here;
    if((string)TPQN != (string)TO->query_property("owner")) {
      force_me("emoteat "+TPQN+" pays $N no attention whatsoever.");
      return 0;
    }
    if(!str) {
      notify_fail("Who do you want to send the bird to?");
      return 0;
    }
    if(sizeof(all_inventory(TO)) < 1){
      force_me("emote holds out one clawed foot expectantly, as if waiting for something.");
      return 1;
    }
    force_me("emoteat "+TPQN+" spreads its wings at a word from $N and takes flight, soaring up into "
"the sky above!");
    TO->set_property("delivering",1);
    here = base_name(ETO);
    move("/realms/nienne/workroom");
    call_out("flight",random(10)+10,str,here);
    return 1;
}

void flight(string target,string home) {
   string location;
   object *inven,*pplz;
   int i;
   if ((int)TO->query_property("delivering") == 2) {
     move(home);
     pplz = all_living(ETO);
     inven = all_inventory(TO);
     for (i=0;i<sizeof(pplz);i++) {
       if (pplz[i]->query_name() == TO->query_property("owner")) {
         TO->remove_property("delivering");
         if (sizeof(inven) > 0) {
           force_me("emoteat "+TO->query_property("owner")+" swoops back down onto $np hand, dropping "
"something upon the ground just before it lands.");
           force_me("drop "+inven[0]->query_name()+"");
         }
         else { force_me("emoteat "+TO->query_property("owner")+" swoops back down onto $np hand."); }
         find_player(TO->query_property("owner"))->add_follower(TO);
         return;
       }
     }
     if (TO->query_property("delivering")) { 
       TO->remove_property("delivering");
       if (sizeof(inven) > 0) {
         force_me("emoteat "+target+" swoops in and drops something upon the ground, and then flaps away "
"again.");
         force_me("drop "+inven[0]->query_name()+"");
       }
       else { force_me("emote swoops in as if looking for something, and then flaps away again."); }
       (TO->query_property("glove"))->remove_property("summoned");
       (TO->query_property("glove"))->set_property("summoned",0);
       TO->remove();
       return;
     }
   }
   if ((int)TO->query_property("delivering") == 1) {
     if(!find_player(target)) {
       TO->set_property("delivering",1);
       call_out("flight",random(10)+10,target,home);
     }
     else {
       if((int)environment(find_player(target))->query_property("indoors")) {
         TO->set_property("delivering",1);
         call_out("flight",random(10)+10,target,home);
       }
       else {
         location = base_name(environment(find_player(target)));
         move(location);
         inven = all_inventory(TO);
         tell_room(ETO,""+TO->QCN+" swoops in from the sky and drops something at "
+find_player(target)->QCN+"'s feet.",find_player(target));
         tell_object(find_player(target),""+TO->QCN+" swoops in from the sky and drops something at "
"your feet.");
         force_me("drop "+inven[0]->query_name());
         force_me("emote soars up into the sky again and disappears from view.");
         move("/realms/nienne/workroom");
         TO->set_property("delivering",1);
         call_out("flight",random(10)+10,target,home);
       }
     }
   }
}

int dismiss_fun(string str) {
    object *inven;
    inven = all_inventory(TO);
    if(!str) {
      notify_fail("Dismiss what?");
      return 0;
    }
    if(member_array(str,TO->query_id()) == -1) { return 0; }
    if((string)TPQN != (string)TO->query_property("owner")) {
      force_me("emoteat "+TPQN+" pointedly ignores $N, and returns to preening its feathers.");
      return 1;
    }
    force_me("emoteat "+TPQN+" spreads its wings at a word from $N and takes flight, soaring up into "
"the sky above!");
    if (sizeof(inven) > 0) {
      tell_room(ETO,"It drops what it was carrying as it flies away.");
      TO->force_me("drop "+inven[0]->query_name());
    }
    (TO->query_property("glove"))->remove_property("summoned");
    (TO->query_property("glove"))->set_property("summoned",0);
    TO->remove();
    return 1;
}

void receive_given_item(object obj){
   object *inven;
   inven = all_inventory(TO);
   if (sizeof(inven) > 1) {
     tell_object(TP,"%^WHITE%^%^BOLD%^The bird can't seem to carry more than one item at a time... "
"It tries to keep hold of both items, but drops one.%^RESET%^");
     TO->force_me("drop "+inven[random(2)]->query_name());
     return;
   }
}

void heart_beat() {
   object *inven;
   string myowner;
   ::heart_beat();
   inven = all_inventory(TO);
   if(!query_property("delivering")) {
   if(sizeof(TO->query_attackers()) > 0) {
     tell_room(ETO,"%^WHITE%^%^BOLD%^The bird screeches in alarm and takes to the air, flapping away!");
     if (sizeof(inven) > 0) {
       tell_room(ETO,"%^WHITE%^%^BOLD%^It drops what it was carrying in its fright.%^RESET%^");
       TO->force_me("drop "+inven[0]->query_name());
     }
     (TO->query_property("glove"))->remove_property("summoned");
     (TO->query_property("glove"))->set_property("summoned",0);
     TO->remove();
   }
   if((int)ETO->query_property("indoors")) {
     tell_room(ETO,"%^WHITE%^%^BOLD%^The bird takes fright at being indoors, and flaps out the way you "
"came in!");
     if (sizeof(inven) > 0) {
       tell_room(ETO,"%^WHITE%^%^BOLD%^It drops what it was carrying in its fright.%^RESET%^");
       TO->force_me("drop "+inven[0]->query_name());
     }
     (TO->query_property("glove"))->remove_property("summoned");
     (TO->query_property("glove"))->set_property("summoned",0);
     TO->remove();
   }
   myowner = (string)TO->query_property("owner");
   if(!present(myowner,ETO)) {
     tell_room(ETO,"%^WHITE%^%^BOLD%^With its companion no longer present, the bird takes flight and "
"returns to the skies.");
     if (sizeof(inven) > 0) {
       tell_room(ETO,"%^WHITE%^%^BOLD%^It drops what it was carrying as it flies away.%^RESET%^");
       TO->force_me("drop "+inven[0]->query_name());
     }
     if (objectp(TO->query_property("glove"))){
       (TO->query_property("glove"))->remove_property("summoned");
       (TO->query_property("glove"))->set_property("summoned",0);
     }
     TO->remove();
   }
   return;
}
}
