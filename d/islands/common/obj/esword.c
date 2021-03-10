#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/scimitar";

int hit_func, wield_func, unwield_func, elec;

void create() {
   ::create();
   set_id(({ "scimitar","sword","scimitar sword","sword of the elements","element sword","scimitar of the elements","element scimitar"}));
   set_name("%^RESET%^%^CYAN%^Scimitar of the elements%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Scimitar of the elements%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A beautifully crafted scimitar%^RESET%^");
   set_long("This beautifully crafted scimitar could have been made by nothing less than a %^MAGENTA%^master %^RESET%^of his"
" trade.  The %^BOLD%^%^WHITE%^elongated blade %^RESET%^has an %^CYAN%^elegant curve %^RESET%^that gives"
" it a smooth, sexy appearance, while the %^BOLD%^%^WHITE%^edge %^RESET%^itself"
" has been honed to be so extremely %^BOLD%^%^BLACK%^sharp %^RESET%^that this sword is nothing less than deadly."
"  The %^BOLD%^%^WHITE%^blade %^RESET%^and %^BOLD%^%^WHITE%^hilt assembly %^RESET%^have been crafted so finely that"
" they balance each other perfectly, granting the wielder a wide range of easy movement.  Softly"
" %^CYAN%^gl%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ng runes %^RESET%^shift in shape along"
" the edge of the fuller, their ever changing %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^h%^BLUE%^a%^BOLD%^%^BLUE%^d"
"%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^s %^RESET%^of %^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^q%^BOLD%^%^CYAN%^ua"
" %^RESET%^looking much like %^BOLD%^%^WHITE%^sh%^RESET%^i%^BOLD%^%^WHITE%^ft%^RESET%^i%^BOLD%^%^WHITE%^ng"
" %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^at%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^s %^RESET%^against the"
" cool %^BOLD%^%^WHITE%^silver %^RESET%^of the %^BOLD%^%^WHITE%^blade.  %^RESET%^The hilt itself consists of an"
" intricate %^BOLD%^%^WHITE%^platinum guardpiece %^RESET%^whose curving ~S~ shape is reminiscent of the %^BOLD%^%^WHITE%^turning w%^RESET%^%^CYAN%^i%^BOLD%^%^WHITE%^nds%^RESET%^, a %^ORANGE%^grip %^RESET%^made of %^ORANGE%^leather"
" %^RESET%^that is so %^ORANGE%^soft %^RESET%^and %^ORANGE%^supple %^RESET%^that it has the feel of the life-giving"
" %^ORANGE%^e%^RESET%^a%^ORANGE%^r%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h%^RESET%^, and a"
" %^RED%^j%^RED%^e%^YELLOW%^w%^RESET%^%^ORANGE%^e%^CYAN%^l%^BOLD%^%^CYAN%^l%^RED%^e%^RESET%^%^BLUE%^d"
" %^RESET%^pommel that reflects the %^YELLOW%^light %^RESET%^in a"
" %^RED%^f%^BOLD%^%^RED%^ie%^RESET%^%^RED%^r%^BOLD%^%^RED%^y %^RESET%^display of %^YELLOW%^c%^RED%^o%^BLUE%^l%^CYAN%^o%^%^MAGENTA%^r.%^RESET%^");
   set("value",15000);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("attack bonus",3);
   set_item_bonus("damage bonus",3);
   set_item_bonus("caster level",2);
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   elec = 0;
}

int wield_func(){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"You can't get a proper grip on the weapon.");
     return 0;
   }
   tell_object(ETO,"%^YELLOW%^The energy of the elements surge through you as the sword in your hand comes to life!%^RESET%^");
   tell_room(environment(ETO),"%^CYAN%^"+ETO->query_cap_name()+"'s sword seems to surge with life as "+ETO->query_subjective()+" takes command of the mighty scimitar!%^RESET%^",ETO);
   return 1;
}

