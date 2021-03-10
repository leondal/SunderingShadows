// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("%^RESET%^%^GREEN%^Ring of Vines%^RESET%^");
   set_id(({"ring","ring of vines","vine ring"}));
   set_short("%^RESET%^%^GREEN%^A delicate ring of vines%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This delicate ring is made out of several"
" intertwined vines that wrap around the wearers finger.  Woven into the vines are"
" %^MAGENTA%^delicate %^GREEN%^and very little %^BOLD%^%^WHITE%^white flowers"
" %^RESET%^%^GREEN%^for added decoration.  The smell coming from the ring is quite"
" lovely.%^RESET%^\n");
   set_lore("%^RESET%^%^GREEN%^It is rumored that these rings were crafted in"
" remembrance of the lovely elven priestess Elliawyn, keeper of the Ring of All"
" Things Beautiful.  Her fate is unknown, though rumors of a terrible travesty upon"
" her family run rampant through the Barrier Mountains.  Nobody knows for certain"
" what befell of the ring entrusted to her.%^RESET%^");
   set_weight(2);
   set_value(500);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_property("enchantment",0);
   set_item_bonus("charisma",1);
   set_ac(0);
   set_wear((:this_object(),"wearme":));
   set_remove((:this_object(),"unwearme":));
   set_heart_beat(1);
}
int wearme(string str){
      tell_room(environment(ETO),"%^BOLD%^%^GREEN%^%^As "+ETOQCN+" slips on the ring a wonderfully fresh fragrance wafts through the room.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^GREEN%^A wonderfully fresh fragrance fills the room as you wear the ring.%^RESET%^");
      TP->set("long",""+capitalize(nominative(TP))+" is surrounded by a wonderfully fresh fragrance.");
      return 1;
 }
int unwearme(string str){
   tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" doesn't look pleased about removing the ring.%^RESET%^",ETO);
   tell_object(ETO,"%^GREEN%^A feeling of disappointment overcomes you as you remove the ring.%^RESET%^");
   ETO->set("long",0);
   return 1;
}
void heart_beat(){
   object obj;
   if((obj=present("vine ring",ETO))&&living(ETO)&&obj!=TO){
      tell_object(ETO,"The ring feels the presence of another and disappears!");
      ETO->do_damage("torso",roll_dice(3,10));
      ETO->add_attacker(TO);
      ETO->continue_attack();
      obj->remove();
      TO->remove();
   }
}
