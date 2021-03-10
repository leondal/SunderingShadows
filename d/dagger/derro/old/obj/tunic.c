//updated by Circe 11/24/04 with descriptions based on 
//deity by Shar
//Added Sune to the list and also gave obvious short 
//to each one - Cythera 8/05
#include <std.h>
inherit ARMOUR;

void create(){
  ::create();
  set_name("knights tunic");
  set_id(({"tunic","knights tunic","knight's tunic","tabard"}));
  set_short("faded knight's tunic");
  set_obvious_short("faded knight's tunic");
  set_long("This knee-length tunic is worn over the armor "+
      "and holds the knight's coat of arms while protecting his "+
      "armor from the elements so it can protect him from blows."
      "  It's a faded gray as if remembering glories long past."
  );
  set_lore("The fabled knight's tunic was fashioned by an order "+
     "of knights in ages past.  Though not allies in the common "+
     "sense, the knights were of all faiths and came together "+
     "to help establish order in the wild lands.  These tunics "+
     "are a remnant of that order, which helped spread civilization "+
     "all over the realms.  The order was named the Knights of "+
     "Genesis, and they disbanded around the year 246 SG, when "+
     "each knight settled into his or her own role.");
  set_type("clothing");
  set_limbs(({"torso"}));
  set_weight(5);
  set_value(100);
  set_size(2);
  set_wear((:TO,"wearit":));
  set_remove((:TO,"removeit":));
}

