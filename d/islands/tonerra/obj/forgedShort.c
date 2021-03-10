//forgedShort.c
// added obvious short & made min level 15, last change 7/98 *Styx* 10/29/03
//updated desc by Circe 4/20/04

#include <std.h>

inherit "/d/common/obj/weapon/shortsword.c";

void create(){
   ::create();

   set_name("Red short sword");
   set_obvious_short("%^BOLD%^%^RED%^A russet short sword%^RESET%^");
   set_short("%^BOLD%^%^RED%^V%^RESET%^%^RED%^o%^BOLD%^l%^RESET%^"+
		"%^RED%^c%^BOLD%^a%^RESET%^%^RED%^n%^BOLD%^i%^RESET%^"+
		"%^RED%^c Short Sword%^RESET%^");
   set_id(({"red","short","sword","short sword","red sword","red short sword"}));
   set_long(
      "%^BOLD%^%^RED%^This blade looks forged from fire itself, "+
      "though it seems solid enough.  The outer shell of the "+
      "blade seems almost %^YELLOW%^crystalline %^RED%^in nature, "+
      "but inside there swirls a storm of %^RESET%^%^RED%^red"+
      "%^BOLD%^, %^RESET%^%^ORANGE%^yellow%^BOLD%^%^RED%^, and "+
      "%^BLACK%^black%^RED%^.  "+
      "The hilt of the blade is made of the same %^YELLOW%^crystalline "+
      "substance %^RED%^as the outer casing, thickened and etched "+
      "with c%^YELLOW%^r%^RED%^o%^YELLOW%^s%^RED%^s%^YELLOW%^-%^RED%^h%^YELLOW%^"+
      "%^RED%^a%^YELLOW%^t%^RED%^c%^YELLOW%^h%^RED%^i%^YELLOW%^n%^RED%^g "+
      "to provide a strong grip.%^RESET%^");
   set_lore(
@OLI
   The deep red color of this sword flows within the blade, forged
from the deep fires that anger the volcano on the islands of  Tonerra.  
The fire was magically sealed in the blade making it a deadly weapon 
to be struck by but also to wield.
OLI
   );
   //set_wc(2,4);
   //set_size(1);
   //set_large_wc(2,5);
   set_hit((:TO,"hitme":));
   set_type("slashing");
   set_weight(6);
   set_value(1000);  
//set_property("magic", 1);
   set_wield((:TO,"wieldme":));
   set_property("enchantment",3);
}


int wieldme(){
   if(ETO->query_lowest_level() < 21) {
	tell_object(ETO,"The power of the sword overwhelms you "+
         "before you can wield it.\nYou feel as though your "+
         "hand was burned through but, when you check, you "+
         "don't see any apparent damage.");
	return 0;
   }
   tell_object(ETO,"Your hand sizzles with pain as the heat seeps into you.");
   //TP->do_damage("torso",random(10));
   return 1;
}

int hitme(object targ){
      if(!objectp(targ)) return 0;

      if(!random(20)){
   	    tell_object(targ,"%^RED%^You feel the fire magically held "+
             "in the sword seep into you.\n");
	    tell_object(ETO,"%^RED%^You feel the fire seep into "+targ->QCN+".\n");
	    targ->do_damage("torso",roll_dice(2,4));
	    call_out("seep",5,targ,1);
	    return random(2);
      }
      return random(2);
}

void seep(object targ, int time){
   if(!objectp(targ)) return;

   switch (time) {
   case 1:
      tell_object(targ,"%^RED%^You feel the fire flowing through "+
         "your veins burning you up from the inside.\n");
      tell_room(environment(targ),"%^RED%^You see "+targ->QCN+" writhe "+
         "in pain as if being burned from the inside.",targ);
      targ->do_damage("torso",roll_dice(2,5));
// adding this to see if it will keep the damage from killing if it's a pk situation *Styx* 11/18/03
      if(targ->query_hp() < 1)  return;
      if(objectp(targ)) targ->add_attacker(TO);
      if(objectp(targ)) targ->continue_attack();
      if(!objectp(targ)) return;
      call_out("seep",5,targ,2);
      break;
   case 2:
      tell_object(targ,"%^RED%^You feel the fire flowing through "+
         "your veins burning you up from the inside.\n");
      tell_room(environment(targ),"%^RED%^You see "+targ->QCN+" "+
         "writhe in pain as if being burned from the inside.",targ);
      targ->do_damage("torso",roll_dice(2,6));
// adding this to see if it will keep the damage from killing if it's a pk situation *Styx* 11/18/03
      if(targ->query_hp() < 1)  return;
      if(objectp(targ)) targ->add_attacker(TO);
      if(objectp(targ)) targ->continue_attack();
      if(!objectp(targ)) return;
// adding this to see if it will keep the damage from killing if it's a pk situation *Styx* 11/18/03
      if(targ->query_hp() < 1)  return;
      call_out("seep",5,targ,3);
      break;
   case 3:
// adding this to see if it will keep the damage from killing if it's a pk situation *Styx* 11/18/03
      if(targ->query_hp() < 1)  return;
      tell_object(targ,"%^RED%^You feel the fire flowing through "+
         "your veins burning you up from the inside.\n");
      tell_room(environment(targ),"%^RED%^You see "+targ->QCN+" "+
         "writhe in pain as if being burned from the inside.",targ);
      targ->do_damage("torso",roll_dice(2,7));
   if(!objectp(targ)) return;
      targ->add_attacker(TO);
   if(!objectp(targ)) return;   
      targ->continue_attack();
      break;
   }
}
