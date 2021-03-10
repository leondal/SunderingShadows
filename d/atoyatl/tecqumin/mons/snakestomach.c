//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("lining");
    set_id( ({"wall","walls", "lining", "stomach lining", "stomach", "muscle", "muscles"}) );
    set_short("The lining of a snake's stomach");
    set_true_invis();
    set_weight(400);
    set_gender("neuter");
    set_no_clean(1);
    set_long("The walls of the %^BOLD%^%^GREEN%^snake's"
      +" %^RESET%^%^GREEN%^stomach%^RESET%^ are thick and"
      +" %^MAGENTA%^muscular%^RESET%^. They mould around you"
      +" and make it hard to move. They are coated in"
      +" %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^o%^BOLD%^rr"
      +"%^RESET%^%^GREEN%^o%^BOLD%^s%^RESET%^%^GREEN%^i"
      +"%^BOLD%^v%^RESET%^%^GREEN%^e fluids %^RESET%^which"
      +" burn at your %^BOLD%^%^MAGENTA%^flesh%^RESET%^.");
    set_race("snake");
    set_body_type("snake");
    add_limb("muscle", "muscle", 0,0,0);
    add_limb("flesh", "flesh", 0,0,0);
    add_limb("sinew", "sinew",0,0,0);
    remove_limb("tail");
    remove_limb("head");
    remove_limb("torso");
    remove_limb("mouth");
    set_overall_ac(-60);
    set_max_hp(2000);
    set_hp(2000);
    set_num_attacks(0);
    set_attacks_num(0);
    set_property("no random treasure", 1);
}

void die()
{
  object snake, room;
  string roomname;
  if (objectp(ETO) && ETO->is_stomach())
  {
    snake = ETO->query_snake();
    room = environment(snake);
    if (objectp(room)){
      roomname = base_name(room);  
      tell_room(ETO, "The lining of the snake's stomach splits, opening a way out to the outside world.");
      tell_room(room, "%^BOLD%^%^GREEN%^The snake suddenly %^RED%^splits%^GREEN%^"
        +" open from the inside and the contents escape in a gush of%^RED%^"
        +" bl%^RESET%^%^RED%^oo%^BOLD%^d%^BOLD%^%^GREEN%^,"
        +" %^RESET%^%^MAGENTA%^g%^BOLD%^o%^RESET%^%^MAGENTA%^re%^BOLD%^%^GREEN%^"
        +"and %^RESET%^%^GREEN%^disgestive ju%^BOLD%^i%^RESET%^%^GREEN%^ces");
      snake->die();
      ETO->add_exit(roomname, "out");
    }
  } 
  ::die();
}

