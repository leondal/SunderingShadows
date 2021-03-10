#include <std.h>
inherit "/d/common/obj/weapon/mace.c";

int FLAG;

void create()
{
   ::create();
   set_name("tomb jade mace");
   set_short("%^RESET%^%^ORANGE%^Tomb Jade Mace%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A tomb jade mace%^RESET%^");
   set_id(({"mace","tomb jade mace","jade mace"}));
   set_long("%^RESET%^The head of this heavy mace is made "+
	"from a solid chunk of %^ORANGE%^tomb jade%^RESET%^. "+
	" The %^ORANGE%^tomb jade%^RESET%^ has been sculpted "+
	"and shaped in a rounded cylinder.  The %^ORANGE%^dark"+
	" orange%^RESET%^ and %^RED%^reddish%^RESET%^ hues of "+
	"the %^ORANGE%^tomb jade%^RESET%^ contrast with the "+
	"%^BOLD%^%^WHITE%^silver%^RESET%^ shaft of the mace.  "+
	"Carved with a decorative %^RED%^geometrical%^RESET%^ "+
	"pattern, the shaft of the mace is quite ornate.  "+
	"Braided strips of %^ORANGE%^orange%^RESET%^ and "+
	"%^BOLD%^%^BLACK%^gray%^RESET%^ leather create a "+
	"hand hold for the mace.  A strip of %^ORANGE%^orange"+
	" %^RESET%^leather has been looped around the end of "+
	"the mace, allowing one to slip it around their wrist.");
   set_lore("The Tomb Jade Mace is created by priests of "+
	"Kelemvor to aid in them as they battle the undead in "+
	"the world.  The head of the mace is crafted from jade "+
	"that has been buried in the earth, turning a dark orange "+
	"and reddish hue over time.  Religious lore claims that "+
	"undead creatures can't handle the feel of tomb jade, or "+
	"silver.  It is not uncommon to see even a senior member "+
	"of the Lord of the Dead's church with a tomb jade mace.");
   set_property("lore",9);
   set_item_bonus("negative energy resistance", 10);
   set_value(800);
   set_hit((:TO,"hitme":));
   set_property("enchantment",3);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
}

int wieldme(){
   if(!ETO->is_class("cleric")) {
      if((string)ETO->query_diety("kelemvor")) {
         FLAG = 1;
         tell_object(ETO,"%^BOLD%^The tomb jade mace feels light and smooth in your hands.");
         return 1;
      }
   }
   if(ETO->is_class("cleric")) {
      FLAG = 1;
      tell_object(ETO,"%^BOLD%^The tomb jade mace feels light in your hands.");
      return 1;
   }
   else {
      FLAG = 0;
      tell_object(ETO,"The mace feels rather heavy to you.");
      return 1;
   }
}

int removeme()
{
   if(FLAG == 1) {
      tell_object(ETO,"You set aside the tomb jade mace for now.");
      FLAG = 0;
      return 1;
   }
   else {
      tell_object(ETO,"Your arm aches as you release the mace, wow that thing is heavy.");
      return 1;
   }
}

int hitme(object targ)
{
   if(FLAG != 1) return 1;
   if(!random(8)) {
      tell_object(targ,"%^ORANGE%^You feel a chill travel through"+
	" your soul as "+ETO->QCN+"'s mace smashes into you.");
      tell_object(ETO,"%^ORANGE%^You slam mace into "+targ->QCN+"!");
      tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+" "+
	"smashes "+ETO->QP+"  mace into "+targ->QCN+".",({ETO,targ}));
      targ->do_damage("torso",random(5)+4);
      return 1;
   }
   if(!random(15)) {
     tell_object(targ,"%^ORANGE%^"+ETO->QCN+"'s mace"+
     " slams into you with stunning force, knocking you off balance!");
     tell_object(ETO,"%^ORANGE%^You slam your mace into "+targ->QCN+""+
     " with stunning force, knocking "+targ->QO+" off"+
     " balance!");
     tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+""+
     " slams "+ETO->QP+" hammer into "+targ->QCN+""+
     " with stunning force, knocking "+targ->QO+" off"+
     " balance!",({ETO,targ}));
     targ->do_damage("torso",random(10)+6);
     targ->set_tripped(1,"You're still recovering from that last hit!");
     return 1;
   }
   return random(4)+1;
}
