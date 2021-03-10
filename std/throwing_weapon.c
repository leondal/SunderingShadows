#include <std.h>

inherit WEAPON;

int throw_wc;
int throw_large_wc;
int throw_dice;
int throw_large_dice;
string throw_hit;

void create(){
    ::create();
}

void set_thrown_hit_func(mixed hitFunc){
    if(functionp(hitFunc)) 
    {
        set_property("thrownhit",1);
        throw_hit = (*hitFunc)(1);
    } else {
        throw_hit = hitFunc;
    }
}

void set_thrown_wc(int val,int d){
    throw_wc = val;
    throw_dice = d;
}

void set_large_thrown_wc(int val, int d){
    throw_large_wc = val;
    throw_large_dice = d;
}

int query_large_wc(){
    return throw_large_wc*throw_large_dice;
}

int query_wc(){
    return throw_wc*throw_dice;
}

int thrown_hit(object ob) {
    int damage = 0;
    if(ob->query_size() < 3) {
        damage = roll_dice(throw_wc,throw_dice );
    } else {
        damage = roll_dice(throw_large_wc,throw_large_dice );
    }
    if(query_property("thrownhit")) {
        damage += call_other(TO,throw_hit,ob);
    } else {
        message("combat",hit,environment(ob));
    }
    damage += query_property("enchantment");
    return damage;
}
