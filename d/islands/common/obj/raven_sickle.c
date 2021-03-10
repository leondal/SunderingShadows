#include <std.h>
inherit "/d/common/obj/weapon/sickle.c";

void create() {
   ::create();
   set_id(({"sickle","wing","raven's wing","raven"}));
   set_name("raven's wing");
   set_obvious_short("%^BOLD%^%^BLACK%^A blackened sickle%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Raven's Wing%^RESET%^");
   set_long(
      "The blade of this sickle curves wickedly in a semi-circle.  "+
      "The edges are razor sharp, and the blade has been etched with "+
      "images of %^BOLD%^%^BLACK%^ravens %^RESET%^in flight against "+
      "an empty sky.  The handle has been wrapped in thin %^BOLD%^%^BLACK%^"+
      "black leather cording %^RESET%^to prevent the wielder from cutting himself.  "+
      "The %^BOLD%^%^BLACK%^blackened blade %^RESET%^glitters dully, "+
      "seeming to drink up the light."
   );
   //set_weight(3);
   //set_size(1);
   set_value(13000);
   //set_wc(1,4);
   //set_large_wc(1,4);
   //set_type("slash");
   //set_prof_type("tool");
   //set_weapon_speed(4);
   set_property("enchantment", 5);
   set_wield((:TO,"wield_me":));
   set_unwield("%^BOLD%^%^BLACK%^You feel the raven recede as you lower the sickle.");
   set_hit((:TO,"hit_me":));
}

int wield_me(){
   if((int)ETO->query_level() < 15){
      tell_object(ETO,"%^BOLD%^%^BLACK%^The blade refuses your puny hand!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^The call of the raven rushes through you "+
      "as you wield the darkened sickle.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The whoosh of wings fills the air as "+
      ""+ETO->QCN+" takes the sickle in hand.",ETO);
   return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
      switch(random(5)){
         case 0..3:   tell_object(ETO,"%^BOLD%^%^RED%^You slash "+targ->QCN+" "+
                         "viciously across the face with your sickle!");
                      tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" slashes you "+
                         "across the face with "+ETO->QP+" sickle!");
                      tell_room(EETO,"%^BOLD%^%^RED%^Blood flies through the air "+
                         "as "+ETOQCN+" slices "+targ->QCN+" across the face "+
                         "with "+ETO->QP+" sickle!",({targ,ETO}));
                      targ->do_damage("torso",random(8)+3);
                      break;
         case 4:   tell_object(ETO,"%^BOLD%^%^RED%^You open "+targ->QCN+"'s "+
                      "chest in one slicing motion with your sickle!");
                   tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" opens your chest "+
                      "in one slice with "+ETO->QP+" sickle!");
                   tell_room(EETO,"%^BOLD%^%^RED%^"+targ->QCN+"'s chest opens "+
                      "with a gaping wound from "+ETOQCN+"'s sickle!",({targ,ETO}));
                   targ->do_damage("torso",random(8)+7);
                   targ->set_tripped(3,"You are trying to catch your breath from your chest being sliced!");
                   break;
      }
   return 1;
   }
