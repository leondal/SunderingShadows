// monster_d.c
// Please note this file now uses TWO database save files
// making the destination rooms load before moving in the master object NPC's to try to stomp the recursion bugs that spam the debug.log and keep the NPC's from fully loading *Styx* 12/18/05
#include <std.h>
#include <daemons.h>
#include <security.h>

#define ERROR 0

inherit DAEMON;

mapping unique_mons_where;
mapping cloned_mons_where;
nosave mapping to_be_placed;
nosave mapping deployed_mons;
nosave object * death_watchers;
// void Save();
// void Restore();
void place_mons(mapping monmap);
mapping load_mons_db(string fromfile);


void create()
{
    ::create();
    unique_mons_where = ([]);
    cloned_mons_where = ([]);
    to_be_placed = ([]);
    deployed_mons = ([]);
    //   if(file_exists(SAVEFILE+".o"))
    //      Restore();
    unique_mons_where=load_mons_db("/daemon/save/monsters_unique.db");
    cloned_mons_where=load_mons_db("/daemon/save/monsters_cloned.db");
    place_mons(unique_mons_where); // Side effects to
    place_mons(cloned_mons_where);   // to_be_placed mapping.
}


void remove_mon(string name)
{
    if(unique_mons_where && unique_mons_where != ([]))
    {
        if(unique_mons_where[name])
        {
            map_delete(unique_mons_where,name);
        }
    }

    if(cloned_mons_where && cloned_mons_where != ([]))
    {
        if(cloned_mons_where[name])
        {
            map_delete(cloned_mons_where,name);
        }
    }

    if(deployed_mons && deployed_mons != ([]))
    {
        if(deployed_mons[name])
        {
	        if(objectp(deployed_mons[name]))
            {
	            deployed_mons[name]->move("/d/shadowgate/void.c");
	            deployed_mons[name]->remove();
	        }
	        map_delete(deployed_mons,name);
        }
    }
    //   Save();
}


void Save()
{
  //   seteuid(UID_DAEMONSAVE);
  //   save_object(SAVEFILE);
  //   seteuid(getuid());
}


void Restore()
{
  //   seteuid(UID_DAEMONSAVE);
  //   restore_object(SAVEFILE);
  //   seteuid(getuid());
}


void set_mon_places(string file, string *places)
{
    if(!unique_mons_where) unique_mons_where = ([]);
    unique_mons_where[file] = places;
    //   Save();
}


void place_mon_at(string what, string where)
{
    if(where == "")
    {
        seteuid(UID_LOG);
        log_file("debug.log","/daemon/monster_d: Bad (or no file) to place monster for monster "+what+" in place_mon_at()!\n");  // added to make it log the what it was trying to place.  *Styx* 11/18/03, last change 4/5/03
        seteuid(getuid());
        return;
    }

    if(what == "")
    {
        seteuid(UID_LOG);
        log_file("debug.log","/daemon/monster_d: Bad (or no file) for the monster in place_mon_at()!\n");
        seteuid(getuid());
        return;
    }

    if(!pointerp(to_be_placed[where]))
    {
        // If we haven't scheduled something to be put in the room yet...
        // Start.
        to_be_placed[where] = ({ what });
    }
    else
    {
        // Otherwise add to it.
        to_be_placed[where] += ({ what });
    }
    //   Save();
}


string assure_file_exists_without_c(string filename)
{
    string temp;
    int len;
    temp = filename;
    len = strlen(temp);

    if(temp[len-2..len-1] != ".c")
    {
        temp += ".c";
        len += 2;
    }

    if(file_exists(temp))
    {
        temp = temp[0..len-3];
    }
    else
    {
        temp = "";
    }
    return temp;
}


