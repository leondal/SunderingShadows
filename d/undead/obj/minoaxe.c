//essy: Nov 2016
#include <std.h>;
#include <daemons.h>
#include <magic.h>
inherit "/d/common/obj/weapon/giant_battle_axe.c";

create() {
    ::create();
   set_id(({ "axe","giant axe","giant battle axe","battle axe","weapon","Weapon","great axe" }));
   set_name("minotaur great axe");
   set_short("%^BOLD%^%^BLACK%^Minotaur Great-Axe%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^Giant Steel Axe%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This great-axe is immense. Even large creatures, such a firbolgs and minotaurs "+
   "would need two hands two wield this weapon. The %^RESET%^axe head %^BOLD%^%^BLACK%^shaped like a oversized "+
   "helbart had and at least 3 inches thick. The majority of the %^RESET%^axe head %^BOLD%^%^BLACK%^is made from "+
   "p%^WHITE%^o%^BLACK%^l%^WHITE%^i%^BLACK%^sh%^WHITE%^e%^BLACK%^d st%^WHITE%^ee%^BLACK%^l except for the core "+
   "which is made from %^BLUE%^cold-iron%^BLACK%^. On each side of the axe head, a carving of a "+
   "%^RESET%^%^ORANGE%^minotaurs head %^BOLD%^%^BLACK%^is seen, with %^RED%^rubies %^BLACK%^for eyes and "+
   "%^RESET%^%^MAGENTA%^onyx %^BOLD%^%^BLACK%^for nostrils.%^RESET%^");
   set_lore("This can only be the fabled Labyrinth Great-Axe. This weapon is said to be as old as the "+
   "Minotaur race itself and granted to the first Minotaur as weapon while guarding a unknown labyrinth. "+
   "While the weapon is impressive on it's own, it is said to be a terror to behold in the hands of a Minotaur.");
   set_value(3000);
   set_property("lore difficulty",20);
   set_property("enchantment",3+random(2));
   set_property("attack bonus",2);
   set_property("attack bonus",2);
   set_hit((:TO,"smackit":));
   set_wield((:TO,"wieldit":));

}



int wieldit(){

	if((int)ETO->query_level() < 20){

	tell_object(ETO,"%^BOLD%^%^RED%^This weapon is far too powerful for one such as you!");
	tell_room(EETO,ETO->QCN+"%^BOLD%^%^RED%^ seem to have problems even lifting the weapon!",ETO);
	return 0;
	}

	if((string)ETO->query_race() == "minotaur"){

		set_property("damage bonus",4);
		tell_object(ETO,"%^BOLD%^%^RED%^You feel adrenaline rushing though you as you wield the axe");
		tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^RED%^muscles tenses and flexes as "+ETO->QS+" wields the weapon",ETO);
		return 1;
		}

		tell_object(ETO,"%^BOLD%^%^BLACK%^You can't help but admire the axes steel edge");
		tell_room(EETO,"%^BOLD%^%^BLACK%^The axes steel edge glisten sharply as "+ETO->QCN+" wields it",ETO);
		return 1;

}


