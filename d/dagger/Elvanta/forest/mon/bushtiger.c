inherit "/std/monster";

create()
{
  ::create();
  set_property("weapon resistance", 50);
  set_name("bushtiger");
  set_id( ({"tiger","saber-tooth tiger","bushtiger","bushtig","bushsaber-tooth tiger"}) );
  set_short("a Bushtiger");
  set_long(
@PEGASUS
  This bush stands about 8ft at what looks to be the shoulder and in the
form of a very hungry looking saber-tooth tiger. Its leaves are a tawny
color with streaks of white along the chest and belly. There is even some
black at the tip of the tail and ears. The only place its truly green is
where the eyes should be. Bare branches stick out to immitate fangs and claws.
PEGASUS
   );
  set_race("bush");
  set_gender("male");
  set_body_type("quadruped");
  set_hd(15,2);
  set_hp(85);
  set_overall_ac(4);
  set_alignment(5);
set("aggressive",(: "attack_function" :));
  set_stats("strength", 12);
  set_stats("constitution", 9);
  set_stats("dexterity", 18);
  set_stats("wisdom", 5);
  set_stats("intelligence", 3);
  set_stats("charisma", 8);
add_money("silver", 500);
  set_size(3);
  //set_max_hp(query_hp());
}


void attack_function(object targ) {
  if(!targ) { return 0; }
  tell_room(environment(targ),"The bushtiger lunges at "+
            targ->query_cap_name()+"!",targ);
  tell_object(targ,"%^BOLD%^%^RED%^The bushtiger lunges at you!");
  targ->do_damage("torso",random(10));
  kill_ob(targ,1);
  set("aggressive",20);
set_exp(300);
}

