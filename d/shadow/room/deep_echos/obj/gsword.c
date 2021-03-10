// really big sword for giants
#include <std.h>
inherit "/d/common/obj/weapon/giant_bastard.c";

void create() {
    ::create();
   set_id(({"sword","giant sword"}));
   set_name("%^BOLD%^%^WHITE%^huge sword%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A huge sword%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Giant Sword%^RESET%^");
   set_long("%^BOLD%^This massive sword looks terrifying.  "+
    "It is big enough to crush a vicious monster.  "+
    "The blade is made of metal with strengthening"+
	" lines of %^CYAN%^diamond%^WHITE%^ on it.  The hilt is huge and "+
	"has a large %^CYAN%^shimmering gem%^WHITE%^ on the end to "+
	"counter balance it%^RESET%^.");
	set_property("lore difficulty",15);
	set_lore("These swords were actually created by "+
    "gnomes to equip on their constructs."+
    "  The large creations could cut through "+
    "most everything in their way."	);
   set("value",1000);
   set_property("enchantment",2);  
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((int)ETO->query_level() < 10 ) {
      tell_object(ETO,"%^RED%^The sword causes your muscles to spasm!");
      ETO->do_damage("torso",random(25)+25);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
   return 0;
   }
      tell_room(environment(ETO),"%^CYAN%^The sword vibrates as "
	   +ETOQCN+" wields it.",ETO);
      tell_object(ETO,"%^CYAN%^The sword vibrates as you wield it.");
      return 1;
}
int unwield_func(){
   tell_room(environment(ETO),"%^CYAN%^The sword of "+ETOQCN+" stops vibrating.",ETO);
    tell_object(ETO,"%^CYAN%^The sword returns to normal when unwielded.");
         
                return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(400) < 100){
      switch(random(5)){
         case 0..2:
            tell_room(environment(ETO),"%^RED%^The sword decimates "
			  +target->query_cap_name()+" shaking their whole body.",({target,ETO}));
              tell_object(ETO,"%^RED%^The vibrating sword decimates "+target->query_cap_name()+
              " shaking them violently.",target);
            tell_object(target, "%^RED%^The sword wielded by "
			  +ETO->query_cap_name()+" slices deep and causes"+
			  " your whole body to shake!");
              return roll_dice(1,8)+2;

           case 3:
            tell_room(environment(ETO),"%^RED%^The lines in the blade glow.",({target,ETO}));
            tell_object(ETO,"%^RED%^The lines in the blade glow as the sword sinks into "+
              target->query_cap_name()+"!");
            tell_object(target, "%^RED%^The lines in the blade glow"+
			  " as it sinks deep into you!");
            return roll_dice(1,8)+2;
         case 4:
            tell_room(environment(ETO),"%^RED%^The sword's powerful"+
			 " strike sends "+target->query_cap_name()+" to the ground."
			 ,({target,ETO}));
            tell_object(ETO,"%^RED%^A powerful strike by "+target->query_cap_name()+
			" sends them to the ground.",target);
            tell_object(target, "%^RED%^"+ETO->query_cap_name()+"'s slash"+
			  " drives you to the ground!");
            target->set_tripped(1,"%^RED%^You try to get up, but the world is spinning.");
            return roll_dice(2,4)+1;
      }
   }
}
