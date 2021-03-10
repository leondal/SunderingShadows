//umberhulk

#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("umberhulk");
   set_short("umber hulk");
   set_id(({"umberhulk","beast","monster","hulk"}));
   set_long(
   "This powerful subterranean predator is something to be feared.  "+
   "It has four insect-like eyes no neck and a powerful "+
   "set of mandables coming out of its mouth.  "+
   "Muscles bulge beneith its thick scaley hide.  "+
   "It has very long arms and short legs, all of which have powerful "+
   "claws." 
   );
   set_hd(15,10);
   set_race("Umber Hulk");
   set_gender("male");
   set_body_type("humanoid");
   set_overall_ac(0);
   set("aggressive",15);
  set_property("swarm",1);
  set_level(15);
  set_class("fighter");
  set_mlevel("fighter",15);
  set_hp(random(300)+280);
  //set_exp(4500);
  set_new_exp(14,"normal");
  set_base_damage_type("slashing"); 
  set_damage(3,20);
  set_stats("strength",24);
  set_stats("intelligence",10);
  set_stats("dexterity",3);
  set_stats("constitution",20);
  set_stats("wisdom",3);
  set_stats("charisma",3);
  set_base_damage_type("slashing");
  set_attacks_num(3);
  remove_limb("left hand");
  remove_limb("right hand");
  set_base_damage_type("slashing");
  add_limb("left claw","left arm",0,0,0);
  add_limb("right claw","right arm",0,0,0);
  add_limb("teeth","head",0,0,0);
  set_attack_limbs(({"left claw","right claw","teeth"}));
  set_hit_funcs((["mouth" : (:TO,"bite":) ]));
  set_overall_ac(2);
  set_alignment(5);
  set_emotes(4,({
  "The hulk lurks ominiously.",
  "The hulk digs with ease through the rock.",
  "The hulk makes some clicking noise with its claws.",
  "The hulk places some rocks off to the side.",
  }),0);
  set_emotes(1,({
  "The hulking beast's four eyes focus.",
  "The umber hulk smashes the wall, shaking the whole cave!",
  "The umber hulk lunges, trying to pin you "
  }),1);
  set_funcs(({"pin"}));
  set_func_chance(5);
  set_max_level(15);
}

int cave_in(){
 tell_room(ETO,"The Umberhulk bashes claws and smashes the "+
                 "ceiling causing room to colapse.");
 ETO->collapse_all_exits();
 return 1; 
}


void heart_beat() {
    ::heart_beat();


    if(!objectp(TO)) return;

    if((int)TO->query_hp() < 75) {
        cave_in();
        TO->remove();
        return;
    }

 

}
void pin(object targ)
{
   tell_object(targ,"%^RED%^The beast charges at you,"+
   " knocking you over!  He begins to tear into your chest.");
   tell_room(ETO,"The umberhulk leaps on"+
   " "+targ->query_cap_name()+"knocking them over! It beings clawing into them.",targ);
   targ->do_damage(targ->return_target_limb(),random(10)+1);
   targ->do_damage(targ->return_target_limb(),random(10)+1);
   
   targ->set_tripped(2,"You're still recovering from being knocked down.");
   return 1;
}
