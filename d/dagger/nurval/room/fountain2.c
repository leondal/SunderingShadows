#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_name("Necropolis");
    set_short("%^BOLD%^%^BLUE%^Fountain of Souls, %^WHITE%^Tomb of Nurval%^RESET%^");
    set_long(
"%^BOLD%^%^BLUE%^Fountain of Souls, %^CYAN%^The second ground level of %^WHITE%^Tomb of Nurval%^RESET%^
%^BOLD%^%^WHITE%^The tunnels converge here in a large hollow chamber made of pearl-white marble. In the center of it, from the round hole in the floor, concentrates into a smaller hole in the ceiling a fountain of %^CYAN%^sky blue%^WHITE%^ light. Numerous undead gather around it, most stand prostrating themselves in a trance, looking at the light. Occasionally someone steps into the light and floats down, or someone floats up from below. The light is harmless to the undead traviling it, and the traffic between layers of the pyramid is busy here.
");
    set_exits(([
                   "north":ROOMS+"/tomb6",
                   "west":ROOMS+"/tomb5",
                   "south":ROOMS+"/tomb8",
                   "east":ROOMS+"/tomb7",
                   "up":ROOMS+"/observatory",
                   "down":ROOMS+"/fountain",
                   ]));
    set_pre_exit_functions(({"up","down"}),({"soulwell_trav","soulwell_trav"}));
    set_heart_beat(0);
}

int soulwell_trav()
{
    tell_room(TO,"%^CYAN%^%^BOLD%^The light envelops "+TP->QCN+".%^RESET%^",TP);
    tell_object(TP,"%^CYAN%^%^BOLD%^The light envelops you.%^RESET%^");
    if(TP->is_undead())
        TP->cause_typed_damage(TP,TP->return_target_limb(),TP->query_max_hp()/3,"negative energy");
    return 1;
}
