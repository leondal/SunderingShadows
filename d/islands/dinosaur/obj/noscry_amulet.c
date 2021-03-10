#include <std.h>

inherit ARMOUR;
int uses;

void create()
{
    ::create();
    set_name("%^BOLD%^%^CYAN%^Amulet of %^BLACK%^Concealment%^RESET%^");
    set_short("%^RESET%^%^CYAN%^Clouded Amulet%^RESET%^");
    set_id( ({"amulet", "clouded amulet", "dark amulet"}) );
    set_long(
        "This amulet, slightly %^RESET%^%^RED%^warm %^RESET%^to the touch, looks almost "
        "like %^BOLD%^%^BLACK%^thickened %^RESET%^%^CYAN%^smoke %^RESET%^or %^BOLD%^f%^BLACK%^o%^WHITE%^g%^RESET%^.  "
        "There is a slight %^BOLD%^%^CYAN%^glow %^RESET%^around the amulet as you look at it, with its long "
        "%^BOLD%^%^WHITE%^white chain %^RESET%^and %^BOLD%^clasp%^RESET%^.  As you stare at it the "
        "%^BOLD%^%^BLACK%^hyroglyphic image %^RESET%^of an %^BOLD%^%^BLACK%^eye %^RESET%^appears in "
        "%^BOLD%^%^BLACK%^black %^RESET%^for a second, then fades away."
    );

    set_lore("These amulets were rumored to have been created by a cult of mages which inherit an "
        "ominous tower on the northern cliffs of dino island.  Rumors suggest that the mages found "
        "a place on an island in the middle of dino lake which was impervious to their magical "
        "scrying attempts.  They traveled to this location expecting to find a great wizard protecting "
        "against their magic, but instead they found a strange mineral which had a natural resistance "
        "to being scried.  The mages then turned small pieces of the mineral into these amulets.");
    set_weight(1);
    set_value(1000);
    set_type("clothing");
    set_limbs( ({"neck"}) );
    set_ac(0);
    set_property("magic", 1);
    set_wear( (:TO, "wearme":) );
    set_remove( (:TO, "removeme":) );
    uses = random(30)+1;
}

void init(){
    ::init();
    if(environment(TO) == TP) set_size(TP->query_size());
}

int wearme()
{
    if(!objectp(ETO)) return 0;
    ETO->set_property("no scry", 1);
    tell_object(ETO, "The amulet glows briefly.");
    return 1;
}

int removeme(){
    uses--;
    if(objectp(ETO))
    {
        ETO->remove_property("no scry", 1);
        tell_object(ETO, "The amulet fades slightly.");
    }
    if(uses < 0)
    {
        if(objectp(ETO)) tell_object(ETO, "The chain around your neck goes limp as the amulet fades away.");
        TO->remove();
    }
    return 1;
}
