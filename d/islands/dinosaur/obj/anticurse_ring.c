#include <std.h>

inherit "/std/armour.c";
int uses;

void create(){
    ::create();
    set_name("ring of curse protection");
    set_short("small turquoise ring");
    set_id( ({"ring", "small ring", "turquoise ring", "small turquoise ring"}) );
    set_long(
      "This small ring is made mostly of a dull silver, but in the center of the ring on the top is a decent sized turquoise stone."
    );
    set_property("magic", 1);
    set_property("enchantment", -1);
    while(query_property("enchantment") != -1){
      remove_property("enchantment");
      set_property("enchantment", -1);
    }
    set_type("ring");
    set_ac(0);
    set_value(200);
    set_limbs( ({"right hand", "left hand"}) );
    uses = 1+random(3);
}

void init(){
    ::init();
    add_action("check_curse", "wear");
    add_action("check_curse", "wield");
}

int check_curse(string str){

    object ob;
    object *lst;

    if(!str) return 0;
    if(!query_worn()) return 0;
    if(query_property("enchantment") != -1) return 0;
    if(uses <= 0) return 0;
    if(!ob = present(str, TP)) return 0;

    if(ob->query_property("enchantment") && ob->query_property("enchantment") > 0) return 0;
    if(ob->query_property("anticurse"))
      lst = ob->query_property("anticurse");
    else
      lst = ({ });

    if(member_array(TPQN, lst) == -1){
      tell_object(TP, "The turquoise ring flashes brightly for a second as you start to "+query_verb()+" the "+ob->query_short()+".");
      ob->set_property("anticurse", ({TPQN}));
      uses--;
      return 1;
    }
    return 0;
}

int query_uses() {
    return uses;
}

void set_uses(int x){
    uses = x;
}
