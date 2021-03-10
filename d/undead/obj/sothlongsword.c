#include <std.h>
inherit "/d/common/obj/weapon/bastard.c";

int counter, i, j;

void create(){
   ::create();
   set_id(({"sword","bastardsword","bastard sword","weapon","Sword","bastard"}));
   set_name("Leyra Uth Matar");
   set_obvious_short("%^BOLD%^%^BLACK%^midnightblack bastard sword%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Soth %^RESET%^%^RED%^family sword%^WHITE%^");
   set_long("This bastard sword is crafted from premium grade %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^ld "+
   "st%^RESET%^ee%^BOLD%^%^BLACK%^l%^RESET%^. Tempering has colored the blade itself in a %^BOLD%^%^BLACK%^shade "+
   "%^RESET%^of %^BOLD%^%^BLACK%^midnight black %^RESET%^except for the edge with seem to shine with "+
   "%^BOLD%^%^RED%^blood-red %^RESET%^color. Along the blade, a fuller is carved to ease the flow of blood. The "+
   "%^BOLD%^%^CYAN%^cr%^WHITE%^o%^CYAN%^ss-g%^WHITE%^u%^CYAN%^ard %^RESET%^is made from a solid piece "+
   "%^BOLD%^%^CYAN%^m%^WHITE%^i%^CYAN%^thr%^WHITE%^i%^CYAN%^l %^RESET%^and besides protecting the wielders hands "+
   "there are sm%^BOLD%^%^BLACK%^a%^RESET%^ll %^BOLD%^%^BLACK%^h%^RESET%^ol%^BOLD%^%^BLACK%^e%^RESET%^s which seem "+
   "to absorb the %^BOLD%^%^RED%^blood %^RESET%^with uncanny efficiency. The %^ORANGE%^hilt %^WHITE%^is %^ORANGE%^woven "+
   "%^WHITE%^with delicate but high quality %^ORANGE%^soft skin %^WHITE%^to ensure perfect grip. At the end a "+
   "%^RED%^l%^BOLD%^a%^RESET%^%^RED%^rge r%^BOLD%^u%^RESET%^%^RED%^by %^WHITE%^is attached as a "+
   "%^RED%^p%^BOLD%^o%^RESET%^%^RED%^mm%^BOLD%^e%^RESET%^%^RED%^l%^WHITE%^, given the sword an %^BOLD%^excellent balance%^RESET%^.\n"
   );
   TO->set_property("enchantment",roll_dice(2,2));
   set_property("lore difficulty",20);
   set_value(5000);
   set_wield((:TO,"wieldit":));
   set_hit((:TO,"hitit":));
   set_property("no alter",1);
   set_unwield((:TO,"unwieldit":));
   set_item_bonus("damage bonus",roll_dice(1,2)+1);
   set_item_bonus("attack bonus",roll_dice(1,2)+1);
   set_lore("The rumors around Lord Soth is many. The one about his sword is a particular terrifying one however. People "+
   "will let of the time, when a mortal woman called Kitiara Uth Matar defeated Lord Soth in a duel and so, bound him to her "+
   "service. This, service did not last forever and on the day that Lord Soth broke free of the oath keeping him to her "+
   "service, Lord Soth swore death to the whole uth Matar bloodline. The first Lord Soth managed to capture was Kiatara "+
   "16 year old daughter, Leyra Uth Matar. She was tortured to the brink of her last breath, broken and defenseless, Lord "+
   "Soth corrupted Leyra's spirit and bound it within this sword. Forcing her to forever be in Lord "+
   "Soth service in his quest to slay every one of the Uth Matar blood-line."
    );
}

int wieldit() {
  
   if((int)ETO->query_level() < 20) {
     tell_object(ETO,"The spirit within the sword refuses you!.");
     return 0;
   }
   if(ETO->query_property("good item")) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^The spirit within the sword snarls at the good items your wearing!%^RESET%^");
     return 0;
   }
   if(ETO->query_property("soth weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"%^BOLD%^%^RED%^The sword spirits senses the each other, and together they tear apart your soul!");
     tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+" gives an unearthly howl of pain as "+ETO->QS+" tries two wield the second weapon.",ETO);
	 ETO->do_damage(ETO->return_taget_limb(),roll_dice(20,20)+150);
     return 0;
   }
   
   tell_object(ETO,"%^BOLD%^%^RED%^As you grip the hilt of the sword, you sence the spirit within!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+"'s sword egde starts glowing as "+ETO->QS+" wields it.%^RESET%^",ETO);
   counter = 0;
   ETO->set_property("evil",1);
   ETO->set_property("soth weapon",1);
   return 1;
}

