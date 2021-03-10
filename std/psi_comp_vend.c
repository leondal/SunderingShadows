#include <std.h>
#include <money.h>
#include <move.h>

#define MAX_COMPONENTS 40
#define COMP_PATH "/d/magic/store_psi_comp"
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

buy_quantity(string str, int number){
    return;
}

int __List(string str) {
   return 1;
}

string sort_strings(string one,string two) {
    return "";
}

int set_components(int total) {
   return 1;
}

string *query_components() {return Available;}

mixed sort_items(object one,object two) {
   return strcmp(one->query_short(),two->query_short()); 
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

