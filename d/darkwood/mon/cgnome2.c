#include <std.h>

inherit MONSTER;

void create()
{
  ::create();
  set_name("gnome");
  set_id( ({"gnome","male gnome","boy","gnome boy"}) );
  set_short("gnome boy");
  set_long("This small male gnome has woody brown skin and ice blue eyes."
           "His clothing is made up of leather and earth toned cloth. He "
           "has a friendly smile and a cat's curiosity."
  );
  set_race("gnome");
  set_gender("male");
  set_body_type("human");
  set_alignment(5);
  set_size(1);
  set_hd(10,20);
  set_hp(100);
  set_max_hp(100);
  set_class("thief");
  set_thief_skill("pick pockets",80);
  toggle_steal();
  set_thief_skill("hide in shadows",80);
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
  set_emotes(2,({"The boy gives you a friendly nod as you pass by.",
                 "The boy gives you a friendly smile."}),0);
  set_achats(5,({"%^MAGENTA%^Gnome yells: %^RESET%^I'm just a child! ",
                 "The boy trips you up and you FALL!"}) );
  set_money("silver",random(100));
  set_funcs( ({"trip","bash"}) );
  set_func_chance(70);
}

void trip(object targ)
{
  tell_room(environment(TP),"The son trips "+TPQCN+" to the ground making "+TP->query_objective()+" lose "+TP->query_possessive()+" breath.",TP);
  TP->do_damage("torso",random(10));
  TP->do_paralyze(random(20));
  tell_object(TP,"The boy trips you to the ground causing you to lose your breath.");
  return 1;
}

void bash(object targ)
{
  tell_room(environment(TP),"The boy bashes "+TPQCN+" unmercifully!",TP);
  TP->do_damage("torso",random(15));
  tell_object(TP,"The boy bashes you unmercifully!");
  tell_object(TP,"%^RED%^BASH!%^RESET%^");
  tell_object(TP,"%^RED%^BASH!%^RESET%^");
  tell_object(TP,"%^BOLD%^BASH!%^RESET%^");
  tell_object(TP,"%^RED%^BASH!%^RESET%^");
  tell_object(TP,"%^RED%^BASH!%^RESET%^");
  return 1;
}
