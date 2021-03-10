//Essy: Nov 2016
#include <std.h>
#include "../undead.h";
inherit "/d/common/obj/lrweapon/longbow.c";
int counter;

void create() {
   	::create();
   	set_name("Asp Bow");
   	set_short("%^GREEN%^Longbow of the Asp%^RESET%^");
	set_obvious_short("%^GREEN%^snake-like longbow%^RESET%^");
   	set_id(({"long bow","bow","longbow","war bow","aspbow", "Asp", "asp","weapon","Weapon"}));
   	set_long("%^GREEN%^This bow seem to be carved out of one piece of %^BOLD%^as%^RESET%^%^ORANGE%^p "+
	"%^BOLD%^%^GREEN%^w%^RESET%^%^ORANGE%^oo%^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^. The %^BOLD%^w%^RESET%^%^ORANGE%^oo%^BOLD%^%^GREEN%^d "+
	"%^RESET%^%^GREEN%^itself have been carved with incredible details to resemble the feared %^BOLD%^%^BLACK%^A%^GREEN%^sp "+
	"sn%^BLACK%^a%^GREEN%^ke%^RESET%^%^GREEN%^. If you look at it long enough, you will almost swear that the %^YELLOW%^e%^BLACK%^y%^ORANGE%^es "+
	"%^RESET%^%^GREEN%^of the %^BOLD%^as%^RESET%^%^ORANGE%^p %^BOLD%^%^GREEN%^b%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^w %^RESET%^%^GREEN%^are "+
	"blinking back at you. The middle of the %^BOLD%^b%^BLACK%^o%^GREEN%^w %^RESET%^%^GREEN%^is swirling in on itself around the handle. "+
	"Almost as to resemble the %^BOLD%^As%^BLACK%^p %^GREEN%^b%^BLACK%^o%^GREEN%^w %^BLACK%^coils %^RESET%^%^GREEN%^around the wielders arm. "+
	"Just above the handle and facing the targets of the %^BOLD%^b%^BLACK%^o%^GREEN%^w%^RESET%^%^GREEN%^, a large %^BOLD%^%^BLACK%^a%^GREEN%^sp "+
	"sn%^BLACK%^a%^GREEN%^ke h%^BLACK%^e%^GREEN%^ad %^RESET%^%^GREEN%^is carved with %^RED%^open maw %^GREEN%^and dangerous looking "+
	"%^BOLD%^%^WHITE%^fangs %^RESET%^%^GREEN%^made from %^BOLD%^%^WHITE%^ivory%^RESET%^\n");
   	set_value(1500);
   	set_property("enchantment",4);
	set_lore("The Asp Bow is a creation both feared and marveled. It is said that only the Medusa are able to bind the spirit of a Asp "+
	"snake to the bow willingly in a way that the bow inherits the powers of the snake. Not much are known about the creation of the bow "+
	"however, as very few live to tell the tale of meeting a Medusa.. -- Sallonir deldor, Bard of Torm");
   	set_property("lore difficulty",19);
      set_lrhit((:TO,"extra_lrhit":));
	  set_wield((:TO,"wieldme":));
}


int wieldme(){
	if((int)ETO->query_level() < 20) {
		tell_object(ETO,"%^BOLD%^%^GREEN%^The Asp Snake turns at bites you in refusal!");
		tell_room(EETO,ETO->QCN+"'s%^BOLD%^%^GREEN%^ bows bit "+ETO->QO+" as "+ETO->QS+"%^BOLD%^%^GREEN%^ tried to wield it!%^RESET%^",({ETO}));
		ETO->add_poisoning(15);
		return 0; }
		if((string)ETO->query_race() == "medusa" || ((string)ETO->query_race() == "yuan-ti")) {
		counter = 0;
			tell_object(ETO,"%^BOLD%^%^ORANGE%^The %^GREEN%^Asp bow%^YELLOW%^ coils caressingly around your hand.%^RESET%^");
			tell_room(environment(ETO),"%^YELLOW%^The Asp bow coils caressingly around "+ETO->QCN+"'s hand",ETO);
                set_item_bonus("damage bonus",2);
				set_item_bonus("dexterity",1);
				return 1;
                }
			tell_object(ETO,"%^BOLD%^%^ORANGE%^The %^GREEN%^Asp bow%^YELLOW%^ coils itself around your hand in vice grip.%^RESET%^");
			tell_room(environment(ETO),"%^YELLOW%^The Asp bow coils its around "+ETO->QCN+"'s hand in very tight grip!",ETO);
			ETO->do_damage(ETO->return_target_limb(),roll_dice(1,10));
				
		return 1;
		}
	
		
int extra_lrhit(object targi){
	object snake;
   if(!objectp(targi)) return 0;
   if(!objectp(ETO)) return 0;
   targi = ETO->query_current_attacker();
   if(random(1000)<150) {
	   switch(random(20)){
		   case 0..4:
		   
			   if(counter > 25){
			   tell_object(ETO,"%^ORANGE%^As you fire yet another Asp Snake at  "+targi->QCN+" %^ORANGE%^your bow tries to awaken snakes around you!");
			   tell_object(targi,"Snakes seem to gather around "+ETO->QCN+"%^ORANGE%^ ");
			   tell_room(EETO,"Snakes seem to gather around "+ETO->QCN+"%^ORANGE%^",ETO);
			   new("/cmds/spells/s/_sticks_into_snakes")->use_spell(ETO,targi,8,100,"cleric");
			   counter = 0;
			   return 1;
			   break;  
			   }
			   
			   tell_object(ETO,"%^ORANGE%^instead of a normal arrow, you fire an %^GREEN%^Asp Snake%^ORANGE%^ at %^WHITE%^"+targi->QCN+"!%^WHITE%^");
			   tell_object(targi,ETO->QCN+"'s transforms the arrows into an %^GREEN%^Asp Snake%^ORANGE%^ and shoots it at you!");
			   tell_room(EETO,ETO->QCN+"'s%^ORANGE%^ bow transform the arrow into an %^GREEN%^Asp Snake%^ORANGE%^ and fires it at "+targi->QCN+"%^RESET%^",ETO);
			   	snake = new(OBJS"aspsnake");
				snake->move(targi);
				snake->hurt(targi);
				counter ++;
			   return 1;
			   break;
			   
			   
		   
			
			
		   case 5..19:
      tell_object(ETO,"%^BOLD%^%^GREEN%^Your bow gives of a slight tremor as it siphons "+targi->QCN+"'s%^BOLD%^%^GREEN%^ life to you!%^RESET%^");
      tell_object(targi,ETO->QCN+"'s%^BOLD%^%^GREEN%^ arrow siphons the lifeforce from you!%^RESET%^");
      tell_room(EETO,ETO->QCN+"'s%^BOLD%^%^GREEN%^ bows tremors slightly as the arrow hits "+targi->QCN+"!",({ETO,targi}));
      set_property("magic",1);
      targi->do_damage(targi->return_target_limb(),random(10)+5);
	  ETO->do_damage("torso",random(10)*(-1));
      remove_property("magic");
      return 1;
	  break;
		   }
		   
		

}
}

