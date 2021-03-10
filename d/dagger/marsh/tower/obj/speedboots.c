//Added color, per Kain's suggested submission - Octothorpe 6/8/09
//Coded by Bane//
#include <std.h>
inherit ARMOUR;

string owner;
void change_limbs(int limbid);

void create(){
   ::create();
   set_id(({"boots","boots of speed","speed"}));
   set_name("leather boots");
   set_obvious_short("%^BOLD%^%^BLACK%^A pair of %^WHITE%^fine %^BOLD%^"+
      "%^BLACK%^leather boots%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Boots of Sp%^WHITE%^ee%^BOLD%^%^BLACK%^d%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^These boots are made of a fine quality "+
      "leather, and look to be quite expensive and nearly brand new.  "+
      "They weigh close to nothing and seem to have a %^RED%^sh%^BOLD%^"+
      "%^BLACK%^a%^BOLD%^%^RED%^dy haze %^BOLD%^%^BLACK%^around them, "+
      "making them look as if they are almost %^RESET%^%^GREEN%^shaking"+
      "%^BOLD%^%^BLACK%^.  The gleaming finish of the %^RESET%^darksteel "+
      "%^BOLD%^%^BLACK%^buckles serve to catch quivering reflections of "+
      "light, as %^BOLD%^%^BLUE%^v%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^br"+
      "%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^io%^BOLD%^%^BLUE%^ns "+
      "%^BOLD%^%^BLACK%^constantly keep the boots aquiver.  A mysterious "+
      "%^BOLD%^%^MAGENTA%^power %^BOLD%^%^BLACK%^seems to be held within them.%^RESET%^");
   //Was too lazy to overcome my writer's block lore - Octothorpe
   set_lore("These boots are imbued with a magical property that allows their wearer to be much quicker "
"than normal.  So powerful is the enchantment upon them that they are said to be able to change to suit "
"feet of any size, or even to fit a creature without feet... though that sounds bizarre to say the least.");
   set_weight(5);
   set_size(-1);
   set_value(5000);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_ac(0);
   set_property("enchantment",5);
   set_item_bonus("damage resistance",10);
   set_wear((:TO,"wield_me":));
   set_remove((:TO,"unwield_me":));
   set_heart_beat(1);
}

void wield_me(){
    if(interactive(ETO) && (string)ETO->query_name() != owner){
        write("These are not your boots.");
        return 0;
    }
    write("Your feet feel lighter than air, and as if you can run for miles.");
    ETO->add_skill_bonus("athletics",5);
    return 1;
}

void unwield_me(){
    write("You feel tired and sluggish.");
    ETO->add_skill_bonus("athletics",-5);
    return 1;
}

void init(){
    ::init();
    if(interactive(TP) && TP == environment(TO) && !owner) { // change to fit only once for the owner. N, 2/14
      owner = TPQN;
      if((string)TP->query_race() == "centaur") { change_limbs(1); return; }
      if((string)TP->query_race() == "minotaur") { change_limbs(2); return; }
      if((string)TP->query_race() == "wemic") { change_limbs(3); return; }
    }
}

void heart_beat(){
    if(!living(ETO)) return 1;
    if(!TO->query_worn()) return 1;
    if(ETO->query_current_attacker()){
         if(!random(15)){
            tell_object(ETO,"%^BOLD%^The boots give you a burst of speed.");
            ETO->execute_attack();
        }
    }
}

void change_limbs(int limbid){
     tell_room(EETO,"%^BLUE%^The boots change into something more fitting of their new owner!");
     switch(limbid) {
       case 1: //forehooves
         TO->set_limbs(({"right forehoof","left forehoof"}));
       break;
       case 2: //hooves
         TO->set_limbs(({"right hoof","left hoof"}));
       break;
       case 3: //forepaws
         TO->set_limbs(({"right forepaw","left forepaw"}));
       break;
     }

     if(limbid == 1 || limbid == 2) { // horseshoes for a centaur or minotaur
       TO->set_name("darksteel horseshoes");
       TO->set_id(({"horseshoes","darksteel horseshoes","horseshoes of speed"}));
       TO->set_obvious_short("%^BOLD%^%^BLACK%^A pair of %^WHITE%^fine %^BOLD%^%^BLACK%^darksteel horseshoes%^RESET%^");
       TO->set_short("%^BOLD%^%^BLACK%^Horseshoes of Sp%^WHITE%^ee%^BOLD%^%^BLACK%^d%^RESET%^");
       TO->set_long("%^BOLD%^%^BLACK%^These horseshoes are made of a fine quality "+
      "%^RESET%^darksteel%^BOLD%^%^BLACK%^, and look to be quite expensive and nearly brand new.  "+
      "They weigh close to nothing and seem to have a %^RED%^sh%^BOLD%^"+
      "%^BLACK%^a%^BOLD%^%^RED%^dy haze %^BOLD%^%^BLACK%^around them, "+
      "making them look as if they are almost %^RESET%^%^GREEN%^shaking"+
      "%^BOLD%^%^BLACK%^.  The gleaming finish of the %^RESET%^darksteel "+
      "%^BOLD%^%^BLACK%^serves to catch quivering reflections of "+
      "light, as %^BOLD%^%^BLUE%^v%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^br"+
      "%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^io%^BOLD%^%^BLUE%^ns "+
      "%^BOLD%^%^BLACK%^constantly keep the metal crescents aquiver.  A mysterious "+
      "%^BOLD%^%^MAGENTA%^power %^BOLD%^%^BLACK%^seems to be held within them.%^RESET%^");
       return;
     }

     if(limbid == 3) { // pawguards for a wemic
       TO->set_name("leather pawguards");
       TO->set_id(({"pawguards","leather pawguards","guards","pawguards of speed"}));
       TO->set_obvious_short("%^BOLD%^%^BLACK%^A pair of %^WHITE%^fine %^BOLD%^%^BLACK%^leather pawguards%^RESET%^");
       TO->set_short("%^BOLD%^%^BLACK%^Pawguards of Sp%^WHITE%^ee%^BOLD%^%^BLACK%^d%^RESET%^");
       TO->set_long("%^BOLD%^%^BLACK%^These pawguards are made of a fine quality "+
      "leather, and look to be quite expensive and nearly brand new.  "+
      "They weigh close to nothing and seem to have a %^RED%^sh%^BOLD%^"+
      "%^BLACK%^a%^BOLD%^%^RED%^dy haze %^BOLD%^%^BLACK%^around them, "+
      "making them look as if they are almost %^RESET%^%^GREEN%^shaking"+
      "%^BOLD%^%^BLACK%^.  The gleaming finish of the %^RESET%^darksteel "+
      "%^BOLD%^%^BLACK%^buckles serve to catch quivering reflections of "+
      "light, as %^BOLD%^%^BLUE%^v%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^br"+
      "%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^io%^BOLD%^%^BLUE%^ns "+
      "%^BOLD%^%^BLACK%^constantly keep the guards aquiver.  A mysterious "+
      "%^BOLD%^%^MAGENTA%^power %^BOLD%^%^BLACK%^seems to be held within them.%^RESET%^");
       return;
     }
}
