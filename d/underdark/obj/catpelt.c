#include <std.h>
#include <materials.h>
inherit MATERIAL;

void create(){
    ::create();
    set_type("leather"); 
    set_quality_type(random(8)+3);
    set_uses(random(10)+3);
    set_subtype("sable hide");
    set_name("black leather");
    set_id(({"fine leather","leather","black leather","pelt","black pelt"}));
    set_short("%^BOLD%^%^BLACK%^A soft sable pelt%^RESET%^");
    set_long("%^ORANGE%^This pelt is covered in a short layer of %^BOLD%^%^BLACK%^soft black fur%^RESET%^"
"%^ORANGE%^, that %^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^mm%^BOLD%^e%^RESET%^%^WHITE%^rs%^ORANGE%^ with "
"a glossy sheen. The hide is of "+query_quality()+". A skilled crafter could probably use it to create a "
"garment or light armor of some kind.%^RESET%^");
    set_weight(5);
    set_cointype("gold");
}
int query_value() {
   return query_uses()*query_quality_type()*7;
}
