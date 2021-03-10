//updated to current code and to remove references to old gods ~Circe~ 9/22/19
#include <std.h>
inherit "/d/common/obj/weapon/glaive.c";

void create(){
   ::create();
   set_name("glaive");
   set_short("%^RESET%^%^RED%^Glaive of the Scarlet %^BOLD%^T%^YELLOW%^h%^WHITE%^u%^RED%^n%^WHITE%^d%^YELLOW%^e%^RED%^r%^RESET%^");
   set_obvious_short("%^BOLD%^%^RED%^A steel glaive%^RESET%^");
   set_id(({"scarlet thunder","glaive","polearm"}));
   set_long("%^BOLD%^Attached to a six-foot-long %^BLACK%^duskwood%^WHITE%^ shaft is what appears to be the %^RED%^steel%^WHITE%^ blade of a broadsword. The thick blade is scored with intricate interwoven lines and swirls along the edges.  The %^RED%^red steel %^WHITE%^blade is secured to the %^BLACK%^duskwood %^WHITE%^shaft in three sections.  Braided strips of %^RED%^scarlet%^WHITE%^ and %^RESET%^white%^BOLD%^ cloth entwine around the shaft, creating the handholds for this polearm.%^RESET%^"); 
   set_value(2000);
   set_property("enchantment",3);
   set_lore("The Order of the Scarlet Thunder was a band of assassins that used to control the city of Torm.  Made up mostly of rogues and wizards, the Scarlet Thunder operated out in the open, fearing little.  They earned their name the Scarlet Thunder for their quicky brutal attacks that left large ammounts of blood in their wake.  Soon the people of Torm had enough of these assassins holding control over their city and sought aid from some of the temples in the area.  Under the leadership of Prenius Maximoff, paladin of Kreysneothosies, an army was gathered and marched into Torm to put an end to the assassins once and for all.  Though when they arrived at the mansion the assassins were using as base they found it empty. After that day no one ever heard from the Scarlet Thunder Assassins again. - A History of the Jewel of the Seas, Torm - Grisham Tobias");
   set_property("lore difficulty",16);
   set_hit((:TO,"hitme":));
   set_wield("%^RED%^You can feel the power within the glaive as you grip it.%^RESET%^");
   set_unwield("%^RED%^The feeling of power subsides as you release the glaive.%^RESET%^");
}

int hitme(object targ){
   if(!random(6)){
      tell_object(ETO,"%^RED%^You feel the glaive sink deeply into "+targ->QCN+"'s flesh.%^RESET%^");
      tell_object(targ,"%^RED%^"+ETOQCN+" sinks "+ETO->QP+" glaive deeply into your flesh.%^RESET%^");
      tell_room(EETO,"%^RED%^"+ETOQCN+" sinks "+ETO->QP+" glaive deeply into "+targ->QCN+"'s flesh.%^RESET%^",({ETO,targ}));
      set_property("magic",1);
     	targ->do_damage("torso",random(4)+6);
      remove_property("magic");
      return 1;
   }
   if(!random(10)){
      tell_object(ETO,"%^BOLD%^%^RED%^You spin your glaive deftly, landing several blows onto "+targ->QCN+".%^RESET%^");
      tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" begins to spin "+ETO->QP+" glaive deftly in "+ETO->QP+" hands, landing several blows onto you.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" begins to spin "+ETO->QP+" glaive deftly in "+ETO->QP+" hands, landing several blows onto "+targ->QCN+".%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(3)+5);
      targ->do_damage("torso",random(4)+4);
      ETO->execute_attack();
      return 1;
   }
   return roll_dice(1,4);
}