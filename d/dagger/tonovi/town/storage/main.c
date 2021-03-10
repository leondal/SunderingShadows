//Added limits to the total number of mobs - *Styx* 3/3/02

#include "/d/dagger/tonovi/town/short.h"

inherit CROOM;

string GRtype;
int citmax, gd1max, gd2max;
void check_critters();

void set_room_type(string str);
string query_room_type();

void create(){
    set_monsters(({ "/d/dagger/tonovi/guards/guard" }),({ random(2)}));
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    GRtype = "none";
}

void set_room_type(string str){
    if(str) {
   GRtype = str;
    } else {
   GRtype = "none";
    }
}

string query_room_type() { return GRtype; }

void init(){
//    string rmtype;
//    object ob;
    ::init();
/* moved to reset and adapted for population control by Styx 3/3/02
    if(Gmonmade) return;
    Gmonmade++;
    if(random(3)) return;
    if(present("Gtonovimon")) return;
    if(random(3)) return;
    rmtype = TO->query_room_type();
    if(ob = OVER->get_room_monster(rmtype))
      if(objectp(ob)) ob->move(TO);
    Gmonmade++;
    return;
*/
}

void reset(){
    string rmtype;
    object ob;
    ::reset();
    //if(base_name(TO) == MAIN)       check_critters();
    if(present("Gtonovimon"))       return;
    if(citmax && gd1max && gd2max)  return;
    if(random(2))                   return;
    rmtype = TO->query_room_type();
    //if((rmtype == "bazaar" || rmtype == "street") && (citmax || gd1max))
    //   return;
    //if(ob = OVER->get_room_monster(rmtype))
    //  if(objectp(ob)) ob->move(TO);
    return;
}
/*
void check_critters() {
   if(sizeof(children("/d/dagger/tonovi/mon/citizen")) > 15)
      citmax = 1;
   if(sizeof(children("/d/dagger/tonovi/guards/guard")) > 25)
      gd1max = 1;
   if(sizeof(children("/d/dagger/tonovi/mon/guard2_city")) > 20)
      gd2max = 1;
}
*/
