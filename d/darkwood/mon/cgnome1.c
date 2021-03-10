#include <std.h>

inherit MONSTER;

void create()
{
  ::create();
  set_name("gnome");
  set_id( ({"gnome","female gnome","girl","gnome girl"}) );
  set_short("gnome girl");
  set_long("This small gnome has dark brown skin and deep blue eyes.  "
           "Her clothing is made up of leather and earth toned cloth.  "
           "She has a friendly smile and a cute laugh as she plays."
  );
  set_race("gnome");
  set_gender("female");
  set_body_type("human");
  set_alignment(5);
  set_size(1);
  set_hd(5,5);
  set_hp(50);
  set_max_hp(50);
  set_class("fighter");
  set_level(15);
  set_overall_ac(10);
  set_stats("strength",15);
  set_stats("constitution",18);
  set_stats("dexterity",21);
  set_stats("intelligence",12);
  set_stats("wisdom",9);
  set_stats("charisma",10);
  set_overall_ac(10);
  set_mob_magic_resistance("average");
  set_emotes(2,({"The girl gives you a friendly nod.",
                 "The girl gives you a friendly smile."}),0);
  set_achats(5,({"%^MAGENTA%^Gnome yells: %^RESET%^Hey, Im just a little girl!!",
                 "The female gnome trips you up and you FALL!"}) );
  set_money("silver",random(100));
  set_funcs( ({"trip","bite"}) );
  set_func_chance(70);
}

void trip(object targ)
{
  tell_room(environment(TP),"The girl trips "+TPQCN+" to the ground making "+TP->query_objective()+" lose "+TP->query_possessive()+" breath.",TP);
  TP->do_damage("torso",random(10));
  TP->do_paralyze(random(20));
  tell_object(TP,"The daughter trips you to the ground causing you to lose your breath.");
  return 1;
}

void bite(object targ)
{
  tell_room(environment(TP),"The daughter bites "+TPQCN+" where she can since she is nothing more then a child and hard pressed to defend herself.",TP);
  TP->do_damage("torso",random(5));
  tell_object(TP,"The daughter bites you where she can as she is nothing more then a child and hard pressed to defend herself.");
  return 1;
}
