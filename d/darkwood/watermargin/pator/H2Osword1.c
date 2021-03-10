// the first part of the watersword
// H2)sword1.c
#include <std.h>

inherit "/std/weapon";


int rune_reading()
{
tell_object(this_player(),
"As you try to read the runes on the blade you get a vision of waterspirit
in a cave.  You feel that he can make this sword to the powerfull weapon
it once was !");
return 1;
}


int read(string str)
{
  if(str="runes" || str="sword" || str="blade")
    { rune_reading();return 1;}
  else { write("Read what ???");return 0;}
}

create()
{
   ::create();
   set_wield( (: this_object(), "weapon_wield" :) );
   set("id", ({ "sword", "longsword","hollow sword"}) );
   set_short("A hollow longsword ");
   set_long("This seems to be a very good blade,but surely there is missing something in it, as it sounds hollow !?");
   set_type("slash");
   set_weight(20);
   set_value("gold","10");
   set_wc(6);
 }
weapon_wield()
{
    tell_object(this_player(), "You feel the potential of the sword,but the power is not yet there!\n");
   
 return 1;
}

init(){
  ::init();
  add_action("knock_sword","knock");
 
  }

int knock_sword()
{
tell_object(this_player(),"As you knock on the sword, you hear a hollow sound");
return 1;
}

