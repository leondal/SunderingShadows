#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("An austere meditation room");
   set_short("%^RESET%^%^GREEN%^An austere meditation room%^RESET%^");
   set_long("%^RESET%^%^GREEN%^An austere meditation room%^RESET%^\n"+
      "Featuring a much lower ceiling than the vaulted dome "+
      "in the fountain room, this chamber is filled with a "+
      "heavy %^CYAN%^hush%^RESET%^ that lends an atmosphere of "+
      "introspection.  The %^GREEN%^emerald-green floor %^RESET%^is "+
      "partially covered by a %^BOLD%^%^BLACK%^jet-black%^RESET%^"+
      "runner %^RESET%^trimmed in %^BOLD%^%^RED%^scarlet "+
      "%^RESET%^.  Areas have been partially segregated by half-"+
      "height walls of crystal, to allow for privacy from the rest "+
      "of the room.  Soft %^RED%^cu%^BOLD%^s%^RESET%^%^RED%^hions "+
      "%^RESET%^have been set about in each area, to allow for comfort "+
      "while one pursues inner enlightenment and higher purpose.  The "
      "walls here have been hung with slender %^BLUE%^tapestries%^RESET%^ "+
      "ending in points capped with %^BOLD%^%^BLACK%^ebon tassels%^RESET%^.  "+
      "Other than this, the room is relatively austere, perhaps to prevent "+
      "any distractions to those within.\n");
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items( ([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^GREEN%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.  Each wall "+
         "has been hung at intervals with three separate %^BLUE%^"+
         "tapestries%^GREEN%^, each trimmed in %^BOLD%^%^BLACK%^black "+
         "%^RESET%^%^GREEN%^and ending in an %^BOLD%^%^BLACK%^ebon "+
         "tassel%^RESET%^%^GREEN%^.%^RESET%^",
      ({"doorway","doorways","arches","archway","archways"}) : "The "+
         "walls of the room are unbroken save by the archway leading "+
         "to the north.",
      ({"tapestry","tapestries"}) : "%^BLUE%^Each tapestry is fashioned "+
         "from flawless viridian cloth and features the %^BOLD%^%^BLACK%^"+
         "clenched fist%^RESET%^%^BLUE%^ that is the holy symbol of the "+
         "%^BOLD%^%^RED%^Black Hand%^RESET%^%^BLUE%^, %^BOLD%^%^BLACK%^"+
         "Bane%^RESET%^%^BLUE%^.  The tapestries have all been trimmed in "+
         "%^BOLD%^%^BLACK%^black braid%^RESET%^%^BLUE%^, and their pointed "
         "ends are capped with an %^BOLD%^%^BLACK%^ebon tassel%^RESET%^%^BLUE%^.%^RESET%^",
      ({"cushion","cushions"}) : "%^ORANGE%^Cushions have been scattered "+
         "throughout the partially enclosed sections of the room, offering "+
         "a comfortable seat for those who come here in meditation.%^RESET%^",
      "runner" : "%^BLUE%^The runner echoes the jet black of the "+
         "tapestries' trimmings, though it bears its own lining of "+
         "%^BOLD%^%^RED%^vibrant scarlet%^RESET%^%^BLUE%^, giving the "+
         "runner definition.%^RESET%^",
   ]));
   set_exits(([
      "north" : "/d/dagger/tonovi/town/cguilds/psions/fountain"
   ]));
}