string explode_dir(string dir)
{
    string *rooms, *wildcards, room, roomdir;
    object ob;
    int i;

    rooms = ({ });
    /***********
    if strsrch(dir,"?") {
    wildcards = explode(dir,"?");
    for (i=0; i < sizeof(wildcards); i++) {
    if (i+1 = sizeof(wildcards)) {
    rooms += wildcards[i] + get_dir(wildcards[i]+"?.c");
    } else {  rooms += wildcards[i] + get_dir(wildcards[i]+"?"+wildcards[i+1])
    }
    }
    if strsrch(dir,"*") {
    wildcards = explode(dir,"*");
    if (sizeof(wildcards) = 1) {
    rooms += wildcards[0] + get_dir(wildcards[0]+"*.c");
    } else {   }
    }
    *******************/
    if (strsrch(dir,"*") == -1)
    {
        rooms = get_dir(dir+"*.c");
    }
    else
    {
        rooms = get_dir(dir+".c");
    }
    //   write(identify(rooms));

    if ((i=strsrch(dir,"/",-1)) != -1)
    {
        roomdir=dir[0..i];
    }
    else
    {
        roomdir = "/";
    }

    if(!pointerp(rooms) || !sizeof(rooms))
    {
        seteuid(UID_LOG);
        log_file("debug.log","/daemon/monster_d: directory "+dir+" empty or invalid, please "
            "correct /daemon/save/monsters_unique.db.\n");
        return assure_file_exists_without_c("");
    }

    room = roomdir + rooms[random(sizeof(rooms))];
    //   write(identify(room));
    return assure_file_exists_without_c(room);
}


string do_placement(string * dest)
{
    string file, where;
    if(!pointerp(dest)) return "";
    if(pointerp(dest)) { dest -= ({""}); }
    if(sizeof(dest))
    {
        where = dest[random(sizeof(dest))];
        //    write(identify(where));
        if ( (strsrch(where,"*") != -1) || (strsrch(where,"?") != -1) || (where[strlen(where)-1] == '/') )
        {
            // God I hope this works right
            return explode_dir(where);
            // Not sure this will work, damnit.
            // going to get crowded here
        }
        else
        {
            return assure_file_exists_without_c(where);
	        //	place_mon_at(where,file[0..len-3]);
	        //               Save();
        }
    }
    else
    {
        // if (dest != ([])) {
        return "";
    }
}


void place_mons(mapping monsmap)
{
    int i,j,len;
    string place_what,*key,*to_where;
    object ob;

    if(!monsmap) { monsmap = ([]); }

    if(!to_be_placed) { to_be_placed = ([]); }

    if(!deployed_mons) { deployed_mons = ([]); }

    key = keys(monsmap);
    j = sizeof(key);

    for(i=0;i<j;i++)
    {
        to_where = monsmap[key[i]];
        place_what = key[i];
        if (place_what != "")
        {
	        place_mon_at(place_what, do_placement(to_where));
        }
        else
        {
	        seteuid(UID_LOG);
	        log_file("debug.log","/daemon/monster_d: Bad (or no) monster file when trying to place in place_mons()!\n");  // added mention of function *Styx* 11/18/03
	        seteuid(getuid());
        }
    } // for
}