int unwield_func(){
   if(elec == 1){  
      tell_object(ETO,"%^YELLOW%^The surge of electrical energy within the sword dies down as you unwield it.%^RESET%^");
      tell_room(environment(ETO),"%^YELLOW%^The surge of energy within "+ETO->query_cap_name()+"'s sword dies down as "+ETO->query_subjective()+" unwields it.%^RESET%^",ETO);
      elec = 0;
   }
   else{
      tell_object(ETO,"%^CYAN%^You feel a sense of disappointment as you unwield the sword and feel the absence of energy it gave you.%^RESET%^");
      tell_room(environment(ETO),"%^CYAN%^The glowing runes of "+ETO->query_cap_name()+"'s sword ebb and finally die down as "+ETO->query_subjective()+" unwields the sword.%^RESET%^",ETO);
   }
      return 1;
}

int hit_func(object target) {
   object ob;
   if(!objectp(target)) return 0;
   if(random(1000) < 200){
      switch(random(20)){
         case 0..4:
  	      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" tightens "+ETO->query_possessive()+" grip on the hilt of the sword and hits "+target->query_cap_name()+" with a devastating blow!",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^ORANGE%^%^You tighten your grip on the smooth leather of the hilt as you hit "+target->query_cap_name()+" with a devastating blow!%^RESET%^",({environment(ETO),target}));
            tell_object(target, "%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" tightens the grip on "+ETO->query_possessive()+" sword and hits you with a devestating blow!%^RESET%^",({environment(ETO),ETO}));
		  return roll_dice(2,8)+3;
              break;
         case 5:
            tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETO->query_cap_name()+" strikes "+target->query_cap_name()+" with earthshaking force that knocks "+target->query_objective()+" off of "+target->query_possessive()+" feet!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^ORANGE%^The grip of the sword lends you strength as you hit "+target->query_cap_name()+" with earthshaking force that knocks "+target->query_objective()+" off of "+target->query_possessive()+" feet!%^RESET%^",({environment(ETO),target}));
            tell_object(target,"%^RESET%^%^ORANGE%^The sword in "+ETO->query_cap_name()+"'s hand hits you so hard that it knocks you off of your feet!%^RESET%^",({environment(ETO),ETO}));
		  return roll_dice(2,10)+5;
              target->set_paralyzed(20,"You are still trying to stand!");
              break;
 	   case 6..10:
            ETO->execute_attack();
  	      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The platinum hilt of "+ETO->query_cap_name()+"'s sword begins to glow as "+ETO->query_subjective()+" picks up the speed of the winds and whirls the sword quickly around to strike "+target->query_cap_name()+" again!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^The hilt of your sword begins to glow slightly as you pick up the speed of the winds and whirl the sword around to hit "+target->query_cap_name()+" again!%^RESET%^",({environment(ETO),target}));
            tell_object(target, "%^BOLD%^%^WHITE%^The hilt of "+ETO->query_cap_name()+"'s sword begins to glow as "+ETO->query_subjective()+" spins the sword around to attack you again!%^RESET%^",({environment(ETO),ETO}));
		  return roll_dice(2,8)+1;
              break;
         case 11:
            tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETO->query_cap_name()+" brings the sword down in a graceful arc, the pommel catches the %^YELLOW%^light %^WHITE%^and reflects it at "+target->query_cap_name()+" in a %^YELLOW%^dazzling %^WHITE%^display of %^YELLOW%^blinding %^WHITE%^light!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^As you swing the sword down in a graceful arc, the pommel catches the %^YELLOW%^light %^WHITE%^and reflects it at "+target->query_cap_name()+" in a %^YELLOW%^blinding flash %^WHITE%^of %^YELLOW%^light!%^RESET%^",({environment(ETO),target}));
            tell_object(target, "%^BOLD%^%^WHITE%^As "+ETO->query_cap_name()+" brings the sword down in a graceful arc, the pommel catches the %^YELLOW%^light %^WHITE%^and reflects it at you in a %^YELLOW%^blinding flash %^WHITE%^of %^YELLOW%^light!",({environment(ETO),ETO}));
            target->set_paralyzed(20,"You are trying to get to your feet.");
            if(!random(3)) target->set_blind(1);
            else target->set_paralyzed(3+random(4), "%^YELLOW%^You are still trying to recover from the blinding light!");
            break;   
         case 12..14:
  	      tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The runes of "+ETO->query_cap_name()+"'s sword begin to shift in form as a soothing flow of energy pulses into "+ETO->query_objective()+".",ETO);
            tell_object(ETO,"%^BOLD%^%^CYAN%^The runes of your sword begin to shift in form as a soothing flow of energy pulses into you.%^RESET%^",({environment(ETO),target}));
            ETO->do_damage("torso",-(random(10)+20));
            break;  
 	   case 15..19:
            if (environment(ETO)->query_property("indoors")&& elec == 0) {
  	               tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+"'s sword seems to suck up the energy from around it before firing it violently towards "+target->query_cap_name()+"!",({target,ETO}));
                     tell_object(ETO,"%^YELLOW%^Your sword seems to suck up the energy from around it before firing it violently towards "+target->query_cap_name()+"!%^RESET%^",({environment(ETO),target}));
                      tell_object(target, "%^YELLOW%^"+ETO->query_cap_name()+"'s sword seems to suck up the energy around it before firing it violently towards you!%^RESET%^",({environment(ETO),ETO}));
		          return roll_dice(1,10)+1;
            }
            else if (!environment(ETO)->query_property("indoors")&& elec == 0) {
  	         tell_room(environment(ETO),"%^RESET%^CYAN%^The runes of "+ETO->query_cap_name()+"'s sword begin to shift into a liquid form as the %^BOLD%^%^BLACK%^clouds %^RESET%^%^CYAN%^above begin to swirl and take form, sending a %^YELLOW%^bolt of lightning %^RESET%^%^CYAN%^down into the sword, %^YELLOW%^electrifying %^RESET%^%^CYAN%^it!",ETO);
               tell_object(ETO,"%^RESET%^%^CYAN%^The runes of your sword begin to shift into a liquid form as the %^BOLD%^%^BLACK%^clouds %^RESET%^%^CYAN%^above begin to swirl and take form, sending a %^YELLOW%^bolt of lightning %^RESET%^%^CYAN%^into the sword, %^YELLOW%^electrifying %^RESET%^it!",({environment(ETO),target}));
		   elec = 1;
            }
            else{
               switch(random(3)){
                  case 0:
  	               tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+"'s sword crackles with electrical energy as it strikes "+target->query_cap_name()+"!",({target,ETO}));
                     tell_object(ETO,"%^YELLOW%^Your sword crackles with electrical energy as it hits "+target->query_cap_name()+"!%^RESET%^",({environment(ETO),target}));
                      tell_object(target, "%^YELLOW%^"+ETO->query_cap_name()+"'s sword crackles with electrical energy as it strikes you!%^RESET%^",({environment(ETO),ETO}));
		          return roll_dice(1,10)+1;
                   break;
                   case 1:
  	                tell_room(environment(ETO),"%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^can be heard as "+ETO->query_cap_name()+"'s sword strikes "+target->query_cap_name()+", causing small surges of electrical energy to dance along the blade!",({target,ETO}));
                      tell_object(ETO,"%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^can be heard as you strike "+target->query_cap_name()+" with the sword, causing small surges of electrical energy to dance along the length of the blade!%^RESET%^",({environment(ETO),target}));
                       tell_object(target, "%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^ can be heard coming from "+ETO->query_cap_name()+"'s sword as it strikes you, causing small surges of electrical energy to dance along the length of the blade!%^RESET%^",({environment(ETO),ETO}));
		           return roll_dice(1,10)+1;
                    break;
                   case 2:
  	                tell_room(environment(ETO),"%^YELLOW%^The pent up energy in "+ETO->query_cap_name()+"'s sword comes to a crest at the tip of the blade before shooting out at "+target->query_cap_name()+" in a forceful explosion of power before the sword once again goes quiet!",({target,ETO}));
                      tell_object(ETO,"%^YELLOW%^The pent up energy in the sword seems to gather at the tip of the blade and suddenly shoots out at "+target->query_cap_name()+" in a forceful explosion of power before the sword once again goes quiet!%^RESET%^",({environment(ETO),target}));
                       tell_object(target, "%^YELLOW%^The pent up energy of "+ETO->query_cap_name()+"'s sword seems to crest at the tip of the sword before shooting out towards you in a forceful explosion of power before the blade once again goes quiet!%^RESET%^",({environment(ETO),ETO}));
                       elec = 0;
		           return roll_dice(3,10)+1;
                    break;
            }
         return 1;
         } 
      }
   }
}

