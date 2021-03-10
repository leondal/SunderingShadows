inherit "/std/monster.c";
string LUCIFER;
void create() {
  :: create();  
    set_name("Byakhee");
    set_id( ({ "byakhee","thing" }) );
    set_short("A Byakhee");
    set_level(15);
    set("long", 
@LUCIFER
The Byakhee is a dragon-like creature, almost reminiscent of a 
gargoyle.  His face is like that of a crow and his and his arms
look like an insect.  Tufts of hair protrude from the beast, but
not enough to cover the slightly decomposing flesh that covers its
bones.
LUCIFER
);
    set_gender("male");
    set("race", "dragon");
    set_body_type("dragon");
    set_alignment(-8);
    set_size(3);
    set_hd(18,1);
    set_stats("intelligence",17);
    set_stats("wisdom",12);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity",25);
    set_stats("constitution",17);
    set_class("ranger");
    set("aggressive",25);
    set_overall_ac(4);
    set_wielding_limbs(({"right foreclaw","left foreclaw"}));
    set_max_mp(20);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_max_hp(query_hp());
    set_mp(query_max_mp());
    set_exp(10*query_max_hp());
    new("/d/islands/carcosa/weapons/bclaws.c")->move(this_object());
    command("wield claw in left foreclaw");
    new("/d/islands/carcosa/weapons/bclaws.c")->move(this_object());
    command("wield claw in right foreclaw");
    set_funcs(({"drain"}));
    set_func_chance(25);
    add_money("silver",100 + random(350));
    add_money("gold",50 + random(300));	      

}
void drain(object target){
  int dam;
  object me = this_object();
  object tar = me->query_current_attacker();
  tell_room(environment(target),"The Byakhee laches onto " +tar->query_cap_name()+
      " and draws their blood!");
  tell_object(target,"The Byakhee drains your blood!");
  dam = (roll_dice(2,6)+3);
  tar->do_damage("torso",dam);
  tar->set_paralyzed((roll_dice(2,4)),"You feel too weak from the Byakhee's attack!");
  return 1;
}

