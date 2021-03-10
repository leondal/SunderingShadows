inherit "/std/monster";

create() {
  ::create();
  set_name("dragon");
  set_id(({"dragon","black dragon"}));
  set_gender("female");
  set("short", "Small Black Dragon");
  set("long","This 7 foot high black dragon lurks in the shadows "+
      "ready to tear apart its prey as it passes.");
  set_level(10);
  set("aggressive",0);
  set_size(3);
  set_hd(15,3);
  set_hp(200);
set_exp(1000);
  set_alignment(9);
  set_overall_ac(2);
  add_money("gold",1000 + random(500));
  set("race","dragon");
  set_body_type("dragon");
  set_funcs( ({"breath"}) );
  set_func_chance(10);
  set_class("mage");
  set_mlevel("mage", 8);
  set_guild_level("mage",8);
  set_spell_chance(70);
  set_spells(({"chill touch","acid arrow","dispel magic"}));
}

void breath(object targ)
{
    string damaging;
    if("/daemon/saving_d"->saving_throw(targ,"breath_weapon"))
        damaging="splashes";
    else
        damaging="soaks";
    tell_object(targ,"%^GREEN%^%^BOLD%^The dragon "+
        damaging+" you with a stream of acid!");
    tell_room(environment(targ),"%^GREEN%^%^BOLD%^The dragon "+
        damaging+" "+targ->query_cap_name()+" with a stream of "+
        "acid!", targ);
    if(damaging=="soaks")
        targ->add_hp( -(6+random(4)+random(4)+random(4)) );
    else
        targ->add_hp( -to_int((6+random(4)+random(4)+random(4))/2) );
}
