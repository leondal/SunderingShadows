#include <std.h>
#include <daemons.h>
#include "../../dagger.h"
inherit ARMOUR;

int mytimer;

void create() {
    ::create();
    set_name("wolf's head visor");
    set_id(({"visor","wolf's head","wolf head","wolf's head visor","ebony 
visor","guise","hunter's guise","Hunter's Guise"}));
    set_short("%^BOLD%^%^BLACK%^Hunter's Guise%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^ebony wolf's head visor%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This jet-black visor covers the wearer's entire face, "
"leaving only the lower jaw and mouth visible. It has been shaped with the appearance of "
"a %^RESET%^%^WHITE%^wolf's head%^BOLD%^%^BLACK%^, with ears lifted to either side and a "
"%^RESET%^%^RED%^feral snarl %^BOLD%^%^BLACK%^across its features, its %^WHITE%^fangs "
"%^BLACK%^hanging down to frame the wearer's face on either side. Two %^RED%^glowing "
"crimson eyes %^BLACK%^are formed from some kind of iridescent gemstone, peering out upon "
"the world with a %^RESET%^%^BLUE%^malignant gaze%^BOLD%^%^BLACK%^.%^RESET%^\n");
   set_weight(4);
   set_value(4000);
   set_type("leather");
   set_limbs(({"head"}));
   set_property("enchantment",3);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   mytimer = 0;
}

int drop(){ return 1; }

void init(){
   ::init();
   add_action("summon","summon");
}

int wear_fun() {
   int myname;
   if(living(ETO)) myname = ETO->query_name();
   tell_object(ETO,"%^BOLD%^%^BLACK%^A great weight settles on your shoulders, and you "
"feel your heart darken as you wear the visor.%^RESET%^");
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the power within you to "
"%^WHITE%^summon%^BLACK%^ the %^WHITE%^wolves%^BLACK%^.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s face disappears beneath the ebony guise "
"of the wolf's head.%^RESET%^",ETO);
   ETO->set_property("evil item",1);
   return 1;
}

int remove_fun(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^With effort you tear the helm away, leaving you "
"strangely exhausted.%^RESET%^");
   ETO->set_property("evil item",-1);
   return 1;
}

void summon(string str){
   int i, j;
   object ob;
   j = random(3)+2;
   if(!objectp(ETO)) return 0;
   if(!str || str != "wolves") {             
     notify_fail("What are you trying to summon?\n");
     return 0;
   }
   if(!TO->query_worn()){ 
     notify_fail("You must be wearing the visor to use it.\n");
     return 0;
   }
   if(mytimer > time()) {
     notify_fail("You've already called to the wolves today.\n");
     return 0;
   }
   mytimer = time() + 28800;
   tell_object(TP,"%^BOLD%^%^BLACK%^You throw back your head and let out a long howl, "
"calling your brethren to you!");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" throws back "+ETO->QP+" head and lets "
"out a long howl, causing several black wolves to come running to his side!",ETO);
   for(i = 0; i< j; i++) {
     ob=new(MON"wolf");
     ob->move(EETO);
     ob->force_me("protect "+ETO->query_name());
     ETO->add_follower(ob);
   }
   return 1;
}

void reset_timer() {
   mytimer = time();
}
