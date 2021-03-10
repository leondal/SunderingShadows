#include <std.h>
#include <daemons.h>

inherit ROOM;

void create(){
  ::create();
  set_terrain(STONE_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("no teleport",1);
  set_property("used sticks",1);
}

int is_junk(object obj)
{
    if(obj->id("summoned monster")) { return 0; }
    if((int)obj->query_weight() > 50) { return 0; }
    if(obj->id("sign")) { return 0; }
    if(obj->id("corpse")) { return 0; }
    if(obj->query_property("died time")) { return 0; }
    if(!living(obj)) { return 1; }
    else return 0;
}

void reset()
{
    int i;
    object *junk,*living;
    ::reset();

    living = all_living(TO);
    living = filter_array(living,"is_non_immortal_player",FILTERS_D);    

    if(junk=filter_array(all_inventory(TO),"is_junk",TO) && !sizeof(living))
    {
        for(i=0;i<sizeof(junk);i++) { junk[i]->remove(); }
    }
    if(sizeof(living))
    {
        tell_room(TO,"%^BOLD%^Spirits of the fallen swirl all around, searching "
            "for supplies for Intruder's army.");
    }

}
