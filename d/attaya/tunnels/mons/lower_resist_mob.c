// Coded by Lujke. The triumph of ignorance over adversity
// This base file should allow a monster to use lower resistance with
// some degree of intelligence. If the monster sees its magic dispersing, 
// it will attempt to lower resistance on the target, unless it has seen // that target having its resistance lowered already.

// NB If you inherit this file to a mob that implements the 'catch_tell' 
// function, remember to have the mob pass the 'tell' string to the 
// 'catch_tell' function (eg ::catch_tell(str); ). 

#include <std.h>
#include "../tunnel.h"
#define ARRAY_SIZE 10
inherit "std/monster";

int lowering;
object * lowerattempt;
object *lowered_creatures;
void spin();
void lower_resistance(object ob);


create()
{
  ::create();
  lowered_creatures = allocate(ARRAY_SIZE);
  add_search_path("/cmds/mage");
  lowering = 0;

 }


void spin()
{
  if (!objectp(TO)){return;}

  tell_room(ETO, "%^BOLD%^%^GREEN%^" + TO->query_cap_name() + "%^BOLD%^"
                +"%^GREEN%^ notices " + TO->query_possessive() + " magic"
                +" dispersing and spins around to deal with the problem");
}

void lower_resistance(object ob)
{
  int j;
 lowering = 0;
 if (!objectp(ob)){ return; }
 if (ob->query_true_invis()){return;}

 // check if the mob knows this person has already had their 
 // resistance lowered, and don't bother trying to lower it again
 // if they have
 for (j=0;j<ARRAY_SIZE;j++)
 {
   if (lowered_creatures[j]==ob)
   {
   //The creature has already been lowered
     return;
   }
 }

  spin();
  new("/cmds/spells/l/_lower_resistance.c")->use_spell(TO, ob,query_class_level("mage"),100,"mage" );
}

void catch_tell(string str)
{
  int i,j;
  object ob;
  if(interact("Your magic disperses futilely around ", str))
  { 
  
 //    tell_room(ETO,"Finding the player the magic dispersed around");
     for (i=0;i<sizeof(all_living(ETO));i++)
     {
       if (interact(all_living(ETO)[i]->query_cap_name(), str))
       {
 //       tell_room(ETO,"It was: "+ all_living(ETO)[i]->query_cap_name());
          ob = all_living(ETO)[i];

      // Have the mob try to lower resistance if the target is a player
      // and the mob is not already trying to lower resistance (to prevent 
      // multiple attempts on the same/different targets all at once

          if (ob->is_player()&&lowering==0)
          {
            lowering = 1;
            call_out("lower_resistance", 2, ob);
            return; 
          }
      }
    }
  }
//watch for attempts to lower resistance in the room the monster is in
// and remember the name of the target of the most recent attempt to lower // resistance
  if (interact("an iron bar at ", str))
  {
    for (i=0;i<sizeof(all_living(ETO));i++)
    {
      if (interact(all_living(ETO)[i]->query_cap_name(), str))
      {
        if (all_living(ETO)[i]->query_true_invis()
             ||all_living(ETO)[i]->is_player() == 0)
        {
          return;
        }
        lowerattempt = all_living(ETO)[i];
        //keeps track of the last creature to have a lower resistance
        // attempt in the room. This is used to work out what creature 
        // has had its resistance lowered when the 'In a great forceful\
        // pull you can see the power yanked...' tell arrives.
        return;
      }
    }
   tell_room(ETO, str, TO);
  }

// watch for any successful castings of lower resistance, and add the name
// of the last person to have an attempt made to lower their resistance
// to the list of people the mob knows to have had their resistance 
// lowered

  if(interact("In a great forceful pull you can see power yanked", str))
  {
    if (!objectp(lowerattempt)){return;}
    if (lowerattempt->query_true_invis()){return;}
    if (!lowerattempt->is_player()){return;}

    for (i=0;i<sizeof(lowered_creatures);i++)
    {
      if (!objectp(lowered_creatures[i]))
      {
        lowered_creatures[i] = lowerattempt;
        break;
      }
    }
    tell_room(ETO, lowerattempt->query_cap_name() +" added to full list");
  }
// watch for any power returning to anyone in the room, and take that 
// creature off of the list of those the mob knows to have had their
// resistance lowered.

  if(interact("You see the wave of incoming power returning to", str))
  {
    for (i=0;i<ARRAY_SIZE;i++)
    {
      //check if the name of anything on the lowered list is within the
      //caught tell
      if (objectp(lowered_creatures[i]))
      {
        if (interact(lowered_creatures[i]->query_cap_name(), str))
        {
          lowered_creatures[i] = -1;
          return;
        }
      }
    }
    tell_room(ETO, str, TO);
  }
// test function for checking that the list is working properly
  if(interact("show list", str))
  {
   for (i=0;i<ARRAY_SIZE;i++)
    {
      if (objectp(lowered_creatures[i]))
      {
        tell_room(ETO, lowered_creatures[i]->query_cap_name()+"\n");
      }
    }
  }
}



