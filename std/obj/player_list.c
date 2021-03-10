#include <std.h>
#include <daemons.h>

inherit OBJECT;

void create() {
    mapping *tmp_arr;
    string *tmp;
    int i, max;

    set_name("list");
    set("id", ({ "list", "list of adventurers", "adventurers list" }) );
    set("short", "a list of the most successful adventurers");
    set("long", "This is a sheet of paper detailing "+mud_name()+"\n"+
      "most experienced adventurers.\n");
    set_weight(100);
    set("value", 20);
    tmp = ({ "    Name", "Class", "Exp", "Qst/Deeds/Died/Kill" });
    for(i=0,max=sizeof(tmp_arr=(mapping *)PLAYER_D->query_player_list());i<max;i++) {
        tmp += ({ (i<9 ? " "+(i+1)+") " : (i+1)+") ")+capitalize(tmp_arr[i]["name"]) });
        tmp += ({ capitalize(tmp_arr[i]["class"]) });
        tmp += ({ tmp_arr[i]["experience"] });
        tmp += ({ tmp_arr[i]["quests"]+" / "+tmp_arr[i]["major accomplishments"]+" / "+tmp_arr[i]["deaths"]+" / "+tmp_arr[i]["kills"] });
    }
    set("read",
      "The most successful adventurers of "+mud_name()+" as of "+
      hour(time())+":"+minutes(time())+" on "+month(time())+" "+date(time())+", "+year(time())+" NM:\n"+
      format_page(tmp, 4)
    );
    set_destroy();
}