int smackit(object targi){
	object myspl;

	if(!objectp(TO)) return 1;
	if(!objectp(ETO)) return 1;
	if(!objectp(targi)) return 1;

		//if((string)ETO->query_race == "minotaur"){}

	if(random(1000) < 150) {
		switch(random(20)){

			case 0..4:

			if((string)ETO->query_race() == "minotaur"){

				if((int)targi->query_hp() < roll_dice(5,10)+50){
					tell_object(ETO,"%^RESET%^%^RED%^With a mighty strike you %^BOLD%^%^BLACK%^execute%^RESET%^%^RED%^ your foe!");
					tell_object(targi,"%^RED%^With one strike "+ETO->QCN+" %^BOLD%^%^BLACK%^executed%^RESET%^%^RED%^ you!",ETO);
					tell_room(EETO,ETO->QCN+" execute "+targi->QCN+" with a single strike!",({ETO,targi}));
					targi->set_hp(roll_dice(100,100)*(-1));
					break;
					}

				tell_object(ETO,"%^RESET%^%^RED%^With a mighty strike you nearly %^BOLD%^%^BLACK%^execute%^RESET%^%^RED%^ your foe!");
				tell_object(targi,ETO->QCN+"%^RESET%^%^RED%^tries to %^BOLD%^%^BLACK%^execute%^RESET%^%^RED%^ you with a single strike!",ETO);
				tell_room(EETO,ETO->QCN+" tries to execute "+targi->QCN+" with one strike!",({ETO,targi}));
				targi->do_damage(targi->return_target_limb(),roll_dice(3,5)+5);
				targi->set_paralized(roll_dice(2,8)+4,"That blow really hurt!");
				break;
			}

			tell_object(ETO,"%^BOLD%^%^BLACK%^You collect all your strength in a strike against "+targi->QCN);
			tell_object(targi,ETO->QCN+"%^BOLD%^%^BLACK%^ grunts as "+ETO->QS+"%^BOLD%^%^BLACK%^ collect all "+ETO->QP+"%^BOLD%^%^BLACK%^ strength in his attack",ETO);
			tell_room(EETO,ETO->QCN+" %^BOLD%^%^BLACK%^grunts as "+ETO->QP+"%^BOLD%^%^BLACK%^ collects all his strength in the strike against "+targi->QCN,({ETO,targi}));
			targi->do_damage(targi->return_target_limb(),roll_dice(2,8)+4);
			break;

			case 5..14:

			if((string)ETO->query_race() == "minotaur") {

				tell_object(ETO,"%^GREEN%^Smell of %^RED%^blood %^GREEN%^reaches you nose as your axe tear "+targi->QCN);
				tell_object(targi,"%^GREEN%^Your %^RED%^blood%^GREEN%^ sprays as "+ETO->QCN+"'s%^GREEN%^ axe tear into you!",ETO);
				tell_room(EETO,targi->QCN+"'s blood sprays as "+ETO->QCN+"'s axe tears into "+targi->QO,({ETO,targi}));
				set_property("magic",1);
				targi->do_damage(targi->return_target_limb(),roll_dice(3,4)+2);
				ETO->do_damage("torso",roll_dice(4,5)*(-1));
				set_property("magic",-1);
				break;
			}
			tell_object(ETO,"%^BOLD%^%^YELLOW%^Your %^BLACK%^steel axe%^YELLOW%^ bites deep into "+targi->QCN);
			tell_object(targi,ETO->QCN+"'s %^BOLD%^%^BLACK%^steel axe%^YELLOW%^ bites deep into you!",ETO);
			tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^BLACK%^steel axe%^YELLOW%^ bites deep into "+targi->QCN,({ETO,targi}));
			set_property("magic",1);
			targi->do_damage(targi->return_target_limb(),roll_dice(2,4)+2);
			set_property("magic",-1);
			break;

			case 15..19:

			if((string)ETO->query_race() == "minotaur") {
				if((int)targi->query_stoneSkinned() > 0){
				 while(objectp(myspl = MAGIC_D->get_spell_from_array(targi->query_property("spelled"),"iron body"))) {
                                remove_property_value("spelled", ({myspl}));
                                myspl->dest_effect();
                        }
                        while(objectp(myspl = MAGIC_D->get_spell_from_array(targi->query_property("spelled"),"stoneskin"))) {
				remove_property_value("spelled", ({myspl}));
				myspl->dest_effect();
			}

			tell_object(ETO,"%^BOLD%^%^WHITE%^The %^BLACK%^steel axe%^WHITE%^ glows bright as it cuts through "+targi->QCN+"'s %^BOLD%^%^WHITE%^protetive spell!");
			tell_object(targi,ETO->QCN+"'s%^BOLD%^%^BLACK%^ steel axe%^WHITE%^ glows bright as it cuts through your protective spell!",ETO);
			tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^BLACK%^steel axe%^WHITE%^ glows bright as it cuts through "+targi->QCN+"'s%^BOLD%^%^WHITE%^ protective spell!",({ETO,targi}));

			}

			}
			tell_object(ETO,"%^BOLD%^%^BLACK%^The steel axe%^WHITE%^ glows bright as it cleaves through "+targi->QCN);
			tell_object(targi,ETO->QCN+"'s %^BOLD%^%^BLACK%^steel axe %^WHITE%^glows bright as it cleaves you!",ETO);
			tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^BLACK%^steel axe%^WHITE%^ glows bright as it cleaves "+targi->QCN,({ETO,targi}));
			set_property("magic",1);
			targi->do_damage(targi->return_target_limb(),roll_dice(5,5)+5);
			set_property("magic",-1);
			break;
		}
		return 1;

	}

}
