#include <std.h>
inherit THROWING_WEAPON;


void create() {
    ::create();
    set_id(({"bottle","bottle of red liquid","alchemist's fire"}));
    set_name("Alchemist's fire");
    set_obvious_short("A bottle of %^RED%^red%^RESET%^ liquid");
    set_short("%^RED%^alchemist's fire%^RESET%^");
    set_long("This is a bottle of some strange red liquid."+
	"  It is kept in a glass container with a rubber "+
	"cork keeping the top shut.  It is filled with a "+
	"thick %^RED%^red liquid%^RESET%^. Likely if thrown at "+
	"something solid it would break open and cover "+
	"them with whatever is inside.");
    set_lore("This the creation of an alchemist.  The liquid inside"+
	" is a special kind of alchemist's fire.  The idea is to throw"+
	" it and hit your enemy and they will burst into flames.  "+
	"The elven magi have found a way to make this batch extra potent.");
    set_property("lore difficulty",12);
    set_weight(2);
    set_value(1000);
    set_wc(1,2);
    set_large_wc(1,2);
    set_large_thrown_wc(1,10);
    set_thrown_wc(1,6);
    set_thrown_hit_func((:TO,"throw_j":));
	set_prof_type("spear");
	set_weapon_prof("simple");
}



int throw_j(object ob) {
        tell_object(ob,"%^ORANGE%^"+ETO->QCN+" throws a bottle at "+
           "you, and it breaks, the liquid catches %^RED%^fire%^ORANGE%^ instantly burning you!");
        tell_room(environment(ob),"%^ORANGE%^"+ETO->QCN+" hurls a "+
           "bottle at "+ob->QCN+" and it shatters on "+ob->QO+" catching "+
           "%^RED%^fire!",({ob,TP}));
        ob->cause_typed_damage(ob,0,roll_dice(5,10),"fire");
        return 1+TO->remove();
}