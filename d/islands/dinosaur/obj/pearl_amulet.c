#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"
#define ORB "/d/magic/obj/sols_orb.c"

inherit ARMOUR;
int pearls;

void create(){
    ::create();
    set_name("Pearl Amulet");
    set_short("%^BOLD%^Pearl Amulet%^RESET%^");
    set_id( ({"amulet", "pearl amulet", "pearl"}) );
    set_long( (:TO, "long_func":) );
    set_weight(5);
    set_value(3000);
    set_type("clothing");
    set_limbs( ({"neck"}) );
    set_ac(0);
    set_property("magic", 1);
    pearls = 3;
}

void init(){
    ::init();
    add_action("extract", "extract");
}

string long_func(string str){
    str = "This exquisitely crafted necklace is made from the finest of gold, and bears several large pearls attached to it at the base.";
    switch(pearls){
      case 1:
        str += "\nThere is one pearl attached to it.";
        break;
      case 2:
        str += "\nThere are two pearls attached to it.";
        break;
      case 3:
        str += "\nThere are three pearls attached to it.";
        break;
      default:
        str += "\nThere are no pearls attached to it.";
      break;
    }
    str += "\nIt looks like you can extract the pearls from the amulet.";
    return str;
}

int extract(string str){
    object ob;

    if(!str || str != "pearl") return notify_fail("Remove what?\n");
    if(!pearls) return notify_fail("There are no pearls left on the necklace.\n");

    tell_object(TP, "%^BOLD%^%^RED%^As you remove the pearl from the necklace it begins to burn in your hand with a strange power.  Perhaps you should <throw orb at target> or maybe <throw orb direction>. %^RESET%^");
    ob = new(ORB);
    ob->set_caster(TP);
    ob->set_level((int)TP->query_lowest_level()/2);
    ob->move(TP);
    pearls -= 1;
    set_value((pearls * 1000) + 10);
    return 1;
}