void check_for_place(string room)
{
    object ob,the_room;
    int iter;
    string what;
    mixed catch_err;
    if(objectp(PO))
    {
        if(PO->query("alternative world")) return;
    }
    if(member_array(room,keys(to_be_placed)) != -1)
    {
        iter = sizeof(to_be_placed[room]);

        while (iter--)
        {
            catch_err = 0;
            what = to_be_placed[room][iter];

            if(!objectp(deployed_mons[what]))
            {
	            if(member_array(what,keys(unique_mons_where)) != -1)
                {
	                // if it's in that array, it's a master NPC
	                catch_err = catch(ob=find_object_or_load(what));
                    if(!objectp(ob))
                    {
                        log_file("debug.log","monster_d error in check_for_place, "
                            "couldn't load monster: "+what+", error is: "+identify(catch_err)+"\n");
                        continue;
                    }
	            }
                else
                {
	                // Otherwise clone it.
                    // removing the catch to save processor effort since clone shouldn't bug *Styx* 12/18/05
                    //	  catch_err = catch(ob=new(what));
	                ob = new(what);

                    if(!objectp(ob))
                    {
                        catch_err = catch(ob=new(what));
                        log_file("debug.log","monster_d error in check_for_place, "
                            "couldn't load monster: "+what+", error is: "+identify(catch_err)+"\n");
                        continue;
                    }
	            }

                if (!catch_err)
                {
                    if(!objectp(room))
                    {
                        the_room = find_object_or_load(room);
                    }

                    if(!objectp(the_room))
                    {
                        catch_err = catch(the_room=find_object_or_load(room));
                        log_file("debug.log","monster_d error in check_for_place, "
                            "couldn't load room: "+room+", error was: "+identify(catch_err)+"\n");
                        continue;
                    }

                    catch_err = catch(call_other(the_room,"???"));

                    if(catch_err)
                    {
                        seteuid(UID_LOG);
                        log_file("debug.log","monster_d error in check_for_place, call_other.  Error is: "+identify(catch_err)+"");
                        seteuid(getuid());
                        continue;
                    }
	                catch_err = catch(ob->move(the_room));

                    if (catch_err)
                    {
	                    seteuid(UID_LOG);
                        // more info. in error logging due to seeing only recursion errors *Styx* 9/05
	                    log_file("debug.log","monster_d error in check_for_place "
		                    "ob->move(room):  "+identify(catch_err)+" room was: "+room+", "
		                    "what is "+what+"\n");
	                    seteuid(getuid());
	                    continue;
	                }

	                ob->set_property("deployed_mons",1);
	                deployed_mons[what] = ob;

	                // Later... Set a flag in the monster and make a clean_up function
	                // that will tell the room that it has to notify the daemon that
	                // it cleaned up the monster.
                }
                else
                {
	                write(identify(catch_err));
	                seteuid(UID_LOG);
                    // more info. in error logging due to getting recursion errors logged *Styx* 9/05
	                log_file("debug.log","monster_d error in check_for_place() last else: "+identify(catch_err)+ " room was: "+room+", what is: "+what+"\n");
	                log_file("Misc_Errors","monster_d error in check_for_place() last else: "+identify(catch_err)+ " room was: "+room+", what is: "+what+" "+ctime(time())+"\n");
	                seteuid(getuid());
	                continue;
	            }
	            //      Save();

            }  // Otherwise this monster's deployed.
        } // While we've still got things to put in the room.
    } // if the room has something to be put into it.
}


mapping load_mons_db(string fromfile)
{
    string *lines;
    string workstr, str;
    mapping work;
    int i, max;
    // Mostly cribbed from /adm/obj/master.c
    work = ([ ]);
    if(!(max=sizeof(lines=explode(read_file(fromfile), "\n"))))
    {
        write("Error in reading monsters database ("+fromfile+").\n");
        return work ;
    }
    for(i=0;i<max;i++)
    {
        // ignore comments, null lines...
        if (!strlen(lines[i])) {
            continue;
        }
        if (!lines[i] || lines[i] == "") {
            continue;
        }
        if (regexp(lines[i], "^#")) {
            continue;
        }
        // If we start with +:, append to the last monster entry.
        // I need to test this. - garrett

        if(sscanf(lines[i], "+: %s", str) == 1)
        {
            if(sizeof(explode(str, " "))) work[workstr] += explode(str, " ");
            continue;
        }

        if(sscanf(lines[i], "(%s): %s", workstr, str) != 2)
        {
	        seteuid(UID_LOG);
	        log_file("debug.log","/daemon/monster_d: Error in reading monsters database ("+fromfile+") in line "+(i+1)+" in load_mons_db().\n");
	        // changed the write to log *Styx* 11/16/03
	        seteuid(getuid());
            continue;
        }
        if(!sizeof(work[workstr] = explode(str, " ")))
        {
            map_delete(work, workstr);
        }
        continue;
    }
    return work;
}

int clean_up() { return 0; } // I could swear this is right.
int cleanup() { return 0; } // return 0 says never call clean up again.


add_death_watcher(object dw)
{
    if((death_watchers == 0) || (sizeof(death_watchers) == 0))
    {
        if(objectp(dw)) { death_watchers = ({ dw }); }
        return;
    }

    if(objectp(dw)) { death_watchers += ({dw}); }

    return;
}


void tell_death_watch(object whom)
{
    object * obz;
    obz = filter_array(death_watchers,"is_objectp","/daemon/messaging_d.c");
    catch(obz->notice_death(whom));
}


mapping query_placement() { return to_be_placed ;}
mapping query_unique_mons() { return unique_mons_where; }
mixed * keys_unique_mons() { return keys(unique_mons_where); }
mapping query_cloned_mons() { return cloned_mons_where; }
mapping query_deployed_mons() { return deployed_mons; }
object * query_death_watchers() {return death_watchers;}
