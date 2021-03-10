#include <std.h>

/**** adjusting the weights down based on the limb since Circe broke the 
  common ones up for food types, ideally would vary by corpse size and 
  account for more limbs but probably not worth the bother *Styx* 12/20/05
****/

#define DECAY_TIME 200

inherit "/std/food";

int decay;
string whose,what;

void create() {
    ::create();
   set_weight(10);
   decay = 2;
   set_id(({"limb"}));
   set_property("no animate", 1);
   // above line added March 01 2008, to stop rended limbs
   // being used with animate object. Lujke.
}

void set_limb(string who, string type) {
   whose = who; what = type;
   set_short(what);
   set_long("This is the " + what + " of " + whose + ".\n");
   add("id", what);
   switch(what){
      case "right arm":  set_strength(6);        
			 set_raw(3);		set_weight(5);
                         break;
      case "left arm":  set_strength(6);
                         set_raw(3);		set_weight(5);
                         break;
      case "right leg":  set_strength(10);
                         set_raw(6);		set_weight(6);
                         break;
      case "left leg":  set_strength(10);
                         set_raw(6);		set_weight(6);
                         break;
      case "torso":  set_strength(20);
                         set_raw(6);		set_weight(20);
                         break;
      case "head":  set_strength(5);
                         set_raw(3);		set_weight(6);
                         break;
      case "neck":  set_strength(2);
                         set_raw(2);		set_weight(5);
                         break;
      case "waist":  set_strength(5);
                         set_raw(3);		set_weight(10);
                         break;
      case "right hand":  set_strength(3);
                         set_raw(2);		set_weight(2);
                         break;
      case "left hand":  set_strength(3);
                         set_raw(2);		set_weight(2);
                         break;
      case "right foot":  set_strength(3);
                         set_raw(2);		set_weight(3);
                         break;
      case "left foot":  set_strength(3);
                         set_raw(2);		set_weight(3);
                         break;
      default: 		 set_strength(5);
		         set_raw(4);		set_weight(5);
               		 break;
   }
   set_destroy();
   if(!random(50)){
      set_poison(3);
   }else{
      set_poison(0);
   }
   set_my_mess("You eat the messy raw meat.");
   set_your_mess("gnaws on some messy raw meat.");
   //call_out("decay", DECAY_TIME);
}

decay() {
   decay -= 1;
   if(decay > 0) {
      call_out("decay", 20);
      return;
   }
   remove();
}

string query_short() {
   if(decay == 2)
    return ""+what+" of "+whose;
   else
      return "the somewhat decayed " + what + " of " + whose;
}
