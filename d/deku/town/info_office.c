#include <std.h>
#include <daemons.h>
#define LF_AR "deku_names_seeking_array"
#define LF_RW "deku_names_seeking_rewards_array"
#define VCONTRACTS "valid_deku_contracts"
inherit ROOM;
int guards_out;
void make_list();

void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_short("%^RED%^Verbobone Information Office%^RESET%^");
  set_long("This building is massive, its walls and ceiling formed "+
  "from heavy wooden logs.  The floor of this building is "+
  "constructed of several flat slabs of oak that have been "+
  "carefully placed together to create a solid surface.  Desks "+
  "line the east wall and numerous pieces of parchment litter "+
  "each desk. A large round table sits in the center of this "+
  "building, its surface marred with stains from recent spills, "+
  "apparently of both food and drink.  Your first thought is "+
  "that it serves as a dining table for the individuals who "+
  "work night and day here, trying to recover the decades of "+
  "lost people of verbobone and its surroundings.  The north "+
  "wall of this room is littered with large pieces of parchment "+
  "but one large %^RED%^notice%^RESET%^ "+
  "immediately catches your attention.  The door "+
  "leading out of this building is an open doorway, reflecting "+
  "the fact that this building is never closed.");

  set_listen("default","The excited chatter of people eager to find lost loved ones fills this room.");
  set_smell("default","Body odor has mixed with the scent of "+
  "fresh ink and parchment, assaulting this room.");

  set_exits((["west":"/d/deku/town/road11"]));
  set_items(([ ({"notice","notices"}) : ({"%^RED%^These are large "+
  "pieces of parchment that have been attached to the north "+
  "wall.  A large central one really catches your attention, you "+
  "could probably read it.",(:TO,"display_info":),"wizish"}),
     ] ));
  guards_out = 0;
  new("/d/deku/monster/elite_guard")->move(TO);
  new("/d/deku/monster/elite_guard")->move(TO);
  if(!present("dariul")) { find_object_or_load("/d/deku/monster/dariul_tymor")->move(TO); }
  make_list();
}

void make_list() 
{
    int x, tmp;
    string *people,person,*rewards,tmp2;
    tmp = sizeof(SAVE_D->query_array(LF_AR));
    if(tmp < 4) 
    {
        for(x = 0;x < 4 - tmp;x++) {
            if(sizeof(SAVE_D->query_array("deku_dead_names_array")) < 1 
            || sizeof(SAVE_D->query_array("deku_missing_names_array")) < 1) {
                "/d/deku/inherits/name_gen_d.c"->make_dead_name_list();
                "/d/deku/inherits/name_gen_d.c"->make_missing_name_list();
            }
            people = random(2) ? SAVE_D->query_array("deku_dead_names_array") : SAVE_D->query_array("deku_missing_names_array");
            person = people[random(sizeof(people))];
            if(member_array(person,SAVE_D->query_array(LF_AR)) != -1) {
                  x--;
                  continue;
            }
            SAVE_D->set_value(LF_AR,person);
            SAVE_D->set_value(LF_RW,300 + random(300) + random(300) + random(200));
        }
    }
}

void init() {
    ::init();
    add_action("display_contracts","display");
    add_action("void_contract","void");
}

void query_guards_out() {
    return guards_out;
}
int add_guards_out(int x) {
   guards_out += x;
   return 1;
} 

void do_rewards() {
    int x;
    string tmp2, *people, *rewards;
    write("Rewards are offered for information leading to the "+
    "location of the following individuals, dead or alive.\n");

    write("%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    people = SAVE_D->query_array(LF_AR);
    rewards = SAVE_D->query_array(LF_RW);
    for(x = 0;x < sizeof(people);x++) {
      tmp2 = sprintf("%%^RED%%^ %-20s %%^YELLOW%%^ %2d%%^RESET%%^ gold coins.",capitalize(people[x]),rewards[x]);
      write(tmp2);
    }
}

void display_info() {
   string str, tmp;
   write("%^RED%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n");

   str = "The city of verbobone is currently offering contracts "+
   "to invidiuals interested in investing gold for the furthering "+
   "of our humble town.  You can now %^CYAN%^<buy contract for # gold>%^RESET%^.  "+
   "The town will offer contracts of up to 5,000 gold "+
   "pieces in value and honor those that have reached up to "+
   "twice their original worth in value.  You need simply to give them "+
   "to our Dariul while he is in to collect the gold for the "+
   "contract.  You may have him %^CYAN%^<estimate contract>%^RESET%^"+
   " to get the current worth of a contract that you carry.";
   if(avatarp(TP)) {
        tmp = "\n\nAVATARS ONLY - You may %^CYAN%^<display "+
        "contracts>%^RESET%^ to view those that have been "+
        "sold by ID (A long string of random nums & letters.) - "+
        "You may %^CYAN%^<void contract #>%^RESET%^ to void anything in "+
        "that list.  Please have a valid reason to void a contract.";
   }
   if(tmp) {
        str += tmp;
   }
   return str;

  //"'request a guard' from him or <show> him someone who was "+
  //"missing that you have brought in and if you owe a fine "+
  //"you may %^RED%^<pay fine>%^RESET%^%^CYAN%^.  ");

}

int read_list(string str) {
    if(!str) { return 0; }
   // if(str == "notices") {
     //   write("Read %^CYAN%^<seeking notice>%^RESET%^, "+
      //  "%^CYAN%^<dead notice>%^RESET%^, or %^CYAN%^<returned "+
       // "noticed>%^RESET%^");
       // return 1;
    //}
    /*if(str == "seeking notice") {
        do_rewards();
        return 1;
    }
    if(str == "dead notice") {
        write("list of dead people reported already and dates associated with them");
        return 1;
    }
    if(str == "returned notice") {
        write("list of missing people returned already");
        return 1;
    }*/
}

void display_contracts(string str) {
    int x;
    string *tmp, tmp2;
    if(!str) return 0;
    if(!avatarp(TP)) return 0;
    if(str == "contracts" || str == "contract" || str == "bonds") {
        write("The following bonds have been recorded as sold and "+
        "not yet claimed.");
        tmp = SAVE_D->query_array(VCONTRACTS);
        for(x = 0;x < sizeof(tmp);x++) {
            if(tmp2) {
                tmp2 += x +":%^BOLD%^%^GREEN%^ "+tmp[x]+"\n";
                continue;
            }
            tmp2 = x + ":%^BOLD%^%^GREEN%^ "+tmp[x]+"\n";
            continue;
        }
        if(tmp2) {
            TP->more(explode(tmp2,"\n"));
        }
        return 1;
    }
    return 0;
}

void void_contract(string str) {
    string tmp,*tmp2;
    int num;
    if(!str) return 0;
    if(sscanf(str,"%s %d",tmp,num) == 2) {
        if(tmp == "contracts" || tmp == "contract" 
        || tmp == "bonds") {
            tmp2 = SAVE_D->query_array(VCONTRACTS);
            if(tmp2[num] != -1) {
                SAVE_D->remove_name_from_array(VCONTRACTS,tmp2[num]);
                write("Contract "+tmp2[num]+" officially rendered "+
                "void.");
                return 1;
            }
            write("No such contract is currently valid.  Try again.");
            return 1;
        }
        return 0;
    }
    return 0;
}

        

void reset() {
    ::reset();
    if(!present("dariul")) { find_object_or_load("/d/deku/monster/dariul_tymor")->move(TO); }
}
