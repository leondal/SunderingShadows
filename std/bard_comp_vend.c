//adapted from comp_vend by Nienne
//if something changes here, please check /std/comp_vend and /std/psi_comp_vend
//to see if the changes are needed there as well.

#include <std.h>
#include <money.h>
#include <bardcomps.h>
#include <move.h>

#define MAX_COMPONENTS 40
#define COMP_PATH "/d/magic/store_bard_comp"
inherit NPC;

string *Available;
mapping Amount = ([]);

void create(){
     ::create();
}

void init() {
   ::init();
}

int __Buy(mixed str) {
   return 1;
}

void buy_quantity(string str, int number){
}

int __List(string str) {
   return 1;
}

string *query_components() {return Available;}

mixed sort_items(object one,object two) {
    return 1;
}

int __Help(string nothing) {
   return 1;
}

int get_amount(int price) {
   return 0;
}

void sell_comp(int number, int amount) {
    return;
}
