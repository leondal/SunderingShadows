#include <std.h>
inherit MONSTER;

// void charge(object targ);

void create()
{
  ::create();
  set_property("strength", "magic");
  set_name("unicorn");
  set_id( ({"unicorn"}) );
  set_short("%^BOLD%^%^WHITE%^A M%^YELLOW%^a%^WHITE%^gnific%^YELLOW%^en%^WHITE%^t Unicorn%^RESET%^");
  set_long("%^RESET%^This is a unicorn of %^BOLD%^%^WHITE%^purest white. Its horn and hooves look to be "+
           "the color of %^YELLOW%^purest gold%^RESET%^. Maybe he will heal your wounds and "+
           "relieve your weariness if you %^BOLD%^kneel%^RESET%^ before him.");
  set_race("unicorn");
  set_body_type("equine");
  add_wielding_limb("head");
  set_gender("male");
  set_size(3);
  set_hd(18,4);
  set_max_hp(148);
  set_hp(148);
  set_overall_ac(2);
  set_new_exp(12, "very high");
  new("/d/koenig/town/mon/weapons/horn.c")->move(this_object());
  command("wield horn in head");
  set_funcs( ({"charge"}) );
  set_func_chance(75);
}
void charge(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ),"%^BOLD%^The unicorn charges at "+targ->query_cap_name()+"!", targ);
  tell_object(targ,"%^BOLD%^The unicorn charges you in an attempt to run you through with its %^YELLOW%^golden %^RESET%^%^BOLD%^horn!");
  targ->do_damage("torso", random(12)+1);
  tell_object(targ, "%^BOLD%^%^RED%^The unicorn runs you through.");
  targ->set_paralyzed(random(3),"It takes you a few seconds to recover from the blow.");
  return 1;
}


void init()
{
  ::init();
  add_action("kneel","kneel");
}

int kneel(string str)
{
  if( str != "before unicorn" )
    return 0;
  if( member_array(TP, TO->query_attackers()) == -1 )
    {
    TP->add_hp(random((int)TP->query_max_hp() - (int)TP->query_hp()));
      write("%^BOLD%^%^CYAN%^You kneel before the unicorn and he touches his "
	    "horn to your brow,%^BOLD%^%^CYAN%^ and you feel revived and "
	    "refreshed.");
      say(TP->query_cap_name() +" kneels down before the unicorn and it "
      "touches its horn to "+ TP->query_cap_name() +"'s shoulder.");
      return 1;
    }
    else
      {
	TP -> do_damage("torso", random(12)+1);
        write("%^BOLD%^%^RED%^You kneel before the unicorn and in the fray, "
	      "he rips his horn through your torso!");
        say(TP->query_cap_name() +" kneels down before the unicorn, and the "
         "the unicorn rips its horn through"+ TP->query_cap_name() +"'s "
            "torso!");
        return 1;
      }
}
