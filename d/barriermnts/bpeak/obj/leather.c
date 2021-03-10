#include <std.h>
#include <materials.h>

inherit MATERIAL;

void create(){
    ::create();
    set_type("leather"); 
    set_quality_type(random(10)+1);
    set_uses(random(10)+3);
    set_name("Leather");
    set_id(({"bolt","fine leather","leather","cloth"}));
    set_short("%^RESET%^%^ORANGE%^Some leather%^RESET%^");
    set_long("This is a bolt of "+query_quality()+" light leather that is probably best suited for clothing.");
    set_weight(5);
    set_cointype("gold");
}
int query_value() {
   return query_uses()*query_quality_type()*7;
}
