//updated by Circe 6/11/04 with new desc, lore, etc.
#include <std.h>

inherit "/d/common/obj/armour/shield.c";

string owner;

int is_metal() { return 0; }

void create() {
   ::create();
   set_name("green skeletal shield");
   set_id(({"shield","skeletal shield","green skeletal shield"}));
   set_obvious_short("%^GREEN%^a green shield%^RESET%^");
   set_short("%^GREEN%^Skeletal shield%^RESET%^");
   set_long("%^GREEN%^This round shield has been constructed "+
      "entirely of bones.  The bones have been dyed a deep green "+
      "shade, with the ends left %^BOLD%^%^WHITE%^sparkling white"+
      "%^RESET%^%^GREEN%^.  "+
      "In battle, the shield may be spun to confuse an opponent.  "+
      "The center of the shield features the front part of a skull, "+
      "and %^BOLD%^%^BLUE%^sapphires %^RESET%^%^GREEN%^have been set "+
      "within, giving "+
      "the skull the appearance of having sparkling eyes.%^RESET%^");
   set_lore("This shield was made by Jarkunish the Great Skeletal "+
      "Warrior on the island of Argentrock from the bones of fallen "+
      "skeletal warriors.  Jarkunish is the guardian of all things "+
      "good and pure in the land of Argentrock, and he has been "+
      "assigned by the gods to guard the Great Sword of Light housed "+
      "there.  Because of this task, he challenges all who come "+
      "his way, even the good of heart.");
   set_value(1500);
   set_property("enchantment",4);
   set_wear( (: TO,"limited_wear" :) );
   set_remove( (: TO,"unwear_msg" :) );
   set_struck((:TO,"strikeme":));
}

void init() {
   ::init();
   if(interactive(TP) && TP == environment(TO) && !owner) {
      owner = TPQN;
   }
}

int limited_wear() {
   if( !interactive(TP) )
      return 1;
   if( (int)TP->query_level() < 25 ) {
      tell_object(ETO,"%^MAGENTA%^The %^GREEN%^Skeletal shield %^MAGENTA%^shouts: "+
         "%^RESET%^You cannot master me!");
      TO->remove();
      return 0;
   }
   else {
      if( (string)TPQN != owner ) {
         tell_room(EETO,"The %^GREEN%^Skeletal shield "+
            "%^RESET%^refuses to fit "+ETOQCN+"'s body.\nSuddenly it "+
             "glows bright %^GREEN%^green %^RESET%^, burning "+ETO->QP+" "+
            "hand and dismantles itself into a pile of bones!",ETO);
         tell_object(ETO,"The %^GREEN%^Skeletal shield "+
             "%^RESET%^refuses to fit your body.\nSuddenly it glows "+
            "bright %^GREEN%^green %^RESET%^, burning your hand and "+
            "dismantles itself into a pile of bones!");
         ETO->add_attacker(TO);
         ETO->continue_attack();
         ETO->do_damage("torso",50 + random(50));
         ETO->remove_attacker(TO);
         TO->remove();
         return 0;
      }
      else {
         switch( (int)ETO->query_alignment() ) {
            case 1:
            case 4:
            case 7:
               tell_object(ETO,"The %^GREEN%^Skeletal shield %^RESET%^recognizes "+
                   "you as its master as you wear it.\nThe %^BOLD%^"+
                   "%^BLUE%^sapphire eyes %^RESET%^sparkle with an "+
                   "inner light.");
               tell_room(EETO,"The %^GREEN%^Skeletal shield %^RESET%^recognizes "+
                   ""+ETOQCN+" as its master as "+ETO->QS+""+
                   " wears it.\nThe %^BOLD%^"+
                   "%^BLUE%^sapphire eyes %^RESET%^sparkle with an "+
                   "inner light.",ETO);
               return 1;
               break;
            default:
               tell_room(EETO,"The %^GREEN%^Skeletal shield "+
                  "%^RESET%^refuses to fit "+ETOQCN+"'s body and glows "+
                  "suddenly %^GREEN%^green%^RESET%^!",ETO);
               tell_object(ETO,"The %^GREEN%^Skeletal shield "+
                  "%^RESET%^refuses to fit your body and glows suddenly "+
                  "%^GREEN%^green%^RESET%^!");
               ETO->add_attacker(TO);
               ETO->continue_attack();
               ETO->do_damage("torso",80 + random(50));
               ETO->remove_attacker(TO);
               return 0;
         }
      }
   }
}

int unwear_msg() {
   tell_object(ETO,"%^GREEN%^The skull grows dull and lifeless "+
      "once more as you remove the shield.");
   tell_room(EETO,"%^GREEN%^The skull on "+ETOQCN+"'s shield "+
      "grows dull and lifeles as "+ETO->QS+" removes the shield.",ETO);
   return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^BOLD%^"+ETOQCN+" spins the shield "+
           "masterfully, confusing "+who->QCN+"!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^You spin the shield masterfully, "+
           "confusing "+who->QCN+"!");
        tell_object(who,"%^BOLD%^"+ETOQCN+" spins "+ETO->QP+" shield and "+
           "for a moment, you're confused!");
        who->set_paralyzed(1,"You are confused from the shield!");
        return 1;
      }
}
