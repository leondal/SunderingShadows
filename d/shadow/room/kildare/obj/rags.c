#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("grimy rags");
    set_id(({"rags","grimy rags","robe of rags","robe"}));
    set_short("A grimy robe of rags");
    set_long("This robe seems to have been pieced together "+
       "from whatever grimy strips of cloth could be found.  "+
       "No stitching has been done on the robe - rather, "+
       "it stays together through a careful system of layering.  "+
       "Occasional feathers can be found poking through the "+
       "layered pieces of fabric.");
    set_weight(1);
    set_value(3);
    set_type("cloth");
    set_limbs(({"torso"}));
    if(!random(3)) set_property("enchantment",1);
    set_wear((:TO,"extra_wear":));
    set_remove((:TO,"remove_me":));
}

int extra_wear(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^Your skin crawls "+
      "as you put on the raggedy robe...no wait, I think "+
      "that was a bug.%^RESET%^");
   return 1;
}

int remove_me(){
   tell_object(ETO,"%^BOLD%^You feel cleaner already as you "+
      "remove the pile of rags.%^RESET%^");
   return 1;
}