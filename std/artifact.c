//  std/artifact.c for the Emerald MUD lib
//  by Kriton@Emerald MUD
//  30 August 1994
//
//  Contains special functions for artifact objects.

#include <std.h>
#include <daemons.h>

inherit OBJECT;

int house_value;

int query_point_value();
void set_point_value(int x);
int is_artifact();

void create()    {   ::create();    }

int is_artifact()   {   return 1;    }

void set_point_value(int x)    {   house_value = x;   }

void remove()    {
  if(previous_object()->is_player() && !archp(previous_object())) return;
  Object::remove();
}

int query_point_value()   {   
  if(!house_value) return 1;
    else return house_value;
}

int get()    {
  object pc;
  string family;
  pc = this_player();
  if(wizardp(pc)) return 0;
/*
  if(pc->query_family())   {
    family = pc->query_family();
    GOVERNMENT->register_owner(this_object(),family);
  }
*/
  return 1;
}

