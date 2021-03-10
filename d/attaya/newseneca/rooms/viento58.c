//viento58 - Circe 11/17/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"Two large %^CYAN%^windows %^RESET%^in the %^BOLD%^"+
      "stone building %^RESET%^to the north hold %^BOLD%^%^BLACK%^suits of armor "+
      "%^RESET%^on display.  To the south is a small %^ORANGE%^bar%^RESET%^ that "+
      "seems to have patrons at all hours.  A small %^BOLD%^%^RED%^sign %^RESET%^"+
      "is displayed in the %^CYAN%^window%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"viento57",
      "east" : ROOMS"estreet17",
      "north" : ROOMS"armor",
      "south" : ROOMS"bar"
   ]));
   set_door("armory door","/d/attaya/newseneca/rooms/armor","north",0,0);
   set_door_description("armory door","The armor shop to the north has a wide "+
      "wooden door set within its stone walls.  It is often left open to help "+
      "relieve some of the heat of the adjoining smithy.");
   set_door("bar door","/d/attaya/newseneca/rooms/bar","south",0,0);
   set_door_description("bar door","The door of the bar to the south is crafted "+
      "on double hinges so that it can swing both inward and outward.  It is "+
      "painted %^BOLD%^%^BLUE%^blue %^RESET%^to match the trim of the bar.");
   add_item("building","The armor shop to the north has thick stone walls "+
      "that continue westward, enclosing both the smithy and the weapons "+
      "shop as well.  Near the top of the walls are long, narrow windows "+
      "left glassless to help provide ventilation.  Two large, paned windows "+
      "hold suits of armor on display.");
   add_item("shop","The armor shop to the north has thick stone walls "+
      "that continue westward, enclosing both the smithy and the weapons "+
      "shop as well.  Near the top of the walls are long, narrow windows "+
      "left glassless to help provide ventilation.  Two large, paned windows "+
      "hold suits of armor on display.");
   add_item("armory","The armor shop to the north has thick stone walls "+
      "that continue westward, enclosing both the smithy and the weapons "+
      "shop as well.  Near the top of the walls are long, narrow windows "+
      "left glassless to help provide ventilation.  Two large, paned windows "+
      "hold suits of armor on display.");
   add_item("suits of armor","Two large display windows in the armory hold "+
      "ornate %^BOLD%^%^BLACK%^suits of armor%^RESET%^.  The one on the left "+
      "is made of %^BOLD%^%^BLACK%^blackened metal %^RESET%^and covered with "+
      "spikes, giving it a fearsome appearance, while the one on the right "+
      "is smooth and crafted from %^BOLD%^mithril%^RESET%^.");
   add_item("windows","Two large display windows in the armory hold "+
      "ornate %^BOLD%^%^BLACK%^suits of armor%^RESET%^.  The one on the left "+
      "is made of %^BOLD%^%^BLACK%^blackened metal %^RESET%^and covered with "+
      "spikes, giving it a fearsome appearance, while the one on the right "+
      "is smooth and crafted from %^BOLD%^mithril%^RESET%^.");
   add_item("armor","Two large display windows in the armory hold "+
      "ornate %^BOLD%^%^BLACK%^suits of armor%^RESET%^.  The one on the left "+
      "is made of %^BOLD%^%^BLACK%^blackened metal %^RESET%^and covered with "+
      "spikes, giving it a fearsome appearance, while the one on the right "+
      "is smooth and crafted from %^BOLD%^mithril%^RESET%^.");
   add_item("bar","Like many bars, the one to the south seems aged and "+
      "well-worn.  It is painted vaguely %^BOLD%^white%^RESET%^ though the "+
      "sand and salt have blasted some of it away, revealing the %^ORANGE%^"+
      "wood %^RESET%^underneath.  It is trimmed in %^BOLD%^%^BLUE%^blue "+
      "%^RESET%^and has a single %^CYAN%^window %^RESET%^displaying a "+
      "%^BOLD%^%^RED%^sign%^RESET%^."); 
   add_item("sign","The sign in the window is circular with the appearance of "+
      "a ship's wheel.  The spokes are wooden, and the interior of the wheel "+
      "has been painted %^BOLD%^white %^RESET%^with a %^BOLD%^%^RED%^red "+
      "message %^RESET%^you could read."); 
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str == "sign" || str == "metal sign"){
      tell_object(TP,"\n"+
"%^RESET%^%^ORANGE%^                                @G7@\n"+
"                                SssK^\n"+
"                                @SGB\n"+
"                                sSO@\n"+
"                                ReG@\n"+
"                                #SsCQ                    //\n"+
"         t%(@/              %BRC@@O@B#S@O/             @6GO@\n"+
"         BCGOCO         @RtCOO#QRS@6KOR(CCt#@^       (QSGO@\n"+
"          ResQ3@     R#C6SG6BOOOO@#Q#eO7@KKSGG#@    @C%e7K\n"+
"            @QO6@KRB6sCOQSQRO#s6sGs/s6sQKS@KtOs67Q@COsQB\n"+
"              RRS#OC66OG#COOSOR@@@Se@R@@QROOGBQQQS%@Gs(\n"+
"              Q#G6CGSSSO@#R@%%^B_WHITE%^            %^RESET%^%^ORANGE%^KS#QO6SGOQG7B\n"+
"              eS36QQRSOe@^%^B_WHITE%^                  %^RESET%^%^ORANGE%^/@e%GeQGOs#\n"+
"             S6sSSO36SR6%^B_WHITE%^                       %^RESET%^%^ORANGE%^RSOQSSO%S\n"+
"            (OGeGGGe@O%^B_WHITE%^     %^BOLD%^%^RED%^___                  %^RESET%^%^ORANGE%^@Q3QQGSG@\n"+
"            KCOSSGO#%^B_WHITE%^        %^BOLD%^%^RED%^||_  _               %^RESET%^%^ORANGE%^RSGGQQSO6\n"+
"           7COQSCOR^%^B_WHITE%^        %^BOLD%^%^RED%^|| |(/_               %^RESET%^%^ORANGE%^@QOOeSGC\n"+
"           #OOQGsKB%^B_WHITE%^                                %^RESET%^%^ORANGE%^QeOQKSO@\n"+
"          %CCQKss@%^B_WHITE%^                 %^BOLD%^%^RED%^__              %^RESET%^%^ORANGE%^BQe#QOOQ^\n"+
"          eCsQQ6CB%^B_WHITE%^                %^BOLD%^%^RED%^(_  _.|_|_       %^RESET%^%^ORANGE%^Q@OGGGO3Q@R/(BK@%Q\n"+
" #S#@@@@R3RCGesOGt%^B_WHITE%^                %^BOLD%^%^RED%^__)(_|| |_       %^RESET%^%^ORANGE%^%@SGSQes@eOG%%GSOO%\n"+
"@OQ((7%OK%RsGSOS#s%^B_WHITE%^                                 %^RESET%^%^ORANGE%^e#eSSGOG@6SQRRK#RR\n"+
" K#RRRR@#KBOSSeCGS%^B_WHITE%^                                 %^RESET%^%^ORANGE%^7QOOeSsB@\n"+
"          @sCQGGs@%^B_WHITE%^      %^BOLD%^%^RED%^|\\/| _ .__|_  _..__|_      %^RESET%^%^ORANGE%^R6sQeeCB\n"+
"          #QGGeGG#%^B_WHITE%^      %^BOLD%^%^RED%^|  |(/_|(_| |(_|| ||_      %^RESET%^%^ORANGE%^#OCee6sK\n"+
"           R63eQG6R%^B_WHITE%^                                %^RESET%^%^ORANGE%^ssSS6OC\n"+
"            #OSeS66B%^B_WHITE%^                             %^RESET%^%^ORANGE%^BsOGe#Gs@\n"+
"            @eOKeGG%@@%^B_WHITE%^                          %^RESET%^%^ORANGE%^RtsSeS3O@\n"+
"             #G6%e6G6#B%^B_WHITE%^                       %^RESET%^%^ORANGE%^O@%GSe#6GK\n"+
"              sSO#QeGeO6@%^B_WHITE%^                   %^RESET%^%^ORANGE%^3@%%6QSesOR\n"+
"               RQCeOQKOK7#@/%^B_WHITE%^              %^RESET%^%^ORANGE%^Q3(36GsQsGO@R\n"+
"               R6QQOC6K37COOS#@R@#OOC@BK#s%SKeeQGt%#@OR@\n"+
"              @6@K@BR6CeQ#RCSGS#3%CtGKSe#KS3SeGOQR@R#%O3@\n"+
"            #SCO#Rs /@GOeCKBRQOSCOQ@#CeQ@RRCB@##O     OGC3R~\n"+
"           #7COS      /~RR#KQeCQB%#K(76CCQQOS@(        #SO%t^\n"+
"          @eGG@            /@BRRQK#RK##@#@s             (sG@\n"+
"           /G(                   #sOGS\n"+
"                                  sGSQ\n"+
"                                  6sG^\n"+
"                                  s66#\n"+
"                                 /OOs@\n"+
"                                  SCB\n"+
"%^RESET%^\n"
      );
      if(!TP->query_invis() && !TP->query_hidden()){
         tell_room(TO,""+TPQCN+" seems to be studying the sign.");
      }
      return 1;
   }
}