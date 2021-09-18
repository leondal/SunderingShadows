//ACTIVELY USED

// room_d.c
//Updating this to allow for other use and to
//make each thing (trainers/laerad caves/tharis forest, etc)
//have its own save file - the benefit of this
//is that it shouldn't break anymore
//and it should allow for future use of
//rooms moving around - so if someone makes
//an area they want to have a random room
//or random room entrance, that would
//just need to do something like
///daemon/room_d.c->register_moving_room("save_file_name", "moving_room_name",
//"enter exit", "out exit", ({"possible place 1", "possible place 2"}), etc.
//Saide - April 1st, 2009

#include <std.h>
#include <daemons.h>
#include <security.h>

#define SAVEFILE "/daemon/save/rooms"
#define TRAINERSAVEFILE "/daemon/save/rooms/trainers"
#define AREASAVEFILE "/daemon/save/rooms/area_saves"
#define SAVE_DIR "/daemon/save/rooms/"
#define ERROR 0

inherit DAEMON;

mapping __NeededRooms;
nosave mapping NeededRooms;
nosave mapping MobilRooms;
string *__AreaSaves;
nosave string *AreaSaves;
mapping whatWhere;
string RoomDisabled;
string EnterName, ExitName;

void create(){
    ::create();
    whatWhere=([]);
    MobilRooms = ([]);
    __AreaSaves = ({});
    __NeededRooms = ([]);
    NeededRooms = ([]);
    AreaSaves = ({});
    RoomDisabled = "0";
    //if(file_exists(SAVEFILE+".o"))
    //Restore();
    if(file_exists(AREASAVEFILE+".o"))
        RestoreAreaFile();
    if(file_exists(TRAINERSAVEFILE+".o"))
        RestoreTrainerFile();
    RandomizeRooms("all");
}

//In order to prevent a random room from
//being placed, without deleting its
//save file or some such - Saide - 4/09
int disable_room(string savename, string x)
{
    string prev;
    string droom, droomt, exit, enter;
    if(!AreaSaves || !sizeof(AreaSaves))
    {
        if(file_exists(AREASAVEFILE+".o"))
        {
            RestoreAreaFile();
        }
    }
    if(!sizeof(AreaSaves)) return 0;
    if(member_array(savename, AreaSaves) == -1) return 0;
    if(RestoreThisArea(savename))
    {
        prev = RoomDisabled;
        RoomDisabled = x;
        droom = keys(whatWhere)[0];
        SaveThisArea(savename);
        if(x == "0" && prev != x)
        {
            RandomizeRooms(savename);
        }
        if(x == "1" && prev != x)
        {
            droomt = MobilRooms[droom];
            droomt = explode(droomt, "&")[0];
            exit = explode(MobilRooms[droom], "&")[1];
            enter = explode(MobilRooms[droomt],"&")[1];
            droomt->remove_exit(enter);
            droom->remove_exit(exit);
            delete_mobil_room(droom);
            delete_mobil_room(droomt);
        }
    }
}
//End of random room disabling code


//Function to register another moving
//room - Saide
void register_moving_room(string save_name,
string room_file, string enter_name, string exit_name,
string *places)
{
    string *nrooms;
    if(!save_name) return;
    if(!room_file) return;
    if(!enter_name) enter_name = "enter";
    if(!exit_name) exit_name = "out";
    if(file_exists(SAVE_DIR+save_name+".o")) return;
    if(member_array(save_name, AreaSaves) != -1) return;
    if(!sizeof(places)) return;
    room_file = explode(room_file, ".c")[0];
    nrooms = places;
    explode(implode(nrooms, ""), ".c");
    if(sizeof(nrooms) <= 1) nrooms = places;
    EnterName = enter_name;
    ExitName = exit_name;
    RoomDisabled = "0";
    whatWhere = ([room_file : nrooms]);
    SaveThisArea(save_name);
    AreaSaves += ({save_name});
    SaveAreaFile();
    RandomizeRooms(save_name);
    return;
}
//End of function to register another
//moving room.

