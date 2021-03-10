//boots for Kua-Toa.  Circe 1/21/05
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_id(({"boots","hide boots","elf-hide boots","elfskin boots","skin boots"}));
   set_name("hide boots");
   set_obvious_short("%^ORANGE%^hide boots%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Elfskin Boots%^RESET%^");
   set_long("Made of an unusual leather, these boots have a deep "+
      "%^BOLD%^%^BLACK%^grayish cast %^RESET%^to them.  It seems, "+
      "though, that the color is from the tanning and dying process "+
      "rather than the natural color of the hide.  The boots are "+
      "soft, supple, and rather tall, lacing all the way to the "+
      "wearer's knees.  They have a thick sole of bendable leather, "+
      "making them quite good for sneaking around places unheard "+
      "although they wouldn't offer the best protection while "+
      "journeying through rocky areas.");
   set_weight(2);
   set_property("enchantment",random(2));
   set_value(350);
   set_lore("These boots are crafted by the kuo-toa from elf skin.  "+
      "Elves are particularly valued to the kuo-toa, for they feel "+
      "their mysterious goddess Blibdoolpoolp prizes sacrifices of "+
      "these pure hearts the most.  Sages speculate that this might "+
      "be partially based in religion - and partially based in the "+
      "working relationship the kuo-toa have with the drow, who "+
      "hate their surface kindred.  The two groups are far from "+
      "friendly, but they often work to mutual benefit.  The elven "+
      "affinity for magic - and their supple skin, which makes "+
      "fantastic boots - makes them prime targets for kuo-toan "+
      "sacrifices.");
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_property("lore difficulty",12);
   set_wear((:TO,"wear_me":));
   set_remove((:TO,"unwear_me":));
}

int wear_me(){
   string myrace = ETO->query_race();
   int align = ETO->query_alignment();
   if(myrace == "elf"){
      switch(align){
         case 3: case 6: case 9:
            tell_object(ETO,"You smirk as you wear the boots, amused "+
               "by the idiotic elf who was inept enough to have "+
               "himself skinned.");
            tell_room(EETO,""+ETOQCN+" smirks as "+ETO->QS+" laces "+
               "the boots.",ETO);
            break;
         default:
            tell_object(ETO,"The elven soul slain by the kuo-toa screams "+
               "in agony as one of its kindred seeks to wear the boots "+
               "made of its hide.");
            tell_room(EETO,"A soft sigh escapes as "+ETOQCN+" wears "+
               "the boots.",ETO);
            break;
      }
      return 1;
   }
   if(myrace == "drow"){
      tell_object(ETO,"You smile with glee as you slip on the boots "+
         "made of the skin of those sickening surface elves.");
      tell_room(EETO,""+ETOQCN+" smirks as "+ETO->QS+" laces "+
         "the boots.",ETO);
      return 1;
   }
   tell_object(ETO,"The supple boots fit your feet perfectly.");
   tell_room(EETO,""+ETOQCN+" laces a pair of supple hide boots.",ETO);
   return 1;
}

int unwear_me(){
   string myrace = ETO->query_race();
   int align = ETO->query_alignment();
   if(myrace == "elf"){
      if(align == 1 || align == 2 || align == 4 || align == 5 || align == 7 || align == 8){
         tell_object(ETO,"You hear the whispered sobbing of the "+
            "shattered elf in your mind as you remove the boots.");
         tell_room(EETO,""+ETOQCN+" unlaces the boots with a "+
            "somber expression.",ETO);
         return 1;
      }
   }
   tell_object(ETO,"You unlace the boots and kick them off.");
   tell_room(EETO,""+ETOQCN+" unlaces a pair of supple hide boots.",ETO);
   return 1;
}