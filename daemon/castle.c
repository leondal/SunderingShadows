#include <dirs.h>
#include <objects.h>
#include <security.h>

private mapping __Rooms;

void create() {
    string *ls;
    int i;

    seteuid(getuid());
    __Rooms = ([]);
    i = sizeof(ls = get_dir(CASTLES_DIRS+"/"));
    while(i--)
      catch(call_other(CASTLES_DIRS+"/"+ls[i]+"/castle", "init_castle"));
}

object query_room(string who, string save_file) {
    if(!who || !save_file) return 0;
    if(!__Rooms[who]) __Rooms[who] = ([]);
    if(!__Rooms[who][save_file]) {
        __Rooms[who][save_file] = new(OB_HM_ROOM);
        seteuid(UID_HM);
        __Rooms[who][save_file]->setup(CASTLES_DIRS+"/"+who+"/"+save_file);
        seteuid(getuid());
    }
    return __Rooms[who][save_file];
}

void add_room(string who, string long, string short, string *first_exit, string dir) {
    string save_file;
    object tmp;

    if(file_size(CASTLES_DIRS+"/"+who+"/") != -2) return;
    if(!__Rooms[who]) __Rooms[who] = ([]);
    __Rooms[who][save_file="room"+sizeof(get_dir(CASTLES_DIRS+"/"+who+"/"))] =
      new(OB_HM_ROOM);
    __Rooms[who][save_file]->set("long", long);
    __Rooms[who][save_file]->set("short", short);
    __Rooms[who][save_file]->set_exits(({first_exit[0]}),({first_exit[1]}));
    query_room(who, first_exit[0])->add_exit(save_file, dir);
    seteuid(UID_HM);
    __Rooms[who][save_file]->set_save_file(save_file);
    __Rooms[who][save_file]->set_owner(who);
    seteuid(getuid());
    __Rooms[who][save_file]->do_save();
}
