#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;

#define VQCN vic->query_cap_name()

int flag;

create() {
   ::create();
   set_name("%^CYAN%^Ice Sprite%^RESET%^");
   set_id( ({"ice","sprite","ice sprite","monster"}) );
   set("short","%^RESET%^%^CYAN%^Ice Sprite%^RESET%^");
    set("long","This is an ice sprite.  It is a swirling"+
    " mass of snow that floats in the air.  It is vaguely "+
    "humanoid shaped and gives of a constant power that "+
    "freezes anything that gets close to it. "+
    "  Better be careful if you don't want to be frozen by it.");

   set_attacks_num(4);
   set_damage(5,8);
   set_hd(40,10);
   set_race("sprite");
   set_hp(1550+random(1500));
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",40);
   set_class("mage");
   set_mlevel("mage",40);
   set_guild_level("fighter",40);
   set_alignment(8);
   set_funcs( ({"touch"}) );
   set_func_chance(100);
   set_property("weapon resistance",30);
   set_property("function and attack",1);
   set_resistance_percent("cold", 100);
   set_mob_magic_resistance("high");
   set_property("no death",1);
   set_property("magic",1);
   set_overall_ac(-38);
   set_moving(1);
   set_speed(60);
   set_new_exp(40,"normal");
   set_max_level(45);
   set_base_damage_type("cold");
   set_skill("perception", 70);
   set_spells(({
      "polar ray",
      "cone of cold",
	  "chill touch",
	  "greater dispel magic"
   }));
   set_spell_chance(100);
   set_missChance(75);
}
void touch(object vic) {
    if(userp(vic)){
        tell_object(vic,"%^CYAN%^The sprite's hand chills your soul!");
        tell_room(ETO,"%^CYAN%^The sprite's hand passes into "+VQCN+".",vic);

        if(!"/daemon/saving_throw_d.c"->fort_save(vic,-40)){
        vic->set_paralyzed(10+random(20),
        "%^CYAN%^You can't stop shivering.");
	    if(vic->query_stats("constitution") > 10);
          vic->add_stat_bonus("constitution",-1);
	    }
     
	    vic->cause_typed_damage(vic,0,roll_dice(10,10)+100,"cold");
    }
    else {
        tell_room(ETO,"%^CYAN%^The sprite %^BLUE%^freezes %^CYAN%^"+VQCN+" solid!");
        vic->die();
        set_max_hp( query_hp() );
        tell_room(ETO,"%^CYAN%^The life force of the dying creature restores the sprite!");
    }
   return ;
}

