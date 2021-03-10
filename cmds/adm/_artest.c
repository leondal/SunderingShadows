#include <std.h>
#include <daemons.h>
#include <objects.h>
#include <security.h>

#define HYBRID ({"psywarrior","druid","bard","warlock"})
inherit OB_USER;
void test();

void create() {
   seteuid(getuid());
}


void test7()
{
    test();
    return;
}

void test6()
{
    test7();
    return;
}

void test5()
{
    test6();
    return;
}

void test4()
{
    test5();
    return;
}

void test3()
{
    test4();
    return;
}

void test2()
{
    test3();
    return;
}

void test1()
{
    test2();
    return;
}

void test()
{
    test1();
    return;
}

void end()
{
    TO->remove();
    return;
}

void cmd_artest(string str)
{
    mixed catch_error;
    int x, count;
    object Mon;
    x = 200;
    while(x > 0)
    {
        x--;
        if(catch_error = catch(Mon = new("/d/shadow/mon/guardnew")))
        {
            tell_object(TP, "Error: "+identify(catch_error));
            break;
        }
        else { if(objectp(Mon)) { Mon->move("/d/shadowgate/void"); if(objectp(Mon)) { Mon->remove(); } count++; } }
        continue;
    }
    tell_object(TP, "\n\nMonsters made without error = "+count);
    return 1;
}

/*void cmd_artest(string dir) 
{	
    //int x;
	/*object MyOb;
    string *rooms, room;
    int x, y, z;
    if(!stringp(dir)) 
    {
        tell_object(TP, "Please specify a directory");
        return 1;
    }
    rooms = get_dir(dir+"*.c");
    for(x = 0;x < sizeof(rooms);x++)
    {
        room = rooms[x];
        if(catch(MyOb = find_object_or_load(dir+room))) 
        {   
            tell_object(TP, "Room "+identify(MyOb) +" FAILED to load");
        }
        else if(!sizeof(MyOb->query_exits()) && !strlen(MyOb->query_long()))
        {
            tell_object(TP, "Room "+identify(MyOb) + " has no exits!");
            z++;
        }
        y++;
        MyOb->remove();
        continue;
    }
    if(!y) tell_object(TP, "Could not find directory "+dir+ " to check.");
    else tell_object(TP, "Check Complete. "+x + " rooms checked. "+z+" Failed with no exits and no long description");
    return 1;*/
    /*int x = 100, count;
    object MyMon;
    
    while(x--)
    {
        count++;
        if(catch(MyMon = new("/d/dagger/tonovi/mon/guard1_city")))
        {
            tell_object(TP, "Monster error on the " +count+ " attempt.");
            return 1;
        }
        if(objectp(MyMon)) MyMon->remove();
    }
    tell_object(TP, count+" monsters cloned and removed with no errors.");
    return 1;*/
    
    /*string *files, *files_to_move, real_dir, targ_dir, targ_file, dest_file;
    int x;
    if(sscanf(dir, "%s to %s", real_dir, targ_dir) != 2) 
    {
        tell_object(TP, "You must specify a directory to back up and a "+
        "target directory to move the files to.");
        return 1;
    }
    
    files = get_dir(real_dir);
    files_to_move = ({});
    for(x = 0;x < sizeof(files);x++)
    {
        if(strsrch(files[x], ".c") != -1 && strsrch(files[x], ".circe") == -1) continue;
        if(strsrch(files[x], ".h") != -1 && strsrch(files[x], ".hash") == -1) continue;
        if(strsrch(files[x], ".o") != -1) continue;
        files_to_move += ({files[x]});
    }
    //tell_object(TP, "Would be moving "+identify(files_to_move) + " to "+targ_dir);
    for(x = 0;x < sizeof(files_to_move);x++)
    {
        if(!file_exists(real_dir + files_to_move[x])) continue;
        //tell_object(TP, "would be moving "+real_dir + files_to_move[x]);
        //targ_file = real_dir + files_to_move[x] + " " +targ_dir;
        //tell_object(TP, targ_file);
        targ_file = real_dir + files_to_move[x];
        dest_file = targ_dir + files_to_move[x];
        tell_object(TP, "Targ = "+targ_file);
        tell_object(TP, "Dest = "+dest_file);
        seteuid(UID_RESTORE);
        rename(targ_file, dest_file);
        seteuid(geteuid());
        //"/cmds/system/_mv"->cmd_mv(targ_file);
        continue;
    }
    
    tell_object(TP, "Backup complete. Moved "+sizeof(files_to_move)+" files.");
    return 1;*/
    //call_out("end", 100);
    /*for(x = 0;x < 200;x++)
    {
        tell_object(TP, "calling test number "+(x+1)+".");
        test();
        continue;
    }
    tell_object(TP, "x = "+x+".");
    return 1; 
}*/

