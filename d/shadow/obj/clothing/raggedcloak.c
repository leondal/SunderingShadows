//updated by Circe 1/4/04
#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("ragged cloak");
   set_id(({"cloak","ragged","rags"}));
   set_obvious_short("%^RESET%^%^MAGENTA%^ragged cloak%^RESET%^");
   set_short("%^BOLD%^%^MAGENTA%^P%^YELLOW%^a%^RED%^t%^MAGENTA%^c%^YELLOW%^h"+
      "%^RED%^w%^MAGENTA%^o%^YELLOW%^r%^RED%^k Cloak%^RESET%^");
   set_long("%^MAGENTA%^This cloak was once bright and colorful, but "+
      "it has become faded and torn from much misuse.  Multiple patches "+
      "are scattered around the cloak, but you cannot tell if that was "+
      "the original design or a long series of repairs.  Either way, the "+
      "cloak is now well beyond full repair and looks as though it might "+
      "be a haven for vermin.  A muted musty smell rises up from the cloak, "+
      "becoming stronger at times.%^RESET%^");
   set_lore("This lice-infested cloak was once a cloak worn by one "+
      "of the Great Bards.  This was not so much a guild as a measure "+
      "of honor bestowed upon some bards of the land.  A visit from "+
      "a true bard to a small town was a real honor and pleasure for "+
      "the townspeople.  In preparation for such an event, the goodwives "+
      "of the town would often get together and make a gift of some "+
      "sort to the bard.  The goodwives of Koenig used to make "+
      "these cloaks.  Each patch was taken from an article of clothing "+
      "of import to all the villagers.  The women gathered the patches "+
      "and sewed them into the cloak so that a little piece of the "+
      "village might go with the bard wherever he traveled.");
   set_weight(6);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(200);
   set_property("enchantment",1);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
   tell_object(ETO,"%^MAGENTA%^As you put on the ragged cloak, you feel like a "
      "beggar.");
   return 1;
}

int remove_func() {
   tell_object(ETO,"%^MAGENTA%^You no longer feel stupid and poor.");
   return 1;
}

void reset() {
   ::reset();
   if(!objectp(ETO)) return;
   if(!(TO->query_worn())) {
        return;
   } else {
      switch(random(5)){
         case 0:  tell_object(ETO,"You think you feel something crawling "+
                     "on your neck and feel the urge to swat it off!");
                  if(!random(2)){
                     tell_room(EETO,"You see lice crawling up "+ETOQCN+"'s neck!",ETO);
                  }
                  break;
         case 1:  tell_object(ETO,"A strange smell rises from your cloak.");
                  tell_room(EETO,"A horrible stench rises around "+ETOQCN+".",ETO);
                  break;
         case 2:  tell_object(ETO,"Something bites you suddenly just behind your ear, "+
                     "making you scratch it.");
                  tell_room(EETO,""+ETOQCN+" scratches suddenly behind "+
                     ""+ETO->query_possessive()+" ear.",ETO);
                  break;
         case 3:  tell_object(ETO,"You feel like you have tiny things crawling all over you!");
                  tell_room(EETO,""+ETOQCN+" squirms and looks uncomfortable.",ETO);
                  break;
         case 4:  tell_object(ETO,"%^BOLD%^Suddenly, fleas and lice pour out of your "+
                     "cloak, crawling all over your arms and neck!");
                  tell_room(EETO,"%^BOLD%^%^BLACK%^Fleas %^WHITE%^and %^RED%^"+
                     "lice %^WHITE%^suddenly pour out of "+ETOQCN+"'s cloak, "+
                     "covering "+ETO->query_possessive()+"'s face and neck!",ETO);
                  break;
      }
   }
}
