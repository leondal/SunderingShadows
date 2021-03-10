#include <std.h>
#include "/d/dagger/road/short.h"
inherit ROOM;

void create()
{
    ::create();
   set_terrain(CEMETERY);
   set_travel(DIRT_ROAD);
   set_property("light", 2);
   set_indoors(0);  
   set_short("%^RESET%^%^ORANGE%^B"+
"%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^f%^BOLD%^%^BLACK%^or%^RESET%^%^ORANGE%^e"
" %^BOLD%^%^BLACK%^an %^RESET%^%^ORANGE%^I%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^p"+
"%^BOLD%^%^BLACK%^os%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^g "
"%^BOLD%^%^BLACK%^Ma%^RESET%^u%^BOLD%^so%^RESET%^l%^BOLD%^%^BLACK%^eum%^RESET%^");
    set("day long",query_short() + "\n" + "%^BOLD%^%^BLACK%^This imposing building is made"+
"of solid black marble. Ionic pillars are spaced along the outside"+
"of the building, inlaid with gold and silver leaf images depicting bloody battle"+
"scenes and dark rituals. The face of the building itself is plain by comparison."+
"The massive double %^ORANGE%^d%^RESET%^%^RED%^o%^YELLOW%^o%^RESET%^%^RED%^r%^YELLOW%^s "+
"%^BLACK%^are made of solid %^RESET%^%^MAGENTA%^duskwood %^BOLD%^%^BLACK%^engraved with a hyena's "+
"head, and flanked by two marble statues. One s%^RESET%^ta%^BOLD%^tu%^BLACK%^e depicts two figures,"+
"both male. One has a look of shock on his face, as the second figure has a dagger half-way into his back "+
"with one hand, and his other hand wrapped around the %^ORANGE%^c%^RESET%^%^ORANGE%^o"+
"%^BOLD%^i%^RESET%^%^ORANGE%^n %^BOLD%^%^BLACK%^purse. The second s%^RESET%^tatu%^BOLD%^%^BLACK%^e "+
"is a single figure, a woman with long hair, holding a tome. She is the picture of scholarly intent, "+
"or would be, if she was not missing some %^RESET%^%^RED%^s%^BOLD%^%^BLACK%^k%^RESET%^%^RED%^i"+
"%^BOLD%^%^BLACK%^n on her cheek. The %^WHITE%^s%^RESET%^ta%^BOLD%^t%^RESET%^ue%^BOLD%^s %^BLACK%^are "+
"%^RESET%^%^RED%^b%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^utifu%^RESET%^%^RED%^ll "+
"%^BOLD%^%^BLACK%^y and lovingly crafted. On the wall next to the door, there are two unlit torches. "+
"The rest of the structure is mostly unadorned save the statues of r%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^v"+
"%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^n%^RESET%^%^BLUE%^s %^BOLD%^%^BLACK%^and vu%^RESET%^%^BLUE%^l"+
"%^WHITE%^t%^BLUE%^u%^BOLD%^%^BLACK%^res perched on the roof."

);
  set("night long", query_short() + "\n" +"%^BLUE%^The building in front of you gives off a sinister aura."+
"The torches blaze, casting eerie shadows on the %^WHITE%^s%^BOLD%^ta%^RESET%^tu%^BOLD%^es "+
"%^RESET%^%^BLUE%^by front of the %^ORANGE%^door%^BLUE%^, and the flickering torchlight gives an "+
"unearthly glow to to the surrounding area. The snarling hyenas on the door seem almost alive, as if "+
"they would bite your hand off if you moved too close.%^RESET%^"

);
set_smell("default", "%^YELLOW%^The smell of blood and death permeate the air");
set_listen("default", "%^GREEN%^It is eerily still, as if even the animals avoid this place.");

set_items(([
  "wall" : "%^BOLD%^%^BLACK%^The walls on the building are made of "+
  "solid black marble and are surprisingly plain. There are no decorations or "
  "%^WHITE%^mak%^RESET%^in%^BOLD%^g%^BLACK%^s on the outside of the building%^RESET%^",
  "statue" : "%^BOLD%^This statue is be%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^u%^WHITE%^tif"+
  "%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^RED%^l%^WHITE%^y sculpted of smooth, white marble. "
  "The creature before you is elegant and po%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^sed, and possessed "
  "of perfect posture. She holds in her hand a %^BLACK%^t%^RESET%^o%^BOLD%^me with a %^RESET%^%^ORANGE%^r"+
  "%^BOLD%^%^WHITE%^une-%^RESET%^%^ORANGE%^i%^BOLD%^%^WHITE%^ns%^RESET%^%^ORANGE%^c%^BOLD%^%^WHITE%^ribed"+
  " cover. The look on her face is %^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^e%^ORANGE%^u%^RESET%^%^ORANGE%^t"+
  "%^BOLD%^r%^WHITE%^a%^ORANGE%^l%^WHITE%^, with whisps of bangs hanging in front of her face. She would "+
  "be beautiful, but the left side of her cheek has %^RESET%^%^RED%^r%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^t"+
  "%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d %^WHITE%^away, and her %^BLACK%^t%^WHITE%^ee"+
  "%^BLACK%^t%^WHITE%^h are peeking out from the hole.%^RESET%^",
  "statue 2" : "%^BOLD%^%^RED%^These two statues are incredibly lifelike. "+
  "You can see the coiled muscles on the %^BLACK%^th%^RESET%^ie%^BOLD%^f%^RED%^, and almost feel "+
  "the anguish of the dying man, almost here the scream escape his lips as the %^BLACK%^d%^RESET%^%^RED%^a"+
  "%^BOLD%^%^BLACK%^g%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r %^BOLD%^penetrates his body. "+
  "The scene is both beautiful and disturbing, as the sculpture itself is made of fine, %^RESET%^%^RED%^r"+
  "%^BOLD%^e%^RESET%^%^RED%^d m%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^b%^RESET%^%^RED%^l%^BOLD%^e and expertly "+
  "crafted, but that adds to the disturbing nature of this piece%^RESET%^",
"pillars" : "%^BOLD%^%^BLACK%^These ionic pillars are "+
"carved with the same black marble as the rest of the building. However, they are inlayed "+
"with %^RESET%^%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d %^BLACK%^and %^WHITE%^s%^RESET%^i"+
"%^BOLD%^l%^RESET%^ve%^BOLD%^%^BLACK%^r leaf designs of various a%^GREEN%^r%^RESET%^%^MAGENTA%^c"+
"%^BOLD%^%^GREEN%^a%^BLACK%^n%^BLUE%^e %^BLACK%^symbols. The swirling designs are %^BLUE%^me%^GREEN%^sm"+
"%^BLUE%^e%^GREEN%^r%^BLACK%^i%^BLUE%^z%^BLACK%^i%^GREEN%^n%^BLACK%^g%^RESET%^",
  "ravens" : "%^BOLD%^%^BLACK%^The statues of "+
  "%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^v%^BOLD%^%^BLACK%^en%^RESET%^%^BLUE%^s "+
  "%^BOLD%^%^BLACK%^and v%^RESET%^u%^BOLD%^%^BLACK%^l%^RESET%^t%^BOLD%^%^BLACK%^ur%^RESET%^e"+
  "%^BOLD%^%^BLACK%^s stare down as si%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ent sentinals guarding their "+
  "lady's building. Thei%^RESET%^%^ORANGE%^r %^BOLD%^%^BLACK%^beady b%^RESET%^l%^BOLD%^%^BLACK%^a"+
  "%^RESET%^c%^BOLD%^%^BLACK%^k eyes can almost see right through you. Like the rest of the statues, "+
  "they are incredibly %^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^f%^BOLD%^%^BLACK%^el"+
  "%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ke, and seem to be only moments away from taking off into the "+
  "%^CYAN%^s%^RESET%^%^CYAN%^k%^BOLD%^y%^BLACK%^.%^RESET%^",
  "doors" : "%^ORANGE%^These heavy, %^MAGENTA%^duskwood "+
  "%^ORANGE%^doors are each engraved with the snarling visage of a hyena. These "+
  "%^RED%^v%^ORANGE%^i%^RED%^c%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^o%^ORANGE%^u%^RED%^s%^ORANGE%^-looking "+
  "engravings l%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ok l%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ke they "+
  "could %^BOLD%^%^RED%^s%^ORANGE%^n%^RED%^a%^ORANGE%^p %^RESET%^%^ORANGE%^your hand off in a split "+
  "second if you looked at them funny."]));
    set_exits( ([
       "west" : "/d/dagger/nurval/room/village2",
       "north" : RPATH"p7",
       "northeast" : RPATH"tempusportal",
       "temple" : "/d/magic/temples/nilith/nilith"
    ]) );
}

void reset()
{
    ::reset();
    if(!present("street_light",TO))
        new("/d/common/obj/misc/street_light")->move(TO);
}
