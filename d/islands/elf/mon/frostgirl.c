#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;

#define VQCN vic->query_cap_name()

int flag;

create() {
   ::create();
   set_name("%^CYAN%^frost spirit%^RESET%^");
   set_id( ({"spirit","frost spirit","woman","monster"}) );
   set("short","%^RESET%^%^CYAN%^frost spirit%^RESET%^");
    set("long","%^CYAN%^This looks like a blue-white hued"+
	" female ghost.  An extreme aura of cold emanates"+
	" from her.   Small flakes of snow fall in her"+
	" wake as if her presence freezes the very air."+
	"  Where her eyes should be are two hollow holes"+
	" that are completely transparent.  Just looking "+
	"at her makes one feel a cold, empty feeling loss.%^RESET%^");
   set_gender("female");
   set_race("undead");
   set_attacks_num(4);
   set_damage(3,8);
   set_hd(35,10);
   set_hp(550+random(200));
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",40);
   set_guild_level("fighter",40);
   set_alignment(8);
   set_funcs( ({"touch"}) );
   set_func_chance(20);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_property("no death",1);
   set_property("magic",1);
   set_overall_ac(-18);
   set_moving(1);
   set_speed(60);
   set_new_exp(30,"normal");
   set_max_level(35);
   set_base_damage_type("cold");
   set_property("function and attack",1);
   set("aggressive",25);
 
}
void touch(object vic) {
   tell_object(vic,"%^CYAN%^The woman's hand chills your soul!");
   tell_room(ETO,"%^CYAN%^The figure's hand passes into "+VQCN+".",vic);
   vic->add_exp(-5000);
   if(!"/daemon/saving_throw_d.c"->fort_save(vic,-30)){
     vic->set_paralyzed(10+random(20),
     "%^CYAN%^You can't stop shivering.");
	 if(vic->query_stats("constitution") > 10);
                 vic->add_stat_bonus("constitution",-1);
	} 
	vic->cause_typed_damage(vic,0,roll_dice(5,10),"cold");
   return ;
}
void die(object ob) {
   tell_room(ETO,"%^RED%^The girl vanishes into a flurry of frost.");
   switch ( random(3)){
    case 0:   new(OBJ"sandals2")->move(ETO);
	break;
	case 1:   new(OBJ"sandals2")->move(ETO);
	break;
	}
   TO->move("/d/shadowgate/void");
   remove();
   return;
}
