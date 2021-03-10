#include <std.h>
inherit ARMOUR;
string owner;

void create(){
  ::create();
  set_name("barkskin");
  set_id(({"barkskin","skin","skin of bark"}));
  set_short("%^RESET%^%^ORANGE%^rough barkskin%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^Rough to the touch is this layer of %^RED%^bark"
"%^ORANGE%^, like the surface of an old and gnarled tree.  It is shaped to "
"provide a %^GREEN%^protective barrier %^ORANGE%^for the wearer, with small "
"chips of wood that fall to the ground as it defends against blows.%^RESET%^");
  set_type("leather");
  set_limbs(({"torso"}));
  set_weight(1); //changing this down because it doesn't cast right if encumberance goes over max
  set_value(0);
  set_ac(8);
  set("no curse",1);
  set_remove((:TO,"removeit":));
}

void init(){
   ::init();
   if(stringp(owner)) return;
   if(interactive(TP) && TP == ETO){
       owner = TPQN;
   }
}

int query_size(){
   if(living(ETO)) return ETO->query_size();
   else return 3;
}

int removeit(){
  tell_object(ETO,"%^RED%^The protective bark crumbles and falls from your "
"skin.");
  tell_room(EETO,"%^RED%^The protective bark crumbles and falls from "
+ETO->QCN+"'s skin.",ETO);
  call_out("go_away",1);
  return 1;
}

int save_me(string file){ return 1;}

void go_away() {
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(TO->query_worn()) return;
   TO->remove();
}

int wearable() { return 1; }
