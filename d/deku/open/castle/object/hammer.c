// File    : hammer.c
// Author  : Pator@ShadowGate
// Date    : Jun 14 1995

#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_name("hammer");
    set_id( ({ "hammer", "smithhammer"}) );
    set_short("A small hammer");
    set_weight(2);
    set_size(1);
    set_wc(1,4)+1;
    set_large_wc(1,4);
    set_ac(3);
    set_type("bludgeoning");
    set_prof_type("small hammer");
    set("value", 40);
    set_long("A truly magnificent hammer of Dwarven origin.  The "+
             "head of the hammer has been forged from some dark "+
             "metal you have never seen or even heard of and inlayed "+
             "with intricate runes of pure silver.  The shaft is "+
             "also formed from some unknown metal but of a lighter "+
             "colour and seems to have been designed especially for "+
             "a strong Dwarven grip.");
    set_wield_string("Many fine objects have been made with this ! Use it with a lot of dignity");
    set_hit_func(this_object());
    set_destroy();
}

int weapon_hit(object ob) {
    int bonus;
    if(random(10) > 8) {    
         tell_object(ETO,"The hammer  S T R I K E S  "+ob->query_cap_name()+ 
               " with unimaginable blacksmith power !\n");
         tell_room(environment(query_wielded()),ETO->query_cap_name()+ "  S T R I K E S  "+
             ob->query_cap_name()+ " with unimaginable blacksmith power!\n",({ob,ETO}));
               tell_object(ob,""+ETO->query_cap_name()+"  S T R I K E S  you with unimaginable blacksmith power!\n");
        bonus = 5+random(10);
        return bonus;
    }
    return 0;
}
