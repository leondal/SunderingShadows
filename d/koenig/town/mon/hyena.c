#include <std.h>
inherit MONSTER;

string time;


void create()
{
  ::create();
  set_name("hyena");
  set_property("swarm",1);
  set_id( ({"hyena","hyena1"}) );
  set_short("%^RESET%^%^ORANGE%^A s%^BLACK%^c%^RESET%^%^ORANGE%^rag%^BOLD%^%^BLACK%^g%^ORANGE%^y h%^BLACK%^y%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^n%^ORANGE%^a%^RESET%^");
  set_long("%^ORANGE%^This %^BOLD%^%^BLACK%^beast %^RESET%^%^ORANGE%^stands on four legs and looks pretty much like any %^WHITE%^"+
           "%^ORANGE%^other of its kind%^WHITE%^.%^ORANGE%^..UGLY! The only difference is this one has a %^WHITE%^"+
           "%^BOLD%^%^RED%^thick collar %^RESET%^%^ORANGE%^around its neck, attached to a thick, %^BOLD%^%^WHITE%^h%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^v%^BOLD%^y c%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^i%^BOLD%^n %^RESET%^"+
           "%^ORANGE%^leash, which in turn is held by a woman who wears a rather %^WHITE%^"+
           "%^BOLD%^%^BLACK%^sinister grin %^RESET%^%^ORANGE%^on her face.%^WHITE%^");
  set_alignment(5);
  set_race("hyena");
  set_gender("male");
  set_hd(5,5);
  set_stats("strength",18);
  set_stats("dexterity", 14);
  set_stats("constitution", 15);
  set_stats("wisdom", 5);
  set_stats("intelligence", 5);
  set_stats("charisma", 1);
  set_body_type("quadruped");
  set_hp(50);
  set_max_hp(50);
  set_overall_ac(6);
  set_size(2);
  set_new_exp(8, "normal");
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "dawn")
    remove();
}
