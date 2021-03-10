#include <std.h>

inherit MONSTER;

void create()
{
  ::create();
  set_name("gnome");
  set_id( ({"female gnome","gnome","gnome woman", "woman"}) );
  set_short("gnome woman");
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
  set_wielding_limbs( ({"left hand","right hand"}) );
  new("/d/darkwood/obj/bread.c")->move(TO);
  new("/d/darkwood/weaps/pan.c")->move(TO);
  command("wield pan in right hand");
  set_stats("strength",15);
  set_stats("constitution",18);
  set_stats("dexterity",21);
  set_stats("intelligence",12);
  set_stats("wisdom",9);
  set_stats("charisma",10);
  set_overall_ac(10);
  set_mob_magic_resistance("average");
  set_emotes(2,({"The woman gives you a friendly nod as you pass by.",
                 "The woman gives you a friendly smile.",
                 "%^MAGENTA%^Gnome woman says: %^RESET%^Good day!"}),0);
  set_achats(5,({"%^MAGENTA%^Gnome woman yells: %^RESET%^How dare you! Trying to pick on a defensly woman!!",
                 "Gnome woman trips you up and you FALL!"}) );
  set_money("silver",random(100));
  set_funcs( ({"trip","bash"}) );
  set_func_chance(50);
}

void trip(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"Gnome woman trips "+TPQCN+" to the ground making "+TP->query_objective()+" lose "+TP->query_possessive()+" breath.",targ);
  targ->do_damage("torso",random(10));
  targ->do_paralyze(random(20));
  tell_object(targ,"Gnome woman trips you to the ground causing you to lose your breath.");
  return 1;
}

void bash(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"Gnome woman bashes "+TPQCN+"'s brains in with one of her frying pans!",targ);
  targ->do_damage("torso",random(15));
  tell_object(targ,"Gnome woman bashes your brains in with one of her frying pans!");
  tell_object(targ,"%^RED%^BASH!%^RESET%^\n"
                 "%^RED%^BASH!%^RESET%^\n"
                 "%^BOLD%^BASH!%^RESET%^\n"
                 "%^RED%^BASH!%^RESET%^\n"
                 "%^RED%^BASH!%^RESET%^\n");
  return 1;
}
