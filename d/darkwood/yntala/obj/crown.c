#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("%^YELLOW%^A golden crown%^RESET%^");
        set_id(({ "crown", "golden crown"}));
        set_short("%^YELLOW%^A golden crown%^RESET%^");
        set_long("%^YELLOW%^This is a five-tipped golden crown that looks like it would be worn on somebodies"
" head rather crookedly.  It also looks to be quite heavy.  The base of the crown is about a quarter of an inch"
" thick, and about five inches tall, with each pointed tip raising another seven inches from there, ending in"
" large, fist-sized golden balls.\n");
        set_lore(
@AVATAR
%^YELLOW%^This is the crown worn by Maklakia, king of the leprechauns.  It is said that Maklakia generally lets the other leprechauns take care of guarding the leprechauns treasures, but when one feels like they are outmatched, they will scream for Maklakia's help and he will appear!
AVATAR
        );
        set_weight(2);
        set_value(3500);
        set_type("ring");
        set_limbs(({"head"}));
        set_size(1);
}
