inherit "/std/monster.c";
string LUCIFER;
void create() {
  :: create();  
   set_name("Ghast");
   set_id( ({ "ghast"}) );
   set_short("Ghast");
   set_level(14);
   set("long", 
@LUCIFER
When looking at this repulsive beast there is little more you
can do than turn and wretch.  His body is about the size of a 
small horse and skin as pale as the moon.  The Ghast's facial 
features look remakably human despite the abssence of a nose,
a forehead, and other inportant particulars.  His yellowish 
red eyes seem to look right through you.
LUCIFER
);
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_alignment(-7);
   set_size(2);
   set_hd(11,0);
   set_stats("intelligence",8);
   set_stats("wisdom",4);
   set_stats("strength",20);
   set_stats("charisma",2);
   set_stats("dexterity",12);
   set_stats("constitution",17);
   set_max_mp(3);
    set_hp(75);
    set_overall_ac(5);
    set_class("fighter");
    set_wielding_limbs(({"right hand","left hand"}));
    set("aggressive",16);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_max_hp(query_hp());
    set_mp(query_max_mp());
    set_funcs(({"bite","grab"}));
    set_func_chance(30);
    set_exp(60+4*query_max_hp());
    new("/d/islands/carcosa/weapons/bclaws.c")->move(this_object());
    command("wield claw in right hand");
    new("/d/islands/carcosa/weapons/bclaws.c")->move(this_object());
    command("wield claw in left hand");
    add_money("silver",100 + random(250));
    add_money("gold",50 + random(150));

}
void bite(object target){
  int dam;
  object me = this_object();
  object tar = me->query_current_attacker();
      tell_room(environment(target),"The Ghast bites deeply into " +tar->query_cap_name()+ " and won't let go!");
      tell_object(target,"You can't shake the Ghast loose!");
      tar->set_paralyzed((random(4)+4),"You can't do anything as the Ghast's teeth are dug into your body!");
      dam = (roll_dice(2,8));
      tar->do_damage("torso",dam);
      return 1;
}

void grab(object target){
  int dam1;
  object me = this_object();
  object tar = me->query_current_attacker();
  tell_room(environment(target),"The Ghast bites loosely into " +tar->query_possessive() +" flesh!");
  tell_object(tar,"The Ghast bites into you taking a piece of flesh!"); 
  dam1 = (roll_dice(2,8)+2);
  tar->do_damage("torso",dam1);
  return 1;
}


