//updated by Circe 6/1/04 with new desc, lore, etc, by Shar
#include <std.h>

inherit ARMOUR;
void create() {
    ::create();
    set_name("helm");
    set_id(({"helm","scavenged helm","helmet"}));
    set_short("Scavenged helm");
    set_long(
@CIRCE
This helm is covered a layer of mud.  The mud has hardened to the point where you are not sure if you can really get it off, be it chipping away or washing.  Strange barbaric symbols and totems are drawn into the mud and filled with colored paste.  %^GREEN%^Olive green%^RESET%^, %^ORANGE%^yellow ochre%^RESET%^, and %^RED%^a reddish-orange brown color%^RESET%^ are the most prominent hues coloring images of what look like boars.  There are also some warg like shapes and strange symbols you can't seem to understand.
CIRCE
    );
    set_lore("The scavenged helm is typical for goblins, since they do "+
       "not have a sophisticated sense of craft.  The helm is said to "+
       "be covered with a combination of sacred mud and dung from "+
       "wargs and boars, two animals the goblins revere and worship."+
       "  The shaman or witch carves the images and symbols into the "+
       "helm to better aid the goblinoid in battle.  Fascinating, if "+
       "gross.  For the colors used to bring the images to life are "+
       "made from the urine, bile and blood of the sacred wargs and "+
       "boars.");
    set_property("lore difficulty",9);
    set_weight(5);
    set_value(10);
    set_type("helmet");
    set_limbs(({"head"}));
    set_ac(1);
    set_wear((:TO,"wearit":));
}
int wearit() {
    tell_object(ETO,"You consider the protection the helm may offer "+
      "and decide to wear it.");
    return 1;
}
