//ACTIVELY USED
//Not sure why. There is already virtual area functionality in Nightmare 3.

#include <std.h>
#include <daemons.h>
#include <security.h>

#define VDIR "/inv/virtual_rooms/"
#define VDIRFILE "/daemon/save/vrooms/vroom_information"

inherit DAEMON;

mapping RoomInfo;

void clear_data()
{
    string usr;
    string vroom;
    mapping vroom_info;
    int usr_count;

    foreach(vroom in keys(RoomInfo)) {
        usr_count = 0;
        vroom_info = RoomInfo[vroom];

        if (!sizeof(vroom_info["names"])) {
            map_delete(RoomInfo, vroom);
            continue;
        }

        foreach(usr in vroom_info["names"]) {
            if (user_exists(usr)) {
                usr_count++;
            }
        }

        if (!usr_count) {
            map_delete(RoomInfo, vroom);
            continue;
        }
    }
}

void virtual_room_d_save()
{
    seteuid(UID_ROOT);
    save_object(VDIRFILE);
    seteuid(geteuid());
}

void virtual_room_d_load()
{
    seteuid(UID_ROOT);
    restore_object(VDIRFILE);
    seteuid(geteuid());

    clear_data();
}

void check_virtual_d()
{
    if(!mapp(RoomInfo))
    {
        virtual_room_d_load();
    }
    if(!mapp(RoomInfo)) RoomInfo = ([]);
}

mapping returnRoomInfo()
{
    check_virtual_d();
    return RoomInfo;
}

mixed restore_virtual_room(string file)
{
    object targ;
    check_virtual_d();
    if(!RoomInfo[file]) return 0;
    if(RoomInfo[file]["destroyed room"])
    {
        return find_object_or_load(RoomInfo[file]["destroyed room"]);
    }
    if(objectp(RoomInfo[file]["current object"]))
    {
        return RoomInfo[file]["current object"];
    }
    targ = new(RoomInfo[file]["points to"]);
    targ->restore_me(file);
    RoomInfo[file]["current object"] = targ;
    virtual_room_d_save();
    return targ;
}

//this does not actually destroy the object file - instead it
//sets up a room for players to be moved to when a virtual room
//is destroyed - IE a boat they were on is dismissed, a tent they were in
//is picked up, etc. - Saide
int destroy_virtual_room(string file, object room)
{
    check_virtual_d();
    if(!stringp(file))  { return 0; }
    if(!RoomInfo[file]) { return 0; }
    if(!objectp(room))  { return 0; }
    //tell_room(room, "It is getting here....");
    RoomInfo[file]["destroyed room"] = base_name(room);
    virtual_room_d_save();
    return 1;
}

//old function - attempting to recode to account for
//moving/linked virtual rooms - Saide, April 2017
/*varargs void register_virtual_room(object ob, string file)
{
    string *files, save_name, new_save_name, *tmp;
    int x;
    check_virtual_d();
    if(!objectp(ob)) return;
    if(stringp(file)) save_name = file;
    else if(!stringp(save_name = ob->query("my_virtual_name")))
    {
        tmp = explode(file_name(ob), "/");
        save_name = time() + "_" + tmp[sizeof(tmp)-1];
        save_name = replace_string(save_name, "#", "&&");
        //save_name = VDIR + file_name(ob);
        files = get_dir(VDIR + save_name +"*.o");
        x = sizeof(files);

        if(x)
        {
            new_save_name = save_name + "_"+(x+1);
            while(file_exists(VDIR+new_save_name + ".o"))
            {
                x++;
                new_save_name = save_name + "_"+x;
            }
            save_name = new_save_name;
        }

        save_name = VDIR + save_name;
    }

    //tell_object(ob, "save_name = "+save_name);
    seteuid(UID_ROOT);
    ob->save_me(save_name);
    seteuid(geteuid());
    add_to_room_info(ob, save_name);
    ob->set("my_virtual_name", save_name);
    return save_name;
}*/

int compare_base_names(object room, string room_base)
{
    if(!stringp(room_base) || !objectp(room)) return 1;
    if(base_name(room) == room_base) return 1;
    return 0;
}

varargs void register_virtual_room(object ob, string file, string room_base)
{
    string *files, save_name, new_save_name, *tmp;
    int x;
    check_virtual_d();
    if(!objectp(ob)) return;
    if(!stringp(save_name = ob->query("my_virtual_name")))
    {
        tmp = explode(file_name(ob), "/");
        save_name = time() + "_" + tmp[sizeof(tmp)-1];
        save_name = replace_string(save_name, "#", "&&");
        //save_name = VDIR + file_name(ob);
        files = get_dir(VDIR + save_name +"*.o");
        x = sizeof(files);

        if(x)
        {
            new_save_name = save_name + "_"+(x+1);
            while(file_exists(VDIR+new_save_name + ".o"))
            {
                x++;
                new_save_name = save_name + "_"+x;
            }
            save_name = new_save_name;
        }

        save_name = VDIR + save_name;
    }
    if(compare_base_names(ob, room_base) && stringp(file)) save_name = file;
    //tell_object(ob, "save_name = "+save_name);
    seteuid(UID_ROOT);
    ob->save_me(save_name);
    seteuid(geteuid());
    add_to_room_info(ob, save_name);
    ob->set("my_virtual_name", save_name);
    return save_name;
}

void add_to_room_info(object room, string file)
{
    object *contents;
    string *MyNames = ({});
    int x;
    if(!objectp(room)) return;
    if(!stringp(file)) return;
    check_virtual_d();

    contents = all_living(room);
    if(!pointerp(MyNames)) MyNames = ({});
    for(x = 0;x < sizeof(contents);x++)
    {
        if(!objectp(contents[x])) continue;
        if(!userp(contents[x])) continue;
        if((string)contents[x]->query("my_virtual_room") != file)
        {
            remove_from_room_info((string)contents[x]->query("my_virtual_room"), contents[x]);
            contents[x]->set("my_virtual_room", file);
        }
        MyNames += ({contents[x]->query_name()});
        continue;
    }
    if(!RoomInfo[file])
    {
        RoomInfo[file] = ([ "names" : MyNames, "active" : 1, "points to" : base_name(room), "current object" : room, "destroyed room" : 0]);
    }
    else
    {
        if(pointerp(RoomInfo[file]["names"])) MyNames += RoomInfo[file]["names"];
        MyNames = distinct_array(MyNames);
        RoomInfo[file]["names"] = MyNames;
    }
    virtual_room_d_save();
    return;
}

void remove_from_room_info(string file, object who)
{
    string name, *MyNames = ({});
    if(!stringp(file)) return;
    check_virtual_d();
    if(!RoomInfo[file]) return;
    if(!objectp(who)) return;
    who->delete("my_virtual_room");
    name = who->query_name();
    if(!pointerp(RoomInfo[file]["names"])) return;
    MyNames = RoomInfo[file]["names"];
    if(member_array(name, MyNames) == -1) return;
    MyNames -= ({name});
    //MyNames = distinct_array(MyNames);
    RoomInfo[file]["names"] = MyNames;
    if(!sizeof(MyNames))
    {
        if(file_exists(file+".o"))
        {
            seteuid(UID_ROOT);
          //  tell_object(who, "It is getting here...");
            rm(file+".o");
            //tell_object(TP, rm(file));
            seteuid(geteuid());
        }
        //tell_object(who, "Outside of the file_exist check");
        map_delete(RoomInfo, file);
    }
    virtual_room_d_save();
    return;
}
