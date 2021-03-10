#include <std.h>
#include <daemons.h>
#include <security.h>
#include <move.h>

inherit DAEMON;

#define SAVE_FILE   "/daemon/save/backup_inv"
#define WAIT        10800 // 3 hours        

mapping BACKUPS;
int HAS_CLEANED;
//added by Saide - should clean the backup mapping approximately once per day 
//of characters who no longer exist
varargs void clean_backup_mapping(object debugger);
void remove_from_backup(string name);
void create()
{
    seteuid(UID_ROOT);
    BACKUPS = ([]);
    restore_object(SAVE_FILE);
    if(time() > HAS_CLEANED) clean_backup_mapping();
}

void assure_save_dir_exists(string file)
{
    string *elems;
    string path, name_path, let_path;
    int i;

    if(strsrch(file, "/d/save/retainers") != -1)
    {
        mkdir(file);
        return;     
    }
    
    elems = explode(file, "/");
    if(sizeof(elems) == 3)
    {
        name_path = file;
        let_path = "/"+ implode(elems[0..1],"/");        
    }    
    else if(sizeof(elems) == 4)
    {
        name_path = file;
        let_path = "/"+implode(elems[0..2],"/");
    }
    if(strlen(let_path) > 1)
    {
        if(file_size(let_path) != -2) mkdir(let_path);
        if(file_size(name_path) != -2) mkdir(name_path);
        return;
    }
    
    path = "";
    for (i=0; i < sizeof(elems) - 1; i++) 
    {
        path += "/" + elems[i];
        if (file_size(path) == -1) 
        {
            if (objectp(this_player()) && wizardp(this_player())) 
            {
                write("Make dir " + path + "\n");
            }
            mkdir(path);
        }
    }
}

void remove_from_backup(string name)
{
    if(!stringp(name)) return;
    if(!mapp(BACKUPS)) return;
    if(member_array(name, keys(BACKUPS)) == -1) return;
    map_delete(BACKUPS, name);
    save_object(SAVE_FILE);
    return;
}

varargs void clean_backup_mapping(object debugger)
{
    int x, i, j;
    string *names, *oldfiles;
    
    if(!mapp(BACKUPS)) return;
    names = keys(BACKUPS);
    if(!sizeof(names)) return;
    for(i = 0;i < sizeof(names);i++)
    {
        if(!user_exists(names[i])) 
        {
            map_delete(BACKUPS, names[i]);
            oldfiles = get_dir("/inv/backup_inv/"+names[i][0..0]+"/"+names[i]);
            for(x=0;x<sizeof(oldfiles);x++) 
            {
                j = rm("/inv/"+names[i][0..0]+"/"+names[i]+"/"+oldfiles[x]);
            }
            if(objectp(debugger)) tell_object(debugger, "Removing name "+names[i]+ " from backup_inventory and deleting backup inventory.");
            rmdir("/inv/backup_inv/"+names[i][0..0]+"/"+names[i]);
            continue;
        }
        continue;
    }
    HAS_CLEANED = time() + 86400;
    save_object(SAVE_FILE);
}

void backup_inventory(object ob)
{
    object *inv;
    string fname,path,*oldfiles;
    int x,j,last_time,start_time;

    if(!ob->is_player()) { return; }

    path = "/inv/backup_inv/"+ob->query_name()[0..0]+"/"+ob->query_name();
    if(file_size("/inv/backup_inv/"+ob->query_name()) == -2)
    {
        oldfiles = get_dir("/inv/backup_inv/"+ob->query_name()+"/");
        seteuid(UID_ROOT);
        for (x=0;x<sizeof(oldfiles);x++) 
        {
            j = rm("/inv/backup_inv/"+ob->query_name()+"/"+oldfiles[x]);
        }
        rmdir("/inv/backup_inv/"+ob->query_name());
    }
    if(!mapp(BACKUPS)) 
    { 
        BACKUPS = ([]);
        save_object(SAVE_FILE);
    }

    if(!intp(BACKUPS[ob->query_name()]))
    {
        BACKUPS[ob->query_name()] = ( time() - 1 );
        save_object(SAVE_FILE);
    }

    last_time = (int)BACKUPS[ob->query_name()];
    
    start_time = ob->query_start_time();
    if( (time() - start_time) < 1200 ) { return; } // will not back up inventory unless somebody has been online for more than 20 minutes

    if( (!objectp(environment(ob))) || (base_name(environment(ob)) == "/d/shadowgate/freezer") || !interactive(ob) || (query_idle(ob) > 300) )
    {
        return;
    }

    if(last_time > time()) { return; }

    inv = all_inventory(ob);
    if(!sizeof(inv)) { return; }
    
    write("Backing Up Inventory");

    BACKUPS[ob->query_name()] = ( time() + WAIT );  
    save_object(SAVE_FILE);

    assure_save_dir_exists(path);
    oldfiles = get_dir(path+"/");
    seteuid(UID_ROOT);
    rm("/inv/"+ob->query_name()[0..0]+"/"+ob->query_name()+"/"+ob->query_name()+".log");

    for (x=0;x<sizeof(oldfiles);x++) 
    {
        j = rm(path+"/"+oldfiles[x]);
    }

    seteuid(getuid());
    j = 0;

    for (x = 0; x < sizeof(inv); x++) 
    {
        fname = path+"/ob"+x;
        j=inv[x]->save_me(fname);
    }
    return;
}

