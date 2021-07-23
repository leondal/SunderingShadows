#include <std.h>
inherit OBJECT;

int hits;
object target;

void create() {
   ::create();
   set_name("rapierdam");
   set("id", ({ "remotexoli"}) );
   set_short("");
   set_long("");
   set_property("no animate", 1);
   set_weight(0);
   hits=random(10)+10;
   set_heart_beat(1);
   set_property("no disenchant",1);
}

int drop(){ return 1;}
void set_target(object obj) { target = obj; }

void heart_beat() {
   if(!objectp(ETO) || ETO != target || target->query_ghost() || hits < 1){
      TO->move("/d/shadowgate/void");
      TO->remove();
      return;
   }
   tell_object(ETO,"%^RESET%^%^RED%^The torn wounds left from the rapier pulse with pain!%^RESET%^");
   ETO->cause_typed_damage(ETO, "torso", 1, "piercing");
   hits--;
}