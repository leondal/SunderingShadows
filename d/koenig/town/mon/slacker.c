#include <std.h>
inherit BARKEEP;

string time;

void create()
{
  ::create();
  set_property("no bump",1);
  set_name("Slacker");
  set_id( ({"slacker", "waiter", "Slacker"}) );
  set_short("%^RESET%^%^ORANGE%^Slacker, the Waiter%^RESET%^");
  set("aggressive",0);
  set_level(10);
   set_long("Slacker doesn't look like the type to actually wait on tables. However, he takes your order cheerfully.");
  set_gender("male");
  set_alignment(6);
  set("race", "hunchback");
  set_hd(11,2);
  add_money("gold", random(100));
  set_body_type("human");
  set_class("fighter");
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/deku/weapons/club.c")->move(this_object());
  command("wield club in right hand and left hand");
  set_exp(500);
  set_hp(80);
  set_currency("gold");
  set_menu(
    ({"house special","rare steak","heart","liver","blood cake","bread"}),
    ({"food","food","food","food","food","food"}),
    ({30,25,20,15,15,10})
      );
set_my_mess(({
    "Your taste buds go crazy for the taste. You really don't think you want to know what it is, however.\n",
    "MMMMM, nice and juicy. The chewing enjoyment goes on and on.\n",
    "You can appreciate a good heart.\n",
    "You gag a bit, but the onions help.\n",
    "Your mouth tingles as you taste the sweetness of the outside, then the salty warmth of the inside.\n",
    "You feel refreshed and sated.\n",
    }));
set_your_mess(({
    "growls contentedly as the spices and herbs play across their deprived taste buds.\n",
    "enjoys the juicy red meat with vigor.\n",
    "shakes their head in approval at the tenderness of the heart.\n",
    "gags a bit but gets the liver down.\n",
    "mmmmm's contentedly as they devour their blood cake with relish.\n",
    "enjoys the crumbling bread with delite.\n"
    }));
set_menu_short(({
    "%^YELLOW%^The House Special%^RESET%^",
    "%^RESET%^%^RED%^A Slab of Steak%^RESET%^",
    "%^BOLD%^%^RED%^A Heart on a Platter%^RESET%^",
    "%^RESET%^%^ORANGE%^Liver and Onions%^RESET%^",
    "%^RED%^A Plate of Blood Cake%^RESET%^",
    "%^ORANGE%^A Basket of Bread%^RESET%^"
    }));
set_menu_long(({
    "A mysterious house special, guaranteed to replenish your body and soul.\n",
    "A fat juicy steak, the kind you've only dreamed of since on your travels.\n",
    "A tender heart mixed with a few key herbs and spices.\n",
    "Some liver to replace your iron level back to normal.\n",
    "A nice dessert to finish off your meal.\n",
    "Some crumbling bread for if you can't afford the good stuff.\n"
    }));
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight")
    remove();
}
