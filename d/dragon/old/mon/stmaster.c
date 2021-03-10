// Fire Dragon Original.. Stablemaster/traner (TANNER)
// Sometime in fall 1995
// (grin)

give_horse(string type, object owner);

#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("orvig");
  set_id( ({ "orvig", "trainer", "stablemaster", "dwarf" }) );
  set_short("Orvig, the stablemaster");
  set_long("This very sturdy dwarf looks very strong and capable of doing "
           "his profession of training horses well.\n");
  set_gender("male");
 set_race("dwarf");
  set_body_type("human");
  set_class("fighter");
  set_level(19);
}

void init()
{
  ::init();
  add_action("buy","buy");
}

int buy(string str)
{
  if(!str)
   {
     write("buy <mount name>");
     return 1;
   }

  switch(str)
           {
     case "steppe pony": case "steppe":
          if( (int)TP->query_level() < 11 )
           {
              write("%^MAGENTA%^Orvig says%^RESET%^: The steppe pony is for level 11 or higher.");
             return 1;
             break;
           }
           else
            give_horse("steppe",TP);
          return 1;
          break;

     case "medium warhorse": case "medium":
          if( (int)TP->query_level() < 11 )
           {
              write("%^MAGENTA%^Orvig says%^RESET%^: The medium warhorse is for level 11 and up.");
             return 1;
             break;
           }
           else
            give_horse("medium",TP);
          return 1;
          break;

     case "heavy warhorse": case "heavy":
          if( (int)TP->query_level() < 11 )
           {
              write("%^MAGENTA%^Orvig says%^RESET%^: The heavy warhorse is for level 11 and up.");
             return 1;
             break;
           }
           else
            give_horse("heavy",TP);
          return 1;
          break;

      default: write("%^MAGENTA%^Orvig shouts%^RESET%^: We don't sell "+ str +"s here.");
              return 1;
   }
  return 1;
}


void give_horse(string type, object owner)
{
  int cost;
  string type_l;
  object horse;

  switch(type)
   {
     case "steppe" :  cost = 200;
                      type_l = "steppe pony";
                      break;
     case "medium" :  cost = 225;
                      type_l = "medium warhorse";
                      break;
     case "heavy"  :  cost = 400;
                      type_l = "heavy warhorse";
                      break;
   }

   if(!owner->query_funds("gold",cost))
   {
       write("%^MAGENTA%^Orvig shouts%^RESET%^: You don't have enough gold for a "+ type_l +"!");
      return;
   }

  write("Orvig collects "+ cost +" gold from you, and leads your "+ type_l 
       +" out of a stall.");
  say("Orvig collects some gold from "+ owner->query_cap_name() +", and "
      "leads a "+ type_l +" out of a stall.");

   owner->use_funds("gold",cost);
  type  = "/d/koenig/town/mounts/"+ type +"1.c";
  horse  = new( type );
   horse->set_owner(owner);
   horse->move(environment(owner));
   owner->add_pet(horse);
}
