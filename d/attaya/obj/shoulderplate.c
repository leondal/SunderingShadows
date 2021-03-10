//updated by Circe 1/1/05 with new desc, lore, etc.
#include <std.h>;
inherit ARMOUR;

void create(){
    ::create();
    set_name("shoulder plates");
    set_id(({"shoulderplates","shoulder plates","plates","silver shoulder plates"}));
    set_obvious_short("silver shoulderplates");
    set_short("%^BOLD%^%^WHITE%^Silver Shoulderplates of the Kinnesaruda%^RESET%^");
/*
    set_long("%^RED%^They are heavy metal plates, attached to a center breastplate.  The shoulderplates are about 2 feet long each and are silver with red and gold accents.");
*/
    set_long("%^BOLD%^These shoulderplates are made of heavy "+
       "metal with a silvered finish.  Each shoulderplate is "+
       "about two feet long, extending well over the wearer's "+
       "shoulder and ending in a curving point.  %^RED%^Red "+
       "%^WHITE%^and %^YELLOW%^gold %^WHITE%^accents have "+
       "been worked into the metal, adding to their dazzling "+
       "appearance.  The shoulderplates are attached to a center "+
       "breastplate which may be worn over other armor, though "+
       "the rising neck guard would probably make wearing other "+
       "neck ornamentation such as a cloak or necklace impossible.%^RESET%^");
    set_lore("Despite their pristine appearance that makes these "+
       "shoulderplates seem somewhat angelic, they actually "+
       "stem from a rather evil source.  They match the description "+
       "of shoulderplates worn by Intruder, who is known to "+
       "rule over the Crystalline Tower of the Black Dawn.  "+
       "Intruder commands the powerful forces of the undead "+
       "including the fallen god Ashtar and his follower Bishimon.  "+
       "Some claim the breastplates house part of Intruder's "+
       "power, while others say that's impossible.");
    set_property("lore difficulty",16);
    set_weight(5);
    set_limbs(({"neck", "left arm", "right arm"}));
    set_type("clothing");
    set_value(1400);
    set_ac(2);
    set_property("enchantment",2);
    set_wear((:TO, "extra_wear":));
    set_remove("You unlatch the shoulderplates and slip them off.");
}
int extra_wear() {
    if((int)ETO->query_lowest_level() < 35) {
	tell_object(ETO,"This is the armor of an experienced "+
         "warrior...  You are not ready.");
	return 0;
    }
    tell_object(ETO,"You slip the cast silver shoulderplates "+
         "onto over your shoulders and attach them to the breastplate.");
    return 1;
}
