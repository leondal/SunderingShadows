#include <std.h>
#define RACE_D "/adm/daemon/race_d.c"

int cmd_races(string str){
    string *race_list;
    string tmp;
    int i;

    tmp = "";
    if(str){
      if(!RACE_D->is_race(str)) return notify_fail("Not a valid race.\n");
      race_list = RACE_D->query_limbs(str);
    } else {
      race_list = RACE_D->query_races();
    }
    for(i=0;i<sizeof(race_list);i++){
      tmp += race_list[i] + ",  ";
    }
    tmp += "\n\n   Use <races [racename]> to see valid limbs.\n";
    tmp += "Wizzes also see <mraces> for other valid body types for mobs.";
    TP->more(explode(tmp, "\n"));
    return 1;
}

int help(){
    write(
      "Syntax: <races>  or <races [racename]>\n\n"
      "<races> alone will give you a list of all races on the mud you can use "
	"(plus some you can't at this time.) <races [racename]> where racename "
	"is a name from 'races' will give you all the limbs of that race, for "
	"use in armors and weapons.\n"
	"Wizzes - see also <mraces> for other body types available for mobs."
    );
    return 1;
}