void save_inventory(object ob, string path)
{
    object *inv;
    string fname, myname;
    int x,j;
    string *oldfiles;

    inv = all_inventory(ob);
    
    if (!stringp(path)) 
    {
        myname = ob->query_name();
        if(stringp(myname)) path = "/inv/"+myname[0..0]+"/"+myname;
    }

    backup_inventory(ob);

    assure_save_dir_exists(path);
    oldfiles = get_dir(path+"/");
    seteuid(UID_ROOT);
    rm("/inv/"+ob->query_name()+"/"+ob->query_name()+".log");
    for (x=0;x<sizeof(oldfiles);x++) 
    {
        j = rm(path+"/"+oldfiles[x]);
    }
    seteuid(getuid());
    j = 0;
    for (x = 0; x < sizeof(inv); x++) 
    {
        fname = path+"/ob"+x;
        j=inv[x]->save_me(fname);
        continue;
    }
}

void load_inventory(object ob, string path)
{
// move all cloned objects to ob
    mapping comps;
    string fname,fn,s1,s2,*files, myname, *myids;
    int i,j,x,fsize,oldsize,z, flag, weight,internal;
    object tmp, old_tmp,failed;
    object *old,*deep;
    x = 0;
    ob->set_property("extra encumbrance",10000);
    ob->do_encumbrance();
    all_inventory(ob)->remove();
    if (!stringp(path))
    {
        myname = ob->query_name();        
        if(stringp(myname)) 
        { 
            if(file_size("/inv/"+myname) == -2) { path = "/inv/"+myname; flag = 1; }
            else path = "/inv/"+myname[0..0]+"/"+myname; 
        }
    }    
    seteuid(getuid());
    fsize = sizeof(files = get_dir(path+"/ob*"));
    write("Loading Inventory");
    for (x = 0; x < (fsize) ; x++) 
    {
        //    write("Loading Object #"+x);
        fname = path+"/"+files[x];
        //write("file name = "+files[x]);
        if (file_exists(fname)) 
        {
            fn = read_file(fname,1,1);
            s1 = "";
            if (!stringp(fn)) continue;
            sscanf(fn,"#%s.c",s1);
            if(!stringp(s1) || strlen(s1) < 2) 
            {
                s1 = "";
                sscanf(fn, "#%s\n",s1);
            }
            if(!stringp(s1)) continue;
            s1 = "/"+s1;
            if (catch(tmp = new(s1))) {
                tell_object(ob,"Error: File "+s1+" not found");
                log_file("BadInv",(string)ob->query_true_name()+":"+s1+"\n");
                continue;
            }
            sscanf(fname,"%s.o",fn);
            if(!objectp(tmp))
            {
                log_file("BadInv", (string)ob->query_true_name()+": bad item : " +s1+"\n");
                continue;
            }
            j = catch(i = tmp->restore_me(fn));
            if (j) 
            {
                tell_object(ob,"There is a problem with one of your items. Ignoring.");
                log_file("BadInv", (string)ob->query_true_name()+": fn : " +fn+"\n");
                //          rm(fname);
                continue;
            }
            if (!j) 
            {
                //    tell_object(ob,"loading "+fname);
                weight = tmp->query_weight();
                tmp->set_weight(0);
                if(UPDATED_ITEM_D->check_update(tmp))
                {
                    tell_object(ob, "%^RESET%^%^B_CYAN%^%^YELLOW%^Your %^RESET%^"+tmp->query_short()+"%^RESET%^%^B_CYAN%^%^YELLOW%^ "+
                        "has had a file update. "+
                        "A new version is being cloned, your old version is removed, and if you had "+
                        "it identified it should still be identified. If there are any modifications that "+
                        "you personally made to the item then you will need to talk to a wiz about having them "+
                        "restored. It is most likely that your item was changed because it no longer fit with "+
                        "the recently implemented item standard - likely it was too powerful or too weak. Thank you!\n%^RESET%^");
                    deep = all_inventory(tmp);
                    old_tmp = tmp;
                    tmp = new(base_name(old_tmp));
                    weight = tmp->query_weight();
                    tmp->set_weight(0);
                    tmp->set("updated time", time());
                    internal = tmp->query_max_internal_encumbrance();
                    tmp->set_max_internal_encumbrance(10000);
                    
                    comps = old_tmp->query_comp_map();
                    if(mapp(comps) && sizeof(keys(comps)))
                    {
                        tmp->set_comp_map(comps);
                    }
                    
                    for(i=0;sizeof(deep),i<sizeof(deep);i++)
                    {
                        if(!objectp(deep[i])) { continue; }
                        if(deep[i]->move(tmp) != MOVE_OK)
                        {
                            if(deep[i]->move(ob) != MOVE_OK)
                            {
                                if(objectp(environment(ob)))
                                {
                                    deep[i]->move(environment(ob));
                                }
                                else
                                {
                                    failed = find_object_or_load("/d/shadowgate/arch/2nd_floor");
                                    failed->set_had_players(25);
                                    deep[i]->move(failed);
                                    tell_object(ob,"Couldn't move item "+identify(deep[i])+" to your inventory, moving to admin bell room, please contact a wiz.");
                                    log_file("BadInv","Inventory Error for "+identify(ob)+" "+s1+", couldn't move "+identify(deep[i])+" to inventory, moved to "+identify(failed)+" instead.\n");
                                }
                            }
                        }                        
                    }
                    
                    tmp->set_max_internal_encumbrance(internal);
                    
                    if(pointerp(myids = old_tmp->query_identified())) tmp->set_identified(myids);
                    if(objectp(old_tmp)) old_tmp->remove();                    
                }
                if(!objectp(tmp))
                {
                    if(find_player("saide")) tell_object(find_player("saide"),"Invalid inventory object in yuck_d");
                    if(objectp(ob))
                    {
                        log_file("BadInv","Inventory Error: "+s1+" couldn't restore object for player "+identify(ob)+".\n");
                    }
                    else
                    {
                        log_file("BadInv","Inventory Error: "+s1+" couldn't restore object.\n");
                    }
                    continue;
                }
                if(!objectp(ob))
                {
                    if(find_player("saide")) tell_object(find_player("saide"), "invalid player object in yuck_d.c");
                    log_file("BadInv","Invalid player object in yuck_d.\n");
                    return;
                }
                if (objectp(tmp) && tmp->move(ob) != MOVE_OK) 
                {
                    if(objectp(environment(ob)) && objectp(tmp)) tmp->move(environment(ob));
                    else
                    {
                        log_file("BadInv", "Either invalid environment or invalid inventory item after "+
                        "attempting to move but not being able to. For "+fname+" and player "+identify(ob)+".  "
                        "Item attempted to restore was "+s1+".\n");
                        if(strsrch(path,"backup_inv") == -1 && objectp(environment(ob)))
                        {
                            rm(fname);
                        }
                        continue;
                    }
                    if(objectp(tmp)) { deep = all_inventory(tmp); }
                    else 
                    {
                        log_file("BadInv", "Either invalid environment or invalid inventory item after "+
                        "attempting to move but not being able to. For "+fname+" and player "+identify(ob)+".  "
                        "Item attempted to restore was "+s1+".\n");
                        if(strsrch(path,"backup_inv") == -1)
                        {
                            rm(fname);
                        }
                        continue;                    
                    }
                    tell_object(ob,"%^B_RED%^%^BOLD%^%^CYAN%^You dropped something %^RESET%^");
                    if(pointerp(deep) && sizeof(deep))
                    {
                        log_file("BadInv", (string)ob->query_true_name()+": dropped "+identify(tmp)+" on login, it contained: \n");
                        for(i=0;i<sizeof(deep);i++)
                        {
                            if(!objectp(deep[i])) { continue; }
                            log_file("BadInv", "        "+identify(deep[i])+"\n");                           
                        }
                    }
                    else
                    {
                        log_file("BadInv",(string)ob->query_true_name()+": dropped "+identify(tmp)+" "+s1+" on login\n");
                    }
                }
                if(objectp(tmp)) tmp->set_weight(weight);
                else log_file("BadInv",(string)ob->query_true_name()+" : lost an item "+s1+" on login?\n");
                //tmp->restore_me(fn+".o");
                if(strsrch(path,"backup_inv") == -1)
                {
                    rm(fname);
                }
            }
        }
    }
    if(flag) rmdir(path);
    ob->set_property("extra encumbrance",-10000);
    ob->do_encumbrance();
}

//  Checks Circumstances that might cause multiple reloads of
//  player inventories.  VERY IMPORTANT thing to avoid.
//  -- Thorn 960117

int check_circumstances(){

    return 1;
}

mixed restore_files(string fname)
{
    string fn;
    string j,s1;
    object tmp;
    int i;

    if (file_exists(fname)) 
    {
        fn = read_file(fname,1,1);
        if(!stringp(fn)) { return "line 1 of "+fname+" invalid: "+fn+" :end"; }
        sscanf(fn,"#%s.c",s1);
        s1 = "/"+s1;
        sscanf(fname,"%s.o",fn);
        j = catch (tmp = new(s1));
        if(j) 
        { 
            log_file("debug.log","**ERROR in /daemon/yuck_d restore_files: "+j+"\n");
            log_file("BadInv","**ERROR creating new file: "+j+" for file"+s1+"\n");
        }
        if(stringp(j)) { return j; }
        j = catch(i = tmp->restore_me(fn));
        if(j) 
        { 
            log_file("debug.log","**ERROR in /daemon/yuck_d restore_files: "+j+"\n");
            log_file("BadInv","**ERROR restoring properties to file: "+j+" for file "+s1+"\n");
        }
        if (!j) { return tmp; }
        return j;
    }
}

