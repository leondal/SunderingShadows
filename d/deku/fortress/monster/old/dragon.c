#include <std.h>
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
  set("aggressive",3);
  set_size(3);
  set_hd(15,3);
   set_hp(165);
  set_body_type("dragon");
  set_alignment(9);
  set_overall_ac(2);
  add_money("gold",1000 + random(1000));
  set("race","dragon");
  set_funcs( ({"breath"}) );
set_func_chance(50);
  set_class("mage");
  set_guild_level("mage",5);
}

void breath(object targ)
{
    string damaging;
    if(!objectp(targ)) return;
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
          targ->do_damage("torso",(6+random(4)+random(4)+random(4)));
else
          targ->do_damage("torso",to_int((6+random(4)+random(4)+random(4))/2));
    return 1;
}
