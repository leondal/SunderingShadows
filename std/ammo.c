// Changing to wearable ring-type. N, 1/13.
//Altered by Circe 12/04 - fixed weight bug with combining quivers
//Also adding ability to split quivers
#include <std.h>
//inherit OBJECT;
inherit "/std/armour";

string query_ammo_type();
int missiles;
mapping __Damage;

void create() {  // added "void" (declaration) for bug prevention *Styx* 7/14/05
    ::create();
   set_weight(3);
   set("value", 1);
   set_limbs(({ "torso" }));
   set_type("ring");
   set_ac(0);
   __Damage = ([]);
}

void init(){
    ::init();
}

int use_shots(){
    int myshots;
    return 1;
}

int query_shots(){
    return missiles;
}

void set_shots(int shots){
    missiles = shots;
}

void set_wc(int num,int plus){
    __Damage["num"] = num;
    __Damage["plus"] = plus;
}

int *query_wc(){ return (({ __Damage["num"],__Damage["plus"] })); }

void set_large_wc(int num,int plus){
    __Damage["lnum"] = num;
    __Damage["lplus"] = plus;
}

int *query_large_wc(){ return (({ __Damage["lnum"],__Damage["lplus"] })); }

void set_poisoning(int amount){
    __Damage["poison"] = amount;
}

int query_poisoning(){
    return __Damage["poison"];
}

void set_ammo_type(string type){
    set("ammo type",type);
}

string query_ammo_type(){
    return query("ammo type");
}

int query_large_ammo_damage(){
    return roll_dice(__Damage["lnum"],__Damage["lplus"]) + query_property("enchantment");
}

int query_ammo_damage(){
    int dam = roll_dice(__Damage["num"],__Damage["plus"]);
    dam += query_property("enchantment");
    //Commented out by Saide - 7 - 16 - 04
    //write("dam = "+dam);
    return dam;
}

int discard_quiver(){
   return 1;
}
