//updated by Circe 11/24/04 with descriptions based on 
//deity by Shar
//Added Sune to the list and also gave obvious short 
//to each one - Cythera 8/05
//Completely redone by ~Circe~ to remove old gods and add in new 7/30/19, also removed enchantment since they cannot wear it with magical armor
#include <std.h>
inherit "/d/common/obj/clothing/shirt.c";

void create(){
   ::create();
   set_name("knights tunic");
   set_id(({"tunic","knights tunic","knight's tunic","tabard"}));
   set_short("faded knight's tunic");
   set_obvious_short("faded knight's tunic");
   set_long("This knee-length tunic is worn over the armor and holds the knight's coat of arms while protecting his armor from the elements so it can protect him from blows.  It's a faded gray as if remembering glories long past.");
   set_lore("The fabled knight's tunic was fashioned by an order of knights in ages past.  Though not allies in the common sense, the knights were of all faiths and came together to help establish order in the wild lands.  These tunics are a remnant of that order, which helped spread civilization all over the realms.  The order was named the Knights of Genesis, and they disbanded around the year 246 SG, when each knight settled into his or her own role.");
   set_value(100);
   set_size(-1);
   set_wear((:TO,"wearit":));
   set_remove((:TO,"removeit":));
}

int wearit(){
   string deity;
   int align;
   deity = ETO->query_diety();
   if((!TP->is_class("paladin")) && (!TP->is_class("antipaladin")) && (!TP->is_class("cavalier"))){
      tell_object(ETO,"The tunic refuses to be worn by a lowly "+ETO->query_class()+" like you.");
      tell_room(EETO,""+ETOQCN+" tries to wear the tunic but cannot seem to manage.",ETO);
      return 0;
   }
   if(!deity){
      align = ETO->query_alignment();
      switch(align){
         case 1: case 4: case 7:
            tell_object(ETO,"As you wear the tunic the dull gray fades away to be replaced by %^BOLD%^pure white%^RESET%^.");
            tell_room(EETO,""+ETOQCN+"s tunic loses its gray tones and shines in the light.",ETO);
            set_short("%^BOLD%^%^WHITE%^White knight's tunic%^RESET%^");
            set_long("%^BOLD%^%^WHITE%^This brilliant white tunic repels dirt and glows in any light.  Its %^YELLOW%^gold trim "
               "%^WHITE%^sparkles in the light, and it seems to protect better now that is has a purpose.%^RESET%^");
            break;
         case 2: case 5: case 8:
            tell_object(ETO,"%^RESET%^%^GREEN%^The cloak's grayness fades and is replaced with a deep %^BOLD%^emerald green%^RESET%^.");
            tell_room(EETO,"%^RESET%^%^GREEN%^"+ETOQCN+"'s cloak loses its grayness and becomes an %^BOLD%^emerald green "
               "%^RESET%^%^GREEN%^as it is worn.%^RESET%^",ETO);
            set_short("%^RESET%^%^GREEN%^Green knight's tunic%^RESET%^");
            set_long("%^RESET%^%^GREEN%^This long tunic is a vibrant %^BOLD%^emerald green %^RESET%^%^GREEN%^trimmed in %^YELLOW%^"
               "gold braid%^RESET%^%^GREEN%^.  It may be worn over a knight's armor to protect him from the elements.%^RESET%^");
            break;
         case 3: case 6: case 9:
            tell_object(ETO,"%^BOLD%^%^BLACK%^As you wear the tunic it fades to dead black to match your heart.%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^BLACK%^As "+ETOQCN+" wears a tunic it fades to pitch black with touches of light reflected from its "
               "%^YELLOW%^gold-stitched %^BLACK%^trim.%^RESET%^",ETO);
            set_short("%^BOLD%^%^BLACK%^Black knight's tunic%^RESET%^");
            set_long("%^BOLD%^%^BLACK%^This tunic is pitch black with a %^YELLOW%^gold trim%^BLACK%^.  It's worn over the "
               "knight's body to help protect him on his path of conquest.%^RESET%^");
            break;
         default:
            tell_object(ETO,"Something seems to be wrong with your alignment! Please notify a wiz.");
            break;
      }
      return 1;
   }
   switch(deity){
      case "callamir": set_long("This %^BOLD%^%^CYAN%^azure%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with wavy %^BOLD%^%^BLUE%^ocean blue borders%^RESET%^.  In the uppermost lefthand quarter is a %^BOLD%^%^WHITE%^white rabbit %^RESET%^running across an %^BOLD%^%^CYAN%^azure backdrop%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a %^CYAN%^co%^GREEN%^m%^CYAN%^pa%^GREEN%^s%^CYAN%^s %^RESET%^made of %^CYAN%^ar%^GREEN%^a%^CYAN%^nd%^GREEN%^u%^CYAN%^r %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^BOLD%^%^CYAN%^azure%^RESET%^ is a %^ORANGE%^clever fox%^RESET%^, watching the world with its glittering eyes.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^BOLD%^%^CYAN%^Tabard of the %^WHITE%^White Rabbit%^RESET%^");
         set_obvious_short("%^BOLD%^%^CYAN%^An azure tabard%^RESET%^");
         break;
      case "jarmila":
         set_long("This %^ORANGE%^pale gold%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with straight %^YELLOW%^gold borders%^RESET%^.  In the uppermost lefthand quarter is a %^RED%^cr%^BOLD%^i%^RESET%^%^RED%^ms%^BOLD%^o%^RESET%^%^RED%^n rose %^RESET%^upon a shield of %^ORANGE%^gold%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a glorious %^BLUE%^s%^BOLD%^u%^RESET%^%^MAGENTA%^n%^RED%^r%^BOLD%^%^MAGENTA%^i%^RESET%^%^ORANGE%^s%^YELLOW%^e %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^ORANGE%^pale gold%^RESET%^ is a %^BOLD%^dove%^RESET%^ in flight, wings spread against the %^CYAN%^azure sky%^RESET%^.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^RESET%^%^ORANGE%^Tabard of the %^YELLOW%^Light%^RESET%^");
         set_obvious_short("%^RESET%^%^ORANGE%^A pale gold tabard%^RESET%^");
         break;
      case "kismet":
         set_long("This %^GREEN%^peridot green%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with swirling s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r borders%^RESET%^.  In the uppermost lefthand quarter is a %^BOLD%^blank scroll %^RESET%^crossed by a %^CYAN%^quill %^RESET%^and a %^BOLD%^%^BLACK%^smith's hammer %^RESET%^upon a field of %^GREEN%^peridot%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, an open %^ORANGE%^tome %^RESET%^filled with %^CYAN%^arcane symbols %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^GREEN%^peridot%^RESET%^ are a pair of %^CYAN%^songbirds %^RESET%^perched atop a %^ORANGE%^lyre%^RESET%^, their heads lifted in song.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^RESET%^%^GREEN%^Tabard of In%^CYAN%^s%^GREEN%^pir%^BOLD%^a%^RESET%^%^GREEN%^ti%^CYAN%^o%^GREEN%^n%^RESET%^");
         set_obvious_short("%^RESET%^%^GREEN%^A peridot green tabard%^RESET%^");
         break;
      case "kreysneothosies":
         set_long("This %^BOLD%^%^BLUE%^sapphire blue%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with straight %^YELLOW%^golden borders%^RESET%^.  In the uppermost lefthand quarter is a %^BOLD%^sword %^RESET%^crossing a %^ORANGE%^sheaf of wheat %^RESET%^upon a field of %^BOLD%^%^BLUE%^sapphire%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a %^ORANGE%^basket %^RESET%^of bountiful %^MAGENTA%^fr%^BOLD%^u%^RESET%^%^MAGENTA%^its %^RESET%^and %^GREEN%^ve%^BOLD%^g%^RESET%^%^GREEN%^et%^YELLOW%^a%^RESET%^%^GREEN%^bles %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^BOLD%^%^BLUE%^sapphire%^RESET%^ is a %^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^ld d%^YELLOW%^r%^RESET%^%^ORANGE%^ag%^YELLOW%^o%^RESET%^%^ORANGE%^n %^RESET%^with its wings spread wide.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^BOLD%^%^BLUE%^Tabard of the Protector%^RESET%^");
         set_obvious_short("%^BOLD%^%^BLUE%^A sapphire blue tabard%^RESET%^");
         break;
      case "lord shadow":
         set_long("This %^BOLD%^%^BLACK%^jet black%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with rigidly straight %^BOLD%^silver borders%^RESET%^.  In the uppermost lefthand quarter is an %^BOLD%^%^CYAN%^azure diamond %^RESET%^upon a %^BOLD%^%^BLACK%^black backdrop%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a sprig of stylized %^BOLD%^%^BLACK%^be%^GREEN%^l%^BLACK%^la%^RESET%^%^GREEN%^d%^BOLD%^%^BLACK%^on%^GREEN%^n%^BLACK%^a %^RESET%^interspersed with wilting %^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^le%^BOLD%^t%^RESET%^%^MAGENTA%^s %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^BOLD%^%^BLACK%^black%^RESET%^ is a rearing %^BOLD%^%^BLACK%^nightmare %^RESET%^outlined in s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^, his %^RED%^f%^BOLD%^l%^YELLOW%^a%^RESET%^%^ORANGE%^m%^BOLD%^%^RED%^i%^RESET%^%^RED%^ng mane %^RESET%^brilliant against the dark background.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^BOLD%^%^BLACK%^Tabard of Darkness%^RESET%^");
         set_obvious_short("%^BOLD%^%^BLACK%^A jet black tabard%^RESET%^");
         break;
      case "lysara":
         set_long("This %^BOLD%^brilliant white%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with wispy %^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r %^BOLD%^borders%^RESET%^.  In the uppermost lefthand quarter is a symbol of three interlocked %^BOLD%^rings %^RESET%^one each of %^BOLD%^white%^RESET%^, gray, and %^BOLD%^%^BLACK%^black %^RESET%^outlined in thread of %^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r upon a %^BOLD%^%^BLACK%^black backdrop%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a single %^BOLD%^white lily %^RESET%^with a %^GREEN%^j%^BOLD%^a%^RESET%^%^GREEN%^de stem %^RESET%^and %^GREEN%^leaves %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^BOLD%^%^BLACK%^black%^RESET%^ is a serene %^BOLD%^snowy owl %^RESET%^wearing a %^BOLD%^diadem %^RESET%^adorned with a single %^BOLD%^moo%^RESET%^n%^BOLD%^st%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ne%^RESET%^.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^BOLD%^%^WHITE%^Tabard of the Three-Faced Moon%^RESET%^");
         set_obvious_short("%^BOLD%^%^WHITE%^A brilliant white tabard%^RESET%^");
         break;
      case "nilith":
         set_long("This %^RED%^blood-red%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with %^BOLD%^bone white borders%^RESET%^.  In the uppermost lefthand quarter is a symbol of a %^BOLD%^skeletal hand %^RESET%^holding a single %^BOLD%^%^WHITE%^ca%^RESET%^l%^BOLD%^l%^RESET%^a %^BOLD%^li%^RESET%^l%^BOLD%^y%^RESET%^ superimposed on a %^BOLD%^tower shield %^RESET%^upon a %^BOLD%^%^BLACK%^black backdrop%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a %^BOLD%^skeletal lich %^RESET%^wearing a %^YELLOW%^golden crown %^RESET%^studded with %^BOLD%^%^BLACK%^blo%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ds%^RED%^t%^BLACK%^one %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^RED%^blood-red%^RESET%^ is a cunning %^BOLD%^%^BLACK%^raven %^RESET%^with beady %^BOLD%^%^BLACK%^black eyes%^RESET%^ and shimmering %^BOLD%^%^BLACK%^w%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g%^BOLD%^%^BLACK%^s%^RESET%^.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^RESET%^%^RED%^Tabard of %^RESET%^Bones");
         set_obvious_short("%^RESET%^%^RED%^A blood-red tabard%^RESET%^");
         break;
      case "nimnavanon":
         set_long("This %^ORANGE%^woody brown%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with %^GREEN%^borders of vines%^RESET%^.  In the uppermost lefthand quarter is a %^BOLD%^wolf's pawprint %^RESET%^upon a %^GREEN%^circle of grass%^RESET%^ upon a %^ORANGE%^woody brown backdrop%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, tendrils of %^GREEN%^i%^BOLD%^v%^RESET%^%^GREEN%^y %^RESET%^weaving among a cluster of %^MAGENTA%^w%^BOLD%^i%^RED%^l%^RESET%^%^RED%^d%^ORANGE%^f%^YELLOW%^l%^CYAN%^o%^RESET%^%^CYAN%^w%^GREEN%^e%^BOLD%^r%^MAGENTA%^s %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^ORANGE%^woody brown%^RESET%^ is a diminutive %^BOLD%^%^MAGENTA%^pixie%^RESET%^ flying above a sleeping %^ORANGE%^fawn%^RESET%^.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^RESET%^%^ORANGE%^Tabard of the Prowling Wolf%^RESET%^");
         set_obvious_short("%^RESET%^%^ORANGE%^A woody brown tabard%^RESET%^");
         break;
      case "the faceless one":
         set_long("This %^BOLD%^%^BLACK%^%^dark gray%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with %^RED%^blood-red borders%^RESET%^.  In the uppermost lefthand quarter is a lighter gray cloak marked with three %^RED%^blood-red t%^BOLD%^e%^RESET%^%^RED%^ar%^BOLD%^d%^RESET%^%^RED%^rops %^RESET%^upon a %^BOLD%^%^BLACK%^dark gray backdrop%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a realistic %^BOLD%^%^BLACK%^spider %^RESET%^in a %^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y web %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^BOLD%^%^BLACK%^dark gray%^RESET%^ is the gaping maw of a %^ORANGE%^cave %^RESET%^from which pour countless %^BOLD%^%^BLACK%^bats%^RESET%^.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^BOLD%^%^BLACK%^Tabard of W%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^is%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^er%^RESET%^%^RED%^s%^RESET%^");
         set_obvious_short("%^BOLD%^%^BLACK%^A dark gray tabard%^RESET%^");
         break;
      case "ryorik":
         set_long("This %^CYAN%^sky blue%^RESET%^ knee-length tabard is made from the finest blend of cashmere and silk in the lands, giving it a richness in its simplicity.  These tabards are worn over the armor, protecting it from the elements and proudly displaying the Coat of Arms of the knight.  This tabard is divided into quarters with %^BOLD%^ir%^RESET%^%^CYAN%^i%^BOLD%^%^WHITE%^d%^MAGENTA%^e%^WHITE%^sc%^CYAN%^e%^WHITE%^nt borders%^RESET%^.  In the uppermost lefthand quarter is an elongated, curved %^BOLD%^silver scimitar %^RESET%^against a %^BOLD%^%^BLACK%^storm-cloud field %^RESET%^upon a %^CYAN%^sky blue backdrop%^RESET%^.  Across from it on a field of %^BOLD%^white%^RESET%^, a riot of %^RED%^e%^BOLD%^l%^YELLOW%^e%^CYAN%^m%^RESET%^%^CYAN%^e%^GREEN%^n%^ORANGE%^t%^CYAN%^s %^RESET%^- %^RED%^f%^BOLD%^i%^YELLOW%^r%^RESET%^%^RED%^e%^RESET%^, %^CYAN%^w%^GREEN%^a%^CYAN%^t%^GREEN%^e%^CYAN%^r%^RESET%^, %^ORANGE%^ea%^GREEN%^r%^ORANGE%^th%^RESET%^, and %^CYAN%^a%^BOLD%^i%^RESET%^%^CYAN%^r %^RESET%^- %^RESET%^has been embroidered into the tabard.  Underneath it on a field of %^CYAN%^sky blue%^RESET%^ are incongruously %^BOLD%^%^BLACK%^stormy clouds %^RESET%^with jagged %^YELLOW%^lightning bolts%^RESET%^.  The last section, which is%^BOLD%^ stark white%^RESET%^, has been left blank, allowing the knight to place his or her own coat of arms on the tabard.");
         set_short("%^RESET%^%^CYAN%^Tabard of the Tempest%^RESET%^");
         set_obvious_short("%^RESET%^%^CYAN%^A sky blue tabard%^RESET%^");
         break;
      default:  tell_object(ETO,"Ack! Somehow, your deity was overlooked!  Bug report this item and tell us what deity you follow!");
         break;
   }
   tell_object(ETO,"%^BOLD%^As you wear the dusky gray tunic, it shimmers and grows insubstantial!  Suddenly, it transforms itself "
      "into a glorious tabard of your deity!");
   tell_room(EETO,"%^BOLD%^As "+ETOQCN+" pulls on the tunic, it shimmers ethereally.  Finally, it settles into a "
      "glorious tabard!",ETO);
   return 1;
}

int removeit(){
   tell_room(EETO,"As "+ETOQCN+" removes the tunic, it fades to gray again.",ETO);
   tell_object(ETO,"As you slip out of the tunic, it fades to a dusky gray once more.");
   set_short("faded knight's tunic");
   set_obvious_short("faded knight's tunic");
   set_long("This knee-length tunic is worn over the armor and holds the knight's coat of arms while protecting his armor from the elements so it can protect him from blows.  It's a faded gray as if remembering glories long past."
  );
  if((int)TO->query_property("enchantment")) TO->remove_property("enchantment");
  return 1;
}
