//adapted from the Shadow guards for Tonovi.  Circe 5/1/04
#include <std.h>
#include <daemons.h>

#define WATCH "/d/dagger/tonovi/guards/watch"
#define GUARD "/d/dagger/tonovi/guards/guard"
#define GUARDNAMES "/d/dagger/tonovi/guards/guards.lst"
#define MAX 100

inherit DAEMON;

nosave object * watch = ({});
nosave string * names2;

mapping wanted = ([]);

void SAVE(){
    save_object(base_name(TO));
}

void RESTORE(){
    restore_object(base_name(TO));
}

int clean_up(){
    return 1;
}

create(){
    ::create();
    RESTORE();
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
        guard->add_id("tonovi law");
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
void guard_party(object room){
    object guard;
    object leader;
    int count;

    count = 2+random(3);

    if(sizeof(watch) + count > MAX) {
        count = MAX - count;
    }
    while(count) {
        guard = new (GUARD);
        guard->add_id("tonovi law");
        watch += ({guard});
        if(!leader) {
            leader = guard;
            leader->move(room);
            //leader->set_speed(60);
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
    broadcast_area("/d/dagger/tonovi/town", "%^BOLD%^%^RED%^A horn blows, followed by voices shouting the alarm.");
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


int add_wanted(mixed live){
    string name, alias;


    if (objectp(live)) {
        if (!userp(live)) {
            return 0;
        }
        name = live->query_name();
        alias = live->query_title();
    } else {

        name = TP->realName(live);
          if(!stringp(name) || (name == "" && !avatarp(TP))){
            return 0;
        }
    if (name == "" && avatarp(TP)) name = live;
        alias = "/adm/daemon/user_call"->user_call(name,"query_title");
    }

    wanted[name] = (["name":name,"alias":alias]);
    SAVE();
    return 1;

}

mapping query_wanted(){
    return wanted;
}

//added by Styx to use for the lists in /d/shadow/room/city/jail_main.c
//stolen by Circe to use for the lists in /d/dagger/tonovi/town/jail_main.c
void query_wanted_name() {
    return keys(wanted);
}

int remove_wanted_name(string str){
    if (wanted[str]) {
        map_delete(wanted,str);
    }
    SAVE();
    return 1;
}

int remove_wanted(mixed live){
    string name;
    if (objectp(live)) {
        if (!userp(live)) {
            return 0;
        }
        name = live->query_name();
    } else {
        name = TP->realName(live);
    }
    if (wanted[name]) {
        map_delete(wanted,name);
    }
    SAVE();
    return 1;
}

int isWanted(mixed live){
    string name;
    if (objectp(live)) {
        if (!userp(live)) {
            return 0;
        }
        name = live->query_name();
    } else {
        name = TP->realName(live);
    }
    if (wanted[name]) {
        return 1;
    }
    return 0;
}
