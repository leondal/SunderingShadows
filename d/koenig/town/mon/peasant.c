#include <std.h>
inherit MONSTER;

string time;

void create()
{
  ::create();
  set_name("peasant");
  set_id( ({"peasant","man"}) );
  set_short("A dour-faced man");
  set_long("This gentleman is dressed in fine clothes and looks rather handsome. However, he wears a sour expression on his face, as if he's just lost everything in the world that matters.");
  set_race("human");
  set_body_type("human");
  set_gender("male");
  set_alignment(5);
  set_hd(7,2);
  set_max_hp(58);
  set_hp(58);
  set_overall_ac(8);
  set_size(2);
  set_stats("strength",12);
  set_stats("constitution",8);
  set_stats("dexterity",10);
  set_stats("wisdom", 12);
  set_stats("intelligence", 13);
  set_stats("charisma",10);
  set_class("fighter");
  set_exp(839);
  add_money("gold",random(20));
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight")
    remove();
}
