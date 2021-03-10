#include <std.h>

inherit WEAPONLESS;

object master, controller;
int price;

void set_master(object ob);
void set_controller(object ob);
object query_master();
object query_controller();
void set_price(int i);
int query_price();
void escape_master();

void create(){
    ::create();

}

void init(){
    ::init();

}

void escape_master(){
    int i;
    object *inv;

    inv = all_inventory(TO);
    if( !inv || !sizeof(inv) ){
      tell_room(ETO, "%^YELLOW%^The slave looks about with fear in "+TO->query_possessive()+" eyes, and suddenly runs like "+TO->query_subjective()+" was being chased by the hounds of hell.");
      TO->move("/d/shadowgate/void.c");
      TO->remove();
      return;
    }

    for(i=0;i<sizeof(inv);i++){
    if(!objectp(inv[i])) continue;
      inv[i]->remove();
    }
    tell_room(ETO, "%^YELLOW%^The slave looks about with fear in "+TO->query_possessive()+" eyes, and suddenly runs like "+TO->query_subjective()+" was being chased by the hounds of hell.");
    TO->move("/d/shadowgate/void.c");
    TO->remove();

}

void heart_beat(){
    ::heart_beat();

    if(!objectp(master) || !objectp(controller) ){
      escape_master();
      return;
    }
}



object query_master() { return master; }
object query_controller() { return controller; }
void set_master(object ob) { master = ob; }
void set_controller(object ob) { controller = ob; }
int query_price() { return price; }
void set_price(int i) { price = i; }
