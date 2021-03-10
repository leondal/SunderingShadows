//      /adm/obj/master.c
//      from the Nightmare Mudlib
//      the mudlib master object
//      created by Descartes of Borg 03 august 1993
//      based upon master objects going back to mudlib.n

//              Nightmare Mudlib Version 3.0 Release 0.9.18
//              created by the founding arches of Nightmare MudOS
//              Darkone, Descartes, Flamme, Forlock, Shadowwolf
//              See detailed credits in /adm/Nightmare

// This is the master object, the second object loaded after the
// simul_efun object.  Everything written with 'write()' at startup
// will be printed to stdout.  At startup, the following functions
// will be called in the following order:
// 1) create()
// 2) flag() will be called once for every argument to the command flag -f
// 3) epilog()
// Finally, the game will enter multiuser mode and users can login.
// At this point preload() gets called once for each object to be
// preloaded.
//    *** Warnings ***
// Do not user any instructions in create() which will need to make
// calls externally to the master object.  For example, do not
// try seteuid(UID_ROOT) since the seteuid() efun has the driver call
// valid_seteuid() in the master object.  A master object will load fine
// and start the mud if it has such a call, but you will crash the
// mud if you try to reload it since it will not be able to find
// the master object (i.e no master exists until create() is done).

#include <conf.h>
#include <objects.h>
#include <rooms.h>
#include <security.h>
#include <dirs.h>
#include <databases.h>
#include <daemons.h>
#include <law.h>

#define READ 0
#define WRITE 1

nosave mapping access, groups, privs;

string creator_file(string str);
void preload(string str);
void load_access();
void load_groups();
void load_privs();
nomask int check_access(string file, object ob, int ind);
string *query_privs(string file);

void flag(string str) {
    string file, arg;
    int i, x;

    if(previous_object()) return;
    if(sscanf(str, "for %d", x) == 1) {
        for(i=0; i<x; i++) {}
        return;
    }
    if(sscanf(str, "call %s %s", file, arg)) {
        write("Got "+(string)call_other(file, arg)+" back.\n");
        return;
    }
    write("Master: unknown flag.\n");
}

string *epilog(int x) {
      set_eval_limit(90000000);
    call_out("socket_preload", 5);
    return read_database(PRELOAD_DB);
}

void load_groups() {
    string *lines;
    string grp, str;
    int i, max;

    groups = ([]);
    if(!(max=sizeof(lines=explode(read_file(GROUPS_DB), "\n")))) {
        write("Error in reading groups database.\n");
        shutdown();
        return;
    }
    for(i=0; i<max; i++) {
        if(!lines[i] || lines[i] == "" || lines[i][0] == '#') continue;
        if(sscanf(lines[i], "(%s): %s", grp, str) != 2) {
            write("Error in reading groups database in line "+(i+1)+".\n");
            shutdown();
            return;
        }
        if(!sizeof(groups[grp] = explode(str, " ")))
          map_delete(groups, grp);
    }
}

void load_access() {
    string *lines, *borg;
    string str, dir, tmp;
    int i, j, maxi, maxj;

    access = ([]);
    if(!(maxi=sizeof(lines=explode(read_file(ACCESS_DB), "\n")))) {
        write("Error in reading access database.\n");
        shutdown();
        return;
    }
    for(i=0; i<maxi; i++) {
        if(!lines[i] || lines[i] == "" || lines[i][0] == '#') continue;
        if(sscanf(lines[i], "(%s): %s", dir,tmp) !=2) {
            write("Error in reading access database at line "+(i+1)+".\n");
            shutdown();
            return;
        }
        if(!(maxj=sizeof(borg=explode(tmp, " ")))) continue;
        access[dir] = ([]);
        for(j=0; j<maxj; j++) {
            if(sscanf(borg[j], "(%s)[%s]", tmp, str) != 2) {
                write("Error in reading access database at line "+(i+1)+".\n");
                shutdown();
                return;
            }
            access[dir][tmp] = ({ 0, 0 });
            switch(str) {
                case "r": access[dir][tmp][READ] = 1; break;
                case "w": access[dir][tmp][WRITE] = 1; break;
                case "wr": case "rw": access[dir][tmp] = ({ 1, 1 }); break;
                default: access[dir][tmp] = ({ 0, 0 });
            }
        }
    }
}

void load_privs() {
    string *lines;
    string obj, euid;
    int i, max;

    privs = ([]);
    if(!(max = sizeof(lines=explode(read_file(PRIVS_DB), "\n")))) {
        write("Error in reading privs database.\n");
        shutdown();
        return;
    }
    for(i=0; i<max; i++) {
        if(!lines[i] || lines[i] == "" || lines[i][0] == '#') continue;
        if(sscanf(lines[i], "(%s): %s", obj, euid) != 2) {
            write("Error in reading privs database at line "+(i+1)+".\n");
            shutdown();
            return;
        }
        if(!sizeof(privs[obj] = explode(euid, " ")))
          map_delete(privs, obj);
    }
}

