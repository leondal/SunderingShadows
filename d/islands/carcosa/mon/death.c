inherit "/std/monster.c";
string LUCIFER;
void create() {
  :: create();  
   set_name("Lesser Spawn of Death");
   set_id( ({ "death"}) );
   set_short("Death");
   set_level(9);
   set("long", 
@LUCIFER
This lesser spawn of death has been sent for your soul.
Defeat him or your soul is sure to travel on the etherial
planes and your body will likely be destroyed.
LUCIFER
);
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_alignment(-10);
   set_size(2);
   set_hd(15,0);
   set_stats("intelligence",18);
   set_stats("wisdom",14);
   set_stats("strength",15);
   set_stats("charisma",9);
   set_stats("dexterity",16);
   set_stats("constitution",17);
   set_max_mp(3);
   set_hp(55);
   set_overall_ac(-2);
   set_class("fighter");
   set_wielding_limbs(({"right hand","left hand"}));
   set("aggressive",16);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());
   set_funcs(({"scythe"}));
   set_func_chance(99);
   set_exp(1000);

}
void scythe(object target){
  int dam;
  object me = this_object();
  object tar = me->query_current_attacker();
write("bite");
      tell_room(environment(target),"Death slashes " +tar->query_cap_name()+ " deeply with his scythe!");
      tell_object(target,"Death's scythe cuts into your chest!");
write("bite damage");
      dam = (roll_dice(3,6));
      tar->do_damage("torso",dam);
      return 1;
}
