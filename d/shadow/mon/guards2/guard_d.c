//
#include <std.h>

#define WATCH "/d/shadow/mon/guards/watch"
#define GUARDNAMES "/d/shadow/mon/guards/guards.lst"
#define MAX 50

inherit DAEMON;

object * watch = ({});
string * names2;

int clean__up(){
    return 1;
}

string do_name(){
      string names, name, *temp;
    int i;

    if (!names2){
    names = read_file(GUARDNAMES);

    names2 = explode(names,", ");
     }
     name = names2[random(sizeof(names2))];
     names2 -= ({name});
     return name;


}

void watch_party(object room){
    object guard;
    object leader;
    int count;

    count = 2+random(3);

    if(sizeof(watch) + count > MAX) {
        count = MAX - count;
    }
    while(count) {
        guard = new (WATCH);
        guard->add_id("shadow law");
        watch += ({guard});
        if(!leader) {
            leader = guard;
            leader->move(room);
            leader->set_speed(60);
        } else {
            guard->set_leader(leader);
            guard->move(room);
            leader->add_follower(guard);
            leader->add_protector(guard);
            guard->add_protector(leader);
            leader = guard;

        }
        count--;
    }

}

void blow_horn(object watchman){
    broadcast_area("/d/shadow/room/city", "%^BOLD%^%^YELLOW%^The warning horn blows alerting all the city watch.");
    broadcast_area("/d/shadow/room/main","%^BOLD%^%^YELLOW%^The warning horn blows alerting all the city watch.");
    broadcast_area("/d/shadowgate/adv_main", "%^BOLD%^%^YELLOW%^The warning horn blows alerting all the city watch.");
}

void call_watch(object watchman, object bad){
     int i;
     for(i=0;i<sizeof(watch);i++) {
         if(watch[i] != watchman) {
             if(objectp(watch[i])) {
                watch[i]->add_attacker(bad);
             }
         }
     }

}

void alert_gates(object watchman){

}
