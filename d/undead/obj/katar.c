//updated by Circe 9/19/04
//Updates by Essy Nov 2016

#include <std.h>
#include <magic.h>

inherit "/d/common/obj/weapon/wakizashi.c";

void create() 
{
    ::create();
    set_id(({"katar"}));
    set_name("katar");
    set_short("%^RED%^Katar%^RESET%^");

    set_long("%^RED%^This unusual weapon has a %^BOLD%^dagger-like blade "+
        "%^RESET%^%^RED%^set into an H-shaped hilt.  The weapon is wielded "+
        "by grasping the %^BLUE%^leather-wrapped crossbar%^RED%^, which "+
        "allows the two %^RESET%^side bars %^RED%^to guard the hand and "+
        "wrist.  It is often used for quick slashing motions by those "+
        "who know it best.%^RESET%^");
  
    set_weight(5);
    set_size(1);
    set_value(400);
    set_property("enchantment",3);
	set_hit((:TO,"smackit" :));
	set_wield((:TO,"wieldme":));
}


int wieldme() {
	
	if(ETO->query_level() < 15){
		tell_object(TO,"%^BOLD%^%^BLACK%^You will need more training if you are to wield this weapon!");
		tell_room(EETO,ETO->QCN+" looks slightly confused by the complexity of the weapon",({ETO}));
		return 0;
	}
	
	if(ETO->is_class("thief") && sizeof(ETO->query_classes()) == 1){
		
		tell_object(ETO,"%^BOLD%^%^BLACK%^You expertly strap the "+TO->query_short()+"%^BOLD%^%^BLACK%^ to your wrist");
		tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLACK%^ expertly straps the "+TO->query_short()+"%^BOLD%^%^BLACK%^ to "+ETP->QP+"%^BOLD%^%^BLACK%^ wrist",({ETO}));
		return 1;
	}
	
	if(ETO->is_class("thief")){
		
		tell_object(ETO,"%^BOLD%^%^BLACK%^Leather straps and blades all over. %^RED%^You draw blood%^BLACK%^ while wielding the weapon!");
		tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLACK%^ looks very focused as "+ETO->QS+"%^BOLD%^%^BLACK%^ wields the "+TO->query_short()+"%^BOLD%^%^BLACK%^ and you are pretty sure "+ETO->QS+"%^BOLD%^%^BLACK%^ cut "+ETO->QO+"self",({ETO}));
		ETO->do_damage(ETO->return_target_limb(),roll_dice(2,10));
		return 1;
	}
	
	tell_object(ETO,"%^BOLD%^%^RED%^leather straps and sharp edges everywhere. You give up before getting hurt!");
	tell_room(EETO,ETO->QCN+"%^BOLD%^%^RED%^ seem perplexed by the weapon and gives before getting "+ETO->QO+"self hurt",({ETO}));
	return 0;
	
	
}



