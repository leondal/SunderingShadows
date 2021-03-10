// updated dex bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;
string OWNER;
int FLAG;
void init(){
  ::init();
  if(interactive(TP) && TP==environment(TO)  && !OWNER) OWNER = TPQN;
}
  void create(){
  ::create();
  set_name("hob-nailed boots");
  set_id(({"boots","hob-nailed boots",}));
  set_short("%^RESET%^%^RED%^Hob-nailed boots%^RESET%^");
  set_long(
   "%^RED%^  These massive heavy leather boots have many straps and buckles"+
   " running down their sides.  Their thick soles are studded with %^ORANGE%^"+
   "copper cleats%^RED%^ which would give them traction anywhere.   Maybe "+
   "too much traction.  The straps and buckles look pretty complicated but "+
   "seem to allow the boot to be reduced in size to something only about "+
   "double that of a human's foot.%^RESET%^"
  );
  set_weight(10);
  set_value(100);
  set_type("clothing");
  set_limbs(({"right foot","left foot"}));
  set_wear((:TO,"extra_wear":));
  set_remove( (:TO,"remove_func":) );
  set_ac(0);
  set_property("enchantment",1);
  set_size(3);
  set("dexbonus",1);
}

int extra_wear(){
  if((string)ETO->query_race() =="giant") return 1;
  if((string)ETO->query_name() !=OWNER){
   tell_room(ETO,"%^RED%^You can't figure the straps and buckles out and give up.");
   tell_room(environment(ETO),"%^RED%^"+ETOQCN+" fiddles with a pair of "+
         "heavy sturdy looking boots and gives up on trying to figure their buckles out.",ETO);
  return 0;
 }
  tell_room(ETO,"%^RED%^You buckle the boots to your feet and grin, looking around"+
          " for something to stomp into the ground.");
  tell_room(environment(ETO),"%^RED%^"+ETOQCN+" buckles a set of boots to"+
     " "+ETO->QP+" feet and looks up with a mean grin.", ETO);
                        TO->set_heart_beat(1);
        return 1;
}


int remove_func(){
  tell_room(ETO,"%^RED%^Hopefully you'll still have enough traction to chase"+
         " things down without the cleated boots.");
   tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" almost seems to slip as "+
         ""+ETO->QS+" removes the buckles and steps out of "+ETO->QP+" massive boots.",ETO);
                TO->set_heart_beat(0);
        return 1;
}


void heart_beat(){
  object owner,env;
 int i;
  env=ETO;
  if(!objectp(ETO))return;
  if(objectp(env) && living (env)){
  owner=env;
  env=environment(owner);
  }
  if(!TO->query_worn()){
  return;  
  } else {
  i=random(500);
  if((i>475)){
  tell_object(owner,"You see a small bug and stop to stomp it flat!\n");
  tell_room(env,""+ETO->query_cap_name()+" is suddenly distracted by a something on the floor and snarls and starts to jump up and down on it ignoring everything else!",owner);
  owner->set_paralyzed(random(10)+3,"Damn! Stomping things with these boots feels so good!");
  }
}
}