void ConvertOldRooms()
{
    int x;
    mapping ThisWhatWhere;
    string *rkeys, tkey, *nrooms;
    if(!file_exists(SAVEFILE+".o")) return;
    Restore();
    ThisWhatWhere = whatWhere;
    rkeys = keys(ThisWhatWhere);
    for(x = 0;x < sizeof(rkeys);x++)
    {
        nrooms = ThisWhatWhere[rkeys[x]];
        nrooms = explode(implode(nrooms, ""), ".c");
        if(sizeof(nrooms) <= 1) nrooms = ThisWhatWhere[rkeys[x]];
        tkey = explode(rkeys[x], ".c")[0];
        if(rkeys[x] == "/d/laerad/parnelli/asgard/as43")
        {
            register_moving_room("estal",
            tkey, "", "",
			nrooms);
			continue;
		}
		if(rkeys[x] == "/d/islands/tonerra/compshop.c")
		{
			register_moving_room("comp_shop",
			tkey, "", "",
			nrooms);
			continue;
		}
		if(rkeys[x] == "/d/tharis/forest/good1")
		{
			register_moving_room("tharis_forest_good",
			tkey, "", "",
			nrooms);
			continue;
		}
		if(rkeys[x] == "/d/tharis/forest/evil1")
		{
			register_moving_room("tharis_forest_evil",
			tkey, "", "",
			nrooms);
			continue;
		}
		if(rkeys[x] == "/d/laerad/parnelli/systyquah/hut17")
		{
			register_moving_room("troll_comp_shop",
			tkey, "", "",
			nrooms);
			continue;
		}
		if(rkeys[x] == "/d/laerad/parnelli/forest/hut")
		{
			register_moving_room("hansoth_quest_giving",
			tkey, "", "",
			nrooms);
		}
	}
}

int set_rooms(string room,string player,string dest)
{
    object ob;
    if(!NeededRooms) NeededRooms = ([]);
//	if(__NeededRooms == ([]) || !__NeededRooms[room])
//		__NeededRooms[room] = ""+player+"&"+dest+"";
//	else return ERROR;
    if (member_array(room, keys(NeededRooms)) != -1) return ERROR;
    else NeededRooms[room] = ""+player+"&"+dest+"";
    SaveTrainerFile();
    if(objectp(find_object(room)))
    {
        if(!present("signpost",find_object(room)))
        {
            ob = new("/d/shadow/obj/special/signpost");
            ob->set_dest(dest);
            ob->set_player(player);
            ob->move(room);
        }
	}
	return 1;
}

void inhere(string name)
{
    object ob;
    string room, player;
    if(!NeededRooms || NeededRooms == ([])) return;
    if(!NeededRooms[name]) return 0;

    if(sscanf(NeededRooms[name],"%s&%s",player,room) != 2) return 0;

    if (!user_exists(player))
	{
        map_delete(NeededRooms,name);
        SaveTrainerFile();
        return;
    }
    if (name != (string) USERCALL->user_call(player,"query","advance place"))
    {
        map_delete(NeededRooms,name);
        SaveTrainerFile();
        return;
    }
    if(!objectp(PO)) return;
    if(!present("signpost", PO) && !PO->query("alternative world"))
    {
        ob = new("/d/shadow/obj/special/signpost");
        ob->set_dest(room);
        ob->set_player(player);
        ob->move(PO);
    }
}

void remove_room(string name)
{
    if(!NeededRooms || NeededRooms == ([])) return;
    if(!NeededRooms[name]) return 0;

    map_delete(NeededRooms,name);
    SaveTrainerFile();
}

int delete_mobil_room(string room)
{
    if(!MobilRooms || MobilRooms == ([])) { return 0; }
    if(!MobilRooms[room]) { return 0; }
    map_delete(MobilRooms,room);
    return 1;
}

int set_mobil_rooms(string room, string dest, string exit)
{
    if(!MobilRooms) MobilRooms = ([]);

    MobilRooms[room] = dest+"&"+exit;
    log_file("living/mobile_rooms",identify(PO)+", "+room+", "+dest+", "+exit+".\n");

    //Save();
    return 1;
}

string query_new_dest(string name)
{
    if(!MobilRooms || MobilRooms == ([])) return 0;
    if(!MobilRooms[name]) return 0;

    return MobilRooms[name];
}

mapping query_mobil_rooms(){return MobilRooms;}

int cleanup(){return 1;}

int rename_Randroom(string old_name,string new_name)
{
    string *places=({});
    if(!stringp(old_name) || old_name == "") { return 0; }
    if(!stringp(new_name) || new_name == "") { return 0; }
    if(!pointerp(whatWhere[old_name])) { return 0; }
    places = whatWhere[old_name];
    whatWhere[new_name] = places;
    map_delete(whatWhere,old_name);
    //Save();
    return 1;
}

