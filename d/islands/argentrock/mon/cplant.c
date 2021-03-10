//4/2/13 updating old code
//-hades
#include <std.h>
#include <daemons.h>
#include "../argabbr.h"

inherit WEAPONLESS;

int flag;

create() {
   ::create();
   set_name("carnivorous plant");
   set_id( ({"plant","carnivorous plant","carnivore","argmon"}) );

   set("short","%^RESET%^%^GREEN%^Ca%^BOLD%^r%^RESET%^%^GREEN%^nivorous p%^BOLD%^l%^RESET%^%^GREEN%^ant%^RESET%^");
   set_long("%^GREEN%^A writhing mass of thick vines is attached"+
        " to a dark leaf green bulbous head.  The thick leafy "+
        "vines sway and twist about, reaching for some prey.  "+
        "The bulbous head of the plant has a teardrop shape to "+
        "it.  As the plant opens its mouth a row of needle sharp "+
        "fangs cover the inside of its mouth.  A whip like fleshy "+
        "pink tongue rolls in the plant's mouth as it furiously m"+
        "oves about looking for its next meal.%^RESET%^");
   set_gender("neuter");
   set_race("plant");
   set_body_type("plant");
   add_limb("trunk","trunk",0,0,0);
   add_limb("mouth","trunk",0,0,0);
   add_limb("teeth","mouth",0,0,0);
   add_limb("left branch","trunk",0,0,0);
   add_limb("right branch","trunk",0,0,0);
   add_limb("root","trunk",0,0,0);
   set_size(3);
   set_hd(random(11) + 30,8);
   set_hp(random(100) + 350);
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel( "fighter",query_hd() );
   set_guild_level( "fighter",query_hd() );
   set_attack_limbs( ({"teeth","left branch","right branch","root"}) );
   set_attacks_num(4);
   set_hit_funcs( ([ "teeth": (: TO,"teeth_func" :) ]) );
   set_base_damage_type("slashing");
   set_base_damage_type("slashing");
   switch( query_hd() - 30 ) {
      case 0..2:
         set_damage(3,4);
         break;
      case 3..5:
         set_damage(2,7);
         break;
      case 6..8:
         set_damage(3,6);
         break;
      case 9..11:
         set_damage(2,10);
         break;
   }
   set_alignment(8);
   set("aggressive",12);
   set_new_exp(31,"normal");
   set_property("swarm",1);
   set_max_level(36);
   set_overall_ac(0);
   add_money("silver",random(1000) + 500);
   flag = 0;
   set_property("natural poisoner", 1);
   set_property("natural poison", "bloodroot");
   set_property("poison chance", 15) ;
   set_mob_magic_resistance("none");
}

int teeth_func(object vic) {
   tell_object(vic,"%^RED%^Your skin has been %^BOLD%^slashed open%^RESET%^%^RED%^ and there is a large "+
    "%^BOLD%^wound%^RESET%^%^RED%^ created by the teeth of the plant!");
   tell_room(ETO,"%^RED%^"+vic->QCN+"'s skin has been "+
     "%^BOLD%^slashed open%^RESET%^%^RED%^ creating a %^BOLD%^large wound%^RESET%^%^RED%^ by the teeth of the plant!",vic);
   if(!"/daemon/saving_throw_d.c"->fort_save(vic,-30)){
      tell_object(vic,"%^RED%^Poison rushes into your blood vessels from "+
         "the %^BOLD%^teeth%^RESET%^%^RED%^ of the plant!");
       tell_room(ETO,"%^RED%^"+vic->QCN+"'s face turns a "+
         "%^MAGENTA%^purple colour%^RED%^ as poison rushes into "+vic->QP+
         " body!",vic);
      vic->add_poisoning(random(5) + 10);
      vic->set_paralyzed(random(15),"%^RED%^You cannot move your "+
         "body!");
   }
   switch( query_hd() - 30 ) {
      case 0..2:
         return roll_dice(3,4);
      case 3..5:
         return roll_dice(2,7);
      case 6..8:
         return roll_dice(3,6);
      case 9..11:
         return roll_dice(2,10);
   }
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if( !objectp(ETO) )
      return;
   if( (object *)TO->query_attackers() == ({}) ) {
      if(flag >= 10) {
         tell_room(ETO,"%^GREEN%^The plant stops moving and disguises itself "+
            "into the surroundings again.");
         TO->remove();
         flag = 0;
         return;
      }
      flag++;
   }
}

void die(object obj) {
    object obj2;
    switch(random(100)){
        case 0..9:
            obj2 = new(OBJ+"diamond_star")->move(TO);
            break;
        case 10..19:
            obj2 = new(OBJ+"lembas")->move(TO);
            break;
        case 20..29:
            obj2 = new(OBJ+"elec_knife")->move(TO);
            break;
        case 30..39:
            obj2 = new(OBJ+"demon_tail")->move(TO);
            break;
        case 40..49:
            obj2 = new(OBJ+"lion_plate")->move(TO);
            break;
        case 50..59:
            obj2 = new(OBJ+"raven_plate")->move(TO);
            break;
        case 60..69:
            obj2 = new(OBJ+"phoenix_leather")->move(TO);
            break;
        case 70..79:
            obj2 = new(OBJ+"purple_hide")->move(TO);
            break;
        case 80..89:
            obj2 = new(OBJ+"flame_fan")->move(TO);
            break;
        default:
            obj2 = new(OBJ+"diamond_fan")->move(TO);
            break;
    }
    tell_room(ETO,"%^GREEN%^With a dying blech, the plant "+
        "releases something hiding inside of it!");
    ::die(obj);
}
