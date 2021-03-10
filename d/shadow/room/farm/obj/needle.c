#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("a golden needle");
   set_id(({"needle","golden needle","gold needle"}));
   set_short("%^YELLOW%^a golden needle%^RESET%^");
   set_long("%^YELLOW%^This slender needle is made of solid "+
      "gold and so smooth that it would fit the hand of the "+
      "most accomplished tailor.  The eye is just large "+
      "enough to fit most any thread, but narrowly made "+
      "so as not to pull the fabric.  You could <thread> "+
      "the needle before you began to tailor.%^RESET%^");
   set_value(1);
   set_weight(1);
}

void init(){
   ::init();
   add_action("thread","thread");
   add_action("sew_em","tailor");
}

int thread(string str){
   if(!str || str != "needle"){
      tell_object(ETO,"Try <thread needle>");
      return 1;
   }
   tell_object(ETO,"%^YELLOW%^You carefully thread the golden "+
      "needle, noticing how easily the job is done.");
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" threads "+ETO->QP+" "+
      "golden needle.",ETO);
   return 1;
}

int sew_em(string str){
   string color, strSize, material, type;
   if(!str) return 0;
   if (sscanf(str, "new %s %s from %s",strSize,type,material) != 3) {
      if (sscanf(str, "new %s %s",strSize,type) != 2) {
         if (sscanf(str, "new %s ",strSize) != 1) {
            if(sscanf(str,"new") != -1){
               if(!present(str,ETO)) return 0;
                  tell_object(ETO,"%^YELLOW%^You begin working on the "+str+" "+
                     "with your exquisite golden needle.");
                  return 0;
            }
         }
      }
      return 0;
   }
   tell_object(ETO,"%^YELLOW%^You begin working on the "+str+" "+
      "with your exquisite golden needle.");
   return 0;
}