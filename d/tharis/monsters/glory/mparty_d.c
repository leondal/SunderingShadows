// mparty_d.c

//will form parties of the glory hunters and place then in the game
// will form on stimulus or automatically based on similar code to scavengers_d.c


#include <std.h>

#define SIZE 6
// cutting back to only 6 too so they won't as often overlap and kill each other with fewer places to load, *Styx* 12/16/03

#define GLORY_DIR "/d/tharis/monsters/glory/"
// I removed the antioch directory, since Antioch doesn't exist anymore. - g.
//   #define WHERE ({"/d/shadow/room/city/forkroad","/d/tharis/Tharis/market5","/d/antioch/village/main_st1","/d/deku/town/road5","/d/laerad/wasteland/waste82","/d/laerad/plains/plains27","/d/darkwood/room/road8","/d/tharis/road/wroad13","/d/dagger/drow/rooms/city2","/d/dagger/marsh/swamp/rooms/m42"})
// removing Laerad since it's being upgraded to more 20+, adding a couple of Deku places and the new areas west of Shadow *Styx*  12/16/03
// #define WHERE ({"/d/shadow/room/city/forkroad","/d/tharis/Tharis/market5","/d/deku/town/road5","/d/laerad/wasteland/waste82","/d/laerad/plains/plains27","/d/darkwood/room/road8","/d/tharis/road/wroad13"})

#define WHERE ({"/d/shadow/room/city/forkroad", "/d/tharis/Tharis/market5", "/d/deku/town/road5", "/d/deku/open/pass5", "/d/darkwood/camps/rooms/path/path03", "/d/darkwood/camps/rooms/orcamp/cpath20",  "/d/tharis/road/wroad13", "/d/shadow/juran/city/r11", "/d/shadow/juran/city/r45"})

inherit DAEMON;

object *glory;
object *hunters;
object *make_party(string path, int size);

void clean_up() {
    return 0;
}

void create() {
    ::create();
/*    glory = allocate(SIZE);
    hunters = ({});
 removing the callout until I find the source of this loading as T agreed to retire the GH's as antiquated even though we may revive them as bounty hunters eventually *Styx* 1/6/04, last change 12/16/03
    call_out("placeem",200);
*/
}

void placeem() {
    int i,j,k,num,m;
    int *pos;
    object *party;
    string x;
    int count = 0;

    pos = ({});
    num = sizeof(glory);
    for(k=0;k<num;k++) {
        if(!objectp(glory[k]))
            pos+=({k});
    }
    while(sizeof(pos) && count<5) {
        j = random(sizeof(pos))+1;
        while(j>4)
            j = random(sizeof(pos))+1;
        x=WHERE[random(sizeof(WHERE))];
        party = make_party(x,j);
        for(m=0;m<j;m++) {
            glory[pos[0]]=party[m];
            pos -= ({pos[0]});
        }
        count++;
    }
    call_out("placeem",1800);
}

object make_em() {
    int res;
    string type;
    object ob;

    res = random(8);
    switch(res) {
    case 0: type = "fighter";
        break;
    case 1: type = "bard";
        break;
    case 2: type = "mage";
        break;
    case 3: type = "cleric";
        break;
    case 4: type = "paladin";
        break;
    case 5: type = "ranger";
        break;
    case 6: type = "antipaladin";
        break;
    case 7: type = "thief";
        break;
    }
    ob = new(GLORY_DIR+"G"+type);
// This code to check if the GH has a user's name, and, if so, recreates it.
  while (user_exists(ob->query_name())) {
  ob->remove();
    ob=new(GLORY_DIR+"G"+type);
  }
    return ob;
}

object *make_party(string path, int size) {
    object *party, temp;
    int i,j;

    party = ({});
    for(i=0;i<size;i++) {
        temp = make_em();
        party += ({temp});
    }
    for(i=0;i<size;i++) {
        if(objectp(party[i]))
            for(j=0;j<size;j++) {
                party[i]->add_party(party[j]);
                if(party[i] != party[0]) {
                    party[0]->add_follower(party[j]);
                }
            }
    }
    party[0]->set_speed(30);
    for(i=0;i<size;i++) {
        party[i]->move(path);
    }
    hunters += party;
    return party;
}

object *query_glory() {
    int i,j,k,num;
    object *temp;

    temp = ({});
    num = sizeof(hunters);
    for(k=0;k<num;k++) {
        if(!objectp(hunters[k]))
            temp+=({hunters[k]});
    }
    hunters -= temp;
    return hunters;
}

void stop_load() {
  remove_call_out("placeem");
  glory->move("/d/shadowgate/void.c");
  glory->remove();
  destruct(TO);
  return;
}
