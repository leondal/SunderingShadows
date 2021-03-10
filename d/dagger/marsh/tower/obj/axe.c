// fixed wear/unwear to use ETO, added obvious short-last change was 7/01  *Styx* 8/2003
// changed to inherit. Nienne, 08/07.
#include <std.h>
inherit "/d/common/obj/weapon/large_battle_axe.c";
int uses;
object owned;
void init() {
    ::init();
    if(interactive(TP) && !owned) owned = TPQN;
}
void create() {
    ::create();
    set_name("axe");
    set_id(({ "axe","two handed axe","battle axe"    }));
    set_obvious_short("%^RESET%^%^RED%^Two handed battle axe%^RESET%^");
    set_short("%^RESET%^%^RED%^Battle axe of Bloodlust%^RESET%^");
    set_long(
   	"%^RED%^This is an extremly well crafted battle axe, meant to be wielded in "
	"two hands in a wildly crazed swinging fashion during battle. It is covered with glowing runic "
	"inscriptions of battle lore and appears highly magical. Its hilt is covered in fine jewels."
        "%^RESET%^"
    );
//    set_weight(30);
//    set_size(3);
    set("value",1000);
//  set_wc(2,5);
//  set_large_wc(3,4);
//    set_type("slashing");
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
   set_unwield((:TO,"removeme":));
// Improving the enchantment to +5 per bug request. Its a lvl 25+ weapon. 
//    set_property("enchantment",3);
    set_property("enchantment",5);
  uses = random((100)+30);
//    set_prof_type("large axe");
}
int extra_hit(object ob) {
    object vic;
    int dam,cycle,amnt;
    vic = ETO->query_current_attacker();
  if(random(4)) return 1;
    if((string)ETO->query_name() == "istvan") {
	for(cycle=0;cycle<2;cycle++) {
	    message("my_action",
	        "%^BOLD%^%^BLUE%^The %^GREEN%^battle axe%^BLUE%^ uses the power of the marsh "
	        "deliver a smashing wound to "
	        +vic->query_cap_name()+"!%^RESET%^"
            ,ETO);
            message("other_action",
	        "%^BOLD%^%^BLUE%^The %^GREEN%^battle axe%^BLUE%^ wielded by "+ETO->query_cap_name()+
	        " screams with blood filled energy as it slices into the flesh of "
	        +vic->query_cap_name()+"!"
    	    ,environment(vic),(({ETO, vic})));
            message("my_action",
                "%^BOLD%^%^BLUE%^The %^GREEN%^battle axe%^BLUE%^ wielded by "+ETO->query_cap_name()+
	        " screams with blood filled energy as it slices deep into your flesh!%^RESET%^"
            ,vic);
	    amnt = random(10)+10;
        vic->cause_typed_damage(vic, vic->return_target_limb(),amnt,"slashing");
        }
   }
    if (uses < 1) {
    dam = random(5)+2;
    } else {  
            message("my_action",
	        "%^RED%^The battle axe of bloodlust delivers a stunning blow!%^RESET%^"
            ,ETO);
            message("my_action",
                "%^RED%^The battle axe of bloodlust delivers a stunning blow!%^RESET%^"
            ,vic);
       dam = random(10)+3;
      if(!random(10)){
	        vic->set_paralyzed(dam,"You are stunned by the blow!");
		uses = uses - 3;
	    }
	    uses = uses - 1;
    }
    return dam;
}

int extra_wield() {
    object tp;
    tp = ETO;
    if (!tp) return 0;
    if((int)tp->query_highest_level() < 25) {
	write("You could not control the power this weapon can deliver!");
	return 0;
    }
    if((string)ETOQN != owned && (string)ETOQN != "istvan") {
	write("The axe fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    if(uses > 0) {
        write(
	    "%^RESET%^%^MAGENTA%^You say: %^RESET%^Time to slice, dice and mutilate mice!"
        );
        tell_room(environment(ETO),
	    "%^RESET%^%^MAGENTA%^"+ETOQCN+" says: %^RESET%^Time to slice, dice and mutilate mice!"
        ,ETO);
      ETO->set_property("evil item",1);
        return 1;
    } else {
      ETO->set_property("evil item",1);
	return 1;
    }
}

int removeme()
{
   ETO->set_property("evil item",-1);
   return 1;
}
