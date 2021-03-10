#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("A majestic shrine");
   set_short("%^RESET%^%^MAGENTA%^A majestic shrine%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^A majestic shrine%^RESET%^\n"+
      "Featuring a much lower ceiling than the vaulted dome "+
      "in the fountain room, this chamber is blessed with a "+
      "reverent %^CYAN%^hush%^RESET%^ that lends an atmosphere of "+
      "worship.  The %^MAGENTA%^amethyst floor %^RESET%^is "+
      "partially covered by an %^CYAN%^az%^BOLD%^ur%^RESET%^"+
      "%^CYAN%^e runner %^RESET%^trimmed in %^BOLD%^%^BLUE%^cobalt "+
      "%^RESET%^and featuring %^ORANGE%^thread-of-bronze %^RESET%^"+
      "embroidery along the edges.  Chairs are arranged in rows "+
      "on either side of the %^CYAN%^runner%^RESET%^, which leads "+
      "directly to an %^BOLD%^altar %^RESET%^carved from "+
      "%^BOLD%^%^BLUE%^deep co%^RESET%^%^BLUE%^ba%^BOLD%^lt blue "+
      "crystal%^RESET%^.  The edges of the altar have been carved and "+
      "filled with %^ORANGE%^molten bronze%^RESET%^, echoing the "+
      "colors of the %^BOLD%^stylized eye %^RESET%^depicted on the "+
      "altar's front.  Atop the altar is a wide %^MAGENTA%^cr%^CYAN%^"+
      "yst%^BOLD%^a%^WHITE%^l%^CYAN%^l%^RESET%^%^CYAN%^in%^MAGENTA%^"+
      "e bowl %^RESET%^filled with cut crystals in all hues.  "+
      "The altar is braced on either side by intricate "+
      "%^ORANGE%^bronze candelabra %^RESET%^fitted with fashionable "+
      "%^BOLD%^%^BLUE%^ca%^RESET%^%^BLUE%^n%^CYAN%^dl%^BOLD%^%^BLUE%^es "+
      "%^RESET%^in shades of %^BLUE%^blue%^RESET%^.  The walls here "+
      "have been hung with slender %^BLUE%^tapestries%^RESET%^ "+
      "ending in points capped with %^ORANGE%^bronze tassels%^RESET%^.\n");
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items( ([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^MAGENTA%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.  Each wall "+
         "has been hung at intervals with three separate %^BLUE%^"+
         "tapestries%^MAGENTA%^, each trimmed in %^ORANGE%^bronze "+
         "%^MAGENTA%^and ending in a %^ORANGE%^bronze tassel%^MAGENTA%^.%^RESET%^",
      ({"doorway","doorways","arches","archway","archways"}) : "The "+
         "walls of the room are unbroken save by the archway leading "+
         "to the west.",
      ({"tapestry","tapestries"}) : "%^BLUE%^Each tapestry is fashioned "+
         "from flawless blue cloth and features the %^BOLD%^stylized "+
         "eye%^RESET%^%^BLUE%^ that is the holy symbol of the "+
         "%^BOLD%^%^CYAN%^Master of the Invisible Art%^RESET%^%^BLUE%^, "+
         "%^BOLD%^%^WHITE%^god of minds%^RESET%^%^BLUE%^.  The tapestries "+
         "have all been trimmed in %^ORANGE%^bronze braid%^BLUE%^, and "+
         "their pointed ends are capped with a %^ORANGE%^bronze tassel"+
         "%^BLUE%^.%^RESET%^",
      "altar" : "%^BOLD%^%^BLUE%^The altar is made from a single cobalt "+
         "crystal, carved with smooth planes so as to appear %^BOLD%^"+
         "%^BLACK%^black %^BLUE%^at its very center.  Near the edges "+
         "narrow channels have been carved and filled with %^RESET%^"+
         "%^ORANGE%^molten bronze%^BOLD%^%^BLUE%^, giving definition "+
         "to its form.  The front of the altar is carved with a "+
         "beautiful depiction of the holy symbol of %^CYAN%^god of minds"+
         "%^BLUE%^, a stylized eye.%^RESET%^",
      ({"bowl","crystal bowl","crystalline bowl"}) : "%^MAGENTA%^The "+
         "cut crystalline bowl is made from an %^BOLD%^amythest"+
         "%^RESET%^%^MAGENTA%^, providing an eye-catching contrast "+
         "to the blue of the altar.  It is filled with crystals of "+
         "all shapes, sizes, and colors, most of which are likely "+
         "offerings from the faithful and other psions paying their "+
         "respects to the deity widely known as the father of "+
         "psionics.  The bowl is sitting atop a %^BOLD%^%^WHITE%^pure "+
         "white %^RESET%^%^MAGENTA%^altar cloth, cut into a hexagon "+
         "and edged in %^BOLD%^%^CYAN%^light blue%^RESET%^%^MAGENTA%^.%^RESET%^",
      ({"chair","chairs"}) : "%^ORANGE%^The chairs are crafted of "+
         "%^YELLOW%^burnished oak %^RESET%^%^ORANGE%^and fitted with "+
         "%^BOLD%^%^BLUE%^cobalt cushions %^RESET%^%^ORANGE%^to provide "+
         "a place for worshippers to sit.  There seem to be enough here "+
         "for a small congregation, with three rows of four chairs each "+
         "on either side of the runner.%^RESET%^",
      "runner" : "%^BLUE%^The runner echoes the deep blue of the "+
         "tapestries in the cobalt edges, though the fabric itself "+
         "is a %^BOLD%^lighter shade%^RESET%^%^BLUE%^.  Near the "+
         "edging are lines of %^ORANGE%^bronze embroidery%^BLUE%^, "+
         "giving the runner definition.%^RESET%^",
      ({"candles","candelabra","bronze candelabra"}) : "The candelabra "+
         "are elaborate %^ORANGE%^bronze creations%^RESET%^, featuring "+
         "candles in different shades of blue at various heights.  "+
         "They lend a soft illumination to the shrine that seems "+
         "somewhat at odds with the strange sky seen through the "+
         "translucent crystal roof."
   ]));
   set_exits(([
      "west" : "/d/shadow/room/city/portal/fountain"
   ]));
}

void init(){
   ::init();
   add_action("worship","worship");
}

int worship(string str){
   if(!str){
      tell_object(TP,"You shouldn't try to <worship> here.  This place is abandoned.");
      return 1;
   }
   if(str != "god of minds" && str != "god of minds" && str != "at altar"){
      tell_object(TP,"You should try to <worship god of minds> here.");
      return 1;
   }
   if((string)TP->query_diety() != "god of minds"){
      tell_object(TP,"%^BOLD%^You kneel before the %^BLUE%^altar %^WHITE%^of "+
         "the %^CYAN%^Enlightened One%^WHITE%^ to pay your respects.%^RESET%^");
      if(!TP->query_invis()){
         tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" %^BOLD%^%^WHITE%^kneels "+
            "before the altar to pay "+TP->QP+" respects.%^RESET%^",TP);
      }
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^As you kneel before the altar of "+
      "the %^CYAN%^Enlightened One%^WHITE%^, you feel a sense of peace "+
      "as all the world's complexities are suddenly revealed to you.  "+
      "If only you could feel this clarity forever...%^RESET%^");
   if(!TP->query_invis()){
      tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" %^BOLD%^%^WHITE%^kneels "+
         "before the altar to pay "+TP->QP+" respects.%^RESET%^",TP);
   }
   return 1;
}