string *query_privs(string file){
	return privs[file];
}

void preload(string str) {
    string err;
    int t;

    if(!file_exists(str+".c")) return;
    t = time();
    write("Preloading: "+str+"...");
    if(err=catch(call_other(str, "???")))
      write("\nGot error "+err+" when loading "+str+".\n");
    else {
        t = time() - t;
        write("("+(t/60)+"."+(t%60)+")\n");
    }
}

void socket_preload() {
    string *items;
    int i, max;

    max = sizeof(items=explode(read_file(PRELOAD_SOCKET_DB), "\n"));
    for(i=0; i<max; i++) {
        if(!items[i] || items[i] == "" || items[i][0] == '#') continue;
        catch(call_other(items[i], "???"));
    }
}

int valid_write(string file, object ob, string fun) {
    return check_access(file, ob, WRITE);
}

int valid_read(string file, object ob, string fun) {
    return check_access(file, ob, READ);
}

int valid_link(string original, string reference) {
    return valid_read(original, this_player(), "") && valid_write(reference, this_player(),"");
}

nomask int check_access(string file, object ob, int ind)
{
    string* path, * grps;
    string euid, tmp, fn;
    int i, j;

    if (strsrch(file, "//") != -1) {
        return 0;
    }
    if (!objectp(ob)) {
        return 0;
    }
    if ((euid = geteuid(ob)) == UID_ROOT) {
        return 1;
    }
    if (sscanf(file, user_path(euid) + "%s", tmp) == 1) {
        return 1;
    }
    if (!euid) {
        return 1;
    }
    if (sscanf(euid, "%sobj", tmp) == 1 && sscanf(file, user_path(tmp) + "%s", tmp)
        == 1) {
        return 1;
    }
    if (!access) {
        load_access();
    }
    if (!groups) {
        load_groups();
    }
    if (!privs) {
        load_privs();
    }
    fn = base_name(ob);
    if (sscanf(file, REALMS_DIRS + "/%s", tmp) ||
        sscanf(file, DOMAINS_DIRS + "/%s", tmp)) {
        if (groups["ambassador"] && member_array(euid, groups["ambassador"])
            != -1) {
            return 0;
        }
    }
    if (!(path = explode(file, "/"))) {
        path = ({});
    }
    i = sizeof(path);
    while ((i--) != -1) {
        if (i == -1) {
            file = "/";
        }else {
            file = "/" + implode(path[0..(i)], "/");
        }
        if (access[file]) {
            if (access[file]["all"] && access[file]["all"][ind] == 1) {
                return 1;
            }else if (access[file][euid]) {
                return access[file][euid][ind];
            }else {
                j = sizeof(grps = keys(access[file]));
                while (j--) {
                    if (groups[grps[j]] && member_array(euid, groups[grps[j]]) != -1
                        && access[file][grps[j]][ind] == 1) {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

mixed connect() {
    mixed ob;
    string err;
    if(catch(ob = clone_object(OB_LOGIN))) {
        write("It looks like someone is working on the user object.\n");
        write(err);
        destruct(this_object());
    }
    return ob;
}

mixed compile_object(string file)
{
    return (mixed)VIRTUAL_D->compile_object(file);
}

protected void crash(string err) {
    log_file("crashes", mud_name()+" crashed "+ctime(time())+" with error "+err+".\n");
    shout("
%^BOLD%^%^BLUE%^Server is shutting down with reason: "+err);
    shout("%^BOLD%^%^%^BLUE%^Be back shortly!");
}

int valid_shutdown(string euid) {
    log_file("shutdowns", mud_name()+" was shut down by "+
      (previous_object() ? (euid=geteuid(previous_object())) : euid)+" "+
      ctime(time())+"\n");
    if(euid != UID_ROOT && euid != UID_SHUTDOWN) return 0;
    return 1;
}

int valid_seteuid(object ob, string id) {
    string fn, uid;

    if((uid = getuid(ob)) == id) return 1;
    if(uid == UID_ROOT) return 1;
    if(file_name(ob) == OB_SIMUL_EFUN) return 1;
    if(uid == UID_SYSTEM && id != UID_ROOT && id != UID_BACKBONE)
      return 1;
     if(id == UID_RESTORE) return 1; // huge security hole
    if(!privs) load_privs();
    return (privs[fn=base_name(ob)] && (member_array(id, privs[fn]) != -1));
}

int valid_shadow(object ob) { return 0; }

int valid_snoop(object snooper, object snoopee) {
    if(!snoopee && snooper) return 1;
    if(archp(snooper) && !archp(snoopee)) return 1;
    if(archp(snooper) && member_group(getuid(snoopee), "assist")) return 1;
    if(snoopee->query_snoop()) {
        return 1;
    }
    return 0;
}

int valid_exec(string nom) {
    if(nom[0] != '/') nom = "/"+nom;
    if(nom == OB_LOGIN+".c") return 1;
    return 0;
}

int valid_hide(object who) {
    if(!objectp(who)) return 0;
    return member_group(geteuid(who), "superuser");
}

int valid_override(string file, string nom)
{
    if (file == "/adm/simul_efun/overrides" || file == OB_SIMUL_EFUN) {
        return 1;
    }
    if (function_exists(nom, find_object(OB_SIMUL_EFUN))) {
        return 0;
    }
    return 1;
}

int valid_socket() { return 1; }

int load_player_from_file(string nom, object ob) {
    int x;

    //if(geteuid(previous_object()) != UID_ROOT) return 0;
    export_uid(ob);
    x = (int)ob->restore_player(nom);
    seteuid(nom);
    export_uid(ob);
    seteuid(UID_ROOT);
    return x;
}

void save_player_to_file(object ob) {
    string nom;
    int x;

    //if(base_name(previous_object()) != OB_USER) return;
    if(!(nom = (string)ob->query_name())) return;
    seteuid(UID_ROOT);
    export_uid(ob);
    ob->actually_save_player(nom);
    seteuid(nom);
    export_uid(ob);
    seteuid(UID_ROOT);
}

string get_wiz_name(string file) {
    string nom, dir, tmp;

    if(file[0] != '/') file = "/"+file;
    if(sscanf(file, REALMS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    if(sscanf(file, DOMAINS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    sscanf(file, "/%s/%s", nom, tmp);
    return nom;
}

void log_error(string file, string msg)
{
    string nom;

    if (!(nom = get_wiz_name(file))) {
        nom = "log";
    }
    catch(write_file(DIR_ERROR_LOGS + "/" + nom, ctime(time()) + ":\n" + msg));
    catch(write_file("/log/debug.log", ctime(time()) + ": " + msg));
}

void destruct_env_of(object ob)
{
    if (!interactive(ob)) {
        return;
    }
    tell_object(ob, "The world about you swirls into nothingness, as " +
                "you are quickly teleported somewhere else.\n");
    ob->move(ROOM_VOID);
}

string make_path_absolute(string file)
{
    return resolv_path((string)this_player()->get_path(), file);
}

int player_exists(string str) {
    return file_exists(DIR_USERS+"/"+str[0..0]+"/"+str+".o");
}

string get_root_uid() { return UID_ROOT; }

string get_bb_uid() { return UID_BACKBONE; }

string creator_file(string str) {
    return (string)call_other(OB_SIMUL_EFUN, "creator_file", str);
}

string domain_file(string str) {
    string nom, tmp;

    if(str[0] != '/') str = "/"+str;
    if(sscanf(str, DOMAINS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    return 0;
}

string author_file(string str) {
    string nom, tmp;

    if(str[0] != '/') str = "/"+str;
    if(sscanf(str, REALMS_DIRS+"/%s/%s", nom, tmp) == 2) return nom;
    return 0;
}

protected int slow_shutdown() {
    log_file("game_log", "Armageddon loaded by master: "+ctime(time())+".\n");
    new(OB_SHUT)->move(ROOM_START);
    SHUT_D->do_armageddon();
    return 1;
}

int save_ed_setup(object who, int code) {
    string file;

    if(!intp(code)) return 0;
    rm(file = user_path(getuid(who))+".edrc");
    return write_file(file, code+"");
}

int retrieve_ed_setup(object who) {
    string file;
    int x;

    if(!file_exists(file = user_path(getuid(who))+".edrc")) return 0;
    return atoi(read_file(file));
}

string get_ed_buffer_save_file_name(string file) {
    string str;

    return (file_size(str=user_path(geteuid(this_player()))) == -2 ?
      str+"dead.edit" : DIR_TMP+"/"+geteuid(this_player())+".edit");
}

int is_locked() { return MUD_IS_LOCKED; }

int query_member_group(string who, string grp) {
    if(!groups) load_groups();
    if(groups[grp]) return (member_array(who, groups[grp]) != -1);
    else return 0;
}

mapping query_groups() {
    if(!groups) load_groups();
    return copy(groups);
}

void error_handler(mapping map,int num)
{
    object ob;
    ob = find_object_or_load("/adm/daemon/error_handler_d.c");
    if(objectp(ob)) ob->process_error(map,num);
    return;
}
/*mixed get_include_path(string file)
{
    return ({"/adm/include/"});
}*/
