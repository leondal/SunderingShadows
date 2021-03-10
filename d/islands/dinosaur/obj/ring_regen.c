#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit "/std/armour.c";
int uses;

void create(){
    ::create();
    set_name("ring of regeneration");
    set_short("Copper Ring");
    set_id( ({"ring", "copper ring"}) );
    set_long(
      "This small copper ring glows slightly when you hold it in your palm."
    );
    set_property("magic", 1);
    if(!random(4))
      set_property("gcurse", 1);
    else
      set_property("gcurse", 0);
    set_type("ring");
    set_ac(0);
    set_value(10);
    set_limbs( ({"right hand", "left hand"}) );
    set_wear( (:TO, "wear_func":) );
    set_heart_beat(5);
    uses = 50+random(50);
}

int wear_func(){

    if(query_property("gcurse")){
      while(query_property("enchantment") != -1){
        remove_property("enchantment");
        set_property("enchantment", 1);
      }

      tell_object(TP, "%^BOLD%^%^RED%^As you wear the ring you feel a sharp pain shoot up your arm!%^RESET%^");
      return 1;
    }
    tell_object(TP, "%^BOLD%^As you wear the ring a soothing calm washes over you.%^RESET%^");
    return 1;
}

void heart_beat(){
    if(!query_worn()) return;

    uses--;
    if(uses < 0) {
      tell_object(query_worn(), "%^BOLD%^%^GREEN%^The small copper ring fades out of existance!%^RESET%^");
      TO->remove();
      return;
    }
    if(query_property("gcurse") || !random(8)){
      query_worn()->do_damage("torso", 5);
      if(!random(10)) tell_object(query_worn(), "%^RED%^%^BOLD%^A sharp pain runs up your arm!");
      if(!random(20)) query_worn()->set_paralyzed(10, "The ring won't let you move!");
      if(!random(25)) query_worn()->do_damage("torso", 5);
      if(!random(20)) query_worn()->add_hp(5);
      if(!random(200)){
        tell_object(query_worn(), "%^BOLD%^The pain of the ring suddenly changes into a soothing warmth up your arm.");
        remove_property("gcurse");
        remove_property("enchantment");
      }
    } else {
      query_worn()->add_hp(5);
      if(!random(10)) tell_object(query_worn(), "%^BOLD%^A soothing warmth flows up your arm.");
      if(query_worn()->query_paralyzed() && !random(15)) query_worn()->remove_paralyzed();
      if(!random(20)) query_worn()->add_hp(5);
      if(!random(20)) query_worn()->do_damage("torso", 5);
      if(!random(200)){
        tell_object(query_worn(), "%^BOLD%^%^RED%^The soothing warmth of the ring suddenly changes into a biting pain!%^RESET%^");
        while(query_property("enchantment") != -1){
          remove_property("enchantment");
          set_property("enchantment", -1);
        }
        set_property("gcurse", 1);
      }
    }
}

int query_uses(){
    return uses;
}

void set_uses(int x){
    uses = x;
}