int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^RED%^The energy of the spirit fades as you unwield the sword.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+"s sword stop glowing at "+ETO->QS+" unwields it.%^RESET%^",ETO);
   ETO->set_property("evil",-1);
   ETO->set_property("soth weapon",-1);
   return 1;
}

int hitit(object ob) {
	
	
 object *goodlies;
 goodlies = ETO->query_attackers();
// int counter, i, j;
 
        if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(ob)) return 1;
        if(random(1000) < 200){
      switch(random(16)){
      case 0..5:
         
            tell_object(ETO,"%^BOLD%^%^RED%^You sword drinks "+ob->QCN+"'s blood!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+"+s sucks the blood from your fresh wound!%^RESET%^");
            tell_room(environment(query_wielded()),"%^RESET%^%^GREEN%^"+ETO->query_cap_name()+"'s sword glows feintly as it strikes "+ob->QCN+"!%^RESET%^",({ETO,ob}));
            ob->do_damage(ob->return_taget_limb(),roll_dice(1,6)+3);
            counter ++;
            break;
         
         case 6..12:
         
            tell_object(ETO,"%^BOLD%^%^CYAN%^You feel the sword drain energy from "+ob->QCN+"!%^RESET%^");
            tell_object(ob,"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+"'s sword leeches a portion of energy from you!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+"'s sword glows bright as it strikes "+ob->QCN+"!%^RESET%^",({ETO,ob}));
            ob->do_damage(ob->return_taget_limb(),roll_dice(1,6)+6);
            counter ++;
			counter ++;
            break;
         
         case 13..15:
			
			if(counter < 4) {
			tell_object(ETO,"%^RESET%^%^RED%^You feel warmth eminating from the hilt of the sword.%^RESET%^");
            tell_object(ob,"%^RESET%^%^RED%^"+ETO->query_cap_name()+"'s sword glows softly as it strikes you!%^RESET%^");
            tell_room(environment(query_wielded()),"%^RESET%^%^RED%^"+ETO->query_cap_name()+"'s sword gloves softly as it drinks "+ob->QCN+"'s blood!%^RESET%^",({ETO,ob}));	
			counter = 0;
			set_property("magic",1);
            ETO->do_damage("torso",roll_dice(5,5)*(-1));
			set_property("magic",-1);			
			}
			
            if(counter > 5 && counter < 9) {
            tell_object(ETO,"%^BOLD%^%^RED%^The sword releases it's spirit upon "+ob->QCN+"%^RESET%^");
            tell_object(ob,"%^BOLD%^%^RED%^"+ETO->QCN+"'s sword releases it's spirit upon you!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETO->QCN+"'s releases it's spirit upon "+ob->QCN+"!%^RESET%^",({ETO,ob}));
            counter = 0;
			set_property("magic",1);
            ob->do_damage(ob->return_taget_limb(),roll_dice(2,6)+10);
			ob->set_paralyzed(roll_dice(2,10)+5,"Your body will not move under the spirit's posession!");
			set_property("magic",-1);
			}
			
			if(counter > 10) {
			tell_object(ETO,"%^BOLD%^%^YELLOW%^The spirit of your sword releases a soul-shattering howl!");	
			tell_room(EETO,"%^BOLD%^%^YELLOW%^The spirit in "+ETO->QCN+"'s sword releases a soul-shattering howl!",({ob,ETO}));
			j = sizeof(goodlies);
			for(i=0;i<j;i++){
				counter = 0;
				tell_object(goodlies[i],"%^BOLD%^%^YELLOW%^The spirit in "+ETO->QCN+"'s sword releases a soul-shattering howl!");
				set_property("magic",1);
				goodlies[i]->do_damage(goodlies[i]->return_taget_limb(),roll_dice(3,10)+20);
				set_property("magic",-1);
			}
				
			}
			
			
			
            break;
	  }
         
return 1;

}
}
