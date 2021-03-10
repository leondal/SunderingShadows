#include <std.h>
#include <dirs.h>
#include <bank.h>
#include <security.h>

#define CAP_PER_TIER 10

int cell_tier=0;
string who;
string bank;
object player;

set_cell_tier(int x)
{
    cell_tier = x;
}

string query_bank()
{
    return bank;
}

void setup_cell(object pobj, string bankname)
{
    if(objectp(pobj))
    {
        TO->remove();
        return;
    }
    player = pobj;
    who = pobj->query_name();
    bank = bankname;
}

int load_inventory()
{
    string dir;
    string fname;
    string * files;
    string shebang;
    string objfile;
    object ob;
    int i;
    int rest_status;

    dir = DIR_ACCOUNTS+"/cells/"+bank+"/"+who;
    files = get_dir(dir+"/ob*");

    for (i; i < sizeof(files); i++)
    {
        fname = dir+"/"+files[i];
        if(file_exists(fname))
        {
            shebang = read_file(fname,1,1);
            if (!stringp(shebang))
            {
                log_file("bank_cells","Empty object for "+who+" in "+bank);
                continue;
            }

            sscanf(fname, "#%s\n",objfile);
            if(!stringp(objfile))
            {
                log_file("bank_cells","Object not found for "+who+" in "+bank);
                continue;
            }

            objfile = "/"+objfile;
            if(catch(ob = new(objfile)))
            {
                log_file("bank_cells","Unable to load object for "+who+" in "+bank);
                continue;
            }

            if(!objectp(ob))
            {
                log_file("bank_cells","Unable to preserve object for "+who+" in "+bank);
                continue;
            }

            sscanf(fname,"%s.o",shebang);

            if(catch(rest_status = ob->restore_me(shebang)))
            {
                log_file("bank_cells","Unable to restore object for "+who+" in "+bank);
                continue;
            }

            ob->move(TO);
        }
    }
}

void save_inventory()
{
    string dir;
    object *inv;
    string *oldfiles;
    string fname;

    int i;

    mkdir(DIR_ACCOUNTS+"/cells/"+"/"+bank);
    mkdir(DIR_ACCOUNTS+"/cells/"+bank+"/"+who);

    dir = DIR_ACCOUNTS+"/cells/"+bank+"/"+who;

    inv = all_inventory(TO);
    oldfiles = get_dir(dir+"/");
    seteuid(UID_ROOT);

    for(i=0; i<sizeof(oldfiles); i++)
        rm(dir+"/"+oldfiles[i]);

    setuid(getuid());

    for (i=0; i<sizeof(inv); i++)
    {
        fname = dir+"/ob"+i;
        inv[i]->save_me(fname);
    }
}

void show_list()
{
    object *inv;
    string obuff;
    string myShort, myWeight;
    int totalWeight;
    int i;

    if(!objectp(player))
    {
        TO->remove();
        return;
    }

    inv = all_inventory(TO);

    obuff="";
    totalWeight=0;
    for (i=0; i<sizeof(inv); i++)
    {
        if(!objectp(inv[i]))
            continue;

        myShort = inv[i]->query_short();
        myWeight = inv[i]->query_weight();
        totalWeight+=myWeight;
        obuff+=myShort+" "+myWeight+"\n";
    }

    tell_object(player,obuff);
    tell_object(player,"Total Weight: "+totalWeight);
}

int current_capacity()
{
    object *inv;
    int i;
    int totalWeight;
    int myWeight;

    inv = all_inventory(TO);
    totalWeight=0;

    for(i=0;i<sizeof(inv);i++)
    {
        if(!objectp(inv[i]))
            continue;

        myWeight = inv[i]->query_weight();
        totalWeight+=myWeight;
    }

    return totalWeight;
}

void deposit_item(string obname)
{
    object ob;

    if(!objectp(player))
    {
        TO->remove();
        return;
    }

    if(!objectp(ob = present(obname,player)))
    {
        tell_object(player,"You don't have that!");
        return;
    }

    if(!objectp(ob))
    {
        tell_object(player,"That doesn't exist!");
        return;
    }

    if(ENV(ob)!=player)
    {
        tell_object(player,"You don't have that!");
        return;
    }

    if(!ob->query_weight())
    {
        tell_object(player,"Can't be deposited as it has no weight.");
        return;
    }

    if(sizeof(all_inventory(ob)))
    {
        tell_object(player,"Only empty containers can be deposited.");
        return;
    }

    if(cell_tier*CAP_PER_TIER+ob->query_weight()>current_capacity())
    {
        tell_object(player,"Cell capacity reached.");
        return;
    }

    ob->move(TO);

    tell_object(player,"You deposit "+ob->query_short()+" into your cell.");
    save_inventory();
}

void withdraw_item(string obname)
{
    object ob;

    if(!objectp(player))
    {
        TO->remove();
        return;
    }

    if(!objectp(ob = present(obname,TO)))
    {
        tell_object(player,"Item can't be found.");
        return;
    }

    ob->move(player);

    tell_object(player,"You retrieve "+ob->query_short()+" from your cell.");
    save_inventory();
}
