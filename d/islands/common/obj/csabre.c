#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

int counter;

void create(){
	::create();
	set_name("crystal sabre");
	set_id(({ "sabre", "crystal sabre", "quicksilver", "sword", "weapon" }));
	set_short("%^BOLD%^%^WHITE%^Qui%^RESET%^ck%^BOLD%^%^WHITE%^sil%^RESET%^ver");
	set_obvious_short("A %^BOLD%^%^CYAN%^cry%^RESET%^st%^BOLD%^%^CYAN%^al %^RESET%^sabre");
	set_long(
"%^BOLD%^%^CYAN%^This beautiful crystal bladed weapon is truly exquisite. The sabre's blade is made of solid crystal which has been sharpened to a fine edge."+
" The pommel of the sword looks to be connected to the blade, as if it was a large piece of crystal which has a crosspiece and handle fused around it. The pommel is in the image of a carved %^RESET%^%^ORANGE%^horse%^BOLD%^%^CYAN%^."+
" The hilt of the blade is made out of a smooth %^BOLD%^%^WHITE%^mi%^RESET%^thr%^BOLD%^%^WHITE%^il %^BOLD%^%^CYAN%^metal."+
" Light and balanced, the sabre's handle is also made from solid mithril with the pommel of the blade extending from the bottom. The handle is wrapped in a rough %^BOLD%^%^GREEN%^skin%^BOLD%^%^CYAN%^ of some kind which allows for a stronger grip."
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^Fast as ye maybe - Quicksilver will always bring the wrath of justice to the miscreants%^RESET%^

AVATAR
	);
    set("langage","common");	
    set_hit((:TO,"hit":));
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
	set_value(10000);
	set_item_bonus("magic resistance",1);
	set_item_bonus("attack bonus",2);
	set_item_bonus("damage bonus",2);
	set_lore(
@AVATAR
The crystal sabre's origin is well known. The weapon was made for the leader of the Paladin Order of Tyr in southern Azha. Winning many battles, Sir Kristan of Poeral (later known as Lord Kristan) claimed his lord Tyr and the sword combined with his courage helped win the day. When the Paladin died he passed it on to his bretheren.

AVATAR
	);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   counter = 0;
}

int unwield_func(){
	tell_object(ETO,"The balance of the blade is lost as you unwield the weapon.");
      //ETO->set_property("magic resistance", -10);	
     return 1;
}

int wield_func(string str){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The boots seem not to fit you.");
     return 0;
   }
   //ETO->set_property("magic resistance", 10);
   return 1;
}

int hit(object targ){
      if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
      if(random(1000) < 200){
      switch(random(9)){
         case 0:
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" cuts effortlessly through the target!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^You cut through your target with ease!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" easily finds the soft spot in your armor for a critical blow!%^RESET%^");
            targ->do_damage("torso",roll_dice(3,4)+2);
      counter++;
            break;
          case 1:
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" jabs the sword into "+targ->QCN+"'s torso and twists the blade before pulling out!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^You jab the sabre into your opponent and twist the handle before pulling out!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" jabs the sword into your torso and twists it before pulling out!%^RESET%^");
            targ->do_damage("torso",roll_dice(3,5)+3);
      counter++;
            break;
          case 2..4:
        if(counter > 4) {
            tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" moves quicker than the eye!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^CYAN%^Suddenly you feel a quickness come over your body!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" move quicker than the eye!%^RESET%^");
        counter = 0;
            ETO->execute_attack();
            ETO->execute_attack();
            ETO->execute_attack();
	}else{
        tell_room(environment(query_wielded()),"%^RESET%^%^MAGENTA%^"+ETOQCN+" deftly performs a quick strike!%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^RESET%^%^MAGENTA%^You deftly perform a quick strike!%^RESET%^");
        tell_object(targ,"%^RESET%^%^MAGENTA%^"+ETOQCN+" deftly perform a quick strike!%^RESET%^");
            targ->do_damage("torso",roll_dice(3,5)+3);
	counter++;
	}
            break;
          case 5:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" elbows "+targ->QCN+" in the nose then brings the blade of the sabre back across "+targ->QCN+"'s eyes!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You elbow your opponent in the nose then bring the sword back across the eyes!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" elbows you in the nose then brings the sword back across your eyes!%^RESET%^");
            targ->set_paralyzed(7,"%^BOLD%^%^RED%^You are trying to wipe the blood from your eyes!%^RESET%^");
            targ->do_damage("torso",roll_dice(1,10));
	counter++;
            break;
          case 6:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+"'s sabre glows blue as it makes contact with its target!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLUE%^The sabre glows a bright blue upon striking the foe!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s sabre glows blue as it makes contact with you!%^RESET%^");
            targ->do_damage("torso",roll_dice(2,10));
	counter++;
            break;
          case 7:
            tell_room(environment(query_wielded()),"%^BOLD%^%^YELLOW%^"+ETOQCN+"'s sword burns into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^YELLOW%^An inner force from the sword warms your whole body!");
            tell_object(targ,"%^BOLD%^%^YELLOW%^"+ETOQCN+"'s sword burns into you, seemingly drawing some of your power away!%^RESET%^");
            set_property("magic",1);
            ETO->add_hp(random(10)+10);
            remove_property("magic");
	counter++;
            break;
          case 8:
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" stabs "+targ->QCN+" in the foot and extracts the blade to slash "+targ->QO+" across the stomach!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^ You stab "+targ->QCN+" in the foot, then quickly extract the blade to slash "+targ->QO+" across the stomach!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" stabs you in the foot and then quickly extracts the blade to slash you across the stomach!%^RESET%^");
            targ->do_damage("torso",roll_dice(3,5)+3);
	counter++;
            break;
      }
   return 1;
   }
}
