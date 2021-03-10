#include <std.h>

inherit MONSTER;

void create()
{
  ::create();
  set_name("gnome");
  set_id( ({"gnome","female gnome"}) );
  set_short("a gnome");
  set_long("This female gnome has dark brown skin and deep blue eyes. "
           "Her clothing is made up of leather and earth toned cloth. "
           "She has a warm welcome and a friendly smile for strangers and "
           "gnome alike.");
  set_race("gnome");
  set_gender("female");
  set_body_type("human");
  set_alignment(5);
  set_size(1);
  set_hd(10,20);
  set_hp(100);
  set_max_hp(100);
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
  set_emotes(2,({"The female gnome gives you a friendly nod as you pass by.",
                 "The female gnome gives you a friendly smile.",
                 "%^MAGENTA%^Gnome says: %^RESET%^Good day!"}),0);
  set_achats(5,({"%^MAGENTA%^Gnome yells: %^RESET%^How dare you!",
                 "The female gnome trips you up and you FALL!"}) );
  set_money("silver",random(100));
  set_funcs( ({"trip"}) );
  set_func_chance(50);
}

void trip(object targ)
{
  tell_room(environment(TP),"The gnome trips "+TPQCN+" to the ground making "+TP->query_objective()+" lose "+TP->query_possessive()+" breath.",TP);
  TP->do_damage("torso",random(10));
  TP->do_paralyze(random(20));
  tell_object(TP,"The gnome trips you to the ground causing you to lose your breath.");
  return 1;
}
