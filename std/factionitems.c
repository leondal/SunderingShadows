//Adapted from /std/plate for use with faction items
//There may be a better way to do this, but this seemed 
//to fit what I needed :)
//~Circe~ 11/24/07

#include <std.h>

inherit ARMOUR;

object owner,factionitem;
string owned;

void check_factionitem(object owner, object factionitem);
 
void create(){
   ::create();
   set_wear((:TO,"wearit":));
}

int check_factionitem(object owner, object factionitem) {
   owned = (string)owner->query_name();
   factionitem->set_wear((:TO,"wearit":));
   return 1;
}

void wearit(){
   if(interactive(TP))
      if((string)TPQN != owned){
         tell_object(TP,"This item was tailored for someone else!  "+
            "It will not fit you.");
         return 0;
      }else{
         tell_object(TP,"The item fits your body perfectly.");
         return 1;
      }
   owned = TPQN;
   return 1;
}

int is_factionitem() { return 1;}

void set_owned(object blah){
   owned = (string)blah->query_name();
}
