#include <std.h>
#include "../tormdefs.h"
#include <daemons.h>
inherit "/std/jail_main.c";
//#define LIST "torm_official_position_list"
//#define WANTED "torm_wanted_list"
//#define SENTS "torm_wanted_sentences_list"
//#define OFFENSES "torm_wanted_offenses_list"

//inherit CELLAR;
void create(){
  ::create();
set_jail_location("Torm");
set_cell("/d/dagger/Torm/city/c146.c");
set_short(
  "Beneath the Torm townhall"
  );
  set_property("indoors",1);
  set_long(
    "  You stand in a dark stone hallway beneath the mansion that is Torm's townhall."
  "  The hall runs north and south and a set of narrow stairs lead up out of the gloom."
"  A barred door sits in the west wall with a list hanging on the wall beside it."
  );
  set_exits(([
  "north":TCITY+"c148",
  "stairs":TCITY+"c125",
  "south":TCITY+"c153",
  "west":TCITY+"c150",
  ]));
  set_items(([
  "walls":"The walls are made of dull grey stone.",
   "floor":"The floors are made of dull grey stone.",
  ({"ceiling","roof"}):"The ceiling is made of dull grey stone and roughly finished.",
  "stairs":"Narrow stairs lead up to the main floor of the mansion.",
  ]));
  set_door("barred door","/d/dagger/Torm/city/c150","west","masterkey");
  set_open("barred door",0);
  set_locked("barred door",1);
}

/* void init() {
    ::init();
    add_action("add_name","add");
    add_action("list","list");
    add_action("pardon_em","pardon");
}

void msg() {
    write("Try %^RED%^<add jailer>%^RESET%^\n");
    write("Try %^RED%^<add wanted 'name' 'offense' 'sentence'>%^RESET%^");
}

int list(string str) {
    string *list,*crimes,*puns, tmp;
    int x;
    if(!str) {
        if(avatarp(TP)) {
            write("Try <list jailers>, <list prisoners>, or
            <list wanted>");
            return 1;
        }
    }
    if(str == "jailers") {
        list = SAVE_D->query_array(LIST);
        if(sizeof(list) < 1) {
            write("No one holds an official position in torm yet.");
            return 1;
        }
        write("The following people hold an official position "+
        "in the city of Torm.\n");
        for(x = 0;x < sizeof(list);x++) {
            write(capitalize(list[x]));
        }
        return 1;
    }
    if(str == "wanted") {
        list = SAVE_D->query_array(WANTED);
        crimes = SAVE_D->query_array(OFFENSES);
        puns = SAVE_D->query_array(SENTS);
        if(sizeof(list) < 1 || sizeof(crimes) < 1 || sizeof(puns) < 1) {
            write("The city of Torm has not officially labeled "+
            "anyone as a criminal.");
            return 1;
        }
       
        write("The following individuals are wanted.");
        for(x = 0;x < sizeof(list);x++) {
            tmp = capitalize(list[x]) + "  " + crimes[x] + "  ";
            if(puns[x] > 1) {
                tmp+= puns[x] + " days";
            }
            else {
                tmp+= puns[x] + " day";
            }
            write(tmp);
        }
        return 1;
    }        
        
}
      
int pardon_em(string str) {
    string *list, *sens, *crimes;
    int x;
    if(!str) {
        return 0;
    }
    if(!avatarp(TP) || member_array(TPQN,SAVE_D->query_array(LIST)) == -1) return 0;
    
    if(member_array(str,SAVE_D->query_array(WANTED)) != -1) {
        list = SAVE_D->query_array(WANTED);
        sens = SAVE_D->query_array(SENTS);
        crimes = SAVE_D->query_array(OFFENSES); 
        x = member_array(str,SAVE_D->query_array(WANTED));

         write(capitalize(str)+ " has been officially pardoned by "+
        "the city of Torm for the crime of "+crimes[x]+"!");
               
        sens = sens[0..(x-1)] + sens[(x+1)..(sizeof(sens) -1)];
        crimes = crimes[0..(x-1)] + sens[(x+1)..(sizeof(crimes)-1)];
       
        SAVE_D->remove_name_from_array(str,WANTED);
        SAVE_D->remove_array(SENTS);
        SAVE_D->remove_array(OFFENSES);
       
        for(x = 0;x < sizeof(sens);x++) {
            SAVE_D->set_value(SENTS,sens[x]);
        }
       
        for(x = 0;x < sizeof(crimes);x++) {
            SAVE_D->set_value(OFFENSES,crimes[x]);
        }
        return 1;
    }
}

int add_name(string str) {
    string nam, off, sen, tmp;
    if(!avatarp(TP) || member_array(TPQN,SAVE_D->query_array(LIST)) == -1) return 0;
    if(!str) {
        msg();
        return 1;
    }
    if(sscanf(str,"jailer %s",nam) == 1) {
        if(member_array(nam,SAVE_D->query_array(LIST)) != -1) {
            write(capitalize(nam)+" already holds an official "+
            "position.");
            return 1;
        }
        SAVE_D->set_value(LIST,nam);
        write(capitalize(nam)+" is now in official position "+
        "within the city of Torm.");
        return 1;
    }
    if(sscanf(str,"wanted %s %s %d day",nam,off,sen) == 3) {
        SAVE_D->set_value(WANTED,nam);
        SAVE_D->set_value(OFFENSES,off);
        SAVE_D->set_value(SENTS,sen);
        if(sen > 1) {
            tmp = "days";
        }
        else {
            tmp = "day";
        }
        write(capitalize(nam) + " is officially wanted within "+
            "the city of Torm, for the crime of "+off+" "+
            "and is to be sentenced to "+sen+" "+tmp+" in the jail.");
            return 1;
    }
    msg();
    return 1;

}
*/
