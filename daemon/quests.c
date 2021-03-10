/**
 * @file
 * @brief collector quest item setter
 */


#include <std.h>

#define LOW "/daemon/quests_low"
#define HIGH "/daemon/quests_high"
#define MID "/daemon/quests_mid"

inherit DAEMON;

void create(){
   ::create();
}

void isMon(object ob)
{
    if(!objectp(ob)) return;
    if(ob->query("alternative world")) return;
    if(environment(ob) && environment(ob)->query("alternative world")) return;
    LOW->isMon(ob);
    MID->isMon(ob);
    HIGH->isMon(ob);
}

void isRoom(object ob)
{
    if(!objectp(ob)) return;
    if(ob->query("alternative world")) return;
    LOW->isRoom(ob);
     MID->isRoom(ob);
    HIGH->isRoom(ob);
}

/* adding the mid ones to this after noticing they weren't here
  Circe and I don't know who added them above and not here and aren't sure if they are needed but figured better safe than waste time trying to trace it through to see if they are actually used or not *Styx* 7/05
*/

mapping queryQuests(){
    return (int)LOW->queryQuests()+(int)MID->queryQuests()+(int)HIGH->queryQuests();
}

mapping queryMonsters(){
    return (int)LOW->queryMonsters()+(int)MID->queryMonsters()+(int)HIGH->queryMonsters();
}

mapping queryRooms(){
    return (int)LOW->queryRooms()+(int)MID->queryRooms()+(int)HIGH->queryRooms();
}

void changeShort(string item, string newShort){
    LOW->changeShort(item,newShort);
    MID->changeShort(item,newShort);
    HIGH->changeShort(item,newShort);
}

void gotten(string name){

    LOW->gotten(name);
    MID->gotten(name);
    HIGH->gotten(name);
}

void resetItem(string name){
    LOW->resetItem(name);
    MID->resetItem(name);
    HIGH->iresetItemsRoom(name);
}

int claimExp(string name, object player, int level){

    LOW->claimExp(name, player, level);
    MID->claimExp(name, player, level);
    HIGH->claimExp(name, player, level);
}

int clean_up(){
   return 1;
}

void removeQuest(string name){
    LOW->removeQuest(name);
    MID->removeQuest(name);
    HIGH->removeQuest(name);
}

int cleanup(){return 1;}
