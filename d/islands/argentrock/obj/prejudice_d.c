#include <std.h>
#include "../prejudice.h"
inherit DAEMON;

int query_elf_prejudice(object live){
    int race, subrace, bad_race;
    if(!objectp(live)) return 0;
    if(wizardp(live)) return 0;
    race = (string)live->query_race();
    subrace = (string)live->query("subrace");
    bad_race = member_array(race, ELFPREJ);

    //on bad standard race list
    if(bad_race != -1 && !live->query_property("shapeshifted")) return 1;

    //un-altered fey'ri and tieflings in natural demonic form (can't be druids)
    if((race == "elf" || race == "human") &&
       (subrace == "fey'ri" || subrace == "tiefling" ) &&
       !live->query_property("altered")
    ) return 1;

    else return 0;
}
