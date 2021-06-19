#include <std.h>
#include <security.h>
#include "/d/dagger/exchange/horse/horse.h"
inherit OBJECT;

#define SAVE_FILE "/d/save/horse_race_stuff"

mapping horse_stats;

nosave mapping example_variable;

nosave string race_horses;
object horse_master;

void SAVE();
void RELOAD();
void clear_all_training();

void create()

{
    horse_stats = ([]);
    restore_object(SAVE_FILE);
}




void clear_all_training()
{

    string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int a,x,b,c,d,e;
    int i,w,q;
    string name,owner;
    temp = keys(horse_stats);
        tell_room(ETP,"loading horses\n");
    RELOAD();
    i = 0;
        q = 0;
        tell_room(ETP,"preparing to reset season\n");
        for (i=0;i<sizeof(temp);i++)
        {
            a = (random(10)+10);
            tell_room(ETP,"A is "+a+" and.. \n");
            b = (random(10)+10);
            c = (random(10)+10);
            d = (random(10)+10);
            e = (a+b+c+d);

            horse_stats[/**/temp[i]/**/]["status"] = 0;
            horse_stats[/**/temp[i]/**/]["speed"] = a;
            horse_stats[/**/temp[i]/**/]["health"] = b;
            horse_stats[/**/temp[i]/**/]["accel"] = c;
            horse_stats[/**/temp[i]/**/]["jockey"] = d;
            horse_stats[/**/temp[i]/**/]["total_skills"] = e;
            horse_stats[/**/temp[i]/**/]["win"] = 0;
            horse_stats[/**/temp[i]/**/]["loss"] = 0;
			horse_stats[/**/temp[i]/**/]["winnings"] = 0;
            horse_stats[/**/temp[i]/**/]["invested"] = 0;
            horse_stats[/**/temp[i]/**/]["claim_winnings"] = 0;

            }
                tell_room(ETP,"all horses reset\n");
            SAVE();
                return 1;

}

void SAVE()
{
    save_object(SAVE_FILE);

        horse_master =find_object_or_load("/d/dagger/exchange/horse/storage/horse_master.c");
        horse_master->create();

    return;
}

void RELOAD()
{
    horse_stats = ([]);
    restore_object(SAVE_FILE);
}

void show_all_horses()
{
    string *temp=({});
        int i;
        string name,owner, check_if_dead;
        int win, loss, winnings, uid;
    temp = keys(horse_stats);
write("You are looking at all of the horses on the books...");
write ("Number   Horse Name             Owner's Name              WIN /
LOSS ");
write
("-----------------------------------------------------------------");
    i = 0;
        for (i=0;i<sizeof(temp);i++)
        {
    name = horse_stats[/**/temp[i]/**/]["name"];
    name = arrange_string(name, 14);
    uid = horse_stats[/**/temp[i]/**/]["UID"];
        owner = horse_stats[/**/temp[i]/**/]["owner"];
    owner = arrange_string(owner, 20);
        win = horse_stats[/**/temp[i]/**/]["win"];
        loss = horse_stats[/**/temp[i]/**/]["loss"];
        winnings = horse_stats[/**/temp[i]/**/]["winnings"];
    check_if_dead = horse_stats[/**/temp[i]/**/]["name"];
        if(check_if_dead != "dead"){
        write(" "+uid+"\t "+name+"\t\t"+owner+"\t   "+win+"/"+loss+"");
        }
        }
}
