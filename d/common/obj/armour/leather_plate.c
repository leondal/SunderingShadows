//leather_plate - leather breastplate as an alternative for thieves
//Circe 9/9/04
inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(7);
    set_armor_prof("light");
    set_name("leather breastplate");
    set_id(({"armor","leather","leather plate","leather breastplate","breastplate","plate"}));
    set_short("%^RESET%^%^ORANGE%^leather breastplate%^RESET%^");
    set_long("This breastplate is made of tanned leather that is still "+
       "rather supple and fits close to the wearer's body, moving with "+
       "him.  For added protection, metal rivets dyed to match the "+
       "leather have been added at intervals so as not to hamper "+
       "movement.  The breastplate is often a prime choice for "+
       "those concerned with appearances who do not like to be "+
       "seen in a full suit of armor.");
    set_weight(14);
    set_value(350);
    set_type("leather");
    set_limbs(({"torso"}));
    set_ac(3);
}

int is_metal() { return 0; }
