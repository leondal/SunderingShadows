#include "../tomb.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 3);
    set_property("indoors", 0);
    set_name("Necropolis");
    set_short("%^BLUE%^%^BOLD%^Observatory, %^BLACK%^Tomb of Nurval%^RESET%^");
    set_long(query_short() +
"
%^BLUE%^%^This small platform tips the %^BOLD%^%^BLACK%^obsidian%^RESET%^%^BLUE%^ pyramid. %^BOLD%^%^BLACK%^The floor here is a solid black glass.%^RESET%^%^BLUE%^ %^WHITE%^The light%^BLUE%^ that comes from the hole in the middle of this clearing converges at a %^WHITE%^crystal sphere%^%^BLUE%^%^ floating about fifty feet above the pyramid, and from there spreads over in beams to pylons scattered on the terrain below. From here %^BLUE%^ruins%^%^BLUE%^%^ of the city merged with the necropolis and tiny village on the eastern side are seen. Further to the northwest, Innsanely tall %^RED%^tower%^%^BLUE%^%^ raising from the dark mist somewhere far to the west. Mountains stand not far to the north behind scarce forest that expands to the east into a huge %^GREEN%^boreal taiga%^%^BLUE%^%^. To the east and southeast, behind rocky terrain and few cliffs, the sea touches the sky on the horizon. To the south, more cliffs, and towers of Torm almost disappear in the mist further far. All around you - open sky.
");
    set_exits(([
                   "down":ROOMS+"/fountain2",
                   ]));
    set_pre_exit_functions(({"down"}),({"soulwell_trav"}));
    set_heart_beat(0);
}

int soulwell_trav()
{
    tell_room(TO,"%^CYAN%^The light envelops "+TP->QCN+".%^RESET%^",TP);
    tell_object(TP,"%^CYAN%^The light envelops you.%^RESET%^");
    if(TP->is_undead())
        TP->cause_typed_damage(TP,TP->return_target_limb(),TP->query_max_hp()/3,"negative energy");
    return 1;
}

void reset()
{
    ::reset();

    if(!present("reaver", TP))
        new("/realms/kismet/mon/ashraplot/d_priest")->move(TO);
}
