#include <std.h>
inherit "/std/armour";

create() {
    ::create();
  set_name("eyepatch");
  set_id(({"black eyepatch","eyepatch"}));
  set_short("%^BOLD%^%^BLACK%^black eyepatch%^RESET%^");
    set_long(
   "  This black eyepatch looks worn at the edges, as if it's seen alot of use after its wearer lost the eye."
   "  A nick is apparent in the eyepatch, evidence that the wearer's lifestyle didn't slow down as a result of the loss."
    );
  set_weight(1);
  set_value(1);
  set_type("ring");
  set_limbs(({"head"}));
    set_wear((:TO,"wearit":));
}
int wearit(){
  object*stuff;
  int i,j,flag;
  stuff=TP->all_armour();
  j=sizeof(stuff);
  for(i=0;i<j;i++){
  if((string)stuff[i]->query_name()=="eyepatch"){
  flag=1;
  break;
    }
  }
    if(flag){write("You'd look a little stupid with an eyepatch over both eyes.");
  return 0;
  }
  tell_object(ETO,"You slide the eyepatch on and realize the scratch "+
     "from the inside lets you see through it, leaving your vision "+
     "as good as before.");
  tell_room(EETO,""+ETOQCN+" wearily puts on an eyepatch, and you "+
     "wonder what tale "+ETO->QS+" has to tell about it.",ETO);
  return 1;
}