int wearit(){
  string deity;
  deity = ETO->query_diety();
  if((!TP->is_class("paladin")) && (!TP->is_class("antipaladin")) && (!TP->is_class("cavalier"))){
     tell_object(ETO,"The tunic refuses to be worn by a lowly "+ETO->query_class());
     tell_room(EETO,""+ETOQCN+" tries to wear the tunic but cannot "+
        "seem to manage.",ETO);
     return 0;
  }
  if(ETO->query_level()<25){
    TO->set_property("enchantment",2);
    while((int)TO->query_property("enchantment") != 2) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",2);
    }
  }
  else {
    TO->set_property("enchantment",3);
    while((int)TO->query_property("enchantment") != 3) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",3);
    }
  }
  if(!deity){
     if(ETO->is_class("paladin")){
        tell_object(ETO,"As you wear the tunic the dull gray "+
           "fades away to be replaced by pure white.");
        tell_room(EETO,""+ETOQCN+"s tunic loses its gray tones "+
           "and shines in the light.",ETO);
        set_short("%^BOLD%^%^WHITE%^White knight's tunic%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^This brilliant white tunic "+
           "repels dirt and glows in any light.  Its %^YELLOW%^"+
           "gold trim %^WHITE%^sparkles in the light, and it "+
           "seems to protect better now that is has a purpose.%^RESET%^");
        return 1;
     }
     if(ETO->is_class("antipaladin")){
        tell_object(ETO,"As you wear the tunic it fades to dead "+
           "black to match your heart.");
        tell_room(EETO,"As "+ETOQCN+" wears a tunic it fades to "+
           "pitch black with touches of light reflected from its "+
           "gold stitched trim.",ETO);
        set_short("%^BOLD%^%^BLACK%^Black knight's tunic%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^This tunic is pitch black with "+
           "a %^YELLOW%^gold trim%^BLACK%^.  It's worn over the "+
           "knight's body to help protect him on his path of "+
           "conquest.%^RESET%^");
        return 1;
     }
     if(ETO->is_class("cavalier")){
        tell_object(ETO,"The cloak's grayness fades and is replaced "+
           "with a deep emerald green.");
        tell_room(EETO,""+ETOQCN+"'s cloak loses its grayness and "+
           "becomes an emerald green as it is worn.",ETO);
        set_short("%^RESET%^%^GREEN%^Green knight's tunic%^RESET%^");
        set_long("%^GREEN%^This long tunic is a vibrant %^BOLD%^"+
           "emerald green %^RESET%^%^GREEN%^trimmed in %^YELLOW%^"+
           "gold braid%^RESET%^%^GREEN%^.  It may be worn over "+
           "a knight's armor to protect him from the elements.%^RESET%^");
        return 1;
     }
  }
  switch(deity){
     case "torm": set_long("This %^BOLD%^pristine white%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, the "+
        "tabard has a richness in its simplicity.  These tabards "+
        "are worn over the armor, protecting it from the elements, "+
        "as well as proudly displaying the Coat of Arms of the "+
        "knight.  This tabard is divided into quarters with strong "+
        "solid %^YELLOW%^golden borders%^RESET%^.  In the uppermost "+
        "left hand quarter, an open hand gauntlet on a field of "+
        "%^BOLD%^%^BLUE%^cobalt blue %^RESET%^lays.  Across from "+
        "it on a field of %^BOLD%^white%^RESET%^ a crossed lance "+
        "and bastard sword over a kite shield has been embroidered "+
        "into the tabard.  Underneath it on a field of %^BOLD%^"+
        "%^BLUE%^cobalt blue%^RESET%^ is a %^YELLOW%^golden lion"+
        "%^RESET%^, hold its head up high in a regal majesty.  "+
        "The last section, which is%^BOLD%^ stark white%^RESET%^ "+
        "has been left blank, allowing the knight to place his or "+
        "her own coat of arms on the tabard.");
        set_short("%^YELLOW%^Tabard of the Lion-heart%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^A pristine white tabard%^RESET%^");
        break;
     case "auril": set_long("This %^BOLD%^%^CYAN%^pale blue%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made of the "+
        "finest blend of cashmere and silk in the lands, the tabard "+
        "has a richness in its simplicity.  These tabards are worn "+
        "over the armor, protecting it from the elements, as well "+
        "as proudly displaying the coat of arms of the knight.  This "+
        "tabard is divided into quarters with broken jagged %^BOLD%^"+
        "frost white %^RESET%^borders.  In the uppermost left hand "+
        "quarter a diamond with a perfect snowflake inside of it "+
        "has been stitched into the %^BOLD%^%^CYAN%^pale blue%^RESET%^ "+
        "fabric, with glittering %^BOLD%^%^WHITE%^white%^RESET%^ "+
        "threads.  Across from it on a field of %^BOLD%^white"+
        "%^RESET%^ a crossed lance and bastard sword over a shield "+
        "made of ice has been embroidered with high detail.  "+
        "Underneath this symbol on a %^BOLD%^%^CYAN%^pale blue"+
        "%^RESET%^ background is the image of %^BOLD%^silvery "+
        "white winter wolf%^RESET%^, standing poised to pounce. "+
        "The last section, %^BOLD%^stark white%^RESET%^, has been "+
        "left blank allowing the knight to place their own coat of "+
        "arms on the tabard.");
        set_short("%^BOLD%^%^WHITE%^Tabard of the Winter Wolf%^RESET%^");
	  set_obvious_short("%^BOLD%^%^CYAN%^A pale blue tabard%^RESET%^");
        break;
	case "auppenser": set_long("This %^BOLD%^%^BLUE%^deep blue%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made of the "+
        "finest blend of cashmere and silk in the lands, the tabard "+
        "has a richness in its simplicity.  These tabards are worn "+
        "over the armor, protecting it from the elements, as well "+
        "as proudly displaying the coat of arms of the knight.  This "+
        "tabard is divided into quarters with uniform and smooth %^ORANGE%^"+
        "bronze %^RESET%^borders.  In the uppermost left hand "+
        "quarter a stylized %^CYAN%^cyan%^RESET%^ eye upon  "+
	  "%^BOLD%^%^BLACK%^soft black%^RESET%^ "+
        "background has been stitched into the fabric.  "+
	  "Across from it on a field of %^BOLD%^%^BLUE%^deep blue"+
        "%^RESET%^ a crossed lance and scimitar sword over a %^BOLD%^crystal"+
	  " shield has been embroidered with high detail.  "+
        "Underneath this symbol on a %^BOLD%^%^BLACK%^soft black"+
        "%^RESET%^ background is the image of %^BOLD%^%^CYAN%^ kirre"+
	  "%^RESET%^, looking serene and insightful. "+
        "The last section, %^BOLD%^BLUE%^deep blue%^RESET%^, has been "+
        "left blank allowing the knight to place their own coat of "+
        "arms on the tabard.");
        set_short("%^BOLD%^%^CYAN%^Tabard of the Serene Kirre%^RESET%^");
	  set_obvious_short("%^BOLD%^%^BLUE%^A deep blue tabard%^RESET%^");
        break;
     case "bane": set_long("This %^BOLD%^%^BLACK%^black %^RESET%^"+
        "knee-length tabard is worn over the armor.  Made of the "+
        "finest blend of cashmere and silk in the lands, the tabard "+
        "has a richness in its simplicity.  These tabards are worn "+
        "over the armor, protecting it from the elements, as well "+
        "as proudly displaying the coat of arms of the knight.  "+
        "This tabard is divided into quarters with %^BOLD%^%^RED%^"+
        "cardnial red%^RESET%^ thick powerful lines.  In the "+
        "uppermost left hand quarter a %^BOLD%^%^BLACK%^black "+
        "gauntlet%^RESET%^ with %^BOLD%^%^GREEN%^green eyes%^RESET%^ "+
        "has been stitched into an %^GREEN%^emerald green%^RESET%^ "+
        "background.  Across from it on a field of%^BOLD%^%^BLACK%^ "+
        "black %^RESET%^a crossed lance and bastard sword over a "+
        "spiked large shield has been embroidered with high detail.  "+
        "Underneath this symbol on an %^GREEN%^emerald green"+
        "%^RESET%^ background is the image of %^BOLD%^%^BLACK%^"+
        "black dragon %^RESET%^in flight, looking imposing and "+
        "fearsome. The last section, %^BOLD%^%^BLACK%^dark black"+
        "%^RESET%^, has been left blank allowing the knight to place "+
        "their own coat of arms on the tabard.");
        set_short("%^BOLD%^%^BLACK%^Tabard of the Black Lord%^RESET%^");
	  set_obvious_short("%^BOLD%^%^BLACK%^A black tabard%^RESET%^");
        break;
     case "lathander": set_long("This %^YELLOW%^golden %^RESET%^"+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, "+
        "the tabard has a richness in its simplicity.  These "+
        "tabards are worn over the armor, protecting it from "+
        "the elements, as well as proudly displaying the Coat "+
        "of Arms of the knight.  This tabard is divided into "+
        "quarters with %^BOLD%^%^MAGENTA%^rose red%^RESET%^ "+
        "scrolling lines.  In the uppermost left hand quarter "+
        "a %^ORANGE%^golden orange %^RESET%^disk featuring the "+
        "rising sun at dawn over a green field has been "+
        "embroidered onto a %^BOLD%^%^RED%^crimson %^RESET%^"+
        "background.  Across from it on a %^YELLOW%^golden%^RESET%^ "+
        "field is a white lance and mace over a smooth round"+
        "%^BOLD%^%^MAGENTA%^ rose quartz%^RESET%^ shield.  "+
        "Underneath this symbol on a %^BOLD%^%^RED%^crimson"+
        "%^RESET%^ background is the image of a %^ORANGE%^phoenix "+
        "%^RESET%^in its brilliant, awe-inspiring glory.  The "+
        "last section, %^YELLOW%^golden yellow%^RESET%^, has been "+
        "left blank allowing the knight to place their own coat of "+
        "arms on the tabard.");
        set_short("%^BOLD%^%^MAGENTA%^Tabard of the Rising Phoenix%^RESET%^");
	  set_obvious_short("%^YELLOW%^A golden tabard%^RESET%^");
        break;
     case "shar": set_long("This %^BOLD%^%^BLACK%^pitch black%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, the "+
        "tabard has a richness in its simplicity.  These tabards "+
        "are worn over the armor, protecting it from the elements, "+
        "as well as proudly displaying the Coat of Arms of the "+
        "knight.  This tabard is divided into quarters with smooth "+
        "faint %^MAGENTA%^amethyst%^RESET%^ lines.  In the upper "+
        "left hand quarter a ring of%^MAGENTA%^ purple%^RESET%^ "+
        "surrounds a %^BOLD%^%^BLACK%^black orb%^RESET%^, on a "+
        "field of %^BOLD%^%^BLACK%^pitch black%^RESET%^.  Across "+
        "from it on a %^MAGENTA%^rich purple %^RESET%^background "+
        "is a %^BOLD%^%^BLACK%^black lance%^RESET%^ and mace over "+
        "a circular shield made of %^MAGENTA%^amethyst%^RESET%^.  "+
        "Underneath this symbol on a %^BOLD%^%^BLACK%^pitch black"+
        "%^RESET%^ background is the image of a %^MAGENTA%^purple "+
        "raven %^RESET%^looking stealthy and proud.  The last "+
        "section,%^MAGENTA%^ rich purple%^RESET%^, has been left "+
        "blank allowing the knight to place their own coat of arms "+
        "on the tabard.");
        set_short("%^BOLD%^%^BLACK%^Tabard of the Night's Raven%^RESET%^");
	  set_obvious_short("%^BOLD%^%^BLACK%^A pitch black tabard%^RESET%^");
        break;
	case "kelemvor": set_long("This %^BOLD%^%^white%^soft white%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, the "+
        "tabard has a richness in its simplicity.  These tabards "+
        "are worn over the armor, protecting it from the elements, "+
        "as well as proudly displaying the Coat of Arms of the "+
        "knight.  This tabard is divided into quarters with smooth "+
        "but solid %^GREEN%^green%^RESET%^ lines.  In the upper "+
        "left hand quarter an upright skeletal arm holding the scales"+
	  " of justice has been stitched in %^BOLD%^%^WHITE%^silver%^RESET%^"+
	  " on a field of %^GREEN%^green-%^BOLD%^%^BLACK%^gray%^RESET%^.  Across "+
        "from it on a %^BOLD%^%^WHITE%^soft white%^RESET%^background "+
        "is a %^BOLD%^%^WHITE%^silver%^RESET%^ lance and bastard sword crossed"+
	  " over a circular shield made of %^BOLD%^%^GREEN%^jade%^RESET%^.  "+
        "Underneath this symbol on a %^GREEN%^green-%^BOLD%^%^BLACK%^gray"+
        "%^RESET%^ background is the image of a %^BOLD%^%^BLACK%^black"+
        "panther %^RESET%^looking strong and deadly.  The last "+
        "section,%^BOLD%^%^WHITE%^soft white%^RESET%^, has been left "+
        "blank allowing the knight to place their own coat of arms "+
        "on the tabard.");
        set_short("%^RESET%^%^GREEN%^Tabard of the Spectral Panther%^RESET%^");
	  set_obvious_short("%^BOLD%^%^WHITE%^A soft white tabard%^RESET%^");
        break;
     case "mystra": set_long("This %^BLUE%^midnight blue%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, the "+
        "tabard has a richness in its simplicity.  These tabards "+
        "are worn over the armor, protecting it from the elements, "+
        "as well as proudly displaying the Coat of Arms of the "+
        "knight.  This tabard is divided into quarters with "+
        "flowing %^BOLD%^%^RED%^red %^RESET%^lines.  In the upper "+
        "left hand quarter a ring of seven %^BOLD%^silvery-"+
        "%^BLUE%^blue%^RESET%^ stars with a %^RED%^%^BOLD%^"+
        "scarlet%^RESET%^ mist flowing from the center has been "+
        "stitched onto a %^BLUE%^midnight blue%^RESET%^ background"+
        ".  Across from it on a %^BOLD%^%^CYAN%^blue-white"+
        "%^RESET%^ background is the image of a %^BLUE%^dark blue "+
        "lance %^RESET%^and bastard sword crossed over an %^RED%^"+
        "ethereal red mist%^RESET%^ circular shield.  Underneath "+
        "this symbol on a %^BLUE%^midnight blue%^RESET%^ field "+
        "is the image of a %^CYAN%^steel dragon %^RESET%^in "+
        "flight, looking graceful and majestic.  The last "+
        "section, %^BOLD%^%^CYAN%^blue-white%^RESET%^, has been "+
        "left blank allowing the knight to place their own coat "+
        "of arms on the tabard.");
        set_short("%^BOLD%^%^CYAN%^Tabard of the Mystical Dragon%^RESET%^");
	  set_obvious_short("%^RESET%^%^BLUE%^A midnight blue tabard%^RESET%^");
        break;
     case "tyr": set_long("This %^BLUE%^navy blue%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made "+
        "from the finest blend of cashmere and silk in the "+
        "lands, the tabard has a richness in its simplicity.  "+
        "These tabards are worn over the armor, protecting "+
        "it from the elements, as well as proudly displaying "+
        "the Coat of Arms of the knight.  The tabard is "+
        "divided into quarters with solid unwavering%^BOLD%^ "+
        "white%^RESET%^ lines.  In the upper left hand "+
        "quarter a shield with a pair of balanced scales on "+
        "top of a war hammer has been stitched into the "+
        "%^BLUE%^navy blue%^RESET%^ background.  Across from "+
        "it on a%^MAGENTA%^ dusky purple %^RESET%^background "+
        "is the image of a %^CYAN%^steel lance%^RESET%^ and "+
        "long sword crossed over a large kite shield.  "+
        "Underneath this symbol on a %^BLUE%^navy blue%^RESET%^ "+
        "field is the image of a wise old wolf, looking grim "+
        "and firm.  The last section, %^MAGENTA%^dusky purple"+
        "%^RESET%^, has been left blank allowing the knight to "+
        "place their own coat of arms on the tabard.");
        set_short("%^BOLD%^%^BLUE%^Tabard of the Even-Handed%^RESET%^");
	  set_obvious_short("%^BOLD%^%^BLUE%^A navy blue tabard%^RESET%^");
        break;
     case "helm": set_long("This steel gray knee-length "+
        "tabard is worn over the armor.  Made from the "+
        "finest blend of cashmere and silk in the lands, the "+
        "tabard has a richness in its simplicity.  These "+
        "tabards are worn over the armor, protecting it "+
        "from the elements, as well as proudly displaying "+
        "the Coat of Arms of the knight.  The tabard is "+
        "divided into quarters with firm thick %^YELLOW%^"+
        "yellow%^RESET%^ lines.  In the upper left hand "+
        "quarter the back of an open handed gauntlet with "+
        "the image of an eye on it has been stitched into a "+
        "%^BOLD%^%^BLUE%^medium blue %^RESET%^field.  Across "+
        "from it on a steel gray background is the image of a "+
        "%^BOLD%^mithril lance %^RESET%^and bastard sword crossed "+
        "over a large tower shield.  Underneath this symbol "+
        "on a %^BOLD%^%^BLUE%^medium blue %^RESET%^background "+
        "is the image of a large dog, standing tall with a "+
        "watchful gaze.  The last section, steel gray, has "+
        "been left blank allowing the knight to place their "+
        "own coat of arms on the tabard.");
        set_short("%^BOLD%^%^WHITE%^Tabard of the Guardian Watchdog%^RESET%^");
	  set_obvious_short("%^RESET%^A steel gray tabard%^RESET%^");
        break;
     case "kossuth": set_long("This %^RED%^fiery red %^RESET%^"+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, "+
        "the tabard has a richness in its simplicity.  These "+
        "tabards are worn over the armor, protecting it from "+
        "the elements, as well as proudly displaying the Coat "+
        "of Arms of the knight.  This tabard is divided into "+
        "quarters with swirling dancing %^YELLOW%^golden"+
        "%^RESET%^ lines.  In the upper left hand quarter twin "+
        "spiraling %^BOLD%^%^RED%^flames %^RESET%^interwoven "+
        "together has been embroidered on a%^ORANGE%^ vibrant "+
        "orange%^RESET%^ field.  Across from it on a%^RED%^ "+
        "fiery red %^RESET%^background is the image of a"+
        "%^YELLOW%^ golden lance %^RESET%^and flaming sword "+
        "over a kite shield.  Underneath this symbol on a "+
        "%^ORANGE%^vibrant orange %^RESET%^field is the image "+
        "of a salamander, blazing with intense fires.  The "+
        "last section, %^RED%^fiery red%^RESET%^, has been "+
        "left blank allowing the knight to place their own coat "+
        "of arms on the tabard.");
        set_short("%^BOLD%^%^RED%^Tabard of the Salamander%^RESET%^");
	  set_obvious_short("%^BOLD%^%^RED%^A fiery red tabard%^RESET%^");
        break;
     case "grumbar": set_long("This %^RED%^ruby red%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made "+
        "from the finest blend of cashmere and silk in the "+
        "lands, the tabard has a richness in its simplicity.  "+
        "These tabards are worn over the armor, protecting it "+
        "from the elements, as well as proudly displaying the "+
        "Coat of Arms of the knight.  This tabard is divided "+
        "into quarters with solid %^CYAN%^steel%^RESET%^ thick "+
        "lines.  In the upper left hand quarter a massive "+
        "solid mountain has been stitched into the%^ORANGE%^ "+
        "coffee brown %^RESET%^background.  Across from it "+
        "on a %^RED%^ruby red%^RESET%^ background is the image "+
        "of a %^BOLD%^%^RED%^gem encrusted lance%^RESET%^ and "+
        "mace crossed over a thick solid rectangular shield.  "+
        "Underneath this symbol on a %^ORANGE%^coffee brown"+
        "%^RESET%^ field is the image of a landshark, also "+
        "known as a bullette, looking strong and unmoving.  "+
        "The last section, %^RED%^ruby red,%^RESET%^ has been "+
        "left blank allowing the knight to place their own "+
        "coat of arms on the tabard.");
        set_short("%^RESET%^%^ORANGE%^Tabard of the Unchanging Earth%^RESET%^");
	  set_obvious_short("%^BOLD%^%^RED%^A ruby red tabard%^RESET%^");
        break;
     case "selune": set_long("This %^BOLD%^%^CYAN%^light blue"+
        "%^RESET%^ knee length tabard is worn over the armor.  "+
        "Made from the finest blend of cashmere and silk in "+
        "the lands, the tabard has richness in its simplicity.  "+
        "These tabards are worn over the armor, protecting it "+
        "from the elements, as well as proudly displaying the "+
        "Coat of Arms of the knight.  This tabard is divided "+
        "into quarters with smooth flowing %^BOLD%^silver "+
        "%^RESET%^lines.  In the upper left hand quarter is "+
        "the image of a pair of feminine eyes surrounded by a "+
        "ring of seven stars, on a field of %^CYAN%^dusky blue"+
        "%^RESET%^.  Across from it on a%^BOLD%^%^BLUE%^ light "+
        "blue %^RESET%^background is the image of a %^BOLD%^"+
        "silver lance%^RESET%^ and mace crossed over a crescent "+
        "shaped shield.  Underneath this symbol on a %^CYAN%^"+
        "dusky blue%^RESET%^ field is a %^BOLD%^silvery white "+
        "owl %^RESET%^in flight, looking both wise and joyful at "+
        "the same time.  The last section, %^BOLD%^%^CYAN%^light "+
        "blue%^RESET%^, has been left blank allowing the knight "+
        "to place their own coat of arms on the tabard.");
        set_short("%^BOLD%^%^WHITE%^Tabard of the Moonlit Owl%^RESET%^");
	  set_obvious_short("%^BOLD%^%^CYAN%^A light blue tabard%^RESET%^");
        break;
     case "loviatar": set_long("This %^RED%^deep red%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, the "+
        "tabard has a richness in its simplicity.  These tabards "+
        "are worn over the armor, protecting it from the elements, "+
        "as well as proudly displaying the Coat of Arms of the "+
        "knight.  This tabard is divided into quarters with smooth "+
        "bold %^BOLD%^%^BLACK%^glittering black%^RESET%^ lines.  "+
        "In the upper left hand quarter a %^BOLD%^%^BLACK%^cat o' "+
        "nine tails %^RESET%^with %^RED%^blood red barbs %^RESET%^"+
        "has been stitched on a "+
        "field of %^BOLD%^%^BLACK%^deep gray%^RESET%^.  Across "+
        "from it on a %^RED%^crimson %^RESET%^background "+
        "is a %^BOLD%^%^BLACK%^black lance%^RESET%^ and bastard sword over "+
        "a kite shield made of %^BOLD%^%^BLACK%^onyx%^RESET%^.  "+
        "Underneath this symbol on a %^BOLD%^%^BLACK%^deep gray"+
        "%^RESET%^ background is the image of a %^BOLD%^%^BLACK%^"+
        "rearing nightmare %^RESET%^with %^RED%^flaming hooves "+
        "%^RESET%^looking strong and proud.  The last "+
        "section,%^RED%^ crimson%^RESET%^, has been left "+
        "blank allowing the knight to place their own coat of arms "+
        "on the tabard.");
        set_short("%^BOLD%^%^BLACK%^Tabard of Pain's Embrace%^RESET%^");
	  set_obvious_short("%^RESET%^%^RED%^A deep red tabard%^RESET%^");
        break;
	case "sune":set_long("This %^RED%^deep crimson%^RESET%^ "+
        "knee-length tabard is worn over the armor.  Made from "+
        "the finest blend of cashmere and silk in the lands, the "+
        "tabard has a richness in its simplicity.  These tabards "+
        "are worn over the armor, protecting it from the elements, "+
        "as well as proudly displaying the Coat of Arms of the "+
        "knight.  This tabard is divided into quarters with smooth "+
        "braided %^YELLOW%^gold%^RESET%^ lines.  "+
        "In the upper left hand quarter a face of a beautiful %^BOLD%^"+
	  "ivory%^RESET%^ skinned human maiden with long %^RED%^crimson"+
	  "%^RESET%^ tresses has been stitched on a "+
        "field of %^BOLD%^ bright white%^RESET%^.  Across "+
        "from it on a %^RED%^deep crimson %^RESET%^background "+
        "is a %^YELLOW%^gold lance%^RESET%^ and long sword over "+
        "a round shield made of %^BOLD%^%^RED%^ruby%^RESET%^.  "+
        "Underneath this symbol on a %^BOLD%^ bright white"+
        "%^RESET%^ background is the image of a%^RED%^ "+
        "chestnut stallion%^RESET%^ with a %^BOLD%^%^RED%^flaming%^RESET%^"+
	  " mane and tail looking beautiful and proud.  The last "+
        "section,%^RED%^ deep crimson%^RESET%^, has been left "+
        "blank allowing the knight to place their own coat of arms "+
        "on the tabard.");
        set_short("%^RESET%^%^RED%^Tabard of Love's Fire%^RESET%^");
	  set_obvious_short("%^RESET%^%^RED%^A deep crimson tabard%^RESET%^");
        break;
     default:  tell_object(ETO,"Ack! Somehow, your deity "+
       "was overlooked!  Please mail Circe telling her you "+
       "got this message and what deity you follow!");
       break;
  }
  tell_object(ETO,"%^BOLD%^As you wear the dusky gray tunic, it shimmers "+
     "and grows insubstantial!  Suddenly, it transforms itself "+
     "into a glorious tabard of your deity!");
  tell_room(EETO,"%^BOLD%^As "+ETOQCN+" pulls on the tunic, "+
     "it shimmers ethereally.  Finally, it settles into a "+
     "glorious tabard!",ETO);
  return 1;
}

int removeit(){
   tell_room(EETO,"As "+ETOQCN+" removes the tunic, it fades to "+
      "gray again.",ETO);
   tell_object(ETO,"As you slip out of the tunic, it fades to "+
      "a dusky gray once more.");
   set_short("faded knight's tunic");
   set_obvious_short("faded knight's tunic");
   set_long("This knee-length tunic is worn over the armor "+
      "and holds the knight's coat of arms while protecting "+
      "his armor from the elements so it can protect him from blows."
      "  It's a faded gray as if remembering glories long past."
  );
  if((int)TO->query_property("enchantment")) TO->remove_property("enchantment");
  return 1;
}
