#include <std.h>
#include "/realms/grendel/grendel.h"
#include "/realms/grendel/include/races.h"

int ok_align(object ob);

int cmd_chkalign(){
    object *peo;
    int i, flag;

    peo = users();
    flag = 1;
    for(i=0;i<sizeof(peo);i++){
      if(interactive(peo[i]) && !peo[i]->query("align ok") && !avatarp(peo[i]) && (string)peo[i]->query_race() != "unborn" && !ok_align(peo[i])){
        tell_object(TP, (string)peo[i]->query_name()+" is a "+(string)peo[i]->query_race()+" with an alignment of "+align_abbrev((int)peo[i]->query_alignment()));
        flag = 0;
      }
    }
    if(flag) tell_object(TP, "None on.");
    return 1;
}

int ok_align(object ob){
    string race;
    int align;

    race = (string)ob->query_race();
    align = (int)ob->query_alignment();
    if(!objectp(ob)) return 1;
    if(!interactive(ob)) return 1;
   if(align == 0) return 1;
    if(member_array(align, RACE_ALIGN[race]) != -1) return 1;
    return 0;
}
