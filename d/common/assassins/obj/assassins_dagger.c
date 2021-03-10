//updated by Circe 4/8/04 to current code and better desc, etc.
//Removed that an assassins ring was needed after T and Circe said yes - Cythera 5/05\\
//Fuck this weapon, it's a damn dagger, it doesn't get medium weapon damage.  Feel free to change base inherit if you want - Odin 5/7/2020
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";
void create() {
    ::create();
    set_name("dagger");
    set_id(({"dagger","assassin dagger","dagger of the assassins"}));
    set_obvious_short("%^BOLD%^%^BLACK%^a cold iron dagger%^RESET%^");
    set_short("%^RESET%^%^RED%^Dagger of the Assassins%^RESET%^");
    set_long(
   	"%^BOLD%^%^BLACK%^Made of the unusual substance known as "+
      "cold iron, this dagger has been given a nasty serrated "+
      "edge that would %^RESET%^%^RED%^shred %^BOLD%^%^BLACK%^"+
      "flesh.  The tip glistens with a "+
      "faint %^RESET%^%^GREEN%^green liquid %^BOLD%^%^BLACK%^"+
      "that runs down the %^RED%^blood groove %^BLACK%^all the "+
      "way to the %^RESET%^hilt %^BOLD%^%^BLACK%^wrapped in "+
      "%^RED%^blood-stained %^BLACK%^black leather."
    );
    set_lore("This dagger is the fabled Dagger of the Assassins, "+
       "a feared group of cutthroats and murderers found "+
       "throughout the realms.  Many speak in hushed tones "+
       "of the deeds of assassins, and there are often rumors "+
       "as to the true identities of these killers.  However, "+
       "they are always made quietly...and generally quickly "+
       "silenced.  The metal of the dagger is said to be one "+
       "that holds power even over demons and devils.");
    set_value(1000);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_unwield((:TO,"removeme":));
    set_property("enchantment",4);
    set_special_material_type("cold iron");
}
int extra_hit(object ob) {
    object vic;
    int dam,amnt;
    vic = ETO->query_current_attacker();
    if(!objectp(vic)) return 1;
    if(!objectp(ETO)) return 1;
    if(!random(9)){
      switch(random(11)){
          case 0..3:  tell_object(ETO,"%^RESET%^%^RED%^You slice "+
                         ""+vic->QCN+" with your dagger!%^RESET%^");
                      tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+" "+
                         "slices "+vic->QCN+" with "+ETO->QP+" "+
                         "dagger!",(({ETO, vic})));
                      tell_object(vic,"%^RESET%^%^RED%^"+ETOQCN+" "+
                         "slices you with "+
                         ""+ETO->QP+" dagger!%^RESET%^");
                      amnt = 4 + random(5);
              	    vic->do_damage("torso",amnt);
                      break;
          case 4..6:  tell_object(ETO,"%^RESET%^%^RED%^You %^BOLD%^slash "+
                         "%^RESET%^%^RED%^"+vic->QCN+" %^BOLD%^viciously "+
                         "%^RESET%^%^RED%^with your dagger!%^RESET%^");
                      tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+" "+
                         "%^BOLD%^slashes %^RESET%^%^RED%^"+vic->QCN+" "+
                         "%^BOLD%^viciously %^RESET%^%^RED%^with "+
                         ""+ETO->QP+" dagger!",(({ETO, vic})));
                      tell_object(vic,"%^RESET%^%^RED%^"+ETOQCN+" "+
                         "%^BOLD%^slashes %^RESET%^%^RED%^you "+
                         "%^BOLD%^viciously %^RESET%^%^RED%^with "+
                         ""+ETO->QP+" dagger!%^RESET%^");
                      amnt = 8 + random(9);
              	    vic->do_damage("torso",amnt);
                      break;
          case 7..8:  tell_object(ETO,"%^BOLD%^%^RED%^You stab "+
                         "your %^BLACK%^dagger %^RED%^deeply into "+
                         ""+vic->QCN+"!%^RESET%^");
                      tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" "+
                         "stabs "+ETO->QP+" %^BLACK%^dagger "+
                         "%^RED%^deeply into "+vic->QCN+"!",(({ETO, vic})));
                      tell_object(vic,"%^BOLD%^%^RED%^"+ETOQCN+" "+
                         "stabs "+ETO->QP+" %^BLACK%^dagger "+
                         "%^RED%^into you!%^RESET%^");
                      amnt = 12 + random(13);
              	    vic->do_damage("torso",amnt);
                      break;
          case 9..10:  tell_object(ETO,"%^RESET%^%^GREEN%^You "+
                         "%^BOLD%^%^RED%^wrench %^RESET%^%^GREEN%^"+
                         "your dagger from "+vic->QCN+" leaving "+
                         "%^BOLD%^poison %^RESET%^%^GREEN%^"+
                         "in the wound!%^RESET%^");
                      tell_room(EETO,"%^RESET%^%^GREEN%^"+ETOQCN+" "+
                         "wrenches "+ETO->QP+" dagger from "+vic->QCN+", "+
                         "leaving a %^BOLD%^green liquid %^RESET%^"+
                         "%^GREEN%^seeping from the wound!",(({ETO, vic})));
                      tell_object(vic,"%^RESET%^%^GREEN%^"+ETOQCN+" "+
                         "%^BOLD%^%^RED%^wrenches %^RESET%^%^GREEN%^"+
                         ""+ETO->QP+" dagger from you, leaving "+
                         "%^BOLD%^poison %^RESET%^%^GREEN%^in "+
                         "the wound!%^RESET%^");
                      amnt = 8 + random(9);
              	    vic->do_damage("torso",amnt);
                      vic->set_tripped(1,"%^GREEN%^You "+
                         "are stunned from the poison!");
                      break;
      }
   }
   return 1;
}

int extra_wield() {
    if(!ETO->query_property("assassin") && !ETO->is_class("assassin") && !ETO->query("is_assassin")){
	tell_object(ETO,"The dagger fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    //if(interactive(ETO) && !present("special_assassin_object",ETO)){
     // tell_object(ETO,"You can't wield this right now.");
      //return 0;
   //}
   tell_object(ETO,"%^BOLD%^%^RED%^You hear deep voices "+
      "whispering their dark charge into your mind as you "+
      "wield the dagger.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" grins with a "+
      "%^BOLD%^%^BLACK%^dark gleam %^RED%^in "+
      ""+ETO->QP+" eyes as "+ETO->QS+" wields the dagger.%^RESET%^",ETO);
   ETO->set_property("evil item",1);
    return 1;
}

int removeme()
{
   tell_object(ETO,"%^RED%^The voices cease their endless "+
      "murmurs as you set aside the blade.");
   tell_room(EETO,"%^RED%^The gleam fades from "+ETOQCN+"'s "+
      "eyes as "+ETO->QS+" sets aside the dagger.",ETO);
   ETO->set_property("evil item",-1);
   return 1;
}
