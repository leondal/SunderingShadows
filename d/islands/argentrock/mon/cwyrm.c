#include <std.h>
#include <daemons.h>
#include "/d/islands/argentrock/argabbr.h"

inherit WEAPONLESS;

#define VQCN vic->query_cap_name()

int flag;

create() {
   object ob;
   ::create();
   set_name("craw wyrm");
   set_id( ({"wyrm","craw wyrm","dragon"}) );
   set_short("%^RESET%^%^GREEN%^C%^BOLD%^r%^RESET%^%^GREEN%^aw w%^BOLD%^y%^RESET%^%^GREEN%^rm");
   set_long("%^GREEN%^The giant wyrm is an awesome sight towering before you."+
	" It is so huge in size that you cannot see clearly where its tail is. "+
    "It is possibly the largest of its kind in the whole known realm.  From "+
    "head to tail, it measures over 20 feet. In its mouth 2 rolls of "+
    "sharp teeth are clearly observable. Smoke erupts periodically out "+
    "of its two big nostrils like volcanoes. Even the heat is enough to "+
    "slay anything living. Green diamond like scales cover the wyrm's "+
    "entire body. Evidently no ordinary weapon can even slightly hurt "+
    "this magnificent creature. It is the most devastating creature of "+
    "the island of Argentrock.");
   set_gender("male");
   set_race("wyrm");
   set_body_type("dragon");
   add_limb("mouth","head",0,0,0);
   set_attack_limbs( ({"teeth","tail","left foreclaw","right foreclaw"}) );
   set_attacks_num(4);
   set_base_damage_type("slashing");
   set_base_damage_type("slashing");
   set_damage(3,8);
   set_hit_funcs( (["tail": (: TO,"tail_func" :)]) );
   set_hd(45,10);
   set_hp(550+random(200));
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",40);
   set_guild_level("fighter",40);
   set_alignment(8);
   //set_exp(55000);
   set_new_exp(31,"very high");
   set_max_level(36);
   set_funcs( ({"roar"}) );
   set_func_chance(10);
   set_property("weapon resistance",2);
   set_property("damage resistance",2);
   set_mob_magic_resistance("very low");
   set_property("no death",1);
   set_property("no steal",1);
   set_property("magic",1);
   set_overall_ac(-18);
   set_moving(1);
   set_speed(60);
   add_money("silver",1000+random(1000));
   add_money("platinum",1000+random(500));
   flag = 0;
   ob = new("/d/common/obj/brewing/herb_special_inherit");
   ob->set_herb_name("dragon scales");
   ob->move(TO);
}

int tail_func(object vic) {
   tell_object(vic,"%^BOLD%^GREEN%^The craw wyrm %^RED%^smashes%^GREEN%^ you with its "+
      "powerful tail!");
   tell_room(ETO,"%^BOLD%^GREEN%^The craw wyrm %^RED%^smashes%^GREEN%^ "+VQCN+" with its "+
      "powerful tail!",vic);
   if( !vic->query_paralyzed() ) {
      if(!"/daemon/saving_throw_d.c"->fort_save(vic,-30)) {
         tell_object(vic,"%^BOLD%^RED%^You almost faint from that hit.");
         tell_room(ETO,"%^BOLD%^RED%^"+VQCN+" almost faints from the hit "+
            "of the craw wyrm!",vic);
         vic->set_paralyzed(random(20) + 10,"%^BOLD%^RED%^You are still "+
            "recovering from the wyrm's hit!");
      }
   }
   return roll_dice(5,10);
}

void roar() {
   object *vic;
   int i,all;
   if(flag) return;
   vic = all_living(ETO);
   vic -= ({TO});
   all = sizeof(vic);
   tell_room(ETO,"%^BLUE%^The craw wyrm lets out a deafening roar and "+
      "pull his head back ready to %^RED%^BREATHE %^BLUE%^flame!!!");
   for(i = 0;i < all;i++) {
      if(wizardp(vic[i]))
         break;
      if(member_array( vic[i],TO->query_attackers() ) == -1)
         TO->kill_ob(vic[i]);
      vic[i]->do_damage( "head",roll_dice(5,10) );
      if(!"/daemon/saving_throw_d.c"->fort_save(vic,-32)) {
         tell_object(vic[i],"%^BLUE%^The roar of the craw wyrm almost "+
            "break your ear-drum!");
         vic[i]->set_paralyzed(10,"You are paralyzed by the wyrm's roar.");
      }
   }
   call_out("breath",10 + random(5),vic,all);
}

void breath(object *vic,int all) {
   int i;
    tell_room(ETO,"%^RED%^The wyrm's nostrils burn this time with flame and "+
      "smoke. A large ball of flame rushes at you and everyone else in "+
      "the room as the wyrm exhales heavily!\nYou are caught in the "+
      "breath of flame!");
   for(i = 0;i < all;i++) {
     if (!objectp(vic[i])) continue;
      if( present(vic[i]) ) {
         if(!"/daemon/saving_throw_d.c"->reflex_save(vic[i],-30)) {
            tell_object(vic[i],"%^BOLD%^%^RED%^You take the fire blast full on.");
			vic[i]->cause_typed_damage(vic[i],0,roll_dice(15,10),"fire");

         }
         else {
            tell_object(vic[i],"%^BOLD%^%^RED%^Your reflexes save you from the worst of the fire.");
			vic[i]->cause_typed_damage(vic[i],0,roll_dice(10,8),"fire");
         }
      }
   }
   flag = 0;
}

void init() {
   ::init();
   if( wizardp(TP) || !interactive(TP) || flag )
      return;
    tell_object(TP,"%^GREEN%^The craw wyrm turns towards your direction and "+
      "stares at you with its bright red eyes. It looks very %^RED%^ANGRY"
      "%^GREEN%^!!");
    tell_room(ETP,"%^GREEN%^The craw wyrm turns towards "+TP->QCN+
      "'s direction and stares at "+TP->QO+" with its "+
      "bright red %^RED%^ANGRY %^GREEN%^eyes!!",TP);
   call_out("roar",10);
   flag = 1;
}

void die(object ob)
{
  object comp;
   if(flag){
      remove_call_out("roar");
      remove_call_out("breath");
   }
   if(!objectp(ob)) return ::die(ob);
   comp = new("/d/magic/store_comp");
   comp ->set_name("dragon scale");
   comp ->set_id(({"dragon scale","component"}));
   comp->set_short("dragon scale (a spell component)");
   comp->set_long("             " + "2 dragon scale "+
        ". \n" + ob->query_long());
   comp->set_comp_quantity(2);
   comp->move(TO);
   ::die(ob);
   return;
}
