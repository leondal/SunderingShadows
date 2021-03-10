#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;

#define VQCN vic->query_cap_name()

int flag;

create() {
   ::create();
   set_name("%^CYAN%^Frost Spirit%^RESET%^");
   set_id( ({"spirit","frost spirit","greater frost spirit","monster"}) );
   set("short","%^RESET%^%^CYAN%^Gre%^RESET%^a%^CYAN%^ter Fr%^RESET%^o%^CYAN%^st S%^RESET%^p%^CYAN%^irit%^RESET%^");
    set("long","%^CYAN%^This looks like a blue-white hued"+
	" female ghost.  An extreme aura of cold emanates"+
	" from her.   Small flakes of snow fall in her"+
	" wake as if her presence freezes the very air."+
	"  Where her eyes should be are two hollow holes"+
	" that are completely transparent.  Just looking "+
	"at her makes one feel a cold, empty feeling loss.%^RESET%^");
   set_gender("female");
   set_race("undead");
   set_attacks_num(6);
   set_damage(4,8);
   set_hd(35,10);
   set_hp(750+random(600));
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",40);
   set_guild_level("fighter",40);
   set_alignment(8);
   set_funcs( ({"touch"}) );
   set_func_chance(20);
   //only fire damages
   set_property("weapon resistance",5);
   set_resistance_percent("cold", 200);
   set_resistance_percent("bludgeoning", 100);
   set_resistance_percent("piercing", 100);
   set_resistance_percent("slashing", 100);
   set_resistance_percent("silver", 100);
   set_resistance_percent("cold iron", 100);
   set_resistance_percent("electricity", 100);
   set_resistance_percent("acid", 100);
   set_resistance_percent("sonic", 100);
   set_resistance_percent("positive energy", 100);
   set_resistance_percent("negative energy", 100);
   set_resistance_percent("force", 100);
   set_resistance_percent("divine", 100);
   set_resistance_percent("untyped", 100);
   set_resistance_percent("mental", 100);
   set_resistance_percent("light", 100);
   set_property("no death",1);
   set_property("magic",1);
   set_overall_ac(-18);
   add_attack_bonus(20);
   set_moving(1);
   set_new_exp(35,"normal");
   set_max_level(35);
   set_base_damage_type("cold");
   set("aggressive",25);
 
}
int touch(object vic) {
   tell_object(vic,"%^BOLD%^%^CYAN%^The spirit's hand %^RESET%^%^CYAN%^chills%^BOLD%^ your soul!");
   tell_room(ETO,"%^CYAN%^The figure's hand passes into "+VQCN+".",vic);
   vic->add_exp(-5000);
   if(!"/daemon/saving_throw_d.c"->fort_save(vic,-30)){
     vic->set_paralyzed(10+random(20),
     "%^CYAN%^You can't stop shivering.");
	 if(vic->query_stats("constitution") > 10);
                 vic->add_stat_bonus("constitution",-1);
	} 
	vic->cause_typed_damage(vic,0,roll_dice(10,10+20),"cold");
   return 1;
}
void die(object ob) {
   tell_room(ETO,"%^RED%^The girl %^CYAN%^vanishes%^RED%^ into a flurry of %^CYAN%^frost.");
   switch ( random(3)){
    case 0:   new(OBJ"sandals2")->move(ETO);
	break;
	case 1:   new(OBJ"tiara2")->move(ETO);
	break;
	}
   TO->move("/d/shadowgate/void");
   remove();
   return;
}
