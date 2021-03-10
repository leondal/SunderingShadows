//by Circe 6/7/04 for Tabor tailor, desc by Shar
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("golden link belt");
   set_short("%^YELLOW%^golden link belt%^RESET%^");
   set_id(({"belt","golden belt","golden link belt","gold belt"}));
   set_long(
@CIRCE
%^ORANGE%^Made from burnished brass, to look like %^YELLOW%^gold%^RESET%^%^ORANGE%^, this metal belt looks quite heavy.  Made to encircle a womans waist and rest low on her hips, this belt is commonly used by many %^MAGENTA%^dancers %^ORANGE%^and %^CYAN%^entertainers %^ORANGE%^in the Tsarven Empire.  %^YELLOW%^Golden disks %^RESET%^%^ORANGE%^that look like %^BOLD%^%^WHITE%^coins %^RESET%^%^ORANGE%^hang by the hundreds from the belt, chiming as the wearer moves about or shakes her hips.%^RESET%^
CIRCE
   );
   set_weight(3);
   set_type("ring");
   set_limbs(({"waist"}));
   set_ac(0);
   set_value(40);
   set_wear((:TO,"wearme":));
   set_property("repairtype",({ "tailor","jewel" }));
}

void init(){
   ::init();
   add_action("shake_em","shake");
}

int wearme(){
   tell_object(ETO,"%^YELLOW%^You settle the golden links around your "+
      "hips, and you feel the urge to %^CYAN%^<%^YELLOW%^shake%^CYAN%^> "+
      "%^YELLOW%^your hips to hear the "+
      "coins jingle again.");
   tell_room(EETO,"%^YELLOW%^The light clinking of coins can be heard "+
      "as "+ETOQCN+" settles the golden belt low on her hips.",ETO);
   return 1;
}

int shake_em(string str)
{
        if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
        }

        if(query_worn() && str == "hips") {
                tell_room(EETO,"%^BOLD%^"+ETOQCN+" shakes her hips "+
                   "seductively, filling the area with the rhythmic "+
                   "melody of the jingling coins.",ETO);
                tell_object(ETO,"%^BOLD%^You shake your hips, and "+
                   "the coins seem to add their own rhythmic "+
                   "melody to your dance.",ETO);
                return 1;
        }
}
