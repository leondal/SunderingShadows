#include <std.h>
#include <daemons.h>

inherit ROOM;

void create(){
    ::create();
    set_short("%^RESET%^%^BOLD%^%^WHITE%^Obsidian %^BLACK%^s%^WHITE%^tair%^BLACK%^c%^BLACK%^a%^WHITE%^se%^RESET%^");    
    set_long("%^RESET%^%^BOLD%^%^WHITE%^Obsidian %^BLACK%^s%^WHITE%^tair%^BLACK%^c%^BLACK%^a%^WHITE%^se%^RESET%^
%^RESET%^%^BOLD%^%^BLACK%^You are upon the Obsidian Staircase of the Kinnesaruda, a series of steps and mountain ledges that winds its way from the %^RED%^Ri%^RESET%^%^RED%^v%^BOLD%^%^RED%^er %^RESET%^%^RED%^o%^BOLD%^%^RED%^f %^RED%^Fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^me%^BLACK%^ to the %^RESET%^%^WHITE%^C%^WHITE%^r%^BOLD%^%^WHITE%^ystalline %^WHITE%^T%^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^wer%^BLACK%^ of the Black Dawn. Just beneath you is the dock on the River of Flame. The smoke makes strange shadows upon it, like hands attacking it.
");
    set_property("no teleport",1);
    set_climate("mountain");
    set_travel(LEDGE);
    set_terrain(OLD_MOUNTS);
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

    "/d/attaya/spec/attaya_cd"->make_monsters(TO,4,15,1);
}

