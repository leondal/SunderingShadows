#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ROOM;

object snake, room;

void create() {
  object walls;
  ::create();
  set_property("indoors", 1);
  set_property("light", 0);
  set_short("A snake's belly");
  set_long((:TO, "long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","There's no air to breathe. But if there were, it would be rank.");
  set_listen("default","There are disquieting rumbles and gurgling sounds");
  set_items( ([ ({"walls", "lining", "muscles", "sinew", "fluids", "corrosive fluids"}) : "The walls of the %^BOLD%^%^GREEN%^snake's"
      +" %^RESET%^%^GREEN%^stomach%^RESET%^ are thick and"
      +" %^MAGENTA%^muscular%^RESET%^. They mould around you"
      +" and make it hard to move. They are coated in"
      +" %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^o%^BOLD%^rr"
      +"%^RESET%^%^GREEN%^o%^BOLD%^s%^RESET%^%^GREEN%^i"
      +"%^BOLD%^v%^RESET%^%^GREEN%^e fluids %^RESET%^which"
      +" burn at your %^BOLD%^%^MAGENTA%^flesh%^RESET%^."    
        ]) );
  set_property("no teleport", 1);
  walls = new(MOB + "stomach_lining");
  walls->move(TO);  
}

void init(){
  ::init();
  add_action("wield_me", "wield");
  add_action("wield_me", "draw");
  add_action("escape_me", "escape"); 
  add_action("kill_me", "cut"); 
  add_action("escape_me", "climb"); 
  add_action("kill_me", "claw"); 
  add_action("kill_me", "tear"); 
  add_action("escape_me", "struggle"); 
}

int escape_me(string str)
{
  tell_object("The powerful muscles of the snake's digestive system stop you going backwards. The only way out would be to cut your way through the snake's stomach walls");
  return 1;
}

int kill_me(string str){
  if (interact("wall", str) ||interact("lining", str) ||interact("stomach", str) ||interact("muscle", str))
  {
    tell_object(TP, "You set about tearing through the lining of the snake's stomach");
    tell_room(TO, TPQCN + " sets about tearing through the lining of the snake's stomach", TP);
    TP->force_me("kill lining");
    return 1;
  }
  return notify_fail("Are you trying to cut through the snake's stomach?");
}

int wield_me(string str)
{
  object * inv, wpn;
  int i, count, num;
  if(present(str, TP)->query_size()>1) {
    tell_object(TP, "%^BOLD%^%^RED%^You fumble for your " 
                   + present(str, TP)->query_name() + "%^BOLD%^%^RED%^,"
                   +" but there's just no room to wield it here!");

    tell_object(TP, "You'll have to try a smaller weapon, or fight empty"
                   +" handed.");
    return 1;
  }
  inv = deep_inventory(TP);
  count = sizeof(inv);
  if (count>0)
  {
    for (i=0;i<count;i++)
    {
      if (inv[i]->id(str))
      {
        wpn = inv[i];
        break;
      }
    }
    if (objectp(wpn) && wpn->query_size()>1)
    {
      tell_object(TP, "%^BOLD%^%^RED%^You fumble for your " 
                   + wpn->query_name() + "%^BOLD%^%^RED%^,"
                   +" but there's just no room to wield it here!");
      tell_object(TP, "You'll have to try a smaller weapon, or fight empty"
                   +" handed.");
      return 1;
    }
  }
  return 0;

}

string long_desc()
{
  string result;
  result = "%^BOLD%^%^BLACK%^You are in the belly of a %^BOLD%^%^GREEN%^snake"
    +"%^BOLD%^%^BLACK%^, tucked snugly against rippling walls of %^RESET%^"
    +"%^MAGENTA%^muscle%^BOLD%^%^BLACK%^, and surrounded in a bath of"
    +" %^GREEN%^corrosive d%^BOLD%^i%^RESET%^%^GREEN%^g%^BOLD%^e%^RESET%^"
    +"%^GREEN%^st%^BOLD%^i%^RESET%^%^GREEN%^ve juices%^BOLD%^%^BLACK%^. If"
    +" you ever get out of here, you are %^BOLD%^%^MAGENTA%^NOT"
    +" %^BOLD%^%^BLACK%^going to be smelling nice.";
  if (query_exit("out")!="/d/shadowgate/void")
  {
    result += " %^BOLD%^%^RED%^A gaping, %^RESET%^%^RED%^bloody%^BOLD%^%^BLACK%^"
      +" hole%^RED%^ torn in the walls of the%^GREEN%^ snake's %^RESET%^"
      +"%^MAGENTA%^i%^BOLD%^nn%^RESET%^%^MAGENTA%^ar%^BOLD%^d%^RESET%^"
      +"%^MAGENTA%^s%^BOLD%^%^RED%^ offers a way out.";
  }
  return result;
}

void reset()
{
  object walls;
  ::reset();
  remove_exit("out");
  if (!objectp(snake))
  {
    if (objectp(room))
    {
      add_exit( base_name(room), "out");
    } else
    {
      add_exit(JUNG_ROOM8 + "j_maze0", "out");
    }
  }
  if (!present("walls", TO))
  {
    walls = new(MOB + "stomach_lining");
    walls->move(TO);
  }
}

void set_snake(object s)
{
  snake = s;
  room = environment(s);
}

object query_snake()
{
  return snake;
}

int is_stomach()
{
  return 1;
}
