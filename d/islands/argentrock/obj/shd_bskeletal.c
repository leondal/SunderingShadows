//updated by Circe 6/11/04 with new desc, lore, etc.
#include <std.h>

inherit "/d/common/obj/armour/shield.c";
int is_metal() { return 0; }
string owner;

void create() {
   ::create();
   set_name("blue skeletal shield");
   set_id(({"shield","skeletal shield","blue skeletal shield"}));
   set_obvious_short("%^BLUE%^a blue shield%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^Skeletal shield%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^This round shield has been constructed "+
      "entirely of bones.  The bones have been dyed a deep blue "+
      "shade, with the ends left %^WHITE%^sparkling white%^BLUE%^.  "+
      "In battle, the shield may be spun to confuse an opponent.  "+
      "The center of the shield features the front part of a skull, "+
      "and %^RED%^deep rubies %^BLUE%^have been set within, giving "+
      "the skull the appearance of having fiery eyes.%^RESET%^");
   set_lore("Worn by the skeletal warriors on the island known as "+
      "Argentrock, this shield has long been both a decoration and "+
      "a sign of honor among those ghastly creatures.  They dye "+
      "the bones of their defeated foes blue and attach them to "+
      "the shield, making each shield unique.  The skull is taken "+
      "from a special foe - the one they must kill before they "+
      "can become skeletal warriors.  Strangely, it is hard to "+
      "say why they would choose such a path.");
   set_value(1000);
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
   if((int)TP->query_level() < 20 ){
      tell_object(ETO,"%^MAGENTA%^The %^BOLD%^BLUE%^Skeletal shield %^RESET%^"+
         "%^MAGENTA%^shouts: %^RESET%^You cannot master me!");
      TO->remove();
      return 0;
   }
   else {
      if( (string)TPQN != owner ) {
         tell_room(EETO,"The %^BOLD%^BLUE%^Skeletal shield "+
             "%^RESET%^refuses to fit "+ETOQCN+"'s body!\nIt lets out "+
             "a deafening cry and flees from "+TP->QP+" hand.",ETO);
         tell_object(ETO,"The %^BOLD%^BLUE%^Skeletal shield "+
             "%^RESET%^refuses to fit your body!\nIt lets out a "+
            "deafening cry and flees from your hand.");
         ETO->add_attacker(TO);
         ETO->continue_attack();
         ETO->do_damage("torso",50 + random(50));
         ETO->remove_attacker(TO);
         TO->remove();
         return 0;
      }
      else {
         switch( (int)ETO->query_alignment() ) {
            case 3:
            case 6:
            case 9:
               tell_object(ETO,"The %^BOLD%^%^BLUE%^Skeletal shield %^RESET%^"+
                   "recognizes you as its master as you wear it.\nThe "+
                   "%^BOLD%^%^RED%^ruby eyes %^RESET%^flare to life.");
               tell_room(EETO,"The %^BOLD%^%^BLUE%^Skeletal shield %^RESET%^"+
                   "recognizes "+ETOQCN+" as its master as "+
                   ""+ETO->QS+" wears it.\nThe "+
                   "%^BOLD%^%^RED%^ruby eyes %^RESET%^flare to life.",ETO);
               return 1;
               break;
            default:
               tell_room(EETO,"The %^BOLD%^BLUE%^Skeletal shield "+
                  "%^RESET%^refuses to fit "+ETOQCN+"'s body and lets out "+
                  "a deafening cry!",ETO);
               tell_object(ETO,"The %^BOLD%^BLUE%^Skeletal shield "+
                   "%^RESET%^refuses to fit your body and lets out a "+
                  "deafening cry!");
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
   tell_object(ETO,"%^BOLD%^%^BLUE%^The skull grows dull and lifeless "+
      "once more as you remove the shield.");
   tell_room(EETO,"%^BOLD%^%^BLUE%^The skull on "+ETOQCN+"'s shield "+
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