int smackit(object targi){
	
	object foes;
	object *weapons;	
	int i,stars;
	
	string ids;
	foes = ETO->query_attackers();
	weapons = targi->query_wielded();
	
	
	targi = ETO->query_current_attacker();
	
	
	if(!objectp(ETO) || !objectp(targi) || !objectp(TO)) {return 0;}
	
	
	if(random(1000) < 200){
		switch(random(50)) {
			
			case 0..39:
				if(ETO->is_class("thief") && sizeof(ETO->query_classes()) == 1){
					tell_object(ETO,"%^BOLD%^%^BLACK%^With a flick of your wrist, the %^RESET%^"+TO->query_short()+"'%^BOLD%^%^BLACK%^s blade splits in two, %^RED%^opening %^RESET%^"+targi->QCN+"%^BOLD%^%^RED%^'s wound%^RESET%^");
					tell_object(targi,"%^BOLD%^%^BLACK%^You hear a %^RESET%^%^MAGENTA%^'click' %^BOLD%^%^BLACK%^from %^RESET%^"+ETO->QCN+"%^BOLD%^%^BLACK%^'s weapon, and a %^RED%^crippling pain follows!%^RESET%^",({ETO}));
					tell_room(EETO,"%^BOLD%^%^BLACK%^You hear a %^RESET%^%^MAGENTA%^'click' %^BOLD%^%^BLACK%^from %^RESET%^"+ETO->QCN+"%^BOLD%^%^BLACK%^'s weapon, followed by a %^RED%^stream of blood %^BLACK%^flowing from %^RESET%^"+targi->QCN+"%^BOLD%^%^BLACK%^'s %^RESET%^%^RED%^wound%^BOLD%^%^BLACK%^!%^RESET%^",({ETO,targi}));
					targi->cause_typed_damage(targi,targi->return_target_limb(),roll_dice(2,6)+3,"slashing");
					return 1;
					break;
				}
					tell_object(ETO,"%^BOLD%^%^BLACK%^You deftly puncture %^RESET%^"+targi->QCN+"%^BOLD%^%^BLACK%^'s abdomen with your%^RESET%^ "+TO->query_short());
					tell_object(targi,"%^BOLD%^%^BLACK%^You feel almost nothing as %^RESET%^"+ETO->QCN+"%^BOLD%^%^BLACK%^'s sharp %^RESET%^"+TO->query_short()+" %^MAGENTA%^slides effortless through your skin!%^WHITE%^",({ETO}));
					tell_room(EETO,ETO->QCN+"'s "+TO->query_short()+" %^MAGENTA%^slides effotly through "+targi->QCN+"'s skin!%^WHITE%^",({ETO,targi}));
					targi->cause_typed_damage(targi,targi->return_target_limb(),roll_dice(1,6)+2,"slashing");
					return 1;
					break;
			
			case 40..43:
				if(ETO->is_class("thief") && sizeof(ETO->query_classes()) == 1){
					tell_object(ETO,"%^MAGENTA%^With a flick of you wrist, you split %^WHITE%^"+TO->query_short()+" %^MAGENTA%^into a 3-bladed weapon, %^BOLD%^an catch your opponents weapon!%^RESET%^");
					tell_object(targi,ETO->QCN+" %^MAGENTA%^flick %^WHITE%^"+ETO->QO+" %^MAGENTA%^wrist and transform his %^WHITE%^"+TO->query_short()+" %^MAGENTA%^into a 3-bladed %^BOLD%^which catches you'r weapon!%^RESET%^",({ETO}));
					tell_room(EETO,ETO->QCN+" %^MAGENTA%^flick %^WHITE%^"+ETO->QO+" %^MAGENTA%^wrist and transform %^WHITE%^"+ETO->QO+" "+TO->query_short()+" %^MAGENTA%^into a 3-bladed %^BOLD%^which catches %^RESET%^"+targi->QCN+"%^BOLD%^%^MAGENTA%^'s weapon!%^RESET%^",({ETO}) );
					if((int)weapons[0]->query_property("enchantment") < 0){
						tell_object(ETO,"%^BOLD%^%^MAGENTA%^An unnatural force prevents you from disarming %^RESET%^"+targi->QCN+" %^RED%^instead you nearly remove %^WHITE%^"+targi->QP+" %^RED%^hand!%^WHITE%^");
						tell_object(targi,"%^BOLD%^%^MAGENTA%^The curse on your weapon prevents %^RESET%^"+ETO->QCN+" %^BOLD%^%^MAGENTA%^from disarming you, %^RESET%^%^RED%^but nearly removes your hand instead!%^WHITE%^");
						targi->cause_typed_damage(targi,targi->return_target_limb(),roll_dice(4,4)+4,"slashing");
						return 1;
						break;
					}
					ids = weapons[0]->query_id();
					targi->force_me("unwield "+ids[0]);
					targi->remove_property("disarm time");
					targi->set_property("disarm time",time()+(ROUND_LENGTH*roll_dice(1,4)+1));
					targi->cause_typed_damage(targi,targi->return_target_limb(),roll_dice(1,4)+2,"slashing");
					return 1;
					break;
			
				}
					tell_object(ETO,"%^MAGENTA%^With a flick of you wrist, you split %^WHITE%^"+TO->query_short()+" %^MAGENTA%^into a 3-bladed weapon, %^BOLD%^an catch your opponents weapon!%^RESET%^");
					tell_object(targi,ETO->QCN+" %^MAGENTA%^flick %^WHITE%^"+ETO->QO+" %^MAGENTA%^wrist and transform his %^WHITE%^"+TO->query_short()+" %^MAGENTA%^into a 3-bladed %^BOLD%^which catches you'r weapon!%^RESET%^",({ETO}) );
					tell_room(EETO,ETO->QCN+" %^MAGENTA%^flick %^WHITE%^"+ETO->QO+" %^MAGENTA%^wrist and transform %^WHITE%^"+ETO->QO+" "+TO->query_short()+" %^MAGENTA%^into a 3-bladed %^BOLD%^which catches %^RESET%^"+targi->QCN+"%^BOLD%^%^MAGENTA%^'s weapon!%^RESET%^",({ETO}) );
					if((int)weapons[0]->query_property("enchantment") < 0){
						tell_object(ETO,"%^BOLD%^%^MAGENTA%^An unnatural force prevents you from disarming %^RESET%^"+targi->QCN+" %^RED%^instead you nearly remove %^WHITE%^"+targi->QP+" %^RED%^hand!%^WHITE%^");
						tell_object(targi,"%^BOLD%^%^MAGENTA%^The curse on your weapon prevents %^RESET%^"+ETO->QCN+" %^BOLD%^%^MAGENTA%^from disarming you, %^RESET%^%^RED%^but nearly removes your hand instead!%^WHITE%^");
						targi->cause_typed_damage(targi,targi->return_target_limb(),roll_dice(3,4),"slashing");
						return 1;
						break;
					}
					ids = weapons[0]->query_id();
					targi->force_me("unwield "+ids[0]);
					targi->remove_property("disarm time");
					targi->set_property("disarm time",time()+(ROUND_LENGTH*roll_dice(1,3)));
					targi->cause_typed_damage(targi,targi->return_target_limb(),roll_dice(1,4),"slashing");				
					return 1;
					break;
			
			case 44..49:
			
				if(ETO->is_class("thief") && sizeof(ETO->query_classes()) == 1){
					
					tell_object(ETO,"%^CYAN%^You scqueeze the %^BOLD%^%^BLACK%^H-shaped handbar %^RESET%^%^CYAN%^and release %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^ns %^RESET%^%^CYAN%^at your enemies%^WHITE%^");
					tell_room(EETO,ETO->QCN+" %^CYAN%^releases a handful %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^ns %^RESET%^%^CYAN%^from%^WHITE%^ "+ETO->QP+" "+TO->query_short()+"",({ETO}));
					stars = roll_dice(2,3);
					for(i=0;i<stars;i++){
						tell_object(ETO,"%^CYAN%^A %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^n %^RESET%^%^CYAN%^hits %^WHITE%^"+targi->QCN+" %^CYAN%^square in the chest%^WHITE%^");
						tell_object(foes,"%^CYAN%^A %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^n %^RESET%^%^CYAN%^hits you in the chest%^WHITE%^",({ETO}));
						tell_room(EETO,"%^CYAN%^A %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^n %^RESET%^%^CYAN%^hits %^BOLD%^%^WHITE%^"+targi->QCN+" %^RESET%^%^CYAN%^in the chest%^WHITE%^",({ETO,targi}));
						targi->cause_typed_damage(targi,targi->return_target_limb(),roll_dice(1,4)+3,"piercing");
					}
					return 1;
					break;
				}
					tell_object(ETO,"%^CYAN%^You scqueeze the %^BOLD%^%^BLACK%^H-shaped handbar %^RESET%^%^CYAN%^and release a %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^n %^RESET%^%^CYAN%^at%^WHITE%^ "+targi->QCN);
					tell_object(targi,ETO->QCN+" %^CYAN%^hits you with a %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^n %^RESET%^%^CYAN%^released from his "+TO->query_short(),({ETO}));
					tell_room(EETO,ETO->QCN+" %^CYAN%^releases a %^BOLD%^%^WHITE%^sh%^BLACK%^u%^WHITE%^r%^BLACK%^i%^WHITE%^k%^BLACK%^e%^WHITE%^n %^RESET%^%^CYAN%^from %^WHITE%^"+ETO->QP+" "+TO->query_short()+" %^CYAN%^at%^WHITE%^ "+targi->QCN,({ETO}));			
					foes->cause_typed_damage(foes,foes->return_target_limb(),roll_dice(1,4)+3,"piercing");
					return 1;
					break;
			
		}
		
		return 1;
		
	}
	
	
}




