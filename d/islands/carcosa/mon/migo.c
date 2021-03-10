inherit "/std/monster.c";
string LUCIFER;
void create() {
  :: create();  
   set_name("Mi-Go");
   set_id( ({ "mi-go","mi" }) );
   set_short("A Mi-Go");
   set_level(9);
   set("long", 
@LUCIFER
The Mi-Go, also known as the Fungi from Yuggoth, is an seems to
be a giant insect.  Their pinkish body is about five feet long
with giant membranous attached to its back.  Its many delicate 
limbs seem to be extremely articulate and is able to walk on 
some, all, or even the hindmost pair only.  The Mi-Go's head
is ellipsoid in shape and completely covered in tine antennae.
It is rumored that some of these creatures can even cast spells.
LUCIFER
);
   set_gender("male");
   set("race", "insectoid");
   set_body_type("insectiod-winged");
   set_alignment(-7);
   set_size(2);
   set_hd(11,0);
   set_stats("intelligence",18);
   set_stats("wisdom",16);
   set_stats("strength",14);
   set_stats("charisma",2);
   set_stats("dexterity",12);
   set_stats("constitution",17);
   set_max_mp(50);
    set_hp(30);
    set_overall_ac(8);
    set_class("fighter");
    set_wielding_limbs(({"right fore leg","left fore leg"}));
    set_funcs(({"bite"}));
    set_func_chance(25);
    set("aggressive",16);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_max_hp(query_hp());
    set_mp(query_max_mp());
    set_exp(60+4*query_max_hp());
    new("/d/islands/carcosa/weapons/dclaws.c")->move(this_object());
    command("wield claw in right fore leg");
    new("/d/islands/carcosa/weapons/dclaws.c")->move(this_object());
    command("wield claw in left fore leg");
    add_money("silver",100 + random(250));
    add_money("copper",50 + random(300));

}
void bite(object target){
  int dam, dam1, rand;
  object me = this_object();
  object tar = me->query_current_attacker();
  rand = (roll_dice(1,20)+2);
  if (rand >= 16){
      tell_room(environment(target),"The Mi-Go grabs " +tar->query_cap_name()+ " and carries him many feet up!");
      tell_object(target,"You can't shake the Mi-Go loose!");
      dam = (roll_dice(1,4)+2);
      tar->do_damage("torso",dam);
      tell_room(environment(target),"The Mi-Go flies high into the air and drops " +tar->query_cap_name()+ "on their head.");
      dam1 = (roll_dice(1,6)+3);
      tar->do_damage("head",dam1);
      return 1;
  } else{
    tell_room(environment(target),"The Mi-Go grabs " +tar->query_possessive() +" flesh, but is shaken loose!");
      tell_object(tar,"The Mi-Go claws you, but you manage to shoo him off!");
      dam = (random(14)+3);
    tar->do_damage("torso",dam);
    return 1;
 }
  }
