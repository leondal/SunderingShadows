/* coded with love for Cara */

inherit "std/Object.c";
#include <str_fmt.h>
#include <ansi.h>
#define ANSIEGG  RED + "e" + YEL + "a" + HIY + "s" + GRN + "t" + BLU + "e" + MAG + "r" + HIR + " e" + HIG + "g" + HIB + "g" + NOR

int strength;
int hidden;
string my_mess, your_mess, my_ansi_mess, your_ansi_mess;

int id(string str)
{  if(hidden) return 0; else return ::id(str); }

tell_env(ob, str, ansiflag)
{
    object *foo;
    int i;
    foo = all_inventory(environment(ob));
    foo = filter_array(foo, "is_living", this_object());
    foo -= ({ ob });
    if(ansiflag)
      foo = filter_array(foo, "is_ansi", this_object());
    else
      foo = filter_array(foo, "not_ansi", this_object());
    if(sizeof(foo))
      map_array(foo, "tell_me", this_object(), str);
    return;
}

tell_me(ob, str)
{
    tell_object(ob, str);
}

is_living(ob)
{
    return (living(ob)?1:0);
}

is_ansi(ob)
{
  return (ob->query_ansi());
}

not_ansi(ob)
{
  return (ob->query_ansi()?0:1);
}

create()
{
    set_no_clean(1);
  set_name("easter egg");
  set_id( ({ "egg", "easter egg" }) );
  set_short("An easter egg");
  set_long("This is a beautiful easter egg.  It looks yummy.\n" 
	   "If you don't want to eat it, you could hide it.\n");
  my_mess = 
    "You peel off all the colorful shell and pop the egg in your mouth.\n"
    "Mmmm, is it yummy.\n";
  your_mess =
    "peels an easter egg and eats it.\n";
  my_ansi_mess = 
    "You peel off all the " + YEL + "s" + HIY + "h" + RED + "e" + GRN + "l" + 
    BLU + "l" + NOR + " and pop the " + HIR + "e" + HIG + "g" + HIB + "g" +
    NOR + " in your mouth.\nMmmm, is it yummy.\n";
  your_ansi_mess =
    "peels an " + ANSIEGG + " and eats it.\n";
  strength = 5;
  if(random(4) == 2) {  /* candy */
    my_mess = 
      "You peel off all the colorful shell and it is full of candy, which "
      "you\nhungrily gobble up.  Mmmm, that tastes good.\n";
    your_mess =
      "peels an easter egg and eats the candy that was inside it.\n";
    my_ansi_mess = 
      "You peel off all the " + YEL + "s" + HIY + "h" + RED + "e" + GRN + "l" 
      + BLU + "l" + NOR + " and it is full of candy, which you\nhungrily" 
      " gobble up.  Mmmm, that tastes good.\n";
    your_ansi_mess =
      "peels an " + ANSIEGG + " and eats the candy that was inside it.\n";
    strength = 5;
  }
  if(random(20) == 8) {  /* rotten */
    my_mess = 
      "You peel off all the colorful shell and pop the egg in your mouth.\n"
      "Yeeech!!  It was rotten and you puke it all up.\n";
    your_mess =
      "peels an easter egg, eats it, and then pukes all over the\nplace.\n";
    my_ansi_mess = 
      "You peel off all the " + YEL + "s" + HIY + "h" + RED + "e" + GRN + "l" 
      + BLU + "l" + NOR + " and pop the " + HIR + "e" + HIG + "g" + HIB + "g" +
      NOR + " in your mouth.\nYeeech!!  It was rotten and you " + HIG + "puke" 
      + NOR + " it all up.\n";
    your_ansi_mess =
      "peels an " + ANSIEGG + 
      ", eats it, and then pukes all over the\nplace.\n";
    strength = -5;
  }
  set_value(0);
  set_weight(1);
  hidden = 0;
}

string query_short()
{
  if(hidden) return 0;
    return ::query_short();
  if(this_player()->query_ansi())
    return ("An " + ANSIEGG);
  else
    return ::query_short();
}

string query_long(string str)
{
  if(hidden) return 0;
  if(this_player()->query_ansi())
    return ("This is a beautiful " + ANSIEGG + ".  It looks yummy.\n" 
	   "If you don't want to eat it, you could hide it.\n");
  else
    return ::query_long();
}

init()
{
    add_action("eat","eat");
    add_action("hide", "hide");
    add_action("search", "search");
}

void set_strength(int x) {
    strength = x;
}

int query_strength() {
    return strength;
}

int eat(string str) {
    if(!id(str)) return 0;
    if(hidden) return 0;
    if(environment(this_object()) != this_player()) return 0;
    if(this_player()->query_current_attacker()) {
        notify_fail("You are too busy to eat anything!\n");
        return 0;
    }
    if(!this_player()->add_stuffed(strength)) {
	write("You are way too full for that!\n");
	return 1;
    }
    this_player()->heal(strength);
    if(this_player()->query_ansi())
      write(my_ansi_mess);
    else
      write(my_mess);
    tell_env(this_player(), this_player()->query_cap_name()+" "+your_mess, 0);
    tell_env(this_player(), this_player()->query_cap_name()+" "+
	     your_ansi_mess, 1);
    remove();
    return 1;
}

hide(string str)
{
  if(!id(str)) return 0;
  if(hidden) return 0;
  if(environment(this_object()) != this_player()) return 0;
  write("You hide an " + query_name() + ".\n");
  say(this_player()->query_cap_name() + " hides something.\n");
  hidden = 1;
  move(environment(this_player()));
  return 1;
}

search()
{
  if(!hidden) return 0;
  write("You find an " + query_name() + ".\n");
  tell_env(this_player(), this_player()->query_cap_name() + 
	   " finds an easter egg.\n", 0);
  tell_env(this_player(), this_player()->query_cap_name() + 
	   " finds an " + ANSIEGG + ".\n", 1);
  hidden = 0;
  return 1;
}

get(){ if (hidden) return 0; else return 1; }
