// /d/guilds/alliance/hall/dungeon.c

#include <std.h>

inherit VAULT;
//inherit "/std/gaol";

void create()
{
    object ob;
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    //set_property("no teleport",1);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_property("no phase", 1);
    set_indoors(1);
    set_light(1);
    set_short("The castle dungeon");
    set_long("%^CYAN%^The castle dungeon\n "+ //commenting out original description for use as a plot element
       "%^RED%^You are in the castle dungeon and the moist and cold "+
       "air chills your body. The dungeon is lit by a few torches but "+
       "vision is still a little blurry. There isn't much space down "+
       "here and this is certainly no place for a giant nor any surface "+
       "creature to be comfortable.\n");
       set_listen("default","You can hear the sound of water dripping and the "
       "screams from a few rats hiding here.");
       set_smell("default","You smell a strong mixture of dirt and burning torches.");
    set_exits(([
                   "up" : "/d/guilds/alliance/hall/stair2.c",
               ]));
    set_door("cell door", "/d/guilds/alliance/hall/stair2", "up", "alliance ring");
    set_open("cell door", 0);
    set_locked("cell door", 1);
    lock_difficulty("cell door", "/daemon/player_housing"->get_phouse_lock_dc("epic"));
    set_door_description("cell door", "This is a door made of three inch thick "
                         "oaken boards.  It has a section cut out and replaced with a grid of one "
                         "inch diameter iron bars so that some air can still get to the prisoners.");
    //set_string("cell door", "open", "The cell door creaks slightly as it swings open.");
    //set_string("cell door", "close", "An ominous thud echoes off the walls as the heavy cell door shuts solidly.");
    //"/d/guilds/alliance/hall/stair2"->set_open("cell door", 0);
    //"/d/guilds/alliance/hall/stair2"->set_locked("cell door", 1);
    //call_out("check",30);
}

void reset()
{
    ::reset();
    if (!present("jail food")) {
        new("/d/common/obj/misc/jailfood/j_food_basic.c")->move(this_object());
    }
    /*if (!present("malory")) {
        new("/realms/kismet/mon/malorybody.c")->move(this_object());
       }*/
}

/*void check(object obj)
   {
   int i, j, temp1, temp2, max;
   object *inven;
   inven = all_living(TO);
   j = sizeof(inven);
   for(i=0;i<j;i++) {
      if(!userp(inven[i])) continue;
      if(!inven[i]->query_bound()) continue;
      max = inven[i]->query_formula();
      temp1 = inven[i]->query_stuffed();
      temp2 = max/6;
      if(!(temp1 < (temp2*3))) continue;
      inven[i]->add_stuffed(500);
      tell_object(inven[i],"Some servants enter and feed you a rather plain yet filling meal.");
      tell_room(TO,"Some servants enter and feed "+inven[i]->query_cap_name()+" a simple meal.",inven[i]);
   }
   for(i=0;i<j;i++) {
      if(!userp(inven[i])) continue;
      if(!inven[i]->query_bound()) continue;
      max = inven[i]->query_formula();
      temp1 = inven[i]->query_quenched();
      temp2 = max/6;
      if(!(temp1 < (temp2*3))) continue;
      inven[i]->add_quenched(500);
      tell_object(inven[i],"Some servants enter and have you drink from a large waterskin.");
      tell_room(TO,"Some servants enter and have "+inven[i]->query_cap_name()+" drink from a waterskin.",inven[i]);
   }

   call_out("check",120);
   }*/
