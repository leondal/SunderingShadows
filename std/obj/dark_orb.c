/* Light absorbing orb cloned by the conjuring dark spell.
   See /bin/user/_dark.c for more info.
   By Valodin, Jan 16, 1993
*/

inherit "/std/Object";

int dark_level, dark_time;
object creator;

create()
{
  set_id( ({ "orb", "orb of darkness", "magical orb" }) );
  set_name("orb");
  set_short("An orb of darkness");
  set_weight(0);
  set_value(0);
  dark_level = 0;
  dark_time = 0;
}

void init()
{
  add_action("shatter", "shatter");
}

set_creator(object ob)
{
  creator = ob;
}

dark(int level, int time)
{
  dark_level = level;
  dark_time = time;
  environment(this_object())->set_property("light", -level);
  call_out("brighten", time);
}

int shatter(string str)
{
  if(!id(str))
  {
    notify_fail("Shatter what?\n");
    return 0;
  }
  if(this_player() != creator)
  {
    notify_fail("Only the creator of this orb can shatter it!\n");
    return 0;
  }
  write("You shatter your orb.\n");
  say(this_player()->query_cap_name()+" shatters " +
      this_player()->query_possessive()  + " orb.\n",
      this_player());
  tell_room(environment(this_player()), 
	    "The thousands of shards of darkness are quickly " +
            "absorbed by the light.\n");
  environment(this_object())->set_property("light", dark_level);
  remove_call_out("brighten");
    dark_level = 0;
  remove();
  return 1;
}

brighten()
{
  dark_level = dark_level - 1;
  environment(this_object())->set_property("light", 1);
  if(dark_level == 0)
  {
    if(!living(environment(this_object())))
      /* must be a room or bag */
      tell_object(environment(this_object()),
                  "The orb fades out of existence.\n");
    else
      /*  in a person */
    {
      tell_room(environment(environment(this_object())), "The orb that " +
                capitalize((string)environment(this_object())->query_name()) +
                " is carrying fades out of existence.\n",
                environment(this_object()));
      tell_object(environment(this_object()),
                  "The orb that you are carrying fades out of existence.\n");
    }
    remove();
  }
  else
  {
    if(!living(environment(this_object())))
      /* must be a room or bag */
      tell_object(environment(this_object()),
                  "The orb brightens slightly.\n");
    else
      /*  in a person */
    {
      tell_room(environment(environment(this_object())),
                "The orb that " +
                capitalize((string)environment(this_object())->query_name()) +
                " is carrying brightens slightly.\n",
                environment(this_object()));
      tell_object(environment(this_object()),
                  "The orb that you are carrying brightens slightly.\n");
    }
    call_out("brighten", dark_time);
  }
}

int move(mixed dest)
{
    int x;

    if(environment(this_object()))
      {
	environment(this_object())->set_property("light", dark_level);
      }    
    x = ::move(dest);
    if(environment(this_object()))
      {
	environment(this_object())->set_property("light", -dark_level);
      }
    return x;
}

int remove() {
    if(dark_level) 
      {
        if(environment(this_object()))
          environment(this_object())->set_property("light", -dark_level);
      }
    return ::remove();
}

