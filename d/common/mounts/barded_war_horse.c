#include <std.h>
inherit "/d/common/mounts/war_horse.c";

void create(){
    ::create();
    new("/d/common/obj/armour/barding")->move(TO);
    command("wear barding");
}

int enter(string str){
      if(TP->is_class("paladin")) set_overall_ac(6 - (int)TP->query_class_level("paladin")/2);
      if(TP->is_class("cavalier")) set_overall_ac(6- (int)TP->query_class_level("cavalier")/2);
      if(TP->is_class("antipaladin")) set_overall_ac(6 - (int)TP->query_class_level("antipaladin")/2);
    return ::enter(str);
}
