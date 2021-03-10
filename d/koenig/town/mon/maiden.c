#include <std.h>
inherit MONSTER;

string time;

void create()
{
  ::create();
  set_name("maiden");
  set_id( ({"maiden","lady","woman"}) );
  set_short("%^BOLD%^%^WHITE%^A Lovely Maiden%^RESET%^");
  set_long("This gentle maiden is dressed in fine clothes and looks very delicate and lovely.");
  set_race("human");
  set_body_type("human");
  set_gender("female");
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
  set_new_exp(8, "normal");
  add_money("gold",random(20));
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight")
    remove();
}
