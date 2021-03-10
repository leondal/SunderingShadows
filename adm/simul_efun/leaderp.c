//     /adm/simul_efun/leaderp.c
//     Nightmare Mudlib
//     Returns 1 if a player is a council member as defined in council.h
//     else returns 0
//     By Gregon@Nightmare 30Dec93


#include <council.h>


int leaderp(object ob) {
    if(!ob) ob = previous_object();
    if(member_array(ob->query_name(), COUNCIL)==-1)
         return 0;
     return 1;
}
