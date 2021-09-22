/*
** /cmds/system/_update.c
**
** Reload a designated file or the room
** we are in.
**
** -- Tlaloc -- 9.22.21
*/

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_newupdate(string str)
{
    if(str)
        update_file(str);
    else
        update_here();
    
    return 1;
}

int update_file(string str)
{
    object file;
    string path, *files;
    mixed error = 0;

    path = resolv_path(this_player()->get_path(), str);
    
    //Reload a directory
    if(str == "*" || file_size(path) == -2)
    {
        path = str == "*" ? path = this_player()->get_path() : path;
        files = get_dir(path + "/*.c");
        
        foreach(string meh in files)
        {
            seteuid(geteuid(this_player()));
            error = catch(file = find_object_or_load(path + "/" + meh));
            
            if(error)
            {
                write("Failed to update : " + path + "/" + meh);
            }
            else
            {
                destruct(file);
                call_other(find_object(path + "/" + meh), "???");
                //write(path + "/" + meh + " Updated Successfully!");
                printf("%20s Updated Successfully!\n", path + "/" + meh);
            }
        }
        if(file != master())
            seteuid(UID_SYSTEM);
        
        return 1;
    }
    
    if(!file_exists(path + ".c"))
    {
        write(str + " doesn't seem to exist.");
        return 1;
    }
    
    //Reload a file
    seteuid(getuid(this_player()));  
    error = catch(file = find_object_or_load(path));
    
    if(error)
    {
        write("Failed to update : " + path);
    }
    else
    {
        seteuid(getuid(previous_object()));
        destruct(file);
        call_other(find_object(path), "???");
        if(file != master())
            seteuid(UID_SYSTEM);
        write(path + " Updated Successfully!");
    }
    
    write("Update done.");
    return 1;
}
    
    
    
    
    