#include <std.h>
#include <daemons.h>

inherit ROOM;

int done;
void create(){
  ::create();
  set_property("no teleport",1);
  set_property("used sticks",1);
  set_property("indoors",1);
  set_terrain(BUILT_CAVE);
  set_travel(PAVED_ROAD);
}

int is_junk(object obj)
{
    if(obj->id("summoned monster")) { return 0; }
    if(obj->id("sign")) { return 0; }
    if(obj->id("corpse")) { return 0; }
    if(obj->id("statue")) { return 0; }
    if(obj->query_property("died time")) { return 0; }
    if(!living(obj)) { return 1; }
    else return 0;
}

void init() {
  ::init();
do_random_encounters(({"/d/attaya/mon/archer.c","/d/attaya/mon/archer2.c","d/attaya/mon/phalanx.c","/d/attaya/mon/guardian.c","/d/islands/common/mon/scorpion.c","/d/attaya/mon/nightstalker.c","/d/attaya/mon/poltergeist.c","/d/attaya/mon/uwarrior.c","/d/attaya/mon/toclhar.c","/d/islands/common/mon/necrophidius.c","/d/attaya/mon/solstice.c","/d/attaya/mon/entity"}),15,1);
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
        if(sizeof(junk))
        {
            for(i=0;i<sizeof(junk);i++) { junk[i]->remove(); }
        }
    }
    if(sizeof(living))
    {
        tell_room(TO,"%^BOLD%^Spirits of the fallen swirl all around, searching "
            "for supplies for Intruder's army.");
    }

    "/d/attaya/base/spec/base_cd"->make_monsters(TO,6,15,1);
}
