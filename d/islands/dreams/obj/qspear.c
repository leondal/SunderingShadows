//updated by ~Circe~ 10/5/19 to current code and to remove references to old gods
#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";

void create(){
   ::create();
   set_name("quartz spear");
   set_short("%^BOLD%^%^WHITE%^S%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^l%^RESET%^i%^BOLD%^g%^RESET%^h%^BOLD%^t%^BLUE%^ Spear%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A %^BLUE%^blue%^WHITE%^ quartz tipped spear%^RESET%^");
   set_id(({"spear","quartz spear","quartz-tipped spear","medium spear","starlight spear"}));
   set_long("%^CYAN%^This spear has a shaft that is made from sturdy %^RESET%^pale ironwood%^CYAN%^ that has been smoothly polished. The head of the spear has been encased with %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^ and has a %^BLUE%^blue quartz%^CYAN%^ tip that looks quite sharp and deadly. A large five-pointed star is cut into either side of the silver, letting the %^BOLD%^%^BLUE%^blue quartz%^RESET%^%^CYAN%^ shine through. Within the %^BLUE%^dark blue%^CYAN%^ quartz tip the faint glimmer of motes of %^BOLD%^%^WHITE%^l%^RESET%^i%^BOLD%^g%^RESET%^h%^BOLD%^t%^RESET%^%^CYAN%^ can be seen.%^RESET%^");
   set_lore("The faith of several deities - notably Lysara and Kismet - have ties to the stars.  The Starlight Spear was in fact created and enchanted by a wizard priest of Kismet's faith by the name of Lancome Thunderfalls.  Lancome created the spear for his close friend Liam Korbat, a ranger in the service of Lysara.  Lancome is said to have infused the essence of a falling star within the blue quartz tip of the spear, which helps fuel its power. - Starlight Starbright: A History of Kismet's and Lysara's Connections - Silverstar Enaliana Gelter");
   set_property("lore difficulty",15);
   set_value(2000);
   set_hit((:TO,"hitme":));
   set_property("enchantment",3);
}

int hitme(object targ){
   if(!objectp(targ) || !objectp(ETO) || !objectp(TO)) return 1;
   targ=ETO->query_current_attacker();
   if(!random(8)){
      tell_object(ETO,"%^BOLD%^You thrust the tip of the spear into "+targ->QCN+".%^RESET%^");
     	tell_object(targ,"%^BOLD%^"+ETOQCN+" thrusts the quartz tip of "+ETO->QP+" spear into you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" thrusts the quartz tip of "+ETO->QP+" spear into "+targ->QCN+".%^RESET%^",({ETO,targ}));
      targ->do_damage("torso",random(11)+10);
      return 1;
   }
   if(!random(13)){
      tell_object(ETO,"%^BOLD%^%^BLUE%^You skillfully whip the spear about and watch "+targ->QCN+"'s eyes bulge as you thrust the quartz tip deeply into "+targ->QP+" gut.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" quickly brings "+ETO->QP+" spear about and thrusts the quartz tip deep into your gut!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" quickly brings "+ETO->QP+" spear about and thrusts the quartz tip deep into "+targ->QCN+"'s gut!%^RESET%^",({ETO,targ}));
     	set_property("magic",1);
      targ->do_damage("torso",random(16)+10);
      if(!targ->query_paralyzed()) {
         targ->set_paralyzed(4,"%^CYAN%^You're recovering from a spear being thrust into your stomach!%^RESET%^");
      }
      remove_property("magic");
     	return 1;
   }
}