#include "../tomb.h"

inherit TOMBSTR;

void create(){
    ::create();
    set_name("Necropolis");
    set_short("%^BOLD%^%^BLUE%^Fountain of Souls, %^WHITE%^Tomb of Nurval%^RESET%^");
    set_long(
"%^BOLD%^%^BLUE%^Fountain of Souls, %^CYAN%^The ground level of %^WHITE%^Tomb of Nurval%^RESET%^
%^BOLD%^%^WHITE%^The tunnels converge here in a large hollow chamber made of pearl-white marble. In the center of it, from the round hole in the floor, raises into a similar hole in the ceiling a fountain of %^CYAN%^sky blue%^WHITE%^ light. Numerous undead gather around it, most stand prostrating themselves in a trance, looking at the light. Occasionally someone steps into the light and floats up or down, or someone floats up from below or down from above. The light is harmless to the undead traviling it, and the traffic between layers of the pyramid is busy here.
");
    set_exits(([
                   "north":ROOMS+"/tomb2",
                   "west":ROOMS+"/tomb1",
                   "south":ROOMS+"/tomb4",
                   "east":ROOMS+"/tomb3",
                   "up":ROOMS+"/fountain2",
                   ]));
    set_pre_exit_functions(({"up"}),({"soulwell_trav"}));
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
    if (!present("guard"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 2"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 3"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 4"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 5"))
        new(MONS + "/necroknight")->move(TO);
    if (!present("guard 6"))
        new(MONS + "/necroknight")->move(TO);
}
