 
/* Glowing orb cloned by the conjuring light spell.
   See /bin/user/_light.c for more info.
   By Valodin, Jan 15, 1993
*/
 
inherit "/std/Object";
 
int light_level, light_time;
object creator;
 
create()
{
  set_id( ({ "orb", "glowing orb", "magical orb" }) );
  set_name("orb");
  set_short("A glowing orb");
  set_weight(0);
  set_value(0);
  light_level = 0;
  light_time = 0;
}
 
void init()
{
  add_action("extinguish", "extinguish");
  add_action("darken", "darken");
}
 
set_creator(object ob)
{
  creator = ob;
}
 
light(int level, int time)
{
  light_level = level;
  light_time = time;
  environment(this_object())->set_property("light", level);
  call_out("dim", time);
}
 
 
int extinguish(string str)
{
  if(!id(str))
  {
    notify_fail("Extinguish what?\n");
    return 0;
  }
  if(this_player() != creator)
  {
    notify_fail("Only the creator of this orb can extinguish it!\n");
    return 0;
  }
  write("You extinguish your orb, leaving nothing.\n");
  say(this_player()->query_cap_name()+" extinguishes " +
      this_player()->query_possessive()  + " orb.\n",
      this_player());
  environment(this_object())->set_property("light", -light_level);
  remove_call_out("dim");
    light_level = 0;
    remove();
  return 1;
}
 
dim()
{
  light_level = light_level - 1;
  environment(this_object())->set_property("light", -1);
  if(light_level == 0)
  {
    if(!living(environment(this_object())))
      /* must be a room or bag */
      tell_object(environment(this_object()),
                  "The orb winks out of existence.\n");
    else
      /*  in a person */
    {
      tell_room(environment(environment(this_object())), "The orb that " +
                capitalize((string)environment(this_object())->query_name()) +
                " is carrying winks out of existence.\n",
                environment(this_object()));
      tell_object(environment(this_object()),
                  "The orb that you are carrying winks out of existence.\n");
    }
    remove();
  }
  else
  {
    if(!living(environment(this_object())))
      /* must be a room or bag */
      tell_object(environment(this_object()),
                  "The glow of the orb weakens slightly.\n");
    else
      /*  in a person */
    {
      tell_room(environment(environment(this_object())),
                "The glow of the orb that " +
                capitalize((string)environment(this_object())->query_name()) +
                " is carrying weakens slightly.\n",
                environment(this_object()));
      tell_object(environment(this_object()),
                  "The glow of the orb that you are carrying weakens" +
                  " slightly.\n");
    }
    call_out("dim", light_time);
  }
}
 
int move(mixed dest)
{
    int x;
 
    if(environment(this_object()))
      {
	environment(this_object())->set_property("light", -light_level);
      }
    x = ::move(dest);
    if(environment(this_object()))
      {
	environment(this_object())->set_property("light", light_level);
      }
    return x;
}
 
int remove() {
    if(light_level) 
      {
	environment(this_object())->set_property("light", -light_level);
      }
    return ::remove();
}
 
int darken(){
   if(this_player() != creator)
   {notify_fail("Only the creator of an orb can attenuate its brilliance\n");
    return 0;}
   
   remove_call_out("dim");
   dim(); 
   return 1;
}
