// rank 9
#include <std.h>

#define EYES ({"%^RESET%^%^CYAN%^deep %^BOLD%^sea%^RESET%^%^CYAN%^-blue","%^RESET%^%^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^let","%^RESET%^%^ORANGE%^warm brown","%^RESET%^%^RED%^f%^BOLD%^i%^YELLOW%^e%^RED%^r%^RESET%^%^RED%^y %^YELLOW%^gold"})

inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"natures ally","unicorn","mystical unicorn"}));
    set_short("%^BOLD%^%^WHITE%^my%^MAGENTA%^s%^WHITE%^ti%^CYAN%^c"
       "%^WHITE%^al u%^YELLOW%^n%^WHITE%^ic%^CYAN%^o%^WHITE%^rn%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This mystical creature looks like a "
       "majestic horse with a spotless %^RESET%^white coat%^BOLD%^ and "
       "a mane that s%^CYAN%^h%^WHITE%^i%^YELLOW%^m%^WHITE%^m%^MAGENTA%^"
       "e%^WHITE%^r%^CYAN%^s%^WHITE%^ in the light with faint hints of "
       "the %^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b"
       "%^BLUE%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^.  A single sleek, "
       "spiralling %^YELLOW%^horn%^WHITE%^ rises from the center of the "
       "creature's forehead, and its "+EYES[random(sizeof(EYES))]+" eyes %^BOLD%^%^WHITE%^are "
       "filled with wisdom and confidence.%^RESET%^");
    set_race("unicorn");
    set_body_type("equine");
    add_limb("horn","head",0,0,0);
    set_attack_limbs(({"horn","right front hoof","left front hoof"}));
    set_base_damage_type("piercing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^WHITE%^The unicorn lowers its head and charges, goring you with its horn!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^WHITE%^The unicorn lowers its head and charges, goring "+target->QCN+" with its horn!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(90)+mylevel);
    TO->remove_property("magic");
}