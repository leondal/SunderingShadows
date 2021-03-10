//vil1.c
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_long(
@CIRCE
%^YELLOW%^A Stone House
%^RESET%^%^WHITE%^This simple stone home consists of one large room 
divided by a curtain.  A fireplace on the northern wall feeds 
into a stone chimney rising above it.  A black iron kettle stands 
over the flames, while a rustic wooden table is pushed against 
the wall nearby with two chairs set facing each other across it.  
In the middle of the room is a wooden couch with brown cushions, 
which is pulled fairly close to the fire.  A tiny table stands beside 
it, upon which rests half-finished needlework.  A blue curtain 
hung across the southeastern corner is pulled back, revealing a small 
bed and a shelf.
CIRCE
   );
   set_items(([
      (({"curtain","blue curtain"})) : "A blue woolen curtain "+
      "hangs across the southeastern corner of the wall.  It is "+
      "pulled back to reveal a small bedchamber.",
      (({"fireplace","chimney","fire"})) : "A warm fire burns "+
      "steadily in the stone fireplace on the northern wall.  "+
      "The smoke rises through the chimney, keeping the air "+
      "inside nice and clean.",
      (({"kettle","iron kettle","black kettle","black iron kettle"})) : 
      "A black iron kettle, much like a cauldron, is bubbling over "+
      "the fire.  Looking inside, you see some sort of brown stew, "+
      "though you are not quite sure what the meat is.",
      (({"table","wooden table","rustic table","chair","chairs"})) : "Just "+
      "beside the fireplace along the northern wall is a rustic "+
      "table left mostly in its natural state though the tabletop "+
      "has been polished to avoid splinters.  Two chairs are pushed "+
      "under it, completing the small dining area.",
      (({"couch","wooden couch","cushions","brown cushions"})) : "The "+
      "deep brown cushions match the wood of the couch.  It seems a "+
      "rather comfortable place to relax for awhile.",
      (({"small table","tiny table","needlepoint","needlework"})) : "A "+
      "low table has been placed beside the couch in front of the fire "+
      "and holds a cream-colored square of fabric with half-completed "+
      "needlework.  Tiny birds are being stitched onto a cloudy sky in "+
      "a blue that matches the curtain strung across the room.",
      "bed" : "A simple wooden frame supports a mattress filled with "+
      "rushes.  A cream colored woolen quilt is stretched across the bed "+
      "and two small pillows rest at its head.",
      "shelf" : "Above the head of the bed, a wooden shelf rests on pegs "+
      "pounded into the wall.  Folded atop it are various common garments, "+
      "mostly tunics and breeches."
      ]));

   set_exits(([
      "west" : TROOMS"path8"
      ]));
   set_door("wooden door",TROOMS"path8","west",0);
}

void reset()
{
        ::reset();
        if(!present("cieren")) {
                new(MON"lady.c")->move(TO);
        }
}
