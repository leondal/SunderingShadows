#include <std.h>
inherit MONSTER;


void create()
{
  ::create();
  set_name("hyena");
  set_property("swarm",1);
  set_id( ({"hyena","hyena1"}) );
  set_short("%^RESET%^%^ORANGE%^A s%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^rag%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^y h%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^a%^RESET%^");
  set_long("This beast stands on four legs and looks pretty much like any "
           "other of its kind...UGLY! Only difference is this one has a "
           "thick collar around its neck attached to a thick, heavy chain "
            "leash, which in turn is held by one of the guards of Muileann.");
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
}
