//updated with new desc, lore, etc by Circe 6/13/04
//Coded by Bane//
#include <std.h>
inherit THROWING_WEAPON;


void create() {
    ::create();
    set_id(({"javelin","lightning","javelin of lightning"}));
    set_name("Javelin of Lightning");
    set_obvious_short("A long flawless javelin");
    set_short("%^YELLOW%^Javelin of Lightning%^RESET%^");
    set_long("This well-made javelin is made of wood and fitted with "+
       "a mithril tip.  Although it is very smooth, it has been "+
       "with the image of a long, jagged lightning bolt running "+
       "from tip to base.  The image is repeated on the other side, "+
       "and the javelin spins when it is thrown, making it seem as "+
       "though a bolt of lightning it being hurled at the target.");
    set_lore("Modelled after the lightning bolts of the titans, "+
       "the javelin of lightning was originally made to make "+
       "the forces of Light combating the hordlings that invaded "+
       "Laerad look that much more fearsome.  A bolt of lightning "+
       "seemingly coming from thin air was enough to make many "+
       "of the less intelligent hordlings run, while it took "+
       "more than that for the brighter ones.  These javelins are "+
       "still favored by many of the good-hearted combatants on the "+
       "Gods Plains.");
    set_property("lore difficulty",12);
    set_weight(5);
    set_value(100);
    set_wc(1,6);
    set_large_wc(1,10);
    set_large_thrown_wc(1,10);
    set_thrown_wc(1,6);
    set_thrown_hit_func((:TO,"throw_j":));
    set_type("piercing");
set_prof_type("spear");

}

int throw_j(object ob) {
        tell_object(ob,"%^BOLD%^YELLOW%^"+TPQCN+" hurls a Javelin at "+
           "you, and it strikes you in the chest!");
        tell_room(environment(ob),"%^BOLD%^YELLOW%^"+TPQCN+" hurls a "+
           "Javelin at "+ob->QCN+" and it strikes "+ob->QO+" in "+
           "the chest!",({ob,TP}));
        tell_room(ETP,"%^BOLD%^The Javelin forms into a lightning bolt!");
        return random(20)+30+TO->remove();
}
