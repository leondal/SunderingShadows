//shield for Kua-Toa.  Circe 9/23/04
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_id(({"shield","sticky shield","bone shield","kuo-toa shield","glutinous shield"}));
   set_name("glutinous shield");
   set_obvious_short("%^BOLD%^A bone shield%^RESET%^");
   set_short("%^BOLD%^Glutinous Shield%^RESET%^");
   set_long("This shield has been formed of what looks to be the "+
      "massive %^BOLD%^shoulderblade %^RESET%^of some %^RED%^great "+
      "beast%^RESET%^.  The unusual material has given it a likewise "+
      "abnormal shape.  Resembling a stylized %^BOLD%^triangle %^RESET%^"+
      "with curving edges, the shield has been %^CYAN%^notched %^RESET%^"+
      "on all sides.  A series of %^ORANGE%^leather straps %^RESET%^"+
      "on the back provides the means to wear the shield, and a "+
      "strange %^GREEN%^sticky substance %^RESET%^seems to coat its "+
      "whole front surface.  An odd %^CYAN%^odor %^RESET%^rises "+
      "from the shield.");
   set_weight(10);
   set_property("enchantment",random(2)+1);
   set_value(75);
   set_lore("The bone for this shield was taken from a deep roethe, "+
      "a creature something like a cow.  The shoulderblade of the "+
      "roethe has a unique construction that makes it both rather "+
      "light and extremely hard at the same time.  The somewhat "+
      "smelly odor rising from the shield is connected with the "+
      "sticky substance coating its surface.  The adhesive is "+
      "made from a mixture of the kuo-toa's body oil combined with "+
      "various other materials known only to the kuo-toas.  Whole "+
      "bands of kuo-toas have been known to use such shields, but "+
      "luckily this seems to be rare.");
   set_type("shield");
   set_limbs(({"right hand"}));
   set_property("lore difficulty",12);
   set_struck((:TO,"strike_func":));
}

int strike_func(int damage, object what, object who){
   int flag,i;
   object *inven;
   flag = -1;
   who = ETO->query_current_attacker();
   if(!random(3)){
     inven = all_inventory(who);
     for (i=0;i<sizeof(inven);i++) {
       if(inven[i]->query_wielded()) {
         if (inven[i]->query_property("enchantment") && inven[i]->query_property("enchantment") >= 0) {
           flag = i; }
         if (!inven[i]->query_property("enchantment")) { flag = i; }
         }
      }
      if(flag != -1){
         tell_object(ETO,"%^CYAN%^As "+who->QCN+" strikes your shield, "+
            ""+who->QP+" weapon sticks to it!");
         tell_object(who,"%^CYAN%^As you strike "+ETOQCN+"'s shield, "+
            "you lurch forward as your weapon sticks fast and you lose it!"+
            "%^RESET%^");
         tell_room(EETO,"%^CYAN%^"+who->QCN+" strikes "+ETOQCN+"'s shield "+
            "and loses "+who->QP+" grip on "+who->QP+" weapon!"+
            "%^RESET%^",({ETO,who}));
         inven[flag]->__ActuallyUnwield();
      }else{
         tell_object(ETO,"%^CYAN%^"+who->QCN+" strikes your shield bare-"+
            "handed, and "+who->QP+" hand sticks!%^RESET%^");
         tell_object(who,"%^CYAN%^You strike "+ETOQCN+"'s shield "+
            "bare-handed and feel naseous as skin rips when you try "+
            "to pull it back!");
         tell_room(EETO,"%^CYAN%^"+who->QCN+" strikes "+ETOQCN+"'s "+
            "shield bare-handed and flesh rips when "+who->QS+" tries "+
            "to pull "+who->QP+" hand back!",({ETO,who}));
         who->do_damage("left hand",roll_dice(2,8));
      }
      return 0;
   }
}