void set_Randrooms(string file, string *places){
    if(!whatWhere) whatWhere = ([]);
    whatWhere[file] = places;
    Save();
}

string * query_Randrooms(string file){  //added by Lujke to aid with bug checking
    return whatWhere[file];
}

mapping query_whatWhere()
{  //added by Lujke to aid with bug checking
    return whatWhere;
}

void remove_Randroom(string file)
{
    map_delete(whatWhere,file);
    //Save();
    return;
}


void RandomizeRooms(string which_area)
{
    int i,j, x, count;
    string where,exit,*key,*dest, fn;
    if(!sizeof(AreaSaves)) return;
    for(x = 0;x < sizeof(AreaSaves);x++)
    {
        fn = AreaSaves[x];
        if(fn != which_area && which_area != "all") continue;
        if(!RestoreThisArea(fn)) continue;
        if(RoomDisabled == "1") continue;
        if(!whatWhere) continue;
        key = keys(whatWhere);
        j = sizeof(key);
        for(i=0;i<j;i++)
        {
            count = 0;
            dest = whatWhere[key[i]];
            if(dest != ([]))
            {
                where = dest[random(sizeof(dest))];
                while(key[i] == where && count < 5)
                {
                    where = dest[random(sizeof(dest))];
                    count++;
                }
                if(count >= 5)
                {
                    log_file("room_d_errors", "Moving Room ("+
                    key[i] + ") added an entrance ("+
                    where+") into itself.");
                }
                if(!ExitName || ExitName = "") ExitName = "out";
                if(!EnterName || EnterName = "") EnterName = "enter";
                set_mobil_rooms(key[i],where,ExitName);
                set_mobil_rooms(where,key[i],EnterName);
            }
        }
    }
}

int clean_up(){return 1;}
string query_needed(string str)
{
    return NeededRooms[str];
}
mapping query_all_needed() { return NeededRooms; }
string * values_query_all_needed() { return values(NeededRooms); }
string * keys_query_all_needed() { return keys(NeededRooms); }
string *query_area_saves(){ return AreaSaves; }
int is_savename_okay(string fn)
{
    if(!AreaSaves) return 1;
    if(!sizeof(AreaSaves)) return 1;
    if(member_array(fn, AreaSaves) == -1) return 1;
    return 0;
}


//Adding all Save and Restore Functions
//to the bottom of the file now - Saide
//Note that Save() and Restore()
//probably shouldn't be used anymore

void Save(){
    seteuid(UID_DAEMONSAVE);
    save_object(SAVEFILE);
    seteuid(getuid());
}

void SaveTrainerFile()
{
    __NeededRooms = NeededRooms;
    whatWhere = ([]);
    RoomDisabled = "0";
    EnterName = "";
    ExitName = "";
    seteuid(UID_DAEMONSAVE);
    save_object(TRAINERSAVEFILE);
    seteuid(getuid());
    __NeededRooms = ([]);
}

void SaveAreaFile()
{
    __AreaSaves = AreaSaves;
    __NeededRooms = ([]);
    EnterName = "";
    ExitName = "";
    whatWhere = ([]);
    seteuid(UID_DAEMONSAVE);
    save_object(AREASAVEFILE);
    seteuid(getuid());
    __AreaSaves = ({});
}

int SaveThisArea(string file)
{
    if(!file) return 0;
    __NeededRooms = ([]);
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_DIR+file);
    seteuid(getuid());
    RoomDisabled = "0";
    whatWhere = ([]);
    return 1;
}
int RestoreThisArea(string file)
{
    if(!file) return 0;
    if(!file_exists(SAVE_DIR+file+".o")) return 0;
    whatWhere = ([]);
    RoomDisabled = "0";
    EnterName = "";
    ExitName = "";
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_DIR+file);
    seteuid(getuid());
    return 1;
}

void Restore()
{
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVEFILE);
    seteuid(getuid());
}
void Restore_Repair(string file){
    seteuid(UID_DAEMONSAVE);
    restore_object(file);
    seteuid(getuid());
}

void RestoreTrainerFile()
{
    seteuid(UID_DAEMONSAVE);
    restore_object(TRAINERSAVEFILE);
    seteuid(getuid());
    NeededRooms = __NeededRooms;
    __NeededRooms = ([]);
}

void RestoreAreaFile()
{
    seteuid(UID_DAEMONSAVE);
    restore_object(AREASAVEFILE);
    seteuid(getuid());
    AreaSaves = __AreaSaves;
    __AreaSaves = ({});
}
