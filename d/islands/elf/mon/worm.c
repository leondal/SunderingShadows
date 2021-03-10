#include <std.h>
inherit WEAPONLESS;

#define VQCN vic->query_cap_name()


create() {
   ::create();
   set_name("ice worm");
   set_id( ({"worm","ice worm","monster","animal"}) );
   set("short","%^CYAN%^i%^RESET%^c%^CYAN%^e w%^RESET%^o%^CYAN%^rm%^RESET%^");
    set("long","This dog-sized worm uses toxic excretions"+
	" to tunnel its way through the ice.  It stinks like"+
	" sulfur.  It has no eyes and in the front a huge"+
	" mouth with several circular rows of teeth.  "+
	"The teeth are dripping a green steaming slime."+
	"  It has a thick gray hide with patches of hair sticking from it.");
   set_gender("male");
   set_race("worm");
   set_body_type("dragon");
   add_limb("mouth","head",0,0,0);
   set_attack_limbs( ({"mouth","tail"}) );
   set_attacks_num(4);
   set_base_damage_type("slashing");
   set_damage(3,8);
   set_hit_funcs( (["mouth": (: TO,"mouth_func" :)]) );
   set_hd(35,10);
   set_hp(550+random(200));
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",40);
   set_guild_level("fighter",40);
   set_alignment(8);
   set_funcs( ({"spray"}) );
   set_func_chance(10);
   set_property("weapon resistance",2);
   set_property("spell resistance",20);
   set_property("no death",1);
   set_property("magic",1);
   set_overall_ac(-18);
   set_moving(1);
   set_speed(60);
   new("/d/antioch/valley/obj/gem")->move(TO);
   set_new_exp(30,"normal");
   set_max_level(36);
   set_base_damage_type("bludgeoning");
   set("aggressive",25);
}

int mouth_func(object vic) {
   if(!objectp(vic)) return 0;
   tell_object(vic,"%^BOLD%^%^RED%^The worm bites down on you with its "+
      "powerful mouth!");
   tell_room(ETO,"%^BOLD%^%^RED%^The worm latches on to "+VQCN+" with its "+
      "powerful mouth!",vic);
   vic->cause_typed_damage(vic,0,roll_dice(5,10),"piercing");
   return 1;
}

void spray(object voc) {
   object *vic;
   int i,all;
   vic = all_living(ETO);
   vic -= ({TO});
   all = sizeof(vic);
   tell_room(ETO,"%^BOLD%^%^CYAN%^The worm lets out a deafening screech and "+
      "pull his head back ready to spit acid!!!");
   for(i = 0;i < all;i++) {
      if(wizardp(vic[i]))
         break;
      if(member_array( vic[i],TO->query_attackers() ) == -1)
         TO->kill_ob(vic[i]);
      vic[i]->do_damage( "head",roll_dice(5,10) );
	  tell_object(vic[i],"%^RED%^The worm sprays you with a hot slime.");
      if(!"/daemon/saving_throw_d.c"->reflex_save(vic[i],-25)) {
         vic[i]->set_paralyzed(10,"%^RED%^You are paralyzed by the worm's slime.");
      }
   }
   
}
